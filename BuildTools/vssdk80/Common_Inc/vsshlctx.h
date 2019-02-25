

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for vsshlctx.idl:
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

#ifndef __vsshlctx_h__
#define __vsshlctx_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsShellContext_FWD_DEFINED__
#define __IVsShellContext_FWD_DEFINED__
typedef interface IVsShellContext IVsShellContext;
#endif 	/* __IVsShellContext_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"
#include "servprov.h"
#include "oaidl.h"
#include "ocidl.h"
#include "context.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IVsShellContext_INTERFACE_DEFINED__
#define __IVsShellContext_INTERFACE_DEFINED__

/* interface IVsShellContext */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsShellContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5e819c22-a727-11d2-aa82-00c04f990343")
    IVsShellContext : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTopContext( 
            /* [out] */ IVsUserContext **ppc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNewContext( 
            /* [out] */ IVsUserContext **ppc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextMonitor( 
            /* [out] */ IVsMonitorUserContext **pmuc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCmdUIContext( 
            /* [in] */ DWORD_PTR dwCookie,
            /* [out] */ IVsUserContext **ppc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCmdUIContext( 
            /* [in] */ DWORD_PTR dwCookie,
            /* [in] */ IVsUserContext *pc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddInformationIndex( 
            /* [in] */ LPCOLESTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveInformationIndex( 
            /* [in] */ LPCOLESTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE F1Lookup( 
            /* [in] */ LPCOLESTR pszKeyword) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryStatusF1WindowLookup( 
            /* [out] */ BOOL *pfIsEnabled,
            /* [out] */ BSTR *pbstrWindowName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE F1WindowLookup( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsShellContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsShellContext * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsShellContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsShellContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTopContext )( 
            IVsShellContext * This,
            /* [out] */ IVsUserContext **ppc);
        
        HRESULT ( STDMETHODCALLTYPE *CreateNewContext )( 
            IVsShellContext * This,
            /* [out] */ IVsUserContext **ppc);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextMonitor )( 
            IVsShellContext * This,
            /* [out] */ IVsMonitorUserContext **pmuc);
        
        HRESULT ( STDMETHODCALLTYPE *GetCmdUIContext )( 
            IVsShellContext * This,
            /* [in] */ DWORD_PTR dwCookie,
            /* [out] */ IVsUserContext **ppc);
        
        HRESULT ( STDMETHODCALLTYPE *SetCmdUIContext )( 
            IVsShellContext * This,
            /* [in] */ DWORD_PTR dwCookie,
            /* [in] */ IVsUserContext *pc);
        
        HRESULT ( STDMETHODCALLTYPE *AddInformationIndex )( 
            IVsShellContext * This,
            /* [in] */ LPCOLESTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveInformationIndex )( 
            IVsShellContext * This,
            /* [in] */ LPCOLESTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *F1Lookup )( 
            IVsShellContext * This,
            /* [in] */ LPCOLESTR pszKeyword);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatusF1WindowLookup )( 
            IVsShellContext * This,
            /* [out] */ BOOL *pfIsEnabled,
            /* [out] */ BSTR *pbstrWindowName);
        
        HRESULT ( STDMETHODCALLTYPE *F1WindowLookup )( 
            IVsShellContext * This);
        
        END_INTERFACE
    } IVsShellContextVtbl;

    interface IVsShellContext
    {
        CONST_VTBL struct IVsShellContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsShellContext_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsShellContext_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsShellContext_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsShellContext_GetTopContext(This,ppc)	\
    (This)->lpVtbl -> GetTopContext(This,ppc)

#define IVsShellContext_CreateNewContext(This,ppc)	\
    (This)->lpVtbl -> CreateNewContext(This,ppc)

#define IVsShellContext_GetContextMonitor(This,pmuc)	\
    (This)->lpVtbl -> GetContextMonitor(This,pmuc)

#define IVsShellContext_GetCmdUIContext(This,dwCookie,ppc)	\
    (This)->lpVtbl -> GetCmdUIContext(This,dwCookie,ppc)

#define IVsShellContext_SetCmdUIContext(This,dwCookie,pc)	\
    (This)->lpVtbl -> SetCmdUIContext(This,dwCookie,pc)

#define IVsShellContext_AddInformationIndex(This,pszPath)	\
    (This)->lpVtbl -> AddInformationIndex(This,pszPath)

#define IVsShellContext_RemoveInformationIndex(This,pszPath)	\
    (This)->lpVtbl -> RemoveInformationIndex(This,pszPath)

#define IVsShellContext_F1Lookup(This,pszKeyword)	\
    (This)->lpVtbl -> F1Lookup(This,pszKeyword)

#define IVsShellContext_QueryStatusF1WindowLookup(This,pfIsEnabled,pbstrWindowName)	\
    (This)->lpVtbl -> QueryStatusF1WindowLookup(This,pfIsEnabled,pbstrWindowName)

#define IVsShellContext_F1WindowLookup(This)	\
    (This)->lpVtbl -> F1WindowLookup(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsShellContext_GetTopContext_Proxy( 
    IVsShellContext * This,
    /* [out] */ IVsUserContext **ppc);


void __RPC_STUB IVsShellContext_GetTopContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsShellContext_CreateNewContext_Proxy( 
    IVsShellContext * This,
    /* [out] */ IVsUserContext **ppc);


void __RPC_STUB IVsShellContext_CreateNewContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsShellContext_GetContextMonitor_Proxy( 
    IVsShellContext * This,
    /* [out] */ IVsMonitorUserContext **pmuc);


void __RPC_STUB IVsShellContext_GetContextMonitor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsShellContext_GetCmdUIContext_Proxy( 
    IVsShellContext * This,
    /* [in] */ DWORD_PTR dwCookie,
    /* [out] */ IVsUserContext **ppc);


void __RPC_STUB IVsShellContext_GetCmdUIContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsShellContext_SetCmdUIContext_Proxy( 
    IVsShellContext * This,
    /* [in] */ DWORD_PTR dwCookie,
    /* [in] */ IVsUserContext *pc);


void __RPC_STUB IVsShellContext_SetCmdUIContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsShellContext_AddInformationIndex_Proxy( 
    IVsShellContext * This,
    /* [in] */ LPCOLESTR pszPath);


void __RPC_STUB IVsShellContext_AddInformationIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsShellContext_RemoveInformationIndex_Proxy( 
    IVsShellContext * This,
    /* [in] */ LPCOLESTR pszPath);


void __RPC_STUB IVsShellContext_RemoveInformationIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsShellContext_F1Lookup_Proxy( 
    IVsShellContext * This,
    /* [in] */ LPCOLESTR pszKeyword);


void __RPC_STUB IVsShellContext_F1Lookup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsShellContext_QueryStatusF1WindowLookup_Proxy( 
    IVsShellContext * This,
    /* [out] */ BOOL *pfIsEnabled,
    /* [out] */ BSTR *pbstrWindowName);


void __RPC_STUB IVsShellContext_QueryStatusF1WindowLookup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsShellContext_F1WindowLookup_Proxy( 
    IVsShellContext * This);


void __RPC_STUB IVsShellContext_F1WindowLookup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsShellContext_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshlctx_0280 */
/* [local] */ 

#define SID_SVsShellContext IID_IVsShellContext


extern RPC_IF_HANDLE __MIDL_itf_vsshlctx_0280_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshlctx_0280_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


