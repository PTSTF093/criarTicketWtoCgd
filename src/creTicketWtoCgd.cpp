//===========================================================================
//
//	Module:	    api_notes
//
//	Description:
//			Cria um doc notes e inclui campos.
//
//	Syntax:	api_notes <pares de tuplas com "nome_campo" "conteúdo">
//
//===========================================================================
/*
 * Para executar é necessário:
 *
 * deprecated::::::::::::::LD_LIBRARY_PATH=/opt/ibm/lotus/notes
 * deprecated::::::::::::::export LD_LIBRARY_PATH
 *
 * Símbolos para o Preprocessor, tanto GCC como G++:
 * -DLINUX
 * -DHANDLE_IS_32BITS
 *
 * Inludes:
 * *****includes do c++ notes api:
 * -I/home/ptsca012/lotus/notes/notescpp/include
 *
 *	Deverá incluir no linkagem a lib:
 *	cpplin
 *
 *	foi criado na dir /etc/ld.so.conf.d
 *	o ficheiro api_notes.conf com o seguinte conteúdo:
 *		/opt/ibm/lotus/notes
 *	depois foi executado: "sudo ldconfig"
 *	assim a library libcpplin.so fica sempre "encontrável"
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "CReloj.h"
#include "CNotesApi.h"

using namespace std;



int main(int argc, char *argv[])
{
	//system("LD_LIBRARY_PATH=/opt/ibm/lotus/notes");
	//system("export LD_LIBRARY_PATH");

	//	cout<<"argc="<<argc<<endl;
	//	cout<<"argv="<<argv<<endl;
	//
	//	return 0;

	//CMysql my;
	CReloj timer;//capturar a o time instantaneo
	CNotesApi Incidents(argc, argv);
	if (!Incidents.GetStatus())
	{
		cout << "erro, tente novamente." << endl;
		return 1;
	}
	CFieldsQueue Campos;
	CFormField * campo;

	if(argc%2!=1)//tem q ser impar
	{
		cout<<"erro na contagem de parametros"<<endl;
		return 3;
	}
	for(int i=1;i<argc;i+=2)
	{
		Campos.Add( CFormField(argv[i],argv[i+1]) );
	}

	//my.start("127.0.0.1","root","OpenPipes","pipes");

	//campos obrigatórios, hidden e com tratamento especial
	Campos.Add(CFormField("Shifttype",timer.GetShifttype()));	//
	Campos.Add(CFormField("ShiftStart",timer.GetShiftStartDate()));	//
	//Campos.Add(CFormField("Time",timer.GetHoraAgora()));	//
	Campos.Add(CFormField("Date",timer.GetDataAgora_dd_mm_aaaa_pontos()));

	Campos.Add(CFormField("Creator","Opipes"));	//
	Campos.Add(CFormField("Subject","REQUEST"));	//
	Campos.Add(CFormField("Status","Open"));	//criar sempre em aberto
	Campos.Add(CFormField("Customer","CGD"));	//
	Campos.Add(CFormField("Priority_1","SEVERITY 2"));	//
	Campos.Add(CFormField("Severity","Yes"));	//
	Campos.Add(CFormField("Tasks","1"));	//
	Campos.Add(CFormField("Date_ok","OK"));	//
	Campos.Add(CFormField("Failure_Class",""));	//
	Campos.Add(CFormField("Simptom",""));	//
	Campos.Add(CFormField("EndTime","Yes"));
	Campos.Add(CFormField("Requested","Consola"));
	Campos.Add(CFormField("Fim_1",""));
	Campos.Add(CFormField("Fim_2",""));
	Campos.Add(CFormField("ManageNow",""));
	Campos.Add(CFormField("Reminder","Reminder"));
	Campos.Add(CFormField("HistoryAuthor","Opipes"));
	Campos.Add(CFormField("Date_2",""));	//
	Campos.Add(CFormField("Date_2_2",""));
	Campos.Add(CFormField("Date_2_2_OK","OK"));
	Campos.Add(CFormField("Date_Closed_1",""));
	Campos.Add(CFormField("Date_Closed_2",""));
	//Campos.Add(CFormField("Solved_at",""));


	campo=new CFormField();
	campo->setTitle("Solved_at");
	campo->SetHHMM(6);//mais 6 minutos
	Campos.Add(*campo);

	campo=new CFormField();
	campo->setTitle("Solved_at_2");
	campo->SetHHMM(6);//mais 6 minutos
	Campos.Add(*campo);

	//Campos.Add(CFormField("Date_Inicial",timer.GetDataHoraAgora_dd_mm_aa_GMT_barras()));	//"08-11-2012 15:31:12 GMT"
	campo= new CFormField();
	campo->setTitle("Date_Inicial");
	campo->SetDDMMAAAAHHMMGMT();
	Campos.Add(*campo);

	//Campos.Add(CFormField("SortTime",timer.GetDataHoraAgora_dd_mm_aa_GMT_barras())); 		//idem
	campo= new CFormField();
	campo->setTitle("SortTime");
	campo->SetDDMMAAAAHHMMGMT();
	Campos.Add(*campo);


	//Campos.Add(CFormField("PostedOn",timer.GetDataHoraAgora_dd_mm_aa_GMT_barras()));
	campo= new CFormField();
	campo->setTitle("PostedOn");
	campo->SetDDMMAAAAHHMMGMT();
	Campos.Add(*campo);

	campo= new CFormField();
	campo->setTitle("HistDate");
	campo->SetDDMMAAAAHHMMGMT();
	Campos.Add(*campo);

	campo = new CFormField();
	campo->setTitle("Time");
	campo->SetHHMM();
	Campos.Add(*campo);

	Incidents.CriarTicket(Campos);

	return (0);
}

