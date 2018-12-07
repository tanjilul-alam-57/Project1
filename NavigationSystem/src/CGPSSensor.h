/*
 * CGPSSensor.h
 *
 *  Created on: Nov 27, 2018
 *      Author: Tanjil
 */

#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_

#include "CWaypoint.h"


using namespace std;

class CGPSSensor
{
	private:
	//declaring constructor and public methods
	public:
	CGPSSensor();
	CWaypoint getCurrentPosition();


	//virtual ~CGPSSensor();
};

#endif /* CGPSSENSOR_H_ */
