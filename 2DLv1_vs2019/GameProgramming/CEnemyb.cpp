#include "CEnemyb.h"
#include "CTexture.h"
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
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
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	x += mFx;
	y += mFy;
}
/*
�e��Collision���I�[�o�[���C�h����
�Փ˂���ƈړ������𔽑΂ɂ���
*/
bool CEnemyb::Collision(const CRectangle& r) {
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

void CEnemyb::Render() {
	if (mEnabled) {
		CRectangle::Render(Texture, 199 - 9, 199 + 9, 119 - 9, 119 + 9);
	}
}

//36
void CEnemyb::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}