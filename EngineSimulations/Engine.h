#pragma once
#include <vector>

using namespace std;

namespace engine
{
	struct IntComEngine {
		double I = 0.1;
		double overheatTemp = 110;
		int numberV;
		double engineTemp;
		vector <int> depenM = { 20, 75, 100, 105, 75, 0 };
		vector <int> speedRotationV = { 0, 75, 150, 200, 250, 300 };
		double Hm = 0.01;
		double Hv = 0.0001;
		double C = 0.1;
		double M;
		double V;

		double Vc(double engineTemp, double ambientTemp);
		double Vh();

	};
}

