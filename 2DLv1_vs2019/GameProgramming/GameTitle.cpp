#include "GameTitle.h"
#include "CKey.h"

void GameTitle::Init() {
	//�V�[���̐ݒ�
	mScene = EGAMEOVER;
}

//�X�V�����̃I�[�o�[���C�h
void GameTitle::Update() {
	//������̕`��
	CText::DrawString("GAME OVER", -200, 0, 50, 50);
	CText::DrawString("Push ENTER Key",
		-200, -100, 16, 16);
	if (CKey::Once(VK_RETURN)) {
		//���̃V�[���̓Q�[��
		mScene = ETITLE;
	}
}
//���̃V�[���̎擾
CScene::EScene GameTitle::GetNextScene() {
	return mScene;
}