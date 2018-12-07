/*
 * CWaypoint.cpp
 *
 *  Created on: Nov 19, 2018
 *      Author: Tanjil
 */

#include "CWaypoint.h"
#include<iostream>
using namespace std;
#include<math.h>
#define R 6378

//#define SHOWADRESS

CWaypoint::CWaypoint(string name, double latitude, double longitude) {

	set(name,latitude,longitude);

#ifdef SHOWADRESS

	cout<<"address of this object is"<<this<<endl;
#endif
}

void CWaypoint::transforLongitude2degmmss(int& deg, int& mm, double& ss) {

	deg=int(m_longitude);
	mm=int((m_longitude-deg)*60);
	ss=((((m_longitude-deg)*60)-mm)*60);

	cout<<" Longitude="<<deg<<" degree"<<mm<<" minute"<<ss<<" second"<<endl;

}

void CWaypoint::transforLatitude2degmmss(int &deg, int &mm, double &ss) {
	deg=int(m_latitude);
	mm=int((m_latitude-deg)*60);
	ss=((((m_latitude-deg)*60)-mm)*60);
	cout<<" latitude="<<deg<<" degree"<<mm<<" minute"<<ss<<" second"<<endl;
}

void CWaypoint::set(string name, double latitude, double longitude) {
	m_name=name;

	if(-90.0<=m_latitude && m_latitude <=90.0 && -180.0<=m_longitude && m_longitude<=180.0)
	{
	m_latitude=latitude;
	m_longitude=longitude;}
	else{
		m_latitude=0;
		m_longitude=0;

		cout<<"please provide the correct value of latitude and longitude"<<endl;
	}

}

string CWaypoint::getName() {

	return m_name;
}

double CWaypoint::getLatitude() {
	return m_latitude;
}

double CWaypoint::getLongitude() {

	return m_longitude;
}

void CWaypoint::getAllDataByReference(string& name, double& latitude,
		double& longitude) {

	name=m_name; //always assignment operator used in opposite direction
	latitude=m_latitude;
	longitude=m_longitude;

	cout<<"call by reference "<<name<<" , "<<latitude<<" , "<<longitude<<endl;
}

double CWaypoint::calculateDistance(const CWaypoint& wp) {

	double latitude_1,latitude_2,longitude_1,longitude_2,dist;
	latitude_1=m_latitude;
	latitude_2=wp.m_latitude;
	longitude_1=m_longitude;
	longitude_2=wp.m_longitude;
	dist=abs(R*acos(sin(latitude_1)*sin(latitude_2)+cos(latitude_1)*cos(latitude_2)*cos(longitude_2-longitude_1)));
	cout<<"distance between "<<m_name<<" and "<<wp.m_name<<" is "<<dist<<" kilometer "<<endl;
	return dist;



}

void CWaypoint::print(int format) {

	switch (format)
	{case 1:
	{cout<<"latitude = "<<m_latitude<<endl;
	cout<<"longitude = "<<m_longitude<<endl;
	break;}

	case 2:
	{
		int deg,mm;
		double ss;
		transforLatitude2degmmss(deg,mm,ss);
		transforLongitude2degmmss(deg,mm,ss);
		break;


	}
	}
}
