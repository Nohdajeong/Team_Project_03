#pragma once

#include "Define.h"
#include "Block.h"

class CMainGame
{

public:
	CMainGame();
	~CMainGame();
public:
	void		Initialize(void);
	void		Update(void);
	void		LateUpdate(void);
	void		Render(void);
	void		Release(void);

private:
	CObj*		m_pBlock;
	CObj*		m_pLastBlock;
	DWORD		m_dwPreTime;

	CObj*		Create_Block();

private:
	TCHAR	szBuff[100] = L"";

private:
	HDC			m_DC;
};