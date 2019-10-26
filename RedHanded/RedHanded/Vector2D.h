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

	Vector2<T>& operator=(const T rhs);
	//Vector2<T>& operator=(const VectorType rhs);

	Vector2<T> operator+(const Vector2<T>& rhs) const;
	//Vector2<T> operator+(const T rhs);
	Vector2<T>& operator+=(const Vector2<T>& rhs);
	//Vector2<T>& operator+=(const T rhs);

	Vector2<T> operator-(const Vector2<T>& rhs) const;
	//Vector2<T> operator-(const T rhs);
	Vector2<T>& operator-=(const Vector2<T>& rhs);
	//Vector2<T>& operator-=(const T rhs);

	//Vector2<T> operator*(const Vector2D<T>& rhs) const;
	Vector2<T> operator*(const T rhs);
	//Vector2<T>& operator*=(const Vector2D<T>& rhs);
	Vector2<T>& operator*=(const T rhs);

	//Vector2<T> operator/(const Vector2<T>& rhs) const;
	Vector2<T> operator/(const T rhs);
	//Vector2<T>& operator/=(const Vector2<T>& rhs);
	Vector2<T>& operator/=(const T rhs);

	//Vector2D<T>& operator++();
	//Vector2D<T> operator++(int);
	//Vector2D<T>& operator--();
	//Vector2D<T> operator--(int);

	Vector2<T> operator-();

	//bool operator==(const Vector2D<T>& rhs);
	//bool operator==(const T rhs);
	//bool operator==(const VectorType rhs);

	//bool operator!=(const Vector2D<T>& rhs);
	//bool operator!=(const T rhs);
	//bool operator!=(const VectorType rhs);

	//bool operator<(const Vector2D<T>& rhs);
	//bool operator<(const T rhs);
	//bool operator<=(const Vector2D<T>& rhs);
	//bool operator<=(const T rhs);

	//bool operator>(const Vector2D<T>& rhs);
	//bool operator>(const T rhs);
	//bool operator>=(const Vector2D<T>& rhs);
	//bool operator>=(const T rhs);

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

template <class T> const Vector2<T> Vector2<T>::Up = Vector2<T>(0, 1);
template <class T> const Vector2<T> Vector2<T>::Down = Vector2<T>(0, -1);
template <class T> const Vector2<T> Vector2<T>::Left = Vector2<T>(-1, 0);
template <class T> const Vector2<T> Vector2<T>::Right = Vector2<T>(1, 0);
template <class T> const Vector2<T> Vector2<T>::Zero = Vector2<T>(0, 0);
template <class T> const Vector2<T> Vector2<T>::One = Vector2<T>(1, 1);
 
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


//------------------------------------------------------------------------------------------------------
//constructor that assigns X and Y values
//------------------------------------------------------------------------------------------------------
template <class T> Vector2<T>::Vector2(T x, T y)
{

	this->x = static_cast<T>(x);
	this->y = static_cast<T>(y);

}



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
//template <class T> Vector2<T>& Vector2<T>::operator=(const T rhs)
//{
//
//	x = rhs;
//	y = rhs;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}



//------------------------------------------------------------------------------------------------------
//function that assigns a value to a Vector2D object based on vector enum type passed
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T>& Vector2D<T>::operator=(const VectorType rhs)
//{
//
//	//based on vector type assign the XY values accordingly
//	switch (rhs)
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
//------------------------------------------------------------------------------------------------------
//function that adds a Vector2D object to a value using the + member function (GLOBAL)
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T> operator+(const T lhs, Vector2D<T>& rhs)
//{
//
//	return rhs + lhs;
//
//}




//------------------------------------------------------------------------------------------------------
//function that adds two Vector2D objects using the += member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2<T> Vector2<T>::operator+(const Vector2<T>& rhs) const
//{
//
//	Vector2<T> result(*this);
//	return (result += rhs);
//
//}




//------------------------------------------------------------------------------------------------------
//function that adds a value to a Vector2D object using the += member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T> Vector2D<T>::operator+(const T rhs)
//{
//
//	Vector2D<T> result(*this);
//	return (result += rhs);
//
//}




//------------------------------------------------------------------------------------------------------
//function that adds and assigns a Vector2D to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& rhs)
//{
//
//	x += rhs.x;
//	y += rhs.y;
//	
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}




//------------------------------------------------------------------------------------------------------
//function that adds and assigns a value to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T>& Vector2D<T>::operator+=(const T rhs)
//{
//
//	X += rhs;
//	Y += rhs;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}
//------------------------------------------------------------------------------------------------------
//function that subtracts a Vector2D object from a value using the - member function (GLOBAL)
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T> operator-(const T lhs, Vector2D<T>& rhs)
//{
//
//	//create a temporary vector based on lhs passed value and then use -= function to subtract
//	//this is because subtraction differs between lhs - rhs and rhs - lhs 
//	//this method is the most efficient way to overcome this issue
//	Vector2D<T> result(lhs, lhs);
//	return (result -= rhs);
//
//}




//------------------------------------------------------------------------------------------------------
//function that subtracts two Vector2D objects using the -= member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2<T> Vector2<T>::operator-(const Vector2<T>& rhs) const
//{
//
//	Vector2<T> result(*this);
//	return (result -= rhs);
//
//}




//------------------------------------------------------------------------------------------------------
//function that subtracts a value from a Vector2D object using the -= member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T> Vector2D<T>::operator-(const T rhs)
//{
//
//	Vector2D<T> result(*this);
//	return (result -= rhs);
//
//}




