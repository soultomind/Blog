// CSharpWrapperActiveXCtrlCtrl.cpp : CCSharpWrapperActiveXCtrlCtrl ActiveX ��Ʈ�� Ŭ������ �����Դϴ�.

#include "stdafx.h"
#include "CSharpWrapperActiveXCtrl.h"
#include "CSharpWrapperActiveXCtrlCtrl.h"
#include "CSharpWrapperActiveXCtrlPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CCSharpWrapperActiveXCtrlCtrl, COleControl)

// �޽��� ���Դϴ�.

BEGIN_MESSAGE_MAP(CCSharpWrapperActiveXCtrlCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// ����ġ ���Դϴ�.

BEGIN_DISPATCH_MAP(CCSharpWrapperActiveXCtrlCtrl, COleControl)
	DISP_FUNCTION_ID(CCSharpWrapperActiveXCtrlCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// �̺�Ʈ ���Դϴ�.

BEGIN_EVENT_MAP(CCSharpWrapperActiveXCtrlCtrl, COleControl)
END_EVENT_MAP()

// �Ӽ� �������Դϴ�.

// TODO: �ʿ信 ���� �Ӽ� �������� �߰��մϴ�.  ī��Ʈ�� �̿� ���� �����ؾ� �մϴ�.
BEGIN_PROPPAGEIDS(CCSharpWrapperActiveXCtrlCtrl, 1)
	PROPPAGEID(CCSharpWrapperActiveXCtrlPropPage::guid)
END_PROPPAGEIDS(CCSharpWrapperActiveXCtrlCtrl)

// Ŭ���� ���͸��� GUID�� �ʱ�ȭ�մϴ�.

IMPLEMENT_OLECREATE_EX(CCSharpWrapperActiveXCtrlCtrl, "CSHARPWRAPPERACT.CSharpWrapperActCtrl.1",
	0x946b5237, 0xc211, 0x485e, 0xa3, 0x9b, 0x16, 0xd4, 0x81, 0x50, 0xbc, 0xa5)

// ���� ���̺귯�� ID�� �����Դϴ�.

IMPLEMENT_OLETYPELIB(CCSharpWrapperActiveXCtrlCtrl, _tlid, _wVerMajor, _wVerMinor)

// �������̽� ID�Դϴ�.

const IID IID_DCSharpWrapperActiveXCtrl = { 0xD922C4EC, 0xAED0, 0x4A70, { 0x97, 0x9B, 0xCE, 0xAF, 0x3C, 0x83, 0x33, 0x6C } };
const IID IID_DCSharpWrapperActiveXCtrlEvents = { 0x4DF964DE, 0xA739, 0x4949, { 0x9F, 0x2B, 0xBC, 0x41, 0x81, 0xA5, 0xE0, 0x10 } };

// ��Ʈ�� ���� �����Դϴ�.

static const DWORD _dwCSharpWrapperActiveXCtrlOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CCSharpWrapperActiveXCtrlCtrl, IDS_CSHARPWRAPPERACTIVEXCTRL, _dwCSharpWrapperActiveXCtrlOleMisc)

// CCSharpWrapperActiveXCtrlCtrl::CCSharpWrapperActiveXCtrlCtrlFactory::UpdateRegistry -
// CCSharpWrapperActiveXCtrlCtrl���� �ý��� ������Ʈ�� �׸��� �߰��ϰų� �����մϴ�.

BOOL CCSharpWrapperActiveXCtrlCtrl::CCSharpWrapperActiveXCtrlCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: ��Ʈ���� ����Ʈ �� ������ ��Ģ�� �ؼ��ϴ���
	// Ȯ���մϴ�. �ڼ��� ������ MFC Technical Note 64��
	// �����Ͻʽÿ�. ��Ʈ���� ����Ʈ �� ��Ģ��
	// ���� �ʴ� ��� �������� ���� ��° �Ű� ������ �����մϴ�.
	// afxRegApartmentThreading�� 0���� �����մϴ�.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_CSHARPWRAPPERACTIVEXCTRL,
			IDB_CSHARPWRAPPERACTIVEXCTRL,
			afxRegApartmentThreading,
			_dwCSharpWrapperActiveXCtrlOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CCSharpWrapperActiveXCtrlCtrl::CCSharpWrapperActiveXCtrlCtrl - �������Դϴ�.

CCSharpWrapperActiveXCtrlCtrl::CCSharpWrapperActiveXCtrlCtrl()
{
	InitializeIIDs(&IID_DCSharpWrapperActiveXCtrl, &IID_DCSharpWrapperActiveXCtrlEvents);
	// TODO: ���⿡�� ��Ʈ���� �ν��Ͻ� �����͸� �ʱ�ȭ�մϴ�.
}

// CCSharpWrapperActiveXCtrlCtrl::~CCSharpWrapperActiveXCtrlCtrl - �Ҹ����Դϴ�.

CCSharpWrapperActiveXCtrlCtrl::~CCSharpWrapperActiveXCtrlCtrl()
{
	// TODO: ���⿡�� ��Ʈ���� �ν��Ͻ� �����͸� �����մϴ�.
}

// CCSharpWrapperActiveXCtrlCtrl::OnDraw - �׸��� �Լ��Դϴ�.

void CCSharpWrapperActiveXCtrlCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: ���� �ڵ带 ����ڰ� ���� �ۼ��� �׸��� �ڵ�� �ٲٽʽÿ�.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CCSharpWrapperActiveXCtrlCtrl::DoPropExchange - ���Ӽ� �����Դϴ�.

void CCSharpWrapperActiveXCtrlCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: �������� ����� ���� �Ӽ� ��ο� ���� PX_ functions�� ȣ���մϴ�.
}


// CCSharpWrapperActiveXCtrlCtrl::OnResetState - ��Ʈ���� �⺻ ���·� �ٽ� �����մϴ�.

void CCSharpWrapperActiveXCtrlCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange�� ��� �ִ� �⺻���� �ٽ� �����մϴ�.

	// TODO: ���⿡�� �ٸ� ��� ��Ʈ���� ���¸� �ٽ� �����մϴ�.
}


// CCSharpWrapperActiveXCtrlCtrl::AboutBox - "����" ��ȭ ���ڸ� ����ڿ��� ���� �ݴϴ�.

void CCSharpWrapperActiveXCtrlCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_CSHARPWRAPPERACTIVEXCTRL);
	dlgAbout.DoModal();
}


// CCSharpWrapperActiveXCtrlCtrl �޽��� ó�����Դϴ�.
