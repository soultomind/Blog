// CSharpWrapperActiveXCtrlPropPage.cpp : CCSharpWrapperActiveXCtrlPropPage 속성 페이지 클래스의 구현입니다.

#include "stdafx.h"
#include "CSharpWrapperActiveXCtrl.h"
#include "CSharpWrapperActiveXCtrlPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CCSharpWrapperActiveXCtrlPropPage, COlePropertyPage)

// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CCSharpWrapperActiveXCtrlPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CCSharpWrapperActiveXCtrlPropPage, "CSHARPWRAPPERA.CSharpWrapperAPropPage.1",
	0xac3fb637, 0x9d98, 0x40bf, 0x92, 0x5d, 0x7b, 0x28, 0x31, 0x73, 0x46, 0xc1)

// CCSharpWrapperActiveXCtrlPropPage::CCSharpWrapperActiveXCtrlPropPageFactory::UpdateRegistry -
// CCSharpWrapperActiveXCtrlPropPage에서 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CCSharpWrapperActiveXCtrlPropPage::CCSharpWrapperActiveXCtrlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CSHARPWRAPPERACTIVEXCTRL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CCSharpWrapperActiveXCtrlPropPage::CCSharpWrapperActiveXCtrlPropPage - 생성자입니다.

CCSharpWrapperActiveXCtrlPropPage::CCSharpWrapperActiveXCtrlPropPage() :
	COlePropertyPage(IDD, IDS_CSHARPWRAPPERACTIVEXCTRL_PPG_CAPTION)
{
}

// CCSharpWrapperActiveXCtrlPropPage::DoDataExchange - 페이지와 속성 사이에서 데이터를 이동시킵니다.

void CCSharpWrapperActiveXCtrlPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CCSharpWrapperActiveXCtrlPropPage 메시지 처리기입니다.
