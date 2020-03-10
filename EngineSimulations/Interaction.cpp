#include "pch.h"
#include "Interaction.h"
#include "Stand.h"
#include <iostream>



int Interaction::ReadTemp() {
	double ambientTemp;
	cout << "Please enter the ambient temperature ";
	cin >> ambientTemp;
	return ambientTemp;
}

void Interaction::ConclusionTime(const int time) {
	if (time == MAX_TIME)
		cout << endl << "At this ambient temperature, the engine should not overheat." << endl;
	else
		cout << endl << "Time of engine overheating: " << time << " sec" << endl;
}
