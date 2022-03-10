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

	//体の座標
	Vector2 bodystartpos;
	
	//端の座標
	Vector2 bodyendpos;

	//折る・開くフラグ
	bool Isfold = false;
	bool Isopen = true;

	//イージング
	easing ease;

	void init(Vector2 position, int number);
	void update(Vector2 bodystartpos);
	void draw();
};

class Player
{
	//変数
public:
	//床の高さ
	float floorHeight = 500;

	//体の構成要素
	Vector2 face = { 100.0f,100.0f };

	//体(折るほう)
	body body_left;
	body body_up;
	body body_right;

	//ジャンプ
	bool IsJump = false;
	float jumpspeed = 3.0f;
	float fallspeed = 3.0f;
	bool IsLand = false;

	char key[256];
	char oldkey[256];

	//関数
	//コンストラクタ
	Player();

	//初期化
	void init();

	//更新
	void Update();

	//描画
	void Draw();
};