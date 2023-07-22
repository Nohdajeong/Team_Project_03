#pragma once

#include "Obj.h"

class CTileS2 : public CObj
{
public:
	CTileS2();
	virtual ~CTileS2();

public:
	void		Set_ID(int _iDrawID, int _iOption)
	{
		m_iDrawID = _iDrawID;
		m_iOption = _iOption;
	}

	int			Get_DrawID() { return m_iDrawID; }
	int			Get_Option() { return m_iOption; }

public:
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	int			m_iDrawID = 0;
	int			m_iOption = 0;

};

