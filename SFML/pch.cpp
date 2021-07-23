#include "pch.h"

float random(float from, float to)
{ 
	static random_device rd;
	static mt19937 gen(rd());
	static uniform_real_distribution<float> d(from, to);
	return d(gen);
}
