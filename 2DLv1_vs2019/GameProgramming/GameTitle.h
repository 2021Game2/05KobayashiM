#ifndef GAMETITLE_H
#define GAMETITLE_H

#include "CScene.h"
#include "CText.h"

class GameTitle : public CScene {
public:
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//次のシーンの取得
	EScene GetNextScene();
};

#endif
