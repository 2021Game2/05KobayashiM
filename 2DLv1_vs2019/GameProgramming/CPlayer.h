#ifndef CPLAYER_H
#define CPLAYER_H

#include "CRectangle.h"

class CPlayer : public CRectangle {
public:
	bool mGameOver;
	int mFx, mFy;
	//37
	int FireCount;
	CPlayer();
	void Update();
	void Render();
	int mAniCnt;//アニメーション用カウンタ
	int stop;

	//36
	void Collision(CRectangle *i, CRectangle *y);
};

#endif
