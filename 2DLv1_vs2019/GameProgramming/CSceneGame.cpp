#include "CSceneGame.h"
#include <stdio.h>

//残り時間（30秒）
int Time = 60 * 60;
int Remain = 3;
int Score = 0;

void CSceneGame::Init() {
	//シーンの設定
	mScene = EGAME;

	//クラスのメンバ変数への代入
//37
	CPlayer *Player = new CPlayer();
	Player->x = 0;
	Player->y = -180;
	Player->w = 25;
	Player->h = 25;
	Player->mEnabled = true;
//37
	int map[6][8] =
	{
		{ 2, 0, 4, 0, 3, 5, 0, 2 },
		{ 2, 3, 0, 4, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 2 },
		{ 2, 0, 0, 0, 0, 0, 0, 2 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
	};
//37	MapSize = 0;	//0を代入する
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 8; i++) {
			//mapの要素が1の時、四角形配置
			if (map[j][i] == 1) {
				//37
				CMap *Map = new CMap();
				//四角形に値を設定
				Map->mEnabled = true;
				Map->x = i * 100 - 350;//-350から-340という風にすると敵が左にずれる
				Map->y = j * -100 + 250;//+250から+240という風にするとマップが下にずれる
				Map->w = 50;
				Map->h = 50;
				//37
			}
			else if (map[j][i] == 2) {
				//37
				CMaps* Maps = new CMaps();
				//四角形に値を設定
				Maps->mEnabled = true;
				Maps->x = i * 100 - 350;//-350から-340という風にすると敵が左にずれる
				Maps->y = j * -100 + 250;//+250から+240という風にするとマップが下にずれる
				Maps->w = 50;
				Maps->h = 50;
				//37
			}
			else if (map[j][i] == 3) {
				CEnemy *Enemy = new CEnemy();//栗
				Enemy->x = i * 100 - 350;//-350から-340という風にすると敵が右にずれる
				Enemy->y = j * -100 + 250;//数字を減らすと敵が下にずれる
				//右へ移動
				Enemy->mFx = 0;//1が右に進む-1が左に進む 速度+1
				Enemy->mFy = -1;//1が上に進む-1が下に進む 速度+1
				/*37
				for (int k = 0; k < 10; k++) {
					if (!Enemy[k].mEnabled) {
						//敵に値を設定
						Enemy[k].x = i * 100 - 350;
						Enemy[k].y = j * -100 + 250;
						//右へ移動
						Enemy[k].mFx = 0;
						Enemy[k].mFy = 1;
						//有効にする
						Enemy[k].mEnabled = true;
						break;
					}
				}
				*/
			}
			else if (map[j][i] == 4) {
				CEnemys* Enemys = new CEnemys();//ウニ
				Enemys->x = i * 100 - 350;//-350から-340という風にすると敵が右にずれる
				Enemys->y = j * -100 + 250;//数字を減らすと敵が下にずれる
				//右へ移動
				Enemys->mFx = 0;//1が右に進む-1が左に進む 速度+1
				Enemys->mFy = -1;//1が上に進む-1が下に進む 速度+1
				/*37
				for (int k = 0; k < 10; k++) {
					if (!Enemys[k].mEnabled) {
						//敵に値を設定
						Enemys[k].x = i * 100 - 350;
						Enemys[k].y = j * -100 + 250;
						//右へ移動
						Enemys[k].mFx = 0;
						Enemys[k].mFy = 1;
						//有効にする
						Enemys[k].mEnabled = true;
						break;
					}
				}
				*/
			}
			else if (map[j][i] == 5) {
				CEnemyb* Enemyb = new CEnemyb();//爆弾
				Enemyb->x = i * 100 - 350;//-350から-340という風にすると敵が右にずれる
				Enemyb->y = j * -100 + 250;//数字を減らすと敵が下にずれる
				//右へ移動
				Enemyb->mFx = 0;//1が右に進む-1が左に進む 速度+1
				Enemyb->mFy = -1;//1が上に進む-1が下に進む 速度+1
				/*37
				for (int k = 0; k < 10; k++) {
					if (!Enemyb[k].mEnabled) {
						//敵に値を設定
						Enemyb[k].x = i * 100 - 350;
						Enemyb[k].y = j * -100 + 250;
						//右へ移動
						Enemyb[k].mFx = 0;
						Enemyb[k].mFy = 1;
						//有効にする
						Enemyb[k].mEnabled = true;
						break;
					}
				}
				*/
			}
		}
	}
}

void CSceneGame::Update() {
	/*
	配列の要素分繰り返す
	配列名.size()
	配列の要素数を取得する
	*/
	for (int i = 0; i < VectorRect.size(); i++) {
		/*
		配列の参照
		配列名[添え字]
		通常の配列同様に添え字で要素にアクセスできる
		*/
		//更新処理
		VectorRect[i]->Update();
	}
	for (int i = 0; i < VectorRect.size() - 1; i++) {
		//衝突処理
		for (int j = i + 1; j < VectorRect.size(); j++) {
			VectorRect[i]->Collision(VectorRect[i], VectorRect[j]);
			VectorRect[j]->Collision(VectorRect[j], VectorRect[i]);
		}
	}

	//リストから削除する
	//イテレータの生成
	std::vector<CRectangle*>::iterator itr;
	//イテレータを先頭
	itr = VectorRect.begin();
	//最後まで繰り返し
	while (itr != VectorRect.end()) {
		if ((*itr)->mEnabled) {
			//次へ
			itr++;
		}
		else {
			//falseのインスタンスを削除
			delete *itr;
			//リストからも削除
			itr = VectorRect.erase(itr);
		}
	}

	for (int i = 0; i < VectorRect.size(); i++) {
		//描画処理
		VectorRect[i]->Render();
	}

	CText::DrawString("Score", -350, 250, 16, 16);	

	//文字列の描画
	CText::DrawString("Time", 150, 250, 16, 16);
	if (Time > 0) {
		Time--;
	}
	//整数を文字列に変換する
	char buf[10];//9文字までOK
	sprintf(buf, "%d", Time / 60);
	CText::DrawString(buf, 300, 250, 16, 16);

	sprintf(buf, "%d", Score);
	CText::DrawString(buf, -160, 250, 16, 16);
}


//次のシーンの取得
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}
//デストラクタ
CSceneGame::~CSceneGame() {
	//全てのインスタンスを削除します
	for (int i = 0; i < VectorRect.size(); i++) {
		//インスタンスの削除
		delete VectorRect[i];
	}
	//可変長配列のクリア
	VectorRect.clear();
}
