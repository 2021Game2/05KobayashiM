#ifndef CENEMYS_H
#define CENEMYS_H

#include "CRectangle.h"

class CEnemys : public CRectangle {
public:
	int mFx; //X�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:�E�ֈړ�
	int mFy; //Y�������̈ړ� -1:�� 0:�ړ����Ȃ� 1:��ֈړ�
//	bool mEnabled;	//�L���t���O

//37	CBullet EBullet[20];
	int mFireCount;

	CEnemys();

	void Update();
	bool Collision(const CRectangle& r);
	void Render();

	//36
	void Collision(CRectangle* i, CRectangle* y);
};

#endif
