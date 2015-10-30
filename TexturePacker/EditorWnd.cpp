// EditorWnd.cpp : 实现文件
//

#include "stdafx.h"
#include "TexturePacker.h"
#include "EditorWnd.h"
#include "ImageTreeView.h"
#include "DXRenderWnd.h"


// EditorWnd

IMPLEMENT_DYNCREATE(EditorWnd, CFrameWnd)

EditorWnd::EditorWnd()
{
	
}

EditorWnd::~EditorWnd()
{
}


BOOL EditorWnd::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	BOOL result = FALSE;
	result = m_splitWnd.CreateStatic(this, 1, 2, WS_CHILD | WS_VISIBLE | WS_BORDER);
	result = m_splitWnd.CreateView(0, 0, RUNTIME_CLASS(ImageTreeView), CSize(300, 0), pContext);
	packerFileView = ImageTreeView::m_instance;
	result = m_splitWnd.CreateView(0, 1, RUNTIME_CLASS(DXRenderWnd), CSize(0, 0), pContext);
	LargeImageView = DXRenderWnd::m_instance;

	return result;
}

BEGIN_MESSAGE_MAP(EditorWnd, CFrameWnd)
END_MESSAGE_MAP()