#include "GameResult.h"
#include "CKey.h"

void GameResult::Init() {
	//�V�[���̐ݒ�
	mScene = EGAMEOVER;
}

//�X�V�����̃I�[�o�[���C�h
void GameResult::Update() {
	//������̕`��
	CText::DrawString("GAME OVER", -320, 150, 40, 40);
	CText::DrawString("1. 5000", -120, 40, 15, 15);
	CText::DrawString("2. 4500", -120, 0, 15, 15);
	CText::DrawString("3. 4000", -120, -40, 15, 15);
	CText::DrawString("4. 3500", -120, -80, 15, 15);
	CText::DrawString("5. 3000", -120, -120, 15, 15);
	CText::DrawString("Push ENTER Key",
		-200, -200, 16, 16);
	if (CKey::Once(VK_RETURN)) {
		//���̃V�[���̓Q�[��
		mScene = ETITLE;
	}
}
//���̃V�[���̎擾
CScene::EScene GameResult::GetNextScene() {
	return mScene;
}