#pragma once
#include "Tree.h"
#include "Stopping_Rule.h"
#define E 2.71828182846

bool first_best(float x, usint r, usint t, Stopping_Rule *tau)
{
	static usint kick_in_time = (usint)((double)tau->n / E);
	return(r == 1 && t > kick_in_time);
}

bool treshold(usint r, usint t, Stopping_Rule *tau)
{
	static float c = 4.0;
	return(r <= (usint)c);
}

void trivial_init(Stopping_Rule *tau)
{
}

//void init(Stopping_Rule *tau)
//{
//	tau->data = new float[tau->n];
//	for (int i = 0; i < tau->n; i++)
//	{
//		tau->data[i] = (float)i;
//	}
//}
//
//
//void deinit(Stopping_Rule *tau)
//{
//	delete tau->data;
//}

void trivial_deinit(Stopping_Rule *tau)
{
}

