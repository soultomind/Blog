#pragma once

// CSharpActiveXCtrlWrapperPropPage.h : CCSharpActiveXCtrlWrapperPropPage �Ӽ� ������ Ŭ������ �����Դϴ�.


// CCSharpActiveXCtrlWrapperPropPage : ������ ������ CSharpActiveXCtrlWrapperPropPage.cpp��(��) �����Ͻʽÿ�.

class CCSharpActiveXCtrlWrapperPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CCSharpActiveXCtrlWrapperPropPage)
	DECLARE_OLECREATE_EX(CCSharpActiveXCtrlWrapperPropPage)

// �������Դϴ�.
public:
	CCSharpActiveXCtrlWrapperPropPage();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PROPPAGE_CSHARPACTIVEXCTRLWRAPPER };

// �����Դϴ�.
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �޽��� ���Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

