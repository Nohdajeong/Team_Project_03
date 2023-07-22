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

	m_iScore = 0;

	m_eRender = GAMEOBJECT;
}

int CBlock::Update()
{
	Key_Input();

#pragma region 벡터&행렬
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

	m_tInfo.vPos.y += m_fSpeed;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CBlock::Late_Update()
{
	if (m_tInfo.vPos.y >= 510.f) {
		m_fSpeed = 0.f;
	}
	if (Search(this))
		m_fSpeed = 0.f;
}

void CBlock::Render(HDC hDC)
{

	HDC		hMemDC = CBmpMgrS2::Get_Instance()->Find_Img(L"BlockA");

	if (m_tInfo.vPos.y >= 70.f) {
		GdiTransparentBlt(hDC,
			m_tRect.left, // 복사 받을 위치 X,Y 좌표
			m_tRect.top,
			(int)m_fCX,	// 복사 받을 가로, 세로 길이
			(int)m_fCY,
			hMemDC,			// 비트맵 이미지를 담고 있는 DC
			(int)m_iDrawID * m_fCX,					// 비트맵을 출력할 시작 X,Y좌표
			0,
			(int)m_fCX,		// 출력할 비트맵의 가로, 세로 사이즈
			(int)m_fCY,
			RGB(195, 134, 255)); // 제거하고자 하는 색상

		MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);

		for (int i = 0; i < 4; ++i) {
			LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);

		}

		LineTo(hDC, m_vPoint[0].x, m_vPoint[0].y);
	}
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
			if (m_tInfo.vPos.x > 360)
				m_tInfo.vPos.x -= m_fCX;
		}

		if (CKeyMgrS2::Get_Instance()->Key_Down(VK_RIGHT)) {
			if (m_tInfo.vPos.x < 700)
				m_tInfo.vPos.x += m_fCX;
		}
	}

}

bool CBlock::Search(CObj* _pTarget)
{
	if (m_tInfo.vPos.y - m_fCY >= _pTarget->Get_Info().vPos.y) {

		if (m_tInfo.vPos.x > _pTarget->Get_Info().vPos.x && (m_tInfo.vPos.x - m_fCX) < _pTarget->Get_Info().vPos.x)
			return true;
		else if (m_tInfo.vPos.x < _pTarget->Get_Info().vPos.x && (m_tInfo.vPos.x + m_fCX) > _pTarget->Get_Info().vPos.x)
			return true;
	}

	return false;
}
