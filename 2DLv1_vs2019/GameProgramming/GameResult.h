#ifndef GAMERESULT_H
#define GAMERESULT_H

#include "CScene.h"
#include "CText.h"

class GameResult : public CScene {
public:
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//���̃V�[���̎擾
	EScene GetNextScene();
};

#endif
