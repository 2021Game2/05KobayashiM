#include "CEnemyb.h"
#include "CTexture.h"
//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;

//CBullet CEnemy::EBullet[20];

CEnemyb::CEnemyb()
	: mFx(1.0f), mFy(0.0f), mFireCount(60)
{
	//37
//	mEnabled = true;
	mTag = EENEMYB;
	w = 25;
	h = 25;
}

void CEnemyb::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	x += mFx;
	y += mFy;
}
/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
bool CEnemyb::Collision(const CRectangle& r) {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return false;
	//親のCollisionメソッドを呼び出す
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EBLOCK:
			//壁に当たると、無効にする
			mEnabled = false;
			break;
		case EPLAYER:
			//プレイヤーに当たると、無効にする
			mEnabled = false;
			break;
		}
		return true;
	}
	return false;
}

void CEnemyb::Render() {
	if (mEnabled) {
		CRectangle::Render(Texture, 199 - 9, 199 + 9, 119 - 9, 119 + 9);
	}
}

//36
void CEnemyb::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}