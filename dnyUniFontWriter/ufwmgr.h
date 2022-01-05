#ifndef _ULRMGR_H
#define _ULRMGR_H

#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <istream>
#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <Windows.h>

/*
	UniFont Writer (dnyUniFontWriter) developed by Daniel Brendel

	(C) 2018 - 2022 by Daniel Brendel

	Version: 0.1
	Contact: dbrendel1988<at>gmail<dot>com
	GitHub: https://github.com/danielbrendel/

	License: The MIT License
			 
*/

//======================================================================
#define UFWMGR_ALPHABETCHARAMOUNT 26
#define UFWMGR_LF_INVALID_ENTRY std::string::npos
//======================================================================

//======================================================================
typedef size_t HLETTERFONT;
//======================================================================

//======================================================================
struct letter_data_s {
	std::wstring wszFontName;
	std::wstring wszaLetterString[UFWMGR_ALPHABETCHARAMOUNT];
};
//======================================================================

//======================================================================
class CUniFontWriterMgr {
private:
	HHOOK m_hKeyboardHook;
	std::vector<letter_data_s> m_vLetterFonts;
	HLETTERFONT m_hCurrentHandledFont;
	bool m_bActivationStatus;
	std::wstring m_wszOriginChars;

	friend LRESULT CALLBACK CLRMGR_LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
	LRESULT LowLevelKeyboardEvent(int nCode, WPARAM wParam, LPARAM lParam);
	bool SendUnicodeString(const std::wstring& wszUnicodeString);
	std::wstring ReplacerStringFromFontSet(KBDLLHOOKSTRUCT* pKeyboardData, bool bShiftHeld);
	HLETTERFONT FindLetterFont(const std::wstring& wszName);
public:
	CUniFontWriterMgr() : m_bActivationStatus(false), m_hCurrentHandledFont(UFWMGR_LF_INVALID_ENTRY) {}
	~CUniFontWriterMgr() { this->Free(); }

	bool Initialize(void);
	void Free(void);

	void Process(void);

	void SetActivationStatus(bool bStatus);
	bool GetActivationStatus(void) { return this->m_bActivationStatus; }

	bool LoadLetterFile(const std::wstring& wszFileName);
	bool SelectLetterSet(const std::wstring& wszLetterName);
	size_t GetFontSetCount(void) { return this->m_vLetterFonts.size(); }
	bool GetLetterData(const size_t uiIdent, letter_data_s& rsDataOut);
	bool SaveLetterFile(const std::wstring& wszFromPath, const std::wstring& wszFontName, const std::wstring& wszAlphabetStream);
};
//======================================================================

//======================================================================
extern CUniFontWriterMgr* pUFWMgrInstance;
extern CUniFontWriterMgr g_oUFWMgr;
//======================================================================

#endif
