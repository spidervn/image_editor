
// ImageEditorView.cpp : implementation of the CImageEditorView class
//

#include "stdafx.h"
#include "ImageEditor.h"
#include "ImageEditorView.h"

#include "impl\CPaintToolkit.h"
#include "impl\CImageFormatter.h"
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
using namespace cv;

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
	if (!model.matCurrent.empty())
	{
		// Paint here
		CPaintToolkit::drawBitmap(
			(HBITMAP)model.bmpCurrent.m_hObject,
			dc.m_hDC,
			0, 0, 
			model.w,
			model.h, 
			0, 0
		);
		
	}
}



void CImageEditorView::OnCmdHistogram()
{
	// TODO: Add your command handler code here
}

void CImageEditorView::OnCmdOpenImage()
{
	// TODO: Add your command handler code here
	CFileDialog FileDialog(TRUE, _T("*.*"),
		NULL,
		OFN_HIDEREADONLY,
		_T("Image Files: (*.bmp,*.png,*.jpg)|*.bmp|Png files|*.png||"));
	
	CString filePath;
	filePath = _T("");
	if (FileDialog.DoModal() == IDOK)
	{
		filePath = FileDialog.GetFileName();
		openFile(filePath);
	}
}

int CImageEditorView::openFile(CString file)
{
	std::string szFile = CT2A(file);
	img.img  = imread(szFile, IMREAD_COLOR);

	if (!img.img.empty())
	{
		img.w = img.img.cols;
		img.h = img.img.rows;

		model.matOrigin = img.img;
		model.matCurrent = img.img;
		model.w = img.w;
		model.h = img.h;

		IImageFormatterPtr ifp = CImageFormatterPtrNew;
		ifp->cvMat_to_CBitmap(model.matCurrent, model.bmpCurrent);

		this->Invalidate();
	}
	else
	{
		AfxMessageBox(_T("Open error!"));
	}

	return 0;
}