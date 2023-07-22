#pragma once

#include "Obj.h"

template<typename T>
class CAbstractFactoryS2
{
public:
	CAbstractFactoryS2() {}
	~CAbstractFactoryS2() {}

public:
	static CObj* Create()
	{
		CObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static CObj* Create(float _fX, float _fY)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);

		return pObj;
	}
};
