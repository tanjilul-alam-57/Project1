/*
 * CRoute.cpp
 *
 *  Created on: Nov 21, 2018
 *      Author: Tanjil
 */

#include <string.h>
#include <iostream>
#include "CPOI.h"
#include "CWaypoint.h"
#include "CPoiDatabase.h"
#include"CRoute.h"
#include"CNavigationSystem.h"
using namespace std;

CRoute::CRoute(unsigned int maxWp, unsigned int maxPoi) {
	this->m_nextPoi=0;
	this->m_nextWp=0;
	this->m_pWaypoint=new CWaypoint[maxWp];//no need to use for loop
	this->m_pPoi=new CPOI*[maxPoi];
	this->m_maxPoi=maxPoi;
	this->m_maxWp=maxWp;
	this->m_pPoiDatabase=NULL;// as we already has databasee of poi so make it zero

}

CRoute::CRoute(const CRoute& origin) {

	//we have to define everything again calling by origin
	this->m_pWaypoint=new CWaypoint[origin.m_maxWp];//no need to use for loop
	this->m_pPoi=new CPOI*[origin.m_maxPoi];
	this->m_maxPoi=origin.m_maxPoi;
	this->m_maxWp=origin.m_maxWp;
	this->m_nextPoi=origin.m_nextPoi;
	this->m_nextWp=origin.m_nextWp;
	this->m_pPoiDatabase=origin.m_pPoiDatabase;

	for(unsigned int i=0;i<m_maxWp;i++)
	{m_pWaypoint[i]=origin.m_pWaypoint[i];}

	for(unsigned int i=0;i<this->m_maxPoi;i++)
	{this->m_pPoi[i]=origin.m_pPoi[i];}
}

void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB) {
	this->m_pPoiDatabase=pPoiDB;
}

void CRoute::addWaypoint(const CWaypoint& wp) {


	if(m_nextWp < m_maxWp)
		{
			this->m_pWaypoint[this->m_nextWp] = wp;//do not make with i

			this->m_nextWp++;

		}
		else
		{
			cout<<"Maximum limit of number of waypoint exceeded !!"<< endl;
		}}

void CRoute::addPoi(string namePoi) {

	//checking if the pointer is pointing to database and also if the number of POI stored is less then maximum.
	if( (m_nextPoi < m_maxPoi) && (m_pPoiDatabase != NULL))
	{
		//checking if the name exists in the database.
		if ((m_pPoiDatabase)->getPointerToPoi(namePoi)!= NULL)
		{
			//if exists then assigning the value of the static array of POI database to dynamic array
			m_pPoi [m_nextPoi]= m_pPoiDatabase->getPointerToPoi(namePoi);
			m_nextPoi++;

		}

		else
		{
			cout<<"Error: no pointer with this name in Database"<<endl;
		}

	}

	else
		{
		cout<<"Error: The Point of interest can not be added because either it exceeds the maximum number of POI or you are not connected to the database"<< endl;
		}
}


double CRoute::getDistanceNextPoi(const CWaypoint& wp, CPOI& poi) {
	double dist=0.0;
	if(this->m_nextPoi!=0)
	{dist=(**m_pPoi).calculateDistance(wp);
	poi=(**m_pPoi);}
	for(unsigned int i=0;i<this->m_maxPoi;i++)
	{
	if(dist>(**(m_pPoi+i)).calculateDistance(wp))
	{dist=(**(m_pPoi+i)).calculateDistance(wp);
	poi=(**(m_pPoi+i));}
	else{
		dist=0;
		poi.set("No poi",0.0,0.0);
	}}
	return dist;
}

void CRoute::print() {

	for(unsigned int i=0;i<this->m_maxWp;i++)
	{
		this->m_pWaypoint[i].print(2);

	}
	for(unsigned int p=0;p<this->m_maxPoi;p++)
	{this->m_pPoi[p]->print();}
}

CRoute::~CRoute() {
	delete []m_pPoi;
	delete []m_pWaypoint;
}
