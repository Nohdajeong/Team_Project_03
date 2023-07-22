#include "stdafx.h"
#include "Stage2.h"
#include "BmpMgrS2.h"
#include "ObjMgrS2.h"
#include "AbstractFactoryS2.h"
#include "KeyMgrS2.h"
#include "TileMgrS2.h"
#include "ScrollMgr.h"

CStage2::CStage2()
{
}

CStage2::~CStage2()
{
	Release();
}

void CStage2::Initialize()
{
	CObjMgrS2::Get_Instance()->Add_Object(PLAYBOX, CAbstractFactoryS2<CPlayBox>::Create());
	CObjMgrS2::Get_Instance()->Add_Object(BUTTON, CAbstractFactoryS2<CPrint>::Create());

	CBmpMgrS2::Get_Instance()->Insert_Bmp(L"../Resource/Back.bmp", L"Back_Game");

}

void CStage2::Update()
{
	m_pBlock = CAbstractFactoryS2<CBlock>::Create();

	if (m_dwPreTime + 3000 < GetTickCount64()) {
		CObjMgrS2::Get_Instance()->Add_Object(BLOCK, m_pBlock);

		m_dwPreTime = GetTickCount64();
	}

	if (m_dwLastTime + 1000 < GetTickCount64()) {
		m_iTime++;
		m_dwLastTime = GetTickCount64();
	}

	CObjMgrS2::Get_Instance()->Update();

}

void CStage2::Late_Update()
{
	CObjMgrS2::Get_Instance()->Late_Update();
}

void CStage2::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgrS2::Get_Instance()->Find_Img(L"Back_Game");

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CObjMgrS2::Get_Instance()->Render(hDC);

	SetBkMode(hDC, 1);
	SetTextColor(hDC, RGB(255, 255, 255));

	swprintf_s(szBuff, L"Time : %d", m_iTime);
	TextOut(hDC, 100.f, 100.f, szBuff, lstrlen(szBuff));


}

void CStage2::Release()
{
}
