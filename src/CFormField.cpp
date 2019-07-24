/*
 * CFormField.cpp
 *
 *  Created on: Nov 7, 2012
 *      Author: ptsca012
 */

#include "CFormField.h"

namespace std
{

CFormField::CFormField(string t,string c)
{
	fieldTitle=t;
	fieldContent=c;
	IsDate=false;

}

CFormField::CFormField(string t,double c)
{
	fieldTitle=t;
	IsDate=true;
}

CFormField::~CFormField()
{
}

void CFormField::setTitle(string allocator)
{
	fieldTitle=allocator;
}

void CFormField::setContent(string allocator)
{
	fieldContent=allocator;
}

CFormField::CFormField()
{

	IsDate=false;

}

/*
 * devolver no formato LNDatetimes
 * a hora conforme o
 * conteudo do campo.
 *
 */




std::CFormField::CFormField(LNDatetimes lNDatetimes)
{
	todayDatetimes=lNDatetimes;

}

void std::CFormField::SetDDMMAAAA()
{
	//LNDatetime today(Session.GetCurrentDatetime());
	CReloj datahora;
	//LNString sdatahora=datahora.GetDataAgora_dd_mm_aaaa_barras().c_str();

	IsDate=true;
	today.SetDate(datahora.GetLNMonth(),datahora.GetLNDay(),datahora.GetLNYear());

	todayDatetimes.Insert(0, today);
}
void std::CFormField::SetDDMMAAAAHHMMGMT(int m)
{
	//LNDatetime today(Session.GetCurrentDatetime());
	CReloj datahora;

	IsDate=true;
	//LNNotesSession Session;
	//LNDatetime stoday(Session.GetCurrentDatetime());
	today.SetDate(datahora.GetLNMonth(),datahora.GetLNDay(),datahora.GetLNYear());
	today.SetTime(datahora.GetLNHour(),datahora.GetLNMin()+m);

	todayDatetimes.Insert(0, today);
}
void std::CFormField::SetHHMM(int m)
{
	//LNDatetime today(Session.GetCurrentDatetime());
	CReloj datahora;

	IsDate=true;
	//LNNotesSession Session;
	//LNDatetime stoday(Session.GetCurrentDatetime());
	//today.SetDate(datahora.GetLNMonth(),datahora.GetLNDay(),datahora.GetLNYear());
	today.SetTime(datahora.GetLNHour(),datahora.GetLNMin()+m);

	todayDatetimes.Insert(0, today);
}


}



