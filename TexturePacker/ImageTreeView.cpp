// ImageTreeView.cpp : 实现文件
//

#include "stdafx.h"
#include "TexturePacker.h"
#include "ImageTreeView.h"


ImageTreeView* ImageTreeView::m_instance = nullptr;

// ImageTreeView

IMPLEMENT_DYNCREATE(ImageTreeView, CTreeView)

ImageTreeView::ImageTreeView()
	:m_isInit(false)
{
	m_instance = this;
}

ImageTreeView::~ImageTreeView()
{
}



BEGIN_MESSAGE_MAP(ImageTreeView, CTreeView)
	ON_WM_SIZE()
END_MESSAGE_MAP()



// ImageTreeView 消息处理程序


void ImageTreeView::OnSize(UINT nType, int cx, int cy)
{
	CTreeView::OnSize(nType, cx, cy);
	
	if (!m_isInit)
	{
		init();
		m_isInit = true;
	}
}

void ImageTreeView::setViewName(const TCHAR* view_name)
{
	m_ViewName = view_name;
}

const CString& ImageTreeView::getViewName() const
{
	return m_ViewName;
}

void ImageTreeView::init()
{
	TVINSERTSTRUCT tvInsert;
	tvInsert.hParent = NULL;
	tvInsert.hInsertAfter = NULL;
	tvInsert.item.mask = TVIF_TEXT;
	tvInsert.item.pszText = _T("United States");

	HTREEITEM hCountry = GetTreeCtrl().InsertItem(&tvInsert);

	// Insert subitems of that root. Pennsylvania is 
	// a state in the United States, so its item will be a child 
	// of the United States item. We won't set any image or states, 
	// so we supply only the TVIF_TEXT mask flag. This 
	// override provides nearly complete control over the 
	// insertion operation without the tedium of initializing 
	// a structure. If you're going to add lots of items 
	// to a tree, you might prefer the structure override 
	// as it affords you a performance win by allowing you 
	// to initialize some fields of the structure only once, 
	// outside of your insertion loop.

	HTREEITEM hPA = GetTreeCtrl().InsertItem(TVIF_TEXT,
		_T("Pennsylvania"), 0, 0, 0, 0, 0, hCountry, NULL);

	// Insert the "Washington" item and assure that it is
	// inserted after the "Pennsylvania" item. This override is 
	// more appropriate for conveniently inserting items with  
	// images.

	HTREEITEM hWA = GetTreeCtrl().InsertItem(_T("Washington"),
		0, 0, hCountry, hPA);

	// We'll add some cities under each of the states. 
	// The override used here is most appropriate 
	// for inserting text-only items.
	
	GetTreeCtrl().InsertItem(_T("Pittsburgh"), hPA, TVI_SORT);
	GetTreeCtrl().InsertItem(_T("Harrisburg"), hPA, TVI_SORT);
	GetTreeCtrl().InsertItem(_T("Altoona"), hPA, TVI_SORT);

	GetTreeCtrl().InsertItem(_T("Seattle"), hWA, TVI_SORT);
	GetTreeCtrl().InsertItem(_T("Kalaloch"), hWA, TVI_SORT);
	GetTreeCtrl().InsertItem(_T("Yakima"), hWA, TVI_SORT);

}
