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

	//static Vector3D<double> AngleToVector(double angle, double size = 1.0, AxisType axis = Z_AXIS);
	//static Vector3D<double> Lerp(Vector3D<double>& firstVector, 
		                         Vector3D<double>& secondVector, double delta, double epsilon = 0.01);
	
public:

	Vector3(T x = 0, T y = 0, T z = 0);
	//Vector3D(VectorType vectorType);

public:

	Vector3<T>& operator=(const T rhs);
	//Vector3<T>& operator=(const VectorType rhs);

	Vector3<T> operator+(const Vector3<T>& rhs) const;
	//Vector3<T> operator+(const T rhs);
	Vector3<T>& operator+=(const Vector3<T>& rhs);
	//Vector3<T>& operator+=(const T rhs);

	Vector3<T> operator-(const Vector3<T>& rhs) const;
	//Vector3<T> operator-(const T rhs);
	Vector3<T>& operator-=(const Vector3<T>& rhs);
	//Vector3<T>& operator-=(const T rhs);

	//Vector3<T> operator*(const Vector3D<T>& rhs) const;
	Vector3<T> operator*(const T rhs);
	//Vector3<T>& operator*=(const Vector3D<T>& rhs);
	Vector3<T>& operator*=(const T rhs);

	//Vector3<T> operator/(const Vector3D<T>& rhs) const;
	Vector3<T> operator/(const T rhs);
	//Vector3<T>& operator/=(const Vector3D<T>& rhs);
	Vector3<T>& operator/=(const T rhs);

	//Vector3<T>& operator++();
	//Vector3<T> operator++(int);
	//Vector3<T>& operator--();
	//Vector3<T> operator--(int);

	Vector3<T> operator-();

	/*bool operator==(const Vector3D<T>& rhs);
	bool operator==(const T rhs);
	bool operator==(const VectorType rhs);
	
	bool operator!=(const Vector3D<T>& rhs);
	bool operator!=(const T rhs);
	bool operator!=(const VectorType rhs);

	bool operator<(const Vector3D<T>& rhs);
	bool operator<(const T rhs);
	bool operator<=(const Vector3D<T>& rhs);
	bool operator<=(const T rhs);

	bool operator>(const Vector3D<T>& rhs);
	bool operator>(const T rhs);
	bool operator>=(const Vector3D<T>& rhs);
	bool operator>=(const T rhs);*/

public:

	T Magnitude();
	T SqrMagnitude();
	T Distance(const Vector3<T>& secondVector);
	T Dot(const Vector3<T>& secondVector) const;
	Vector3<T> Cross(const Vector3<T>& secondVector) const;

	void Set(T x, T y, T z);
	//double Angle(Vector3D<T>& secondVector);
		
	Vector3<T> Normalize() const;
	//Vector2D<T> Convert2D() const;
	//Vector4D<T> Convert4D() const;
	

//public :

	//void Output(unsigned int precision = 0);

public :

	T x;
	T y;
	T z;

};

template <class T> const Vector3<T> Vector3<T>::Up = Vector3<T>(0, 1, 0);
template <class T> const Vector3<T> Vector3<T>::Down = Vector3<T>(0, -1, 0);
template <class T> const Vector3<T> Vector3<T>::Left = Vector3<T>(-1, 0, 0);
template <class T> const Vector3<T> Vector3<T>::Right = Vector3<T>(1, 0, 0);
template <class T> const Vector3<T> Vector3<T>::Forward = Vector3<T>(0, 0, 1);
template <class T> const Vector3<T> Vector3<T>::Back = Vector3<T>(0, 0, -1);
template <class T> const Vector3<T> Vector3<T>::Zero = Vector3<T>(0, 0, 0);
template <class T> const Vector3<T> Vector3<T>::One = Vector3<T>(1, 1, 1);

