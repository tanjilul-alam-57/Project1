/*
 * CPoiDatabase.cpp
 *
 *  Created on: Nov 20, 2018
 *      Author: Tanjil
 */

#include "CPoiDatabase.h"
#include <string.h>
#include <iostream>
#include "CPOI.h"
#include "CWaypoint.h"

CPoiDatabase::CPoiDatabase() {
	m_noPoi=0;
}

void CPoiDatabase::addPoi(t_poi type, string name, string description,
		double latitude, double longitude) {


	for(int i=0;i<10;i++)
	{m_POI[i]=CPOI(type,description,name,latitude,longitude);//we can write object type array is equal to constructor
	m_noPoi++;
	break;}
}

CPOI* CPoiDatabase::getPointerToPoi(string name) {

	for(int i=0;i<20;i++)
	{
		m_POI[i].getName()=name; //as we have already an object so no need to create new object

	return &m_POI[i];}//return type pointer so return address
}
