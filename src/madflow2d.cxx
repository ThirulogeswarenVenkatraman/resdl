#include "minclude.h"

void Vector2::Invert()
{
	x = -x;
	y = -y;
}

madflow Vector2::magnitude() const
{
	return madflow(x * x + y * y);
}

madflow Vector2::sqrtmagnitude() const
{
	return madflow(sqrt(x * x + y * y));
}

void Vector2::normalize()
{
	madflow mag = magnitude();

	if (mag > 0)
	{
		this->x *= ((madflow)1) / mag;
		this->y *= ((madflow)1) / mag;
	}
}

void Vector2::operator+=(const Vector2& v)
{
	this->x += v.x;
	this->y += v.y;
}

void Vector2::operator-=(const Vector2& v)
{
	this->x -= v.x;
	this->y -= v.y;
}

Vector2 Vector2::operator+(const Vector2& v) const 
{
	return Vector2(this->x + v.x, this->y + v.y);
}

Vector2 Vector2::operator-(const Vector2& v) const
{
	return Vector2(this->x - v.x, this->y - v.y);
}

void Vector2::operator*=(const madflow scalar) 
{
	x *= scalar;
	y *= scalar;
}

Vector2 Vector2::operator*(const madflow scalar) const
{
	return Vector2(x * scalar, y * scalar);
}

void Vector2::addScaledVector(const Vector2& vec, const madflow scalar)
{
	this->x += vec.x * scalar;
	this->y += vec.y * scalar;
}

Vector2 Vector2::componentproduct(const Vector2& vec) const
{
	return Vector2(this->x * vec.x, this->y * vec.y);
}

void Vector2::componentproductUpdate(const Vector2& vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
}

madflow Vector2::scalarProduct(const Vector2& vec) const
{
	return madflow(this->x * vec.x + this->y * vec.y);
}


madflow Vector2::operator*(const Vector2& vec) const
{
	return madflow(this->x * vec.x + this->y * vec.y);
}

void Vector2::clear()
{
	this->x = 0.0f;
	this->y = 0.0f;
}