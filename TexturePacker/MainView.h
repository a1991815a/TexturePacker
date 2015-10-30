
// TexturePackerView.h : CMainView 类的接口
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "EditorWnd.h"


class CMainView : public CFormView
{
protected: // 仅从序列化创建
	CMainView();
	DECLARE_DYNCREATE(CMainView)

public:
	enum{ IDD = IDD_TEXTUREPACKER_FORM };

// 特性
public:
	CTexturePackerDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CMainView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
// 生成的消息映射函数
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

#ifndef _DEBUG  // TexturePackerView.cpp 中的调试版本
inline CTexturePackerDoc* CMainView::GetDocument() const
   { return reinterpret_cast<CTexturePackerDoc*>(m_pDocument); }
#endif

