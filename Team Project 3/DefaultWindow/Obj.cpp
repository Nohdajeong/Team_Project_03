#include "stdafx.h"
#include "Obj.h"


CObj::CObj() 
	: m_fSpeed(0.f), m_fAngle(0.f), m_fCX(0.f), m_fCY(0.f),
	m_bDead(false)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	D3DXMatrixIdentity(&m_tInfo.matWorld);
}


CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	m_tRect.left = LONG(m_tInfo.vPos.x - (m_fCX * 0.5f));
	m_tRect.top = LONG(m_tInfo.vPos.y - (m_fCY * 0.5f));
	m_tRect.right = LONG(m_tInfo.vPos.x + (m_fCX * 0.5f));
	m_tRect.bottom = LONG(m_tInfo.vPos.y + (m_fCY * 0.5f));
}

void CObj::Move_Frame()
{
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < (DWORD)GetTickCount64())
	{
		++m_tFrame.iFrameStart;

		if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			m_tFrame.iFrameStart = 0;

		m_tFrame.dwTime = (DWORD)GetTickCount64();
	}

}
