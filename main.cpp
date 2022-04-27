#include <Novice.h>
#include<DirectXMath.h>
#define PI 3.14159265

const char kWindowTitle[] = "LE2B_07_イワタ_ユウシロウ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	//初期化
	float box[4][3] = {
	  {100,100, 100},
	  {100,400, 100},
	  {400,400, 100},
	  {400,100, 100}
    };

	float box2[4][3] = {
	  {100, 100, 100},
      {100, 400, 100},
      {400, 400, 100},
      {400, 100, 100}
    };
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
		/// 1,平行移動
		/*
		for (int i = 0; i < 4; i++) {
		    Novice::DrawLine(
			  box[i][0] * 1 + box[i][1] * 0 + box[i][2]*1,
			  box[i][0] * 0 + box[i][1] * 1 + box[i][2] * 1,
			  box[(i + 1) % 4][0] * 1 + box[(i + 1) % 4][1] * 0 + box[i][2] * 1,
			  box[(i + 1) % 4][0] * 0 + box[(i + 1) % 4][1] * 1 + box[i][2] * 1, BLACK);
		}*/

		/// 2,回転
		/*for (int i = 0; i < 4; i++) {
			Novice::DrawLine(
			  box[i][0] * cos(PI / 4) + box[i][1] * -sin(PI/4) + box[i][2] * 1,
			  box[i][0] * sin(PI / 4) + box[i][1] * cos(PI/4) + box[i][2] * 1,
			  box[(i + 1) % 4][0] * cos(PI / 4) + box[(i + 1) % 4][1] * -sin(PI / 4) + box[i][2] * 1,
			  box[(i + 1) % 4][0] * sin(PI / 4) + box[(i + 1) % 4][1] * cos(PI / 4) + box[i][2] * 1,
				BLACK);
		}*/
		///
		/// 
		/// 3,拡大,縮小
		
		for (int i = 0; i < 4; i++) {
			Novice::DrawLine(
			  box[i][0] * 2 + box[i][1] * 0 + box[i][2] * 0,
			  box[i][0] * 0 + box[i][1] * 2 + box[i][2] * 0,
			  box[(i + 1) % 4][0] * 2 + box[(i + 1) % 4][1] * 0 + box[i][2] * 0,
			  box[(i + 1) % 4][0] * 0 + box[(i + 1) % 4][1] * 2 + box[i][2] * 0, GREEN);
		}

		for (int i = 0; i < 4; i++) {
			Novice::DrawLine(
			  box[i][0] * 1/2 + box[i][1] * 0 + box[i][2] * 0,
			  box[i][0] * 0 + box[i][1] * 1/2 + box[i][2] * 0,
			  box[(i + 1) % 4][0] * 1/2 + box[(i + 1) % 4][1] * 0 + box[i][2] * 0,
			  box[(i + 1) % 4][0] * 0 + box[(i + 1) % 4][1] * 1/2 + box[i][2] * 0, WHITE);
		}
		///
		/// 0,ベース
		for (int i = 0; i < 4; i++) {
			Novice::DrawLine(
			  box2[i][0], box2[i][1], box2[(i + 1) % 4][0],
			  box2[(i + 1) % 4][1], BLACK);
		}
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
