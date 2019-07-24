/*
 * CReloj.cpp
 *
 *  Created on: Nov 8, 2012
 *      Author: ptsca012
 */
#include "CReloj.h"

namespace std
{

CReloj::CReloj()
{
	rawtime=time(NULL);
	timeinfo = localtime ( &rawtime );
	mktime(timeinfo);
}

CReloj::~CReloj()
{
	// TODO Auto-generated destructor stub
}

string CReloj::GetHoraAgora(int maisMinutos)
{
	time ( &rawtime );
	char buf[80];
	timeinfo->tm_min+=maisMinutos;
	strftime(buf, 80, "%X", timeinfo);
	return buf;
}



string CReloj::GetDataAgora_dd_mm_aaaa()
{
	time ( &rawtime );
	char buf[80];
	strftime(buf, sizeof(buf), "%d-%m-%Y", timeinfo);
	return buf;
}

string CReloj::GetDataAgora_dd_mm_aaaa_pontos()
{
	time ( &rawtime );
	char buf[80];
	strftime(buf, sizeof(buf), "%d.%m.%Y", timeinfo);
	return buf;
}

string CReloj::GetDataHoraAgora_dd_mm_aa_GMT()
{
	string tmp;
	time ( &rawtime );
	char buf[80];
	strftime(buf, sizeof(buf), "%d-%m-%Y %X", timeinfo);
	tmp.assign(buf);
	tmp+=" GMT";
	return tmp;
}

string CReloj::GetDataAgora_dd_mm_aaaa_barras()
{
	string tmp;
	time ( &rawtime );
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y", timeinfo);
	tmp.assign(buf);
	//tmp+=" GMT";
	return tmp;
}

string CReloj::GetDataHoraAgora_dd_mm_aa_GMT_barras()
{
	string tmp;
	time ( &rawtime );
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", timeinfo);
	tmp.assign(buf);
	tmp+=" GMT";
	return tmp;
}

string CReloj::GetShifttype()
{
	string tmp="";
	if(timeinfo->tm_hour < 1 && timeinfo->tm_hour >= 0){
		//pertence ao turno da noite do dia anterior
		tmp="Turno 4 (Noite)";
	}
	else if(timeinfo->tm_hour >= 1 && timeinfo->tm_hour < 7){
		tmp="Turno 1 (Madrugada)";
	}
	else if(timeinfo->tm_hour >= 7 && timeinfo->tm_hour < 13){
		tmp="Turno 2 (Manhã)";
	}
	else if(timeinfo->tm_hour >= 13 && timeinfo->tm_hour < 19){
		tmp="Turno 3 (Tarde)";
	}
	else{
		tmp="Turno 4 (Noite)";
	}
	return tmp;
}
/*
 * apanhar a hora actual
 * mais os minutos passados como
 * parâmetro e retornar no
 * formato double
 */
double CReloj::GetHoraAgoraDouble(int m)
{
	double hora;
	time ( &rawtime );
	timeinfo->tm_min+=m;
	mktime(timeinfo);
	hora=timeinfo->tm_gmtoff;
	return hora;
}

string CReloj::GetDataHoraUniversal()
{
	string tmp;
	time ( &rawtime );
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", timeinfo);
	tmp.assign(buf);
	tmp+=" GMT";
	return tmp;
}

string CReloj::GetShiftStartDate()
{
	string tmp;
	time ( &rawtime );
	char buf[80];

	if(timeinfo->tm_hour>0 && timeinfo->tm_hour<1){
		timeinfo->tm_yday-=1;
	}
	strftime(buf, sizeof(buf), "%d/%m/%Y", timeinfo);
	tmp.assign(buf);
	//tmp+=" GMT";
	return tmp;
}
void CReloj::setAno(int ano)
{
	datetime.SetYear(ano);
}

void CReloj::setMes(int int1)
{
	datetime.SetMonth(int1);
}

LNDatetimes CReloj::getLNDatetimes()
{
	time ( &rawtime );
	datetime.SetYear(timeinfo->tm_year);
	datetime.SetMonth(timeinfo->tm_mon);
	datetime.SetDay(timeinfo->tm_mday);
	datetimes.Append(datetime);
	return datetimes;
}

void CReloj::setDia(int int1)
{
	datetime.SetDay(int1);
}
/*
 * devolver o dia em formato LNINT
 */
LNINT CReloj::GetLNDay()
{
	LNINT dia;
	time(&rawtime);
	dia=timeinfo->tm_mday;
	return dia;
}
/*
 * devolver o mes em formato LNINT
 */
LNINT CReloj::GetLNMonth()
{
	LNINT mon;
	time(&rawtime);
	mon=timeinfo->tm_mon;
	return ++mon;
}
/*
 * devolver o year em formato LNINT
 */
LNINT CReloj::GetLNYear()
{
	LNINT year;
	time(&rawtime);
	year=timeinfo->tm_year +1900;
	return year;
}

LNINT CReloj::GetLNHour()
{
	LNINT Hour;
	time(&rawtime);
	Hour=timeinfo->tm_hour;
	return Hour;
}

LNINT CReloj::GetLNMin()
{
	LNINT Min;
	time(&rawtime);
	Min=timeinfo->tm_min;
	return Min;
}














/* namespace std */

}








