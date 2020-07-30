#ifndef COLOR_H
#define COLOR_H
 
#include <math.h>

class Color
{

public:

	//=============================================================
	static const Color Red()	 { return Color(1.f, 0.f, 0.f); };
	static const Color Green()	 { return Color(0.f, 1.f, 0.f); };
	static const Color Blue()	 { return Color(0.f, 0.f, 1.f); };
	//=============================================================
	static const Color Cyan()	 { return Color(0.f, 1.f, 1.f); };
	static const Color Yellow()  { return Color(1.f, 1.f, 0.f); };
	static const Color Magenta() { return Color(1.f, 0.f, 1.f); };
	static const Color White()	 { return Color(1.f, 1.f, 1.f); };
	static const Color Black()	 { return Color(0.f, 0.f, 0.f); };
	//=============================================================
	static const Color Grey_1()	 { return Color(0.2f, 0.2f, 0.2f); };
	static const Color Grey_2()	 { return Color(0.4f, 0.4f, 0.4f); };
	static const Color Grey_3()	 { return Color(0.6f, 0.6f, 0.6f); };
	static const Color Grey_4()	 { return Color(0.8f, 0.8f, 0.8f); };

public:

	//=============================================================
	inline Color(float r = 1.f, float g = 1.f, float b = 1.f, float a = 1.f) 
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

public:

	//=============================================================
	inline Color operator+(const Color& second) const
	{
		Color result(*this);
		return (result += second);
	}
	inline Color& operator+=(const Color& second)
	{
		Color result(*this);
		return (result += second);
	}
	//=============================================================
	inline Color operator+(const float second) const
	{
		Color result(*this);
		return (result += second);
	}
	inline Color& operator+=(const float second)
	{
		r += second;
		g += second;
		b += second;
		return *this;
	}
	//=============================================================
	inline Color operator-(const Color& second) const
	{
		Color result(*this);
		return (result -= second);
	}
	inline Color& operator-=(const Color& second)
	{
		r -= second.r;
		g -= second.g;
		b -= second.b;
		return *this;
	}
	//=============================================================
	inline Color operator-(const float second) const
	{
		Color result(*this);
		return (result -= second);
	}
	inline Color& operator-=(const float second)
	{
		r -= second;
		g -= second;
		b -= second;
		return *this;
	}
	//=============================================================
	inline Color operator*(const Color& second) const
	{
		Color result(*this);
		return (result *= second);
	}
	inline Color& operator*=(const Color& second)
	{
		r *= second.r;
		g *= second.g;
		b *= second.b;
		a *= second.a;
		return *this;
	}
	//=============================================================
	inline Color operator*(const float second) const
	{
		Color result(*this);
		return (result *= second);
	}
	inline Color& operator*=(const float second)
	{
		r *= second;
		g *= second;
		b *= second;
		a *= second;
		return *this;
	}
	//=============================================================
	inline Color operator/(const Color& second) const
	{
		Color result(*this);
		return (result /= second);
	}
	inline Color& operator/=(const Color& second)
	{
		r /= second.r;
		g /= second.g;
		b /= second.b;
		a /= second.a;
		return *this;
	}
	//=============================================================
	inline Color operator/(const float second) const
	{
		Color result(*this);
		return (result /= second);
	}
	inline Color& operator/=(const float second)
	{
		r /= second;
		g /= second;
		b /= second;
		a /= second;
		return *this;
	}
	//=============================================================
	inline Color operator-() const
	{
		Color result(1 - r, 1 - g, 1 - b);
		return result;
	}

private:

	//=============================================================
	inline float Magnitude() const
	{
		return sqrtf(SqrMagnitude());
	}
	inline float SqrMagnitude() const
	{
		return (r * r) + (g * g) + (b * b);
	}
	
public:

	//=============================================================
	inline Color Normalize() const
	{
		return *this / Magnitude();
	}
	//=============================================================
	inline Color Lerp(const Color& second, float delta) const
	{
		return *this + (second - *this) * delta;
	}
	
public:

	float r;
	float g;
	float b;
	float a;
};

#endif