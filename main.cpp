#include"DxLib.h"
#include<cstdlib>
#include"math_collision/Vector2.h"
#include"math_collision/Vector3.h"
#include"math_collision/Matrix4.h"
#include"math_collision/Quaternion.h"
#include"math_collision/Primitive.h"
#include"math_collision/Collision.h"
#include"player.h"

using namespace DxLib;


int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	const int window_width = 1280;
	const int window_hight = 720;

	ChangeWindowMode(true);
	SetGraphMode(window_width, window_hight, 32);
	SetBackgroundColor(0, 0, 64);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowText("LE2A_17_�t���J��_�R�E�L");

	//�g�p�ϐ�
	Player player;
	
	player.init();

	//�Q�[�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		//�X�V

		player.Update();

		//��ʃN���A
		ClearDrawScreen();

		//�`��
		player.Draw();
		DrawLine(0, 500, 1280, 500, GetColor(0, 255, 0), 3);

		//�t���b�v
		ScreenFlip();
	}

	DxLib_End();

	return 0;
}