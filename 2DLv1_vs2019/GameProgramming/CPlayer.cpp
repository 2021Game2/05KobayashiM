#include "CPlayer.h"
#include "CKey.h"

//extern�F���̃\�[�X�t�@�C���̊O���ϐ��ɃA�N�Z�X����錾
extern CTexture Texture;

CPlayer::CPlayer()
: mFx(1.0f), mFy(0.0f)
, FireCount(0)
{
	mTag = EPLAYER;
}

void CPlayer::Update() {

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
	CRectangle::Render(Texture, 146 - 16, 146 + 16, 146 + 16, 146 - 16);
}

//36
void CPlayer::Collision(CRectangle *ri, CRectangle *ry) {
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
}