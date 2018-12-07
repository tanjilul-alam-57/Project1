/*
 * CWaypoint.h
 *
 *  Created on: Nov 19, 2018
 *      Author: Tanjil
 */

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_

#include <string.h>
#include <iostream>


using namespace std;

class CWaypoint
{
protected:

	//declaring attributes
	string m_name;
	double m_latitude;
	double m_longitude;

private:
	//declaring "transform longitude to deg mm ss" function
	void transforLongitude2degmmss (int &deg, int &mm, double &ss);

	//declaring "transform latitude to deg mm ss" function
	void transforLatitude2degmmss (int &deg, int &mm, double &ss);

public:
	//declaring constructor
	CWaypoint(string name="no name",double latitude=0,double longitude=0);

	//declaring set function that set the values of attributes string-name, double-latitude, double-longitude
	void set(string name, double latitude, double longitude);

	/*declaring get function that get the values of function string-getName, double-getLatitude,
	double-getLongitude */
	string getName ();
	double getLatitude ();
	double getLongitude ();

	//declaring "get all data by reference" function
	void getAllDataByReference(string&name, double&latitude, double&longitude);


	//declaring "distance calculation function" working as copy constructor
	double calculateDistance (const CWaypoint &wp);

	//declaring print function
	void print(int format);


	//virtual ~CWaypoint();
};

#endif /* CWAYPOINT_H_ */
