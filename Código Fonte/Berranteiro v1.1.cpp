//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("Login.cpp", Form7);
USEFORM("Menu.cpp", Form1);
USEFORM("Ranking.cpp", Form5);
USEFORM("Teste.cpp", Form6);
USEFORM("Fase3.cpp", Form4);
USEFORM("Fase2.cpp", Form3);
USEFORM("Fase1.cpp", Form2);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TForm7), &Form7);
		Application->FormFactor->Orientations = TScreenOrientations() << TScreenOrientation::Landscape;
		//Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
