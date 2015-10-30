// DXRenderWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "TexturePacker.h"
#include "DXRenderWnd.h"


DXRenderWnd* DXRenderWnd::m_instance = nullptr;

// DXRenderWnd

IMPLEMENT_DYNCREATE(DXRenderWnd, CView)

DXRenderWnd::DXRenderWnd()
{
	m_instance = this;
}

DXRenderWnd::~DXRenderWnd()
{
}

BEGIN_MESSAGE_MAP(DXRenderWnd, CWnd)
END_MESSAGE_MAP()

void DXRenderWnd::OnDraw(CDC* pDC)
{
	
}
