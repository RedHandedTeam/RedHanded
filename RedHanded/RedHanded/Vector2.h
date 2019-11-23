#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

template <class T> class Vector2
{

public:

	static const Vector2<T> Up;
	static const Vector2<T> Down;
	static const Vector2<T> Left;
	static const Vector2<T> Right;
	static const Vector2<T> Zero;
	static const Vector2<T> One;

public:

	Vector2(T x = 0, T y = 0);
	
public:

	Vector2<T> operator+(const Vector2<T>& second) const;
	Vector2<T>& operator+=(const Vector2<T>& second);
	
	Vector2<T> operator-(const Vector2<T>& second) const;
	Vector2<T>& operator-=(const Vector2<T>& second);
	
	Vector2<T> operator*(const T second) const;
	Vector2<T>& operator*=(const T second);

	Vector2<T> operator/(const T second) const;
	Vector2<T>& operator/=(const T second);

	Vector2<T> operator-() const;
	
public:

	T Magnitude() const;
	T SqrMagnitude() const;
	T Distance(const Vector2<T>& second) const;
	T Dot(const Vector2<T>& second) const;

	Vector2<T> Normalize() const;
	Vector2<T> Lerp(const Vector2<T>& second, float delta) const;
	Vector2<T> Slerp(const Vector2<T>& second, float delta) const;

public:

	T x;
	T y;
};

template <class T> const Vector2<T> Vector2<T>::Up = Vector2<T>(0, 1);
template <class T> const Vector2<T> Vector2<T>::Down = Vector2<T>(0, -1);
template <class T> const Vector2<T> Vector2<T>::Left = Vector2<T>(-1, 0);
template <class T> const Vector2<T> Vector2<T>::Right = Vector2<T>(1, 0);
template <class T> const Vector2<T> Vector2<T>::Zero = Vector2<T>(0, 0);
template <class T> const Vector2<T> Vector2<T>::One = Vector2<T>(1, 1);
 
//======================================================================================================
template <class T> Vector2<T>::Vector2(T x, T y)
{
	this->x = x;
	this->y = y;
}
//======================================================================================================
template <class T> Vector2<T> Vector2<T>::operator+(const Vector2<T>& second) const
{
	Vector2<T> result(*this);
    return (result += second);
}
//======================================================================================================
template <class T> Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& second)
{
	x += second.x;
	y += second.y;
	return *this;
}
//======================================================================================================
template <class T> Vector2<T> Vector2<T>::operator-(const Vector2<T>& second) const
{
	Vector2<T> result(*this);
	return (result -= second);
}
//======================================================================================================
template <class T> Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& second)
{
	x -= second.x;
	y -= second.y;
	return *this;
}
//======================================================================================================
template <class T> Vector2<T> Vector2<T>::operator*(const T second) const
{
	Vector2<T> result(*this);
	return (result *= second);
}
//======================================================================================================
template <class T> Vector2<T>& Vector2<T>::operator*=(const T second)
{
	x *= second;
	y *= second;
	return *this;
}
//======================================================================================================
template <class T> Vector2<T> Vector2<T>::operator/(const T second) const
{
	Vector2<T> result(*this);
	return (result /= second);
}
//======================================================================================================
template <class T> Vector2<T>& Vector2<T>::operator/=(const T second)
{
	if (second != 0) x /= second;
	if (second != 0) y /= second;
	return *this;
}
//======================================================================================================
template <class T> Vector2<T> Vector2<T>::operator-() const
{
	Vector2<T> result(-x, -y);
	if (result.x == -0) result.x = 0;
	if (result.y == -0) result.y = 0;
	return result;
}
//======================================================================================================
template <class T> T Vector2<T>::Magnitude() const
{
	return sqrtf(SqrMagnitude());
}
//======================================================================================================
template <class T> T Vector2<T>::SqrMagnitude() const
{
	return (x * x) + (y * y);
}
//======================================================================================================
template <class T> T Vector2<T>::Distance(const Vector2<T>& second) const
{
	return (*this - second).Magnitude();
}
//======================================================================================================
template <class T> T Vector2<T>::Dot(const Vector2<T>& second) const
{
	return (x * second.x) + (y * second.y);
}
//======================================================================================================
template <class T> Vector2<T> Vector2<T>::Normalize() const
{
	return *this / Magnitude();
}
//======================================================================================================
template <class T> Vector2<T> Vector2<T>::Lerp(const Vector2<T>& second, float delta) const
{
	return *this + (second - *this) * delta;
}
//======================================================================================================
template<class T> Vector2<T> Vector2<T>::Slerp(const Vector2<T>& second, float delta) const
{
	float dot = Dot(second);
	dot = fmax(fmin(dot, 1.0f), -1.0f);
	float angle = acosf(dot) * delta;
	Vector2<T> relative = (second - *this * dot).Normalize();
	return (*this * cosf(angle)) + (relative * sinf(angle));
}

#endif