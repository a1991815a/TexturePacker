#include "stdafx.h"
#include "CustomSplitWnd.h"

IMPLEMENT_DYNCREATE(CustomSplitWnd, CSplitterWnd);

CustomSplitWnd::CustomSplitWnd()
	:m_isDraging(false)
{

}

CustomSplitWnd::~CustomSplitWnd()
{

}

BEGIN_MESSAGE_MAP(CustomSplitWnd, CSplitterWnd)
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



void CustomSplitWnd::OnInvertTracker(const CRect& rect)
{
	// TODO: 在此添加专用代码和/或调用基类

	CSplitterWnd::OnInvertTracker(rect);
	
	if (m_isDraging)
		return;
	m_barRect = rect;
	CRect rc = rect;
	rc.InflateRect(2, 1);
	CDC* pDC = GetDC();
	HPEN hPen = (HPEN)GetStockObject(WHITE_PEN);
	HPEN hOldPen = NULL;
	if (hPen != NULL)
		hOldPen = (HPEN)SelectObject(pDC->m_hDC, hPen);

	pDC->Rectangle(&rc);
	if (hOldPen != NULL)
		SelectObject(pDC->m_hDC, hOldPen);
	ReleaseDC(pDC);
	m_isDraging = true;
}


void CustomSplitWnd::OnLButtonUp(UINT nFlags, CPoint point)
{
	CSplitterWnd::OnLButtonUp(nFlags, point);


	if (m_isDraging)
	{
		CRect rc = m_barRect;
		rc.InflateRect(2, 1);
		CDC* pDC = GetDC();
		HPEN hPen = (HPEN)GetStockObject(WHITE_PEN);
		HPEN hOldPen = NULL;
		if (hPen != NULL)
			hOldPen = (HPEN)SelectObject(pDC->m_hDC, hPen);

		pDC->Rectangle(&rc);
		if (hOldPen != NULL)
			SelectObject(pDC->m_hDC, hOldPen);
		ReleaseDC(pDC);
		m_isDraging = false;
	}
	
}
