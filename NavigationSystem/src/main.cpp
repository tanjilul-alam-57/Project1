//============================================================================
// Name        : NavigationSystem.cpp
// Author      : Md Tanjilul Alam
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CWaypoint.h"
#include "CPOI.h"
#include"CNavigationSystem.h"
#include<string>
#include<math.h>
#define DEGREE 1
#define MMSS 2
using namespace std;



int main() {
/*cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	CWaypoint Tokio("tokio",35.68,139.69);
	CWaypoint Amsterdam("amsterdam",52.36,4.90);
	CWaypoint Darmstadt("darmstadt",49.87,8.65);
	CWaypoint Berlin("berlin",52.5166,13.4);
	Berlin.print(MMSS);
	Amsterdam.calculateDistance(Berlin);

	string name, description;
	t_poi type;
	double latitude, longitude;
	Tokio.getAllDataByReference(name,latitude,longitude);
	CPOI Mensa(Hotel, "Best Mensa", "mensa", 12,23.6);
	Mensa.print();
	Mensa.getAllDataByReference(name,latitude,longitude,type,description);*/
CNavigationSystem n;
n.run();

	return 0;
}
