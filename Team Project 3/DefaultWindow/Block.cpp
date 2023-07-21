#include "stdafx.h"
#include "Block.h"
#include "KeyMgr.h"

CBlock::CBlock()
{
}

CBlock::~CBlock()
{
	Release();
}

void CBlock::Initialize()
{
	m_tInfo.vPos = { 400.f, 0.f, 0.f };

	m_vPoint[0] = { m_tInfo.vPos.x - 30.f,  m_tInfo.vPos.y - 30.f, 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + 30.f,  m_tInfo.vPos.y - 30.f, 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + 30.f,  m_tInfo.vPos.y + 30.f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - 30.f,  m_tInfo.vPos.y + 30.f, 0.f };

	for (int i = 0; i < 4; ++i)
		m_vOriginalPoint[i] = m_vPoint[i];

	m_tInfo.vDir = { 1.f, 0.f, 0.f };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };

	m_fSpeed = 3.f;

	m_eRender = GAMEOBJECT;
}

int CBlock::Update()
{
	Key_Input();

	D3DXMATRIX	matScale, matRotZ, matTrans;

	D3DXMatrixScaling(&matScale, -1.f, 1.f, 1.f);
	D3DXMatrixRotationZ(&matRotZ, m_fAngle);
	D3DXMatrixTranslation(&matTrans, m_tInfo.vPos.x, m_tInfo.vPos.y, 0.f);

	m_tInfo.matWorld = matScale * matRotZ * matTrans;

	for (int i = 0; i < 4; i++) {
		m_vPoint[i] = m_vOriginalPoint[i];
		m_vPoint[i] -= {400.f, 0.f, 0.f};

		D3DXVec3TransformCoord(&m_vPoint[i], &m_vPoint[i], &m_tInfo.matWorld);
	}

	if (m_tInfo.vPos.y >= 500)
		m_fSpeed = 0.f;

	m_tInfo.vPos.y += m_fSpeed;



	return OBJ_NOEVENT;
}

void CBlock::Late_Update()
{
}

void CBlock::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);

	for (int i = 0; i < 4; ++i) {
		LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);

	}

	LineTo(hDC, m_vPoint[0].x, m_vPoint[0].y);

}

void CBlock::Release()
{
}

void CBlock::Key_Input()
{

	if (m_tInfo.vPos.y < 500) {
		if (CKeyMgr::Get_Instance()->Key_Down('A'))
			m_fAngle -= D3DXToRadian(45.f);

		if (CKeyMgr::Get_Instance()->Key_Down('D'))
			m_fAngle += D3DXToRadian(45.f);

		if (CKeyMgr::Get_Instance()->Key_Down(VK_LEFT)) {
			if (m_tInfo.vPos.x > 300)
				m_tInfo.vPos.x -= 60.f;
		}

		if (CKeyMgr::Get_Instance()->Key_Down(VK_RIGHT)) {
			if (m_tInfo.vPos.x < 700)
				m_tInfo.vPos.x += 60.f;
		}
	}

}

