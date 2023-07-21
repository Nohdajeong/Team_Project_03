#include "stdafx.h"
#include "Logo.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

CLogo::CLogo()
{
}

CLogo::~CLogo()
{
	Release();
}

void CLogo::Initialize()
{
	
}

void CLogo::Update()
{
}

void CLogo::Late_Update()
{

		//CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE1);
		//return;
}

void CLogo::Render(HDC hDC)
{
	//HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Logo");
	//BitBlt(hDC,	0, 0, WINCX, WINCY, hMemDC,	0, 0, SRCCOPY);
}

void CLogo::Release()
{
}
