// CSharpActiveXCtrlWrapperCtrl.cpp : CCSharpActiveXCtrlWrapperCtrl ActiveX 컨트롤 클래스의 구현입니다.

#include "stdafx.h"
#include "CSharpActiveXCtrlWrapper.h"
#include "CSharpActiveXCtrlWrapperCtrl.h"
#include "CSharpActiveXCtrlWrapperPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CCSharpActiveXCtrlWrapperCtrl, COleControl)

// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CCSharpActiveXCtrlWrapperCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 디스패치 맵입니다.

BEGIN_DISPATCH_MAP(CCSharpActiveXCtrlWrapperCtrl, COleControl)
	DISP_FUNCTION_ID(CCSharpActiveXCtrlWrapperCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 이벤트 맵입니다.

BEGIN_EVENT_MAP(CCSharpActiveXCtrlWrapperCtrl, COleControl)
END_EVENT_MAP()

// 속성 페이지입니다.

// TODO: 필요에 따라 속성 페이지를 추가합니다.  카운트도 이에 따라 증가해야 합니다.
BEGIN_PROPPAGEIDS(CCSharpActiveXCtrlWrapperCtrl, 1)
	PROPPAGEID(CCSharpActiveXCtrlWrapperPropPage::guid)
END_PROPPAGEIDS(CCSharpActiveXCtrlWrapperCtrl)

// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CCSharpActiveXCtrlWrapperCtrl, "CSHARPACTIVEXCTR.CSharpActiveXCtrCtrl.1",
	0xb932c6af, 0xbb4, 0x4785, 0x8b, 0x78, 0x79, 0x65, 0xd8, 0xb0, 0x65, 0x4)

// 형식 라이브러리 ID와 버전입니다.

IMPLEMENT_OLETYPELIB(CCSharpActiveXCtrlWrapperCtrl, _tlid, _wVerMajor, _wVerMinor)

// 인터페이스 ID입니다.

const IID IID_DCSharpActiveXCtrlWrapper = { 0x314A733D, 0x9681, 0x4541, { 0x95, 0xF, 0xE1, 0x79, 0xA8, 0x2F, 0x28, 0x25 } };
const IID IID_DCSharpActiveXCtrlWrapperEvents = { 0x699678E7, 0x6CEC, 0x46B9, { 0x87, 0xA6, 0xF5, 0x3C, 0x40, 0x1F, 0x3F, 0xB2 } };

// 컨트롤 형식 정보입니다.

static const DWORD _dwCSharpActiveXCtrlWrapperOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CCSharpActiveXCtrlWrapperCtrl, IDS_CSHARPACTIVEXCTRLWRAPPER, _dwCSharpActiveXCtrlWrapperOleMisc)

// CCSharpActiveXCtrlWrapperCtrl::CCSharpActiveXCtrlWrapperCtrlFactory::UpdateRegistry -
// CCSharpActiveXCtrlWrapperCtrl에서 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CCSharpActiveXCtrlWrapperCtrl::CCSharpActiveXCtrlWrapperCtrlFactory::UpdateRegistry(BOOL bRegister)
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


// CCSharpActiveXCtrlWrapperCtrl::CCSharpActiveXCtrlWrapperCtrl - 생성자입니다.

CCSharpActiveXCtrlWrapperCtrl::CCSharpActiveXCtrlWrapperCtrl()
{
	InitializeIIDs(&IID_DCSharpActiveXCtrlWrapper, &IID_DCSharpActiveXCtrlWrapperEvents);
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 초기화합니다.
}

// CCSharpActiveXCtrlWrapperCtrl::~CCSharpActiveXCtrlWrapperCtrl - 소멸자입니다.

CCSharpActiveXCtrlWrapperCtrl::~CCSharpActiveXCtrlWrapperCtrl()
{
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 정리합니다.
}

// CCSharpActiveXCtrlWrapperCtrl::OnDraw - 그리기 함수입니다.

void CCSharpActiveXCtrlWrapperCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: 다음 코드를 사용자가 직접 작성한 그리기 코드로 바꾸십시오.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CCSharpActiveXCtrlWrapperCtrl::DoPropExchange - 지속성 지원입니다.

void CCSharpActiveXCtrlWrapperCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 지속적인 사용자 지정 속성 모두에 대해 PX_ functions를 호출합니다.
}


// CCSharpActiveXCtrlWrapperCtrl::OnResetState - 컨트롤을 기본 상태로 다시 설정합니다.

void CCSharpActiveXCtrlWrapperCtrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange에 들어 있는 기본값을 다시 설정합니다.

	// TODO: 여기에서 다른 모든 컨트롤의 상태를 다시 설정합니다.
}


// CCSharpActiveXCtrlWrapperCtrl::AboutBox - "정보" 대화 상자를 사용자에게 보여 줍니다.

void CCSharpActiveXCtrlWrapperCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_CSHARPACTIVEXCTRLWRAPPER);
	dlgAbout.DoModal();
}


// CCSharpActiveXCtrlWrapperCtrl 메시지 처리기입니다.
