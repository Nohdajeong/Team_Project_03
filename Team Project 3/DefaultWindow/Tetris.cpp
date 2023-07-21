#include "stdafx.h"
#include "Tetris.h"
#include "Block.h"

CTetris::CTetris()
{
}

CTetris::~CTetris()
{
	Release();
}

void CTetris::Initialize(void)
{


}

void CTetris::Update(void)
{

}

void CTetris::Late_Update(void)
{
}

void CTetris::Render(HDC hDC)
{

}

void CTetris::Release(void)
{
	Safe_Delete<CObj*>(m_pBlock);

}
