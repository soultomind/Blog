// CSharpActiveXCtrlWrapperCtrl.cpp : CCSharpActiveXCtrlWrapperCtrl ActiveX ��Ʈ�� Ŭ������ �����Դϴ�.

#include "stdafx.h"
#include "CSharpActiveXCtrlWrapper.h"
#include "CSharpActiveXCtrlWrapperCtrl.h"
#include "CSharpActiveXCtrlWrapperPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CCSharpActiveXCtrlWrapperCtrl, COleControl)

// �޽��� ���Դϴ�.

BEGIN_MESSAGE_MAP(CCSharpActiveXCtrlWrapperCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// ����ġ ���Դϴ�.

BEGIN_DISPATCH_MAP(CCSharpActiveXCtrlWrapperCtrl, COleControl)
	DISP_FUNCTION_ID(CCSharpActiveXCtrlWrapperCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// �̺�Ʈ ���Դϴ�.

BEGIN_EVENT_MAP(CCSharpActiveXCtrlWrapperCtrl, COleControl)
END_EVENT_MAP()

// �Ӽ� �������Դϴ�.

// TODO: �ʿ信 ���� �Ӽ� �������� �߰��մϴ�.  ī��Ʈ�� �̿� ���� �����ؾ� �մϴ�.
BEGIN_PROPPAGEIDS(CCSharpActiveXCtrlWrapperCtrl, 1)
	PROPPAGEID(CCSharpActiveXCtrlWrapperPropPage::guid)
END_PROPPAGEIDS(CCSharpActiveXCtrlWrapperCtrl)

// Ŭ���� ���͸��� GUID�� �ʱ�ȭ�մϴ�.

IMPLEMENT_OLECREATE_EX(CCSharpActiveXCtrlWrapperCtrl, "CSHARPACTIVEXCTR.CSharpActiveXCtrCtrl.1",
	0xc5c3aae2, 0x4733, 0x487b, 0x8a, 0x11, 0xc8, 0x92, 0x5b, 0x15, 0xb3, 0xae)

// ���� ���̺귯�� ID�� �����Դϴ�.

IMPLEMENT_OLETYPELIB(CCSharpActiveXCtrlWrapperCtrl, _tlid, _wVerMajor, _wVerMinor)

// �������̽� ID�Դϴ�.

const IID IID_DCSharpActiveXCtrlWrapper = { 0xEDFFD0FF, 0x97FA, 0x4322, { 0xB5, 0x8D, 0xF, 0x8A, 0xC3, 0x2E, 0xD7, 0x2B } };
const IID IID_DCSharpActiveXCtrlWrapperEvents = { 0x9155CED3, 0xA95E, 0x4683, { 0x9B, 0x81, 0xCC, 0xC6, 0x27, 0xB8, 0x55, 0x2 } };

// ��Ʈ�� ���� �����Դϴ�.

static const DWORD _dwCSharpActiveXCtrlWrapperOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CCSharpActiveXCtrlWrapperCtrl, IDS_CSHARPACTIVEXCTRLWRAPPER, _dwCSharpActiveXCtrlWrapperOleMisc)

// CCSharpActiveXCtrlWrapperCtrl::CCSharpActiveXCtrlWrapperCtrlFactory::UpdateRegistry -
// CCSharpActiveXCtrlWrapperCtrl���� �ý��� ������Ʈ�� �׸��� �߰��ϰų� �����մϴ�.

BOOL CCSharpActiveXCtrlWrapperCtrl::CCSharpActiveXCtrlWrapperCtrlFactory::UpdateRegistry(BOOL bRegister)
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
			IDS_CSHARPACTIVEXCTRLWRAPPER,
			IDB_CSHARPACTIVEXCTRLWRAPPER,
			afxRegApartmentThreading,
			_dwCSharpActiveXCtrlWrapperOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CCSharpActiveXCtrlWrapperCtrl::CCSharpActiveXCtrlWrapperCtrl - �������Դϴ�.

CCSharpActiveXCtrlWrapperCtrl::CCSharpActiveXCtrlWrapperCtrl()
{
	InitializeIIDs(&IID_DCSharpActiveXCtrlWrapper, &IID_DCSharpActiveXCtrlWrapperEvents);
	// TODO: ���⿡�� ��Ʈ���� �ν��Ͻ� �����͸� �ʱ�ȭ�մϴ�.
}

// CCSharpActiveXCtrlWrapperCtrl::~CCSharpActiveXCtrlWrapperCtrl - �Ҹ����Դϴ�.

CCSharpActiveXCtrlWrapperCtrl::~CCSharpActiveXCtrlWrapperCtrl()
{
	// TODO: ���⿡�� ��Ʈ���� �ν��Ͻ� �����͸� �����մϴ�.
}

// CCSharpActiveXCtrlWrapperCtrl::OnDraw - �׸��� �Լ��Դϴ�.

void CCSharpActiveXCtrlWrapperCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: ���� �ڵ带 ����ڰ� ���� �ۼ��� �׸��� �ڵ�� �ٲٽʽÿ�.
	// pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	// pdc->Ellipse(rcBounds);
}

// CCSharpActiveXCtrlWrapperCtrl::DoPropExchange - ���Ӽ� �����Դϴ�.

void CCSharpActiveXCtrlWrapperCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: �������� ����� ���� �Ӽ� ��ο� ���� PX_ functions�� ȣ���մϴ�.
}


// CCSharpActiveXCtrlWrapperCtrl::OnResetState - ��Ʈ���� �⺻ ���·� �ٽ� �����մϴ�.

void CCSharpActiveXCtrlWrapperCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange�� ��� �ִ� �⺻���� �ٽ� �����մϴ�.

	// TODO: ���⿡�� �ٸ� ��� ��Ʈ���� ���¸� �ٽ� �����մϴ�.
}


// CCSharpActiveXCtrlWrapperCtrl::AboutBox - "����" ��ȭ ���ڸ� ����ڿ��� ���� �ݴϴ�.

void CCSharpActiveXCtrlWrapperCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_CSHARPACTIVEXCTRLWRAPPER);
	dlgAbout.DoModal();
}


// CCSharpActiveXCtrlWrapperCtrl �޽��� ó�����Դϴ�.





int CCSharpActiveXCtrlWrapperCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	RECT rect;
	::GetClientRect(m_hWnd, &rect);

	if (m_MyFormView.Create(NULL, NULL, WS_VISIBLE | WS_CHILD, rect, this, IDD_FORMVIEW))
	{
		OutputDebugString(L"MyFormView Create");
	}
	return 0;
}
