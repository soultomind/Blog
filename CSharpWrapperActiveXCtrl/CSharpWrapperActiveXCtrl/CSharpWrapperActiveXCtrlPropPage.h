#pragma once

// CSharpWrapperActiveXCtrlPropPage.h : CCSharpWrapperActiveXCtrlPropPage �Ӽ� ������ Ŭ������ �����Դϴ�.


// CCSharpWrapperActiveXCtrlPropPage : ������ ������ CSharpWrapperActiveXCtrlPropPage.cpp��(��) �����Ͻʽÿ�.

class CCSharpWrapperActiveXCtrlPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CCSharpWrapperActiveXCtrlPropPage)
	DECLARE_OLECREATE_EX(CCSharpWrapperActiveXCtrlPropPage)

// �������Դϴ�.
public:
	CCSharpWrapperActiveXCtrlPropPage();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPPAGE_CSHARPWRAPPERACTIVEXCTRL };

// �����Դϴ�.
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �޽��� ���Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

