#include "pch.h"
#include "Engine.h"


namespace engine
{
	double IntComEngine::Vh() {
		return M * Hm + V * V * Hv;
	}

	double IntComEngine::Vc(double engineTemp, double ambientTemp) {
		return C * (ambientTemp - engineTemp);
	}
}
