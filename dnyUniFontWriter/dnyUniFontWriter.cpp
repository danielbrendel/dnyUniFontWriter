#include "stdafx.h"
#include "frmMain.h"

/*
	UniFont Writer (dnyUniFontWriter) developed by Daniel Brendel

	(C) 2018 - 2023 by Daniel Brendel

	Version: 0.1
	Contact: dbrendel1988<at>gmail<dot>com
	GitHub: https://github.com/danielbrendel/

	License: The MIT License
			 
*/

#pragma comment(lib, "user32.lib")

using namespace dnyUniFontWriter;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	//Enable visual effect styles
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	//Create and run main window
	Application::Run(gcnew frmMain(args));
	return 0;
}
