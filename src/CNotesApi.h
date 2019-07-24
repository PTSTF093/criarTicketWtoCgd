/*
 * CNotesApi.h
 *
 *  Created on: Nov 7, 2012
 *      Author: ptsca012
 *
 *
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



#ifndef CNOTESAPI_H_
#define CNOTESAPI_H_

#include <lncppapi.h>
#include <iostream>
#include <string>

//#include <lndb.hpp>
//#include <lndoc.hpp>
//#include <lnform.hpp>
//#include <lntext.hpp>
//#include <lnformf.hpp>
//#include <lnformfa.hpp>
//#include <lnsessio.hpp>
#include "CFieldsQueue.h"
#include "CReloj.h"

#define ERR_BUF_SIZE 512

namespace std
{

class CNotesApi
{
	LNNotesSession Session;
	LNDatabase Db;
	LNString DbTitle;
	//char DatabasePath[]	=	"c_dir/cgdmultipurposedb.nsf";
	string DatabasePath;

	//char DatabasePath[]	=	"/home/ptsca012/lotus/notes/data/c_dir/cgdmultipurposedb.nsf";
	//char ServerPath[]	=	"D06DBL051/06/A/IBM";
	//char *ServerPath;	// = NULL; //para trabalhar na Local
	string ServerPath;

	LNDocument novoDocumento;
	LNFormFieldArray campos;
	LNForm form;

	LNText texto;
	LNDatetime datahora;

	//LotusScript
	LNAgent agente;
	LNLotusScript lscript;

	LNBOOL status;
public:

	CNotesApi(int argc, char *argv[]);
	virtual ~CNotesApi();
	void CriarTicket();
	void CriarTicket(CFieldsQueue);
	//se não foi possível inicializar a sessão (id em uso??)
	bool GetStatus(){return status;};
};

} /* namespace std */
#endif /* CNOTESAPI_H_ */
