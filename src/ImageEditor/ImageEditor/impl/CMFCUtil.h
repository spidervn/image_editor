#pragma once

class CMFCUtil
{
public:
	static CMFCToolBarButton* getButtonByID(CMFCToolBar* pToolbar, UINT nID);

	static int getButtonIndexByID(CMFCToolBar* pToolbar, UINT nID);

	static int setStyleToolbarButton(CMFCToolBar* pToolbar, UINT nID, UINT style);
};

