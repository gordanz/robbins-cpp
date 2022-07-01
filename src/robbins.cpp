// Robbins_Simulation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//  

// standard headers
#include <iostream>

// my headers
#include "Tree.h"
#include "Stopping_Rule.h"
#include "my_rules.h"
#include "simulate.h"

// debug/profile headers
#include "helpers.h"

using namespace std;

int main()
{
	usint number_of_secretaries = 1024;
	int number_of_simulations = 20480;

	timer();
	hline();

	Stopping_Rule tau("First record after n/e", number_of_secretaries, first_best, trivial_init, trivial_deinit);

	float val = 0;
	val = simulate(number_of_simulations, tau, false); // last argument if expected rank
	hline();

	double true_value = 0.3678794411; // robbinsIII? = 3.8695);
	double rel_error = 100.0*(val - true_value) / true_value;
	printf("Value: \t\t\t %f\nTrue value: \t\t %.4f\nRelative error: \t %.2f %%\n", val, true_value, rel_error);

	hline();
	timer();
	getchar();

}

