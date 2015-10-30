#ifndef __CUSTOMSPLITWND__
#define __CUSTOMSPLITWND__

class CustomSplitWnd: public CSplitterWnd{
public:
	DECLARE_DYNCREATE(CustomSplitWnd);

protected:
	DECLARE_MESSAGE_MAP()

public:
	CustomSplitWnd();
	virtual ~CustomSplitWnd();
private:
	
protected:
	virtual void OnInvertTracker(const CRect& rect);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

private:
	bool	m_isDraging;			//�ָ����Ƿ������ק
	CRect	m_barRect;			//ԭ�ָ������µĺ�ӡ
};
#endif