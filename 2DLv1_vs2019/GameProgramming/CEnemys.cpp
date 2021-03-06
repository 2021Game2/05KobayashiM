#include "CEnemys.h"//ウニ
#include "CTexture.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;
extern int Score;

//CBullet CEnemy::EBullet[20];
CTexture uni;
CEnemys::CEnemys()
	: mFx(1.0f), mFy(0.0f), mFireCount(60)
{
	//37
//	mEnabled = true;
	mTag = EENEMYS;
	w = 25;
	h = 25;
	if (uni.mId == 0) {
		uni.Load("Guni.png");
	}
}

void CEnemys::Update() {
	//mEnabledがfalseなら戻る
	if (!mEnabled) return;
	x += mFx;
	y += mFy;
}
/*
親のCollisionをオーバーライドする
衝突すると移動方向を反対にする
*/
bool CEnemys::Collision(const CRectangle& r) {
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
			Score += 50;
			break;
		}
		return true;
	}
	return false;
}

void CEnemys::Render() {
	if (mEnabled) {
		CRectangle::Render(uni, 0, 3840, 3244, 0);
	}
}

//36
void CEnemys::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}