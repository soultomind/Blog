========================================================================
    ACTIVEX 컨트롤 DLL : CSharpWrapperActiveXCtrl 프로젝트 개요
========================================================================

컨트롤 마법사에서는 1개의 컨트롤이 포함된 CSharpWrapperActiveXCtrl ActiveX 컨트롤 DLL에 사용하기 위해 이 프로젝트를 만들었습니다.

이 기초 프로젝트는 ActiveX 컨트롤의 기본적인 작성법을 보여줄 뿐만 아니라 컨트롤의 특정 기능을 작성하기 위한 기본 구조를 제공합니다.

이 파일에는 CSharpWrapperActiveXCtrl ActiveX 컨트롤 DLL을 구성하는 각 파일에 대한 요약 설명이 포함되어 있습니다.

CSharpWrapperActiveXCtrl.vcxproj
    응용 프로그램 마법사를 사용하여 생성한 VC++ 프로젝트의 기본 프로젝트 파일입니다. 파일을 생성한 Visual C++ 버전에 대한 정보와 응용 프로그램 마법사를 사용하여 선택한 플랫폼, 구성 및 프로젝트 기능에 대한 정보가 포함되어 있습니다.

CSharpWrapperActiveXCtrl.vcxproj.filters
    응용 프로그램 마법사를 사용하여 생성된 VC++ 프로젝트의 필터 파일입니다. 이 파일에는 프로젝트의 파일과 필터 간의 연결 정보가 들어 있습니다. 이러한 연결은 특정 노드에서 유사한 확장명으로 그룹화된 파일을 표시하기 위해 IDE에서 사용됩니다. 예를 들어 ".cpp" 파일은 "소스 파일" 필터와 연결되어 있습니다.

CSharpWrapperActiveXCtrl.h
    ActiveX 컨트롤 DLL의 기본 포함 파일입니다. 여기에는 resource.h와 같은 다른 프로젝트 관련 포함 파일이 포함되어 있습니다.

CSharpWrapperActiveXCtrl.cpp
    DLL 초기화, 종료 및 기타 정리 작업에 필요한 코드가 포함된 기본 소스 파일입니다.

CSharpWrapperActiveXCtrl.rc
    프로젝트에서 사용하는 Microsoft Windows 리소스의 목록입니다. 이 파일은 Visual C++ 리소스 편집기로 직접 편집할 수 있습니다.

CSharpWrapperActiveXCtrl.def
    이 파일에는 Microsoft Windows에서 실행하기 위해 제공해야 하는 ActiveX 컨트롤 DLL에 대한 정보가 포함되어 있습니다.

CSharpWrapperActiveXCtrl.idl
    이 파일에는 컨트롤의 형식 라이브러리에 대한 개체 정의 언어 소스 코드가 포함되어 있습니다.

CSharpWrapperActiveXCtrl.ico
    이 파일에는 정보 대화 상자에 표시되는 아이콘이 포함되어 있습니다. 이 아이콘은 기본 리소스 파일인 CSharpWrapperActiveXCtrl.rc에 의해 포함됩니다.

/////////////////////////////////////////////////////////////////////////////
CCSharpWrapperActiveXCtrlCtrl control:

CSharpWrapperActiveXCtrlCtrl.h
    이 파일에는 CCSharpWrapperActiveXCtrlCtrl C++ 클래스가 선언되어 있습니다.

CSharpWrapperActiveXCtrlCtrl.cpp
    이 파일에는 CCSharpWrapperActiveXCtrlCtrl C++ 클래스가 구현되어 있습니다.

CSharpWrapperActiveXCtrlPropPage.h
    이 파일에는 CCSharpWrapperActiveXCtrlPropPage C++ 클래스가 선언되어 있습니다.

CSharpWrapperActiveXCtrlPropPage.cpp
    이 파일에는 CCSharpWrapperActiveXCtrlPropPage C++ 클래스가 구현되어 있습니다.

CCSharpWrapperActiveXCtrlCtrl.bmp
    이 파일에는 CCSharpWrapperActiveXCtrlCtrl 컨트롤이 도구 팔레트에 표시될 때 해당 컨트롤을 나타내기 위해 컨테이너에서 사용하는 비트맵이 포함되어 있습니다. 이 비트맵은 기본 리소스 파일인 CSharpWrapperActiveXCtrl.rc에 의해 포함됩니다.

/////////////////////////////////////////////////////////////////////////////
기타 표준 파일:

stdafx.h, stdafx.cpp
    이 파일은 미리 컴파일된 헤더(PCH) 파일 CSharpWrapperActiveXCtrl.pch와 미리 컴파일된 형식(PCT) 파일 stdafx.obj를 빌드하는 데 사용됩니다.

resource.h
    새 리소스 ID를 정의하는 표준 헤더 파일입니다. Visual C++ 리소스 편집기에서 이 파일을 읽고 업데이트합니다.

/////////////////////////////////////////////////////////////////////////////
기타 참고:

컨트롤 마법사에서 사용하는 "TODO:" 주석은 사용자가 추가하거나 사용자 지정해야 하는 소스 코드 부분을 나타냅니다.

/////////////////////////////////////////////////////////////////////////////
