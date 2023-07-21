#pragma once

#include "Define.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	const INFO&			Get_Info() const { return m_tInfo; }
	bool				Get_Dead() { return m_bDead; }
	float				Get_Speed() { return m_fSpeed; }


	RENDERID		Get_RenderID() { return m_eRender; }


public:
	void				Set_Dead() { m_bDead = true; }
	void				Set_Pos(float _fX, float _fY)
	{
		m_tInfo.vPos.x = _fX;
		m_tInfo.vPos.y = _fY;
	}


public:
	virtual void		Initialize()	PURE;
	virtual int			Update()		PURE;
	virtual void		Late_Update()	PURE;
	virtual void		Render(HDC hDC)	PURE;
	virtual void		Release()		PURE;

protected:
	INFO		m_tInfo;
	RENDERID	m_eRender;
	DIRECTION	m_eDir;
	FRAME		m_tFrame;

	TCHAR* m_pFrameKey;

	float		m_fSpeed;
	float		m_fAngle;

	bool		m_bDead;
};

