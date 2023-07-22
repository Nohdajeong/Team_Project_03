#include "stdafx.h"
#include "CollisionMgrS2.h"


CCollisionMgrS2::CCollisionMgrS2()
{
}


CCollisionMgrS2::~CCollisionMgrS2()
{
}

void CCollisionMgrS2::Collision_Rect(list<CObj*> _Dst, list<CObj*> _Src)
{
	/*RECT	rc{};

	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			if (IntersectRect(&rc, &(Dst->Get_Rect()), &(Src->Get_Rect())))
			{
				Dst->Set_Dead();
				Src->Set_Dead();
			}
		}
	}*/


}

void CCollisionMgrS2::Collision_RectEx(list<CObj*> _Dst, list<CObj*> _Src)
{
	//float fX = 0.f, fY = 0.f;


	//for (auto& Dst : _Dst)
	//{
	//	for (auto& Src : _Src)
	//	{
	//		if (Check_Rect(Dst, Src, &fX, &fY))
	//		{
	//			// 상하 충돌
	//			if (fX > fY)
	//			{
	//				// 상 충돌
	//				if (Dst->Get_Info().fY < Src->Get_Info().fY)
	//				{
	//					Dst->Set_PosY(-fY);
	//				}
	//				// 하 충돌
	//				else
	//				{
	//					Dst->Set_PosY(fY);
	//				}
	//			}
	//			// 좌우 충돌
	//			else
	//			{
	//				// 좌 충돌
	//				if (Dst->Get_Info().fX < Src->Get_Info().fX)
	//				{
	//					Dst->Set_PosX(-fX);
	//				}
	//				// 우 충돌
	//				else
	//				{
	//					Dst->Set_PosX(fX);
	//				}
	//			}
	//		}
	//	}
	//}
}

bool CCollisionMgrS2::Check_Rect(CObj* _Dst, CObj* _Src, float* _pX, float* _pY)
{
	/*float		fWidth = fabs(_Dst->Get_Info().fX - _Src->Get_Info().fX);
	float		fHeight = fabs(_Dst->Get_Info().fY - _Src->Get_Info().fY);

	float		fRadiusX = (_Dst->Get_Info().fCX + _Src->Get_Info().fCX) * 0.5f;
	float		fRadiusY = (_Dst->Get_Info().fCY + _Src->Get_Info().fCY) * 0.5f;

	if ((fRadiusX >= fWidth) && (fRadiusY >= fHeight))
	{
		*_pX = fRadiusX - fWidth;
		*_pY = fRadiusY - fHeight;

		return true;
	}

	return false;*/
	return false;
}

void CCollisionMgrS2::Collision_Sphere(list<CObj*> _Dst, list<CObj*> _Src)
{
	//float fX = 0.f, fY = 0.f;

	//for (auto& Dst : _Dst)
	//{
	//	for (auto& Src : _Src)
	//	{
	//		if (Check_Sphere(Dst, Src))
	//		{
	//				// 상 충돌
	//				if (Dst->Get_Info().vPos.y < Src->Get_Info().vPos.y)
	//				{
	//					Dst->Set_PosY(+fY);
	//				}
	//		}
	//	}
	//}
}

bool CCollisionMgrS2::Check_Sphere(CObj* _Dst, CObj* _Src)
{
	float	fWidth = abs(_Dst->Get_Info().vPos.x - _Src->Get_Info().vPos.x);
	float	fHeight = _Dst->Get_Info().vPos.y - _Src->Get_Info().vPos.y;

	float	fDiagonal = sqrt(fWidth * fWidth + fHeight * fHeight);

	float	fRadius = (_Dst->Get_fCX() + _Src->Get_fCX()) * 0.5f;

	return fDiagonal <= fRadius;
	return false;
}

D3DXVECTOR3 CCollisionMgrS2::Vector_Reset(CObj* _Dst)
{
	D3DXVECTOR3		m_vPrepos;

	m_vPrepos.x = _Dst->Get_Info().vPrepos.x;
	m_vPrepos.y = _Dst->Get_Info().vPrepos.y;

	return m_vPrepos;
}
