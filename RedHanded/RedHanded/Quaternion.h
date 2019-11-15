#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector3.h"

#define PI = 3.14159265359;

class Quaternion
{

public:

	static const Quaternion Identity;

public:

	Quaternion(float x = 0, float y = 0, float z = 0, float w = 1);
	Quaternion(Vector3<float> axis, float angle);
	
private:

	Quaternion operator+(const Quaternion& second) const;
	Quaternion& operator+=(const Quaternion& second);

	Quaternion operator-(const Quaternion& second) const;
	Quaternion& operator-=(const Quaternion& second);
	
	Quaternion operator*(const float& second) const;
	Quaternion operator/(const float& second) const;

public:

	Quaternion operator*(const Quaternion& second) const;
	Quaternion& operator*=(const Quaternion& second);

	Quaternion operator/(const Quaternion& second) const;
	Quaternion& operator/=(const Quaternion& second);

	Vector3<float> operator*(const Vector3<float>& second) const;

public:

	float Magnitude() const;
	float SqrMagnitude() const;
	float Angle(const Quaternion& second) const;
	float Dot(const Quaternion& second) const;

	Quaternion Inverse() const;
	Quaternion Conjugate() const;
	Quaternion Normalize() const;
	Quaternion Slerp(const Quaternion& second, float delta) const;

public:

	Vector3<float> xyz;
	float w;
};

const Quaternion Quaternion::Identity = Quaternion(0, 0, 0, 1);

//======================================================================================================
Quaternion::Quaternion(float x, float y, float z, float w)
{
	this->xyz = Vector3<float>(x, y, z);
	this->w = w;
}
//======================================================================================================
Quaternion::Quaternion(Vector3<float> axis, float angle)
{
	double radian = angle / 180.0 * PI;
	double sinThetaOverTwo = sinf(radian / 2.0f);
	double cosThetaOverTwo = cosf(radian / 2.0f);

	w = cosThetaOverTwo;
	xyz.x *= sinThetaOverTwo;
	xyz.y *= sinThetaOverTwo;
	xyz.z *= sinThetaOverTwo;
}
//======================================================================================================
Quaternion Quaternion::operator+(const Quaternion& second) const
{
	Quaternion result(*this);
	return (result += second);
}
//======================================================================================================
Quaternion& Quaternion::operator+=(const Quaternion& second)
{
	xyz += second.xyz;
	w += second.w;
	return *this;
}
//======================================================================================================
Quaternion Quaternion::operator-(const Quaternion& second) const
{
	Quaternion result(*this);
	return (result -= second);
}
//======================================================================================================
Quaternion& Quaternion::operator-=(const Quaternion& second)
{
	xyz -= second.xyz;
	w -= second.w;
	return *this;
}
//======================================================================================================
Quaternion Quaternion::operator*(const float& second) const
{
	return Quaternion(xyz * second, w * second);
}
//======================================================================================================
Quaternion Quaternion::operator/(const float& second) const
{
	return Quaternion(xyz / second, w / second);
}
//======================================================================================================
Quaternion Quaternion::operator*(const Quaternion& second) const
{
	Quaternion result(*this);
	return (result *= second);
}
//======================================================================================================
Quaternion& Quaternion::operator*=(const Quaternion& second)
{
	Vector3<float> imaginary = second.xyz * w + xyz * second.w + xyz.Cross(second.xyz);
	w = w * second.w - xyz.Dot(second.xyz);
	xyz = imaginary;
	return *this;
}
//======================================================================================================
Quaternion Quaternion::operator/(const Quaternion& second) const
{
	Quaternion result(*this);
	return (result /= second);
}
//======================================================================================================
Quaternion& Quaternion::operator/=(const Quaternion& second)
{
	return *this *= second.Inverse();
}
//======================================================================================================
Vector3<float> Quaternion::operator*(const Vector3<float>& second) const
{
	Vector3<float> cross = xyz.Cross(second) * 2;
	return second + cross * w + xyz.Cross(cross);
}
//======================================================================================================
float Quaternion::Magnitude() const
{
	return sqrtf(SqrMagnitude());
}
//======================================================================================================
float Quaternion::SqrMagnitude() const
{
	return xyz.SqrMagnitude() + (w * w);
}
//======================================================================================================
float Quaternion::Angle(const Quaternion& second) const
{
	return 2 * acosf((Inverse() * second).w) * (180 / PI);
}
//======================================================================================================
float Quaternion::Dot(const Quaternion& second) const
{
	return xyz.Dot(second.xyz) + (w * second.w);
}
//======================================================================================================
Quaternion Quaternion::Inverse() const
{
	return  Conjugate() / SqrMagnitude();
}
//======================================================================================================
Quaternion Quaternion::Conjugate() const
{
	return Quaternion(-xyz, w);
}
//======================================================================================================
Quaternion Quaternion::Normalize() const
{
	return *this / Magnitude();
}
//======================================================================================================
Quaternion Quaternion::Slerp(const Quaternion& second, float delta) const
{
	float dot = Dot(second);
	dot = max(min(dot, 1), -1);
	float angle = acosf(dot) * delta;
	Quaternion relative = (second - *this * dot).Normalize();
	return (*this * cosf(angle)) + (relative * sinf(angle));
}

#endif