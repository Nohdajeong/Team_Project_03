#pragma once
#include "Obj.h"
class CBlockI :
    public CObj
{
public:
    CBlockI();
    virtual ~CBlockI();

public:
    virtual void Initialize() override;
    virtual int Update() override;
    virtual void Late_Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

private:
    void	    Key_Input();

private:
    D3DXVECTOR3		m_vPoint[4];
    D3DXVECTOR3		m_vOriginalPoint[4];
};
