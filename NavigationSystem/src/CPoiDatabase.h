/*
 * CPoiDatabase.h
 *
 *  Created on: Nov 20, 2018
 *      Author: Tanjil
 */

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_

#include <string.h>
#include <iostream>
#include "CPOI.h"
#include "CWaypoint.h"


using namespace std;


class CPoiDatabase
{
	//declaring private attributes
private:
    /**
     * @clientCardinality 1
     * @link aggregationByValue
     * @supplierCardinality 1..*
     */
	CPOI m_POI[10];
	int m_noPoi;

	//declaring constructor & public methods
public:
	CPoiDatabase();
	void addPoi(t_poi type=Resturant, string name="no name", string description="no description", double latitude=0, double longitude=0);
	CPOI* getPointerToPoi(string name);

	//virtual ~CPoiDatabase();
};
#endif /* CPOIDATABASE_H_ */
