#pragma once
#include "stdafx.h"

#define		WINCX		800
#define		WINCY		600

#define		VK_MAX		0xff

#define		PURE		= 0
#define		PI			3.141592f

#define		OBJ_DEAD	 1
#define		OBJ_NOEVENT	 0

#define		TILEX		30
#define		TILEY		20

#define		TILECX		60
#define		TILECY		60


extern	HWND	g_hWnd;

typedef struct tagInfo
{
	D3DXVECTOR3		vPos;
	D3DXVECTOR3		vPrepos;
	
	D3DXVECTOR3		vDir;
	D3DXVECTOR3		vLook;

	D3DXMATRIX		matWorld;
	
}INFO;

static D3DXVECTOR3		Get_Mouse()
{
	POINT		Pt{};

	GetCursorPos(&Pt);
	ScreenToClient(g_hWnd, &Pt);

	return D3DXVECTOR3((float)Pt.x, (float)Pt.y, 0.f);
}

enum DIRECTION { LEFT, RIGHT, UP, DOWN, DIR_END };
enum OBJID { PLAYBOX, PLAYER, BULLET, MONSTER, MOUSE, SHIELD, BUTTON, 
			 BLOCKJ, BLOCKU, BLOCKS, BLOCKI, BLOCKN, OBJID_END };
enum SCENEID { SC_LOGO, SC_STAGE1, SC_STAGE2, SC_STAGE3, SC_STAGE4, SC_ENDING, SC_END };
enum RENDERID { BACKGROUND, UI, GAMEOBJECT, EFFECT, RENDER_END };
enum CHANNELID { SOUND_EFFECT, SOUND_BGM, MAXCHANNEL };


class CTag_Finder
{
public:
	CTag_Finder(const TCHAR* pString) : m_pString(pString) {}
public:
	template<typename T>
	bool operator()(T& Pair)
	{
		return !lstrcmp(m_pString, Pair.first);
	}

private:
	const TCHAR* m_pString;
};

class CDeleteMap
{
public:
	template<typename T>
	void operator()(T& Pair)
	{
		if (Pair.second)
		{
			delete Pair.second;
			Pair.second = nullptr;
		}
	}
};

template<typename T>
void		Safe_Delete(T& Temp)
{
	if(Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

struct DeleteObj
{
	template<typename T>
	void operator()(T& Temp)
	{
		if(Temp)
		{
			delete Temp;
			Temp = nullptr;
		}
	}
};

typedef struct tagFrame
{
	int			iFrameStart;
	int			iFrameEnd;
	int			iMotion;

	DWORD		dwSpeed;
	DWORD		dwTime;

}FRAME;

