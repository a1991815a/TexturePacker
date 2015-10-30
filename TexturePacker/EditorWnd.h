#pragma once
#include "CustomSplitWnd.h"
#include "ImageTreeView.h"
#include "DXRenderWnd.h"


// EditorWnd 框架

class EditorWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(EditorWnd)
protected:
	EditorWnd();           // 动态创建所使用的受保护的构造函数
	virtual ~EditorWnd();

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) override;


protected:
	DECLARE_MESSAGE_MAP()
public:
	CustomSplitWnd	m_splitWnd;

	ImageTreeView*	packerFileView;
	ImageTreeView*	animateFrameView;

	DXRenderWnd*	LargeImageView;
};


