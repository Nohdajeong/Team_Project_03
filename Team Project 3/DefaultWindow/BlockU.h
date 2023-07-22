#pragma once
#include "Obj.h"
class CBlockU :
    public CObj
{
public:
    CBlockU();
    virtual ~CBlockU();

public:
    virtual void Initialize() override;
    virtual int Update() override;
    virtual void Late_Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;

private:
    void	    Key_Input();
    bool		Search(CObj* _pTarget);

private:
    D3DXVECTOR3		m_vPoint[4];
    D3DXVECTOR3		m_vOriginalPoint[4];

private:
    float       m_fFirst;
};

