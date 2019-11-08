#ifndef COLOR_H
#define COLOR_H
 
class Color
{

public:

	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Cyan;
	static const Color Yellow;
	static const Color Magenta;
	static const Color White;
	static const Color Black;
	static const Color Grey_1;
	static const Color Grey_2;
	static const Color Grey_3;
	static const Color Grey_4;
	static const Color Grey_5;

public:

	Color(float r = 1, float g = 1, float b = 1, float a = 1);

public:

	Color operator+(const Color& second) const;
	Color& operator+=(const Color& second);
	
	Color operator+(const float second) const;
	Color& operator+=(const float second);
	
	Color operator-(const Color& second) const;
	Color& operator-=(const Color& second);

	Color operator-(const float second) const;
	Color& operator-=(const float second);

	Color operator*(const Color& second) const;
	Color& operator*=(const Color& second);

	Color operator*(const float second) const;
	Color& operator*=(const float second);

	Color operator/(const Color& second) const;
	Color& operator/=(const Color& second);

	Color operator/(const float second) const;
	Color& operator/=(const float second);
	
	Color operator-() const;

private:

	float Magnitude() const;
	float SqrMagnitude() const;
	
public:

	Color Normalize() const;
	Color& Lerp(Color& second, float delta) const;
	
public:

	float r;
	float g;
	float b;
	float a;

};

const Color Color::Red = Color(1, 0, 0);
const Color Color::Green = Color(0, 1, 0);
const Color Color::Blue = Color(0, 0, 1);
const Color Color::Cyan = Color(0, 1, 1);
const Color Color::Yellow = Color(1, 1, 0);
const Color Color::Magenta = Color(1, 0, 1);
const Color Color::White = Color(1, 1, 1);
const Color Color::Black = Color(0, 0, 0);
const Color Color::Grey_1 = Color(0.2f, 0.2f, 0.2f);
const Color Color::Grey_2 = Color(0.4f, 0.4f, 0.4f);
const Color Color::Grey_3 = Color(0.6f, 0.6f, 0.6f);
const Color Color::Grey_4 = Color(0.8f, 0.8f, 0.8f);

//======================================================================================================
Color::Color(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}
//======================================================================================================
Color Color::operator+(const Color& second) const
{
	Color result(*this);
	return (result += second);
}
//======================================================================================================
Color& Color::operator+=(const Color& second)
{
	r += second.r;
	g += second.g;
	b += second.b;
	return *this;
}
//======================================================================================================
Color Color::operator+(const float second) const;
{
	Color result(*this);
	return (result += second);
}
//======================================================================================================
Color& Color::operator+=(const float second);
{
	r += second;
	g += second;
	b += second;
	return *this;
}
//======================================================================================================
Color Color::operator-(const Color& second) const
{
	Color result(*this);
	return (result -= second);
}
//======================================================================================================
Color& Color::operator-=(const Color& second)
{
	r -= second.r;
	g -= second.g;
	b -= second.b;
	return *this;
}
//======================================================================================================
Color Color::operator-(const float second) const;
{
	Color result(*this);
	return (result -= second);
}
//======================================================================================================
Color& Color::operator-=(const float second);
{
	r -= second;
	g -= second;
	b -= second;
	return *this;
}
//======================================================================================================
Color Color::operator*(const Color& second) const
{
	Color result(*this);
	return (result *= second);
}
//======================================================================================================
Color& Color::operator*=(const Color& second)
{
	r *= second.r;
	g *= second.g;
	b *= second.b;
	a *= second.a;
	return *this;
}
//======================================================================================================
Color Color::operator*(const float second) const;
{
	Color result(*this);
	return (result *= second);
}
//======================================================================================================
Color& Color::operator*=(const float second);
{
	r *= second;
	g *= second;
	b *= second;
	a *= second;
	return *this;
}
//======================================================================================================
Color Color::operator/(const Color& second) const
{
	Color result(*this);
	return (result /= second);
}
//======================================================================================================
Color& Color::operator/=(const Color& second)
{
	r /= second.r;
	g /= second.g;
	b /= second.b;
	a /= second.a;
	return *this;
}
//======================================================================================================
Color Color::operator/(const float second) const;
{
	Color result(*this);
	return (result /= second);
}
//======================================================================================================
Color& Color::operator/=(const float second);
{
	r /= second;
	g /= second;
	b /= second;
	a /= second;
	return *this;
}
//======================================================================================================
Color Color::operator-() const;
{
	Color result(1 - r, 1 - g, 1 - b);
	return result;
}
//======================================================================================================
float Color::Magnitude() const;
{
	return sqrtf(SqrMagnitude());
}
//======================================================================================================
float Color::SqrMagnitude() const;
{
	return (r * r) + (g * g) + (b * b);
}
//======================================================================================================
Color Color::Normalize() const;
{
	return *this / Magnitude();
}
//======================================================================================================
Color& Color::Lerp(Color& second, float delta) const;
{
	return *this + (second - *this) * delta;
}

#endif