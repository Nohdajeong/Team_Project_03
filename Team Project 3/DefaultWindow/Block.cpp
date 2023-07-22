#include "stdafx.h"
#include "Block.h"
#include "KeyMgrS2.h"
#include "BmpMgrS2.h"

CBlock::CBlock()
{
}

CBlock::~CBlock()
{
	Release();
}

void CBlock::Initialize()
{
	m_fCX = 60.f;
	m_fCY = 60.f;

	m_tInfo.vPos = { 400.f, 0.f, 0.f };

	m_vPoint[0] = { m_tInfo.vPos.x - (m_fCX * 0.5f),  m_tInfo.vPos.y - (m_fCY * 0.5f), 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + (m_fCX * 0.5f),  m_tInfo.vPos.y - (m_fCY * 0.5f), 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + (m_fCX * 0.5f),  m_tInfo.vPos.y + (m_fCY * 0.5f), 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - (m_fCX * 0.5f),  m_tInfo.vPos.y + (m_fCY * 0.5f), 0.f };

	for (int i = 0; i < 4; ++i)
		m_vOriginalPoint[i] = m_vPoint[i];

	m_tInfo.vDir = { 1.f, 0.f, 0.f };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };

	m_fSpeed = 3.f;

	CBmpMgrS2::Get_Instance()->Insert_Bmp(L"../Resource/BlockA.bmp", L"BlockA");

	m_iDrawID = 0;

	m_eRender = GAMEOBJECT;
}

int CBlock::Update()
{
	Key_Input();

#pragma region ����&���
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

#pragma endregion

	if (m_tInfo.vPos.y >= 500) {
		m_fSpeed = 0.f;
	}

	m_tInfo.vPos.y += m_fSpeed;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CBlock::Late_Update()
{
}

void CBlock::Render(HDC hDC)
{

	HDC		hMemDC = CBmpMgrS2::Get_Instance()->Find_Img(L"BlockA");

	GdiTransparentBlt(hDC,
		int(m_vPoint[1].x), // ���� ���� ��ġ X,Y ��ǥ
		int(m_vPoint[1].y),
		(int)m_fCX,	// ���� ���� ����, ���� ����
		(int)m_fCY,
		hMemDC,			// ��Ʈ�� �̹����� ��� �ִ� DC
		(int)m_iDrawID * m_fCX,					// ��Ʈ���� ����� ���� X,Y��ǥ
		0,
		(int)m_fCX,		// ����� ��Ʈ���� ����, ���� ������
		(int)m_fCY,
		RGB(195, 134, 255)); // �����ϰ��� �ϴ� ����

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

	if (m_tInfo.vPos.y <= 500) {
		if (CKeyMgrS2::Get_Instance()->Key_Down('A'))
			m_fAngle -= D3DXToRadian(45.f);

		if (CKeyMgrS2::Get_Instance()->Key_Down('D'))
			m_fAngle += D3DXToRadian(45.f);

		if (CKeyMgrS2::Get_Instance()->Key_Down(VK_LEFT)) {
			if (m_tInfo.vPos.x > 300)
				m_tInfo.vPos.x -= m_fCX;
		}

		if (CKeyMgrS2::Get_Instance()->Key_Down(VK_RIGHT)) {
			if (m_tInfo.vPos.x < 700)
				m_tInfo.vPos.x += m_fCX;
		}
	}

}
