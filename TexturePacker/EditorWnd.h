#pragma once
#include "CustomSplitWnd.h"
#include "ImageTreeView.h"
#include "DXRenderWnd.h"


// EditorWnd ���

class EditorWnd : public CFrameWnd
{
	DECLARE_DYNCREATE(EditorWnd)
protected:
	EditorWnd();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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


