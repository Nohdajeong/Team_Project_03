#include "stdafx.h"
#include "Tile.h"
#include "BmpMgrS2.h"
#include "ScrollMgr.h"

CTileS2::CTileS2()
{
}


CTileS2::~CTileS2()
{
	Release();
}

void CTileS2::Initialize(void)
{
	m_fCX = TILECX;
	m_fCY = TILECY;

	CBmpMgrS2::Get_Instance()->Insert_Bmp(L"../Resource/Test.bmp", L"Test");

}

int CTileS2::Update(void)
{

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CTileS2::Late_Update(void)
{
}

void CTileS2::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	HDC		hMemDC = CBmpMgrS2::Get_Instance()->Find_Img(L"Test");

	BitBlt(hDC,
		m_tRect.left + iScrollX,
		m_tRect.top + iScrollY,
		TILECX,
		TILECY,
		hMemDC,
		TILECX * m_iDrawID,
		0,
		SRCCOPY);
}

void CTileS2::Release(void)
{
}
