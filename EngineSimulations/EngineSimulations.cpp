// EngineSimulations.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Stand.h"
#include "Interaction.h"

int main()
{
	double ambientTemp = Interaction::ReadTemp();
	engine::IntComEngine engine;
	standArr::Stand<engine::IntComEngine> stand(engine, ambientTemp);
	Interaction::ConclusionTime(stand.LaunchEngine());


	return 0;
}


