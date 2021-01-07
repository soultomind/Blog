#pragma once

#include "MyFormView.h"
// CSharpActiveXCtrlWrapperCtrl.h : CCSharpActiveXCtrlWrapperCtrl ActiveX ��Ʈ�� Ŭ������ �����Դϴ�.


// CCSharpActiveXCtrlWrapperCtrl : ������ ������ CSharpActiveXCtrlWrapperCtrl.cpp��(��) �����Ͻʽÿ�.

class CCSharpActiveXCtrlWrapperCtrl : public COleControl
{
	DECLARE_DYNCREATE(CCSharpActiveXCtrlWrapperCtrl)
private:
	CMyFormView m_MyFormView;
// �������Դϴ�.
public:
	CCSharpActiveXCtrlWrapperCtrl();

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// �����Դϴ�.
protected:
	~CCSharpActiveXCtrlWrapperCtrl();

	DECLARE_OLECREATE_EX(CCSharpActiveXCtrlWrapperCtrl)    // Ŭ���� ���͸��� GUID�Դϴ�.
	DECLARE_OLETYPELIB(CCSharpActiveXCtrlWrapperCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CCSharpActiveXCtrlWrapperCtrl)     // �Ӽ� ������ ID�Դϴ�.
	DECLARE_OLECTLTYPE(CCSharpActiveXCtrlWrapperCtrl)		// ���� �̸��� ��Ÿ �����Դϴ�.

// �޽��� ���Դϴ�.
	DECLARE_MESSAGE_MAP()

// ����ġ ���Դϴ�.
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �̺�Ʈ ���Դϴ�.
	DECLARE_EVENT_MAP()

// ����ġ�� �̺�Ʈ ID�Դϴ�.
public:
	enum {
	};
	
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

