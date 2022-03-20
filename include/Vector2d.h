#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include "common.h"

class Vector2 {
public:
	madflow x;
	madflow y;

	Vector2() : x(0.0f), y(0.0f) { }
	Vector2(madflow xx,madflow yy) : x(xx),y(yy) { }

	void Invert();
	madflow magnitude() const;
	madflow sqrtmagnitude() const;
	void normalize();

	void operator+=(const Vector2& v);
	Vector2 operator+(const Vector2& v) const;
	void operator-=(const Vector2& v);
	Vector2 operator-(const Vector2& v) const;
	void operator*=(const madflow scalar);
	Vector2 operator*(const madflow scalar) const;

	void clear();
	void addScaledVector(const Vector2& vec, const madflow scalar);
	Vector2 componentproduct(const Vector2& vec) const;
	void componentproductUpdate(const Vector2& vec);

	madflow scalarProduct(const Vector2& vec) const;
	madflow operator*(const Vector2& vec) const;

};

#endif
