#pragma once

#include "Tile.h"

class CTileMgrS2
{
private:
	CTileMgrS2();
	~CTileMgrS2();

public:
	void Initialize();
	void Update();
	void Late_Update();
	void Render(HDC hDC);
	void Release();

	void	Picking_Tile(POINT pt, int _iDrawID, int _iOption);
	
	void	Save_Tile();
	void	Load_Tile();
public:
	static CTileMgrS2*		Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CTileMgrS2;
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
	static CTileMgrS2*		m_pInstance;
	vector<CObjS2*>			m_vecTile;

};

