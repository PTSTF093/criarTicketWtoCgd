/*
 * CFieldsQueue.cpp
 *
 *  Created on: Nov 7, 2012
 *      Author: ptsca012
 */

#include "CFieldsQueue.h"
#include "CReloj.h"

namespace std
{

CFieldsQueue::CFieldsQueue()
{
	// TODO Auto-generated constructor stub

}

CFieldsQueue::~CFieldsQueue()
{
	// TODO Auto-generated destructor stub
}

void CFieldsQueue::Add(CFormField cFormField)
{
	pilha.push_back(cFormField);
}

} /* namespace std */
