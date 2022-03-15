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

	body_one.init(center_position, left);
	body_two.init(center_position, down);
	body_three.init(center_position, right);
}

void Player::Update()
{
	for (int i = 0; i < 256; i++)
	{
		oldkey[i] = key[i];
	}

	GetHitKeyStateAll(key);

	//���E�ړ�
	if (key[KEY_INPUT_D] == true)
	{
		center_position.x += 2.0f;
	}
	if (key[KEY_INPUT_A] == true)
	{
		center_position.x -= 2.0f;
	}

	//�W�����v
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

	//��������
	if (center_position.y < floorHeight - 31 && IsJump == false)
	{
		center_position.y += fallspeed;

		if (fallspeed <= 5.0)
		{
			fallspeed += 0.1f;
		}
	}

	//�܂�E�J��
	//��
	if (returnkeytrigger(KEY_INPUT_LEFT) && body_one.ease.ismove == false && body_one.bodypat == left)
	{
		body_one.ease.addtime = 0.1f;
		body_one.ease.maxtime = 1.5f;
		body_one.ease.timerate = 0.0f;

		//�܂�
		if (body_one.Isfold == false && body_one.Isopen == true && body_one.Isaction_fold == false)
		{
			body_one.ease.ismove = true;
			body_one.Isfold = true;
			body_one.Isopen = false;
			body_one.Isaction_fold = true;

			if (body_two.Isfold == true)
			{
				body_two.overlap++;
			}
			if (body_three.Isfold == true)
			{
				body_three.overlap++;
			}
		}
	}
	//��
	if (returnkeytrigger(KEY_INPUT_UP) && body_two.ease.ismove == false && body_two.bodypat == up)
	{
		body_two.ease.addtime = 0.1f;
		body_two.ease.maxtime = 1.5f;
		body_two.ease.timerate = 0.0f;

		//�܂�
		if (body_two.Isfold == false && body_two.Isopen == true && body_two.Isaction_fold == false)
		{
			body_two.ease.ismove = true;
			body_two.Isfold = true;
			body_two.Isopen = false;
			body_two.Isaction_fold = true;

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
	//�E
	if (returnkeytrigger(KEY_INPUT_RIGHT) && body_three.ease.ismove == false && body_three.bodypat == right)
	{
		body_three.ease.addtime = 0.1f;
		body_three.ease.maxtime = 1.5f;
		body_three.ease.timerate = 0.0f;

		//�܂�
		if (body_three.Isfold == false && body_three.Isopen == true && body_three.Isaction_fold == false)
		{
			body_three.ease.ismove = true;
			body_three.Isfold = true;
			body_three.Isopen = false;
			body_three.Isaction_fold = true;

			if (body_one.Isfold == true)
			{
				body_one.overlap++;
			}
			if (body_two.Isfold == true)
			{
				body_two.overlap++;
			}
		}


	}
	//��
	if (returnkeytrigger(KEY_INPUT_DOWN) && body_two.ease.ismove == false && body_two.bodypat == down)
	{
		body_two.ease.addtime = 0.1f;
		body_two.ease.maxtime = 1.5f;
		body_two.ease.timerate = 0.0f;

		//�܂�
		if (body_two.Isfold == false && body_two.Isopen == true && body_two.Isaction_fold == false)
		{
			body_two.ease.ismove = true;
			body_two.Isfold = true;
			body_two.Isopen = false;
			body_two.Isaction_fold = true;

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

	//�J��
	if (key[KEY_INPUT_SPACE] == true && oldkey[KEY_INPUT_SPACE] == false)
	{
		//��
		if (body_one.Isfold == true && body_one.Isopen == false && body_one.Isaction_fold == false && body_one.overlap == 0)
		{
			body_one.ease.addtime = 0.1f;
			body_one.ease.maxtime = 1.5f;
			body_one.ease.timerate = 0.0f;

			body_one.ease.ismove = true;
			body_one.Isfold = false;
			body_one.Isopen = true;
			body_one.Isaction_fold = true;

			if (body_two.Isfold == true)
			{
				body_two.overlap--;
			}
			if (body_three.Isfold == true)
			{
				body_three.overlap--;
			}
		}
		//��
		else if (body_two.Isfold == true && body_two.Isopen == false && body_two.Isaction_fold == false && body_two.overlap == 0)
		{
			body_two.ease.addtime = 0.1f;
			body_two.ease.maxtime = 1.5f;
			body_two.ease.timerate = 0.0f;

			body_two.ease.ismove = true;
			body_two.Isfold = false;
			body_two.Isopen = true;
			body_two.Isaction_fold = true;

			if (body_one.Isfold == true)
			{
				body_one.overlap--;
			}
			if (body_three.Isfold == true)
			{
				body_three.overlap--;
			}
		}
		//�E
		else if (body_three.Isfold == true && body_three.Isopen == false && body_three.Isaction_fold == false && body_three.overlap == 0)
		{
			body_three.ease.addtime = 0.1f;
			body_three.ease.maxtime = 1.5f;
			body_three.ease.timerate = 0.0f;

			body_three.ease.ismove = true;
			body_three.Isfold = false;
			body_three.Isopen = true;
			body_three.Isaction_fold = true;

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


	//�̂̃X���C�h
	if (returnkeytrigger(KEY_INPUT_Z))
	{
		if (body_one.bodydistance < 2)
		{
			
		}
	}

	body_one.update(center_position);
	body_two.update(center_position);
	body_three.update(center_position);
}

void Player::Draw()
{
	DrawBox(center_position.x - 30, center_position.y - 30, center_position.x + 30, center_position.y + 30, GetColor(255, 0, 0), true);

#pragma region �d�Ȃ��Ă��閇�����Ƃɏ��Ԃɕ`��
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
#pragma endregion �d�Ȃ��Ă��閇�����Ƃɏ��Ԃɕ`��

	DrawFormatString(0, 0, GetColor(255, 255, 255), "AD:���E�ړ�");
	DrawFormatString(0, 20, GetColor(255, 255, 255), "SPACE:�W�����v");
	DrawFormatString(0, 40, GetColor(255, 255, 255), "������:�܂�E�J��");
	DrawFormatString(0, 60, GetColor(255, 255, 255), "�d�Ȃ��Ă��閇��\n���F%d\n��F%d\n�E�F%d", body_one.overlap, body_two.overlap, body_three.overlap);
	DrawFormatString(0, 140, GetColor(255, 255, 255), "���E�X���C�h�FZ or X\n�㉺�X���C�h�FC or V");
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
	bodypat = number;

	if (bodypat == left || bodypat == up)
	{
		bodystartpos = { position.x - 30,position.y - 30 };
	}
	else if (bodypat == right || bodypat == down)
	{
		bodystartpos = { position.x + 30,position.y + 30 };
	}

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
		bodyendpos = { bodystartpos.x + 60,bodystartpos.y - 60 };
	}
	else if (bodypat == down)
	{
		bodyendpos = { bodystartpos.x - 60,bodystartpos.y + 60 };
	}

	Isopen = true;
	Isfold = false;
}

void body::update(Vector2 center)
{
	if (bodypat == left || bodypat == up)
	{
		bodystartpos = { center.x - 30,center.y - 30 };
	}
	else if (bodypat == right || bodypat == down)
	{
		bodystartpos = { center.x + 30,center.y + 30 };
	}

	if (Isfold == false && Isopen == true)
	{
		if (ease.ismove == true)
		{
			ease.addtime += ease.maxtime / 60.0f;
			ease.timerate = min(ease.addtime / ease.maxtime, 1.0f);

			if (bodypat == left)
			{
				bodystartpos = { center.x - 30,center.y - 30 };
				bodyendpos.x = ease.easeout(bodystartpos.x + 60, bodystartpos.x - 60, ease.timerate);
				bodyendpos.y = bodystartpos.y + 60;
			}
			else if (bodypat == up)
			{
				bodystartpos = { center.x - 30,center.y - 30 };
				bodyendpos.y = ease.easeout(bodystartpos.y + 60, bodystartpos.y - 60, ease.timerate);
				bodyendpos.x = bodystartpos.x + 60;
			}
			else if (bodypat == right)
			{
				bodystartpos = { center.x + 30,center.y + 30 };
				bodyendpos.x = ease.easeout(bodystartpos.x - 60, bodystartpos.x + 60, ease.timerate);
				bodyendpos.y = bodystartpos.y - 60;
			}
			else if (bodypat == down)
			{
				bodystartpos = { center.x + 30,center.y + 30 };
				bodyendpos.y = ease.easeout(bodystartpos.y - 60, bodystartpos.y + 60, ease.timerate);
				bodyendpos.x = bodystartpos.x - 60;
			}

			if (ease.timerate >= 1.0f)
			{
				ease.ismove = false;
				Isaction_fold = false;
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
				bodyendpos = { bodystartpos.x + 60,bodystartpos.y - 60 };
			}
			else if (bodypat == down)
			{
				bodyendpos = { bodystartpos.x - 60,bodystartpos.y + 60 };
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
				bodystartpos = { center.x - 30,center.y - 30 };
				bodyendpos.x = ease.easeout(bodystartpos.x - 60, bodystartpos.x + 60, ease.timerate);
				bodyendpos.y = bodystartpos.y + 60;
			}
			else if (bodypat == up)
			{
				bodystartpos = { center.x - 30,center.y - 30 };
				bodyendpos.y = ease.easeout(bodystartpos.y - 60, bodystartpos.y + 60, ease.timerate);
				bodyendpos.x = bodystartpos.x + 60;
			}
			else if (bodypat == right)
			{
				bodystartpos = { center.x + 30,center.y + 30 };
				bodyendpos.x = ease.easeout(bodystartpos.x + 60, bodystartpos.x - 60, ease.timerate);
				bodyendpos.y = bodystartpos.y - 60;
			}
			else if (bodypat == down)
			{
				bodystartpos = { center.x + 30,center.y + 30 };
				bodyendpos.y = ease.easeout(bodystartpos.y + 60, bodystartpos.y - 60, ease.timerate);
				bodyendpos.x = bodystartpos.x - 60;
			}

			if (ease.timerate >= 1.0f)
			{
				ease.ismove = false;
				Isaction_fold = false;
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
				bodyendpos = { bodystartpos.x - 60,bodystartpos.y - 60 };
			}
			else if (bodypat == down)
			{
				bodyendpos = { bodystartpos.x - 60,bodystartpos.y - 60 };
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
