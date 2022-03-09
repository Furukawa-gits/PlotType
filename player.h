#pragma once
#include"DxLib.h"
#include"math_collision/Vector2.h"

using namespace DxLib;

class Player
{
	//�ϐ�
public:
	//���̍���
	float floorHeight = 500;

	//�̂̍\���v�f
	Vector2 face = { 100.0f,100.0f };
	Vector2 body_1 = { face.x - 60,face.y };
	Vector2 body_2 = { face.x,face.y - 60 };
	Vector2 body_3 = { face.x + 60,face.y };

	//�W�����v
	bool IsJump = false;
	float jumpspeed = 3.0f;

	//�܂�t���O
	bool Isfold = false;

	int key[256];
	int oldkey[256];

	//�֐�
	//�R���X�g���N�^
	Player();

	//�X�V
	void Update();

	//�`��
	void Draw();
};