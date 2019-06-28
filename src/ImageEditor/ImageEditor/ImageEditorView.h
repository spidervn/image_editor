
// ImageEditorView.h : interface of the CImageEditorView class
//


#pragma once


// CImageEditorView window

class CImageEditorView : public CWnd
{
// Construction
public:
	CImageEditorView();

// Attributes
public:

// Operations
public:

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

