#include <DirectXMath.h>
#include <Novice.h>
#define PI 3.14159265

const char kWindowTitle[] = "LE2B_07_イワタ_ユウシロウ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//ベースとなる行列の宣言と初期化
	float boxBase[4][3] = {
	  {100.0f, 100.0f, 1.0f},
	  {100.0f, 400.0f, 1.0f},
	  {400.0f, 400.0f, 1.0f},
	  {400.0f, 100.0f, 1.0f}
    };

	// 移動・回転・拡大の行列の宣言と初期化
	float boxMoved[4][3];
	float boxRotated[4][3];
	float boxScaled[4][3];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			boxMoved[i][j] = boxBase[i][j];
			boxRotated[i][j] = boxBase[i][j];
			boxScaled[i][j] = boxBase[i][j];
		}
	}

	// 平行移動のためのアフィン行列

	float affinMove[3][3] = {
	  {1.0f, 0.0f, 100.0f},
      {0.0f, 1.0f, 100.0f},
      {0.0f, 0.0f, 1.0f  }
    };

	// 回転のためのアフィン行列
	float affinRotated[3][3] = {
	  {cos(45), -sin(45), -100.0f},
      {sin(45), cos(45),  -100.0f},
      {0.0f,    0.0f,     1.0f}
    };
	// 拡大ののためのアフィン行列
	float affinScaled[3][3]{
	  {2.0f, 0.0f,-100.0f},
      {0.0f, 2.0f, -100.0f},
      {0.0f, 0.0f, 1.0f}
    };
	// 平行移動の計算
	for (int i = 0; i < 4; i++) {
		boxMoved[i][0] = affinMove[0][0] * boxBase[i][0] + 
						 affinMove[0][1] * boxBase[i][1] +
		                 affinMove[0][2] * boxBase[i][2];

		boxMoved[i][1] = affinMove[1][0] * boxBase[i][0] + 
						 affinMove[1][1] * boxBase[i][1] +
		                 affinMove[1][2] * boxBase[i][2];

		boxMoved[i][2] = affinMove[2][0] * boxBase[i][0] + 
						 affinMove[2][1] * boxBase[i][1] +
		                 affinMove[2][2] * boxBase[i][2];
	}

	// 回転の計算
	for (int i = 0; i < 4; i++) {
		
						   
		boxRotated[i][0] = affinRotated[0][0] * boxRotated[i][0] +
		                   affinRotated[0][1] * boxRotated[i][1] +
		                   affinRotated[0][2] * boxRotated[i][2];

		boxRotated[i][1] = affinRotated[1][0] * boxRotated[i][0] +
		                   affinRotated[1][1] * boxRotated[i][1] +
		                   affinRotated[1][2] * boxRotated[i][2];

		boxRotated[i][2] = affinRotated[2][0] * boxRotated[i][0] +
		                   affinRotated[2][1] * boxRotated[i][1] +
		                   affinRotated[2][2] * boxRotated[i][2];
	
	}
	// 拡大の計算
	for (int i = 0; i < 4; i++) {

		boxScaled[i][0] = affinScaled[0][0] * boxScaled[i][0] +
		                  affinScaled[0][1] * boxScaled[i][1] + 
						  affinScaled[0][2] * boxScaled[i][2];

		boxScaled[i][1] = affinScaled[1][0] * boxScaled[i][0] +
		                  affinScaled[1][1] * boxScaled[i][1] +
						  affinScaled[1][2] * boxScaled[i][2];

		boxScaled[i][2] = affinScaled[2][0] * boxScaled[i][0] +
		                  affinScaled[2][1] * boxScaled[i][1] + 
						  affinScaled[2][2] * boxScaled[i][2];
	}
	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		/// 0,ベース
		for (int i = 0; i < 4; i++) {
			Novice::DrawLine(
			  boxBase[i][0], boxBase[i][1], boxBase[(i + 1) % 4][0], boxBase[(i + 1) % 4][1],
			  BLACK);
		}
		/// 1,平行移動

		for (int i = 0; i < 4; i++) {
			Novice::DrawLine(
			  boxMoved[i][0], boxMoved[i][1], boxMoved[(i + 1) % 4][0], boxMoved[(i + 1) % 4][1],
			  BLUE);
		}
		//2,回転
		for (int i = 0; i < 4; i++) {
			Novice::DrawLine(
			  boxRotated[i][0], boxRotated[i][1],
			  boxRotated[(i + 1) % 4][0],
			  boxRotated[(i + 1) % 4][1], RED);
		}

		// 3,拡大
		for (int i = 0; i < 4; i++) {
			Novice::DrawLine(
			  boxScaled[i][0], boxScaled[i][1], boxScaled[(i + 1) % 4][0],
			  boxScaled[(i + 1) % 4][1], GREEN);
		}
		//
		/*for (int i = 0; i < 4; i++) {
		    Novice::DrawLine(
		      box[i][0] * 1/2 + box[i][1] * 0 + box[i][2] * 0,
		      box[i][0] * 0 + box[i][1] * 1/2 + box[i][2] * 0,
		      box[(i + 1) % 4][0] * 1/2 + box[(i + 1) % 4][1] * 0 + box[i][2] * 0,
		      box[(i + 1) % 4][0] * 0 + box[(i + 1) % 4][1] * 1/2 + box[i][2] * 0, WHITE);
		}*/

		///
		/*/// 0,全部(拡大)
		for (int i = 0; i < 4; i++) {
		    Novice::DrawLine(
		      box[i][0] * cos(PI / 4) * 2 + box[i][1] * -sin(PI / 4) * -2 + box[i][2] * 1,
		      box[i][0] * sin(PI / 4) * -2 + box[i][1] * cos(PI / 4) * 2 + box[i][2] * 1,
		      box[(i + 1) % 4][0] * cos(PI / 4) * 2 + box[(i + 1) % 4][1] * -sin(PI / 4) * -2 +
		        box[i][2] * 1,
		      box[(i + 1) % 4][0] * sin(PI / 4) * -2 + box[(i + 1) % 4][1] * cos(PI / 4) * 2 +
		        box[i][2] * 1,
		      BLACK);
		}*/

		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
