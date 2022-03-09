#pragma once
#include"Vector3.h"

struct Sphere
{
	Vector3 position;
	float radius;

	unsigned color;

	Sphere(const Vector3& position, float radius, unsigned color);

	void draw();
	void drawinfo(int x, int y, unsigned color);
};


struct Box
{
	Vector3 minPosition;
	Vector3 maxPosition;

	unsigned color;

	Box(const Vector3& minPosition, const Vector3& maxPosition, unsigned color);

	void draw();
	void drawinfo(int x, int y, unsigned color);
};

//カプセル
struct Capsule
{
	Vector3 startPosition;
	Vector3 endPosition;
	float radius;

	unsigned color;

	//コンストラクタ
	Capsule(const Vector3& start, const Vector3& end, float radius, unsigned color);

	void draw();
	void drawInfo(int x, int y, unsigned color);
};