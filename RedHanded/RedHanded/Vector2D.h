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
	//Vector2(VectorType vectorType);

public:

	Vector2<T>& operator=(const T second);
	//Vector2<T>& operator=(const VectorType second);

	Vector2<T> operator+(const Vector2<T>& second) const;
	Vector2<T>& operator+=(const Vector2<T>& second);
	
	Vector2<T> operator-(const Vector2<T>& second) const;
	Vector2<T>& operator-=(const Vector2<T>& second);
	
	Vector2<T> operator*(const T second) const;
	Vector2<T>& operator*=(const T second);

	Vector2<T> operator/(const T second) const;
	Vector2<T>& operator/=(const T second);

	//Vector2D<T>& operator++();
	//Vector2D<T> operator++(int);
	//Vector2D<T>& operator--();
	//Vector2D<T> operator--(int);

	Vector2<T> operator-();

	//bool operator==(const Vector2D<T>& second);
	//bool operator==(const T second);
	//bool operator==(const VectorType second);

	//bool operator!=(const Vector2D<T>& second);
	//bool operator!=(const T second);
	//bool operator!=(const VectorType second);

	//bool operator<(const Vector2D<T>& second);
	//bool operator<(const T second);
	//bool operator<=(const Vector2D<T>& second);
	//bool operator<=(const T second);

	//bool operator>(const Vector2D<T>& second);
	//bool operator>(const T second);
	//bool operator>=(const Vector2D<T>& second);
	//bool operator>=(const T second);

public:

	T Magnitude();
	T SqrMagnitude();
	T Lerp(const Vector2<T> secondVector);
	T Distance(const Vector2<T>& secondVector);
	T Dot(const Vector2<T>& secondVector) const;
	
	void Set(T x, T y);
	//double Angle(Vector2D<T>& secondVector);

	Vector2<T> Normalize() const;
	//Vector3D<T> Convert3D() const;
	//Vector4D<T> Convert4D() const;

public:

	T x;
	T y;

	static int i;

};


//int Vector2::i = 10;

template <class T> const Vector2<T> Vector2<T>::Up = Vector2<T>(static_cast<T>(0), static_cast<T>(1));
template <class T> const Vector2<T> Vector2<T>::Down = Vector2<T>(static_cast<T>(0), static_cast<T>(-1));
template <class T> const Vector2<T> Vector2<T>::Left = Vector2<T>(static_cast<T>(-1), static_cast<T>(0));
template <class T> const Vector2<T> Vector2<T>::Right = Vector2<T>(static_cast<T>(1), static_cast<T>(0));
template <class T> const Vector2<T> Vector2<T>::Zero = Vector2<T>(static_cast<T>(0), static_cast<T>(0));
template <class T> const Vector2<T> Vector2<T>::One = Vector2<T>(static_cast<T>(1), static_cast<T>(1));
 
//------------------------------------------------------------------------------------------------------
//STATIC function that creates a Vector2D object based on angle, size and axis passed
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<double> Vector2D<T>::AngleToVector(double angle, double size)
//{
//
//	//create a specific double type vector 
//	//which will be the resulting vector to send back
//	Vector2D<double> result;
//
//	//first convert the passed angle into a radian value
//	//so that the sin and cos functions can use it
//	double radian = angle / 180.0 * 3.14159265359;
//
//	//calculate the cos and sin of the passed angle
//	//to determine the resulting X and Y values
//	result.X = cos(radian);
//	result.Y = sin(radian);
//		
//	//the resulting vector will always be normalised
//	//so enlarge it based on size passed and return it
//	return (result *= size);
//
//}
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


//------------------------------------------------------------------------------------------------------
//second constructor that assigns X and Y values based on vector enum type passed
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T>::Vector2D(VectorType vectorType)
//{
//
//	//based on vector type assign the XY values accordingly
//	//these types are best used for the common four directions
//	//and a null vector
//	switch (vectorType)
//	{
//		case ZERO:     { X = 0;  Y = 0;  break; }
//		case LEFT:	   { X = -1; Y = 0;  break; }
//		case RIGHT:	   { X = 1;  Y = 0;  break; }
//		case UP:	   { X = 0;  Y = 1;  break; }
//		case DOWN:	   { X = 0;  Y = -1; break; }
//	}
//
//}



