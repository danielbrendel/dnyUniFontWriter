#include "stdafx.h"
#include "ufwmgr.h"

/*
	UniFont Writer (dnyUniFontWriter) developed by Daniel Brendel

	(C) 2018 - 2022 by Daniel Brendel

	Version: 0.1
	Contact: dbrendel1988<at>gmail<dot>com
	GitHub: https://github.com/danielbrendel/

	License: The MIT License
		   	 
*/

//======================================================================
CUniFontWriterMgr* pUFWMgrInstance = NULL;
CUniFontWriterMgr g_oUFWMgr;
//======================================================================

//======================================================================
LRESULT CALLBACK CLRMGR_LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	//Low-level keyboard procedure

	//Pass to manager event method
	return pUFWMgrInstance->LowLevelKeyboardEvent(nCode, wParam, lParam);
}
//======================================================================

//======================================================================
bool CUniFontWriterMgr::Initialize(void)
{
	//Initialize manager

	//Register low-level keyboard hook
	this->m_hKeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, &CLRMGR_LowLevelKeyboardProc, NULL, 0);
	if (!this->m_hKeyboardHook)
		return false;

	//Save object instance pointer
	pUFWMgrInstance = this;

	//Setup original char string
	this->m_wszOriginChars = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	return true;
}
//======================================================================

//======================================================================
void CUniFontWriterMgr::Free(void)
{
	//Free resources

	//Unregister low-level keyboard hook
	UnhookWindowsHookEx(this->m_hKeyboardHook);

	//Clear data
	this->m_hKeyboardHook = NULL;
	this->m_vLetterFonts.clear();
}
//======================================================================

//======================================================================
bool CUniFontWriterMgr::SendUnicodeString(const std::wstring& wszUnicodeString)
{
	//Send unicode string as input message so it is handled as it would have been typed via keyboard

	//Allocate memory for input data array according to string length
	INPUT* pInputs = new INPUT[wszUnicodeString.length()];
	if (!pInputs)
		return false;

	//Loop through chars and setup each element input data for this char
	for (size_t i = 0; i < wszUnicodeString.length(); i++) {
		pInputs[i].type = INPUT_KEYBOARD;
		pInputs[i].ki.wVk = 0;
		pInputs[i].ki.wScan = wszUnicodeString[i];
		pInputs[i].ki.dwFlags = KEYEVENTF_UNICODE;
		pInputs[i].ki.time = 0;
		pInputs[i].ki.dwExtraInfo = 0;
	}

	//Attempt to perform input simulation
	bool bResult = SendInput((UINT)wszUnicodeString.length(), pInputs, sizeof(INPUT)) > 0;

	//Free memory
	delete[] pInputs;

	return bResult;
}
//======================================================================

//======================================================================
std::wstring CUniFontWriterMgr::ReplacerStringFromFontSet(KBDLLHOOKSTRUCT* pKeyboardData, bool bShiftHeld)
{
	//Attempt to find replacer letter fontset string from given virtual key code char

	if (this->m_hCurrentHandledFont == UFWMGR_LF_INVALID_ENTRY)
		return L"";

	//Get character from virtual key code
	wchar_t wcResult = (wchar_t)MapVirtualKey(pKeyboardData->vkCode, MAPVK_VK_TO_CHAR);
	if (!wcResult)
		return L"";

	for (size_t i = 0; i < UFWMGR_ALPHABETCHARAMOUNT; i++) { //Iterate through alphabet chars
		if (this->m_wszOriginChars[i] == wcResult) { //Check if given char is an alphabet char
			return this->m_vLetterFonts[this->m_hCurrentHandledFont].wszaLetterString[i]; //Return replacer char
		}
	}

	return L"";
}
//======================================================================

//======================================================================
LRESULT CUniFontWriterMgr::LowLevelKeyboardEvent(int nCode, WPARAM wParam, LPARAM lParam)
{
	//Low-level keyboard hook event method

	if ((this->m_bActivationStatus) && (this->m_hCurrentHandledFont != UFWMGR_LF_INVALID_ENTRY)) { //Check if activated and a letter fontset has been selected
		if (nCode == HC_ACTION) {//Check if keyboard data is available
			//Setup data pointer
			KBDLLHOOKSTRUCT* pKeyboardHookData = (KBDLLHOOKSTRUCT*)lParam;

			//Check for control keys being held
			bool bShiftHeld = (GetKeyState(VK_LSHIFT) & 0x8000) > 0;
			bool bCtrlHeld = (GetKeyState(VK_CONTROL) & 0x8000) > 0;

			if ((!bShiftHeld) && (!bCtrlHeld)) { //Only continue if control keys are not being handled
				//Attempt to find replacer string from keyboard event data
				std::wstring wszReplacerString = this->ReplacerStringFromFontSet(pKeyboardHookData, bShiftHeld);
				if (wszReplacerString.length()) { //Check if found
					if (wParam == WM_KEYDOWN) { //Do only simulate input if key is pressed
						SendUnicodeString(wszReplacerString); //Simulate input
					}

					return 1L; //Don't continue passing the keyboard event message
				}
			}
		}
	}

	//Continue with hook chain
	return CallNextHookEx(this->m_hKeyboardHook, nCode, wParam, lParam);
}
//======================================================================

//======================================================================
void CUniFontWriterMgr::Process(void)
{
	//Perform permanent processings

	MSG sMsg;

	if (GetMessage(&sMsg, NULL, 0, 0)) { //Check if a message is in the message queue
		TranslateMessage(&sMsg); //Translate vkey messages to character messages
		DispatchMessage(&sMsg); //Dispatch message to window procedure
	}
}
//======================================================================

