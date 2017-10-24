/****************************************************************************************************************
 *    Date    : 2017/10/07 16:43
 *
 *    Author  : Smile
 *    Contact : smile@illidan.org
 *
 *    Brief   : 最简单的MFC程序 - 带有窗口的 - 带有消息的（使用重载）
 *
 ****************************************************************************************************************/
#include <afxwin.h>
#include <afxframewndex.h>
#include <afxribbonbar.h>
#include <afxribbonstatusbar.h>
#include <afxbaseribbonelement.h>
#include <afxRibbonLabel.h>
#include <afxribbonbutton.h>
#include <afxribbonstatusbarpane.h>

#include "resource.h"

class MyFrameWnd : public CFrameWndEx
{
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT);

	afx_msg void OnAbout();
	afx_msg void OnExit();
	afx_msg void OnOpenFile();
	afx_msg void OnCopy();
private:
	CMFCRibbonBar m_RibbonBar;
	CMFCRibbonStatusBar m_RibbonStatusBar;
};

BEGIN_MESSAGE_MAP(MyFrameWnd, CFrameWndEx)
	ON_WM_CREATE()
	ON_COMMAND(IDB_ABOUT, OnAbout)
	ON_COMMAND(IDB_EXIT, OnExit)
	ON_COMMAND(IDB_OPENFILE, OnOpenFile)
	ON_COMMAND(IDB_COPY, OnCopy)
END_MESSAGE_MAP()

afx_msg int MyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	m_RibbonBar.Create(this);
	m_RibbonBar.LoadFromResource(IDR_RIBBON1);

	m_RibbonStatusBar.Create(this);
	m_RibbonStatusBar.AddElement(new CMFCRibbonLabel(TEXT("About标签")), TEXT("这是一个About标签"), TRUE);
	m_RibbonStatusBar.AddElement(new CMFCRibbonButton(IDB_ABOUT, TEXT("About按钮")), TEXT("这是一个About按钮"), TRUE);
	m_RibbonStatusBar.AddElement(new CMFCRibbonStatusBarPane(IDB_ABOUT, TEXT("About片")), TEXT("这是一个About片"), TRUE);

	m_RibbonStatusBar.GetElement(0)->SetText(TEXT("已经修改了内容。"));

	return CFrameWndEx::OnCreate(lpCreateStruct);
}

afx_msg void MyFrameWnd::OnAbout()
{
	AfxMessageBox(TEXT("OnAbout!"));
}

afx_msg void MyFrameWnd::OnExit()
{
	AfxMessageBox(TEXT("OnExit!"));
}

afx_msg void MyFrameWnd::OnOpenFile()
{
	AfxMessageBox(TEXT("OnOpenFile!"));
}

afx_msg void MyFrameWnd::OnCopy()
{
	AfxMessageBox(TEXT("OnCopy!"));
}

class MyApp : public CWinApp
{
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();
};

BEGIN_MESSAGE_MAP(MyApp, CWinApp)
END_MESSAGE_MAP()

BOOL MyApp::InitInstance()
{
	AfxOleInit();

	CFrameWnd* pFrameWnd = new MyFrameWnd;
	this->m_pMainWnd = pFrameWnd;

	pFrameWnd->Create(NULL, TEXT("illidan"));
	pFrameWnd->ShowWindow(SW_SHOW);
	pFrameWnd->UpdateWindow();

	return TRUE;
}

MyApp app;
