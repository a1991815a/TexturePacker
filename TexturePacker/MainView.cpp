
// TexturePackerView.cpp : CMainView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "TexturePacker.h"
#endif

#include "TexturePackerDoc.h"
#include "MainView.h"
#include "EditorWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainView

IMPLEMENT_DYNCREATE(CMainView, CFormView)

BEGIN_MESSAGE_MAP(CMainView, CFormView)
	ON_WM_SIZE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_CMF_TABVIEW, &CMainView::OnTcnSelchangeCmfTabview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMainView 构造/析构

CMainView::CMainView()
	: CFormView(CMainView::IDD)
{
	// TODO: 在此处添加构造代码

}

CMainView::~CMainView()
{
}

void CMainView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CMF_TABVIEW, m_TabView);
}

BOOL CMainView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CMainView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	TabInit();
}


// CMainView 诊断

#ifdef _DEBUG
void CMainView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMainView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTexturePackerDoc* CMainView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTexturePackerDoc)));
	return (CTexturePackerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMainView 消息处理程序
void CMainView::TabInit()
{
	m_TabView.InsertItem(0, _T("图片打包器"));
	m_TabView.InsertItem(1, _T("动画编辑器"));
	m_TabView.SetItemSize(CSize(100, 30));

	RECT rect;

	GetClientRect(&rect);

	m_TabView.AdjustRect(FALSE, &rect);


	BOOL result = m_edtiorWnd->Create(nullptr, _T("编辑器"), WS_CHILD | WS_BORDER | WS_VISIBLE, 
		rect, &m_TabView);
	
	

}



void CMainView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	if(::IsWindow(m_TabView.GetSafeHwnd()))
	{

		m_TabView.SetWindowPos(nullptr, 0, 0, cx, cy, nType);

		if(::IsWindow(m_edtiorWnd->GetSafeHwnd()))
		{
			CRect rect;
			GetClientRect(&rect);
			m_TabView.AdjustRect(FALSE, &rect);
			m_edtiorWnd->SetWindowPos(nullptr, 
				rect.left, rect.top,
				rect.Width(), rect.Height(), SWP_NOZORDER);
		}
	}
		


}


void CMainView::OnTcnSelchangeCmfTabview(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
	TCHAR buffer[256] = {0};
	TCITEM sel_item;
	
	sel_item.pszText = buffer;
	sel_item.cchTextMax = 256;
	sel_item.mask = TCIF_TEXT;

	int a = m_TabView.GetCurSel();
	m_TabView.GetItem(m_TabView.GetCurSel(), &sel_item);
	OutputDebugString(sel_item.pszText);
}

int CMainView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	m_edtiorWnd = dynamic_cast<EditorWnd*>(RUNTIME_CLASS(EditorWnd)->CreateObject());

	return 0;
}
