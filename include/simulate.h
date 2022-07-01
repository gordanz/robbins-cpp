#pragma once
#include "Tree.h"
#include "Stopping_Rule.h"
#include <random>

std::random_device device;
std::mt19937 generator(device());
std::uniform_real_distribution<float> float_dis(0, 1);

float draw()
{
	static bool first_time = true;
	if (first_time)
	{
		generator.discard(700000);
		first_time = false;
	}
	return(float_dis(generator));
}

float simulate(int nsim, Stopping_Rule tau, bool expected_rank)
{
	cout << "Number of simulations: \t " << nsim << endl;
	cout << "Number of secretaries: \t " << tau.n << endl;
	cout << "Objective function: \t ";
	
	if (expected_rank) 
	{
		cout << "\"Expected rank (Robbins)\"" << endl;
	}
	else
	{
		cout << "\"Probability of rank=1\"" << endl;
	}
	cout << "Stopping rule: \t\t \"" << tau.name << "\"" << endl;

	Node *a = new Node[tau.n];
	Tree tree;
	usint r; float x; usint t;
	float value = 0.0;
	for (int sim = 0; sim < nsim; sim++)
	{
		for (t = 1; t <= tau.n; t++)
		{
			x = draw();
			a[t-1].initialize(x);
			r = tree.insert_node(&a[t-1]);
			if (tau.should_stop(x, r, t, &tau)) break;
		}
		if (expected_rank) { // objective = Robbins, expected rank
			if (t >= tau.n) 
			{
				value += r;
			}
			else
			{
				value += r + (tau.n - t)*x;
			};
		}
		else { // objective = probability of best
			if (r == 1)
			{
				if (t >= tau.n)
				{
					value += 1;
				}
				else
				{
					value += (float)t / tau.n;
				};
			}
		tree.empty();
	}
	delete[] a;
	return(value / nsim);
}