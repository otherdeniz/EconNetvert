

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for context2.idl:
    Oicf, W0, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __context2_h__
#define __context2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsUserContextExport_FWD_DEFINED__
#define __IVsUserContextExport_FWD_DEFINED__
typedef interface IVsUserContextExport IVsUserContextExport;
#endif 	/* __IVsUserContextExport_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"
#include "vsshell.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_context2_0000 */
/* [local] */ 

#pragma once

enum __VSUSERCONTEXTEXPORTTEXTFLAGS
    {	VSUC_ETFlags_None	= 0,
	VSUC_ETFlags_StandardXML	= 0x1,
	VSUC_ETFlags_IncludeChildren	= 0x10
    } ;
typedef DWORD VSUSERCONTEXTEXPORTTEXTFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_context2_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_context2_0000_v0_0_s_ifspec;

#ifndef __IVsUserContextExport_INTERFACE_DEFINED__
#define __IVsUserContextExport_INTERFACE_DEFINED__

/* interface IVsUserContextExport */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsUserContextExport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B50F15A4-C42D-4dc1-AE09-7D2069EC58E9")
    IVsUserContextExport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetUserContextAsText( 
            VSUSERCONTEXTEXPORTTEXTFLAGS dwFlags,
            BSTR bstrOptions,
            BSTR *pbstrKeywords,
            BSTR *pbstrAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserContextAsSafeArray( 
            VSUSERCONTEXTEXPORTTEXTFLAGS dwFlags,
            BSTR bstrF1Keyword,
            SAFEARRAY * *ppKeywords,
            SAFEARRAY * *ppAttributes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSubcontextsFromSafeArrays( 
            IVsMonitorUserContext *pMUC,
            SAFEARRAY * pKeywords,
            SAFEARRAY * pAttributes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsUserContextExportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsUserContextExport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsUserContextExport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsUserContextExport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserContextAsText )( 
            IVsUserContextExport * This,
            VSUSERCONTEXTEXPORTTEXTFLAGS dwFlags,
            BSTR bstrOptions,
            BSTR *pbstrKeywords,
            BSTR *pbstrAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserContextAsSafeArray )( 
            IVsUserContextExport * This,
            VSUSERCONTEXTEXPORTTEXTFLAGS dwFlags,
            BSTR bstrF1Keyword,
            SAFEARRAY * *ppKeywords,
            SAFEARRAY * *ppAttributes);
        
        HRESULT ( STDMETHODCALLTYPE *CreateSubcontextsFromSafeArrays )( 
            IVsUserContextExport * This,
            IVsMonitorUserContext *pMUC,
            SAFEARRAY * pKeywords,
            SAFEARRAY * pAttributes);
        
        END_INTERFACE
    } IVsUserContextExportVtbl;

    interface IVsUserContextExport
    {
        CONST_VTBL struct IVsUserContextExportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsUserContextExport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsUserContextExport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsUserContextExport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsUserContextExport_GetUserContextAsText(This,dwFlags,bstrOptions,pbstrKeywords,pbstrAttributes)	\
    (This)->lpVtbl -> GetUserContextAsText(This,dwFlags,bstrOptions,pbstrKeywords,pbstrAttributes)

#define IVsUserContextExport_GetUserContextAsSafeArray(This,dwFlags,bstrF1Keyword,ppKeywords,ppAttributes)	\
    (This)->lpVtbl -> GetUserContextAsSafeArray(This,dwFlags,bstrF1Keyword,ppKeywords,ppAttributes)

#define IVsUserContextExport_CreateSubcontextsFromSafeArrays(This,pMUC,pKeywords,pAttributes)	\
    (This)->lpVtbl -> CreateSubcontextsFromSafeArrays(This,pMUC,pKeywords,pAttributes)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsUserContextExport_GetUserContextAsText_Proxy( 
    IVsUserContextExport * This,
    VSUSERCONTEXTEXPORTTEXTFLAGS dwFlags,
    BSTR bstrOptions,
    BSTR *pbstrKeywords,
    BSTR *pbstrAttributes);


void __RPC_STUB IVsUserContextExport_GetUserContextAsText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsUserContextExport_GetUserContextAsSafeArray_Proxy( 
    IVsUserContextExport * This,
    VSUSERCONTEXTEXPORTTEXTFLAGS dwFlags,
    BSTR bstrF1Keyword,
    SAFEARRAY * *ppKeywords,
    SAFEARRAY * *ppAttributes);


void __RPC_STUB IVsUserContextExport_GetUserContextAsSafeArray_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsUserContextExport_CreateSubcontextsFromSafeArrays_Proxy( 
    IVsUserContextExport * This,
    IVsMonitorUserContext *pMUC,
    SAFEARRAY * pKeywords,
    SAFEARRAY * pAttributes);


void __RPC_STUB IVsUserContextExport_CreateSubcontextsFromSafeArrays_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsUserContextExport_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


