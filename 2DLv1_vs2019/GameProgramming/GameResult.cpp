#include "GameResult.h"
#include "CKey.h"

void GameResult::Init() {
	//シーンの設定
	mScene = EGAMEOVER;
}

//更新処理のオーバーライド
void GameResult::Update() {
	//文字列の描画
	CText::DrawString("GAME OVER", -320, 150, 40, 40);
	CText::DrawString("1. 5000", -120, 40, 15, 15);
	CText::DrawString("2. 4500", -120, 0, 15, 15);
	CText::DrawString("3. 4000", -120, -40, 15, 15);
	CText::DrawString("4. 3500", -120, -80, 15, 15);
	CText::DrawString("5. 3000", -120, -120, 15, 15);
	CText::DrawString("Push ENTER Key",
		-200, -200, 16, 16);
	if (CKey::Once(VK_RETURN)) {
		//次のシーンはゲーム
		mScene = ETITLE;
	}
}
//次のシーンの取得
CScene::EScene GameResult::GetNextScene() {
	return mScene;
}