
// ImageEditorView.h : interface of the CImageEditorView class
//


#pragma once

#include <ImageEngine\common\business_struct.h>

// CImageEditorView window

class CImageEditorView : public CWnd
{
// Construction
public:
	CImageEditorView();

protected:
// Attributes
	ImgObject img;
	ViewModel model;

// Attributes
public:

// Operations
public:
	int openFile(CString file);

// Overrides
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);


// Implementation
public:
	virtual ~CImageEditorView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCmdHistogram();
	afx_msg void OnCmdOpenImage();
};

