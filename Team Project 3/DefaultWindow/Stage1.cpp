#include "stdafx.h"
#include "Stage1.h"
#include "BmpMgrS2.h"
#include "ObjMgrS2.h"
#include "ScrollMgr.h"
#include "KeyMgrS2.h"
#include "SceneMgr.h"

CStage1::CStage1()
{
}

CStage1::~CStage1()
{
}

void CStage1::Initialize()
{
	//CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CPlayer>::Create());
	//CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CMonster>::Create());
	////CLineMgr::Get_Instance()->Initialize();

	////CTileMgr::Get_Instance()->Load_Tile();
	////CTileMgr::Get_Instance()->Initialize();

	CBmpMgrS2::Get_Instance()->Insert_Bmp(L"../Resource/Back.bmp", L"Ground");
}

void CStage1::Update()
{
	//CObjMgr::Get_Instance()->Update();
}

void CStage1::Late_Update()
{
	if (CKeyMgrS2::Get_Instance()->Key_Down('P'))
		CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE2);

	//CObjMgr::Get_Instance()->Late_Update();
}

void CStage1::Render(HDC hDC)
{
	HDC		hGoundDC = CBmpMgrS2::Get_Instance()->Find_Img(L"Ground");

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	BitBlt(hDC,	// 복사 받을 DC(최종적으로 그림을 그릴 DC공간)
		iScrollX, iScrollY, 1920, 1280,
		hGoundDC,			// 비트맵 이미지를 담고 있는 DC
		0,					// 비트맵을 출력할 시작 X,Y좌표
		0,
		SRCCOPY);

	////CTileMgr::Get_Instance()->Render(hDC);

	//CObjMgr::Get_Instance()->Render(hDC);
}

void CStage1::Release()
{
}
