#pragma once
#include"DxLib.h"

class Vector3 :public VECTOR
{
public:
	//VECTOR�\���̂Œ�`
	//float x;	//x����
	//float y;	//y����
	//float z;	//z����

public:
	//�R���X�g���N�^
	Vector3();								//��x�N�g��
	Vector3(float x, float y, float z);		//�e�������w�肵������

	//�����o�֐�
	float length()const;					//����
	Vector3& nomalize();					//���K��
	float dot(const Vector3& v)const;		//����
	Vector3 cross(const Vector3& v)const;	//�O��


	//�P�����Z�q�I�[�o�[���[�h
	Vector3 operator+()const;
	Vector3 operator-()const;

	//������Z�q�I�[�o�[���[�h
	Vector3& operator+=(const Vector3& v);
	Vector3& operator-=(const Vector3& v);
	Vector3& operator*=(float s);
	Vector3& operator/=(float s);
};


//�񍀉��Z�q�I�[�o�[���[�h
//�e�p�^�[��������
const Vector3 operator+(const Vector3& v1, const Vector3& v2);
const Vector3 operator-(const Vector3& v1, const Vector3& v2);
const Vector3 operator*(const Vector3& v, float s);
const Vector3 operator*(float s, const Vector3& v);
const Vector3 operator/(const Vector3& v, float s);


//��Ԋ֐�
//���`���
const Vector3 lerp(const Vector3& start, const Vector3& end, const float t);

const Vector3 easeIn(const Vector3& start, const Vector3& end, float t);

const Vector3 easeOut(const Vector3& start, const Vector3& end, float t);

const Vector3 easeInOut(const Vector3& start, const Vector3& end, float t);

