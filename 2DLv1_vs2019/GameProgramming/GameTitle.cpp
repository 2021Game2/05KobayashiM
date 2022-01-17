#include "GameTitle.h"
#include "CKey.h"

void GameTitle::Init() {
	//シーンの設定
	mScene = EGAMEOVER;
}

//更新処理のオーバーライド
void GameTitle::Update() {
	//文字列の描画
	CText::DrawString("GAME OVER", -200, 0, 50, 50);
	CText::DrawString("Push ENTER Key",
		-200, -100, 16, 16);
	if (CKey::Once(VK_RETURN)) {
		//次のシーンはゲーム
		mScene = ETITLE;
	}
}
//次のシーンの取得
CScene::EScene GameTitle::GetNextScene() {
	return mScene;
}