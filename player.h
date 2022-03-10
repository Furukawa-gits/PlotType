#pragma once
#include"DxLib.h"
#include"math_collision/Vector2.h"

using namespace DxLib;

struct easing
{
	float maxtime = 2.0f;
	float timerate = 0.0f;
	float addtime = 0.1f;

	bool ismove = false;

	float easeout(const float start, const float end, const float time)
	{
		float position = time * (2 - time);
		return start * (1.0f - position) + end * position;
	}
};

struct body
{
	int bodypat;

	//�̂̍��W
	Vector2 bodystartpos;
	
	//�[�̍��W
	Vector2 bodyendpos;

	//�܂�E�J���t���O
	bool Isfold = false;
	bool Isopen = true;

	//�C�[�W���O
	easing ease;

	void init(Vector2 position, int number);
	void update(Vector2 bodystartpos);
	void draw();
};

class Player
{
	//�ϐ�
public:
	//���̍���
	float floorHeight = 500;

	//�̂̍\���v�f
	Vector2 face = { 100.0f,100.0f };

	//��(�܂�ق�)
	body body_left;
	body body_up;
	body body_right;

	//�W�����v
	bool IsJump = false;
	float jumpspeed = 3.0f;
	float fallspeed = 3.0f;
	bool IsLand = false;

	char key[256];
	char oldkey[256];

	//�֐�
	//�R���X�g���N�^
	Player();

	//������
	void init();

	//�X�V
	void Update();

	//�`��
	void Draw();
};