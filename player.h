#pragma once
#include"DxLib.h"
#include"math_collision/Vector2.h"

using namespace DxLib;

class player
{
	//�ϐ�
public:
	Vector2 face = { 100.0f,100.0f };
	Vector2 body_1 = { face.x - 60,face.y };
	Vector2 body_2 = { face.x,face.y - 60 };
	Vector2 body_3 = { face.x + 60,face.y };

	int* key[256];
	int* oldkey[256];

	//�֐�
	//�R���X�g���N�^
	player();

	//�X�V
	void Update();

	//�`��
	void Draw();
};