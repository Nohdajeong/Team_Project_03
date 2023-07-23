#pragma once
#include "Scene.h"
#include "ObjS2.h"
#include "BlockJ.h"
#include "BlockU.h"
#include "BlockS.h"
#include "BlockI.h"
#include "BlockN.h"
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
	void	Collision_BlockJ();
	void	Collision_BlockU();
	void	Collision_BlockS();
	void	Collision_BlockI();

	bool	Draw_Same();

private:
	CObjS2* m_pBlockJ;
	CObjS2* m_pBlockU;
	CObjS2* m_pBlockS;
	CObjS2* m_pBlockI;
	CObjS2* m_pBlockN;

private:
	TCHAR	szBuff[100] = L"";
	TCHAR	szBuff2[100] = L"";
	DWORD	m_dwPreTime = (DWORD)GetTickCount64();
	DWORD	m_dwLastTime = (DWORD)GetTickCount64();
	DWORD	m_dwTime = (DWORD)GetTickCount64();

	int		m_iTime = 0;
	int		m_iRand = 0;
	int		m_iCount = 0;
};

