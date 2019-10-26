#ifndef VECTOR3_H
#define VECTOR3_H

template <class T> class Vector3
{

public:

	static const Vector3<T> Up;
	static const Vector3<T> Down;
	static const Vector3<T> Left;
	static const Vector3<T> Right;
	static const Vector3<T> Forward;
	static const Vector3<T> Back;
	static const Vector3<T> Zero;
	static const Vector3<T> One;

public:

	Vector3(T x = 0, T y = 0, T z = 0);

public:

	Vector3<T> operator+(const Vector3<T>& second) const;
	Vector3<T>& operator+=(const Vector3<T>& second);

	Vector3<T> operator-(const Vector3<T>& second) const;
	Vector3<T>& operator-=(const Vector3<T>& second);

	Vector3<T> operator*(const T second) const;
	Vector3<T>& operator*=(const T second);

	Vector3<T> operator/(const T second) const;
	Vector3<T>& operator/=(const T second);

	Vector3<T> operator-();

public:

	T Magnitude() const;
	T SqrMagnitude() const;
	T Distance(const Vector3<T>& second) const;
	T Dot(const Vector3<T>& second) const;

	Vector3<T> Normalize() const;
	Vector3<T> Cross(const Vector3<T>& second) const;
	Vector3<T> Lerp(const Vector3<T>& second, float delta) const;
	Vector3<T> Slerp(const Vector3<T>& second, float delta) const;

public:

	T x;
	T y;
	T z;
};

template <class T> const Vector3<T> Vector3<T>::Up = Vector3<T>(static_cast<T>(0), static_cast<T>(1), static_cast<T>(0));
template <class T> const Vector3<T> Vector3<T>::Down = Vector3<T>(static_cast<T>(0), static_cast<T>(-1), static_cast<T>(0));
template <class T> const Vector3<T> Vector3<T>::Left = Vector3<T>(static_cast<T>(-1), static_cast<T>(0), static_cast<T>(0));
template <class T> const Vector3<T> Vector3<T>::Right = Vector3<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
template <class T> const Vector3<T> Vector3<T>::Forward = Vector3<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
template <class T> const Vector3<T> Vector3<T>::Back = Vector3<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(-1));
template <class T> const Vector3<T> Vector3<T>::Zero = Vector3<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
template <class T> const Vector3<T> Vector3<T>::One = Vector3<T>(static_cast<T>(1), static_cast<T>(1), static_cast<T>(1));

//======================================================================================================
template <class T> Vector3<T>::Vector3(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
//======================================================================================================
template <class T> Vector3<T> Vector3<T>::operator+(const Vector3<T>& second) const
{
	Vector3<T> result(*this);
	return (result += second);
}
//======================================================================================================
template <class T> Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& second)
{
	x += second.x;
	y += second.y;
	z += second.z;
	return *this;
}
//======================================================================================================
template <class T> Vector3<T> Vector3<T>::operator-(const Vector3<T>& second) const
{
	Vector3<T> result(*this);
	return (result -= second);
}
//======================================================================================================
template <class T> Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& second)
{
	x -= second.x;
	y -= second.y;
	z -= second.z;
	return *this;
}
//======================================================================================================
template <class T> Vector3<T> Vector3<T>::operator*(const T second) const
{
	Vector3<T> result(*this);
	return (result *= second);
}
//======================================================================================================
template <class T> Vector3<T>& Vector3<T>::operator*=(const T second)
{
	x *= second;
	y *= second;
	z *= second;
	return *this;
}
//======================================================================================================
template <class T> Vector3<T> Vector3<T>::operator/(const T second) const
{
	Vector3<T> result(*this);
	return (result /= second);
}
//======================================================================================================
template <class T> Vector3<T>& Vector3<T>::operator/=(const T second)
{
	if (second != 0) x /= second;
	if (second != 0) y /= second;
	if (second != 0) z /= second;
	return *this;
}
//======================================================================================================
template <class T> Vector3<T> Vector3<T>::operator-()
{
	Vector3<T> result(-x, -y, -z);
	if (result.x == -0) result.x = 0;
	if (result.y == -0) result.y = 0;
	if (result.z == -0) result.z = 0;
	return result;
}
//======================================================================================================
template <class T> T Vector3<T>::Magnitude() const
{
	return static_cast<T>(sqrt(SqrMagnitude()));
}
//======================================================================================================
template <class T> T Vector3<T>::SqrMagnitude() const
{
	return x * x + y * y + z * z;
}
//======================================================================================================
template <class T> T Vector3<T>::Distance(const Vector3<T>& second) const
{
	return (*this - second).Magnitude();
}
//======================================================================================================
template <class T> T Vector3<T>::Dot(const Vector3<T>& second) const
{
	return (x * second.x) + (y * second.y) + (z * second.z);
}
//======================================================================================================
template <class T> Vector3<T> Vector3<T>::Normalize() const
{
	return *this / Magnitude();
}
//======================================================================================================
template <class T> Vector3<T> Vector3<T>::Cross(const Vector3<T>& second) const
{
	Vector3<T> result(y * second.z - z * second.y,
					  z * second.x - x * second.z,
					  x * second.y - y * second.x);
	return result;
}
//======================================================================================================
template <class T> Vector3<T> Vector3<T>::Lerp(const Vector3<T>& second, float delta) const
{
	return *this + (second - *this) * delta;
}
//======================================================================================================
template<class T> Vector3<T> Vector3<T>::Slerp(const Vector3<T>& second, float delta) const
{
	float dot = Dot(second);
	dot = max(min(dot, 1), -1);
	float angle = acos(dot) * delta;
	Vector3<T> relative = (second - *this * dot).Normalize();
	return (*this * cos(angle)) + (relative * sin(angle));
}

#endif