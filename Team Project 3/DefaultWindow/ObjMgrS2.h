#pragma once

#include "Define.h"
#include "ObjS2.h"

class CObjMgrS2
{
private:
	CObjMgrS2();
	~CObjMgrS2();

public:
	CObjS2* Get_Player() { return m_ObjList[PLAYER].front(); }
	CObjS2* Get_Target(OBJID eID, CObjS2* pInstance);

	list<CObjS2*>	Get_Objects(OBJID eId) { return m_ObjList[eId]; }

public:
	void		Add_Object(OBJID eID, CObjS2* pInstance);
	int			Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();

	void		Delete_ID(OBJID eID);

public:
	static CObjMgrS2* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CObjMgrS2;
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
	list<CObjS2*>	m_ObjList[OBJID_END];
	list<CObjS2*>	m_RenderList[RENDER_END];

	static CObjMgrS2* m_pInstance;
};

// 1. ���� �̻��� �����(���� ����� ��ü�� Ž���Ͽ� ����)

// 2. ���� �׸��� ���� ��ǥ�� �������� ���� Ÿ�⸦ �����϶�
// '�� ���� ������ ������ ������' ������ ��