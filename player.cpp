#include"player.h"

player::player()
{
}

void player::Update()
{
	
}

void player::Draw()
{
	DrawBox(face.x - 30, face.y - 30, face.x + 30, face.y + 30, GetColor(255, 0, 0), true);
	DrawBox(body_1.x - 30, body_1.y - 30, body_1.x + 30, body_1.y + 30, GetColor(255, 0, 0), true);
	DrawBox(body_2.x - 30, body_2.y - 30, body_2.x + 30, body_2.y + 30, GetColor(255, 0, 0), true);
	DrawBox(body_3.x - 30, body_3.y - 30, body_3.x + 30, body_3.y + 30, GetColor(255, 0, 0), true);
}
