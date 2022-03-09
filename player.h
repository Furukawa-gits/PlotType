#pragma once
#include"DxLib.h"
#include"math_collision/Vector2.h"

using namespace DxLib;

class player
{
	//変数
public:
	Vector2 face = { 100.0f,100.0f };
	Vector2 body_1 = { face.x - 60,face.y };
	Vector2 body_2 = { face.x,face.y - 60 };
	Vector2 body_3 = { face.x + 60,face.y };

	int* key[256];
	int* oldkey[256];

	//関数
	//コンストラクタ
	player();

	//更新
	void Update();

	//描画
	void Draw();
};