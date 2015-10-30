
// TexturePackerView.cpp : CMainView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CMainView ����/����

CMainView::CMainView()
	: CFormView(CMainView::IDD)
{
	// TODO: �ڴ˴���ӹ������

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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void CMainView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	TabInit();
}


// CMainView ���

#ifdef _DEBUG
void CMainView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMainView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTexturePackerDoc* CMainView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTexturePackerDoc)));
	return (CTexturePackerDoc*)m_pDocument;
}
#endif //_DEBUG


// CMainView ��Ϣ�������
void CMainView::TabInit()
{
	m_TabView.InsertItem(0, _T("ͼƬ�����"));
	m_TabView.InsertItem(1, _T("�����༭��"));
	m_TabView.SetItemSize(CSize(100, 30));

	RECT rect;

	GetClientRect(&rect);

	m_TabView.AdjustRect(FALSE, &rect);


	BOOL result = m_edtiorWnd->Create(nullptr, _T("�༭��"), WS_CHILD | WS_BORDER | WS_VISIBLE, 
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
