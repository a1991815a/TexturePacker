
// TexturePacker.h : TexturePacker Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CTexturePackerApp:
// �йش����ʵ�֣������ TexturePacker.cpp
//

class CTexturePackerApp : public CWinApp
{
public:
	CTexturePackerApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTexturePackerApp theApp;
