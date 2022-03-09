#pragma once
#include"Primitive.h"
#include"Vector3.h"


class Colision
{
public:

	static bool testSpSp(const Sphere& sp1, const Sphere& sp2);

	static bool testSpBox(const Sphere& sp, const Box& box);

	static bool testSpCp(const Sphere& sp, const Capsule& cp);

	static bool testCpCp(const Capsule& cp1, const Capsule& cp2);

	static float sqDisSegSeg(const Vector3& p1, const Vector3& q1, const Vector3& p2, const Vector3& q2);

	static float clamp(float x, float low, float high)
	{
		x = (x < low) ? low : x;
		x = (x > high) ? high : x;
		return x;
	}
};