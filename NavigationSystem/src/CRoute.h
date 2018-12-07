/*
 * CRoute.h
 *
 *  Created on: Nov 21, 2018
 *      Author: Tanjil
 */

#ifndef CROUTE_H_
#define CROUTE_H_

#include <string.h>
#include <iostream>
#include "CPOI.h"
#include "CWaypoint.h"
#include "CPoiDatabase.h"

using namespace std;


class CRoute
{
	//declaring private attributes
private:
    /**
     * @link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 1..*
     */
	CWaypoint* m_pWaypoint;
	unsigned int m_maxWp;
	unsigned int m_nextWp;
	CPOI **m_pPoi;
	unsigned int m_maxPoi;
	unsigned int m_nextPoi;
	CPoiDatabase* m_pPoiDatabase;
    /**@link dependency*/
    /*# CPOI lnkCPOI; */
    /**@link aggregation
     * @supplierCardinality 1..**/
    CPOI lnkCPOI1;
	//declaring constructor, destuctor and public functions
public:

	CRoute(unsigned int maxWp=4 , unsigned int maxPoi=2);//do not declare more
	CRoute(CRoute const &origin);
	void connectToPoiDatabase(CPoiDatabase *pPoiDB);
	void addWaypoint(CWaypoint const &wp);
	void addPoi(string namePoi);
	double getDistanceNextPoi(CWaypoint const &wp, CPOI &poi);
	void print();


	virtual ~CRoute();
};

#endif /* CROUTE_H_ */
