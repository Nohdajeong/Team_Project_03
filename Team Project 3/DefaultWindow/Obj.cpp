#include "stdafx.h"
#include "Obj.h"


CObj::CObj() : m_fSpeed(0.f), m_fAngle(0.f), m_fCX(0.f), m_fCY(0.f)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	D3DXMatrixIdentity(&m_tInfo.matWorld);
}


CObj::~CObj()
{
}

void CObj::Update_Rect()
{
	//m_tRect.left = LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	//m_tRect.top = LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
	//m_tRect.right = LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	//m_tRect.bottom = LONG(m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

void CObj::Move_Frame()
{
	if (m_tFrame.dwTime + m_tFrame.dwSpeed < GetTickCount())
	{
		++m_tFrame.iFrameStart;

		if (m_tFrame.iFrameStart > m_tFrame.iFrameEnd)
			m_tFrame.iFrameStart = 0;

		m_tFrame.dwTime = GetTickCount();
	}

}
