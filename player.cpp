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
	center_position = { 100.0f,100.0f };
	
	body_one.init({ center_position.x - 30,center_position.y - 30 }, left);
	body_two.init({ center_position.x - 30,center_position.y - 30 }, up);
	body_three.init({ center_position.x + 30,center_position.y - 30 }, right);
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
		center_position.x += 2.0f;
	}
	if (key[KEY_INPUT_A] == true)
	{
		center_position.x -= 2.0f;
	}

	//ジャンプ
	if (key[KEY_INPUT_SPACE] && IsJump == false)
	{
		IsJump = true;
		fallspeed = 4.2f;
	}

	if (IsJump == true)
	{
		center_position.y -= fallspeed;
		fallspeed -= 0.1f;

		if (center_position.y >= floorHeight - 30)
		{
			center_position.y = floorHeight - 30;
			IsJump = false;
		}
	}

	//落下判定
	if (center_position.y < floorHeight - 31 && IsJump == false)
	{
		center_position.y += fallspeed;

		if (fallspeed <= 5.0)
		{
			fallspeed += 0.1f;
		}
	}

	//折る・開く
	//左
	if (key[KEY_INPUT_LEFT] == true && oldkey[KEY_INPUT_LEFT] == false && body_one.ease.ismove == false)
	{
		body_one.ease.addtime = 0.1f;
		body_one.ease.maxtime = 1.5f;
		body_one.ease.timerate = 0.0f;

		//折る
		if (body_one.Isfold == false && body_one.Isopen == true && body_one.Isaction == false)
		{
			body_one.ease.ismove = true;
			body_one.Isfold = true;
			body_one.Isopen = false;
			body_one.Isaction = true;

			if (body_two.Isfold == true)
			{
				body_two.overlap++;
			}
			if (body_three.Isfold == true)
			{
				body_three.overlap++;
			}
		}

		//開く
		if (body_one.Isfold == true && body_one.Isopen == false && body_one.Isaction == false && body_one.overlap == 0)
		{
			body_one.ease.ismove = true;
			body_one.Isfold = false;
			body_one.Isopen = true;
			body_one.Isaction = true;

			if (body_two.Isfold == true)
			{
				body_two.overlap--;
			}
			if (body_three.Isfold == true)
			{
				body_three.overlap--;
			}
		}
	}
	//上
	if (key[KEY_INPUT_UP] == true && oldkey[KEY_INPUT_UP] == false && body_two.ease.ismove == false)
	{
		body_two.ease.addtime = 0.1f;
		body_two.ease.maxtime = 1.5f;
		body_two.ease.timerate = 0.0f;

		//折る
		if (body_two.Isfold == false && body_two.Isopen == true && body_two.Isaction == false)
		{
			body_two.ease.ismove = true;
			body_two.Isfold = true;
			body_two.Isopen = false;
			body_two.Isaction = true;

			if (body_one.Isfold == true)
			{
				body_one.overlap++;
			}
			if (body_three.Isfold == true)
			{
				body_three.overlap++;
			}
		}

		//開く
		if (body_two.Isfold == true && body_two.Isopen == false && body_two.Isaction == false && body_two.overlap == 0)
		{
			body_two.ease.ismove = true;
			body_two.Isfold = false;
			body_two.Isopen = true;
			body_two.Isaction = true;

			if (body_one.Isfold == true)
			{
				body_one.overlap--;
			}
			if (body_three.Isfold == true)
			{
				body_three.overlap--;
			}
		}
	}
	//右
	if (key[KEY_INPUT_RIGHT] == true && oldkey[KEY_INPUT_RIGHT] == false && body_three.ease.ismove == false)
	{
		body_three.ease.addtime = 0.1f;
		body_three.ease.maxtime = 1.5f;
		body_three.ease.timerate = 0.0f;

		//折る
		if (body_three.Isfold == false && body_three.Isopen == true && body_three.Isaction == false)
		{
			body_three.ease.ismove = true;
			body_three.Isfold = true;
			body_three.Isopen = false;
			body_three.Isaction = true;

			if (body_one.Isfold == true)
			{
				body_one.overlap++;
			}
			if (body_two.Isfold == true)
			{
				body_two.overlap++;
			}
		}

		//開く
		if (body_three.Isfold == true && body_three.Isopen == false && body_three.Isaction == false && body_three.overlap == 0)
		{
			body_three.ease.ismove = true;
			body_three.Isfold = false;
			body_three.Isopen = true;
			body_three.Isaction = true;

			if (body_one.Isfold == true)
			{
				body_one.overlap--;
			}
			if (body_two.Isfold == true)
			{
				body_two.overlap--;
			}
		}
	}

	body_one.update({ center_position.x - 30,center_position.y - 30 });
	body_two.update({ center_position.x - 30,center_position.y - 30 });
	body_three.update({ center_position.x + 30,center_position.y - 30 });
}

