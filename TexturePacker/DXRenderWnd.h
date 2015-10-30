#pragma once


// DXRenderWnd

class DXRenderWnd : public CView
{
	DECLARE_DYNCREATE(DXRenderWnd)

public:
	DXRenderWnd();
	virtual ~DXRenderWnd();

	static DXRenderWnd*	m_instance;



protected:
	DECLARE_MESSAGE_MAP()
public:

	virtual void OnDraw(CDC* pDC) override;

};


