#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

template <class T> class Vector2
{

public:

	//=============================================================
	static const Vector2<T> Up()	{ return Vector2<T>(0, 1); };
	static const Vector2<T> Down()	{ return Vector2<T>(0, -1); };
	static const Vector2<T> Left()	{ return Vector2<T>(-1, 0); };
	static const Vector2<T> Right()	{ return Vector2<T>(1, 0); };
	static const Vector2<T> Zero()	{ return Vector2<T>(0, 0); };
	static const Vector2<T> One()	{ return Vector2<T>(1, 1); };

public:

	//=============================================================
	inline Vector2(T x = 0, T y = 0)
	{
		this->x = x;
		this->y = y;
	}
	
public:

	//=============================================================
	inline Vector2<T> operator+(const Vector2<T>& second) const
	{
		Vector2<T> result(*this);
		return (result += second);
	}
	inline Vector2<T>& operator+=(const Vector2<T>& second)
	{
		x += second.x;
		y += second.y;
		return *this;
	}
	//=============================================================
	inline Vector2<T> operator-(const Vector2<T>& second) const
	{
		Vector2<T> result(*this);
		return (result -= second);
	}
	inline Vector2<T>& operator-=(const Vector2<T>& second)
	{
		x -= second.x;
		y -= second.y;
		return *this;
	}
	//=============================================================
	inline Vector2<T> operator*(const T second) const
	{
		Vector2<T> result(*this);
		return (result *= second);
	}
	inline Vector2<T>& operator*=(const T second)
	{
		x *= second;
		y *= second;
		return *this;
	}
	//=============================================================
	inline Vector2<T> operator/(const T second) const
	{
		Vector2<T> result(*this);
		return (result /= second);
	}
	inline Vector2<T>& operator/=(const T second)
	{
		if (second != 0) x /= second;
		if (second != 0) y /= second;
		return *this;
	}
	//=============================================================
	inline Vector2<T> operator-() const
	{
		Vector2<T> result(-x, -y);
		if (result.x == -0) result.x = 0;
		if (result.y == -0) result.y = 0;
		return result;
	}
	
public:

	//=============================================================
	inline T Magnitude() const
	{
		return sqrtf(SqrMagnitude());
	}
	inline T SqrMagnitude() const
	{
		return (x * x) + (y * y);
	}
	//=============================================================
	inline T Distance(const Vector2<T>& second) const
	{
		return (*this - second).Magnitude();
	}
	//=============================================================
	inline T Dot(const Vector2<T>& second) const
	{
		return (x * second.x) + (y * second.y);
	}
	//=============================================================
	inline Vector2<T> Normalize() const
	{
		return *this / Magnitude();
	}
	//=============================================================
	inline Vector2<T> Lerp(const Vector2<T>& second, float delta) const
	{
		return *this + (second - *this) * delta;
	}
	inline Vector2<T> Slerp(const Vector2<T>& second, float delta) const
	{
		float dot = Dot(second);
		dot = fmax(fmin(dot, 1.f), -1.f);
		float angle = acosf(dot) * delta;
		Vector2<T> relative = (second - *this * dot).Normalize();
		return (*this * cosf(angle)) + (relative * sinf(angle));
	}

public:

	T x;
	T y;
};

#endif