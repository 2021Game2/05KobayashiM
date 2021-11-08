#include "CEnemy.h"//�I
#include "CTexture.h"
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;

//CBullet CEnemy::EBullet[20];
CTexture kuri;
CEnemy::CEnemy()
: mFx(1.0f), mFy(0.0f), mFireCount(60)
{
	//37
//	mEnabled = true;
	mTag = EENEMY;
	w = 25;
	h = 25;
	if (kuri.mId == 0) {
		kuri.Load("Gkuri.png");
	}
}

void CEnemy::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	x += mFx;
	y += mFy;
}
/*
�e��Collision���I�[�o�[���C�h����
�Փ˂���ƈړ������𔽑΂ɂ���
*/
bool CEnemy::Collision(const CRectangle &r) {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return false;
	//�e��Collision���\�b�h���Ăяo��
	if (CRectangle::Collision(r)) {
		switch (r.mTag) {
		case EBLOCK:
			//�ǂɓ�����ƁA�����ɂ���
			mEnabled = false;
			break;
		case EPLAYER:
			//�v���C���[�ɓ�����ƁA�����ɂ���
			mEnabled = false;
			break;
		}
		return true;
	}
	return false;
}

void CEnemy::Render() {
	if (mEnabled) {
		CRectangle::Render(kuri, 0, 640, 640, 0);
	}
}

//36
void CEnemy::Collision(CRectangle *i, CRectangle *y) {
	Collision(*y);
}
