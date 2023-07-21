#pragma once
#include "IScene.h"
class CTetris : public IScene
{
public:
	CTetris();
	virtual ~CTetris();

public:
	// IScene을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	CObj* m_pBlock;

	HDC			m_DC;

};

