#ifndef CPLAYER_H
#define CPLAYER_H

#include "CRectangle.h"

class CPlayer : public CRectangle {
public:
	int mFx, mFy;
	//37
	int FireCount;
	CPlayer();
	void Update();
	void Render();
	int mAniCnt;//�A�j���[�V�����p�J�E���^


	//36
	void Collision(CRectangle *i, CRectangle *y);
};

#endif
