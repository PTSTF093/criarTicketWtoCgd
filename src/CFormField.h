/*
 * CFormField.h
 *
 *  Created on: Nov 7, 2012
 *      Author: ptsca012
 */

#ifndef CFORMFIELD_H_
#define CFORMFIELD_H_

#include <lncppapi.h>
#include <iostream>
#include <string>
#include "CReloj.h"


namespace std
{

class CFormField
{
	string fieldTitle;
	string fieldContent;

	LNDatetime today;
	LNItem datetimeItem;
	LNDatetimes todayDatetimes;


public:
	CFormField();
	CFormField(LNDatetimes);
	CFormField(string,string);
	CFormField(string,double);
	virtual ~CFormField();
	bool IsDate;


	LNDatetimes getLndatetimes() const
	{
		return todayDatetimes;
	}
	const char * getTitle(){return fieldTitle.c_str();};
	const char * getContent(){return fieldContent.c_str();};
	LNDatetimes GetTodayDatetimes(){return todayDatetimes;};

	void setTitle(string);
	void setContent(string);

	void SetDDMMAAAA();
	void SetDDMMAAAAHHMMGMT(int m=0);
	void SetHHMM(int m=0);

};

} /* namespace std */
#endif /* CFORMFIELD_H_ */
