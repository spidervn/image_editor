#include "stdafx.h"
#include "CPaintToolkit.h"

CPaintToolkit::CPaintToolkit(/* args */)
{}

CPaintToolkit::~CPaintToolkit()
{}

int CPaintToolkit::drawBitmap(CBitmap bmp, HDC hdcDest, 
                            int x_src, int y_src, 
                            int width_src,
                            int height_src,
                            int x_dst,
                            int y_dst)
{
    HDC hdcMem;
    HGDIOBJ hBmpOld;
    
    //@@1> Create HDC for Bitmap
    hdcMem = CreateCompatibleDC(hdcDest);               
    hBmpOld = SelectObject(hdcMem, bmp.m_hObject);  

    //@@2> Draw
    BitBlt(hdcDest, x_dst, y_dst, width_src, height_src, hdcMem, x_src, y_src, SRCCOPY);

    //@@3> Free resources
    SelectObject(hdcMem, hBmpOld);
    DeleteDC(hdcMem);
    return 0;
}

int CPaintToolkit::drawBitmap(HBITMAP hBmp, HDC hdcDest,
                            int x_src, int y_src, 
                            int width_src,
                            int height_src,
                            int x_dst,
                            int y_dst)
{
    CBitmap bmp;
    HDC hdcMem;
    HGDIOBJ hBmpOld;

    //@@1> Create HDC for Bitmap
    bmp.Attach(hBmp);
    hdcMem = CreateCompatibleDC(hdcDest);               
    hBmpOld = SelectObject(hdcMem, bmp.m_hObject);  

    //@@2> Draw
    if (!BitBlt(hdcDest, x_dst, y_dst, width_src, height_src, hdcMem, x_src, y_src, SRCCOPY))
	{
		// Error here
		int x = 1;
		int y = x;

		
	}

    //@@3> Free resources
    bmp.Detach();
    SelectObject(hdcMem, hBmpOld);
    DeleteDC(hdcMem);
    return 0;
}


int CPaintToolkit::addClipRgn(HDC hdc, HRGN hRgnAdd, HRGN& hOriginRgn, HRGN hRgnStoreResult)
{
	int nret = GetClipRgn(hdc, hOriginRgn);
	int ret = 1;
	HRGN hDest;

	if (nret == 0)
	{
		// No current region
		hOriginRgn = NULL;
		ret = PAINTTOOLKIT_ADDCLIPRGN_NOT_NEED_COMBINE;
		SelectClipRgn(hdc, hRgnAdd);

		return ret;	
	}
	else if (nret > 0)
	{
		HRGN hNew;
		// hNew = CreateRectRgn(0, 0, 0, 0);
		// New Region        
		if (CombineRgn(hRgnStoreResult, hRgnAdd, hOriginRgn, RGN_AND) != ERROR &&
			SelectClipRgn(hdc, hRgnStoreResult) != ERROR)
		{
			ret = PAINTTOOLKIT_ADDCLIPRGN_SUCCESS;
		}
		else
		{
			ret = PAINTTOOLKIT_ADDCLIPRGN_FAIL;
		}
	}
	else
	{
		// Error 
		ret = PAINTTOOLKIT_ADDCLIPRGN_FAIL;
	}

	return ret;
}