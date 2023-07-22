#include "stdafx.h"
#include "TileMgrS2.h"
#include "AbstractFactoryS2.h"
#include "ScrollMgr.h"

CTileMgrS2* CTileMgrS2::m_pInstance = nullptr;

CTileMgrS2::CTileMgrS2()
{
	m_vecTile.reserve(TILEX * TILEY);
}

CTileMgrS2::~CTileMgrS2()
{
	Release();
}

void CTileMgrS2::Initialize()
{
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			float	fX = (float)(TILECX >> 1) + (TILECX * j);
			float	fY = (float)(TILECY >> 1) + (TILECY * i);

			CObj*		pObj = CAbstractFactoryS2<CTileS2>::Create(fX, fY);
			m_vecTile.push_back(pObj);
		}
	}

}

void CTileMgrS2::Update()
{
	for (auto& iter : m_vecTile)
		iter->Update();
}

void CTileMgrS2::Late_Update()
{
	for (auto& iter : m_vecTile)
		iter->Late_Update();
}

void CTileMgrS2::Render(HDC hDC)
{
	for (auto& iter : m_vecTile)
		iter->Render(hDC);

	int iCullX = (int)abs(CScrollMgr::Get_Instance()->Get_ScollX() / TILECX);
	int iCullY = (int)abs(CScrollMgr::Get_Instance()->Get_ScollY() / TILECY);

	int	iMaxX = iCullX + WINCX / TILECX + 2; 
	int	iMaxY = iCullY + WINCY / TILECY + 2;

	for (int i = iCullY; i < iMaxY; ++i)
	{
		for (int j = iCullX; j < iMaxX; ++j)
		{
			int iIndex = i * TILEX + j;

			if(0 > iIndex || size_t(iIndex) >= m_vecTile.size())
				continue;

			m_vecTile[iIndex]->Render(hDC);
		}
	}




}

void CTileMgrS2::Release()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), 
		[](CObj* pTemp)
	{
		if (pTemp)
		{ 
			delete pTemp; 
			pTemp = nullptr; 
		}
	});
	
	m_vecTile.clear();
	m_vecTile.shrink_to_fit();
}

void CTileMgrS2::Picking_Tile(POINT pt, int _iDrawID, int _iOption)
{
	int		x = pt.x / TILECX;
	int		y = pt.y / TILECY;

	int		iIndex = y * TILEX + x;

	if (0 > iIndex || (size_t)iIndex >= m_vecTile.size())
		return;

	dynamic_cast<CTileS2*>(m_vecTile[iIndex])->Set_ID(_iDrawID, _iOption);

}

void CTileMgrS2::Save_Tile()
{
	HANDLE		hFile = CreateFile(L"../Data/Tile.dat", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return;

	int		iDrawID = 0, iOption = 0;
	DWORD	dwByte = 0;

	for (auto& iter : m_vecTile)
	{
		iDrawID = dynamic_cast<CTileS2*>(iter)->Get_DrawID();
		iOption = dynamic_cast<CTileS2*>(iter)->Get_Option();

		WriteFile(hFile, &(iter->Get_Info()), sizeof(INFO), &dwByte, NULL);
		WriteFile(hFile, &iDrawID, sizeof(int), &dwByte, NULL);
		WriteFile(hFile, &iOption, sizeof(int), &dwByte, NULL);
	}

	CloseHandle(hFile);

	MessageBox(g_hWnd, L"Tile Save", L"성공", MB_OK);
}

void CTileMgrS2::Load_Tile()
{
	HANDLE		hFile = CreateFile(L"../Data/Tile.dat", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == hFile)
		return;

	INFO	tInfo{};
	int		iDrawID = 0, iOption = 0;
	DWORD	dwByte = 0;

	Release();

	while(true)
	{
		ReadFile(hFile, &tInfo, sizeof(INFO), &dwByte, NULL);
		ReadFile(hFile, &iDrawID, sizeof(int), &dwByte, NULL);
		ReadFile(hFile, &iOption, sizeof(int), &dwByte, NULL);

		if (0 == dwByte)
			break;

		CObj*	pObj = CAbstractFactoryS2<CTileS2>::Create(tInfo.vPos.x, tInfo.vPos.y);
		dynamic_cast<CTileS2*>(pObj)->Set_ID(iDrawID, iOption);

		m_vecTile.push_back(pObj);
	}

	CloseHandle(hFile);

	MessageBox(g_hWnd, L"Tile Load", L"성공", MB_OK);
}
