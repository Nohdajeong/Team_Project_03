#pragma once
#include "BitMapS2.h"

class CBmpMgrS2
{
private:
	CBmpMgrS2();
	~CBmpMgrS2();

public:
	void		Insert_Bmp(const TCHAR* pFilePath, const TCHAR* pImgKey);
	HDC			Find_Img(const TCHAR* pImgKey);
	void		Release();

public:
	static CBmpMgrS2* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CBmpMgrS2;
		}

		return m_pInstance;
	}
	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CBmpMgrS2* m_pInstance;
	map<const TCHAR*, CBitMapS2*>			m_mapBit;

};

