// CSharpActiveXCtrlWrapperPropPage.cpp : CCSharpActiveXCtrlWrapperPropPage 속성 페이지 클래스의 구현입니다.

#include "stdafx.h"
#include "CSharpActiveXCtrlWrapper.h"
#include "CSharpActiveXCtrlWrapperPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CCSharpActiveXCtrlWrapperPropPage, COlePropertyPage)

// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CCSharpActiveXCtrlWrapperPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CCSharpActiveXCtrlWrapperPropPage, "CSHARPACTIVEXC.CSharpActiveXCPropPage.1",
	0xb1c600fc, 0xab8e, 0x4aff, 0xbd, 0xf0, 0x8e, 0xae, 0xe, 0xad, 0x9c, 0xa5)

// CCSharpActiveXCtrlWrapperPropPage::CCSharpActiveXCtrlWrapperPropPageFactory::UpdateRegistry -
// CCSharpActiveXCtrlWrapperPropPage에서 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CCSharpActiveXCtrlWrapperPropPage::CCSharpActiveXCtrlWrapperPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CSHARPACTIVEXCTRLWRAPPER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CCSharpActiveXCtrlWrapperPropPage::CCSharpActiveXCtrlWrapperPropPage - 생성자입니다.

CCSharpActiveXCtrlWrapperPropPage::CCSharpActiveXCtrlWrapperPropPage() :
	COlePropertyPage(IDD, IDS_CSHARPACTIVEXCTRLWRAPPER_PPG_CAPTION)
{
}

// CCSharpActiveXCtrlWrapperPropPage::DoDataExchange - 페이지와 속성 사이에서 데이터를 이동시킵니다.

void CCSharpActiveXCtrlWrapperPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CCSharpActiveXCtrlWrapperPropPage 메시지 처리기입니다.
