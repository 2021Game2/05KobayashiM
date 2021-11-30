#include "CPlayer.h"
#include "CKey.h"
#define ANICNT 30 //�A�j���[�V�����̐؂�ւ�

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
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
	//static���\�b�h�͂ǂ�����ł��Ăׂ�
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
			//abs(x) x�̐�Βl�����߂�
			//�ړ��ʂ����Ȃ����������ړ�������
			if (abs(mx) < abs(my)) {
				//Rect��x�����ړ�����
				x += mx;
			}
			else {
				//Rect��y�����ړ�����
				y += my;
			}
		}
	}
	//�e��Collision���\�b�h���Ăяo��
	if (CRectangle::Collision(*ry)) {
		switch (ry->mTag) {
		case EENEMYB:
			//�G�ɓ�����ƂT�b�Ԓ�~
			stop = 300;
			break;
		}
	}
}


