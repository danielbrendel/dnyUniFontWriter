#pragma once

#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>
#include "ufwmgr.h"
#include "frmNewFont.h"

/*
	UniFont Writer (dnyUniFontWriter) developed by Daniel Brendel

	(C) 2018 - 2023 by Daniel Brendel

	Version: 0.1
	Contact: dbrendel1988<at>gmail<dot>com
	GitHub: https://github.com/danielbrendel/

	License: The MIT License
			 
*/

#define PROGRAM_NAME "UniFont Writer"
#define PROGRAM_VERSION "0.1"
#define PROGRAM_AUTHOR "Daniel Brendel"
#define PROGRAM_CONTACT "dbrendel1988<at>gmail<dot>com"
#define PROGRAM_WEBSITE "https://github.com/danielbrendel"
#define HK_TOGGLE 1

namespace dnyUniFontWriter {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace Microsoft::Win32;
	using namespace System::Diagnostics;
	using namespace System::ComponentModel;
	using namespace msclr::interop;
	using namespace System::Web;
	using namespace System::Net;
	using namespace System::Net::Cache;
	using namespace Microsoft::VisualBasic;
	using namespace System::Threading;
	using namespace System::Reflection;

	/// <summary>
	/// Zusammenfassung für frmMain
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form
	{
	public:
		frmMain(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

		frmMain(array<System::String ^> ^args)
		{
			InitializeComponent();
			
			bHideOnStartup = false;

			if (args->Length) {
				for (int i = 0; i < args->Length; i++) {
					if (args[i] == "-hide") {
						bHideOnStartup = true;
					}
				}
			}
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ListView^  lvFontList;

	private: System::Windows::Forms::ColumnHeader^  chFontName;
	private: System::Windows::Forms::ColumnHeader^  chAlphabet;
	private: System::Windows::Forms::ColumnHeader^  chStatus;
	private: System::Windows::Forms::Label^  lblHotkey;
	private: System::Windows::Forms::TextBox^  txtHotkey;

	private: System::Windows::Forms::Label^  lblHotkeyInfo;

	private: System::Windows::Forms::Button^  btnAbout;
	private: System::Windows::Forms::Button^  btnExit;
	private: System::Windows::Forms::ContextMenuStrip^  ctxTNAMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  showToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toggleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::NotifyIcon^  niTNAIcon;
	private: System::Windows::Forms::Button^  btnToggle;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toggleToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  fontsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  createToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gitHubToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pbBanner;



	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
			this->lvFontList = (gcnew System::Windows::Forms::ListView());
			this->chFontName = (gcnew System::Windows::Forms::ColumnHeader());
			this->chAlphabet = (gcnew System::Windows::Forms::ColumnHeader());
			this->chStatus = (gcnew System::Windows::Forms::ColumnHeader());
			this->lblHotkey = (gcnew System::Windows::Forms::Label());
			this->txtHotkey = (gcnew System::Windows::Forms::TextBox());
			this->lblHotkeyInfo = (gcnew System::Windows::Forms::Label());
			this->btnAbout = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->ctxTNAMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->showToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toggleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->niTNAIcon = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->btnToggle = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toggleToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fontsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gitHubToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pbBanner = (gcnew System::Windows::Forms::PictureBox());
			this->ctxTNAMenu->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBanner))->BeginInit();
			this->SuspendLayout();
			// 
			// lvFontList
			// 
			this->lvFontList->BackColor = System::Drawing::Color::AliceBlue;
			this->lvFontList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->chFontName, this->chAlphabet,
					this->chStatus
			});
			this->lvFontList->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lvFontList->FullRowSelect = true;
			this->lvFontList->HideSelection = false;
			this->lvFontList->Location = System::Drawing::Point(0, 109);
			this->lvFontList->Name = L"lvFontList";
			this->lvFontList->Size = System::Drawing::Size(585, 159);
			this->lvFontList->TabIndex = 0;
			this->lvFontList->UseCompatibleStateImageBehavior = false;
			this->lvFontList->View = System::Windows::Forms::View::Details;
			this->lvFontList->SelectedIndexChanged += gcnew System::EventHandler(this, &frmMain::lvFontList_SelectedIndexChanged);
			// 
			// chFontName
			// 
			this->chFontName->Text = L"Font Name";
			this->chFontName->Width = 125;
			// 
			// chAlphabet
			// 
			this->chAlphabet->Text = L"Alphabet";
			this->chAlphabet->Width = 373;
			// 
			// chStatus
			// 
			this->chStatus->Text = L"Status";
			this->chStatus->Width = 83;
			// 
			// lblHotkey
			// 
			this->lblHotkey->AutoSize = true;
			this->lblHotkey->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHotkey->Location = System::Drawing::Point(15, 282);
			this->lblHotkey->Name = L"lblHotkey";
			this->lblHotkey->Size = System::Drawing::Size(75, 20);
			this->lblHotkey->TabIndex = 1;
			this->lblHotkey->Text = L"Hotkey: ";
			// 
			// txtHotkey
			// 
			this->txtHotkey->Font = (gcnew System::Drawing::Font(L"Verdana", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtHotkey->ForeColor = System::Drawing::Color::Green;
			this->txtHotkey->Location = System::Drawing::Point(86, 283);
			this->txtHotkey->Name = L"txtHotkey";
			this->txtHotkey->Size = System::Drawing::Size(41, 21);
			this->txtHotkey->TabIndex = 2;
			// 
			// lblHotkeyInfo
			// 
			this->lblHotkeyInfo->AutoSize = true;
			this->lblHotkeyInfo->Location = System::Drawing::Point(133, 287);
			this->lblHotkeyInfo->Name = L"lblHotkeyInfo";
			this->lblHotkeyInfo->Size = System::Drawing::Size(25, 13);
			this->lblHotkeyInfo->TabIndex = 3;
			this->lblHotkeyInfo->Text = L"Info";
			// 
			// btnAbout
			// 
			this->btnAbout->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAbout.Image")));
			this->btnAbout->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnAbout->Location = System::Drawing::Point(371, 274);
			this->btnAbout->Name = L"btnAbout";
			this->btnAbout->Size = System::Drawing::Size(104, 37);
			this->btnAbout->TabIndex = 5;
			this->btnAbout->Text = L"About";
			this->btnAbout->UseVisualStyleBackColor = true;
			this->btnAbout->Click += gcnew System::EventHandler(this, &frmMain::btnAbout_Click);
			// 
			// btnExit
			// 
			this->btnExit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnExit.Image")));
			this->btnExit->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnExit->Location = System::Drawing::Point(481, 274);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(104, 37);
			this->btnExit->TabIndex = 6;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &frmMain::btnExit_Click);
			// 
			// ctxTNAMenu
			// 
			this->ctxTNAMenu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->ctxTNAMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->showToolStripMenuItem,
					this->toggleToolStripMenuItem, this->toolStripMenuItem1, this->exitToolStripMenuItem
			});
			this->ctxTNAMenu->Name = L"ctxTNAMenu";
			this->ctxTNAMenu->Size = System::Drawing::Size(114, 88);
			this->ctxTNAMenu->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &frmMain::ctxTNAMenu_Opening);
			// 
			// showToolStripMenuItem
			// 
			this->showToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"showToolStripMenuItem.Image")));
			this->showToolStripMenuItem->Name = L"showToolStripMenuItem";
			this->showToolStripMenuItem->Size = System::Drawing::Size(113, 26);
			this->showToolStripMenuItem->Text = L"Show";
			this->showToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::showToolStripMenuItem_Click);
			// 
			// toggleToolStripMenuItem
			// 
			this->toggleToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toggleToolStripMenuItem.Image")));
			this->toggleToolStripMenuItem->Name = L"toggleToolStripMenuItem";
			this->toggleToolStripMenuItem->Size = System::Drawing::Size(113, 26);
			this->toggleToolStripMenuItem->Text = L"Toggle";
			this->toggleToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::toggleToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(110, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitToolStripMenuItem.Image")));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(113, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::exitToolStripMenuItem_Click);
			// 
			// niTNAIcon
			// 
			this->niTNAIcon->ContextMenuStrip = this->ctxTNAMenu;
			this->niTNAIcon->Visible = true;
			this->niTNAIcon->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmMain::niTNAIcon_MouseDoubleClick);
			// 
			// btnToggle
			// 
			this->btnToggle->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnToggle.Image")));
			this->btnToggle->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnToggle->Location = System::Drawing::Point(258, 275);
			this->btnToggle->Name = L"btnToggle";
			this->btnToggle->Size = System::Drawing::Size(104, 37);
			this->btnToggle->TabIndex = 7;
			this->btnToggle->Text = L"Toggle";
			this->btnToggle->UseVisualStyleBackColor = true;
			this->btnToggle->Click += gcnew System::EventHandler(this, &frmMain::btnToggle_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->fontsToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(588, 24);
			this->menuStrip1->TabIndex = 8;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->toggleToolStripMenuItem1,
					this->toolStripMenuItem2, this->exitToolStripMenuItem1
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// toggleToolStripMenuItem1
			// 
			this->toggleToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toggleToolStripMenuItem1.Image")));
			this->toggleToolStripMenuItem1->Name = L"toggleToolStripMenuItem1";
			this->toggleToolStripMenuItem1->Size = System::Drawing::Size(109, 22);
			this->toggleToolStripMenuItem1->Text = L"Toggle";
			this->toggleToolStripMenuItem1->Click += gcnew System::EventHandler(this, &frmMain::toggleToolStripMenuItem1_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(106, 6);
			// 
			// exitToolStripMenuItem1
			// 
			this->exitToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitToolStripMenuItem1.Image")));
			this->exitToolStripMenuItem1->Name = L"exitToolStripMenuItem1";
			this->exitToolStripMenuItem1->Size = System::Drawing::Size(109, 22);
			this->exitToolStripMenuItem1->Text = L"Exit";
			this->exitToolStripMenuItem1->Click += gcnew System::EventHandler(this, &frmMain::exitToolStripMenuItem1_Click);
			// 
			// fontsToolStripMenuItem
			// 
			this->fontsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->createToolStripMenuItem });
			this->fontsToolStripMenuItem->Name = L"fontsToolStripMenuItem";
			this->fontsToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->fontsToolStripMenuItem->Text = L"Fonts";
			// 
			// createToolStripMenuItem
			// 
			this->createToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"createToolStripMenuItem.Image")));
			this->createToolStripMenuItem->Name = L"createToolStripMenuItem";
			this->createToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->createToolStripMenuItem->Text = L"Create...";
			this->createToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::createToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutToolStripMenuItem,
					this->gitHubToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutToolStripMenuItem.Image")));
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::aboutToolStripMenuItem_Click);
			// 
			// gitHubToolStripMenuItem
			// 
			this->gitHubToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gitHubToolStripMenuItem.Image")));
			this->gitHubToolStripMenuItem->Name = L"gitHubToolStripMenuItem";
			this->gitHubToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->gitHubToolStripMenuItem->Text = L"GitHub";
			this->gitHubToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMain::gitHubToolStripMenuItem_Click);
			// 
			// pbBanner
			// 
			this->pbBanner->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbBanner.Image")));
			this->pbBanner->Location = System::Drawing::Point(0, 25);
			this->pbBanner->Margin = System::Windows::Forms::Padding(2);
			this->pbBanner->Name = L"pbBanner";
			this->pbBanner->Size = System::Drawing::Size(585, 89);
			this->pbBanner->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbBanner->TabIndex = 9;
			this->pbBanner->TabStop = false;
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(588, 318);
			this->Controls->Add(this->pbBanner);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->btnToggle);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnAbout);
			this->Controls->Add(this->lblHotkeyInfo);
			this->Controls->Add(this->txtHotkey);
			this->Controls->Add(this->lblHotkey);
			this->Controls->Add(this->lvFontList);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"frmMain";
			this->Load += gcnew System::EventHandler(this, &frmMain::frmMain_Load);
			this->ctxTNAMenu->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbBanner))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Drawing::Color clrDefaultFormColor;
	private: bool bHideOnStartup;

	private: bool LoadFontSets() {
		array<System::String^>^ aFileNames = Directory::GetFiles(Path::GetDirectoryName(Application::ExecutablePath) + "\\fontsets");

		IEnumerator^ oFileEnumerator = aFileNames->GetEnumerator();
		while (oFileEnumerator->MoveNext())
		{
		System::String^ szFileName = safe_cast<System::String^>(oFileEnumerator->Current);
		std::wstring wszFileName = msclr::interop::marshal_as<std::wstring>(szFileName);

		if (!g_oUFWMgr.LoadLetterFile(wszFileName)) {
			MessageBox::Show("LoadLetterFile() failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return false;
		}
		}

		for (size_t i = 0; i < g_oUFWMgr.GetFontSetCount(); i++) {
			letter_data_s sCurData;

			if (!g_oUFWMgr.GetLetterData(i, sCurData)) {
				return false;
			}

			cli::array<System::String^>^ aItems = gcnew cli::array<System::String^>(3);
			marshal_context context;
			aItems[0] = context.marshal_as<System::String^>(sCurData.wszFontName);

			System::String^ szAlphabet = "";
			for (size_t j = 0; j < UFWMGR_ALPHABETCHARAMOUNT; j++) {
				szAlphabet += context.marshal_as<System::String^>(sCurData.wszaLetterString[j]);
			}

			aItems[1] = szAlphabet;
			aItems[2] = "";
			ListViewItem^ lvItem = gcnew ListViewItem(aItems);
			this->lvFontList->Items->Add(lvItem);
		}

		return true;
	}

	public: System::Void AddNewFontset(System::String^ szFontName, System::String^ szAlphabet) {
		cli::array<System::String^>^ aItems = gcnew cli::array<System::String^>(3);

		aItems[0] = szFontName;
		aItems[1] = szAlphabet;
		aItems[2] = "";

		ListViewItem^ lvItem = gcnew ListViewItem(aItems);
		this->lvFontList->Items->Add(lvItem);
	}

	private: System::Void ToggleActivation() {
				 //Toggle activation status

				g_oUFWMgr.SetActivationStatus(!g_oUFWMgr.GetActivationStatus());

				if (g_oUFWMgr.GetActivationStatus()) {
					this->BackColor = System::Drawing::Color::LightGreen;
					this->niTNAIcon->Text = PROGRAM_NAME + " - Activated";

					Beep(1000, 100);
				} else {
					this->BackColor = this->clrDefaultFormColor;
					this->niTNAIcon->Text = PROGRAM_NAME;

					Beep(500, 100);
				}
			 }

	private: System::Void SelectFontset(System::String^ szFontSet) {
				 //Select fontset from list

				 std::wstring wszFontName = msclr::interop::marshal_as<std::wstring>(szFontSet);

				 if (!g_oUFWMgr.SelectLetterSet(wszFontName)) {
					 MessageBox::Show("SelectLetterSet() failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 return;
				 }

				 for (int i = 0; i < this->lvFontList->Items->Count; i++) {
					 if (this->lvFontList->Items[i]->Text == szFontSet)
						  this->lvFontList->Items[i]->SubItems[2]->Text = "Selected";
					 else
						this->lvFontList->Items[i]->SubItems[2]->Text = "";
				 }
			 }

	protected: virtual void WndProc(Message %m) override {
				   //WndProc overrider method

				   //Handle hotkey
				   if ((m.Msg == WM_HOTKEY) && ((int)m.WParam == HK_TOGGLE)) {
					   this->ToggleActivation();
				   }

				   //Pass message
				   Form::WndProc(m);
			   }

	private: System::Void frmMain_Load(System::Object^  sender, System::EventArgs^  e) {
				 //Form load event method

				 this->Text = PROGRAM_NAME;

				 bool bAlreadyRunning = System::Diagnostics::Process::GetProcessesByName(System::IO::Path::GetFileNameWithoutExtension(System::Reflection::Assembly::GetEntryAssembly()->Location))->Length > 1;
				 if (bAlreadyRunning) {
					 MessageBox::Show("An instance of the program is already running.", PROGRAM_NAME, MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					 Application::Exit();
				 }

				 this->Shown += gcnew System::EventHandler(this, &frmMain::frmMain_Shown);
				 this->Resize += gcnew System::EventHandler(this, &frmMain::frmMain_Resize);
				 this->Closing += gcnew CancelEventHandler(this, &frmMain::frmMain_Closing);
				 this->lvFontList->MouseDoubleClick += gcnew MouseEventHandler(this, &frmMain::lvFontList_MouseDoubleClick);
				 this->txtHotkey->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &frmMain::txtHotkey_KeyUp);

				 this->clrDefaultFormColor = this->BackColor;

				 this->niTNAIcon->Click += gcnew System::EventHandler(this, &frmMain::niTNAIcon_Click);
				 this->niTNAIcon->Visible = false;
				 #undef ExtractAssociatedIcon
				 this->niTNAIcon->Icon = System::Drawing::Icon::ExtractAssociatedIcon(Assembly::GetExecutingAssembly()->Location);

				 if (!g_oUFWMgr.Initialize()) {
					 MessageBox::Show("Initialize() failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 Application::Exit();
				 }

				 LoadFontSets();

				 this->txtHotkey->Text = File::ReadAllText(Path::GetDirectoryName(Application::ExecutablePath) + "\\hotkey.txt");
				 if (!RegisterHotKey((HWND)this->Handle.ToPointer(), HK_TOGGLE, MOD_CONTROL, Convert::ToInt32(this->txtHotkey->Text))) {
					 MessageBox::Show("RegisterHotKey() failed: " + GetLastError().ToString(), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }

				 System::Windows::Forms::Keys oKey = (System::Windows::Forms::Keys)Convert::ToInt32(this->txtHotkey->Text);
				 this->lblHotkeyInfo->Text = "Ctrl+" + oKey.ToString();

				 if (File::Exists(Path::GetDirectoryName(Application::ExecutablePath) + "\\selection.txt")) {
					 System::String^ szStartSelection = File::ReadAllText(Path::GetDirectoryName(Application::ExecutablePath) + "\\selection.txt");

					 SelectFontset(szStartSelection);
				 }

				 this->CenterToScreen();
			 }
	private: System::Void frmMain_Shown(System::Object^ sender, System::EventArgs^ e) {
				 //this->lvFontList->BackColor = System::Drawing::Color::FromArgb(0xFF, 0x82, 0xC5, 0xE6);

				 if (bHideOnStartup)
					 this->WindowState = FormWindowState::Minimized;
			 }
	private: System::Void frmMain_Closing( Object^ sender, CancelEventArgs^ e ) {
				 //Form closing event

				 File::WriteAllText(Path::GetDirectoryName(Application::ExecutablePath) + "\\hotkey.txt", this->txtHotkey->Text);

				 for (int i = 0; i < this->lvFontList->Items->Count; i++) {
					 if (this->lvFontList->Items[i]->SubItems[2]->Text == "Selected") {
						 File::WriteAllText(Path::GetDirectoryName(Application::ExecutablePath) + "\\selection.txt", this->lvFontList->Items[i]->Text);
					 }
				 }

				 g_oUFWMgr.SetActivationStatus(false);
				 g_oUFWMgr.Free();

				 UnregisterHotKey(NULL, HK_TOGGLE);
			 }
	private: System::Void frmMain_Resize(System::Object^ sender, System::EventArgs^ e) {
				//Called for form resize events

				if (this->WindowState == FormWindowState::Minimized) { //Form shall be minimized
					//Update NotifyIcon data, add icon to tray bar and hide form
					this->niTNAIcon->Text = PROGRAM_NAME;
					if (g_oUFWMgr.GetActivationStatus()) this->niTNAIcon->Text += " - Activated";
					this->niTNAIcon->Visible = true;
					this->Hide();
				} else if (this->WindowState == FormWindowState::Normal) {
					//Remove icon from taskbar notification bar
					this->niTNAIcon->Text = PROGRAM_NAME;
					this->niTNAIcon->Visible = false;
				}
			 }
	private: void txtHotkey_KeyUp(Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
				 int iKeyCode = (int)e->KeyCode;
				 this->txtHotkey->Text = iKeyCode.ToString();
				 this->lblHotkeyInfo->Text = "Ctrl+" + e->KeyCode.ToString();

				 UnregisterHotKey((HWND)this->Handle.ToPointer(), HK_TOGGLE);

				 if (!RegisterHotKey((HWND)this->Handle.ToPointer(), HK_TOGGLE, MOD_CONTROL, Convert::ToInt32(this->txtHotkey->Text))) {
					 MessageBox::Show("RegisterHotKey() failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					 Application::Exit();
				 }
				 e->Handled = true;
			 }

	private: System::Void niTNAIcon_Click( Object^ sender, System::EventArgs^ e) {
				//Called when clicking at the taskbar notification bar program icon

				System::Windows::Forms::MouseEventArgs^ evts = (System::Windows::Forms::MouseEventArgs^)e;
				if (evts->Button == System::Windows::Forms::MouseButtons::Left) {
					//Hide icon, show form and normalize form status
					this->niTNAIcon->Visible = false;
					this->Show();
					this->WindowState = FormWindowState::Normal;
				}
			}
	private: System::Void lvFontList_MouseDoubleClick(System::Object^ sender, MouseEventArgs^ e) {
				//Listview doubleclick event

				std::wstring wszFontName = msclr::interop::marshal_as<std::wstring>(lvFontList->Items[this->lvFontList->SelectedIndices[0]]->Text);

				if (!g_oUFWMgr.SelectLetterSet(wszFontName)) {
					 MessageBox::Show("SelectLetterSet() failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				} else {
					for (int i = 0; i < this->lvFontList->Items->Count; i++) {
						this->lvFontList->Items[i]->SubItems[2]->Text = "";
					}

					this->lvFontList->Items[this->lvFontList->SelectedIndices[0]]->SubItems[2]->Text = "Selected";
				}
			 }
	private: System::Void lvFontList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void btnExit_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void btnAbout_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show(PROGRAM_NAME " v" PROGRAM_VERSION " developed by " PROGRAM_AUTHOR + Environment::NewLine +  Environment::NewLine + "Visit: " PROGRAM_WEBSITE, "About", MessageBoxButtons::OK, MessageBoxIcon::Information);
		 }
private: System::Void showToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Hide icon, show form and normalize form status
			this->niTNAIcon->Visible = false;
			this->Show();
			this->WindowState = FormWindowState::Normal;
		 }
private: System::Void toggleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->ToggleActivation();
		 }
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void niTNAIcon_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		 }
private: System::Void ctxTNAMenu_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }
private: System::Void btnToggle_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->ToggleActivation();
		 }
private: System::Void toggleToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnToggle->PerformClick();
}
private: System::Void exitToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnExit->PerformClick();
}
private: System::Void createToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	frmNewFont^ oFrmNewFont = gcnew frmNewFont;
	oFrmNewFont->Show();
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->btnAbout->PerformClick();
}
private: System::Void gitHubToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Diagnostics::Process::Start(PROGRAM_WEBSITE);
}
};
}

