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
	center_position = { 300.0f,100.0f };

	body_one.init(center_position, left);
	body_one.bodycolor = GetColor(255, 255, 0);

	body_two.init(center_position, up);
	body_two.bodycolor = GetColor(0, 255, 0);

	body_three.init(center_position, right);
	body_three.bodycolor = GetColor(255, 0, 255);

	bodysetup(true, left, true, up, true, right);
}

void Player::bodysetup(bool one, int one_type, bool two, int two_type, bool three, int three_type)
{
	if (one == true)
	{
		body_one.Isactivate = true;
		body_one.body_type = one_type;
	}

	if (two == true)
	{
		body_two.Isactivate = true;
		body_two.body_type = two_type;
	}

	if (three == true)
	{
		body_three.Isactivate = true;
		body_three.body_type = three_type;
	}

	body_one.setactivate(center_position);
	body_two.setactivate(center_position);
	body_three.setactivate(center_position);
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
	if (key[KEY_INPUT_W] && IsJump == false)
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

	//折る
	//左
	if (returnkeytrigger(KEY_INPUT_LEFT) && body_one.ease.ismove == false && body_one.body_type == left)
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
			if (body_three.Isfold == true || body_one.bodydistance == 2)
			{
				body_three.overlap++;
			}
		}
	}
	//上
	if (returnkeytrigger(KEY_INPUT_UP) && body_two.ease.ismove == false && body_two.body_type == up)
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
	}
	//右
	if (returnkeytrigger(KEY_INPUT_RIGHT) && body_three.ease.ismove == false && body_three.body_type == right)
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

			if (body_one.Isfold == true || body_three.bodydistance == 2)
			{
				body_one.overlap++;
			}
			if (body_two.Isfold == true)
			{
				body_two.overlap++;
			}
		}


	}
	//下
	if (returnkeytrigger(KEY_INPUT_DOWN) && body_two.ease.ismove == false && body_two.body_type == down)
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
	}

	//開く
	if (returnkeytrigger(KEY_INPUT_SPACE))
	{
		//左
		if (body_one.Isfold == true && body_one.Isopen == false && body_one.Isaction == false && body_one.overlap == 0)
		{
			body_one.ease.addtime = 0.1f;
			body_one.ease.maxtime = 1.5f;
			body_one.ease.timerate = 0.0f;

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
		//上
		else if (body_two.Isfold == true && body_two.Isopen == false && body_two.Isaction == false && body_two.overlap == 0)
		{
			body_two.ease.addtime = 0.1f;
			body_two.ease.maxtime = 1.5f;
			body_two.ease.timerate = 0.0f;

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
		//右
		else if (body_three.Isfold == true && body_three.Isopen == false && body_three.Isaction == false && body_three.overlap == 0)
		{
			body_three.ease.addtime = 0.1f;
			body_three.ease.maxtime = 1.5f;
			body_three.ease.timerate = 0.0f;

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

	//体のスライド
	//左
	if (returnkeytrigger(KEY_INPUT_Z) && body_one.bodydistance < 2 && body_one.Isaction == false)
	{
		if (body_one.body_type == right)
		{
			if (body_three.Isopen == true)
			{
				body_one.setslide(-1, 2);
				body_three.bodydistance = 1;
				body_three.setslide(-1, 1);
			}
		}
		else if (body_one.bodydistance == 1)
		{
			body_one.bodydistance = 2;
			body_one.setslide(-1, 1);
			body_three.setslide(-1, 2);
		}
	}
	//右
	if (returnkeytrigger(KEY_INPUT_X) && body_three.bodydistance < 2 && body_three.Isaction == false)
	{
		if (body_three.body_type == left)
		{
			body_three.setslide(1, 2);
			body_one.bodydistance = 1;
			body_one.setslide(1, 1);
		}
		else if (body_three.bodydistance == 1)
		{
			body_three.bodydistance = 2;
			body_three.setslide(1, 1);
			body_one.setslide(1, 2);
		}
	}
	//上下
	if (returnkeytrigger(KEY_INPUT_C) && body_two.Isfold == false && body_two.Isaction == false)
	{
		if (body_two.body_type == up)
		{
			body_two.setslide(1, 2);
		}
		else
		{
			body_two.setslide(-1, 2);
		}
	}

	//体のリセット
	if (returnkeytrigger(KEY_INPUT_R))
	{
		bodysetup(true, left, true, up, true, right);
	}

	if (body_one.Isactivate == true)
	{
		body_one.update(center_position);
	}
	if (body_two.Isactivate == true)
	{
		body_two.update(center_position);
	}
	if (body_three.Isactivate == true)
	{
		body_three.update(center_position);
	}
}

void Player::Draw()
{
	if (body_one.Isslide == false && body_two.Isslide == false && body_three.Isslide == false)
	{
		DrawBox(center_position.x - 30, center_position.y - 30, center_position.x + 30, center_position.y + 30, GetColor(255, 0, 0), true);
	}

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

	if (body_one.Isslide == true || body_two.Isslide == true || body_three.Isslide == true)
	{
		if (body_three.slide_dis == 2)
		{
			DrawBox(center_position.x - 30, center_position.y - 30, body_one.bodyendpos.x, body_one.bodyendpos.y, body_three.bodycolor, true);
		}
		if (body_one.slide_dis == 2)
		{
			DrawBox(center_position.x + 30, center_position.y - 30, body_three.bodystartpos.x, body_three.bodyendpos.y, body_one.bodycolor, true);
		}

		DrawBox(center_position.x - 30, center_position.y - 30, center_position.x + 30, center_position.y + 30, GetColor(255, 0, 0), true);
	}

	DrawFormatString(0, 0, GetColor(255, 255, 255), "AD:左右移動");
	DrawFormatString(0, 20, GetColor(255, 255, 255), "SPACE:ジャンプ");
	DrawFormatString(0, 40, GetColor(255, 255, 255), "←↑→:折る・開く");
	DrawFormatString(0, 60, GetColor(255, 255, 255), "重なっている枚数\n左：%d\n上：%d\n右：%d", body_one.overlap, body_two.overlap, body_three.overlap);
	DrawFormatString(0, 140, GetColor(255, 255, 255), "左右スライド：Z or X\n上下スライド：C or V");
	DrawFormatString(0, 180, GetColor(255, 255, 255), "%f   %f   %f", body_one.bodystartpos.x, body_one.bodyendpos.x, center_position.x);
}

bool Player::returnkeytrigger(int keycode)
{
	if (oldkey[keycode] == false && key[keycode] == true)
	{
		return true;
	}
	return false;
}

void body::init(Vector2 position, bodytype number)
{
	body_type = number;

	if (body_type == left)
	{
		bodystartpos = { position.x - 90,position.y - 30 };
	}
	else if (body_type == up)
	{
		bodystartpos = { position.x - 30,position.y - 90 };
	}
	else if (body_type == right)
	{
		bodystartpos = { position.x + 30,position.y - 30 };
	}
	else if (body_type == down)
	{
		bodystartpos = { position.x - 30,position.y + 30 };
	}

	bodyendpos = { bodystartpos.x + 60,bodystartpos.y + 60 };

	Isopen = true;
	Isfold = false;
}

void body::setactivate(Vector2 center)
{
	if (Isactivate == true)
	{
		Isfold = false;
		Isopen = true;
		Isslide = false;
		bodydistance = 1;

		if (body_type == left)
		{
			bodystartpos = { center.x - 90,center.y - 30 };
		}
		else if (body_type == right)
		{
			bodystartpos = { center.x + 30,center.y - 30 };
		}
		else if (body_type == up)
		{
			bodystartpos = { center.x - 30,center.y - 90 };
		}
		else if (body_type == down)
		{
			bodystartpos = { center.x - 30,center.y + 30 };
		}

		bodyendpos = { bodystartpos.x + 60,bodystartpos.y + 60 };
	}
}

void body::update(Vector2 center)
{
	//開いているとき
	if (Isfold == false && Isopen == true)
	{
		if (ease.ismove == true && Isslide == false)
		{
			ease.addtime += ease.maxtime / 60.0f;
			ease.timerate = min(ease.addtime / ease.maxtime, 1.0f);

			if (body_type == left)
			{
				bodyendpos = { center.x - (30 + 60 * (bodydistance - 1)),center.y + 30 };
				bodystartpos.x = ease.easeout(bodyendpos.x + 60, bodyendpos.x - 60, ease.timerate);
				bodystartpos.y = bodyendpos.y - 60;
			}
			if (body_type == up)
			{
				bodyendpos = { center.x + 30,center.y - 30 };
				bodystartpos.y = ease.easeout(bodyendpos.y + 60, bodyendpos.y - 60, ease.timerate);
				bodystartpos.x = bodyendpos.x - 60;
			}
			if (body_type == right)
			{
				bodystartpos = { center.x + (30 + 60 * (bodydistance - 1)),center.y - 30 };
				bodyendpos.x = ease.easeout(bodystartpos.x - 60, bodystartpos.x + 60, ease.timerate);
				bodyendpos.y = bodystartpos.y + 60;
			}
			if (body_type == down)
			{
				bodystartpos = { center.x + 30,center.y + 30 };
				bodyendpos.y = ease.easeout(bodystartpos.y - 60, bodystartpos.y + 60, ease.timerate);
				bodyendpos.x = bodystartpos.x - 60;
			}

			if (ease.timerate >= 1.0f)
			{
				ease.ismove = false;
				Isaction = false;
			}
		}
		else if (Isaction == false)
		{
			if (body_type == left)
			{
				bodystartpos = { center.x - (30 + bodydistance * 60),center.y - 30 };
			}
			if (body_type == up)
			{
				bodystartpos = { center.x - 30,center.y - 90 };
			}
			if (body_type == right)
			{
				bodystartpos = { center.x + (30 + (bodydistance - 1) * 60),center.y - 30 };
			}
			if (body_type == down)
			{
				bodystartpos = { center.x - 30,center.y + 30 };
			}

			bodyendpos = { bodystartpos.x + 60,bodystartpos.y + 60 };
		}
	}
	//折るとき
	else if (Isfold == true && Isopen == false)
	{
		if (ease.ismove == true && Isslide == false)
		{
			ease.addtime += ease.maxtime / 60.0f;
			ease.timerate = min(ease.addtime / ease.maxtime, 1.0f);

			if (body_type == left)
			{
				bodyendpos = { center.x - (30 + 60 * (bodydistance - 1)),center.y + 30 };
				bodystartpos.x = ease.easeout(bodyendpos.x - 60, bodyendpos.x + 60, ease.timerate);
				bodystartpos.y = bodyendpos.y - 60;
			}
			if (body_type == up)
			{
				bodyendpos = { center.x + 30,center.y - 30 };
				bodystartpos.y = ease.easeout(bodyendpos.y - 60, bodyendpos.y + 60, ease.timerate);
				bodystartpos.x = bodyendpos.x - 60;
			}
			if (body_type == right)
			{
				bodystartpos = { center.x + (30 + 60 * (bodydistance - 1)),center.y - 30 };
				bodyendpos.x = ease.easeout(bodystartpos.x + 60, bodystartpos.x - 60, ease.timerate);
				bodyendpos.y = bodystartpos.y + 60;
			}
			if (body_type == down)
			{
				bodystartpos = { center.x - 30,center.y + 30 };
				bodyendpos.y = ease.easeout(bodystartpos.y + 60, bodystartpos.y - 60, ease.timerate);
				bodyendpos.x = bodystartpos.x + 60;
			}

			if (ease.timerate >= 1.0f)
			{
				ease.ismove = false;
				Isaction = false;
			}
		}
		else
		{
			if (body_type == left)
			{
				bodyendpos = { center.x - (30 + 60 * (bodydistance - 1)),center.y + 30 };
				bodystartpos = { bodyendpos.x + 60, bodyendpos.y - 60 };
			}
			else if (body_type == up)
			{
				bodystartpos = { center.x - 30,center.y + 30 };
				bodyendpos = { bodystartpos.x + 60,bodystartpos.y - 60 };
			}
			else if (body_type == right)
			{
				bodystartpos = { center.x + (30 + 60 * (bodydistance - 1)),center.y - 30 };
				bodyendpos = { bodystartpos.x - 60,bodystartpos.y + 60 };
			}
			else if (body_type == down)
			{
				bodystartpos = { center.x - 30,center.y + 30 };
				bodyendpos = { bodystartpos.x + 60,bodystartpos.y - 60 };
			}
		}
	}

	//体のスライド
	//顔を挟むとなり移動
	if (Isslide == true && ease.ismove == true && slide_dis == 2)
	{
		ease.addtime += ease.maxtime / 60.0f;
		ease.timerate = min(ease.addtime / ease.maxtime, 1.0f);

		if (body_type == left)
		{
			bodystartpos = { ease.easeout(center.x - 90, center.x + 30, ease.timerate), center.y - 30 };
			bodyendpos = { bodystartpos.x + (-120 * Isfold + 60), center.y + 30 };
		}
		else if (body_type == right)
		{
			bodystartpos = { ease.easeout(center.x + 30, center.x - 90, ease.timerate), center.y - 30 };
			bodyendpos = { bodystartpos.x + (-120 * Isfold + 60), center.y + 30 };
		}
		else if (body_type == up)
		{
			bodystartpos = { center.x - 30, ease.easeout(center.y - 90, center.y + 30, ease.timerate) };
			bodyendpos = { center.x + 30, bodystartpos.y + (-120 * Isfold + 60) };
		}
		else if (body_type == down)
		{
			bodystartpos = { center.x - 30, ease.easeout(center.y + 30, center.y - 90, ease.timerate) };
			bodyendpos = { center.x + 30, bodystartpos.y + (-120 * Isfold + 60) };
		}

		if (ease.timerate >= 1.0f)
		{
			ease.ismove = false;
			Isaction = false;
			Isslide = false;

			if (body_type == left)
			{
				body_type = right;
			}
			else if (body_type == right)
			{
				body_type = left;
			}
			else if (body_type == up)
			{
				body_type = down;
			}
			else if (body_type == down)
			{
				body_type = up;
			}
		}
	}

	//顔を挟まないとなり移動(左右のみ)
	if (Isslide == true && ease.ismove == true && slide_dis == 1)
	{
		ease.addtime += ease.maxtime / 60.0f;
		ease.timerate = min(ease.addtime / ease.maxtime, 1.0f);

		if (body_type == left)
		{
			if (slidepat == -1)
			{
				bodystartpos = { ease.easeout(center.x - 90, center.x - 150, ease.timerate), center.y - 30 };
			}
			else
			{
				bodystartpos = { ease.easeout(center.x - 150, center.x - 90, ease.timerate), center.y - 30 };
			}
		}
		else if (body_type == right)
		{
			if (slidepat == -1)
			{
				bodystartpos = { ease.easeout(center.x + 90, center.x + 30, ease.timerate), center.y - 30 };
			}
			else
			{
				bodystartpos = { ease.easeout(center.x + 30, center.x + 90, ease.timerate), center.y - 30 };
			}
		}

		bodyendpos = { bodystartpos.x + (-120 * Isfold + 60), center.y + 30 };

		if (ease.timerate >= 1.0f)
		{
			ease.ismove = false;
			Isaction = false;
			Isslide = false;
		}
	}
}

void body::setslide(int slidepat, int move_dis)
{
	Isaction = true;
	Isslide = true;
	ease.ismove = true;

	ease.addtime = 0.1f;
	ease.maxtime = 1.5f;
	ease.timerate = 0.0f;

	this->slidepat = slidepat;

	slide_dis = move_dis;
}

void body::draw()
{
	if (Isactivate == true)
	{
		DrawBox(bodystartpos.x, bodystartpos.y, bodyendpos.x, bodyendpos.y, bodycolor, true);
	}
}
