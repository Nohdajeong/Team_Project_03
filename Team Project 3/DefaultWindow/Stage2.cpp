#include "stdafx.h"
#include "Stage2.h"
#include "BmpMgrS2.h"
#include "ObjMgrS2.h"
#include "AbstractFactoryS2.h"
#include "KeyMgrS2.h"
#include "TileMgrS2.h"
#include "ScrollMgr.h"
#include "time.h"
#include "CollisionMgrS2.h"

CStage2::CStage2()
{
}

CStage2::~CStage2()
{
	Release();
}

void CStage2::Initialize()
{
	srand((unsigned int)time(NULL));

	CObjMgrS2::Get_Instance()->Add_Object(PLAYBOX, CAbstractFactoryS2<CPlayBox>::Create());
	CObjMgrS2::Get_Instance()->Add_Object(BUTTON, CAbstractFactoryS2<CPrint>::Create());

	CBmpMgrS2::Get_Instance()->Insert_Bmp(L"../Resource/PlayBox.bmp", L"Back_Game");
	m_iRand = 0;

}

void CStage2::Update()
{
	if (m_dwPreTime + 4000 < GetTickCount64()) {


		switch (m_iRand % 2)
		{
		case 0:
			CObjMgrS2::Get_Instance()->Add_Object(BLOCKJ, CAbstractFactoryS2<CBlockJ>::Create());
			m_iRand++;
			break;

		case 1:
			CObjMgrS2::Get_Instance()->Add_Object(BLOCKU, CAbstractFactoryS2<CBlockU>::Create());
			m_iRand++;
			break;
		}


		m_dwPreTime = GetTickCount64();
	}

	if (m_dwTime + 1000 < GetTickCount64()) {
		m_iTime++;
		m_dwTime = GetTickCount64();
	}

	CObjMgrS2::Get_Instance()->Update();


}

void CStage2::Late_Update()
{
	CObjMgrS2::Get_Instance()->Late_Update();

	//CCollisionMgrS2::Collision_Sphere(
	//	CObjMgrS2::Get_Instance()->Get_Objects(BLOCKJ),
	//	CObjMgrS2::Get_Instance()->Get_Objects(BLOCKU));

	//CCollisionMgrS2::Collision_Sphere(
	//	CObjMgrS2::Get_Instance()->Get_Objects(BLOCKU),
	//	CObjMgrS2::Get_Instance()->Get_Objects(BLOCKJ));

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
