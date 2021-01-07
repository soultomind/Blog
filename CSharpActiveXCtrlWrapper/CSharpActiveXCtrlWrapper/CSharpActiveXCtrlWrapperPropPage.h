#pragma once

// CSharpActiveXCtrlWrapperPropPage.h : CCSharpActiveXCtrlWrapperPropPage 속성 페이지 클래스의 선언입니다.


// CCSharpActiveXCtrlWrapperPropPage : 구현을 보려면 CSharpActiveXCtrlWrapperPropPage.cpp을(를) 참조하십시오.

class CCSharpActiveXCtrlWrapperPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CCSharpActiveXCtrlWrapperPropPage)
	DECLARE_OLECREATE_EX(CCSharpActiveXCtrlWrapperPropPage)

// 생성자입니다.
public:
	CCSharpActiveXCtrlWrapperPropPage();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PROPPAGE_CSHARPACTIVEXCTRLWRAPPER };

// 구현입니다.
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 메시지 맵입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

