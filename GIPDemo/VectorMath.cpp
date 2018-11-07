#include "VectorMath.h"

Vector::Vector()
{
}

Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector::~Vector()
{
}

Vector Vector::operator-(Vector secondVector)
{
	Vector v;
	v.x = this->x - secondVector.x;
	v.y = this->y - secondVector.y;
	return v;
}

Vector Vector::operator+(Vector secondVector)
{
	Vector v;
	v.x = this->x + secondVector.x;
	v.y = this->y + secondVector.y;
	return v;
}

void Vector::normalize()
{
	float length = sqrt(pow(x,2) + pow(y,2));
	if (length > 0) {
		this->x /= length;
		this->y /= length;
	}
}
