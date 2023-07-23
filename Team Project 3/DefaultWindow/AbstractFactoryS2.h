#pragma once

#include "ObjS2.h"

template<typename T>
class CAbstractFactoryS2
{
public:
	CAbstractFactoryS2() {}
	~CAbstractFactoryS2() {}

public:
	static CObjS2* Create()
	{
		CObjS2* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	static CObjS2* Create(float _fX, float _fY)
	{
		CObjS2* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);

		return pObj;
	}
};

