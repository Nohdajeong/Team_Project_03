#include "stdafx.h"
#include "Print.h"
#include "KeyMgrS2.h"
#include "BmpMgrS2.h"

CPrint::CPrint()
{
}

CPrint::~CPrint()
{
	Release();
}

void CPrint::Initialize()
{
	m_tInfo.vPos = { 70.f, 400.f, 0.f };

	m_fCX = 120.f;
	m_fCY = 120.f;

	m_fSpeed = 3.f;

	CBmpMgrS2::Get_Instance()->Insert_Bmp(L"../Resource/NoteBook.bmp", L"NoteBook");

	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 1;
	m_tFrame.iMotion = 0;
	m_tFrame.dwSpeed = 300;
	m_tFrame.dwTime = (DWORD)GetTickCount64();


	m_eRender = GAMEOBJECT;
}

int CPrint::Update()
{
	__super::Move_Frame();

	return OBJ_NOEVENT;
}

void CPrint::Late_Update()
{
}

void CPrint::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgrS2::Get_Instance()->Find_Img(L"NoteBook");

		GdiTransparentBlt(hDC,
			(int)m_tInfo.vPos.x, // ���� ���� ��ġ X,Y ��ǥ
			(int)m_tInfo.vPos.y,
			m_fCX,	// ���� ���� ����, ���� ����
			m_fCY,
			hMemDC,			// ��Ʈ�� �̹����� ��� �ִ� DC
			m_tFrame.iFrameStart * m_fCX,					// ��Ʈ���� ����� ���� X,Y��ǥ
			m_tFrame.iMotion * m_fCY,
			m_fCX,		// ����� ��Ʈ���� ����, ���� ������
			m_fCY,
			RGB(195, 134, 255)); // �����ϰ��� �ϴ� ����

}

void CPrint::Release()
{
}