/*
 * CFieldsQueue.h
 *
 *  Created on: Nov 7, 2012
 *      Author: ptsca012
 */

#ifndef CFIELDSQUEUE_H_
#define CFIELDSQUEUE_H_

#include <vector>
#include "CFormField.h"

namespace std
{

class CFieldsQueue: public std::CFormField
{
	vector<CFormField> pilha;
	vector<CFormField>::iterator it;
public:
	CFieldsQueue();
	virtual ~CFieldsQueue();
	void Add(CFormField);
	void Clear(){pilha.clear();};
	vector<CFormField>::iterator begin(){return pilha.begin();};
	vector<CFormField>::iterator end(){return pilha.end();};
	bool Empty(){return pilha.empty();};
};

} /* namespace std */
#endif /* CFIELDSQUEUE_H_ */
