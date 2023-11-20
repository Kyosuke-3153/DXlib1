#include "DxLib.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "�A�Z�b�g�K�[��";

// �E�B���h�E����
const int WIN_WIDTH = 608;

// �E�B���h�E�c��
const int WIN_HEIGHT = 640;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0xFF);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���

	int graphHandle[2];
	graphHandle[0] = LoadGraph("background3.png");
	graphHandle[1] = LoadGraph("Star.png");

	int graphHandle1[20];//�摜�p�ϐ�
	LoadDivGraph
	(
		"block.png",  //�ǂݍ��݂����摜�t�@�C���̖��O
		20,             //�O���t�B�b�N�̑���������
		4,             //�O���t�B�b�N�̉������ɑ΂��镪����
		5,             //�O���t�B�b�N�̏c�����ɑ΂��镪����
		32,            //�O���t�B�b�N�T�C�Y
		32,            //�O���t�B�b�N�T�C�Y
		graphHandle1    //�����ǂݍ��݂��ē����O���t�B�b�N�n���h����ۑ�����int�^�z��
	);

	int graphHandle2[6];//�摜�p�ϐ�
	LoadDivGraph
	(
		"charcter.png",  //�ǂݍ��݂����摜�t�@�C���̖��O
		6,             //�O���t�B�b�N�̑���������
		3,             //�O���t�B�b�N�̉������ɑ΂��镪����
		2,             //�O���t�B�b�N�̏c�����ɑ΂��镪����
		32,            //�O���t�B�b�N�T�C�Y
		32,            //�O���t�B�b�N�T�C�Y
		graphHandle2    //�����ǂݍ��݂��ē����O���t�B�b�N�n���h����ۑ�����int�^�z��
	);

	int graphHandle3[2];//�摜�p�ϐ�
	LoadDivGraph
	(
		"taitle.png",  //�ǂݍ��݂����摜�t�@�C���̖��O
		2,             //�O���t�B�b�N�̑���������
		2,             //�O���t�B�b�N�̉������ɑ΂��镪����
		1,             //�O���t�B�b�N�̏c�����ɑ΂��镪����
		608,            //�O���t�B�b�N�T�C�Y
		640,            //�O���t�B�b�N�T�C�Y
		graphHandle3    //�����ǂݍ��݂��ē����O���t�B�b�N�n���h����ۑ�����int�^�z��
	);

	int graphHandle4[3];//�摜�p�ϐ�
	LoadDivGraph
	(
		"crear.png",  //�ǂݍ��݂����摜�t�@�C���̖��O
		3,             //�O���t�B�b�N�̑���������
		3,             //�O���t�B�b�N�̉������ɑ΂��镪����
		1,             //�O���t�B�b�N�̏c�����ɑ΂��镪����
		608,            //�O���t�B�b�N�T�C�Y
		640,            //�O���t�B�b�N�T�C�Y
		graphHandle4    //�����ǂݍ��݂��ē����O���t�B�b�N�n���h����ۑ�����int�^�z��
	);

	int graphHandle5[4];//�摜�p�ϐ�
	LoadDivGraph
	(
		"rank.png",  //�ǂݍ��݂����摜�t�@�C���̖��O
		4,             //�O���t�B�b�N�̑���������
		4,             //�O���t�B�b�N�̉������ɑ΂��镪����
		1,             //�O���t�B�b�N�̏c�����ɑ΂��镪����
		128,            //�O���t�B�b�N�T�C�Y
		128,            //�O���t�B�b�N�T�C�Y
		graphHandle5    //�����ǂݍ��݂��ē����O���t�B�b�N�n���h����ۑ�����int�^�z��
	);

	int graphHandle6[10];//�摜�p�ϐ�
	LoadDivGraph
	(
		"number.png",  //�ǂݍ��݂����摜�t�@�C���̖��O
		10,             //�O���t�B�b�N�̑���������
		10,             //�O���t�B�b�N�̉������ɑ΂��镪����
		1,             //�O���t�B�b�N�̏c�����ɑ΂��镪����
		128,            //�O���t�B�b�N�T�C�Y
		128,            //�O���t�B�b�N�T�C�Y
		graphHandle6    //�����ǂݍ��݂��ē����O���t�B�b�N�n���h����ۑ�����int�^�z��
	);

	int graphHandle7[3];//�摜�p�ϐ�
	LoadDivGraph
	(
		"operation.png",  //�ǂݍ��݂����摜�t�@�C���̖��O
		3,             //�O���t�B�b�N�̑���������
		1,             //�O���t�B�b�N�̉������ɑ΂��镪����
		3,             //�O���t�B�b�N�̏c�����ɑ΂��镪����
		608,            //�O���t�B�b�N�T�C�Y
		160,            //�O���t�B�b�N�T�C�Y
		graphHandle7    //�����ǂݍ��݂��ē����O���t�B�b�N�n���h����ۑ�����int�^�z��
	);

	int graphHandle8[49];//�摜�p�ϐ�
	LoadDivGraph
	(
		"backgroundAA.png",  //�ǂݍ��݂����摜�t�@�C���̖��O
		49,             //�O���t�B�b�N�̑���������
		49,             //�O���t�B�b�N�̉������ɑ΂��镪����
		1,             //�O���t�B�b�N�̏c�����ɑ΂��镪����
		608,            //�O���t�B�b�N�T�C�Y
		1280,            //�O���t�B�b�N�T�C�Y
		graphHandle8    //�����ǂݍ��݂��ē����O���t�B�b�N�n���h����ۑ�����int�^�z��
	);

	int blockSize = 32;

	int map[60][19] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,7,8,8,8,8,8,8,8,9,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,6,0,0,6,0,0,6,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,7,8,8,8,8,8,8,8,8,8,8,8,8,8,9,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
		{7,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,9},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0},
		{0,0,0,0,0,6,0,0,0,0,0,0,0,6,0,0,0,0,0},
		{0,0,0,0,0,0,0,6,0,0,0,6,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,5,5,5,0,0,0,0,0,0,0,0},
		{0,0,0,5,0,0,5,0,0,0,0,0,5,0,0,5,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,5,5,0,0,0,0,0,0,0,0,0,5,5,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,5,0,0,0,0,0,5,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,5,5,0,0,0,0,0,5,5,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,5,5,0,0,0,0,0,5,5,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,2,4,0,0,0,0,0,1,2,4,0,0,0,0},
		{2,2,2,2,3,3,3,2,2,2,2,2,3,3,3,2,2,2,2}
	};

	//�}�b�v�̗�(��)�̐�
	int mapCountX = sizeof(map[0]) / sizeof(map[0][0]);

	//�}�b�v�̍s(�c)�̐�
	int mapCountY = sizeof(map) / sizeof(map[0]);

	//�}�b�v�̗�(��)�̐�
	enum MapInfo
	{
		NONE,
		BLOCK,     //1
		BLOCK1,    //2
		BLOCK2,    //3
		BLOCK3,    //4
		BLOCK4,    //5
		BLOCK5,    //6
		BLOCK6,    //7
		BLOCK7,    //8
		BLOCK8,    //9
		BLOCK9     //10
	};

	int bgm[3];
	bgm[0] = LoadSoundMem("MusMus-BGM-072.mp3");
	ChangeVolumeSoundMem(255 * 20 / 100, bgm[0]);
	bgm[1] = LoadSoundMem("bgm_maoudamashii_healing04.mp3");
	ChangeVolumeSoundMem(255 * 20 / 100, bgm[1]);
	bgm[2] = LoadSoundMem("MusMus-BGM-087.mp3");
	ChangeVolumeSoundMem(255 * 20 / 100, bgm[2]);

	int voice = LoadSoundMem("voice.wav");
	ChangeVolumeSoundMem(255 * 30 / 100, voice);

	// �Q�[�����[�v�Ŏg���ϐ��̐錾

	//�v���C���[�̈ʒu
	int playerX = 304;
	int playerY = 1872;

	//�v���C���[�̔��a
	int playerRadius = 16;

	//�v���C���[�̈ړ�
	int playerSpeed = 4;

	//�v���C���[�̊G�̓���
	int playerNumber = 0;

	//�W�����v
	int jumpFlag = 0;
	int jumpTimer = 0;

	float jumpPower = 0.0f;
	float landingSpeed = 0.0f;
	float upwardSpeed = 2.0f;

	//�d��
	float gravity = 1.0f;

	//�X�N���[��
	int scrollY = 1280;

	//�����蔻��ɕK�v

	//����̍�
	int upperLeftX = 0;
	int upperLeftY = 0;
	//����̏�
	int upperLeftX2 = 0;
	int upperLeftY2 = 0;
	//�E��̉E
	int upperRightX = 0;
	int upperRightY = 0;
	//�E��̏�
	int upperRightX2 = 0;
	int upperRightY2 = 0;
	//�E���̉E
	int bottomRightX = 0;
	int bottomRightY = 0;
	//�E���̉�
	int bottomRightX2 = 0;
	int bottomRightY2 = 0;
	//�����̍�
	int bottomLeftX = 0;
	int bottomLeftY = 0;
	//�����̉�
	int bottomLeftX2 = 0;
	int bottomLeftY2 = 0;

	//����
	int countTimer = 0;
	int timer = 0;
	int displayTimer = 0;
	int animationTimer = 0;

	//�V�[��
	int scene = 0;

	//�X�R�A
	int jumpCount = 0;
	int oneDigits = 0;
	int tenDigits = 0;

	//�G�𓮂���
	int titleScene = 0;
	int crearScene = 1;
	int playScene = 0;

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (1)
	{
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�

		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}

		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����

		if (scene == 0)
		{
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
			{
				if (titleScene == 0)
				{
					scene = 1;
				}
				if (titleScene == 1)
				{
					break;
				}
			}
			if (keys[KEY_INPUT_UP] == 1 && oldkeys[KEY_INPUT_UP] == 0)
			{
				if (titleScene == 0)
				{
					titleScene = 1;
				}
				else if (titleScene == 1)
				{
					titleScene = 0;
				}
			}
			if (keys[KEY_INPUT_DOWN] == 1 && oldkeys[KEY_INPUT_DOWN] == 0)
			{
				if (titleScene == 0)
				{
					titleScene = 1;
				}
				else if (titleScene == 1)
				{
					titleScene = 0;
				}
			}
			if (CheckSoundMem(bgm[1]) == 1)
			{
				StopSoundMem(bgm[1]);
			}
			if (CheckSoundMem(bgm[2]) == 1)
			{
				StopSoundMem(bgm[2]);
			}
			if (CheckSoundMem(bgm[0]) == 0)
			{
				PlaySoundMem(bgm[0], DX_PLAYTYPE_LOOP);
			}

			DrawGraph(0, 0, graphHandle3[titleScene], TRUE);
		}
		if (scene == 1)
		{
			if (CheckSoundMem(bgm[0]) == 1)
			{
				StopSoundMem(bgm[0]);
			}
			if (CheckSoundMem(bgm[1]) == 0)
			{
				PlaySoundMem(bgm[1], DX_PLAYTYPE_LOOP);
			}

			//����̍�
			upperLeftY = ((playerY - playerRadius) + 1) / blockSize;
			upperLeftX = ((playerX - playerRadius) - 1) / blockSize;
			//����̏�
			upperLeftY2 = ((playerY - playerRadius) - 1) / blockSize;
			upperLeftX2 = ((playerX - playerRadius) + 1) / blockSize;
			//�E��̉E
			upperRightY = ((playerY - playerRadius) + 1) / blockSize;
			upperRightX = ((playerX + playerRadius) + 1) / blockSize;
			//�E��̏�
			upperRightY2 = ((playerY - playerRadius) - 1) / blockSize;
			upperRightX2 = ((playerX + playerRadius) - 1) / blockSize;
			//�E���̉E
			bottomRightY = ((playerY + playerRadius) - 1) / blockSize;
			bottomRightX = ((playerX + playerRadius) + 1) / blockSize;
			//�E���̉�
			bottomRightY2 = ((playerY + playerRadius) + 1) / blockSize;
			bottomRightX2 = ((playerX + playerRadius) - 3) / blockSize;
			//�����̍�
			bottomLeftY = ((playerY + playerRadius) - 1) / blockSize;
			bottomLeftX = ((playerX - playerRadius) - 1) / blockSize;
			//�����̉�
			bottomLeftY2 = ((playerY + playerRadius) + 1) / blockSize;
			bottomLeftX2 = ((playerX - playerRadius) + 3) / blockSize;

			//�v���C���[�ړ�

			if (map[upperRightY][upperRightX] <= 0 || map[bottomRightY][bottomRightX] <= 0)
			{
				//�E�ړ�
				if (keys[KEY_INPUT_RIGHT] == 1 && playerX + playerRadius < 607 && displayTimer >= 270)
				{
					playerX += playerSpeed;

					if (playerNumber >= 2)
					{
						playerNumber = 0;
					}
					playerNumber++;
				}
				else if (keys[KEY_INPUT_RIGHT] == 0 && oldkeys[KEY_INPUT_RIGHT] == 1 && displayTimer >= 270)
				{
					playerNumber = 0;
				}
			}
			if (map[upperLeftY][upperLeftX] <= 0 || map[bottomLeftY][bottomLeftX] <= 0)
			{
				//���ړ�
				if (keys[KEY_INPUT_LEFT] == 1 && playerX - playerRadius >= 0 && displayTimer >= 270)
				{
					playerX -= playerSpeed;
					if (playerNumber <= 2)
					{
						playerNumber = 3;
					}
					if (playerNumber >= 5)
					{
						playerNumber = 3;
					}
					playerNumber++;
				}
				else if (keys[KEY_INPUT_LEFT] == 0 && oldkeys[KEY_INPUT_LEFT] == 1 && displayTimer >= 270)
				{
					playerNumber = 3;
				}
			}
			if (map[upperLeftY2][upperLeftX2] <= 0 && map[upperRightY2][upperRightX2] <= 0)
			{
				jumpTimer++;

				//�W�����v
				if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && map[bottomRightY2][bottomRightX2] >= 1  && jumpTimer > 5 && displayTimer >= 270 ||
					keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && map[bottomLeftY2][bottomLeftX2] >= 1 && jumpTimer > 5 && displayTimer >= 270)
				{
					jumpFlag = 1;
					jumpCount += 1;
					PlaySoundMem(voice, DX_PLAYTYPE_BACK);
				}
				if (jumpFlag == 1)
				{
					if (jumpPower > 16)
					{
						jumpPower = 0.0f;
						jumpFlag = 0;
					}
					if (jumpPower <= 16)
					{
						jumpPower += upwardSpeed;
					}
					playerY -= jumpPower;
				}
			}
			if (map[bottomRightY2][bottomRightX2] <= 0  && jumpFlag == 0 || map[bottomLeftY2][bottomLeftX2] <= 0 && jumpFlag == 0)
			{
				//�d��(����)
				if (landingSpeed <= 15.0f)
				{
					landingSpeed += gravity;
				}
				playerY += landingSpeed;
			}

			//�N���A
			if (map[upperLeftY][upperLeftX] >= 10 || map[bottomLeftY][bottomLeftX] >= 10 ||
				map[upperRightY][upperRightX] >= 10 || map[bottomRightY][bottomRightX] >= 10 ||
				map[upperLeftY2][upperLeftX2] >= 10 || map[upperRightY2][upperRightX2] >= 10 ||
				map[bottomRightY2][bottomRightX2] >= 10 || map[bottomLeftY2][bottomLeftX2] >= 10)
			{
				scene = 2;
			}

			//�Ԃ������Ƃ�

			//����̍�
			if (keys[KEY_INPUT_LEFT] == 1 && oldkeys[KEY_INPUT_LEFT] == 0 && map[upperLeftY][upperLeftX] >= 1)
			{
				playerX = (upperLeftX * blockSize) + blockSize + playerRadius;
			}
			//�����̍�
			if (keys[KEY_INPUT_LEFT] == 1 && oldkeys[KEY_INPUT_LEFT] == 0 && map[bottomLeftY][bottomLeftX] >= 1)
			{
				playerX = (bottomLeftX * blockSize) + blockSize + playerRadius;
			}
			//�E��̉E
			if (keys[KEY_INPUT_RIGHT] == 1 && oldkeys[KEY_INPUT_RIGHT] == 0 && map[upperRightY][upperRightX] >= 1)
			{
				playerX = (upperRightX * blockSize) - playerRadius;
			}
			//�E���̉E
			if (keys[KEY_INPUT_RIGHT] == 1 && oldkeys[KEY_INPUT_RIGHT] == 0 && map[bottomRightY][bottomRightX] >= 1)
			{
				playerX = (bottomRightX * blockSize) - playerRadius;
			}
			//����̏�
			if (jumpFlag == 1 && map[upperLeftY2][upperLeftX2] >= 1)
			{
				playerY = (upperLeftY2 * blockSize) + blockSize + playerRadius;
				jumpPower = 0.0f;
				jumpFlag = 0;
			}
			//�E��̏�
			if (jumpFlag == 1 && map[upperRightY2][upperRightX2] >= 1)
			{
				playerY = (upperRightY2 * blockSize) + blockSize + playerRadius;
				jumpPower = 0.0f;
				jumpFlag = 0;
			}
			//�E���̉�
			if (jumpFlag == 0 && map[bottomRightY2][bottomRightX2] >= 1)
			{
				landingSpeed = 0.0f;
				playerY = (bottomRightY2 * blockSize) - playerRadius;
			}
			//�����̉�
			if (jumpFlag == 0 && map[bottomLeftY2][bottomLeftX2] >= 1)
			{
				landingSpeed = 0.0f;
				playerY = (bottomLeftY2 * blockSize) - playerRadius;
			}

			//�X�N���[���͑S�̂̑傫��(�c��)���߂Ă���

			//�}�b�v�c1920(���ʏc640) �J�n�n�_320 �I���n�_1600(1920 - 320)
			if (playerY >= 320 && playerY <= 1920 - 320)
			{
				scrollY = playerY - 320;
			}

			animationTimer++;

			if (animationTimer >= 5)
			{
				animationTimer = 0;
				playScene++;
			}

			if (playScene >= 48)
			{
				playScene = 0;
			}

			// �`�揈��

			DrawGraph(0, 640 - scrollY, graphHandle8[playScene], TRUE);
			DrawGraph(0, 0 - scrollY, graphHandle[0], TRUE);

			for (int y = 0; y < mapCountY; y++)
			{
				for (int x = 0; x < mapCountX; x++)
				{
					if (map[y][x] == BLOCK)
					{
						DrawGraph(x * blockSize, (y * blockSize) - scrollY, graphHandle1[0], TRUE);
					}
					if (map[y][x] == BLOCK1)
					{
						DrawGraph(x * blockSize, (y * blockSize) - scrollY, graphHandle1[1], TRUE);
					}
					if (map[y][x] == BLOCK2)
					{
						DrawGraph(x * blockSize, (y * blockSize) - scrollY, graphHandle1[5], TRUE);
					}
					if (map[y][x] == BLOCK3)
					{
						DrawGraph(x * blockSize, (y * blockSize) - scrollY, graphHandle1[2], TRUE);
					}
					if (map[y][x] == BLOCK4)
					{
						DrawGraph(x * blockSize, (y * blockSize) - scrollY, graphHandle1[14], TRUE);
					}
					if (map[y][x] == BLOCK5)
					{
						DrawGraph(x * blockSize, (y * blockSize) - scrollY, graphHandle1[3], TRUE);
					}
					if (map[y][x] == BLOCK6)
					{
						DrawGraph(x * blockSize, (y * blockSize) - scrollY, graphHandle1[7], TRUE);
					}
					if (map[y][x] == BLOCK7)
					{
						DrawGraph(x * blockSize, (y * blockSize) - scrollY, graphHandle1[11], TRUE);
					}
					if (map[y][x] == BLOCK8)
					{
						DrawGraph(x * blockSize, (y * blockSize) - scrollY, graphHandle1[15], TRUE);
					}
					if (map[y][x] == BLOCK9)
					{
						DrawGraph(x * blockSize, (y * blockSize) - scrollY, graphHandle[1], TRUE);
					}
				}
			}

			//�������
			displayTimer++;

			if (displayTimer <= 90)
			{
				DrawGraph(0, 30, graphHandle7[0], TRUE);
			}
			if (displayTimer > 90 && displayTimer <= 180)
			{
				DrawGraph(0, 30, graphHandle7[1], TRUE);
			}
			if (displayTimer > 180 && displayTimer <= 270)
			{
				DrawGraph(0, 30, graphHandle7[2], TRUE);
			}

			//�v���C���[
			DrawExtendGraph(playerX - playerRadius, (playerY - playerRadius) - scrollY, playerX + playerRadius, (playerY + playerRadius) - scrollY, graphHandle2[playerNumber], TRUE);
		}
		if (scene == 2)
		{
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0)
			{
				scene = 3;
			}

			if (jumpCount <= 99)
			{
				oneDigits = jumpCount % 10;
				tenDigits = (jumpCount - oneDigits) / 10;
			}
			else
			{
				oneDigits = 9;
				tenDigits = 9;
			}

			if (CheckSoundMem(bgm[0]) == 1)
			{
				StopSoundMem(bgm[0]);
			}
			if (CheckSoundMem(bgm[1]) == 1)
			{
				StopSoundMem(bgm[1]);
			}
			if (CheckSoundMem(bgm[2]) == 0)
			{
				PlaySoundMem(bgm[2], DX_PLAYTYPE_LOOP);
			}

			DrawGraph(0, 0, graphHandle[0], TRUE);

			if (jumpCount <= 30)
			{
				DrawGraph(170, 500, graphHandle5[0], TRUE);
			}
			if (jumpCount >= 31 && jumpCount <= 35)
			{
				DrawGraph(170, 500, graphHandle5[1], TRUE);
			}
			if (jumpCount >= 36 && jumpCount <= 45)
			{
				DrawGraph(170, 500, graphHandle5[2], TRUE);
			}
			if (jumpCount >= 46)
			{
				DrawGraph(170, 500, graphHandle5[3], TRUE);
			}

			DrawGraph(220, 300, graphHandle6[oneDigits], TRUE);
			DrawGraph(150, 300, graphHandle6[tenDigits], TRUE);

			DrawGraph(0, 0, graphHandle4[0], TRUE);
		}
		if (scene == 3)
		{
			timer++;
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0 && timer >= 5)
			{
				if (crearScene == 1)
				{
					playerX = 304;
					playerY = 1872;
					playerNumber = 0;
					scrollY = 1280;
					jumpFlag = 0;
					jumpTimer = 0;
					countTimer = 0;
					timer = 0;
					jumpCount = 0;
					oneDigits = 0;
					tenDigits = 0;
					displayTimer = 0;
					animationTimer = 0;
					playScene = 0;
					scene = 0;
				}
				if (crearScene == 2)
				{
					break;
				}
			}
			if (keys[KEY_INPUT_UP] == 1 && oldkeys[KEY_INPUT_UP] == 0)
			{
				if (crearScene == 1)
				{
					crearScene = 2;
				}
				else if (crearScene == 2)
				{
					crearScene = 1;
				}
			}
			if (keys[KEY_INPUT_DOWN] == 1 && oldkeys[KEY_INPUT_DOWN] == 0)
			{
				if (crearScene == 1)
				{
					crearScene = 2;
				}
				else if (crearScene == 2)
				{
					crearScene = 1;
				}
			}

			DrawGraph(0, 0, graphHandle[0], TRUE);
			DrawGraph(0, 0, graphHandle4[crearScene], TRUE);
		}

		// �`�揈��

		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1)
		{
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}