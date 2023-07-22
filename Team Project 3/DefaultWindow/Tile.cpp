#include "stdafx.h"
#include "Tile.h"
#include "BmpMgrS2.h"

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
}

void CTileS2::Release(void)
{
}
