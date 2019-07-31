#include <stdafx.h>
#include "CMFCUtil.h"

CMFCToolBarButton* CMFCUtil::getButtonByID(CMFCToolBar* pToolbar, UINT nID)
{
	CMFCToolBarButton* pIter = NULL;
	CMFCToolBarButton* pFound = NULL;
	int i;
    for (i=0, pIter = pToolbar->GetButton(i); pIter != NULL; ++i)
    {
        UINT btnID;
        UINT nStyle;
        int iImage;
		pToolbar->GetButtonInfo(i, btnID, nStyle, iImage);

        if (btnID == nID)
        {
            pFound = pIter;
            break;
        }
    }

    return pFound;
}

int CMFCUtil::getButtonIndexByID(CMFCToolBar* pToolbar, UINT nID)
{
	CMFCToolBarButton* pIter = NULL;
	int indexFound = -1;
	int i = 0;
	for (i = 0, pIter = pToolbar->GetButton(i); pIter != NULL; ++i)
	{
		UINT btnID;
		UINT nStyle;
		int iImage;
		pToolbar->GetButtonInfo(i, btnID, nStyle, iImage);

		if (btnID == nID)
		{
			indexFound = i;
			break;
		}
	}

	return indexFound;
}

int CMFCUtil::setStyleToolbarButton(CMFCToolBar* pToolbar, UINT nID, UINT style)
{
	int iDx = getButtonIndexByID(pToolbar, nID);
	if (iDx >= 0)
	{
		pToolbar->GetButton(iDx)->SetStyle(style);
		pToolbar->InvalidateButton(iDx);
	}

	return 0;
}