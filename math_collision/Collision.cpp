#include"Collision.h"
#include"Primitive.h"
#include"Vector3.h"

bool Colision::testSpSp(const Sphere& sp1, const Sphere& sp2)
{
	Vector3 vec = sp1.position - sp2.position;

	float sqLen = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;

	float r = sp1.radius + sp2.radius;

	return sqLen < r* r;
}

bool Colision::testSpBox(const Sphere& sp, const Box& box)
{
	float sqDis = 0.0f;
	float pos;

	//xé≤
	pos = sp.position.x;
	if (pos < box.minPosition.x)
	{
		sqDis += (box.minPosition.x - pos) * (box.minPosition.x - pos);
	}
	else if (pos > box.maxPosition.x)
	{
		sqDis += (box.maxPosition.x - pos) * (box.maxPosition.x - pos);
	}

	//yé≤
	pos = sp.position.y;
	if (pos < box.minPosition.y)
	{
		sqDis += (box.minPosition.y - pos) * (box.minPosition.y - pos);
	}
	else if (pos > box.maxPosition.y)
	{
		sqDis += (box.maxPosition.y - pos) * (box.maxPosition.y - pos);
	}

	//zé≤
	pos = sp.position.z;
	if (pos < box.minPosition.z)
	{
		sqDis += (box.minPosition.z - pos) * (box.minPosition.z - pos);
	}
	else if (pos > box.maxPosition.z)
	{
		sqDis += (box.maxPosition.z - pos) * (box.maxPosition.z - pos);
	}

	return sqDis < sp.radius* sp.radius;
}

bool Colision::testSpCp(const Sphere& sp, const Capsule& cp)
{
	Vector3 vstoe = cp.endPosition - cp.startPosition;

	Vector3 n = vstoe;
	n.nomalize();

	float t = (sp.position - cp.startPosition).dot(n);

	Vector3 vPsPn = n * t;
	Vector3 posPn = cp.startPosition + vPsPn;

	float lengthRat = t / vstoe.length();

	float distance;
	if (lengthRat < 0.0f)
	{
		distance = (sp.position - cp.startPosition).length() - cp.radius;
	}
	else if (lengthRat <= 1.0f)
	{
		distance = (sp.position - posPn).length() - cp.radius;
	}
	else
	{
		distance = (sp.position - cp.endPosition).length() - cp.radius;
	}

	return distance < sp.radius;
}

bool Colision::testCpCp(const Capsule& cp1, const Capsule& cp2)
{
	float sqDis = sqDisSegSeg(cp1.startPosition, cp1.endPosition,
		cp2.startPosition, cp2.endPosition);

	float r = cp1.radius + cp2.radius;

	return sqDis < r* r;
}

float Colision::sqDisSegSeg(const Vector3& p1, const Vector3& q1, const Vector3& p2, const Vector3& q2)
{
	Vector3 d1 = q1 - p1;
	Vector3 d2 = q2 - p2;

	Vector3 r = p1 - p2;

	float a = d1.dot(d1);
	float b = d1.dot(d2);
	float e = d2.dot(d2);

	float c = d1.dot(r);
	float f = d2.dot(r);

	float s = 0.0f;
	float t = 0.0f;

	float denom = a * e - b * b;

	if (denom != 0.0f)
	{
		s = (b * f - c * e) / denom;
		s = clamp(s, 0.0f, 1.0f);
	}
	else
	{
		s = 0.0f;
	}

	t = (b * s + f) / e;

	if (t < 0.0f)
	{
		t = 0.0f;
		s = clamp(-c / a, 0.0f, 1.0f);
	}
	else if (t > 1.0f)
	{
		s = clamp((b - c) / a, 0.0f, 1.0f);
		t = 1.0f;
	}

	Vector3 c1 = p1 + d1 * s;
	Vector3 c2 = p2 + d2 * t;

	return (c1 - c2).dot(c1 - c2);
}
