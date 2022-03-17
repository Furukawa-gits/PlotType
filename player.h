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

enum bodytype
{
	left,
	up,
	right,
	down
};

struct body
{
	//有効化フラグ
	bool Isactivate = false;

	//顔から見た体の位置
	int body_type;

	//体の座標
	Vector2 bodystartpos;

	//端の座標
	Vector2 bodyendpos;

	//スライドの開始座標
	Vector2 slidestartpos;

	//折る・開くフラグ
	bool Isfold = false;
	bool Isopen = true;

	//スライドフラグ・スライドする方向
	bool Isslide = false;
	int slidepat = 0;

	//折る・開く・スライドをしている途中かどうか
	bool Isaction = false;

	//スライドする距離
	int slide_dis;

	//上に重なっている噛みの数
	int overlap = 0;

	//本体からどれだけ離れているか(左右専用)
	int bodydistance = 1;

	//イージング
	easing ease;

	//体の色
	int bodycolor = GetColor(255, 255, 255);

	void init(Vector2 position, bodytype number);
	void update(Vector2 center);
	/// <summary>
	/// 体のスライドのセットアップ
	/// </summary>
	/// <param name="slidepat">スライドする向き(左上:-1 右下:1)</param>
	/// <param name="move_dis">スライドする距離(隣:1 顔をまたぐ:2)</param>
	void setslide(int slidepat,int move_dis);
	void draw();
};

class Player
{
	//変数
public:
	//床の高さ
	float floorHeight = 500;

	//体の構成要素
	Vector2 center_position = { 100.0f,100.0f };

	//体(折るほう)
	body body_one;
	body body_two;
	body body_three;

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

	//キーのトリガー判定
	bool returnkeytrigger(int keycode);
};