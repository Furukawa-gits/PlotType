#pragma once
class Vector2
{
public:
	float x;	//x成分
	float y;	//y成分

	//コンストラクタ
	Vector2();					//零ベクトルとして生成
	Vector2(float x, float y);	//x,yを指定して生成

	//メンバ関数
	float length() const;					//ベクトルのアガサを求める
	Vector2& normalize();					//正規化
	float dot(const Vector2& v) const;		//内積
	float cross(const Vector2& v) const;	//外積

	//単項演算子オーバーロード
	Vector2 operator+() const;
	Vector2 operator-() const;

	//代入演算子オーバーロード
	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(float s);
	Vector2& operator/=(float s);

};

//2項演算子オーバーロード
//いろんなパターンに対応するため、以下のように準備
const Vector2 operator+(const Vector2& v1, const Vector2& v2);
const Vector2 operator-(const Vector2& v1, const Vector2& v2);
const Vector2 operator*(const Vector2& v, float s);
const Vector2 operator*(float s, const Vector2& v);
const Vector2 operator/(const Vector2& v, float s);
