#include "stdafx.h"
#include "MainGame.h"
#include "AbstractFactory.h"
#include "SceneMgr.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "LineMgr.h"


CMainGame::CMainGame() 
	:m_pBlock(nullptr), m_pLastBlock(nullptr), m_dwPreTime(GetTickCount64())

{
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_DC = GetDC(g_hWnd);

	m_pLastBlock = CAbstractFactory<CBlock>::Create();


	//CObjMgr::Get_Instance()->Add_Object(BLOCK, CAbstractFactory<CBlock>::Create());

	CSceneMgr::Get_Instance()->Scene_Change(GAME);

}

void CMainGame::Update(void)
{
	//m_pBlock->Update();

	CObjMgr::Get_Instance()->Update();

	CSceneMgr::Get_Instance()->Update();

}

void CMainGame::LateUpdate(void)
{
	//m_pBlock->Late_Update();
	CObjMgr::Get_Instance()->Late_Update();
	CSceneMgr::Get_Instance()->Late_Update();

}

void CMainGame::Render(void)
{
	Rectangle(m_DC, 0, 0, WINCX, WINCY);

	m_pBlock->Render(m_DC);
	//m_pLastBlock->Render(m_DC);

	CObjMgr::Get_Instance()->Render(m_DC);

	swprintf_s(szBuff, L"stage2");
	TextOut(m_DC, 700.f, 100.f, szBuff, lstrlen(szBuff));


	CSceneMgr::Get_Instance()->Render(m_DC);
}

void CMainGame::Release(void)
{
	CSceneMgr::Destroy_Instance();
	CScrollMgr::Destroy_Instance();
	CBmpMgr::Destroy_Instance();
	CKeyMgr::Destroy_Instance();

	ReleaseDC(g_hWnd, m_DC);
}

CObj* CMainGame::Create_Block()
{
	CObj* pTemp = CAbstractFactory<CBlock>::Create();

	return pTemp;
}
