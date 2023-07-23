#pragma once
#include "ObjS2.h"
class CPlayBox :
    public CObjS2
{
public:
    CPlayBox();
    virtual ~CPlayBox();

public:
    virtual void Initialize() override;
    virtual int Update() override;
    virtual void Late_Update() override;
    virtual void Render(HDC hDC) override;
    virtual void Release() override;


};

