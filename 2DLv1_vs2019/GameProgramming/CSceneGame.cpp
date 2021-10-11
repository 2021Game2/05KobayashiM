#include "CSceneGame.h"
#include <stdio.h>

//�c�莞�ԁi30�b�j
int Time = 60 * 60;
int Remain = 3;

void CSceneGame::Init() {
	//�V�[���̐ݒ�
	mScene = EGAME;

	//�N���X�̃����o�ϐ��ւ̑��
//37
	CPlayer *Player = new CPlayer();
	Player->x = 150;
	Player->y = 150;
	Player->w = 25;
	Player->h = 25;
	Player->mEnabled = true;
//37
	int map[6][8] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 0, 0, 0, 1, 1 },
		{ 1, 2, 0, 0, 1, 5, 0, 1 },
		{ 1, 0, 1, 2, 0, 0, 1, 1 },
		{ 1, 0, 0, 0, 1, 2, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1 },
	};
//37	MapSize = 0;	//0��������
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 8; i++) {
			//map�̗v�f��1�̎��A�l�p�`�z�u
			if (map[j][i] == 1) {
				//37
				CMap *Map = new CMap();
				//�l�p�`�ɒl��ݒ�
				Map->mEnabled = true;
				Map->x = i * 100 - 350;//-350����-340�Ƃ������ɂ���ƓG�����ɂ����
				Map->y = j * -100 + 250;//+250����+240�Ƃ������ɂ���ƃ}�b�v�����ɂ����
				Map->w = 50;
				Map->h = 50;
				//37
			}
			else if (map[j][i] == 2) {
				CEnemy *Enemy = new CEnemy();
				Enemy->x = i * 100 - 350;//-350����-340�Ƃ������ɂ���ƓG���E�ɂ����
				Enemy->y = j * -100 + 250;//���������炷�ƓG�����ɂ����
				//�E�ֈړ�
				Enemy->mFx = 0;//1���E�ɐi��-1�����ɐi�� ���x+1
				Enemy->mFy = -1;//1����ɐi��-1�����ɐi�� ���x+1
				/*37
				for (int k = 0; k < 10; k++) {
					if (!Enemy[k].mEnabled) {
						//�G�ɒl��ݒ�
						Enemy[k].x = i * 100 - 350;
						Enemy[k].y = j * -100 + 250;
						//�E�ֈړ�
						Enemy[k].mFx = 0;
						Enemy[k].mFy = 1;
						//�L���ɂ���
						Enemy[k].mEnabled = true;
						break;
					}
				}
				*/
			}
			else if (map[j][i] == 3) {
				CEnemyas* Enemyas = new CEnemyas();
				Enemyas->x = i * 100 - 350;//-350����-340�Ƃ������ɂ���ƓG���E�ɂ����
				Enemyas->y = j * -100 + 250;//���������炷�ƓG�����ɂ����
				//�E�ֈړ�
				Enemyas->mFx = 0;//1���E�ɐi��-1�����ɐi�� ���x+1
				Enemyas->mFy = -1;//1����ɐi��-1�����ɐi�� ���x+1
				/*37
				for (int k = 0; k < 10; k++) {
					if (!Enemyas[k].mEnabled) {
						//�G�ɒl��ݒ�
						Enemyas[k].x = i * 100 - 350;
						Enemyas[k].y = j * -100 + 250;
						//�E�ֈړ�
						Enemyas[k].mFx = 0;
						Enemyas[k].mFy = 1;
						//�L���ɂ���
						Enemyas[k].mEnabled = true;
						break;
					}
				}
				*/
			}
			else if (map[j][i] == 4) {
				CEnemys* Enemys = new CEnemys();
				Enemys->x = i * 100 - 350;//-350����-340�Ƃ������ɂ���ƓG���E�ɂ����
				Enemys->y = j * -100 + 250;//���������炷�ƓG�����ɂ����
				//�E�ֈړ�
				Enemys->mFx = 0;//1���E�ɐi��-1�����ɐi�� ���x+1
				Enemys->mFy = -1;//1����ɐi��-1�����ɐi�� ���x+1
				/*37
				for (int k = 0; k < 10; k++) {
					if (!Enemys[k].mEnabled) {
						//�G�ɒl��ݒ�
						Enemys[k].x = i * 100 - 350;
						Enemys[k].y = j * -100 + 250;
						//�E�ֈړ�
						Enemys[k].mFx = 0;
						Enemys[k].mFy = 1;
						//�L���ɂ���
						Enemys[k].mEnabled = true;
						break;
					}
				}
				*/
			}
			else if (map[j][i] == 5) {
				CEnemyb* Enemyb = new CEnemyb();
				Enemyb->x = i * 100 - 350;//-350����-340�Ƃ������ɂ���ƓG���E�ɂ����
				Enemyb->y = j * -100 + 250;//���������炷�ƓG�����ɂ����
				//�E�ֈړ�
				Enemyb->mFx = 0;//1���E�ɐi��-1�����ɐi�� ���x+1
				Enemyb->mFy = -1;//1����ɐi��-1�����ɐi�� ���x+1
				/*37
				for (int k = 0; k < 10; k++) {
					if (!Enemyb[k].mEnabled) {
						//�G�ɒl��ݒ�
						Enemyb[k].x = i * 100 - 350;
						Enemyb[k].y = j * -100 + 250;
						//�E�ֈړ�
						Enemyb[k].mFx = 0;
						Enemyb[k].mFy = 1;
						//�L���ɂ���
						Enemyb[k].mEnabled = true;
						break;
					}
				}
				*/
			}
		}
	}
}

