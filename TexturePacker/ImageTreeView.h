#pragma once


// ImageTreeView

class ImageTreeView : public CTreeView
{
	DECLARE_DYNCREATE(ImageTreeView)

public:
	ImageTreeView();
	virtual ~ImageTreeView();
	static ImageTreeView* m_instance;


protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);


	void setViewName(const TCHAR* view_name);
	const CString& getViewName() const;

	void init();
private:
	CString		m_ViewName;
	bool		m_isInit;
};


