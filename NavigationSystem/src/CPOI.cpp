/*
 * CPOI.cpp
 *
 *  Created on: Nov 19, 2018
 *      Author: Tanjil
 */

#include "CPOI.h"
#include <string.h>
#include <iostream>
#include "CWaypoint.h"

CPOI::CPOI(t_poi type, string description, string name, double latitude,
		double longitude)
{
	m_name=name;
	m_latitude=latitude;
	m_longitude=longitude;
	m_type = type;
	m_description = description;
	set(name, latitude, longitude);
}

void CPOI::print() {

	switch (m_type) {
	case Resturant:

		cout << "Restaurant :" << " best food" << endl;
		cout << getName() << ", " << getLatitude() << "," << getLongitude()
				<< endl;
		break;

	case Hotel:

		cout << "Hotel :" << " best environment" << endl;
		cout << getName() << ", " << getLatitude() << "," << getLongitude()
				<< endl;
		break;

	case Pub:

		cout << "Pub :" << " best beer" << endl;
		cout << getName() << ", " << getLatitude() << "," << getLongitude()
				<< endl;
		break;

	case NONE:

		cout << "None :" << " blank" << endl;
		cout << getName() << ", " << getLatitude() << "," << getLongitude()
				<< endl;
		break;

	case Park:

		cout << "Park :" << " best space" << endl;
		cout << getName() << ", " << getLatitude() << "," << getLongitude()
				<< endl;
		break;
	case Market:

		cout << "Market :" << " best mall" << endl;
		cout << getName() << ", " << getLatitude() << "," << getLongitude()
				<< endl;
		break;
	}
}

void CPOI::getAllDataByReference(string& name, double& latitude,
		double& longitude, t_poi& type, string& description) {
	name=getName();
	latitude=getLatitude();
	longitude=getLongitude();
	type=m_type;
	description=m_description;
	cout<<"print by reference:";
	this->print();
}
