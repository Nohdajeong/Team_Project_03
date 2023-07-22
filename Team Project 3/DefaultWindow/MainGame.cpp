#include "stdafx.h"
#include "MainGame.h"
#include "SceneMgr.h"
#include "ObjMgrS2.h"
#include "BmpMgrS2.h"
#include "KeyMgrS2.h"

CMainGame::CMainGame()
{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_DC = GetDC(g_hWnd);
	CSceneMgr::Get_Instance()->Scene_Change(SC_STAGE2);

}

void CMainGame::Update(void)
{
	CSceneMgr::Get_Instance()->Update();

}

void CMainGame::Late_Update(void)
{
	CSceneMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render(void)
{

	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	CSceneMgr::Get_Instance()->Render(m_DC);

}

void CMainGame::Release(void)
{
	CSceneMgr::Destroy_Instance();
	CObjMgrS2::Destroy_Instance();
	CBmpMgrS2::Destroy_Instance();
	CKeyMgrS2::Destroy_Instance();

	ReleaseDC(g_hWnd, m_DC);
}
