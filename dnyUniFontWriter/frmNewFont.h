#pragma once

#include "ufwmgr.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

/*
	UniFont Writer (dnyUniFontWriter) developed by Daniel Brendel

	(C) 2018 - 2022 by Daniel Brendel

	Version: 0.1
	Contact: dbrendel1988<at>gmail<dot>com
	GitHub: https://github.com/danielbrendel/

	License: The MIT License
			 
*/

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
	/// Zusammenfassung für frmNewFont
	/// </summary>
	public ref class frmNewFont : public System::Windows::Forms::Form
	{
	public:
		frmNewFont(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~frmNewFont()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Button^  btnAbort;
	private: System::Windows::Forms::TextBox^  textBox26;
	private: System::Windows::Forms::TextBox^  textBox25;
	private: System::Windows::Forms::TextBox^  textBox24;
	private: System::Windows::Forms::TextBox^  textBox23;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  txtFontName;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmNewFont::typeid));
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnAbort = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->txtFontName = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox26);
			this->groupBox1->Controls->Add(this->textBox25);
			this->groupBox1->Controls->Add(this->textBox24);
			this->groupBox1->Controls->Add(this->textBox23);
			this->groupBox1->Controls->Add(this->textBox22);
			this->groupBox1->Controls->Add(this->textBox21);
			this->groupBox1->Controls->Add(this->textBox20);
			this->groupBox1->Controls->Add(this->textBox19);
			this->groupBox1->Controls->Add(this->textBox18);
			this->groupBox1->Controls->Add(this->textBox17);
			this->groupBox1->Controls->Add(this->textBox16);
			this->groupBox1->Controls->Add(this->textBox15);
			this->groupBox1->Controls->Add(this->textBox14);
			this->groupBox1->Controls->Add(this->textBox13);
			this->groupBox1->Controls->Add(this->textBox12);
			this->groupBox1->Controls->Add(this->textBox11);
			this->groupBox1->Controls->Add(this->textBox10);
			this->groupBox1->Controls->Add(this->textBox9);
			this->groupBox1->Controls->Add(this->textBox8);
			this->groupBox1->Controls->Add(this->textBox7);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label26);
			this->groupBox1->Controls->Add(this->label25);
			this->groupBox1->Controls->Add(this->label24);
			this->groupBox1->Controls->Add(this->label23);
			this->groupBox1->Controls->Add(this->label22);
			this->groupBox1->Controls->Add(this->label21);
			this->groupBox1->Controls->Add(this->label20);
			this->groupBox1->Controls->Add(this->label19);
			this->groupBox1->Controls->Add(this->label18);
			this->groupBox1->Controls->Add(this->label17);
			this->groupBox1->Controls->Add(this->label16);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(16, 103);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox1->Size = System::Drawing::Size(661, 401);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L" Characters ";
			// 
			// textBox26
			// 
			this->textBox26->Location = System::Drawing::Point(548, 79);
			this->textBox26->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(89, 22);
			this->textBox26->TabIndex = 51;
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(548, 32);
			this->textBox25->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(89, 22);
			this->textBox25->TabIndex = 50;
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(373, 361);
			this->textBox24->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(89, 22);
			this->textBox24->TabIndex = 49;
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(373, 313);
			this->textBox23->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(89, 22);
			this->textBox23->TabIndex = 48;
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(373, 265);
			this->textBox22->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(89, 22);
			this->textBox22->TabIndex = 47;
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(375, 218);
			this->textBox21->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(88, 22);
			this->textBox21->TabIndex = 46;
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(375, 172);
			this->textBox20->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(88, 22);
			this->textBox20->TabIndex = 45;
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(375, 127);
			this->textBox19->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(88, 22);
			this->textBox19->TabIndex = 44;
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(376, 79);
			this->textBox18->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(87, 22);
			this->textBox18->TabIndex = 43;
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(376, 32);
			this->textBox17->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(87, 22);
			this->textBox17->TabIndex = 42;
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(211, 361);
			this->textBox16->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(87, 22);
			this->textBox16->TabIndex = 41;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(211, 313);
			this->textBox15->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(87, 22);
			this->textBox15->TabIndex = 40;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(211, 265);
			this->textBox14->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(87, 22);
			this->textBox14->TabIndex = 39;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(211, 218);
			this->textBox13->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(87, 22);
			this->textBox13->TabIndex = 38;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(211, 172);
			this->textBox12->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(87, 22);
			this->textBox12->TabIndex = 37;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(211, 130);
			this->textBox11->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(87, 22);
			this->textBox11->TabIndex = 36;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(211, 79);
			this->textBox10->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(87, 22);
			this->textBox10->TabIndex = 35;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(211, 32);
			this->textBox9->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(87, 22);
			this->textBox9->TabIndex = 34;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(48, 361);
			this->textBox8->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(84, 22);
			this->textBox8->TabIndex = 33;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(48, 313);
			this->textBox7->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(84, 22);
			this->textBox7->TabIndex = 32;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(48, 265);
			this->textBox6->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(84, 22);
			this->textBox6->TabIndex = 31;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(48, 218);
			this->textBox5->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(84, 22);
			this->textBox5->TabIndex = 30;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(48, 169);
			this->textBox4->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(84, 22);
			this->textBox4->TabIndex = 29;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(48, 127);
			this->textBox3->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(84, 22);
			this->textBox3->TabIndex = 28;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(48, 79);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(84, 22);
			this->textBox2->TabIndex = 27;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(189, 36);
			this->label26->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(11, 17);
			this->label26->TabIndex = 26;
			this->label26->Text = L"I";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(17, 364);
			this->label25->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(18, 17);
			this->label25->TabIndex = 25;
			this->label25->Text = L"H";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(348, 36);
			this->label24->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(19, 17);
			this->label24->TabIndex = 24;
			this->label24->Text = L"Q";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(348, 176);
			this->label23->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(17, 17);
			this->label23->TabIndex = 23;
			this->label23->Text = L"T";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(191, 172);
			this->label22->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(16, 17);
			this->label22->TabIndex = 22;
			this->label22->Text = L"L";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(347, 268);
			this->label21->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(17, 17);
			this->label21->TabIndex = 21;
			this->label21->Text = L"V";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(189, 130);
			this->label20->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(17, 17);
			this->label20->TabIndex = 20;
			this->label20->Text = L"K";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(347, 364);
			this->label19->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(17, 17);
			this->label19->TabIndex = 19;
			this->label19->Text = L"X";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(521, 82);
			this->label18->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(17, 17);
			this->label18->TabIndex = 18;
			this->label18->Text = L"Z";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(347, 316);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(21, 17);
			this->label17->TabIndex = 17;
			this->label17->Text = L"W";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(187, 364);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(17, 17);
			this->label16->TabIndex = 16;
			this->label16->Text = L"P";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(189, 316);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(19, 17);
			this->label15->TabIndex = 15;
			this->label15->Text = L"O";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(23, 268);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(16, 17);
			this->label14->TabIndex = 14;
			this->label14->Text = L"F";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(188, 268);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(18, 17);
			this->label13->TabIndex = 13;
			this->label13->Text = L"N";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(348, 134);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(17, 17);
			this->label12->TabIndex = 12;
			this->label12->Text = L"S";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(189, 222);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(19, 17);
			this->label11->TabIndex = 11;
			this->label11->Text = L"M";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(348, 82);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(18, 17);
			this->label10->TabIndex = 10;
			this->label10->Text = L"R";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(521, 36);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(17, 17);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Y";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(347, 222);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(18, 17);
			this->label8->TabIndex = 8;
			this->label8->Text = L"U";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(189, 82);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(15, 17);
			this->label7->TabIndex = 7;
			this->label7->Text = L"J";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(17, 316);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(19, 17);
			this->label6->TabIndex = 6;
			this->label6->Text = L"G";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(21, 222);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(17, 17);
			this->label5->TabIndex = 5;
			this->label5->Text = L"E";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(20, 172);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(18, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"D";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(20, 130);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 17);
			this->label3->TabIndex = 3;
			this->label3->Text = L"C";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 82);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"B";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(48, 32);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(84, 22);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(21, 36);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"A";
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(16, 528);
			this->btnSave->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(107, 41);
			this->btnSave->TabIndex = 1;
			this->btnSave->Text = L"Save";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &frmNewFont::btnSave_Click);
			// 
			// btnAbort
			// 
			this->btnAbort->Location = System::Drawing::Point(131, 528);
			this->btnAbort->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnAbort->Name = L"btnAbort";
			this->btnAbort->Size = System::Drawing::Size(105, 41);
			this->btnAbort->TabIndex = 2;
			this->btnAbort->Text = L"Abort";
			this->btnAbort->UseVisualStyleBackColor = true;
			this->btnAbort->Click += gcnew System::EventHandler(this, &frmNewFont::btnAbort_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->txtFontName);
			this->groupBox2->Location = System::Drawing::Point(16, 12);
			this->groupBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->groupBox2->Size = System::Drawing::Size(661, 84);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L" Font Name ";
			// 
			// txtFontName
			// 
			this->txtFontName->Location = System::Drawing::Point(48, 37);
			this->txtFontName->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtFontName->Name = L"txtFontName";
			this->txtFontName->Size = System::Drawing::Size(560, 22);
			this->txtFontName->TabIndex = 0;
			// 
			// frmNewFont
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(696, 583);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->btnAbort);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->groupBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximizeBox = false;
			this->Name = L"frmNewFont";
			this->Text = L"frmNewFont";
			this->Load += gcnew System::EventHandler(this, &frmNewFont::frmNewFont_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: bool SaveFont(System::String^ szFontName) {
		try {
			std::wstring wszPath = msclr::interop::marshal_as<std::wstring>(Path::GetDirectoryName(Application::ExecutablePath) + "\\fontsets\\");
			std::wstring wszFontName = msclr::interop::marshal_as<std::wstring>(szFontName);

			std::wstring wszAlphabet = msclr::interop::marshal_as<std::wstring>(
				textBox1->Text + ";" +
				textBox2->Text + ";" +
				textBox3->Text + ";" +
				textBox4->Text + ";" +
				textBox5->Text + ";" +
				textBox6->Text + ";" +
				textBox7->Text + ";" +
				textBox8->Text + ";" +
				textBox9->Text + ";" +
				textBox10->Text + ";" +
				textBox11->Text + ";" +
				textBox12->Text + ";" +
				textBox13->Text + ";" +
				textBox14->Text + ";" +
				textBox15->Text + ";" +
				textBox16->Text + ";" +
				textBox17->Text + ";" +
				textBox18->Text + ";" +
				textBox19->Text + ";" +
				textBox20->Text + ";" +
				textBox21->Text + ";" +
				textBox22->Text + ";" +
				textBox23->Text + ";" +
				textBox24->Text + ";" +
				textBox25->Text + ";" +
				textBox26->Text + ";"
				);

			return g_oUFWMgr.SaveLetterFile(wszPath, wszFontName, wszAlphabet);
		} catch (Exception^) {
			return false;
		}

		return true;
	}

	private: System::Void frmNewFont_Load(System::Object^  sender, System::EventArgs^  e) {
		this->CenterToScreen();
	}
	private: System::Void btnAbort_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) {
		if (this->SaveFont(txtFontName->Text)) {
			MessageBox::Show("The new font has been saved.", "New Font", MessageBoxButtons::OK, MessageBoxIcon::Information);
		} else {
			MessageBox::Show("Failed to save the new font.", "New Font", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		this->Close();
	}
};
}
