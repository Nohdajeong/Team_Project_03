#pragma once

#include "ObjS2.h"

class CCollisionMgrS2
{
public:
	CCollisionMgrS2();
	~CCollisionMgrS2();

public:
	static void	Collision_Sphere(list<CObjS2*> _Dst, list<CObjS2*> _Src);
	static bool	Check_Sphere(CObjS2* _Dst, CObjS2* _Src);

	static D3DXVECTOR3 Vector_Reset(CObjS2* _Dst);

public:
	static bool	Collison_Sphere_Check(list<CObjS2*> _Dst, list<CObjS2*> _Src);
};

