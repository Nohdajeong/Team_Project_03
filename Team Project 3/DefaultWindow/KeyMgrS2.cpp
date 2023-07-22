#include "stdafx.h"
#include "KeyMgrS2.h"

CKeyMgrS2* CKeyMgrS2::m_pInstance = nullptr;

CKeyMgrS2::CKeyMgrS2()
{
	ZeroMemory(m_bKeyState, sizeof(m_bKeyState));
}

CKeyMgrS2::~CKeyMgrS2()
{
}

bool CKeyMgrS2::Key_Pressing(int _iKey)
{
	if (GetAsyncKeyState(_iKey) & 0x8000)
		return true;

	return false;
}

bool CKeyMgrS2::Key_Down(int _iKey)
{
	// �������� ���� ���� ���� ���� ������ ���
	if (!m_bKeyState[_iKey] && (GetAsyncKeyState(_iKey) & 0x8000))
	{
		m_bKeyState[_iKey] = !m_bKeyState[_iKey];
		return true;
	}

	for (int i = 0; i < VK_MAX; ++i)
	{
		if (m_bKeyState[i] && !(GetAsyncKeyState(i) & 0x8000))
			m_bKeyState[i] = !m_bKeyState[i];
	}

	return false;
}

bool CKeyMgrS2::Key_Up(int _iKey)
{
	// �������� ���� ���� �ְ� ���� ������ �ʾ��� ���
	if (m_bKeyState[_iKey] && !(GetAsyncKeyState(_iKey) & 0x8000))
	{
		m_bKeyState[_iKey] = !m_bKeyState[_iKey];
		return true;
	}

	for (int i = 0; i < VK_MAX; ++i)
	{
		if (!m_bKeyState[i] && (GetAsyncKeyState(i) & 0x8000))
			m_bKeyState[i] = !m_bKeyState[i];
	}

	return false;
}
