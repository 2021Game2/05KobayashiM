#include "CPlayer.h"
#include "CKey.h"

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;

CPlayer::CPlayer()
: mFx(1.0f), mFy(0.0f)
, FireCount(0)
{
	mTag = EPLAYER;
}

void CPlayer::Update() {

	//staticメソッドはどこからでも呼べる
	if (CKey::Push('A')) {
		x -= 3;
		mFx = -1;
		mFy = 0;
		if (x - w < -400) {
			x = -400 + w;
		}
	}
	if (CKey::Push('D')) {
		x += 3;
		mFx = 1;
		mFy = 0;
		if (x + w > 400) {
			x = 400 - w;
		}
	}
}

void CPlayer::Render() {
	CRectangle::Render(Texture, 146 - 16, 146 + 16, 146 + 16, 146 - 16);
}

//36
void CPlayer::Collision(CRectangle *ri, CRectangle *ry) {
	if (ry->mTag == EBLOCK) {
		int mx, my;
		if (CRectangle::Collision(ry, &mx, &my)) {
			//abs(x) xの絶対値を求める
			//移動量が少ない方向だけ移動させる
			if (abs(mx) < abs(my)) {
				//Rectをxだけ移動する
				x += mx;
			}
			else {
				//Rectをyだけ移動する
				y += my;
			}
		}
	}
}
