#include "DxLib.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "アセットガール";

// ウィンドウ横幅
const int WIN_WIDTH = 608;

// ウィンドウ縦幅
const int WIN_HEIGHT = 640;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0xFF);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み

	int graphHandle[2];
	graphHandle[0] = LoadGraph("background3.png");
	graphHandle[1] = LoadGraph("Star.png");

	int graphHandle1[20];//画像用変数
	LoadDivGraph
	(
		"block.png",  //読み込みたい画像ファイルの名前
		20,             //グラフィックの総分割総数
		4,             //グラフィックの横向きに対する分割数
		5,             //グラフィックの縦向きに対する分割数
		32,            //グラフィックサイズ
		32,            //グラフィックサイズ
		graphHandle1    //分割読み込みして得たグラフィックハンドルを保存するint型配列
	);

	int graphHandle2[6];//画像用変数
	LoadDivGraph
	(
		"charcter.png",  //読み込みたい画像ファイルの名前
		6,             //グラフィックの総分割総数
		3,             //グラフィックの横向きに対する分割数
		2,             //グラフィックの縦向きに対する分割数
		32,            //グラフィックサイズ
		32,            //グラフィックサイズ
		graphHandle2    //分割読み込みして得たグラフィックハンドルを保存するint型配列
	);

	int graphHandle3[2];//画像用変数
	LoadDivGraph
	(
		"taitle.png",  //読み込みたい画像ファイルの名前
		2,             //グラフィックの総分割総数
		2,             //グラフィックの横向きに対する分割数
		1,             //グラフィックの縦向きに対する分割数
		608,            //グラフィックサイズ
		640,            //グラフィックサイズ
		graphHandle3    //分割読み込みして得たグラフィックハンドルを保存するint型配列
	);

	int graphHandle4[3];//画像用変数
	LoadDivGraph
	(
		"crear.png",  //読み込みたい画像ファイルの名前
		3,             //グラフィックの総分割総数
		3,             //グラフィックの横向きに対する分割数
		1,             //グラフィックの縦向きに対する分割数
		608,            //グラフィックサイズ
		640,            //グラフィックサイズ
		graphHandle4    //分割読み込みして得たグラフィックハンドルを保存するint型配列
	);

	int graphHandle5[4];//画像用変数
	LoadDivGraph
	(
		"rank.png",  //読み込みたい画像ファイルの名前
		4,             //グラフィックの総分割総数
		4,             //グラフィックの横向きに対する分割数
		1,             //グラフィックの縦向きに対する分割数
		128,            //グラフィックサイズ
		128,            //グラフィックサイズ
		graphHandle5    //分割読み込みして得たグラフィックハンドルを保存するint型配列
	);

	int graphHandle6[10];//画像用変数
	LoadDivGraph
	(
		"number.png",  //読み込みたい画像ファイルの名前
		10,             //グラフィックの総分割総数
		10,             //グラフィックの横向きに対する分割数
		1,             //グラフィックの縦向きに対する分割数
		128,            //グラフィックサイズ
		128,            //グラフィックサイズ
		graphHandle6    //分割読み込みして得たグラフィックハンドルを保存するint型配列
	);

	int graphHandle7[3];//画像用変数
	LoadDivGraph
	(
		"operation.png",  //読み込みたい画像ファイルの名前
		3,             //グラフィックの総分割総数
		1,             //グラフィックの横向きに対する分割数
		3,             //グラフィックの縦向きに対する分割数
		608,            //グラフィックサイズ
		160,            //グラフィックサイズ
		graphHandle7    //分割読み込みして得たグラフィックハンドルを保存するint型配列
	);

	int graphHandle8[49];//画像用変数
	LoadDivGraph
	(
		"backgroundAA.png",  //読み込みたい画像ファイルの名前
		49,             //グラフィックの総分割総数
		49,             //グラフィックの横向きに対する分割数
		1,             //グラフィックの縦向きに対する分割数
		608,            //グラフィックサイズ
		1280,            //グラフィックサイズ
		graphHandle8    //分割読み込みして得たグラフィックハンドルを保存するint型配列
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

	//マップの列(横)の数
	int mapCountX = sizeof(map[0]) / sizeof(map[0][0]);

	//マップの行(縦)の数
	int mapCountY = sizeof(map) / sizeof(map[0]);

	//マップの列(横)の数
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

	// ゲームループで使う変数の宣言

	//プレイヤーの位置
	int playerX = 304;
	int playerY = 1872;

	//プレイヤーの半径
	int playerRadius = 16;

	//プレイヤーの移動
	int playerSpeed = 4;

	//プレイヤーの絵の動き
	int playerNumber = 0;

	//ジャンプ
	int jumpFlag = 0;
	int jumpTimer = 0;

	float jumpPower = 0.0f;
	float landingSpeed = 0.0f;
	float upwardSpeed = 2.0f;

	//重力
	float gravity = 1.0f;

	//スクロール
	int scrollY = 1280;

	//当たり判定に必要

	//左上の左
	int upperLeftX = 0;
	int upperLeftY = 0;
	//左上の上
	int upperLeftX2 = 0;
	int upperLeftY2 = 0;
	//右上の右
	int upperRightX = 0;
	int upperRightY = 0;
	//右上の上
	int upperRightX2 = 0;
	int upperRightY2 = 0;
	//右下の右
	int bottomRightX = 0;
	int bottomRightY = 0;
	//右下の下
	int bottomRightX2 = 0;
	int bottomRightY2 = 0;
	//左下の左
	int bottomLeftX = 0;
	int bottomLeftY = 0;
	//左下の下
	int bottomLeftX2 = 0;
	int bottomLeftY2 = 0;

	//制限
	int countTimer = 0;
	int timer = 0;
	int displayTimer = 0;
	int animationTimer = 0;

	//シーン
	int scene = 0;

	//スコア
	int jumpCount = 0;
	int oneDigits = 0;
	int tenDigits = 0;

	//絵を動かす
	int titleScene = 0;
	int crearScene = 1;
	int playScene = 0;

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (1)
	{
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存

		for (int i = 0; i < 256; ++i)
		{
			oldkeys[i] = keys[i];
		}

		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理

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

			//左上の左
			upperLeftY = ((playerY - playerRadius) + 1) / blockSize;
			upperLeftX = ((playerX - playerRadius) - 1) / blockSize;
			//左上の上
			upperLeftY2 = ((playerY - playerRadius) - 1) / blockSize;
			upperLeftX2 = ((playerX - playerRadius) + 1) / blockSize;
			//右上の右
			upperRightY = ((playerY - playerRadius) + 1) / blockSize;
			upperRightX = ((playerX + playerRadius) + 1) / blockSize;
			//右上の上
			upperRightY2 = ((playerY - playerRadius) - 1) / blockSize;
			upperRightX2 = ((playerX + playerRadius) - 1) / blockSize;
			//右下の右
			bottomRightY = ((playerY + playerRadius) - 1) / blockSize;
			bottomRightX = ((playerX + playerRadius) + 1) / blockSize;
			//右下の下
			bottomRightY2 = ((playerY + playerRadius) + 1) / blockSize;
			bottomRightX2 = ((playerX + playerRadius) - 3) / blockSize;
			//左下の左
			bottomLeftY = ((playerY + playerRadius) - 1) / blockSize;
			bottomLeftX = ((playerX - playerRadius) - 1) / blockSize;
			//左下の下
			bottomLeftY2 = ((playerY + playerRadius) + 1) / blockSize;
			bottomLeftX2 = ((playerX - playerRadius) + 3) / blockSize;

			//プレイヤー移動

			if (map[upperRightY][upperRightX] <= 0 || map[bottomRightY][bottomRightX] <= 0)
			{
				//右移動
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
				//左移動
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

				//ジャンプ
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
				//重力(落下)
				if (landingSpeed <= 15.0f)
				{
					landingSpeed += gravity;
				}
				playerY += landingSpeed;
			}

			//クリア
			if (map[upperLeftY][upperLeftX] >= 10 || map[bottomLeftY][bottomLeftX] >= 10 ||
				map[upperRightY][upperRightX] >= 10 || map[bottomRightY][bottomRightX] >= 10 ||
				map[upperLeftY2][upperLeftX2] >= 10 || map[upperRightY2][upperRightX2] >= 10 ||
				map[bottomRightY2][bottomRightX2] >= 10 || map[bottomLeftY2][bottomLeftX2] >= 10)
			{
				scene = 2;
			}

			//ぶつかったとき

			//左上の左
			if (keys[KEY_INPUT_LEFT] == 1 && oldkeys[KEY_INPUT_LEFT] == 0 && map[upperLeftY][upperLeftX] >= 1)
			{
				playerX = (upperLeftX * blockSize) + blockSize + playerRadius;
			}
			//左下の左
			if (keys[KEY_INPUT_LEFT] == 1 && oldkeys[KEY_INPUT_LEFT] == 0 && map[bottomLeftY][bottomLeftX] >= 1)
			{
				playerX = (bottomLeftX * blockSize) + blockSize + playerRadius;
			}
			//右上の右
			if (keys[KEY_INPUT_RIGHT] == 1 && oldkeys[KEY_INPUT_RIGHT] == 0 && map[upperRightY][upperRightX] >= 1)
			{
				playerX = (upperRightX * blockSize) - playerRadius;
			}
			//右下の右
			if (keys[KEY_INPUT_RIGHT] == 1 && oldkeys[KEY_INPUT_RIGHT] == 0 && map[bottomRightY][bottomRightX] >= 1)
			{
				playerX = (bottomRightX * blockSize) - playerRadius;
			}
			//左上の上
			if (jumpFlag == 1 && map[upperLeftY2][upperLeftX2] >= 1)
			{
				playerY = (upperLeftY2 * blockSize) + blockSize + playerRadius;
				jumpPower = 0.0f;
				jumpFlag = 0;
			}
			//右上の上
			if (jumpFlag == 1 && map[upperRightY2][upperRightX2] >= 1)
			{
				playerY = (upperRightY2 * blockSize) + blockSize + playerRadius;
				jumpPower = 0.0f;
				jumpFlag = 0;
			}
			//右下の下
			if (jumpFlag == 0 && map[bottomRightY2][bottomRightX2] >= 1)
			{
				landingSpeed = 0.0f;
				playerY = (bottomRightY2 * blockSize) - playerRadius;
			}
			//左下の下
			if (jumpFlag == 0 && map[bottomLeftY2][bottomLeftX2] >= 1)
			{
				landingSpeed = 0.0f;
				playerY = (bottomLeftY2 * blockSize) - playerRadius;
			}

			//スクロールは全体の大きさ(縦の)決めてから

			//マップ縦1920(一画面縦640) 開始地点320 終了地点1600(1920 - 320)
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

			// 描画処理

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

			//操作説明
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

			//プレイヤー
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

		// 描画処理

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}