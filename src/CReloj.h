/*
 * CReloj.h
 *
 *  Created on: Nov 8, 2012
 *      Author: ptsca012
 */

#ifndef CRELOJ_H_
#define CRELOJ_H_

#include <lncppapi.h>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <string>


namespace std
{

class CReloj
{
	time_t rawtime;
	struct tm * timeinfo;
	string shiftCGD;
	string shiftStartDate;
	LNDatetime datetime;
	LNDatetimes datetimes;

public:
	CReloj();
	virtual ~CReloj();
	string GetHoraAgora(int m=0);
	double GetHoraAgoraDouble(int m=0);
	string GetDataAgora_dd_mm_aaaa();
	string GetDataAgora_dd_mm_aaaa_barras();
	string GetDataAgora_dd_mm_aaaa_pontos();
	string GetDataHoraAgora_dd_mm_aa_GMT();
	string GetDataHoraAgora_dd_mm_aa_GMT_barras();
	string GetDataHoraUniversal();
	string GetShifttype();
	string GetShiftStartDate();

	LNDatetimes getLNDatetimes();

	LNINT GetLNDay();
	LNINT GetLNMonth();
	LNINT GetLNYear();
	LNINT GetLNHour();
	LNINT GetLNMin();

	//setters
	void setAno(int ano=0);
	void setMes(int);
	void setDia(int);
};

} /* namespace std */
#endif /* CRELOJ_H_ */