void Player::Draw()
{
	DrawBox(center_position.x - 30, center_position.y - 30, center_position.x + 30, center_position.y + 30, GetColor(255, 0, 0), true);

#pragma region 重なっている枚数ごとに順番に描画
	if (body_one.overlap == 2)
	{
		body_one.draw();
	}
	if (body_two.overlap == 2)
	{
		body_two.draw();
	}
	if (body_three.overlap == 2)
	{
		body_three.draw();
	}

	if (body_one.overlap == 1)
	{
		body_one.draw();
	}
	if (body_two.overlap == 1)
	{
		body_two.draw();
	}
	if (body_three.overlap == 1)
	{
		body_three.draw();
	}

	if (body_one.overlap == 0)
	{
		body_one.draw();
	}
	if (body_two.overlap == 0)
	{
		body_two.draw();
	}
	if (body_three.overlap == 0)
	{
		body_three.draw();
	}
#pragma endregion 重なっている枚数ごとに順番に描画

	DrawFormatString(0, 0, GetColor(255, 255, 255), "AD:左右移動");
	DrawFormatString(0, 20, GetColor(255, 255, 255), "SPACE:ジャンプ");
	DrawFormatString(0, 40, GetColor(255, 255, 255), "←↑→:折る・開く");
	DrawFormatString(0, 60, GetColor(255, 255, 255), "重なっている枚数\n左：%d\n上：%d\n右：%d", body_one.overlap, body_two.overlap, body_three.overlap);
}

void body::init(Vector2 position, bodytype number)
{
	bodystartpos = position;

	bodypat = number;

	if (bodypat == left)
	{
		bodyendpos = { bodystartpos.x - 60,bodystartpos.y + 60 };
	}
	else if (bodypat == up)
	{
		bodyendpos = { bodystartpos.x + 60,bodystartpos.y - 60 };
	}
	else if (bodypat == right)
	{
		bodyendpos = { bodystartpos.x + 60,bodystartpos.y + 60 };
	}
	else if (bodypat == down)
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

			if (bodypat == left)
			{
				bodyendpos.x = ease.easeout(bodystartpos.x + 60, bodystartpos.x - 60, ease.timerate);
			}
			else if (bodypat == up)
			{
				bodyendpos.y = ease.easeout(bodystartpos.y + 60, bodystartpos.y - 60, ease.timerate);
			}
			else if (bodypat == right)
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
			if (bodypat == left)
			{
				bodyendpos = { bodystartpos.x - 60,bodystartpos.y + 60 };
			}
			else if (bodypat == up)
			{
				bodyendpos = { bodystartpos.x + 60,bodystartpos.y - 60 };
			}
			else if (bodypat == right)
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

			if (bodypat == left)
			{
				bodyendpos.x = ease.easeout(bodystartpos.x - 60, bodystartpos.x + 60, ease.timerate);
			}
			else if (bodypat == up)
			{
				bodyendpos.y = ease.easeout(bodystartpos.y - 60, bodystartpos.y + 60, ease.timerate);
			}
			else if (bodypat == right)
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
			if (bodypat == left)
			{
				bodyendpos = { bodystartpos.x + 60,bodystartpos.y + 60 };
			}
			else if (bodypat == up)
			{
				bodyendpos = { bodystartpos.x + 60,bodystartpos.y + 60 };
			}
			else if (bodypat == right)
			{
				bodyendpos = { bodystartpos.x - 60,bodystartpos.y + 60 };
			}
		}
	}

}

void body::draw()
{
	if (bodypat == left)
	{
		DrawBox(bodystartpos.x, bodystartpos.y, bodyendpos.x, bodyendpos.y, GetColor(255, 255, 0), true);
	}
	else if (bodypat == up)
	{
		DrawBox(bodystartpos.x, bodystartpos.y, bodyendpos.x, bodyendpos.y, GetColor(0, 255, 0), true);
	}
	else if (bodypat == right)
	{
		DrawBox(bodystartpos.x, bodystartpos.y, bodyendpos.x, bodyendpos.y, GetColor(255, 0, 255), true);
	}
	else if (bodypat == down)
	{
		DrawBox(bodystartpos.x, bodystartpos.y, bodyendpos.x, bodyendpos.y, GetColor(0, 255, 255), true);
	}
}
