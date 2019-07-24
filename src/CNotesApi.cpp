/*
 * CNotesApi.cpp
 *
 *  Created on: Nov 7, 2012
 *      Author: ptsca012
 */

#include "CNotesApi.h"

namespace std
{

CNotesApi::CNotesApi(int argc, char *argv[])
{
	// Make the error handler throw all errors encountered during execution.
	LNSetThrowAllErrors(TRUE);

	/*
	 * TODO
	 * path a alterar no futuro para reflectir
	 * a database definitiva
	 */
	DatabasePath.assign("c_dir/cgdmultipurposedb.nsf");
	//		"LIXO.nsf");
	// D06DBL051/06/A/IBM
	//ServerPath = NULL; //para trabalhar na Local
	ServerPath.assign("D06DBL051/06/A/IBM");
	try
	{
		// Initialize the C++ API
		Session.Init(argc, argv);
		status=Session.IsInitialized();
		if(!status)
		{
			return;
		}

		// Get the specified database.
		//com servidor:
		//TIMEDATE id;
		Session.GetDatabase(DatabasePath.c_str(), &Db, ServerPath.c_str());
		//sem servidor:
		//Session.GetDatabase(DatabasePath.c_str(), &Db);
		//Session.GetDatabase(id, &Db, ServerPath.c_str());

		// Open sesame.
		Db.Open();
		// Get the database's title.
		DbTitle = Db.GetTitle();
		// Display it.
		cout << "DB:(" << DbTitle << ")" << endl;

		//criar novo documento conforme o form
		//Db.CreateForm("ShiftbookForm",&form);
		//cout<<"form="<<form.GetName()<<endl;
		//form.SetRefreshFieldsAutomatically(true);

	} catch (LNSTATUS Lnerror)
	{
		// Error handler.  If an error occurred, get the text of
		// the error message and display it.
		char ErrorBuf[ERR_BUF_SIZE];
		LNGetErrorMessage(Lnerror, ErrorBuf, ERR_BUF_SIZE);
		cout << "Error:  " << ErrorBuf << endl;
	}
}

CNotesApi::~CNotesApi()
{

	// Close sesame.
	Db.Close();

	// Terminate the API.
	Session.Term();
}

/*
 * Somente para teste, criação
 * de ticket instream
 */
void CNotesApi::CriarTicket()
{
	try
	{
		Db.CreateDocument(&novoDocumento, "ShiftbookForm");
		//DATE/TIME
		/*
		 * formato: dd-mm-aaaa hh:mm:ss
		 */
		string data = "07-11-2012";
		string hora = "14:00:00";
		novoDocumento.CreateItem("Date", &texto);
		texto.Append(data.c_str()); //CGD ou CEMG
		novoDocumento.CreateItem("Time", &texto);
		texto.Append(hora.c_str()); //CGD ou CEMG
		novoDocumento.CreateItem("Date_inicial", &texto);
		string dataInicial = data + " " + hora + " GMT";
		texto.Append(dataInicial.c_str()); //CGD ou CEMG
		novoDocumento.CreateItem("Date_ok", &texto);
		texto.Append("ok"); //CGD ou CEMG

		/*
		 * Turno:
		 * campo=Shifttype
		 */
		novoDocumento.CreateItem("Shifttype", &texto);
		texto.Append(""); //CGD ou CEMG

		//trabalhar
		novoDocumento.CreateItem("Customer", &texto);
		texto.Append("CGD"); //CGD ou CEMG

		novoDocumento.CreateItem("System", &texto);
		texto.Append("SYB1"); //Lpars

		novoDocumento.CreateItem("Subject", &texto);
		texto.Append("INCIDENT"); //INCIDENT ou REQUEST->wto, sessão lançamentos

		/*
		 * JOB IN ERROR PRD
		 * JOB IN ERROR QLD
		 * vai depender da lpar
		 *
		 * se for WTO:
		 * CLOSE CICS/OPEN CICS
		 * START TASK/STOP TASK
		 * URGENT MESSAGES FROM CONSOLE (REQ)
		 */
		novoDocumento.CreateItem("Category", &texto);
		texto.Append("JOB IN ERROR QLD"); //

		/*
		 * conforme a lpar/SYSTEM
		 * definir o tipo de entrada no formato
		 * se for JOB IN ERROR...
		 * Resolver cancelamento do(s) seguinte(s) job(s) <vari do pipes com job>
		 * se for Sessão de lançamentos: Efectuar sessão de lançamentos nº xx
		 *
		 */
		novoDocumento.CreateItem("Details", &texto);
		texto.Append("Resolver cancelamento do(s) seguinte(s) job(s) teste"); //resolver job, etc...

		/*
		 * campo Element
		 * contem o nome do operador
		 */
		novoDocumento.CreateItem("Element", &texto);
		texto.Append("Hacker");

		/*
		 * campo Team
		 * deverá conter JAZZ, BLUES, etc..
		 */
		novoDocumento.CreateItem("Team", &texto);
		texto.Append("Team");

		/*
		 * campo Severity
		 * deverá conter "Yes"
		 */
		novoDocumento.CreateItem("Severity", &texto);
		texto.Append("Yes");

		/*
		 * campo Priority_1
		 * deverá conter SEVERITY 1,2,...
		 * campo protected
		 */
		novoDocumento.CreateItem("Priority_1", &texto);
		texto.Append("SEVERITY 3");

		/*
		 * campo Status
		 * deverá conter Open
		 */
		novoDocumento.CreateItem("Status", &texto);
		texto.Append("Open");

		/*
		 * campo Tasks
		 *
		 */
		novoDocumento.CreateItem("Tasks", &texto);
		texto.Append("1");

		//finalizar
//		novoDocumento.RefreshNoteHandleFromObject();
//		novoDocumento.RefreshObjectFromNoteHandle();

		novoDocumento.Save();
		novoDocumento.Close();
	} catch (LNSTATUS Lnerror)
	{
		// Error handler.  If an error occurred, get the text of
		// the error message and display it.
		char ErrorBuf[ERR_BUF_SIZE];
		LNGetErrorMessage(Lnerror, ErrorBuf, ERR_BUF_SIZE);
		cout << "Error:  " << ErrorBuf << endl;
	}
}

/*
 * Criar o ticket
 * atraves de uma pilha do tipo CFormField
 * previamente preenchida
 */
void CNotesApi::CriarTicket(CFieldsQueue cFieldsQueue)
{
	if (cFieldsQueue.Empty())
		return;

	vector<CFormField>::iterator it;
	try
	{
		Db.CreateDocument(&novoDocumento, "ShiftbookForm");
		//iterar pela pilha
		for (it = cFieldsQueue.begin(); it < cFieldsQueue.end(); ++it)
		{
			CFormField campo = *it;

			if (campo.IsDate)
			{
				//LNDatetime today(Session.GetCurrentDatetime());
//				CReloj datahora;
//				LNString sdatahora=datahora.GetDataAgora_dd_mm_aaaa_barras().c_str();
//
//				LNDatetime today;
//				today.SetDate(datahora.GetLNMonth(),datahora.GetLNDay(),datahora.GetLNYear());
				LNItem datetimeItem;
//				LNDatetimes todayDatetimes;
//				todayDatetimes.Insert(0, today);
				//todayDatetimes.Insert(1, today);
//				novoDocumento.CreateItem(campo.getTitle(), campo.GetTodayDatetimes(), 0,
//						LNITEMOPTION_DELETE_APPEND, &datetimeItem);
				novoDocumento.CreateItem(campo.getTitle(),
						campo.GetTodayDatetimes(), LNITEMFLAGS_AUTO_SUMMARY,
						LNITEMOPTION_DELETE_APPEND, &datetimeItem);

			}
			else //é texto
			{
				novoDocumento.CreateItem(campo.getTitle(), &texto);
				texto.Append(campo.getContent());
			}
		}
		novoDocumento.Save();
		novoDocumento.Close();
	} catch (LNSTATUS Lnerror)
	{
		// Error handler.  If an error occurred, get the text of
		// the error message and display it.
		char ErrorBuf[ERR_BUF_SIZE];
		LNGetErrorMessage(Lnerror, ErrorBuf, ERR_BUF_SIZE);
		cout << "Error:  " << ErrorBuf << endl;
	}
}

} /* namespace std */
