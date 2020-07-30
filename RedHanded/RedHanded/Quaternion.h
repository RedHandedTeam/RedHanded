#ifndef QUATERNION_H
#define QUATERNION_H

#include <math.h>

#include "Vector3.h"

#define PI 3.14159265359f

class Quaternion
{

public:

	//=============================================================
	static const Quaternion Identity() { return Quaternion(); };

public:

	//=============================================================
	inline Quaternion(float x = 0.f, float y = 0.f, float z = 0.f, float w = 1.f)
	{
		this->xyz = Vector3<float>(x, y, z);
		this->w = w;
	}
	inline Quaternion(Vector3<float> axis, float angle)
	{
		float radian = angle / 180.f * PI;
		float sinThetaOverTwo = sinf(radian / 2.f);
		float cosThetaOverTwo = cosf(radian / 2.f);

		w = cosThetaOverTwo;
		xyz.x = axis.x * sinThetaOverTwo;
		xyz.y = axis.y * sinThetaOverTwo;
		xyz.z = axis.z * sinThetaOverTwo;
	}
	
private:

	//=============================================================
	inline Quaternion operator+(const Quaternion& second) const
	{
		Quaternion result(*this);
		return (result += second);
	}
	inline Quaternion& operator+=(const Quaternion& second)
	{
		xyz += second.xyz;
		w += second.w;
		return *this;
	}
	//=============================================================
	inline Quaternion operator-(const Quaternion& second) const
	{
		Quaternion result(*this);
		return (result -= second);
	}
	inline Quaternion& operator-=(const Quaternion& second)
	{
		xyz -= second.xyz;
		w -= second.w;
		return *this;
	}
	//=============================================================
	inline Quaternion operator*(const float& second) const
	{
		return Quaternion(xyz * second, w * second);
	}
	inline Quaternion operator/(const float& second) const
	{
		return Quaternion(xyz / second, w / second);
	}

public:

	//=============================================================
	inline Quaternion operator*(const Quaternion& second) const
	{
		Quaternion result(*this);
		return (result *= second);
	}
	inline Quaternion& operator*=(const Quaternion& second)
	{
		Vector3<float> imaginary = second.xyz * w + xyz * second.w + xyz.Cross(second.xyz);
		w = w * second.w - xyz.Dot(second.xyz);
		xyz = imaginary;
		return *this;
	}
	//=============================================================
	inline Quaternion operator/(const Quaternion& second) const
	{
		Quaternion result(*this);
		return (result /= second);
	}
	inline Quaternion& operator/=(const Quaternion& second)
	{
		return *this *= second.Inverse();
	}
	//=============================================================
	inline Vector3<float> operator*(const Vector3<float>& second) const
	{
		Vector3<float> cross = xyz.Cross(second) * 2.f;
		return second + cross * w + xyz.Cross(cross);
	}

private:

	//=============================================================
	inline float Magnitude() const
	{
		return sqrtf(SqrMagnitude());
	}
	inline float SqrMagnitude() const
	{
		return xyz.SqrMagnitude() + (w * w);
	}

public:

	//=============================================================
	inline float Angle(const Quaternion& second) const
	{
		return 2.f * acosf((Inverse() * second).w) * (180.f / PI);
	}
	//=============================================================
	inline float Dot(const Quaternion& second) const
	{
		return xyz.Dot(second.xyz) + (w * second.w);
	}
	//=============================================================
	inline Quaternion Inverse() const
	{
		return  Conjugate() / SqrMagnitude();
	}
	inline Quaternion Conjugate() const
	{
		return Quaternion(-xyz, w);
	}
	inline Quaternion Normalize() const
	{
		return *this / Magnitude();
	}
	//=============================================================
	inline Quaternion Slerp(const Quaternion& second, float delta) const
	{
		float dot = Dot(second);
		dot = fmax(fmin(dot, 1.f), -1.f);
		float angle = acosf(dot) * delta;
		Quaternion relative = (second - *this * dot).Normalize();
		return (*this * cosf(angle)) + (relative * sinf(angle));
	}

public:

	Vector3<float> xyz;
	float w;
};

#endif