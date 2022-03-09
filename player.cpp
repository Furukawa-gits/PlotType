#include"player.h"

Player::Player()
{
	for (int i = 0; i < 256; i++)
	{
		oldkey[i] = key[i] = 0;
	}
}

void Player::Update()
{
	for (int i = 0; i < 256; i++)
	{
		oldkey[i] = key[i];
	}

	if (key[KEY_INPUT_D])
	{
		face.x += 2.0f;
	}
	if (key[KEY_INPUT_A])
	{
		face.x -= 2.0f;
	}

	if (key[KEY_INPUT_W] && !oldkey[KEY_INPUT_W])
	{
		IsJump = true;
		jumpspeed = 3.0f;
	}



	body_1 = { face.x - 60,face.y };
	body_2 = { face.x,face.y - 60 };
	body_3 = { face.x + 60,face.y };
}

void Player::Draw()
{
	DrawBox(face.x - 30, face.y - 30, face.x + 30, face.y + 30, GetColor(255, 0, 0), true);
	DrawBox(body_1.x - 30, body_1.y - 30, body_1.x + 30, body_1.y + 30, GetColor(255, 255, 0), true);
	DrawBox(body_2.x - 30, body_2.y - 30, body_2.x + 30, body_2.y + 30, GetColor(255, 255, 0), true);
	DrawBox(body_3.x - 30, body_3.y - 30, body_3.x + 30, body_3.y + 30, GetColor(255, 255, 0), true);
}