//======================================================================
void CUniFontWriterMgr::SetActivationStatus(bool bStatus)
{
	//Set activation status

	//Save status value
	this->m_bActivationStatus = bStatus;

	//Correct value if required
	if ((this->m_bActivationStatus) && (m_hCurrentHandledFont == UFWMGR_LF_INVALID_ENTRY))
		this->m_bActivationStatus = false;
}
//======================================================================

//======================================================================
bool CUniFontWriterMgr::LoadLetterFile(const std::wstring& wszFileName)
{
	//Load letter fontset from file

	HANDLE hFile = CreateFile(wszFileName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0); //Open file for reading
	if (hFile != INVALID_HANDLE_VALUE) { //If file has been opened
		std::wstring wszLine(L"");
		letter_data_s sLetterData;
		size_t uiLineCounter = 0;
		wchar_t wcCurrentChar;
		DWORD dwBytesRead;

		while (ReadFile(hFile, &wcCurrentChar, sizeof(wchar_t), &dwBytesRead, NULL)) { //While file content at current position is available
			if (wcCurrentChar == 0x003B) { //Check for line delimiter
				if (uiLineCounter >= 1) { //Handle each letter char
					sLetterData.wszaLetterString[uiLineCounter - 1] = wszLine;
				} else { //Handle base info
					sLetterData.wszFontName = &wszLine[1];
					
					//Check if already exists
					if (this->FindLetterFont(wszLine) != UFWMGR_LF_INVALID_ENTRY) {
						CloseHandle(hFile); //Close file
						return false;
					}
				}

				uiLineCounter++; //Increment line counter

				//Break out if all lines have been read
				if (uiLineCounter >= UFWMGR_ALPHABETCHARAMOUNT)
					break;

				wszLine = L""; //Clear string again
				SetFilePointer(hFile, 4, 0, FILE_CURRENT); //Jump to next line

				continue; //Ignore further processing for this iteration
			}

			wszLine += wcCurrentChar; //Append current wide char to line string
		}

		//Add element to list
		this->m_vLetterFonts.push_back(sLetterData);

		CloseHandle(hFile); //Close file
	}

	return true;
}
//======================================================================

//======================================================================
bool CUniFontWriterMgr::SaveLetterFile(const std::wstring& wszFromPath, const std::wstring& wszFontName, const std::wstring& wszAlphabetStream)
{
	//Save letter file to text

	//Create file for writing
	HANDLE hFile = CreateFile((wszFromPath + wszFontName + L".txt").c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	std::wstring wszCurrentLetter;
	DWORD dwBytesWritten;
	const byte waPrefix[] = { 0xFF, 0xFE };
	const wchar_t waDelim[] = { 0x003B , 0x000D, 0x000A };

	//Write prefix
	if ((!WriteFile(hFile, waPrefix, sizeof(waPrefix), &dwBytesWritten, NULL)) || (!dwBytesWritten)) {
		CloseHandle(hFile);
		return false;
	}

	//Write font name
	if ((!WriteFile(hFile, wszFontName.data(), (DWORD)wszFontName.length() * 2, &dwBytesWritten, NULL)) || (!dwBytesWritten)) {
		CloseHandle(hFile);
		return false;
	}

	//Write delimiter
	if ((!WriteFile(hFile, waDelim, sizeof(waDelim), &dwBytesWritten, NULL)) || (!dwBytesWritten)) {
		CloseHandle(hFile);
		return false;
	}

	for (size_t i = 0; i < wszAlphabetStream.length(); i++) { //Loop through stream chars
		if (wszAlphabetStream[i] == ';') { //Check for delimiter
			//Write letter string
			if ((!WriteFile(hFile, wszCurrentLetter.data(), (DWORD)wszCurrentLetter.length() * 2, &dwBytesWritten, NULL)) || (!dwBytesWritten)) {
				CloseHandle(hFile);
				return false;
			}

			//Write delimiter
			if ((!WriteFile(hFile, waDelim, sizeof(waDelim), &dwBytesWritten, NULL)) || (!dwBytesWritten)) {
				CloseHandle(hFile);
				return false;
			}

			//Clear buffer
			wszCurrentLetter.clear();

			continue; //Ignore this char
		}

		wszCurrentLetter += wszAlphabetStream[i]; //Append to letter
	}

	//Close file stream
	CloseHandle(hFile);

	return true;
}
//======================================================================

//======================================================================
HLETTERFONT CUniFontWriterMgr::FindLetterFont(const std::wstring& wszName)
{
	//Get handle to letter fontset if exists

	for (size_t i = 0; i < this->m_vLetterFonts.size(); i++) { //Iterate through list
		if (this->m_vLetterFonts[i].wszFontName == wszName) { //Compare name strings
			return i; //Return list ID as a handle
		}
	}

	return UFWMGR_LF_INVALID_ENTRY;
}
//======================================================================

//======================================================================
bool CUniFontWriterMgr::SelectLetterSet(const std::wstring& wszLetterName)
{
	//Select a letter fontset to use

	//Attempt to find font
	HLETTERFONT hLetterFont = this->FindLetterFont(wszLetterName);
	if (hLetterFont == UFWMGR_LF_INVALID_ENTRY)
		return false;

	//Select found font
	this->m_hCurrentHandledFont = hLetterFont;

	return true;
}
//======================================================================

//======================================================================
bool CUniFontWriterMgr::GetLetterData(const size_t uiIdent, letter_data_s& rsDataOut)
{
	//Get letter data via ID

	if ((uiIdent == UFWMGR_LF_INVALID_ENTRY) || (uiIdent >= this->m_vLetterFonts.size()))
		return false;

	rsDataOut = this->m_vLetterFonts[uiIdent];

	return true;
}
//======================================================================
