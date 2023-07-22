#include "stdafx.h"
#include "BmpMgrS2.h"

CBmpMgrS2* CBmpMgrS2::m_pInstance = nullptr;

CBmpMgrS2::CBmpMgrS2()
{
}


CBmpMgrS2::~CBmpMgrS2()
{
	Release();
}

void CBmpMgrS2::Insert_Bmp(const TCHAR* pFilePath, const TCHAR* pImgKey)
{
	auto iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTag_Finder(pImgKey));

	if (iter == m_mapBit.end())
	{
		CBitMapS2* pBmp = new CBitMapS2;
		pBmp->Load_Bmp(pFilePath);

		m_mapBit.insert({ pImgKey, pBmp });
	}


}

HDC CBmpMgrS2::Find_Img(const TCHAR* pImgKey)
{
	auto iter = find_if(m_mapBit.begin(), m_mapBit.end(), CTag_Finder(pImgKey));

	if (iter == m_mapBit.end())
		return nullptr;

	return iter->second->Get_MemDC();
}

void CBmpMgrS2::Release()
{
	for_each(m_mapBit.begin(), m_mapBit.end(), CDeleteMap());
	m_mapBit.clear();
}
