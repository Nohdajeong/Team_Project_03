#include "stdafx.h"
#include "MainGame.h"
#include "SceneMgr.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "KeyMgr.h"

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

void CMainGame::Render(void)
{

	Rectangle(m_DC, 0, 0, WINCX, WINCY);
	CSceneMgr::Get_Instance()->Render(m_DC);

}

void CMainGame::Release(void)
{
	CSceneMgr::Destroy_Instance();
	CObjMgr::Destroy_Instance();
	CBmpMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();

	ReleaseDC(g_hWnd, m_DC);
}