void CSceneGame::Update() {
	/*
	�z��̗v�f���J��Ԃ�
	�z��.size()
	�z��̗v�f�����擾����
	*/
	for (int i = 0; i < VectorRect.size(); i++) {
		/*
		�z��̎Q��
		�z��[�Y����]
		�ʏ�̔z�񓯗l�ɓY�����ŗv�f�ɃA�N�Z�X�ł���
		*/
		//�X�V����
		VectorRect[i]->Update();
	}
	for (int i = 0; i < VectorRect.size() - 1; i++) {
		//�Փˏ���
		for (int j = i + 1; j < VectorRect.size(); j++) {
			VectorRect[i]->Collision(VectorRect[i], VectorRect[j]);
			VectorRect[j]->Collision(VectorRect[j], VectorRect[i]);
		}
	}

	//���X�g����폜����
	//�C�e���[�^�̐���
	std::vector<CRectangle*>::iterator itr;
	//�C�e���[�^��擪
	itr = VectorRect.begin();
	//�Ō�܂ŌJ��Ԃ�
	while (itr != VectorRect.end()) {
		if ((*itr)->mEnabled) {
			//����
			itr++;
		}
		else {
			//false�̃C���X�^���X���폜
			delete *itr;
			//���X�g������폜
			itr = VectorRect.erase(itr);
		}
	}

	for (int i = 0; i < VectorRect.size(); i++) {
		//�`�揈��
		VectorRect[i]->Render();
	}

	CText::DrawChar('S', -350, 250, 16, 16);
	CText::DrawChar('c', -350 + 32, 250, 16, 16);
	CText::DrawChar('o', -350 + 32 * 2, 250, 16, 16);
	CText::DrawChar('r', -350 + 32 * 3, 250, 16, 16);
	CText::DrawChar('e', -350 + 32 * 4, 250, 16, 16);

	CText::DrawChar('P', 150, -250, 16, 16);
	CText::DrawChar('l', 150 + 32, -250, 16, 16);
	CText::DrawChar('a', 150 + 32 * 2, -250, 16, 16);
	CText::DrawChar('y', 150 + 32 * 3, -250, 16, 16);
	CText::DrawChar('e', 150 + 32 * 4, -250, 16, 16);
	CText::DrawChar('r', 150 + 32 * 5, -250, 16, 16);

	//������̕`��
	CText::DrawString("Time", 150, 250, 16, 16);
	if (Time > 0) {
		Time--;
	}
	//�����𕶎���ɕϊ�����
	char buf[10];//9�����܂�OK
	sprintf(buf, "%d", Time / 60);
	CText::DrawString(buf, 300, 250, 16, 16);

	sprintf(buf, "%d", Remain);
	CText::DrawString(buf, 150 + 32 * 7, -250, 16, 16);

}


//���̃V�[���̎擾
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}
//�f�X�g���N�^
CSceneGame::~CSceneGame() {
	//�S�ẴC���X�^���X���폜���܂�
	for (int i = 0; i < VectorRect.size(); i++) {
		//�C���X�^���X�̍폜
		delete VectorRect[i];
	}
	//�ϒ��z��̃N���A
	VectorRect.clear();
}
