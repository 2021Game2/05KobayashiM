#ifndef GAMETITLE_H
#define GAMETITLE_H

#include "CScene.h"
#include "CText.h"

class GameTitle : public CScene {
public:
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
