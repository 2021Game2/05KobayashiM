#include "CEnemys.h"//�E�j
#include "CTexture.h"
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;

//CBullet CEnemy::EBullet[20];

CEnemys::CEnemys()
	: mFx(1.0f), mFy(0.0f), mFireCount(60)
{
	//37
//	mEnabled = true;
	mTag = EENEMYS;
	w = 25;
	h = 25;
}

void CEnemys::Update() {
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	x += mFx;
	y += mFy;
}
/*
�e��Collision���I�[�o�[���C�h����
�Փ˂���ƈړ������𔽑΂ɂ���
*/
bool CEnemys::Collision(const CRectangle& r) {
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

void CEnemys::Render() {
	if (mEnabled) {
		CRectangle::Render(Texture, 146 - 16, 146 + 16, 178 + 16, 178 - 16);
	}
}

//36
void CEnemys::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}