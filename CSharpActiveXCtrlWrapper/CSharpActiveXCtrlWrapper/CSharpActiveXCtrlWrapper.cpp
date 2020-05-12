// CSharpActiveXCtrlWrapper.cpp : CCSharpActiveXCtrlWrapperApp �� DLL ����� �����Դϴ�.

#include "stdafx.h"
#include "CSharpActiveXCtrlWrapper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CCSharpActiveXCtrlWrapperApp theApp;

const GUID CDECL _tlid = { 0x782DB4B1, 0xF0B9, 0x41E2, { 0xB8, 0x10, 0x30, 0x36, 0x44, 0x1D, 0x23, 0xF } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CCSharpActiveXCtrlWrapperApp::InitInstance - DLL �ʱ�ȭ�Դϴ�.

BOOL CCSharpActiveXCtrlWrapperApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: ���⿡ ���� �ۼ��� ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	}

	return bInit;
}



// CCSharpActiveXCtrlWrapperApp::ExitInstance - DLL �����Դϴ�.

int CCSharpActiveXCtrlWrapperApp::ExitInstance()
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
