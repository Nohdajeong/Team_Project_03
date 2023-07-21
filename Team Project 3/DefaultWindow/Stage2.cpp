#include "stdafx.h"
#include "Stage2.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "Block.h"
#include "AbstractFactory.h"
#include "KeyMgr.h"

CStage2::CStage2()
	:m_pBlock(nullptr)
{
}

CStage2::~CStage2()
{
	Release();
}

void CStage2::Initialize()
{
	m_pBlock = CAbstractFactory<CBlock>::Create();



	////CLineMgr::Get_Instance()->Initialize();

	////CTileMgr::Get_Instance()->Load_Tile();
	////CTileMgr::Get_Instance()->Initialize();

	//CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ground.bmp", L"Ground");
}

void CStage2::Update()
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE)) {
		CObjMgr::Get_Instance()->Add_Object(BLOCK, m_pBlock);
	}

	m_pBlock->Update();

	CObjMgr::Get_Instance()->Update();

}

void CStage2::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();

}

void CStage2::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	m_pBlock->Render(hDC);

	CObjMgr::Get_Instance()->Render(hDC);

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

	swprintf_s(szBuff, L"stage2");
	TextOut(hDC, 700.f, 100.f, szBuff, lstrlen(szBuff));


}

void CStage2::Release()
{
}
