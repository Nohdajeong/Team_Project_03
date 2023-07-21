#include "stdafx.h"
#include "LineMgr.h"
#include "KeyMgr.h"
#include "ScrollMgr.h"
#include "ObjMgr.h"

CLineMgr* CLineMgr::m_pInstance = nullptr;

CLineMgr::CLineMgr()
{
}


CLineMgr::~CLineMgr()
{
	Release();
}

bool CLineMgr::Collision_Line(float& fX, float* pY, int _distance)
{
	if (m_LineList.empty())
		return false;

	CObj* pPlayer = CObjMgr::Get_Instance()->Get_Player();;

	CLine* pTarget = nullptr;
	float minDistance = 100000.f;

	for (auto& iter : m_LineList)
	{
		if (iter->Get_Info().tLpoint.fX <= fX &&
			iter->Get_Info().tRpoint.fX > fX) 
		{
			float	x1 = iter->Get_Info().tLpoint.fX;
			float	x2 = iter->Get_Info().tRpoint.fX;

			float	y1 = iter->Get_Info().tLpoint.fY;
			float	y2 = iter->Get_Info().tRpoint.fY;

			float	y = ((y2 - y1) / (x2 - x1)) * (fX - x1) + y1;

			float distance = abs(y - pPlayer->Get_Info().vPos.y);
			if (minDistance > distance  && _distance > distance)
			{
				pTarget = iter;
				minDistance = distance;
			}
		}	
	}

	if (!pTarget)
		return false;

	float	x1 = pTarget->Get_Info().tLpoint.fX;
	float	x2 = pTarget->Get_Info().tRpoint.fX;

	float	y1 = pTarget->Get_Info().tLpoint.fY;
	float	y2 = pTarget->Get_Info().tRpoint.fY;

	*pY = ((y2 - y1) / (x2 - x1)) * (fX - x1) + y1;

	return true;
}





void CLineMgr::Add_Line(LINEPOINT _p1, LINEPOINT _p2)
{
	m_LineList.push_back(new CLine(_p1, _p2));
}


void CLineMgr::Load_Line()
{
	Release();

	HANDLE		hFile = CreateFile(L"../Data/Line.dat",		// ������ ���
		GENERIC_READ,	// ���� ������ ���(GENERIC_READ : �б� ���� ���)
		NULL, // �������, ������ �����ִ� ���¿��� �ٸ� ���μ����� ������ �� �㰡�� ���ΰ�, NULL�̸� �������� �ʰڴ�.
		NULL, // ���ȼӼ�, NULL�� ��� �⺻ ���� ����
		OPEN_EXISTING,  // ���� ���� ���, CREATE_ALWAYS : ������ ���ٸ� ����, ������ �ִ� ��� ���� ����, OPEN_EXITING : ������ ���� ��쿡�� ����
		FILE_ATTRIBUTE_NORMAL, // ���� �Ӽ� : FILE_ATTRIBUTE_NORMAL �ƹ��� �Ӽ��� ���� �Ϲ����� ���ϻ��� 
		NULL); // ������ ������ �Ӽ��� ������ ���ø� ����, ������� �ʱ� ������ NULL

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"���� ����", _T("����"), MB_OK);
		return;
	}

	DWORD		dwByte = 0;
	LINE		tInfo{};

	while (true)
	{
		ReadFile(hFile, &tInfo, sizeof(LINE), &dwByte, nullptr);

		if (0 == dwByte)
			break;

		m_LineList.push_back(new CLine(tInfo));
	}

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"�ҷ����� ����", _T("����"), MB_OK);
}


void CLineMgr::Initialize()
{
}

int CLineMgr::Update()
{
	POINT	pt{};

	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScollX();

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
	{
		if ((!m_tLintPoint[0].fX) && !(m_tLintPoint[0].fY))
		{
			m_tLintPoint[0].fX = float(pt.x);
			m_tLintPoint[0].fY = float(pt.y);
		}
		else
		{
			m_tLintPoint[1].fX = float(pt.x);
			m_tLintPoint[1].fY = float(pt.y);

			LINE	tInfo{ m_tLintPoint[0], m_tLintPoint[1] };
			m_LineList.push_back(new CLine(tInfo));

			m_tLintPoint[0].fX = m_tLintPoint[1].fX;
			m_tLintPoint[0].fY = m_tLintPoint[1].fY;
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_RBUTTON))
	{
		m_tLintPoint[0].fX = float(pt.x);
		m_tLintPoint[0].fY = float(pt.y);
	}

	if (CKeyMgr::Get_Instance()->Key_Down('S'))
		Load_Line();

	return 0;
}

void CLineMgr::Late_Update()
{

}

void CLineMgr::Render(HDC hDC)
{
	for (auto& iter : m_LineList)
		iter->Render(hDC);
}

void CLineMgr::Release()
{
	for_each(m_LineList.begin(), m_LineList.end(), CDeleteObj());
	m_LineList.clear();
}
