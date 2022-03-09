#include"Vector3.h"
#include<cmath>

Vector3::Vector3() :
	Vector3(0, 0, 0)
{
}

Vector3::Vector3(float x, float y, float z) :
	VECTOR{ x,y,z }
{
}

float Vector3::length() const
{
	return sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
}

Vector3& Vector3::nomalize()
{
	float len = length();

	if (len != 0)
	{
		return *this /= len;
	}

	return *this;
}

float Vector3::dot(const Vector3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

Vector3 Vector3::cross(const Vector3& v) const
{
	return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

Vector3 Vector3::operator+() const
{
	return *this;
}

Vector3 Vector3::operator-() const
{
	return Vector3(-1 * x, -1 * y, -1 * z);
}

Vector3& Vector3::operator+=(const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector3& Vector3::operator*=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

Vector3& Vector3::operator/=(float s)
{
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

const Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	return temp += (v2);
}

const Vector3 operator-(const Vector3& v1, const Vector3& v2)
{
	Vector3 temp(v1);
	return temp -= (v2);
}

const Vector3 operator*(const Vector3& v, float s)
{
	Vector3 temp(v);
	return temp *= s;
}

const Vector3 operator*(float s, const Vector3& v)
{
	return v * s;
}

const Vector3 operator/(const Vector3& v, float s)
{
	Vector3 temp(v);
	return temp /= s;
}

const Vector3 lerp(const Vector3& start, const Vector3& end, const float t)
{
	return start * (1.0f - t) + end * t;
}

const Vector3 easeIn(const Vector3& start, const Vector3& end, float t)
{
	Vector3 c = end - start;

	return c * t * t * t + start;
}

const Vector3 easeOut(const Vector3& start, const Vector3& end, float t)
{
	Vector3 c = end - start;
	//t /= 5.0f;

	t = t - 1;

	return c * (t * t * t + 1) + start;
}

const Vector3 easeInOut(const Vector3& start, const Vector3& end, float t)
{
	Vector3 c = end - start;
	t *= 2;

	if (t < 1)
	{
		return c / 2.0f * t * t * t + start;
	}
	else
	{
		t = t - 2;
		return c / 2.0f * (t * t * t + 2.0f) + start;
	}
}
