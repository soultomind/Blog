// CSharpActiveXCtrlWrapperPropPage.cpp : CCSharpActiveXCtrlWrapperPropPage �Ӽ� ������ Ŭ������ �����Դϴ�.

#include "stdafx.h"
#include "CSharpActiveXCtrlWrapper.h"
#include "CSharpActiveXCtrlWrapperPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CCSharpActiveXCtrlWrapperPropPage, COlePropertyPage)

// �޽��� ���Դϴ�.

BEGIN_MESSAGE_MAP(CCSharpActiveXCtrlWrapperPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Ŭ���� ���͸��� GUID�� �ʱ�ȭ�մϴ�.

IMPLEMENT_OLECREATE_EX(CCSharpActiveXCtrlWrapperPropPage, "CSHARPACTIVEXC.CSharpActiveXCPropPage.1",
	0x9ec3c446, 0xd720, 0x425b, 0xa6, 0xd4, 0x4a, 0x3c, 0xc7, 0x49, 0x75, 0xba)

// CCSharpActiveXCtrlWrapperPropPage::CCSharpActiveXCtrlWrapperPropPageFactory::UpdateRegistry -
// CCSharpActiveXCtrlWrapperPropPage���� �ý��� ������Ʈ�� �׸��� �߰��ϰų� �����մϴ�.

BOOL CCSharpActiveXCtrlWrapperPropPage::CCSharpActiveXCtrlWrapperPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CSHARPACTIVEXCTRLWRAPPER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CCSharpActiveXCtrlWrapperPropPage::CCSharpActiveXCtrlWrapperPropPage - �������Դϴ�.

CCSharpActiveXCtrlWrapperPropPage::CCSharpActiveXCtrlWrapperPropPage() :
	COlePropertyPage(IDD, IDS_CSHARPACTIVEXCTRLWRAPPER_PPG_CAPTION)
{
}

// CCSharpActiveXCtrlWrapperPropPage::DoDataExchange - �������� �Ӽ� ���̿��� �����͸� �̵���ŵ�ϴ�.

void CCSharpActiveXCtrlWrapperPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CCSharpActiveXCtrlWrapperPropPage �޽��� ó�����Դϴ�.
