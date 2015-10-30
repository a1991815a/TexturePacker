
// TexturePackerView.h : CMainView ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "EditorWnd.h"


class CMainView : public CFormView
{
protected: // �������л�����
	CMainView();
	DECLARE_DYNCREATE(CMainView)

public:
	enum{ IDD = IDD_TEXTUREPACKER_FORM };

// ����
public:
	CTexturePackerDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CMainView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTcnSelchangeCmfTabview(NMHDR *pNMHDR, LRESULT *pResult);
public:
	CTabCtrl m_TabView;
	EditorWnd* m_edtiorWnd;
	void TabInit();





	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // TexturePackerView.cpp �еĵ��԰汾
inline CTexturePackerDoc* CMainView::GetDocument() const
   { return reinterpret_cast<CTexturePackerDoc*>(m_pDocument); }
#endif

