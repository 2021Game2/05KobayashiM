#include "CEnemyas.h"
#include "CTexture.h"
//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;

//CBullet CEnemy::EBullet[20];

CEnemyas::CEnemyas()
	: mFx(1.0f), mFy(0.0f), mFireCount(60)
{
	//37
//	mEnabled = true;
	mTag = EENEMYAS;
	w = 25;
	h = 25;
}

void CEnemyas::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	x += mFx;
	y += mFy;
}
/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
bool CEnemyas::Collision(const CRectangle& r) {
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

void CEnemyas::Render() {
	if (mEnabled) {
		CRectangle::Render(Texture, 146 - 16, 146 + 16, 178 + 16, 178 - 16);
	}
}

//36
void CEnemyas::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}