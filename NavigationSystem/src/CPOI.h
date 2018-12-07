/*
 * CPOI.h
 *
 *  Created on: Nov 19, 2018
 *      Author: Tanjil
 */

#ifndef CPOI_H_
#define CPOI_H_

#include <string.h>
#include <iostream>
#include "CWaypoint.h"

enum t_poi{Resturant,Hotel, Pub, Market, NONE, Park};

using namespace std;

//declaring inheritance and making CWaypoints attributes public in this class
class CPOI : public CWaypoint
{
private:
	//declaring private attributes
	string m_description;
	t_poi m_type;
public:
	//declaring constructor & public functions.
	CPOI(t_poi type=NONE, string description="", string name="", double latitude=0, double longitude=0);
	void print();
	void getAllDataByReference(string &name, double &latitude, double &longitude, t_poi &type, string &description);
	//Declared destructor.
	//virtual ~CPOI();
};


#endif /* CPOI_H_ */
