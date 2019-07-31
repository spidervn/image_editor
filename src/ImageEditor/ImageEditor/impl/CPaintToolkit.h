#pragma once

#define PAINTTOOLKIT_ADDCLIPRGN_SUCCESS 0
#define PAINTTOOLKIT_ADDCLIPRGN_NOT_NEED_COMBINE 1
#define PAINTTOOLKIT_ADDCLIPRGN_FAIL 2

#define PAINTTOOLKIT_ADDCLIPRGN_ISFINE(nRetRgn) nRetRgn == PAINTTOOLKIT_ADDCLIPRGN_SUCCESS || nRetRgn == PAINTTOOLKIT_ADDCLIPRGN_NOT_NEED_COMBINE

class CPaintToolkit
{
public:
    CPaintToolkit(/* args */);
    ~CPaintToolkit();

    static int drawBitmap(CBitmap bmp, HDC hdcDest, 
                            int x_src, int y_src, 
                            int width_src,
                            int height_src,
                            int x_dst,
                            int y_dst);   // Draw bitmap on hdcDest

    static int drawBitmap(HBITMAP hBmp, HDC hdcDest,
                            int x_src, int y_src, 
                            int width_src,
                            int height_src,
                            int x_dst,
                            int y_dst);   // Draw bitmap on hdcDest

	static int addClipRgn(HDC hdc, HRGN hRgnAdd, HRGN& hOriginRgn, HRGN hRgnStoreResult);	// Union new hRgn to current Region; 
												// Return the CurrentRegion
};