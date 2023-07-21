#pragma once

#define		WINCX		800
#define		WINCY		600

#define		PURE		= 0

#define		OBJ_DEAD	 1
#define		OBJ_NOEVENT	 0

#define		VK_MAX		0xff

#define		TILEX		30
#define		TILEY		20

#define		TILECX		64
#define		TILECY		64


extern	HWND	g_hWnd;

typedef struct tagInfo
{
	D3DXVECTOR3	vPos;

	D3DXVECTOR3	vDir;
	D3DXVECTOR3 vLook;

	D3DXMATRIX	matWorld;

}INFO;

enum DIRECTION { LEFT, RIGHT, UP, DOWN, DIR_END };

enum OBJID { PLAYER, MONSTER, BLOCK, OBJID_END };

enum RENDERID { BACKGROUND, UI, GAMEOBJECT, EFFECT, RENDER_END };

enum CHANNELID { SOUND_EFFECT, SOUND_BGM, MAXCHANNEL };

enum class JUMPSTATE { JUMP, STAND, FALL };

enum SCENEID {
	GAME,
	SCENE_END
};

static D3DXVECTOR3	Get_Mouse() {
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	return D3DXVECTOR3 { (float)pt.x, (float)pt.y, 0.f };

}


template<typename T>
void		Safe_Delete(T& Temp)
{
	if(Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}

struct CDeleteObj
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

typedef	struct tagLinePoint
{
	tagLinePoint() { ZeroMemory(this, sizeof(tagLinePoint)); }
	tagLinePoint(float _fX, float _fY) : fX(_fX), fY(_fY) {}

	float	fX;
	float	fY;

}LINEPOINT;

typedef struct tagLine
{
	tagLine() { ZeroMemory(this, sizeof(tagLine)); }
	tagLine(LINEPOINT& _tLpoint, LINEPOINT& _tRpoint)
		: tLpoint(_tLpoint), tRpoint(_tRpoint) { }

	LINEPOINT	tLpoint;
	LINEPOINT	tRpoint;

}LINE;

typedef struct tagFrame
{
	int			iFrameStart;
	int			iFrameEnd;
	int			iMotion;

	DWORD		dwSpeed;
	DWORD		dwTime;

}FRAME;
