#include "stdafx.h"
#include "SceneMgr.h"

#include "Tetris.h"

CSceneMgr*	CSceneMgr::m_pInstance = nullptr;

CSceneMgr::CSceneMgr()
	: m_eCurScene(GAME), m_ePreScene(SCENE_END), m_pScene(nullptr)
{
}

CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::Scene_Change(SCENEID eScene)
{
	m_eCurScene = eScene;

	if (m_ePreScene != m_eCurScene)
	{
		Safe_Delete(m_pScene);

		switch (m_eCurScene)
		{
		case GAME:
			m_pScene = new CTetris;
			break;
		}

		m_pScene->Initialize();

		m_ePreScene = m_eCurScene;
	}

}

void CSceneMgr::Update()
{
	m_pScene->Update();
}

void CSceneMgr::Late_Update()
{
	m_pScene->Late_Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
}

void CSceneMgr::Release()
{
	Safe_Delete(m_pScene);
}