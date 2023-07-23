#include "stdafx.h"
#include "CollisionMgrS2.h"


CCollisionMgrS2::CCollisionMgrS2()
{
}


CCollisionMgrS2::~CCollisionMgrS2()
{
}


void CCollisionMgrS2::Collision_Sphere(list<CObjS2*> _Dst, list<CObjS2*> _Src)
{

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Sphere(Dst, Src))
			{
				if (Dst->Get_Info().vPos.y > Src->Get_Info().vPos.y)
					Src->Set_Pos(Vector_Reset(Src).x, Vector_Reset(Dst).y - 60.f);
				else
					Src->Set_Pos(Vector_Reset(Src).x, Vector_Reset(Src).y);
			}
		}
	}
}

bool CCollisionMgrS2::Check_Sphere(CObjS2* _Dst, CObjS2* _Src)
{
	float	fWidth = abs(_Dst->Get_Info().vPos.x - _Src->Get_Info().vPos.x);
	float	fHeight = _Dst->Get_Info().vPos.y - _Src->Get_Info().vPos.y;

	float	fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

	float	fRadius = (_Dst->Get_fCX() + _Src->Get_fCX()) * 0.5f;

	return fDiagonal <= fRadius;

	return false;
}

D3DXVECTOR3 CCollisionMgrS2::Vector_Reset(CObjS2* _Dst)
{
	D3DXVECTOR3		m_vPrepos;

	m_vPrepos.x = _Dst->Get_Info().vPrepos.x;
	m_vPrepos.y = _Dst->Get_Info().vPrepos.y;

	return m_vPrepos;
}

bool CCollisionMgrS2::Collison_Sphere_Check(list<CObjS2*> _Dst, list<CObjS2*> _Src)
{
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (Check_Sphere(Dst, Src))
			{
				return true;
			}
		}
	}

	return false;
}