//------------------------------------------------------------------------------------------------------
//STATIC function that creates a Vector3D object based on angle, size and axis passed
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<double> Vector3D<T>::AngleToVector(double angle, double size, AxisType axis)
//{
//
//	//create a specific double type vector 
//	//which will be the resulting vector to send back
//	Vector3D<double> result;
//
//	//first convert the passed angle into a radian value
//	//so that the sin and cos functions can use it
//	double radian = angle / 180.0 * 3.14159265359;
//
//	//based on which axis value has been passed, calculate the cos and sin
//	//cos and sin of the passed angle calculate the respective x and y positions
//	//of the result vector in 3D space. However these positions are in effect 2D 
//	//positions on a particular plane, either X, Y or Z. Based on which plane we
//	//want to calculate x and y, assign the result of the other two components accordingly
//	switch (axis)
//	{
//
//		//the x axis is the plane that rotates around it. That means that
//		//the 2D Z and Y components are assigned their cos and sin results.
//		//Z is multiplied by negative 1 so that the angle gets larger from
//		//the negative Z to the positive Z axis
//		case X_AXIS:
//		{
//			result.Z = cos(radian) * -1;
//			result.Y = sin(radian);
//			break;
//		}
//
//		//the y axis is the plane that rotates around it. That means that
//		//the 2D X and Z components are assigned their cos and sin results.
//		//Z is multiplied by negative 1 so that the angle gets larger from
//		//the negative Z to the positive Z axis
//		case Y_AXIS:
//		{
//			result.X = cos(radian);
//			result.Z = sin(radian) * -1;
//			break;
//		}
//
//		//the z axis is the plane that rotates around it. That means that
//		//the 2D X and Y components are assigned their cos and sin results.
//		case Z_AXIS:
//		{
//			result.X = cos(radian);
//			result.Y = sin(radian);
//			break;
//		}
//
//	}
//
//	//the resulting vector will always be normalised
//	//so enlarge it based on size passed and return it
//	return (result *= size);
//
//}
//------------------------------------------------------------------------------------------------------
//STATIC function that performs linear interpolation between two Vector3D objects 
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<double> Vector3D<T>::Lerp(Vector3D<double>& firstVector,
//													  Vector3D<double>& secondVector,
//													  double delta, double epsilon)
//{
//
//	//use a simple algorithm to create the new lerped vector value
//	Vector3D<double> result = (firstVector * (1.0 - delta)) + (secondVector * delta);
//
//	//check if the difference between the XYZ components of the source and destination vector
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
//	if (abs(secondVector.Z - result.Z) <= epsilon)
//	{
//		result.Z = secondVector.Z;
//	}
//
//	return result;
//
//}
//------------------------------------------------------------------------------------------------------
//constructor that assigns X, Y and Z values
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T>::Vector3(T x, T y, T z)
{

	this->x = x;
	this->y = y;
	this->z = z;

}
//------------------------------------------------------------------------------------------------------
//second constructor that assigns X, Y and Z values based on vector enum type passed
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T>::Vector3D(VectorType vectorType)
//{
//
//	//based on vector type assign the XYZ values accordingly
//	//these types are best used for the common six directions
//	//and a null vector
//	switch (vectorType)
//	{
//		case ZERO:     { X = 0;  Y = 0;  Z = 0;  break; }
//		case LEFT:	   { X = -1; Y = 0;  Z = 0;  break; }
//		case RIGHT:	   { X = 1;  Y = 0;  Z = 0;  break; }
//		case UP:	   { X = 0;  Y = 1;  Z = 0;  break; }
//		case DOWN:	   { X = 0;  Y = -1; Z = 0;  break; }
//		case FORWARD:  { X = 0;  Y = 0;  Z = -1; break; }
//		case BACKWARD: { X = 0;  Y = 0;  Z = 1;  break; }
//	}
//
//}
//------------------------------------------------------------------------------------------------------
//function that assigns a value to a Vector3D object
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T>& Vector3<T>::operator=(const T rhs)
{
		
	x = rhs;
	y = rhs;
	z = rhs;
	
	//return a reference of the vector object so that 
	//assignment chaining can be used as well
	return *this;

}
//------------------------------------------------------------------------------------------------------
//function that assigns a value to a Vector3D object based on vector enum type passed
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T>& Vector3D<T>::operator=(const VectorType rhs)
//{
//
//	//based on vector type assign the XYZ values accordingly
//	switch (rhs)
//	{
//		case ZERO:     { X = 0;  Y = 0;  Z = 0;  break; }
//		case LEFT:	   { X = -1; Y = 0;  Z = 0;  break; }
//		case RIGHT:	   { X = 1;  Y = 0;  Z = 0;  break; }
//		case UP:	   { X = 0;  Y = 1;  Z = 0;  break; }
//		case DOWN:	   { X = 0;  Y = -1; Z = 0;  break; }
//		case FORWARD:  { X = 0;  Y = 0;  Z = -1; break; }
//		case BACKWARD: { X = 0;  Y = 0;  Z = 1;  break; }
//	}
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}
//------------------------------------------------------------------------------------------------------
//function that adds a Vector3D object to a value using the + member function (GLOBAL)
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> operator+(const T lhs, Vector3D<T>& rhs)
//{
//
//	return rhs + lhs;
//
//}
//------------------------------------------------------------------------------------------------------
//function that adds two Vector3D objects using the += member function
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T> Vector3<T>::operator+(const Vector3<T>& rhs) const
{

	Vector3<T> result(*this);
	return (result += rhs);

}
//------------------------------------------------------------------------------------------------------
//function that adds a value to a Vector3D object using the += member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> Vector3D<T>::operator+(const T rhs)
//{
//
//	Vector3D<T> result(*this);
//	return (result += rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that adds and assigns a Vector3D to another Vector3D object
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& rhs)
{

	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	//return a reference of the vector object so that 
	//assignment chaining can be used as well
	return *this;

}
//------------------------------------------------------------------------------------------------------
//function that adds and assigns a value to another Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T>& Vector3D<T>::operator+=(const T rhs)
//{
//
//	X += rhs;
//	Y += rhs;
//	Z += rhs;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}
//------------------------------------------------------------------------------------------------------
//function that subtracts a Vector3D object from a value using the - member function (GLOBAL)
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> operator-(const T lhs, Vector3D<T>& rhs)
//{
//
//	//create a temporary vector based on lhs passed value and then use -= function to subtract
//	//this is because subtraction differs between lhs - rhs and rhs - lhs 
//	//this method is the most efficient way to overcome this issue
//	Vector3D<T> result(lhs, lhs, lhs);
//	return (result -= rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that subtracts two Vector3D objects using the -= member function
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T> Vector3<T>::operator-(const Vector3<T>& rhs) const
{

	Vector3<T> result(*this);
	return (result -= rhs);

}
//------------------------------------------------------------------------------------------------------
//function that subtracts a value from a Vector3D object using the -= member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> Vector3D<T>::operator-(const T rhs)
//{
//
//	Vector3D<T> result(*this);
//	return (result -= rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that subtracts and assigns a Vector3D to another Vector3D object
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& rhs)
{

	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;

	//return a reference of the vector object so that 
	//assignment chaining can be used as well
	return *this;

}
//------------------------------------------------------------------------------------------------------
//function that subtracts and assigns a value to another Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T>& Vector3D<T>::operator-=(const T rhs)
//{
//
//	X -= rhs;
//	Y -= rhs;
//	Z -= rhs;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}
//------------------------------------------------------------------------------------------------------
//function that multiplies a value by a Vector3D object using the * member function (GLOBAL)
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> operator*(const T lhs, Vector3D<T>& rhs)
//{
//
//	return rhs * lhs;
//
//}
//------------------------------------------------------------------------------------------------------
//function that multiplies two Vector3D objects using the *= member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> Vector3D<T>::operator*(const Vector3D<T>& rhs) const
//{
//
//	Vector3D<T> result(*this);
//	return (result *= rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that multiplies a Vector3D object by a value using the *= member function
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T> Vector3<T>::operator*(const T rhs)
{

	Vector3<T> result(*this);
	return (result *= rhs);

}
//------------------------------------------------------------------------------------------------------
//function that multiplies and assigns a Vector3D to another Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T>& Vector3D<T>::operator*=(const Vector3D<T>& rhs)
//{
//
//	X *= rhs.X;
//	Y *= rhs.Y;
//	Z *= rhs.Z;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}
//------------------------------------------------------------------------------------------------------
//function that multiplies and assigns a value to another Vector3D object
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T>& Vector3<T>::operator*=(const T rhs)
{

	x *= rhs;
	y *= rhs;
	z *= rhs;

	//return a reference of the vector object so that 
	//assignment chaining can be used as well
	return *this;

}
//------------------------------------------------------------------------------------------------------
//function that divides a value by a Vector3D object using the /= member function (GLOBAL)
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> operator/(const T lhs, Vector3D<T>& rhs)
//{
//
//	//create a temporary vector based on lhs passed value and then use /= function to divide
//	//this is because division differs between lhs / rhs and rhs / lhs 
//	//this method is the most efficient way to overcome this issue
//	Vector3D<T> result(lhs, lhs, lhs);
//	return (result /= rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that divides two Vector3D objects using the /= member function
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> Vector3D<T>::operator/(const Vector3D<T>& rhs) const
//{
//
//	Vector3D<T> result(*this);
//	return (result /= rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that divides a Vector3D object by a value using the /= member function
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T> Vector3<T>::operator/(const T rhs)
{

	Vector3<T> result(*this);
	return (result /= rhs);

}
//------------------------------------------------------------------------------------------------------
//function that divides and assigns a Vector3D to another Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T>& Vector3D<T>::operator/=(const Vector3D<T>& rhs)
//{
//
//	//first make sure that we do not divide by 0!
//	if(rhs.X != 0) X /= rhs.X;
//	if(rhs.Y != 0) Y /= rhs.Y;
//	if(rhs.Z != 0) Z /= rhs.Z;
//
//	//return a reference of the vector object so that 
//	//assignment chaining can be used as well
//	return *this;
//
//}
//------------------------------------------------------------------------------------------------------
//function that divides and assigns a value to another Vector3D object
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T>& Vector3<T>::operator/=(const T rhs)
{

	//first make sure that we do not divide by 0!
	if(rhs != 0) x /= rhs;
	if(rhs != 0) y /= rhs;
	if(rhs != 0) z /= rhs;

	//return a reference of the vector object so that 
	//assignment chaining can be used as well
	return *this;

}
//------------------------------------------------------------------------------------------------------
//function that increments a Vector3D object using the prefix method
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T>& Vector3D<T>::operator++()
//{
//
//	X++;
//	Y++;
//	Z++;
//
//	//return a reference of the vector object because
//	//the object is changed before being used
//	return *this;
//
//}
//------------------------------------------------------------------------------------------------------
//function that increments a Vector3D object using the postfix method
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> Vector3D<T>::operator++(int)
//{
//
//	//first create a temporary vector before incrementing
//	Vector3D<T> temp(*this);
//	++(*this);
//	
//	//return the temporary vector instead of the incremented one
//	//because the old object needs to be used before the new one 
//	return temp;
//
//}
//------------------------------------------------------------------------------------------------------
//function that decrements a Vector3D object using the prefix method
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T>& Vector3D<T>::operator--()
//{
//
//	X--;
//	Y--;
//	Z--;
//
//	//return a reference of the vector object because
//	//the object is changed before being used
//	return *this;
//
//}
//------------------------------------------------------------------------------------------------------
//function that decrements a Vector3D object using the postfix method
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> Vector3D<T>::operator--(int)
//{
//
//	//first create a temporary vector before decrementing
//	Vector3D<T> temp(*this);
//	--(*this);
//
//	//return the temporary vector instead of the decremented one
//	//because the old object needs to be used before the new one 
//	return temp;
//
//}
//------------------------------------------------------------------------------------------------------
//function that negates a Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector3D<T> Vector3D<T>::operator-()
//{
//
//	Vector3D<T> temp(-X, -Y, -Z);
//
//	//make sure there is no -0
//	if(temp.X == -0) temp.X = 0;
//	if(temp.Y == -0) temp.Y = 0;
//	if(temp.Z == -0) temp.Z = 0;
//
//	return temp;
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if two Vector3D objects are identical
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator==(const Vector3D<T>& rhs)
//{
//
//	return (X == rhs.X && Y == rhs.Y && Z == rhs.Z);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector3D object is identical to a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator==(const T rhs)
//{
//
//	return (X == rhs && Y == rhs && Z == rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that checks if Vector3D object is a certain value based on vector enum type passed
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator==(const VectorType rhs)
//{
//
//	//check the XYZ values individually to see if that vector type is active
//	switch (rhs)
//	{
//		case ZERO:     { return (X == 0  && Y == 0  && Z == 0);  }
//		case LEFT:	   { return (X == -1 && Y == 0  && Z == 0);  }
//		case RIGHT:	   { return (X == 1  && Y == 0  && Z == 0);  }
//		case UP:	   { return (X == 0  && Y == 1  && Z == 0);  }
//		case DOWN:	   { return (X == 0  && Y == -1 && Z == 0);  }
//		case FORWARD:  { return (X == 0  && Y == 0  && Z == -1); }
//		case BACKWARD: { return (X == 0  && Y == 0  && Z == 1);  }
//	}
//
//	return false;
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if two Vector3D objects are unequal using the inverse of the == function
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator!=(const Vector3D<T>& rhs)
//{
//
//	return (!(*this == rhs));
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector3D object is unequal to a value using the inv. of the == function
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator!=(const T rhs)
//{
//
//	return (!(*this == rhs));
//
//}
//------------------------------------------------------------------------------------------------------
//function that checks if Vector3D object is not a certain value based on vector enum type passed
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator!=(const VectorType rhs)
//{
//
//	//use the == overloaded function and negate its result
//	//this will oppose the == functionality and prevent repetitive code
//	return !(*this == rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector3D object is smaller than another Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator<(const Vector3D<T>& rhs)
//{
//
//	return (X < rhs.X && Y < rhs.Y && Z < rhs.Z);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector3D object is smaller than a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator<(const T rhs)
//{
//
//	return (X < rhs && Y < rhs && Z < rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector3D object is smaller or equal to another Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator<=(const Vector3D<T>& rhs)
//{
//
//	//use the < and == member functions and return the result
//	return (*this < rhs || *this == rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector3D object is smaller or equal to a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator<=(const T rhs)
//{
//
//	//use the < and == member functions and return the result
//	return (*this < rhs || *this == rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector3D object is bigger than another Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator>(const Vector3D<T>& rhs)
//{
//
//	return (X > rhs.X && Y > rhs.Y && Z > rhs.Z);
//	
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector3D object is smaller than a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator>(const T rhs)
//{
//
//	return (X > rhs && Y > rhs && Z > rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector3D object is bigger than or equal to another Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator>=(const Vector3D<T>& rhs)
//{
//
//	//use the > and == member functions and return the result
//	return (*this > rhs || *this == rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that determines if a Vector3D object is bigger than or equal to a value
//------------------------------------------------------------------------------------------------------
//template <class T> bool Vector3D<T>::operator>=(const T rhs)
//{
//
//	//use the > and == member functions and return the result
//	return (*this > rhs || *this == rhs);
//
//}
//------------------------------------------------------------------------------------------------------
//function that calculates the length of a Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> T Vector3D<T>::Length()
//{
//
//	return (T)(sqrt(LengthSquared()));
//
//}
//------------------------------------------------------------------------------------------------------
//function that calculates the squared length of a Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> T Vector3D<T>::LengthSquared()
//{
//
//	return (X * X + Y * Y + Z * Z);
//
//}
//------------------------------------------------------------------------------------------------------
//function that calculates the distance between two Vector3D objects
//------------------------------------------------------------------------------------------------------
template <class T> T Vector3<T>::Distance(const Vector3<T>& secondVector)
{

	Vector3<T> temp(*this);
	temp -= secondVector;
	return temp.Length();

}
//------------------------------------------------------------------------------------------------------
//function that calculates the dot product of two Vector3D objects
//------------------------------------------------------------------------------------------------------
template <class T> T Vector3<T>::Dot(const Vector3<T>& secondVector) const
{

	return ((x * secondVector.x) + (y * secondVector.y) + (z * secondVector.z));

}
//------------------------------------------------------------------------------------------------------
//function that assigns all components of Vector3D object at once
//------------------------------------------------------------------------------------------------------
template <class T> void Vector3<T>::Set(T x, T y, T z)
{

	this->x = x;
	this->y = y;
	this->z = z;

}
//------------------------------------------------------------------------------------------------------
//function that calculates the angle in degrees between two Vector3D objects
//------------------------------------------------------------------------------------------------------
//template <class T> double Vector3D<T>::Angle(Vector3D<T>& secondVector)
//{
//
//	//manually cast the calling vector and passed vector object into double types
//	//so that precision is maintained in the following calculation
//	Vector3D<double> tempVector_1(X, Y, Z);
//	Vector3D<double> tempVector_2(secondVector.X, secondVector.Y, secondVector.Z);
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
//function that normalises a Vector3D object
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T> Vector3<T>::Normalize() const
{

	Vector3<T> temp(*this);

	T length = temp.Length();

	temp.x /= length;
	temp.y /= length;
	temp.z /= length;

	return temp;

}
//------------------------------------------------------------------------------------------------------
//function that converts the Vector3D object to a Vector2D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector2D<T> Vector3D<T>::Convert2D() const
//{
//
//	return Vector2D<T>(X, Y);
//
//}
//------------------------------------------------------------------------------------------------------
//function that converts the Vector3D object to a Vector4D object
//------------------------------------------------------------------------------------------------------
//template <class T> Vector4D<T> Vector3D<T>::Convert4D() const
//{
//
//	return Vector4D<T>(X, Y, Z);
//
//}
//------------------------------------------------------------------------------------------------------
//function that calculates the cross product of two Vector3D objects
//------------------------------------------------------------------------------------------------------
template <class T> Vector3<T> Vector3<T>::Cross(const Vector3<T>& secondVector) const
{

	Vector3D<T> crossProduct((y * secondVector.z - z * secondVector.y),
		                     (z * secondVector.x - x * secondVector.z),
		                     (x * secondVector.y - y * secondVector.x));

	return crossProduct;

}
//------------------------------------------------------------------------------------------------------
//function that displays X, Y and Z values of a Vector3D object
//------------------------------------------------------------------------------------------------------
//template <class T> void Vector3D<T>::Output(unsigned int precision)
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
//	std::cout << "X = " << X << " <<>> " << "Y = " << Y << " <<>> " << "Z = " << Z << std::endl;
//
//}

#endif