//------------------------------------------------------------------------------------------------------
//function that assigns a value to a Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2<T>& Vector2<T>::operator=(const T second)
//{
//
//	x = second;
//	y = second;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}



//------------------------------------------------------------------------------------------------------
//function that assigns a value to a Vector2D object based on vector enum type passed
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T>& Vector2D<T>::operator=(const VectorType second)
//{
//
//	//based on vector type assign the XY values accordingly
//	switch (second)
//	{
//		case ZERO:     { X = 0;  Y = 0;  break; }
//		case LEFT:	   { X = -1; Y = 0;  break; }
//		case RIGHT:	   { X = 1;  Y = 0;  break; }
//		case UP:	   { X = 0;  Y = 1;  break; }
//		case DOWN:	   { X = 0;  Y = -1; break; }
//	}
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}


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




//------------------------------------------------------------------------------------------------------
//function that increments a Vector2D object using the prefix method
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T>& Vector2D<T>::operator++()
//{
//
//	X++;
//	Y++;
//	
//	//return a reference of the vector object because
//	//the object is changed before being used
//	return *this;
//
//}
//------------------------------------------------------------------------------------------------------
//function that increments a Vector2D object using the postfix method
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T> Vector2D<T>::operator++(int)
//{
//
//	//first create a temporary vector before incrementing
//	Vector2D<T> temp(*this);
//	++(*this);
//
//	//return the temporary vector instead of the incremented one
//	//because the old object needs to be used before the new one 
//	return temp;
//
//}
//------------------------------------------------------------------------------------------------------
//function that decrements a Vector2D object using the prefix method
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T>& Vector2D<T>::operator--()
//{
//
//	X--;
//	Y--;
//
//	//return a reference of the vector object because
//	//the object is changed before being used
//	return *this;
//
//}
//------------------------------------------------------------------------------------------------------
//function that decrements a Vector2D object using the postfix method
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T> Vector2D<T>::operator--(int)
//{
//
//	//first create a temporary vector before decrementing
//	Vector2D<T> temp(*this);
//	--(*this);
//
//	//return the temporary vector instead of the decremented one
//	//because the old object needs to be used before the new one 
//	return temp;
//
//}




//------------------------------------------------------------------------------------------------------
//function that negates a Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2<T> Vector2<T>::operator-()
//{
//
//	Vector2<T> temp(-x, -y);
//
//	//make sure there is no -0
//	if (temp.x == -0) temp.x = 0;
//	if (temp.y == -0) temp.y = 0;
//
//	return temp;
//
//}



//------------------------------------------------------------------------------------------------------
//function that determines if two Vector2D objects are identical
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator==(const Vector2D<T>& second)
//{
//
//	return (X == second.X && Y == second.Y);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is identical to a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator==(const T second)
//{
//
//	return (X == second && Y == second);
//
//}
//------------------------------------------------------------------------------------------------------
//function that checks if Vector2D object is a certain value based on vector enum type passed
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator==(const VectorType second)
//{
//
//	//check the XY values individually to see if that vector type is active
//	switch (second)
//	{
//		case ZERO:     { return (X == 0 && Y == 0);  }
//		case LEFT:	   { return (X == -1 && Y == 0); }
//		case RIGHT:	   { return (X == 1 && Y == 0);  }
//		case UP:	   { return (X == 0 && Y == 1);  }
//		case DOWN:	   { return (X == 0 && Y == -1); }
//	}
//
//	return false;
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if two Vector2D objects are unequal using the inverse of the == function
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator!=(const Vector2D<T>& second)
//{
//
//	return (!(*this == second));
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is unequal to a value using the inv. of the == function
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator!=(const T second)
//{
//
//	return (!(*this == second));
//
//}
//------------------------------------------------------------------------------------------------------
//function that checks if Vector2D object is not a certain value based on vector enum type passed
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator!=(const VectorType second)
//{
//
//	//use the == overloaded function and negate its result
//	//this will oppose the == functionality and prevent repetitive code
//	return !(*this == second);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is smaller than another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator<(const Vector2D<T>& second)
//{
//
//	return (X < second.X && Y < second.Y);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is smaller than a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator<(const T second)
//{
//
//	return (X < second && Y < second);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is smaller or equal to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator<=(const Vector2D<T>& second)
//{
//
//	//use the < and == member functions and return the result
//	return (*this < second || *this == second);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is smaller or equal to a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator<=(const T second)
//{
//
//	//use the < and == member functions and return the result
//	return (*this < second || *this == second);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is bigger than another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator>(const Vector2D<T>& second)
//{
//
//	return (X > second.X && Y > second.Y);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is smaller than a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator>(const T second)
//{
//
//	return (X > second && Y > second);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is bigger than or equal to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator>=(const Vector2D<T>& second)
//{
//
//	//use the > and == member functions and return the result
//	return (*this > second || *this == second);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is bigger than or equal to a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator>=(const T second)
//{
//
//	//use the > and == member functions and return the result
//	return (*this > second || *this == second);
//
//}





