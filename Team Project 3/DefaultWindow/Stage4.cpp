#include "stdafx.h"
#include "Stage4.h"
#include "BmpMgrS2.h"
#include "ObjMgrS2.h"

CStage4::CStage4()
{
}

CStage4::~CStage4()
{
}

void CStage4::Initialize()
{
	//CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CPlayer>::Create());
	//CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CMonster>::Create());
	////CLineMgr::Get_Instance()->Initialize();

	////CTileMgr::Get_Instance()->Load_Tile();
	////CTileMgr::Get_Instance()->Initialize();

	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ground.bmp", L"Ground");
}

void CStage4::Update()
{
	//CObjMgr::Get_Instance()->Update();
}

void CStage4::Late_Update()
{
	//CObjMgr::Get_Instance()->Late_Update();
}

void CStage4::Render(HDC hDC)
{
	//HDC		hGoundDC = CBmpMgr::Get_Instance()->Find_Img(L"Ground");

	//int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	//int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	//BitBlt(hDC,	// ���� ���� DC(���������� �׸��� �׸� DC����)
	//	iScrollX, iScrollY, 1920, 1280,
	//	hGoundDC,			// ��Ʈ�� �̹����� ��� �ִ� DC
	//	0,					// ��Ʈ���� ����� ���� X,Y��ǥ
	//	0,
	//	SRCCOPY);

	////CTileMgr::Get_Instance()->Render(hDC);

	//CObjMgr::Get_Instance()->Render(hDC);
}

void CStage4::Release()
{
}
