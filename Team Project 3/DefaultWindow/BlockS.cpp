#include "stdafx.h"
#include "BlockS.h"
#include "KeyMgrS2.h"
#include "BmpMgrS2.h"
#include "CollisionMgrS2.h"
#include "ObjMgrS2.h"

CBlockS::CBlockS()
{
}

CBlockS::~CBlockS()
{
	Release();
}

void CBlockS::Initialize()
{
	m_fCX = 60.f;
	m_fCY = 60.f;

	m_tInfo.vPos = { 460.f, 0.f, 0.f };

	m_vPoint[0] = { m_tInfo.vPos.x - 30.f,  m_tInfo.vPos.y - 30.f, 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + 30.f,  m_tInfo.vPos.y - 30.f, 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + 30.f,  m_tInfo.vPos.y + 30.f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - 30.f,  m_tInfo.vPos.y + 30.f, 0.f };

	for (int i = 0; i < 4; ++i)
		m_vOriginalPoint[i] = m_vPoint[i];

	m_tInfo.vDir = { 1.f, 0.f, 0.f };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };

	m_fSpeed = 3.f;

	CBmpMgrS2::Get_Instance()->Insert_Bmp(L"../Resource/BlockS.bmp", L"BlockS");

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.iMotion = rand() % 3;
	m_tFrame.dwSpeed = 300;
	m_tFrame.dwTime = (DWORD)GetTickCount64();
	m_iFirst = m_tFrame.iMotion;

	m_iScore = 0;
	m_fLine = 500.f;

	m_eRender = GAMEOBJECT;
}

int CBlockS::Update()
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
	__super::Move_Frame();

	return OBJ_NOEVENT;
}

void CBlockS::Late_Update()
{
	m_tInfo.vPrepos = m_tInfo.vPos;

	m_tFrame.iMotion = m_iFirst;

	if (m_tInfo.vPos.y >= m_fLine + 10) {
		m_fSpeed = 0.f;
	}

}

void CBlockS::Render(HDC hDC)
{

	HDC		hMemDC = CBmpMgrS2::Get_Instance()->Find_Img(L"BlockS");

	if (m_tInfo.vPos.y >= 70.f) {

		GdiTransparentBlt(hDC,
			(int)m_tRect.left, // 복사 받을 위치 X,Y 좌표
			(int)m_tRect.top,
			(int)m_fCX,	// 복사 받을 가로, 세로 길이
			(int)m_fCY,
			hMemDC,			// 비트맵 이미지를 담고 있는 DC
			int(m_tFrame.iFrameStart * m_fCX),					// 비트맵을 출력할 시작 X,Y좌표
			int(m_tFrame.iMotion * m_fCY),
			(int)m_fCX,		// 출력할 비트맵의 가로, 세로 사이즈
			(int)m_fCY,
			RGB(195, 134, 255)); // 제거하고자 하는 색상

	}
}

void CBlockS::Release()
{
}

void CBlockS::Key_Input()
{
	if (m_tInfo.vPos.y <= m_fLine - 120.f) {
		if (CKeyMgrS2::Get_Instance()->Key_Down('A')) {
			m_fAngle -= D3DXToRadian(90.f);
			m_iFirst -= 1;
			if (m_iFirst == -1)
				m_iFirst = 3;
		}

		if (CKeyMgrS2::Get_Instance()->Key_Down('D')) {
			m_fAngle += D3DXToRadian(90.f);
			m_iFirst += 1;
			if (m_iFirst == 4)
				m_iFirst = 0;
		}

		if (CKeyMgrS2::Get_Instance()->Key_Down(VK_LEFT)) {
			if (m_tInfo.vPos.x > 360.f)
				m_tInfo.vPos.x -= m_fCX;
		}

		if (CKeyMgrS2::Get_Instance()->Key_Down(VK_RIGHT)) {
			if (m_tInfo.vPos.x < 700.f)
				m_tInfo.vPos.x += m_fCX;
		}
	}

}