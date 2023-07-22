#include "stdafx.h"
#include "Stage2.h"
#include "BmpMgrS2.h"
#include "ObjMgrS2.h"
#include "AbstractFactoryS2.h"
#include "KeyMgrS2.h"
#include "TileMgrS2.h"

CStage2::CStage2()
	:m_pBlock(nullptr)
{
}

CStage2::~CStage2()
{
	Release();
}

void CStage2::Initialize()
{
	CObjMgrS2::Get_Instance()->Add_Object(BUTTON, CAbstractFactoryS2<CPrint>::Create());
	
	CTileMgrS2::Get_Instance()->Load_Tile();
	CTileMgrS2::Get_Instance()->Initialize();

	////CLineMgr::Get_Instance()->Initialize();

	////CTileMgr::Get_Instance()->Initialize();

	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ground.bmp", L"Ground");
}

void CStage2::Update()
{

	if (m_dwPreTime + 4000 < GetTickCount64()) {
			CObjMgrS2::Get_Instance()->Add_Object(BLOCK, CAbstractFactoryS2<CBlock>::Create());

			m_dwPreTime = GetTickCount64();
	}

	CObjMgrS2::Get_Instance()->Update();
	CTileMgrS2::Get_Instance()->Update();

}

void CStage2::Late_Update()
{
	CObjMgrS2::Get_Instance()->Late_Update();
	CTileMgrS2::Get_Instance()->Late_Update();
}

void CStage2::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);

	CObjMgrS2::Get_Instance()->Render(hDC);
	CTileMgrS2::Get_Instance()->Render(hDC);

	//HDC		hGoundDC = CBmpMgr::Get_Instance()->Find_Img(L"Ground");

	//int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	//int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	//BitBlt(hDC,	// 복사 받을 DC(최종적으로 그림을 그릴 DC공간)
	//	iScrollX, iScrollY, 1920, 1280,
	//	hGoundDC,			// 비트맵 이미지를 담고 있는 DC
	//	0,					// 비트맵을 출력할 시작 X,Y좌표
	//	0,
	//	SRCCOPY);


	swprintf_s(szBuff, L"stage2");
	TextOut(hDC, 100.f, 100.f, szBuff, lstrlen(szBuff));


}

void CStage2::Release()
{
}
