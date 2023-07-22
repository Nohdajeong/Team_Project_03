#pragma once

#include "Define.h"

class CKeyMgrS2
{
private:
	CKeyMgrS2();
	~CKeyMgrS2();

public:
	bool		Key_Pressing(int _iKey);
	bool		Key_Down(int _iKey);
	bool		Key_Up(int _iKey);

public:
	static CKeyMgrS2* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CKeyMgrS2;
		}

		return m_pInstance;
	}
	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CKeyMgrS2* m_pInstance;
	bool	m_bKeyState[VK_MAX];
};

