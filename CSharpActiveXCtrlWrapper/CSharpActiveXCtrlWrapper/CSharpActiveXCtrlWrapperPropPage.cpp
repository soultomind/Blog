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
	0xb1c600fc, 0xab8e, 0x4aff, 0xbd, 0xf0, 0x8e, 0xae, 0xe, 0xad, 0x9c, 0xa5)

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
