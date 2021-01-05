// CSharpWrapperActiveXCtrl.cpp : CCSharpWrapperActiveXCtrlApp 및 DLL 등록의 구현입니다.

#include "stdafx.h"
#include "CSharpWrapperActiveXCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CCSharpWrapperActiveXCtrlApp theApp;

const GUID CDECL _tlid = { 0x380F898F, 0xEFF1, 0x4142, { 0xA1, 0x4C, 0x88, 0x6, 0x27, 0xC5, 0xF5, 0x77 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CCSharpWrapperActiveXCtrlApp::InitInstance - DLL 초기화입니다.

BOOL CCSharpWrapperActiveXCtrlApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 여기에 직접 작성한 모듈 초기화 코드를 추가합니다.
	}

	return bInit;
}



// CCSharpWrapperActiveXCtrlApp::ExitInstance - DLL 종료입니다.

int CCSharpWrapperActiveXCtrlApp::ExitInstance()
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
