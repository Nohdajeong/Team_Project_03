#include "stdafx.h"
#include "Print.h"
#include "KeyMgrS2.h"
#include "BmpMgrS2.h"
#include "SceneMgr.h"

CPrint::CPrint()
{
}

CPrint::~CPrint()
{
	Release();
}

void CPrint::Initialize()
{
	m_tInfo.vPos = { 70.f, 400.f, 0.f };

	m_fCX = 120.f;
	m_fCY = 120.f;

	m_fSpeed = 3.f;

	CBmpMgrS2::Get_Instance()->Insert_Bmp(L"../Resource/NoteBook.bmp", L"NoteBook");

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 1;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 300;
	m_tFrame.dwTime = (DWORD)GetTickCount64();


	m_eRender = GAMEOBJECT;
}

int CPrint::Update()
{
	if (m_bDead)
		return OBJ_DEAD;

	__super::Move_Frame();

	return OBJ_NOEVENT;
}

void CPrint::Late_Update()
{
	if (CSceneMgr::Get_Instance()->Get_SceneID() != SC_STAGE2)
		Set_Dead();

}

void CPrint::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgrS2::Get_Instance()->Find_Img(L"NoteBook");

		GdiTransparentBlt(hDC,
			(int)m_tInfo.vPos.x, // 복사 받을 위치 X,Y 좌표
			(int)m_tInfo.vPos.y,
			(int)m_fCX,	// 복사 받을 가로, 세로 길이
			(int)m_fCY,
			hMemDC,			// 비트맵 이미지를 담고 있는 DC
			int(m_tFrame.iFrameStart * m_fCX),					// 비트맵을 출력할 시작 X,Y좌표
			int(m_tFrame.iMotion * m_fCY),
			(int)m_fCX,		// 출력할 비트맵의 가로, 세로 사이즈
			(int)m_fCY,
			RGB(195, 134, 255)); // 제거하고자 하는 색상

}

void CPrint::Release()
{
}