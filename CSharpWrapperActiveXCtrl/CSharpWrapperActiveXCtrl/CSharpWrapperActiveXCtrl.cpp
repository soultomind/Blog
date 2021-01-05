// CSharpWrapperActiveXCtrl.cpp : CCSharpWrapperActiveXCtrlApp �� DLL ����� �����Դϴ�.

#include "stdafx.h"
#include "CSharpWrapperActiveXCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CCSharpWrapperActiveXCtrlApp theApp;

const GUID CDECL _tlid = { 0x380F898F, 0xEFF1, 0x4142, { 0xA1, 0x4C, 0x88, 0x6, 0x27, 0xC5, 0xF5, 0x77 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CCSharpWrapperActiveXCtrlApp::InitInstance - DLL �ʱ�ȭ�Դϴ�.

BOOL CCSharpWrapperActiveXCtrlApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: ���⿡ ���� �ۼ��� ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	}

	return bInit;
}



// CCSharpWrapperActiveXCtrlApp::ExitInstance - DLL �����Դϴ�.

int CCSharpWrapperActiveXCtrlApp::ExitInstance()
{
	// TODO: ���⿡ ���� �ۼ��� ��� ���� �ڵ带 �߰��մϴ�.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - �ý��� ������Ʈ���� �׸��� �߰��մϴ�.

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �ý��� ������Ʈ������ �׸��� �����մϴ�.

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
