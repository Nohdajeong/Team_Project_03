#pragma once
#include "Scene.h"
#include "Obj.h"

class CStage2 :
	public CScene
{
public:
			 CStage2();
	virtual ~CStage2();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	CObj*		m_pBlock;

private:
	TCHAR	szBuff[100] = L"";

};

