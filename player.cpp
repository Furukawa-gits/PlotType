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

		if (face.y >= floorHeight - 30)
		{
			face.y = floorHeight - 30;
			IsJump = false;
		}
	}

	//落下判定
	if (face.y < floorHeight - 31 && IsJump == false)
	{
		face.y += fallspeed;

		if (fallspeed <= 5.0)
		{
			fallspeed += 0.1f;
		}
	}

	//折る・開く
	//左
	if (key[KEY_INPUT_LEFT] == true && oldkey[KEY_INPUT_LEFT] == false && body_left.ease.ismove == false)
	{
		body_left.ease.addtime = 0.1f;
		body_left.ease.maxtime = 1.5f;
		body_left.ease.timerate = 0.0f;

		if (body_left.Isfold == false && body_left.Isopen == true && body_left.Isaction == false)
		{
			body_left.ease.ismove = true;
			body_left.Isfold = true;
			body_left.Isopen = false;
			body_left.Isaction = true;
		}

		if (body_left.Isfold == true && body_left.Isopen == false && body_left.Isaction == false)
		{
			body_left.ease.ismove = true;
			body_left.Isfold = false;
			body_left.Isopen = true;
			body_left.Isaction = true;
		}
	}
	//上
	if (key[KEY_INPUT_UP] == true && oldkey[KEY_INPUT_UP] == false && body_up.ease.ismove == false)
	{
		body_up.ease.addtime = 0.1f;
		body_up.ease.maxtime = 1.5f;
		body_up.ease.timerate = 0.0f;

		if (body_up.Isfold == false && body_up.Isopen == true && body_up.Isaction == false)
		{
			body_up.ease.ismove = true;
			body_up.Isfold = true;
			body_up.Isopen = false;
			body_up.Isaction = true;
		}

		if (body_up.Isfold == true && body_up.Isopen == false && body_up.Isaction == false)
		{
			body_up.ease.ismove = true;
			body_up.Isfold = false;
			body_up.Isopen = true;
			body_up.Isaction = true;
		}
	}
	//右
	if (key[KEY_INPUT_RIGHT] == true && oldkey[KEY_INPUT_RIGHT] == false && body_right.ease.ismove == false)
	{
		body_right.ease.addtime = 0.1f;
		body_right.ease.maxtime = 1.5f;
		body_right.ease.timerate = 0.0f;

		if (body_right.Isfold == false && body_right.Isopen == true && body_right.Isaction == false)
		{
			body_right.ease.ismove = true;
			body_right.Isfold = true;
			body_right.Isopen = false;
			body_right.Isaction = true;
		}

		if (body_right.Isfold == true && body_right.Isopen == false && body_right.Isaction == false)
		{
			body_right.ease.ismove = true;
			body_right.Isfold = false;
			body_right.Isopen = true;
			body_right.Isaction = true;
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
		if (ease.ismove == true)
		{
			ease.addtime += ease.maxtime / 60.0f;
			ease.timerate = min(ease.addtime / ease.maxtime, 1.0f);

			if (bodypat == 0)
			{
				bodyendpos.x = ease.easeout(bodystartpos.x + 60, bodystartpos.x - 60, ease.timerate);
			}
			else if (bodypat == 1)
			{
				bodyendpos.y = ease.easeout(bodystartpos.y + 60, bodystartpos.y - 60, ease.timerate);
			}
			else if (bodypat == 2)
			{
				bodyendpos.x = ease.easeout(bodystartpos.x - 60, bodystartpos.x + 60, ease.timerate);
			}

			if (ease.timerate >= 1.0f)
			{
				ease.ismove = false;
				Isaction = false;
			}
		}
		else
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
		if (ease.ismove == true)
		{
			ease.addtime += ease.maxtime / 60.0f;
			ease.timerate = min(ease.addtime / ease.maxtime, 1.0f);

			if (bodypat == 0)
			{
				bodyendpos.x = ease.easeout(bodystartpos.x - 60, bodystartpos.x + 60, ease.timerate);
			}
			else if (bodypat == 1)
			{
				bodyendpos.y = ease.easeout(bodystartpos.y - 60, bodystartpos.y + 60, ease.timerate);
			}
			else if (bodypat == 2)
			{
				bodyendpos.x = ease.easeout(bodystartpos.x + 60, bodystartpos.x - 60, ease.timerate);
			}

			if (ease.timerate >= 1.0f)
			{
				ease.ismove = false;
				Isaction = false;
			}
		}
		else
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
	if (bodypat == 0)
	{
		DrawBox(bodystartpos.x, bodystartpos.y, bodyendpos.x, bodyendpos.y, GetColor(255, 255, 0), true);
	}
	else if (bodypat == 1)
	{
		DrawBox(bodystartpos.x, bodystartpos.y, bodyendpos.x, bodyendpos.y, GetColor(0, 255, 0), true);
	}
	else if (bodypat == 2)
	{
		DrawBox(bodystartpos.x, bodystartpos.y, bodyendpos.x, bodyendpos.y, GetColor(255, 0, 255), true);
	}
}
