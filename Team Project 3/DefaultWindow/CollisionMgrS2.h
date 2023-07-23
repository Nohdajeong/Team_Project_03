#pragma once

#include "Obj.h"

class CCollisionMgrS2
{
public:
	CCollisionMgrS2();
	~CCollisionMgrS2();

public:
	static void	Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src);
	static void	Collision_RectEx(list<CObj*> _Dst, list<CObj*> _Src);
	static bool	Check_Rect(CObj* _Dst, CObj* _Src, float* _pX, float* _pY);

	static void	Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src);
	static bool	Check_Sphere(CObj* _Dst, CObj* _Src);

	static D3DXVECTOR3 Vector_Reset(CObj* _Dst);

public:
	static bool	Collison_Sphere_Check(list<CObj*> _Dst, list<CObj*> _Src);
};

