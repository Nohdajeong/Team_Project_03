#pragma once
#include "Scene.h"
#include "Obj.h"
#include "Block.h"
#include "Print.h"
#include "PlayBox.h"

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
	CObj*	m_pBlock;

private:
	TCHAR	szBuff[100] = L"";
	DWORD	m_dwPreTime = GetTickCount64();
	DWORD	m_dwLastTime = GetTickCount64();

	int		m_iTime = 0;
};

