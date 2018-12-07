/*
 * CGPSSensor.cpp
 *
 *  Created on: Nov 27, 2018
 *      Author: Tanjil
 */

#include "CGPSSensor.h"
#include"CWaypoint.h"
#include<iostream>
using namespace std;

CGPSSensor::CGPSSensor() {
}

CWaypoint CGPSSensor::getCurrentPosition() {
	string name="current postion";
	double latitude, longitude;
	cin>>latitude;
	cin>>longitude;
	CWaypoint temp(name,latitude,longitude);
	return temp;

}
