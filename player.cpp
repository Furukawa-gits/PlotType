#include"player.h"

Player::Player()
{
	for (int i = 0; i < 256; i++)
	{
		oldkey[i] = key[i] = 0;
	}
}

void Player::init()
{
	face = { 100.0f,100.0f };
	body_left.init({ face.x - 30,face.y - 30 }, 0);
	body_up.init({ face.x - 30,face.y - 30 }, 1);
	body_right.init({ face.x + 30,face.y - 30 }, 2);
}

void Player::Update()
{
	for (int i = 0; i < 256; i++)
	{
		oldkey[i] = key[i];
	}

	GetHitKeyStateAll(key);

	//左右移動
	if (key[KEY_INPUT_D] == true)
	{
		face.x += 2.0f;
	}
	if (key[KEY_INPUT_A] == true)
	{
		face.x -= 2.0f;
	}

	//ジャンプ
	if (key[KEY_INPUT_SPACE] && IsJump == false)
	{
		IsJump = true;
		fallspeed = 4.2f;
	}

	if (IsJump == true)
	{
		face.y -= fallspeed;
		fallspeed -= 0.1f;

		if (face.y >= 500 - 30)
		{
			face.y = 500 - 30;
			IsJump = false;
		}
	}

	//落下判定
	if (face.y < 500 - 31 && IsJump == false)
	{
		face.y += fallspeed;

		if (fallspeed <= 5.0)
		{
			fallspeed += 0.1f;
		}
	}

	//折る・開く
	if (key[KEY_INPUT_LEFT] == true)
	{
		if (body_left.Isfold == false && body_left.Isopen == true)
		{

		}
	}

	body_left.update({ face.x - 30,face.y - 30 });
	body_up.update({ face.x - 30,face.y - 30 });
	body_right.update({ face.x + 30,face.y - 30 });
}

void Player::Draw()
{
	DrawBox(face.x - 30, face.y - 30, face.x + 30, face.y + 30, GetColor(255, 0, 0), true);

	body_left.draw();
	body_up.draw();
	body_right.draw();

	DrawFormatString(0, 0, GetColor(255, 255, 255), "AD:左右移動");
	DrawFormatString(0, 20, GetColor(255, 255, 255), "SPACE:ジャンプ");
	DrawFormatString(0, 40, GetColor(255, 255, 255), "←↑→:折る・開く");
}

void body::init(Vector2 position, int number)
{
	bodystartpos = position;

	bodypat = number;

	if (bodypat == 0)
	{
		bodyendpos = { bodystartpos.x - 60,bodystartpos.y + 60 };
	}
	else if (bodypat == 1)
	{
		bodyendpos = { bodystartpos.x + 60,bodystartpos.y - 60 };
	}
	else if (bodypat == 2)
	{
		bodyendpos = { bodystartpos.x + 60,bodystartpos.y + 60 };
	}

	Isopen = true;
	Isfold = false;
}

void body::update(Vector2 bodystartpos)
{
	this->bodystartpos = bodystartpos;

	if (Isfold == false && Isopen == true)
	{
		if (ease.ismove == false)
		{
			if (bodypat == 0)
			{
				bodyendpos = { bodystartpos.x - 60,bodystartpos.y + 60 };
			}
			else if (bodypat == 1)
			{
				bodyendpos = { bodystartpos.x + 60,bodystartpos.y - 60 };
			}
			else if (bodypat == 2)
			{
				bodyendpos = { bodystartpos.x + 60,bodystartpos.y + 60 };
			}
		}
	}
	else if (Isfold == true && Isopen == false)
	{
		if (ease.ismove == false)
		{
			if (bodypat == 0)
			{
				bodyendpos = { bodystartpos.x + 60,bodystartpos.y + 60 };
			}
			else if (bodypat == 1)
			{
				bodyendpos = { bodystartpos.x + 60,bodystartpos.y + 60 };
			}
			else if (bodypat == 2)
			{
				bodyendpos = { bodystartpos.x - 60,bodystartpos.y + 60 };
			}
		}
	}

}

void body::draw()
{
	DrawBox(bodystartpos.x, bodystartpos.y, bodyendpos.x, bodyendpos.y, GetColor(255, 255, 0), true);
}
