#pragma once

// CSharpWrapperActiveXCtrlCtrl.h : CCSharpWrapperActiveXCtrlCtrl ActiveX ��Ʈ�� Ŭ������ �����Դϴ�.


// CCSharpWrapperActiveXCtrlCtrl : ������ ������ CSharpWrapperActiveXCtrlCtrl.cpp��(��) �����Ͻʽÿ�.

class CCSharpWrapperActiveXCtrlCtrl : public COleControl
{
	DECLARE_DYNCREATE(CCSharpWrapperActiveXCtrlCtrl)

// �������Դϴ�.
public:
	CCSharpWrapperActiveXCtrlCtrl();

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// �����Դϴ�.
protected:
	~CCSharpWrapperActiveXCtrlCtrl();

	DECLARE_OLECREATE_EX(CCSharpWrapperActiveXCtrlCtrl)    // Ŭ���� ���͸��� GUID�Դϴ�.
	DECLARE_OLETYPELIB(CCSharpWrapperActiveXCtrlCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CCSharpWrapperActiveXCtrlCtrl)     // �Ӽ� ������ ID�Դϴ�.
	DECLARE_OLECTLTYPE(CCSharpWrapperActiveXCtrlCtrl)		// ���� �̸��� ��Ÿ �����Դϴ�.

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
};

