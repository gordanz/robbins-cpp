#pragma once

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Stopping_Rule
{
public:
	Stopping_Rule(string name_in, usint n_in,
		bool(*should_stop_in)(float x, usint r, usint t, Stopping_Rule *tau),
		void(*initializer)(Stopping_Rule* tau),
		void(*deinitializer_in)(Stopping_Rule* tau));
	~Stopping_Rule();
	bool(*should_stop)(float x, usint r, usint t, Stopping_Rule *tau);
	void(*deinitializer)(Stopping_Rule* tau);

	//float *data;
	usint n;
	string name;
	string str(void);
};

Stopping_Rule::Stopping_Rule(string name_in, usint n_in,
	bool(*should_stop_in)(float x, usint r, usint t, Stopping_Rule *tau),
	void(*initializer)(Stopping_Rule* tau),
	void(*deinitializer_in)(Stopping_Rule* tau))
{
	name = name_in;
	n = n_in;
	should_stop = should_stop_in;
	deinitializer = deinitializer_in;
	initializer(this);
}

Stopping_Rule::~Stopping_Rule()
{
	deinitializer(this);
}

string Stopping_Rule::str()
{
	stringstream out;
	out << "Name: \"" << name << "\", n = " << n;
	/*out << ", data : [";
	for (int i = 0; i < n; i++)
	{
		out << data[i];
		if (i < n - 1) out << ", ";
	}
	out << "]";*/
	return(out.str());
}



