#pragma once

#include "Define.h"

class CBitMap
{
public:
	CBitMap();
	~CBitMap();

public:
	HDC			Get_MemDC() { return m_hMemDC; }

	void		Load_Bmp(const TCHAR* pFilePath);
	void		Release();

private:
	HDC			m_hMemDC;
	HBITMAP		m_hBitMap;
	HBITMAP		m_hOldBmp;

};

// DDB(Device Dependent Bitmap) : ��ġ�� �������� ��Ʈ�� ���� ����, �̹����� ũ��, ���� �� �⺻���� ������ �̹��� �����ͷ� �����Ǿ� �־� �پ��� �ػ��� ��ġ�� �������ϰ� ������ ���Ѵ�. 
// DIB(Device Independet Bitmap) : ��ġ�� �������� ��Ʈ�� ���� ����, DDB�� ���� ���� ���̺�, �ػ� ���� ���� �߰� ������ �����Ƿ� ��ġ�� ���ӵ��� �ʾ� Ȱ�뵵�� �� �������ϰ� ȣȯ���� �پ.