//------------------------------------------------------------------------------------------------------
//function that subtracts and assigns a Vector2D to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& rhs)
//{
//
//	x -= rhs.x;
//	y -= rhs.y;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}




//------------------------------------------------------------------------------------------------------
//function that subtracts and assigns a value to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T>& Vector2D<T>::operator-=(const T rhs)
//{
//
//	X -= rhs;
//	Y -= rhs;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}
//------------------------------------------------------------------------------------------------------
//function that multiplies a value by a Vector2D object using the * member function (GLOBAL)
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T> operator*(const T lhs, Vector2D<T>& rhs)
//{
//
//	return rhs * lhs;
//
//}
//------------------------------------------------------------------------------------------------------
//function that multiplies two Vector2D objects using the *= member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T> Vector2D<T>::operator*(const Vector2D<T>& rhs) const
//{
//
//	Vector2D<T> result(*this);
//	return (result *= rhs);
//
//}




//------------------------------------------------------------------------------------------------------
//function that multiplies a Vector2D object by a value using the *= member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2<T> Vector2<T>::operator*(const T rhs)
//{
//
//	Vector2<T> result(*this);
//	return (result *= rhs);
//
//}



//------------------------------------------------------------------------------------------------------
//function that multiplies and assigns a Vector2D to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T>& Vector2D<T>::operator*=(const Vector2D<T>& rhs)
//{
//
//	X *= rhs.X;
//	Y *= rhs.Y;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}




//------------------------------------------------------------------------------------------------------
//function that multiplies and assigns a value to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2<T>& Vector2<T>::operator*=(const T rhs)
//{
//
//	x *= rhs;
//	y *= rhs;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}




//------------------------------------------------------------------------------------------------------
//function that divides a value by a Vector2D object using the /= member function (GLOBAL)
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T> operator/(const T lhs, Vector2D<T>& rhs)
//{
//
//	//create a temporary vector based on lhs passed value and then use /= function to divide
//	//this is because division differs between lhs / rhs and rhs / lhs 
//	//this method is the most efficient way to overcome this issue
//	Vector2D<T> result(lhs, lhs);
//	return (result /= rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that divides two Vector2D objects using the /= member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T> Vector2D<T>::operator/(const Vector2D<T>& rhs) const
//{
//
//	Vector2D<T> result(*this);
//	return (result /= rhs);
//
//}




//------------------------------------------------------------------------------------------------------
//function that divides a Vector2D object by a value using the /= member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2<T> Vector2<T>::operator/(const T rhs)
//{
//
//	Vector2<T> result(*this);
//	return (result /= rhs);
//
//}




//------------------------------------------------------------------------------------------------------
//function that divides and assigns a Vector2D to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T>& Vector2D<T>::operator/=(const Vector2D<T>& rhs)
//{
//
//	//first make sure that we do not divide by 0!
//	if (rhs.X != 0) X /= rhs.X;
//	if (rhs.Y != 0) Y /= rhs.Y;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}




//------------------------------------------------------------------------------------------------------
//function that divides and assigns a value to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2<T>& Vector2<T>::operator/=(const T rhs)
//{
//
//	//first make sure that we do not divide by 0!
//	if (rhs != 0) x /= rhs;
//	if (rhs != 0) y /= rhs;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}




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
//template <class T> bool Vector2D<T>::operator==(const Vector2D<T>& rhs)
//{
//
//	return (X == rhs.X && Y == rhs.Y);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is identical to a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator==(const T rhs)
//{
//
//	return (X == rhs && Y == rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that checks if Vector2D object is a certain value based on vector enum type passed
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator==(const VectorType rhs)
//{
//
//	//check the XY values individually to see if that vector type is active
//	switch (rhs)
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
//template <class T> bool Vector2D<T>::operator!=(const Vector2D<T>& rhs)
//{
//
//	return (!(*this == rhs));
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is unequal to a value using the inv. of the == function
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator!=(const T rhs)
//{
//
//	return (!(*this == rhs));
//
//}
//------------------------------------------------------------------------------------------------------
//function that checks if Vector2D object is not a certain value based on vector enum type passed
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator!=(const VectorType rhs)
//{
//
//	//use the == overloaded function and negate its result
//	//this will oppose the == functionality and prevent repetitive code
//	return !(*this == rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is smaller than another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator<(const Vector2D<T>& rhs)
//{
//
//	return (X < rhs.X && Y < rhs.Y);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is smaller than a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator<(const T rhs)
//{
//
//	return (X < rhs && Y < rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is smaller or equal to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator<=(const Vector2D<T>& rhs)
//{
//
//	//use the < and == member functions and return the result
//	return (*this < rhs || *this == rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is smaller or equal to a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator<=(const T rhs)
//{
//
//	//use the < and == member functions and return the result
//	return (*this < rhs || *this == rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is bigger than another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator>(const Vector2D<T>& rhs)
//{
//
//	return (X > rhs.X && Y > rhs.Y);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is smaller than a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator>(const T rhs)
//{
//
//	return (X > rhs && Y > rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is bigger than or equal to another Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator>=(const Vector2D<T>& rhs)
//{
//
//	//use the > and == member functions and return the result
//	return (*this > rhs || *this == rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector2D object is bigger than or equal to a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector2D<T>::operator>=(const T rhs)
//{
//
//	//use the > and == member functions and return the result
//	return (*this > rhs || *this == rhs);
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