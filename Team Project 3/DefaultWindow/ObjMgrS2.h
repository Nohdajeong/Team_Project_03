#pragma once

#include "Define.h"
#include "Obj.h"

class CObjMgrS2
{
private:
	CObjMgrS2();
	~CObjMgrS2();

public:
	CObj* Get_Player() { return m_ObjList[PLAYER].front(); }
	CObj* Get_Target(OBJID eID, CObj* pInstance);

public:
	void		Add_Object(OBJID eID, CObj* pInstance);
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
	list<CObj*>	m_ObjList[OBJID_END];
	list<CObj*>	m_RenderList[RENDER_END];

	static CObjMgrS2* m_pInstance;
};

// 1. ���� �̻��� �����(���� ����� ��ü�� Ž���Ͽ� ����)

// 2. ���� �׸��� ���� ��ǥ�� �������� ���� Ÿ�⸦ �����϶�
// '�� ���� ������ ������ ������' ������ ��