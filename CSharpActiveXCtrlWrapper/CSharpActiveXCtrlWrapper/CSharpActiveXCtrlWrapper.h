#pragma once

// CSharpActiveXCtrlWrapper.h : CSharpActiveXCtrlWrapper.DLL�� �⺻ ��� �����Դϴ�.

#if !defined( __AFXCTL_H__ )
#error "�� ������ �����ϱ� ���� 'afxctl.h'�� �����Ͻʽÿ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CCSharpActiveXCtrlWrapperApp : ������ ������ CSharpActiveXCtrlWrapper.cpp�� �����Ͻʽÿ�.

class CCSharpActiveXCtrlWrapperApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

