#ifndef VECTOR2_H
#define VECTOR2_H

//#include <iomanip>
//#include <iostream>
//#include <math.h>

//template <class T> class Vector3D;

template <class T> class Vector2
{

public:

	static const Vector2<T> Up;
	static const Vector2<T> Down;
	static const Vector2<T> Left;
	static const Vector2<T> Right;
	static const Vector2<T> Zero;
	static const Vector2<T> One;

	//static Vector2D<double> AngleToVector(double angle, double size = 100.0);
	//static Vector2D<double> Lerp(Vector2<double>& firstVector,
		//                         Vector2<double>& secondVector, double delta, double epsilon = 0.01);

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

	Vector2<T> operator-();
	
public:

	T Magnitude();
	T SqrMagnitude();
	T Lerp(const Vector2<T> second);
	T Distance(const Vector2<T>& second);
	T Dot(const Vector2<T>& second) const;
	Vector2<T> Normalize() const;
	
public:

	T x;
	T y;

};

template <class T> const Vector2<T> Vector2<T>::Up = Vector2<T>(static_cast<T>(0), static_cast<T>(1));
template <class T> const Vector2<T> Vector2<T>::Down = Vector2<T>(static_cast<T>(0), static_cast<T>(-1));
template <class T> const Vector2<T> Vector2<T>::Left = Vector2<T>(static_cast<T>(-1), static_cast<T>(0));
template <class T> const Vector2<T> Vector2<T>::Right = Vector2<T>(static_cast<T>(1), static_cast<T>(0));
template <class T> const Vector2<T> Vector2<T>::Zero = Vector2<T>(static_cast<T>(0), static_cast<T>(0));
template <class T> const Vector2<T> Vector2<T>::One = Vector2<T>(static_cast<T>(1), static_cast<T>(1));
 

//------------------------------------------------------------------------------------------------------
//STATIC function that performs linear interpolation between two Vector2D objects 
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<double> Vector2D<T>::Lerp(Vector2D<double>& firstVector,
//	                                                  Vector2D<double>& secondVector,
//	                                                  double delta, double epsilon)
//{
//
//	//use a simple algorithm to create the new lerped vector value
//	Vector2D<double> result = (firstVector * (1.0 - delta)) + (secondVector * delta);
//
//	//check if the difference between the XY components of the source and destination vector
//	//are within the epsilon range. If they are, make them both equal. This ensures that the source
//	//vector will reach the destination value as quick as the epsilon value states. The smaller the 
//	//epsilon value, the longer it will take to reach the destination vector.
//	if (abs(secondVector.X - result.X) <= epsilon)
//	{
//		result.X = secondVector.X;
//	}
//
//	if (abs(secondVector.Y - result.Y) <= epsilon)
//	{
//		result.Y = secondVector.Y;
//	}
//
//	return result;
//
//}


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
template <class T> Vector2<T> Vector2<T>::operator-()
{
	Vector2<T> result(-x, -y);
	if (result.x == -0) result.x = 0;
	if (result.y == -0) result.y = 0;
	return result;
}
//======================================================================================================
template <class T> T Vector2<T>::Magnitude()
{
	return static_cast<T>(sqrt(SqrMagnitude()));
}
//======================================================================================================
template <class T> T Vector2<T>::SqrMagnitude()
{
	return (x * x + y * y);
}


//lerp...


//======================================================================================================
template <class T> T Vector2<T>::Distance(const Vector2<T>& second)
{
	Vector2<T> result(*this);
	result -= second;
	return result.Magnitude();
}
//======================================================================================================
template <class T> T Vector2<T>::Dot(const Vector2<T>& second) const
{
	return ((x * second.x) + (y * second.y));
}
//======================================================================================================
template <class T> Vector2<T> Vector2<T>::Normalize() const
{
	Vector2<T> result(*this);
	T length = result.Magnitude();
	result /= length;
	return result;
}

#endif