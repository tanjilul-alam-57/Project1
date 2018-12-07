/*
 * CNavigationSystem.cpp
 *
 *  Created on: Nov 24, 2018
 *      Author: Tanjil
 */

#include "CNavigationSystem.h"
#include<iostream>
using namespace std;
#include "CPoiDatabase.h"
#include "CGPSSensor.h"
#include "CRoute.h"
#include "CWaypoint.h"


void CNavigationSystem::enterRoute() {
	CWaypoint Tokio("tokio",35.68,139.69);
	cout<<"test"<<endl;
	CWaypoint Amsterdam("amsterdam",52.36,4.90);
	CWaypoint Darmstadt("darmstadt",49.87,8.65);
	CWaypoint Berlin("berlin",52.5166,13.4);
	m_route.addWaypoint(Tokio);
	m_route.addWaypoint(Amsterdam);
	m_route.addWaypoint(Berlin);
	m_route.addWaypoint(Darmstadt);

	m_PoiDatabase.addPoi(Hotel, "mensa", "best mensa", 12,23.6);
	m_PoiDatabase.addPoi(Hotel,"purobi","cheap hotel",12,23);


	m_route.connectToPoiDatabase(&m_PoiDatabase);
	m_route.addPoi("mensa");
	m_route.addPoi("purobi");


}

void CNavigationSystem::printRoute() {
	m_route.print();
}

CNavigationSystem::CNavigationSystem(){
}

void CNavigationSystem::run() {
	enterRoute();
	printRoute();
	printDistanceCurPosNextPoi();
}

void CNavigationSystem::printDistanceCurPosNextPoi() {

	CWaypoint wp;
	wp=this->m_GPSSensor.getCurrentPosition();
	CPOI poi;//as we consider first poi as latitude=0,longitude=0
	double dist;
	m_route.connectToPoiDatabase(&m_PoiDatabase);//to get poi we need to connect to database
	dist=m_route.getDistanceNextPoi(wp,poi);
	cout<<"nearest poi is "<<poi.getName()<<"distance= "<<dist<<endl;


	//double m_route.getDistanceNextPoi()
}

CNavigationSystem::~CNavigationSystem() {
	cout<<"Navigation System";
}
