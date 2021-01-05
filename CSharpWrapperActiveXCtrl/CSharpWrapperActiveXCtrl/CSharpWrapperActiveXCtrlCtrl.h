#pragma once

// CSharpWrapperActiveXCtrlCtrl.h : CCSharpWrapperActiveXCtrlCtrl ActiveX 컨트롤 클래스의 선언입니다.


// CCSharpWrapperActiveXCtrlCtrl : 구현을 보려면 CSharpWrapperActiveXCtrlCtrl.cpp을(를) 참조하십시오.

class CCSharpWrapperActiveXCtrlCtrl : public COleControl
{
	DECLARE_DYNCREATE(CCSharpWrapperActiveXCtrlCtrl)

// 생성자입니다.
public:
	CCSharpWrapperActiveXCtrlCtrl();

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 구현입니다.
protected:
	~CCSharpWrapperActiveXCtrlCtrl();

	DECLARE_OLECREATE_EX(CCSharpWrapperActiveXCtrlCtrl)    // 클래스 팩터리와 GUID입니다.
	DECLARE_OLETYPELIB(CCSharpWrapperActiveXCtrlCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CCSharpWrapperActiveXCtrlCtrl)     // 속성 페이지 ID입니다.
	DECLARE_OLECTLTYPE(CCSharpWrapperActiveXCtrlCtrl)		// 형식 이름과 기타 상태입니다.

// 메시지 맵입니다.
	DECLARE_MESSAGE_MAP()

// 디스패치 맵입니다.
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 이벤트 맵입니다.
	DECLARE_EVENT_MAP()

// 디스패치와 이벤트 ID입니다.
public:
	enum {
	};
};

