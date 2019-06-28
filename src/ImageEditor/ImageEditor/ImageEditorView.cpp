
// ImageEditorView.cpp : implementation of the CImageEditorView class
//

#include "stdafx.h"
#include "ImageEditor.h"
#include "ImageEditorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageEditorView

CImageEditorView::CImageEditorView()
{
}

CImageEditorView::~CImageEditorView()
{
}


BEGIN_MESSAGE_MAP(CImageEditorView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_CMD_HISTOGRAM, &CImageEditorView::OnCmdHistogram)
	ON_COMMAND(ID_CMD_OPEN_IMAGE, &CImageEditorView::OnCmdOpenImage)
END_MESSAGE_MAP()



// CImageEditorView message handlers

BOOL CImageEditorView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CImageEditorView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
}



void CImageEditorView::OnCmdHistogram()
{
	// TODO: Add your command handler code here
	
}


void CImageEditorView::OnCmdOpenImage()
{
	// TODO: Add your command handler code here

}
