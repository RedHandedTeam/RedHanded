#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>

template <class T> class Vector3
{

public:

	//=============================================================
	static const Vector3<T> Up()	  { return Vector3<T>(0, 1, 0); };
	static const Vector3<T> Down()	  { return Vector3<T>(0, -1, 0); };
	static const Vector3<T> Left()	  { return Vector3<T>(-1, 0, 0); };
	static const Vector3<T> Right()	  { return Vector3<T>(1, 0, 0); };
	static const Vector3<T> Forward() { return Vector3<T>(0, 0, 1); };
	static const Vector3<T> Back()	  { return Vector3<T>(0, 0, -1); };
	static const Vector3<T> Zero()	  { return Vector3<T>(0, 0, 0); };
	static const Vector3<T> One()	  { return Vector3<T>(1, 1, 1); };

public:

	//=============================================================
	inline Vector3(T x = 0, T y = 0, T z = 0)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

public:

	//=============================================================
	inline Vector3<T> operator+(const Vector3<T>& second) const
	{
		Vector3<T> result(*this);
		return (result += second);
	}
	inline Vector3<T>& operator+=(const Vector3<T>& second)
	{
		x += second.x;
		y += second.y;
		z += second.z;
		return *this;
	}
	//=============================================================
	inline Vector3<T> operator-(const Vector3<T>& second) const
	{
		Vector3<T> result(*this);
		return (result -= second);
	}
	inline Vector3<T>& operator-=(const Vector3<T>& second)
	{
		x -= second.x;
		y -= second.y;
		z -= second.z;
		return *this;
	}
	//=============================================================
	inline Vector3<T> operator*(const T second) const
	{
		Vector3<T> result(*this);
		return (result *= second);
	}
	inline Vector3<T>& operator*=(const T second)
	{
		x *= second;
		y *= second;
		z *= second;
		return *this;
	}
	//=============================================================
	inline Vector3<T> operator/(const T second) const
	{
		Vector3<T> result(*this);
		return (result /= second);
	}
	inline Vector3<T>& operator/=(const T second)
	{
		if (second != 0) x /= second;
		if (second != 0) y /= second;
		if (second != 0) z /= second;
		return *this;
	}
	//=============================================================
	inline Vector3<T> operator-() const
	{
		Vector3<T> result(-x, -y, -z);
		if (result.x == -0) result.x = 0;
		if (result.y == -0) result.y = 0;
		if (result.z == -0) result.z = 0;
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
		return (x * x) + (y * y) + (z * z);
	}
	//=============================================================
	inline T Distance(const Vector3<T>& second) const
	{
		return (*this - second).Magnitude();
	}
	inline T Dot(const Vector3<T>& second) const
	{
		return (x * second.x) + (y * second.y) + (z * second.z);
	}
	//=============================================================
	inline Vector3<T> Normalize() const
	{
		return *this / Magnitude();
	}
	inline Vector3<T> Cross(const Vector3<T>& second) const
	{
		return Vector3<T>(y * second.z - z * second.y,
						  z * second.x - x * second.z,
						  x * second.y - y * second.x);
	}
	//=============================================================
	inline Vector3<T> Lerp(const Vector3<T>& second, float delta) const
	{
		return *this + (second - *this) * delta;
	}
	inline Vector3<T> Slerp(const Vector3<T>& second, float delta) const
	{
		float dot = Dot(second);
		dot = fmax(fmin(dot, 1.f), -1.f);
		float angle = acosf(dot) * delta;
		Vector3<T> relative = (second - *this * dot).Normalize();
		return (*this * cosf(angle)) + (relative * sinf(angle));
	}

public:

	T x;
	T y;
	T z;
};

#endif