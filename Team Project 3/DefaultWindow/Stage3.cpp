#include "stdafx.h"
#include "Stage3.h"
#include "BmpMgrS2.h"
#include "ObjMgrS2.h"
#include "ScrollMgr.h"

CStage3::CStage3()
{
}

CStage3::~CStage3()
{
}

void CStage3::Initialize()
{
	//CLineMgr::Get_Instance()->Initialize();

	//CTileMgr::Get_Instance()->Load_Tile();
	//CTileMgr::Get_Instance()->Initialize();

	CBmpMgrS2::Get_Instance()->Insert_Bmp(L"../Resource/Back.bmp", L"Ground");
}

void CStage3::Update()
{
	CObjMgrS2::Get_Instance()->Update();
}

void CStage3::Late_Update()
{
	CObjMgrS2::Get_Instance()->Late_Update();
}

void CStage3::Render(HDC hDC)
{
	HDC		hGoundDC = CBmpMgrS2::Get_Instance()->Find_Img(L"Ground");

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	BitBlt(hDC,	// ���� ���� DC(���������� �׸��� �׸� DC����)
		iScrollX, iScrollY, 1920, 1280,
		hGoundDC,			// ��Ʈ�� �̹����� ��� �ִ� DC
		0,					// ��Ʈ���� ����� ���� X,Y��ǥ
		0,
		SRCCOPY);

	//CTileMgr::Get_Instance()->Render(hDC);

	CObjMgrS2::Get_Instance()->Render(hDC);
}

void CStage3::Release()
{
}
