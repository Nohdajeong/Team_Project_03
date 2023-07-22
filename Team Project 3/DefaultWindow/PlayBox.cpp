#include "stdafx.h"
#include "PlayBox.h"
#include "KeyMgrS2.h"
#include "BmpMgrS2.h"
#include "TileMgrS2.h"
#include "ScrollMgr.h"

CPlayBox::CPlayBox()
{
}

CPlayBox::~CPlayBox()
{
	Release();
}

void CPlayBox::Initialize()
{
	m_fCX = 500.f;
	m_fCY = 500.f;

	m_tInfo.vPos = { 240.f, 50.f, 0.f };
	m_tInfo.vDir = { 1.f, 0.f, 0.f };
	m_tInfo.vLook = { 0.f, -1.f, 0.f };

	m_fSpeed = 3.f;

	CBmpMgrS2::Get_Instance()->Insert_Bmp(L"../Resource/BlockBox.bmp", L"BlockBox");

	CTileMgrS2::Get_Instance()->Load_Tile();
	CTileMgrS2::Get_Instance()->Initialize();


	m_eRender = UI;
}

int CPlayBox::Update()
{	
	CTileMgrS2::Get_Instance()->Update();

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayBox::Late_Update()
{
	CTileMgrS2::Get_Instance()->Late_Update();

}

void CPlayBox::Render(HDC hDC)
{

	HDC		hMemDC = CBmpMgrS2::Get_Instance()->Find_Img(L"BlockBox");

	GdiTransparentBlt(hDC,
		(int)m_tInfo.vPos.x, // ���� ���� ��ġ X,Y ��ǥ
		(int)m_tInfo.vPos.y,
		(int)m_fCX,	// ���� ���� ����, ���� ����
		(int)m_fCY,
		hMemDC,			// ��Ʈ�� �̹����� ��� �ִ� DC
		0,					// ��Ʈ���� ����� ���� X,Y��ǥ
		0,
		(int)m_fCX,		// ����� ��Ʈ���� ����, ���� ������
		(int)m_fCY,
		RGB(195, 134, 255)); // �����ϰ��� �ϴ� ����


}

void CPlayBox::Release()
{
}