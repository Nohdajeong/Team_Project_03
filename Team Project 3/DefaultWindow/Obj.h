#pragma once

#include "Define.h"

class CObj abstract
{
public:
	CObj();
	virtual ~CObj();

public:
	const INFO&			Get_Info() const { return m_tInfo; }
	bool				Get_Dead() { return m_bDead; }
	float				Get_Speed() { return m_fSpeed; }

	RENDERID			Get_RenderID() { return m_eRender; }
	int					Get_DrawID() { return m_iDrawID; }

	float				Get_fCX() { return m_fCX; }
	float				Get_fCY() { return m_fCY; }

	int					Get_Score() { return m_iScore; }

public:
	void				Set_Dead() { m_bDead = true; }
	void				Set_Pos(float _fX, float _fY)
	{
		m_tInfo.vPos.x = _fX;
		m_tInfo.vPos.y = _fY;
	}

	void				Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }
	void				Set_Score(int _iScore) { m_iScore += _iScore; }

public:
	virtual void		Initialize()	PURE;
	virtual int			Update()		PURE;
	virtual void		Late_Update()	PURE;
	virtual void		Render(HDC hDC)	PURE;
	virtual void		Release()		PURE;

protected:
	void		Update_Rect();
	void		Move_Frame();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	RENDERID	m_eRender;
	DIRECTION	m_eDir;
	FRAME		m_tFrame;

	CObj*		m_pTarget;
	TCHAR*		m_pFrameKey;

	float		m_fSpeed;
	float		m_fAngle;

	bool		m_bDead;

	int			m_iDrawID = 0;
	int			m_iScore = 0;

	float		m_fCX;
	float		m_fCY;
};

