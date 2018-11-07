#pragma once
#include <math.h>

class Vector {
public:
	float x, y;
	Vector();
	Vector(float x, float y);
	~Vector();
	Vector operator-(Vector);
	Vector operator+(Vector);
	void normalize();
};