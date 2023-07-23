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
#include "SceneMgr.h"

CStage2::CStage2()
	:m_pBlockJ(nullptr), m_pBlockU(nullptr), m_pBlockS(nullptr), m_pBlockI(nullptr), m_pBlockN(nullptr)
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
	m_iCount = 0;
	m_iDraw_Count = 0;
}

void CStage2::Update()
{

	if (m_dwPreTime + 2000 < GetTickCount64()) {

		switch (m_iRand % 5) {
		case 0:
			m_pBlockJ = CAbstractFactoryS2<CBlockJ>::Create();
			CObjMgrS2::Get_Instance()->Add_Object(BLOCKJ, m_pBlockJ);
			m_iRand++;
			break;

		case 1:
			m_pBlockU = CAbstractFactoryS2<CBlockU>::Create();
			CObjMgrS2::Get_Instance()->Add_Object(BLOCKU, m_pBlockU);
			m_iRand++;
			break;

		case 2:
			m_pBlockS = CAbstractFactoryS2<CBlockS>::Create();
			CObjMgrS2::Get_Instance()->Add_Object(BLOCKS, m_pBlockS);
			m_iRand++;
			break;

		case 3:
			m_pBlockI = CAbstractFactoryS2<CBlockI>::Create();
			CObjMgrS2::Get_Instance()->Add_Object(BLOCKI, m_pBlockI);
			m_iRand++;
			break;

		case 4:
			m_pBlockN = CAbstractFactoryS2<CBlockN>::Create();
			CObjMgrS2::Get_Instance()->Add_Object(BLOCKN, m_pBlockN);
			m_iRand++;
			break;

		}


		m_dwPreTime = (DWORD)GetTickCount64();
	}

	if (m_dwTime + 1000 < (DWORD)GetTickCount64()) {
		m_iTime++;
		m_dwTime = (DWORD)GetTickCount64();
	}


	CObjMgrS2::Get_Instance()->Update();

}

void CStage2::Late_Update()
{
	CObjMgrS2::Get_Instance()->Late_Update();

	if (CKeyMgrS2::Get_Instance()->Key_Down('P'))
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE3);

	if (m_iTime == 60)
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE3);

	if (m_iCount >= 5)
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE3);

	Collision_BlockJ();
	Collision_BlockU();
	Collision_BlockS();
	Collision_BlockI();


	if (Draw_Same()) {
		if (CObjMgrS2::Get_Instance()->Get_Objects(BLOCKJ).front()->Get_First() == 0)
			m_iDraw_Count++;

		if (CObjMgrS2::Get_Instance()->Get_Objects(BLOCKU).front()->Get_First() == 0)
			m_iDraw_Count++;

		if (CObjMgrS2::Get_Instance()->Get_Objects(BLOCKS).front()->Get_First() == 0)
			m_iDraw_Count++;

		if (CObjMgrS2::Get_Instance()->Get_Objects(BLOCKI).front()->Get_First() == 0)
			m_iDraw_Count++;

		if (CObjMgrS2::Get_Instance()->Get_Objects(BLOCKN).front()->Get_First() == 0)
			m_iDraw_Count++;


		if (m_iDraw_Count > 0) {

			CObjMgrS2::Get_Instance()->Get_Objects(BLOCKJ).front()->Set_Dead();
			CObjMgrS2::Get_Instance()->Get_Objects(BLOCKU).front()->Set_Dead();
			CObjMgrS2::Get_Instance()->Get_Objects(BLOCKS).front()->Set_Dead();
			CObjMgrS2::Get_Instance()->Get_Objects(BLOCKI).front()->Set_Dead();
			CObjMgrS2::Get_Instance()->Get_Objects(BLOCKN).front()->Set_Dead();

			m_iCount = m_iDraw_Count;
		}
	}

}

void CStage2::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgrS2::Get_Instance()->Find_Img(L"Back_Game");

	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CObjMgrS2::Get_Instance()->Render(hDC);

	SetBkMode(hDC, 1);
	SetTextColor(hDC, RGB(255, 255, 255));

	swprintf_s(szBuff, L"Time : %d", m_iTime);
	TextOut(hDC, 100, 100, szBuff, lstrlen(szBuff));

	swprintf_s(szBuff2, L"Count : %d", m_iCount);
	TextOut(hDC, 100, 150, szBuff2, lstrlen(szBuff2));

}

void CStage2::Release()
{
}

void CStage2::Collision_BlockJ()
{
	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKJ),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKU));

	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKJ),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKS));

	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKJ),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKI));

	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKJ),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKN));

}

void CStage2::Collision_BlockU()
{
	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKU),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKS));

	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKU),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKI));

	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKU),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKN));
}

void CStage2::Collision_BlockS()
{
	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKS),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKI));

	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKS),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKN));

	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKS),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKJ));

}

void CStage2::Collision_BlockI()
{

	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKI),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKN));

	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKI),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKJ));

	CCollisionMgrS2::Collision_Sphere(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKI),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKU));

}

bool CStage2::Draw_Same()
{
	if (CCollisionMgrS2::Collison_Sphere_Check(
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKJ),
		CObjMgrS2::Get_Instance()->Get_Objects(BLOCKU)) &&
		CCollisionMgrS2::Collison_Sphere_Check(
			CObjMgrS2::Get_Instance()->Get_Objects(BLOCKU),
			CObjMgrS2::Get_Instance()->Get_Objects(BLOCKS)) &&
		CCollisionMgrS2::Collison_Sphere_Check(
			CObjMgrS2::Get_Instance()->Get_Objects(BLOCKS),
			CObjMgrS2::Get_Instance()->Get_Objects(BLOCKI)) &&
		CCollisionMgrS2::Collison_Sphere_Check(
			CObjMgrS2::Get_Instance()->Get_Objects(BLOCKI),
			CObjMgrS2::Get_Instance()->Get_Objects(BLOCKN)))
			return true;

	return false;
}

