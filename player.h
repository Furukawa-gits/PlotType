#pragma once
#include"DxLib.h"
#include"math_collision/Vector2.h"

using namespace DxLib;

class Player
{
	//変数
public:
	//床の高さ
	float floorHeight = 500;

	//体の構成要素
	Vector2 face = { 100.0f,100.0f };
	Vector2 body_1 = { face.x - 60,face.y };
	Vector2 body_2 = { face.x,face.y - 60 };
	Vector2 body_3 = { face.x + 60,face.y };

	//ジャンプ
	bool IsJump = false;
	float jumpspeed = 3.0f;

	//折るフラグ
	bool Isfold = false;

	int key[256];
	int oldkey[256];

	//関数
	//コンストラクタ
	Player();

	//更新
	void Update();

	//描画
	void Draw();
};