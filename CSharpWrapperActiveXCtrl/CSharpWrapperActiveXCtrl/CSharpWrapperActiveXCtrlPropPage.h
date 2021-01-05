#pragma once

// CSharpWrapperActiveXCtrlPropPage.h : CCSharpWrapperActiveXCtrlPropPage 속성 페이지 클래스의 선언입니다.


// CCSharpWrapperActiveXCtrlPropPage : 구현을 보려면 CSharpWrapperActiveXCtrlPropPage.cpp을(를) 참조하십시오.

class CCSharpWrapperActiveXCtrlPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CCSharpWrapperActiveXCtrlPropPage)
	DECLARE_OLECREATE_EX(CCSharpWrapperActiveXCtrlPropPage)

// 생성자입니다.
public:
	CCSharpWrapperActiveXCtrlPropPage();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PROPPAGE_CSHARPWRAPPERACTIVEXCTRL };

// 구현입니다.
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 메시지 맵입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

