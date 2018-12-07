/*
 * CNavigationSystem.h
 *
 *  Created on: Nov 24, 2018
 *      Author: Tanjil
 */

#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_

#include "CPoiDatabase.h"
#include "CGPSSensor.h"
#include "CRoute.h"
#include "CWaypoint.h"

#define DEGREE 1
#define MMSS 2

using namespace std;

class CNavigationSystem
{
	//declaring private attributes
private:
	CGPSSensor m_GPSSensor;
	CRoute m_route;
	CPoiDatabase m_PoiDatabase;
	void enterRoute();
	void printRoute();
	void printDistanceCurPosNextPoi();

	//declaring constructor & public functions
public:

	CNavigationSystem();
	void run();


	virtual ~CNavigationSystem();
};

#endif /* CNAVIGATIONSYSTEM_H_ */
