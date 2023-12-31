//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Menu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	fase1 = NULL;
	fase2 = NULL;
	fase3 = NULL;
    FDConnection1->Params->Values["Database"] =
		System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), "Ranking.db");
	FDConnection1->Params->Database = System::Ioutils::TPath::Combine(System::Ioutils::TPath::GetDocumentsPath
		(), L"Ranking.db");
	construtor = new Construtor(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::selecionarBotao(TObject *Sender)
{
	dynamic_cast <TButton*> (Sender)->FontColor = TAlphaColor(TAlphaColorRec::Blue);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::desselecionarBotao(TObject *Sender)
{
	dynamic_cast <TButton*> (Sender)->FontColor = TAlphaColor(TAlphaColorRec::White);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::executarFase1(TObject* Sender)
{
	clock_t timer = clock();
	//Button1->Visible = false;
	//Label1->Visible = false;
	//Label2->Visible = true;
	if (fase2) {
		delete fase2;
		fase2 = NULL;
	}
	if (fase3) {
		delete fase3;
		fase3 = NULL;
	}
    if (construtor->getExecutando() == 3) {
			fase1->setF1(construtor->getFase1());
            fase1->setTimer(1);
			this->Hide();
			fase1->Show();
			Timer1->Enabled = false;
			construtor->setExecutando(0);
			return;
	}
	else if (construtor->getExecutando() == 0) {
    		delete construtor;
			construtor = new Construtor(1);
			Label1->Visible = false;
			Button1->Visible = false;
			Button2->Visible = false;
			Button3->Visible = false;
			Button4->Visible = false;
			Button5->Visible = false;
			Button6->Visible = false;
			Label2->Visible = true;
			fase1 = new TForm2(this);
			fase1->setTimer(0);
			construtor->setNum(1);
			construtor->setOwner(fase1);
			construtor->setParent(fase1);
			construtor->Start();
	}
	else {
		ShowMessage("Carregando fase. Aguarde.");
	}

	/*System::Classes::TComponent* o = this;
	String timeStarted = DateTimeToStr(Now());
	TThread::CreateAnonymousThread(
		  [timeStarted]() {
		   fase1 = new TForm2(o); // Some lengthy work done in worker thread
		   TThread::Synchronize(nullptr, _di_TThreadProcedure([timeStarted] {
				 ShowMessage(String("DONE: Job started @ ")+timeStarted);
		   }));
		  })->Start(); */

	//Label2->Visible = false;
	//fase1->Show();
	//Hide();
	//ShowMessage("Total: ");
	//ShowMessage((float) (clock() - timer) /CLOCKS_PER_SEC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::executarFase2(TObject *Sender)
{
	clock_t timer = clock();
	//Button1->Visible = false;
	//Label1->Visible = false;
	//Label2->Visible = true;
	if (fase1) {
		delete fase1;
		fase1 = NULL;
	}
	if (fase3) {
		delete fase3;
		fase3 = NULL;
	}
     if (construtor->getExecutando() == 3) {
			fase2->setF2(construtor->getFase2());
			fase2->setTimer(1);
			this->Hide();
			fase2->Show();
			Timer1->Enabled = false;
			construtor->setExecutando(0);
			return;
	}
	else if (construtor->getExecutando() == 0) {
    		delete construtor;
			construtor = new Construtor(1);
			Label1->Visible = false;
			Button1->Visible = false;
			Button2->Visible = false;
			Button3->Visible = false;
			Button4->Visible = false;
			Button5->Visible = false;
			Button6->Visible = false;
			Label2->Visible = true;
			fase2 = new TForm3(this);
			fase2->setTimer(0);
			construtor->setNum(2);
			construtor->setOwner(fase2);
			construtor->setParent(fase2);
			construtor->Start();
	}
	else {
		ShowMessage("Carregando fase. Aguarde.");
	}
	//fase2 = new TForm3(this);
	//Label2->Visible = false;
	//fase2->Show();
	//Hide();
	//ShowMessage("Total: ");
	//ShowMessage((float) (clock() - timer) /CLOCKS_PER_SEC);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::executarFase3(TObject *Sender)
{
    clock_t timer = clock();
	//Button1->Visible = false;
	//Label1->Visible = false;
	//Label2->Visible = true;
	if (fase1) {
		delete fase1;
		fase1 = NULL;
	}
	if (fase2) {
		delete fase2;
		fase2 = NULL;
	}
     if (construtor->getExecutando() == 3) {
			fase3->setF3(construtor->getFase3());
			fase3->setTimer(1);
			this->Hide();
			fase3->Show();
			Timer1->Enabled = false;
            construtor->setExecutando(0);
			return;
	}
	else if (construtor->getExecutando() == 0) {
    		delete construtor;
			construtor = new Construtor(1);
			Label1->Visible = false;
			Button1->Visible = false;
			Button2->Visible = false;
			Button3->Visible = false;
			Button4->Visible = false;
			Button5->Visible = false;
			Button6->Visible = false;
			Label2->Visible = true;
			fase3 = new TForm4(this);
			fase3->setTimer(0);
			construtor->setNum(3);
			construtor->setOwner(fase3);
			construtor->setParent(fase3);
			construtor->Start();
	}
	else {
		ShowMessage("Carregando fase. Aguarde.");
	}
	//fase3 = new TForm4(this);
	//Label2->Visible = false;
	//fase3->Show();
	//Hide();
	//ShowMessage("Total: ");
	//ShowMessage((float) (clock() - timer) /CLOCKS_PER_SEC);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::executarRanking(TObject *Sender)
{
	ranking = new TForm5(this);
	ranking->Show();
	//teste = new TForm6(this);
    //teste->Show();
	this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::login(TObject *Sender)
{
	dynamic_cast <TForm*> (this->Owner)->Show();
	this->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::resumir(TObject *Sender)
{
	if (fase1 == NULL && fase2 == NULL && fase3 == NULL) return;
	if (fase1) {
		fase1->Show();
		fase1->Timer1->Enabled = true;
	}
	else if (fase2) {
		fase2->Show();
		fase2->Timer1->Enabled = true;
	}
	else if (fase3) {
		fase3->Show();
		fase3->Timer1->Enabled = true;
	}
    this->Hide();
}
//---------------------------------------------------------------------------
void TForm1::mostrarItens() {
	Label1->BringToFront();
	Label1->Visible = true;
	Button1->BringToFront();
	Button1->Visible = true;
	Button2->BringToFront();
	Button2->Visible = true;
	Button3->BringToFront();
	Button3->Visible = true;
	Button4->BringToFront();
	Button4->Visible = true;
	Button5->BringToFront();
	Button5->Visible = true;
	Button6->BringToFront();
	Button6->Visible = true;
}

void TForm1::setUsuario(System::UnicodeString s) { usuario = s; };

void TForm1::atualizaPontos() {
	int total = 0;
	if (fase1) total = fase1->getF1()->getJogador()->getPontos();
	else if (fase2) total = fase2->getF2()->getJogador()->getPontos();
	else if (fase3) total = fase3->getF3()->getJogador()->getPontos();


    FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	if (fase1) FDQuery1->SQL->Text = "select Pontos_F1 as pontos from Ranking where Nome = '"+usuario+"';";
	else if (fase2) FDQuery1->SQL->Text = "select Pontos_F2 as pontos from Ranking where Nome = '"+usuario+"';";
	else if (fase3) FDQuery1->SQL->Text = "select Pontos_F3 as pontos from Ranking where Nome = '"+usuario+"';";
	FDQuery1->Active = true;

	if (FDQuery1->IsEmpty()) {
		ShowMessage("Nome nao encontrado.");
		return;
	}

	//ShowMessage("Parte 1 concluida");

	if (FDQuery1->FieldByName("pontos")->AsInteger >= total) return;



	FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	if (fase1) FDQuery1->SQL->Text = "update Ranking set Pontos_F1 = "+System::UnicodeString((int) fase1->getF1()->getJogador()->getPontos())+" where Nome = '"+usuario+"';";
	else if (fase2) FDQuery1->SQL->Text = "update Ranking set Pontos_F2 = "+System::UnicodeString((int) fase2->getF2()->getJogador()->getPontos())+" where Nome = '"+usuario+"';";
	else if (fase3) FDQuery1->SQL->Text = "update Ranking set Pontos_F3 = "+System::UnicodeString((int) fase3->getF3()->getJogador()->getPontos())+" where Nome = '"+usuario+"';";
    //ShowMessage("Parte 2 a ser executada...");
	FDQuery1->ExecSQL();
}

void TForm1::verifResumir() {
	if (fase1 == NULL && fase2 == NULL && fase3 == NULL) {
		 Button6->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::Gray;
		 Button6->Enabled = false;
	}
	else {
		Button6->TextSettings->FontColor = System::Uitypes::TAlphaColorRec::White;
		Button6->Enabled = true;
    }
}

void TForm1::atualizaTempo() {
	clock_t total = 0;
	if (fase1) total = clock() - fase1->getF1()->getTempoInicio();
	else if (fase2) total = clock() - fase2->getF2()->getTempoInicio();
	else if (fase3) total = clock() - fase3->getF3()->getTempoInicio();

	total /= CLOCKS_PER_SEC;
	System::UnicodeString ap1("");
	System::UnicodeString ap2("");
	System::UnicodeString ap3("");
	int seg = total % 60;
	if (seg < 10) ap3 = ap3 + System::UnicodeString("0");
	int min = (total / 60) % 60;
	if (min < 10) ap1 = ap1 + System::UnicodeString("0");
	int hora = total / 3600;
	if (hora < 10) ap2 = ap2 + System::UnicodeString("0");
	System::UnicodeString tempo = ap2 + System::UnicodeString((int) hora) + System::UnicodeString(":") +
	ap1 + System::UnicodeString((int) min) + System::UnicodeString(":") +
	ap3 + System::UnicodeString((int) seg);
	ShowMessage(tempo);


    FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	if (fase1) FDQuery1->SQL->Text = "select Tempo_F1 as pontos from Ranking where Nome = '"+usuario+"';";
	else if (fase2) FDQuery1->SQL->Text = "select Tempo_F2 as pontos from Ranking where Nome = '"+usuario+"';";
	else if (fase3) FDQuery1->SQL->Text = "select Tempo_F3 as pontos from Ranking where Nome = '"+usuario+"';";
	FDQuery1->Active = true;
	//ShowMessage("Query 1 Terminada.");

	if (FDQuery1->FieldByName("pontos")->AsString <= tempo) return;



	FDQuery1->Active = false;
	FDQuery1->SQL->Clear();
	if (fase1) FDQuery1->SQL->Text = "update Ranking set Tempo_F1 = '"+tempo+"' where Nome = '"+usuario+"';";
	else if (fase2) FDQuery1->SQL->Text = "update Ranking set Tempo_F2 = '"+tempo+"' where Nome = '"+usuario+"';";
	else if (fase3) FDQuery1->SQL->Text = "update Ranking set Tempo_F3 = '"+tempo+"' where Nome = '"+usuario+"';";
	FDQuery1->ExecSQL();
}

void __fastcall TForm1::ajustar(TObject *Sender)
{
	construtor->setExecutando(0);
    Timer1->Enabled = true;
	desselecionarBotao(Button1);
	desselecionarBotao(Button2);
	desselecionarBotao(Button3);
	Label2->Visible = false;
    mostrarItens();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::verif_fase_construida(TObject *Sender)
{
	if (construtor->getExecutando() == 3) {
		if (construtor->getNum() == 1) executarFase1(Button1);
		else if (construtor->getNum() == 2) executarFase2(Button2);
		else if (construtor->getNum() == 3) executarFase3(Button3);
    }
}
//---------------------------------------------------------------------------

void TForm1::ShowCarregando() {
	Show();
    Label1->Visible = false;
	Button1->Visible = false;
	Button2->Visible = false;
	Button3->Visible = false;
	Button4->Visible = false;
	Button5->Visible = false;
	Button6->Visible = false;
	Label2->Visible = true;
}