//------------------------------------------------------------------------------------------------------
//function that calculates the length of a Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> T Vector2<T>::Magnitude()
//{
//
//	return (T)(sqrt(LengthSquared()));
//
//}
////------------------------------------------------------------------------------------------------------
////function that calculates the squared length of a Vector2D object
////------------------------------------------------------------------------------------------------------
//template <class T> T Vector2<T>::SqrMagnitude()
//{
//
//	return (x * x + y * y);
//
//}





//------------------------------------------------------------------------------------------------------
//function that calculates the distance between two Vector2D objects
//------------------------------------------------------------------------------------------------------
//template <class T> T Vector2<T>::Distance(const Vector2<T>& secondVector)
//{
//
//	Vector2<T> temp(*this);
//	temp -= secondVector;
//	return temp.Length();
//
//}
////------------------------------------------------------------------------------------------------------
////function that calculates the dot product of two Vector2D objects
////------------------------------------------------------------------------------------------------------
//template <class T> T Vector2<T>::Dot(const Vector2<T>& secondVector) const
//{
//
//	return ((x * secondVector.x) + (y * secondVector.y));
//
//}
////------------------------------------------------------------------------------------------------------
////function that assigns all components of Vector2D object at once
////------------------------------------------------------------------------------------------------------
//template <class T> void Vector2<T>::Set(T x, T y)
//{
//
//	this->x = x;
//	this->y = y;
//
//}





//------------------------------------------------------------------------------------------------------
//function that calculates the angle in degrees between two Vector2D objects
//------------------------------------------------------------------------------------------------------
//template <class T> double Vector2<T>::Angle(Vector2D<T>& secondVector)
//{
//
//	//manually cast the calling vector and passed vector object into double types
//	//so that precision is maintained in the following calculation
//	Vector2D<double> tempVector_1(X, Y);
//	Vector2D<double> tempVector_2(secondVector.X, secondVector.Y);
//
//	//calculate the angle in radians using a formula
//	double radian = acos((tempVector_1.DotProduct(tempVector_2)) /
//		                 (tempVector_1.Length() * tempVector_2.Length()));
//
//	//convert the angle to degrees before returning it
//	return (radian / 3.14159265359 * 180.0);
//
//}




//------------------------------------------------------------------------------------------------------
//function that normalises a Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2<T> Vector2<T>::Normalize() const
//{
//
//	Vector2<T> temp(*this);
//
//	T length = temp.Length();
//
//	temp.x /= length;
//	temp.y /= length;
//
//	return temp;
//
//}



//------------------------------------------------------------------------------------------------------
//function that converts the Vector2D object to a Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> Vector2D<T>::Convert3D() const
//{
//
//	return Vector3D<T>(X, Y); 
//
//}
//------------------------------------------------------------------------------------------------------
//function that converts the Vector2D object to a Vector4D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector4D<T> Vector2D<T>::Convert4D() const
//{
//
//	return Vector4D<T>(X, Y);
//
//}
//------------------------------------------------------------------------------------------------------
//function that displays X and Y values of a Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> void Vector2D<T>::Output(unsigned int precision)
//{
//
//	//if precision value is passed then set display mode 
//	//to floating point notation and set the precision accordingly
//	if (precision > 0)
//	{
//		std::cout << std::fixed;
//		std::cout << std::setprecision(precision);
//	}
//
//	std::cout << "X = " << X << " <<>> " << "Y = " << Y << std::endl;
//
//}

#endif