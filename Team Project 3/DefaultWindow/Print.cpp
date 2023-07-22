#include "stdafx.h"
#include "Print.h"
#include "KeyMgrS2.h"
#include "BmpMgrS2.h"

CPrint::CPrint()
{
}

CPrint::~CPrint()
{
	Release();
}

void CPrint::Initialize()
{
	m_tInfo.vPos = { 150.f, 450.f, 0.f };

	m_vPoint[0] = { m_tInfo.vPos.x - 50.f,  m_tInfo.vPos.y - 100.f, 0.f };
	m_vPoint[1] = { m_tInfo.vPos.x + 50.f,  m_tInfo.vPos.y - 100.f, 0.f };
	m_vPoint[2] = { m_tInfo.vPos.x + 50.f,  m_tInfo.vPos.y + 100.f, 0.f };
	m_vPoint[3] = { m_tInfo.vPos.x - 50.f,  m_tInfo.vPos.y + 100.f, 0.f };

	for (int i = 0; i < 4; ++i)
		m_vOriginalPoint[i] = m_vPoint[i];

	m_fSpeed = 3.f;

	CBmpMgrS2::Get_Instance()->Insert_Bmp(L"../Resource/Teacher.bmp", L"Teacher");

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 2;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 300;
	m_tFrame.dwTime = (DWORD)GetTickCount64();


	m_eRender = GAMEOBJECT;
}

int CPrint::Update()
{
	__super::Move_Frame();

	return OBJ_NOEVENT;
}

void CPrint::Late_Update()
{
}

void CPrint::Render(HDC hDC)
{
	MoveToEx(hDC, (int)m_vPoint[0].x, (int)m_vPoint[0].y, nullptr);

	for (int i = 0; i < 4; ++i) {
		LineTo(hDC, (int)m_vPoint[i].x, (int)m_vPoint[i].y);

	}

	LineTo(hDC, m_vPoint[0].x, m_vPoint[0].y);

	HDC		hMemDC = CBmpMgrS2::Get_Instance()->Find_Img(L"Teacher");

		GdiTransparentBlt(hDC,
			(int)m_tInfo.vPos.x, // 복사 받을 위치 X,Y 좌표
			(int)m_tInfo.vPos.y,
			50.f,	// 복사 받을 가로, 세로 길이
			75.f,
			hMemDC,			// 비트맵 이미지를 담고 있는 DC
			m_tFrame.iFrameStart * 50.f,					// 비트맵을 출력할 시작 X,Y좌표
			m_tFrame.iMotion * 75.f,
			50.f,		// 출력할 비트맵의 가로, 세로 사이즈
			75.f,
			RGB(195, 134, 255)); // 제거하고자 하는 색상

}

void CPrint::Release()
{
}
