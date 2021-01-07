// CSharpActiveXCtrlWrapper.cpp : CCSharpActiveXCtrlWrapperApp 및 DLL 등록의 구현입니다.

#include "stdafx.h"
#include "CSharpActiveXCtrlWrapper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CCSharpActiveXCtrlWrapperApp theApp;

const GUID CDECL _tlid = { 0xB903F7A0, 0xF4CA, 0x4005, { 0xBE, 0x59, 0x3, 0xBC, 0xBC, 0xF7, 0x7D, 0x61 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CCSharpActiveXCtrlWrapperApp::InitInstance - DLL 초기화입니다.

BOOL CCSharpActiveXCtrlWrapperApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 여기에 직접 작성한 모듈 초기화 코드를 추가합니다.
	}

	return bInit;
}



// CCSharpActiveXCtrlWrapperApp::ExitInstance - DLL 종료입니다.

int CCSharpActiveXCtrlWrapperApp::ExitInstance()
{
	// TODO: 여기에 직접 작성한 모듈 종료 코드를 추가합니다.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 시스템 레지스트리에 항목을 추가합니다.

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 시스템 레지스트리에서 항목을 제거합니다.

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
