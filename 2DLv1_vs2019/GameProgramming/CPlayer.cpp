#include "CPlayer.h"
#include "CKey.h"
#define ANICNT 30 //アニメーションの切り替え

//extern：他のソースファイルの外部変数にアクセスする宣言
extern CTexture Texture;

CPlayer::CPlayer()
: mFx(1.0f), mFy(0.0f)
, FireCount(0)
, mAniCnt(0)
,stop(0)
{
	mTag = EPLAYER;
}

void CPlayer::Update() {
	if (stop > 0)
	{
		stop--;
		return;
	}
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
	if (stop > 0)
	{
		return;
	}
	mAniCnt++;
	mAniCnt %= ANICNT;
	if (mAniCnt < ANICNT / 2)
	{
		if (mFx >= 0) {
			CRectangle::Render(Texture, 130, 162, 162, 130);
		}
		else {
			CRectangle::Render(Texture, 162, 130, 162, 130);
		}
	}
	else{
		if(mFx >= 0) {
			CRectangle::Render(Texture, 162, 194, 162, 130);
		}
		else {
			CRectangle::Render(Texture, 194, 162, 162, 130);
		}
	}
}

//36
void CPlayer::Collision(CRectangle *ri, CRectangle *ry) {
	if (stop > 0)
	{
		return;
	}
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
	//親のCollisionメソッドを呼び出す
	if (CRectangle::Collision(*ry)) {
		switch (ry->mTag) {
		case EENEMYB:
			//敵に当たると５秒間停止
			stop = 300;
			break;
		}
	}
}


