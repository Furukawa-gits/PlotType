#include"Primitive.h"
#include"Vector3.h"
#include<DxLib.h>

Sphere::Sphere(const Vector3& position, float radius, unsigned color)
	:position(position), radius(radius), color(color)
{
}

void Sphere::draw()
{
	const unsigned white = GetColor(255, 255, 255);
	DrawSphere3D(position, radius, 32, color, white, TRUE);
}

void Sphere::drawinfo(int x, int y, unsigned color)
{
	DrawFormatString(x, y, color, "Sphere (%6.1f,%6.1f,%6.1f),%6.1f", position.x, position.y, position.z, radius);
}

Box::Box(const Vector3& minPosition, const Vector3& maxPosition, unsigned color)
	:minPosition(minPosition), maxPosition(maxPosition), color(color)
{
}

void Box::draw()
{
	const unsigned white = GetColor(255, 255, 255);
	DrawCube3D(minPosition, maxPosition, color, white, TRUE);
}

void Box::drawinfo(int x, int y, unsigned color)
{
	DrawFormatString(x, y, color, "Box (%6.1f,%6.1f,%6.1f)-(%6.1f,%6.1f,%6.1f)",
		minPosition.x, minPosition.y, minPosition.z, maxPosition.x, maxPosition.y, maxPosition.z);
}

Capsule::Capsule(const Vector3& start, const Vector3& end, float radius, unsigned color)
	:startPosition(start), endPosition(end), color(color), radius(radius)
{
}

void Capsule::draw()
{
	const unsigned white = GetColor(255, 255, 255);

	DrawCapsule3D(startPosition, endPosition, radius, 32, color, white, TRUE);
}

void Capsule::drawInfo(int x, int y, unsigned color)
{
	DrawFormatString(x, y, color, "Capsule (%6.1f,%6.1f,%6.1f)-(%6.1f,%6.1f,%6.1f),%6.1f",
		startPosition.x, startPosition.y, startPosition.z,
		endPosition.x, endPosition.y, endPosition.z, radius);
}
