// CSharpWrapperActiveXCtrlPropPage.cpp : CCSharpWrapperActiveXCtrlPropPage �Ӽ� ������ Ŭ������ �����Դϴ�.

#include "stdafx.h"
#include "CSharpWrapperActiveXCtrl.h"
#include "CSharpWrapperActiveXCtrlPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CCSharpWrapperActiveXCtrlPropPage, COlePropertyPage)

// �޽��� ���Դϴ�.

BEGIN_MESSAGE_MAP(CCSharpWrapperActiveXCtrlPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Ŭ���� ���͸��� GUID�� �ʱ�ȭ�մϴ�.

IMPLEMENT_OLECREATE_EX(CCSharpWrapperActiveXCtrlPropPage, "CSHARPWRAPPERA.CSharpWrapperAPropPage.1",
	0xac3fb637, 0x9d98, 0x40bf, 0x92, 0x5d, 0x7b, 0x28, 0x31, 0x73, 0x46, 0xc1)

// CCSharpWrapperActiveXCtrlPropPage::CCSharpWrapperActiveXCtrlPropPageFactory::UpdateRegistry -
// CCSharpWrapperActiveXCtrlPropPage���� �ý��� ������Ʈ�� �׸��� �߰��ϰų� �����մϴ�.

BOOL CCSharpWrapperActiveXCtrlPropPage::CCSharpWrapperActiveXCtrlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CSHARPWRAPPERACTIVEXCTRL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CCSharpWrapperActiveXCtrlPropPage::CCSharpWrapperActiveXCtrlPropPage - �������Դϴ�.

CCSharpWrapperActiveXCtrlPropPage::CCSharpWrapperActiveXCtrlPropPage() :
	COlePropertyPage(IDD, IDS_CSHARPWRAPPERACTIVEXCTRL_PPG_CAPTION)
{
}

// CCSharpWrapperActiveXCtrlPropPage::DoDataExchange - �������� �Ӽ� ���̿��� �����͸� �̵���ŵ�ϴ�.

void CCSharpWrapperActiveXCtrlPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CCSharpWrapperActiveXCtrlPropPage �޽��� ó�����Դϴ�.
