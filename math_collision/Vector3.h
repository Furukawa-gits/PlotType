#pragma once
#include"DxLib.h"

class Vector3 :public VECTOR
{
public:
	//VECTOR構造体で定義
	//float x;	//x成分
	//float y;	//y成分
	//float z;	//z成分

public:
	//コンストラクタ
	Vector3();								//零ベクトル
	Vector3(float x, float y, float z);		//各成分を指定した生成

	//メンバ関数
	float length()const;					//長さ
	Vector3& nomalize();					//正規化
	float dot(const Vector3& v)const;		//内積
	Vector3 cross(const Vector3& v)const;	//外積


	//単項演算子オーバーロード
	Vector3 operator+()const;
	Vector3 operator-()const;

	//代入演算子オーバーロード
	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3& operator*=(float s);
	Vector3& operator/=(float s);
};


//二項演算子オーバーロード
//各パターンを準備
const Vector3 operator+(const Vector3& v1, const Vector3& v2);
const Vector3 operator-(const Vector3& v1, const Vector3& v2);
const Vector3 operator*(const Vector3& v, float s);
const Vector3 operator*(float s, const Vector3& v);
const Vector3 operator/(const Vector3& v, float s);


//補間関数
//線形補間
const Vector3 lerp(const Vector3& start, const Vector3& end, const float t);

const Vector3 easeIn(const Vector3& start, const Vector3& end, float t);

const Vector3 easeOut(const Vector3& start, const Vector3& end, float t);

const Vector3 easeInOut(const Vector3& start, const Vector3& end, float t);

