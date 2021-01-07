

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Jan 07 21:16:20 2021
 */
/* Compiler settings for CSharpActiveXCtrlWrapper.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __CSharpActiveXCtrlWrapperidl_h__
#define __CSharpActiveXCtrlWrapperidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DCSharpActiveXCtrlWrapper_FWD_DEFINED__
#define ___DCSharpActiveXCtrlWrapper_FWD_DEFINED__
typedef interface _DCSharpActiveXCtrlWrapper _DCSharpActiveXCtrlWrapper;

#endif 	/* ___DCSharpActiveXCtrlWrapper_FWD_DEFINED__ */


#ifndef ___DCSharpActiveXCtrlWrapperEvents_FWD_DEFINED__
#define ___DCSharpActiveXCtrlWrapperEvents_FWD_DEFINED__
typedef interface _DCSharpActiveXCtrlWrapperEvents _DCSharpActiveXCtrlWrapperEvents;

#endif 	/* ___DCSharpActiveXCtrlWrapperEvents_FWD_DEFINED__ */


#ifndef __CSharpActiveXCtrlWrapper_FWD_DEFINED__
#define __CSharpActiveXCtrlWrapper_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSharpActiveXCtrlWrapper CSharpActiveXCtrlWrapper;
#else
typedef struct CSharpActiveXCtrlWrapper CSharpActiveXCtrlWrapper;
#endif /* __cplusplus */

#endif 	/* __CSharpActiveXCtrlWrapper_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_CSharpActiveXCtrlWrapper_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_CSharpActiveXCtrlWrapper_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_CSharpActiveXCtrlWrapper_0000_0000_v0_0_s_ifspec;


#ifndef __CSharpActiveXCtrlWrapperLib_LIBRARY_DEFINED__
#define __CSharpActiveXCtrlWrapperLib_LIBRARY_DEFINED__

/* library CSharpActiveXCtrlWrapperLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_CSharpActiveXCtrlWrapperLib;

#ifndef ___DCSharpActiveXCtrlWrapper_DISPINTERFACE_DEFINED__
#define ___DCSharpActiveXCtrlWrapper_DISPINTERFACE_DEFINED__

/* dispinterface _DCSharpActiveXCtrlWrapper */
/* [uuid] */ 


EXTERN_C const IID DIID__DCSharpActiveXCtrlWrapper;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EDFFD0FF-97FA-4322-B58D-0F8AC32ED72B")
    _DCSharpActiveXCtrlWrapper : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DCSharpActiveXCtrlWrapperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DCSharpActiveXCtrlWrapper * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DCSharpActiveXCtrlWrapper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DCSharpActiveXCtrlWrapper * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DCSharpActiveXCtrlWrapper * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DCSharpActiveXCtrlWrapper * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DCSharpActiveXCtrlWrapper * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DCSharpActiveXCtrlWrapper * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DCSharpActiveXCtrlWrapperVtbl;

    interface _DCSharpActiveXCtrlWrapper
    {
        CONST_VTBL struct _DCSharpActiveXCtrlWrapperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DCSharpActiveXCtrlWrapper_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DCSharpActiveXCtrlWrapper_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DCSharpActiveXCtrlWrapper_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DCSharpActiveXCtrlWrapper_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DCSharpActiveXCtrlWrapper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DCSharpActiveXCtrlWrapper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DCSharpActiveXCtrlWrapper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DCSharpActiveXCtrlWrapper_DISPINTERFACE_DEFINED__ */


#ifndef ___DCSharpActiveXCtrlWrapperEvents_DISPINTERFACE_DEFINED__
#define ___DCSharpActiveXCtrlWrapperEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DCSharpActiveXCtrlWrapperEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DCSharpActiveXCtrlWrapperEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9155CED3-A95E-4683-9B81-CCC627B85502")
    _DCSharpActiveXCtrlWrapperEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DCSharpActiveXCtrlWrapperEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DCSharpActiveXCtrlWrapperEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DCSharpActiveXCtrlWrapperEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DCSharpActiveXCtrlWrapperEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DCSharpActiveXCtrlWrapperEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DCSharpActiveXCtrlWrapperEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DCSharpActiveXCtrlWrapperEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DCSharpActiveXCtrlWrapperEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DCSharpActiveXCtrlWrapperEventsVtbl;

    interface _DCSharpActiveXCtrlWrapperEvents
    {
        CONST_VTBL struct _DCSharpActiveXCtrlWrapperEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DCSharpActiveXCtrlWrapperEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DCSharpActiveXCtrlWrapperEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DCSharpActiveXCtrlWrapperEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DCSharpActiveXCtrlWrapperEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DCSharpActiveXCtrlWrapperEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DCSharpActiveXCtrlWrapperEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DCSharpActiveXCtrlWrapperEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DCSharpActiveXCtrlWrapperEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CSharpActiveXCtrlWrapper;

#ifdef __cplusplus

class DECLSPEC_UUID("C5C3AAE2-4733-487B-8A11-C8925B15B3AE")
CSharpActiveXCtrlWrapper;
#endif
#endif /* __CSharpActiveXCtrlWrapperLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


