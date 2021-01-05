// CSharpWrapperActiveXCtrlCtrl.cpp : CCSharpWrapperActiveXCtrlCtrl ActiveX 컨트롤 클래스의 구현입니다.

#include "stdafx.h"
#include "CSharpWrapperActiveXCtrl.h"
#include "CSharpWrapperActiveXCtrlCtrl.h"
#include "CSharpWrapperActiveXCtrlPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CCSharpWrapperActiveXCtrlCtrl, COleControl)

// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CCSharpWrapperActiveXCtrlCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 디스패치 맵입니다.

BEGIN_DISPATCH_MAP(CCSharpWrapperActiveXCtrlCtrl, COleControl)
	DISP_FUNCTION_ID(CCSharpWrapperActiveXCtrlCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 이벤트 맵입니다.

BEGIN_EVENT_MAP(CCSharpWrapperActiveXCtrlCtrl, COleControl)
END_EVENT_MAP()

// 속성 페이지입니다.

// TODO: 필요에 따라 속성 페이지를 추가합니다.  카운트도 이에 따라 증가해야 합니다.
BEGIN_PROPPAGEIDS(CCSharpWrapperActiveXCtrlCtrl, 1)
	PROPPAGEID(CCSharpWrapperActiveXCtrlPropPage::guid)
END_PROPPAGEIDS(CCSharpWrapperActiveXCtrlCtrl)

// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CCSharpWrapperActiveXCtrlCtrl, "CSHARPWRAPPERACT.CSharpWrapperActCtrl.1",
	0x946b5237, 0xc211, 0x485e, 0xa3, 0x9b, 0x16, 0xd4, 0x81, 0x50, 0xbc, 0xa5)

// 형식 라이브러리 ID와 버전입니다.

IMPLEMENT_OLETYPELIB(CCSharpWrapperActiveXCtrlCtrl, _tlid, _wVerMajor, _wVerMinor)

// 인터페이스 ID입니다.

const IID IID_DCSharpWrapperActiveXCtrl = { 0xD922C4EC, 0xAED0, 0x4A70, { 0x97, 0x9B, 0xCE, 0xAF, 0x3C, 0x83, 0x33, 0x6C } };
const IID IID_DCSharpWrapperActiveXCtrlEvents = { 0x4DF964DE, 0xA739, 0x4949, { 0x9F, 0x2B, 0xBC, 0x41, 0x81, 0xA5, 0xE0, 0x10 } };

// 컨트롤 형식 정보입니다.

static const DWORD _dwCSharpWrapperActiveXCtrlOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CCSharpWrapperActiveXCtrlCtrl, IDS_CSHARPWRAPPERACTIVEXCTRL, _dwCSharpWrapperActiveXCtrlOleMisc)

// CCSharpWrapperActiveXCtrlCtrl::CCSharpWrapperActiveXCtrlCtrlFactory::UpdateRegistry -
// CCSharpWrapperActiveXCtrlCtrl에서 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CCSharpWrapperActiveXCtrlCtrl::CCSharpWrapperActiveXCtrlCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 컨트롤이 아파트 모델 스레딩 규칙을 준수하는지
	// 확인합니다. 자세한 내용은 MFC Technical Note 64를
	// 참조하십시오. 컨트롤이 아파트 모델 규칙에
	// 맞지 않는 경우 다음에서 여섯 번째 매개 변수를 변경합니다.
	// afxRegApartmentThreading을 0으로 설정합니다.

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


// CCSharpWrapperActiveXCtrlCtrl::CCSharpWrapperActiveXCtrlCtrl - 생성자입니다.

CCSharpWrapperActiveXCtrlCtrl::CCSharpWrapperActiveXCtrlCtrl()
{
	InitializeIIDs(&IID_DCSharpWrapperActiveXCtrl, &IID_DCSharpWrapperActiveXCtrlEvents);
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 초기화합니다.
}

// CCSharpWrapperActiveXCtrlCtrl::~CCSharpWrapperActiveXCtrlCtrl - 소멸자입니다.

CCSharpWrapperActiveXCtrlCtrl::~CCSharpWrapperActiveXCtrlCtrl()
{
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 정리합니다.
}

// CCSharpWrapperActiveXCtrlCtrl::OnDraw - 그리기 함수입니다.

void CCSharpWrapperActiveXCtrlCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: 다음 코드를 사용자가 직접 작성한 그리기 코드로 바꾸십시오.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CCSharpWrapperActiveXCtrlCtrl::DoPropExchange - 지속성 지원입니다.

void CCSharpWrapperActiveXCtrlCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 지속적인 사용자 지정 속성 모두에 대해 PX_ functions를 호출합니다.
}


// CCSharpWrapperActiveXCtrlCtrl::OnResetState - 컨트롤을 기본 상태로 다시 설정합니다.

void CCSharpWrapperActiveXCtrlCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange에 들어 있는 기본값을 다시 설정합니다.

	// TODO: 여기에서 다른 모든 컨트롤의 상태를 다시 설정합니다.
}


// CCSharpWrapperActiveXCtrlCtrl::AboutBox - "정보" 대화 상자를 사용자에게 보여 줍니다.

void CCSharpWrapperActiveXCtrlCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_CSHARPWRAPPERACTIVEXCTRL);
	dlgAbout.DoModal();
}


// CCSharpWrapperActiveXCtrlCtrl 메시지 처리기입니다.
