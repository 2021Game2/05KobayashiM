#ifndef CMAPS_H
#define CMAPS_H

#include "CRectangle.h"

extern CTexture Texture;

class CMaps : public CRectangle {
public:
	void Render() {
		if (mEnabled) {
			CRectangle::Render(Texture, 1, 15, 15, 1);
		}
	}
};

#endif
