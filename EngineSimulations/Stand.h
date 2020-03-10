#pragma once
#include "Engine.h"

#define ABSOLUTE_ERROR 10e-2
#define MAX_TIME 1600

namespace standArr {
	template<typename T>
	class Stand {
		int numberV;
		double engineTemp;
		double ambientTemp;
		T* engine;
	public:
		int LaunchEngine();
		Stand(T& engine, const double ambientTemp);
	};

	template<typename T>
	Stand<T>::Stand(T& engine, const double ambientTemp) {
		numberV = 0;
		this->engine = &engine;
		engineTemp = ambientTemp;
		this->ambientTemp = ambientTemp;
		this->engine->M = engine.depenM[numberV];
		this->engine->V = engine.speedRotationV[numberV];
	}

	template <typename T>
	int Stand<T>::LaunchEngine() {
		double a = engine->M * engine->I;
		double tmp = engine->overheatTemp - engine->engineTemp;
		int timeEngine = 0;
		while (tmp > ABSOLUTE_ERROR && timeEngine < MAX_TIME) {
			timeEngine++;
			engine->V += a;
			if (numberV < engine->depenM.size() - 2)
				numberV += engine->V < engine->depenM[numberV + 1] ? 0 : 1;
			double up = (engine->V - engine->speedRotationV[numberV]);
			double down = (engine->speedRotationV[numberV + 1] - engine->speedRotationV[numberV]);
			double factor = (engine->depenM[numberV + 1] - engine->depenM[numberV]);
			engine->M = up / down * factor + engine->depenM[numberV];

			engineTemp += engine->Vc(ambientTemp, engineTemp) + engine->Vh();

			a = engine->M * engine->I;

			tmp = engine->overheatTemp - engineTemp;
		}

		return timeEngine;
	}
}