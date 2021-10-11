#include "CEnemyas.h"
#include "CTexture.h"
//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
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
	//mEnabled��false�Ȃ�߂�
	if (!mEnabled) return;
	x += mFx;
	y += mFy;
}
/*
�e��Collision���I�[�o�[���C�h����
�Փ˂���ƈړ������𔽑΂ɂ���
*/
bool CEnemyas::Collision(const CRectangle& r) {
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

void CEnemyas::Render() {
	if (mEnabled) {
		CRectangle::Render(Texture, 146 - 16, 146 + 16, 178 + 16, 178 - 16);
	}
}

//36
void CEnemyas::Collision(CRectangle* i, CRectangle* y) {
	Collision(*y);
}