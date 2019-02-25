

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for webapplicationctx.idl:
    Oicf, W0, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

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


#ifndef __webapplicationctx_h__
#define __webapplicationctx_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWebApplicationCtxSvc_FWD_DEFINED__
#define __IWebApplicationCtxSvc_FWD_DEFINED__
typedef interface IWebApplicationCtxSvc IWebApplicationCtxSvc;
#endif 	/* __IWebApplicationCtxSvc_FWD_DEFINED__ */


#ifndef __IWebFileCtxService_FWD_DEFINED__
#define __IWebFileCtxService_FWD_DEFINED__
typedef interface IWebFileCtxService IWebFileCtxService;
#endif 	/* __IWebFileCtxService_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "vsshell.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __WebApplicationCtx_LIBRARY_DEFINED__
#define __WebApplicationCtx_LIBRARY_DEFINED__

/* library WebApplicationCtx */
/* [helpstring][version][uuid] */ 

#define SID_SWebApplicationCtxSvc IID_IWebApplicationCtxSvc
#define SID_SWebFileCtxService IID_IWebFileCtxService

EXTERN_C const IID LIBID_WebApplicationCtx;

#ifndef __IWebApplicationCtxSvc_INTERFACE_DEFINED__
#define __IWebApplicationCtxSvc_INTERFACE_DEFINED__

/* interface IWebApplicationCtxSvc */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IWebApplicationCtxSvc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CCCECEE2-D225-4294-858E-2B8C3F7D84EA")
    IWebApplicationCtxSvc : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetItemContext( 
            /* [in] */ IVsHierarchy *pHier,
            /* [in] */ VSITEMID itemid,
            /* [out] */ IServiceProvider **ppServiceProvider) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWebApplicationCtxSvcVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebApplicationCtxSvc * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebApplicationCtxSvc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebApplicationCtxSvc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemContext )( 
            IWebApplicationCtxSvc * This,
            /* [in] */ IVsHierarchy *pHier,
            /* [in] */ VSITEMID itemid,
            /* [out] */ IServiceProvider **ppServiceProvider);
        
        END_INTERFACE
    } IWebApplicationCtxSvcVtbl;

    interface IWebApplicationCtxSvc
    {
        CONST_VTBL struct IWebApplicationCtxSvcVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebApplicationCtxSvc_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWebApplicationCtxSvc_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWebApplicationCtxSvc_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWebApplicationCtxSvc_GetItemContext(This,pHier,itemid,ppServiceProvider)	\
    (This)->lpVtbl -> GetItemContext(This,pHier,itemid,ppServiceProvider)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWebApplicationCtxSvc_GetItemContext_Proxy( 
    IWebApplicationCtxSvc * This,
    /* [in] */ IVsHierarchy *pHier,
    /* [in] */ VSITEMID itemid,
    /* [out] */ IServiceProvider **ppServiceProvider);


void __RPC_STUB IWebApplicationCtxSvc_GetItemContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWebApplicationCtxSvc_INTERFACE_DEFINED__ */


#ifndef __IWebFileCtxService_INTERFACE_DEFINED__
#define __IWebFileCtxService_INTERFACE_DEFINED__

/* interface IWebFileCtxService */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IWebFileCtxService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("05B4B4B7-6A9D-4a70-BDB1-04CBB26C9248")
    IWebFileCtxService : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddFileToIntellisense( 
            /* [in] */ LPCWSTR pszFilePath,
            /* [out] */ VSITEMID *pItemID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnsureFileOpened( 
            /* [in] */ VSITEMID itemid,
            /* [out] */ IVsWindowFrame **ppFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveFileFromIntellisense( 
            /* [in] */ LPCWSTR pszFilePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWebRootPath( 
            /* [out] */ BSTR *pbstrWebRootPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIntellisenseProjectName( 
            /* [out] */ BSTR *pbstrProjectName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddDependentAssemblyFile( 
            /* [in] */ LPCWSTR pszFilePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveDependentAssemblyFile( 
            /* [in] */ LPCWSTR pszFilePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertToAppRelPath( 
            /* [in] */ LPCWSTR pszFilePath,
            /* [out] */ BSTR *pbstrAppRelPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CBMCallbackActive( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitForIntellisenseReady( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDocumentInProject( 
            /* [in] */ LPCWSTR pszFilePath,
            /* [out] */ VSITEMID *pItemID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWebFileCtxServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWebFileCtxService * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWebFileCtxService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWebFileCtxService * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddFileToIntellisense )( 
            IWebFileCtxService * This,
            /* [in] */ LPCWSTR pszFilePath,
            /* [out] */ VSITEMID *pItemID);
        
        HRESULT ( STDMETHODCALLTYPE *EnsureFileOpened )( 
            IWebFileCtxService * This,
            /* [in] */ VSITEMID itemid,
            /* [out] */ IVsWindowFrame **ppFrame);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveFileFromIntellisense )( 
            IWebFileCtxService * This,
            /* [in] */ LPCWSTR pszFilePath);
        
        HRESULT ( STDMETHODCALLTYPE *GetWebRootPath )( 
            IWebFileCtxService * This,
            /* [out] */ BSTR *pbstrWebRootPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetIntellisenseProjectName )( 
            IWebFileCtxService * This,
            /* [out] */ BSTR *pbstrProjectName);
        
        HRESULT ( STDMETHODCALLTYPE *AddDependentAssemblyFile )( 
            IWebFileCtxService * This,
            /* [in] */ LPCWSTR pszFilePath);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveDependentAssemblyFile )( 
            IWebFileCtxService * This,
            /* [in] */ LPCWSTR pszFilePath);
        
        HRESULT ( STDMETHODCALLTYPE *ConvertToAppRelPath )( 
            IWebFileCtxService * This,
            /* [in] */ LPCWSTR pszFilePath,
            /* [out] */ BSTR *pbstrAppRelPath);
        
        HRESULT ( STDMETHODCALLTYPE *CBMCallbackActive )( 
            IWebFileCtxService * This);
        
        HRESULT ( STDMETHODCALLTYPE *WaitForIntellisenseReady )( 
            IWebFileCtxService * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsDocumentInProject )( 
            IWebFileCtxService * This,
            /* [in] */ LPCWSTR pszFilePath,
            /* [out] */ VSITEMID *pItemID);
        
        END_INTERFACE
    } IWebFileCtxServiceVtbl;

    interface IWebFileCtxService
    {
        CONST_VTBL struct IWebFileCtxServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWebFileCtxService_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWebFileCtxService_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWebFileCtxService_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWebFileCtxService_AddFileToIntellisense(This,pszFilePath,pItemID)	\
    (This)->lpVtbl -> AddFileToIntellisense(This,pszFilePath,pItemID)

#define IWebFileCtxService_EnsureFileOpened(This,itemid,ppFrame)	\
    (This)->lpVtbl -> EnsureFileOpened(This,itemid,ppFrame)

#define IWebFileCtxService_RemoveFileFromIntellisense(This,pszFilePath)	\
    (This)->lpVtbl -> RemoveFileFromIntellisense(This,pszFilePath)

#define IWebFileCtxService_GetWebRootPath(This,pbstrWebRootPath)	\
    (This)->lpVtbl -> GetWebRootPath(This,pbstrWebRootPath)

#define IWebFileCtxService_GetIntellisenseProjectName(This,pbstrProjectName)	\
    (This)->lpVtbl -> GetIntellisenseProjectName(This,pbstrProjectName)

#define IWebFileCtxService_AddDependentAssemblyFile(This,pszFilePath)	\
    (This)->lpVtbl -> AddDependentAssemblyFile(This,pszFilePath)

#define IWebFileCtxService_RemoveDependentAssemblyFile(This,pszFilePath)	\
    (This)->lpVtbl -> RemoveDependentAssemblyFile(This,pszFilePath)

#define IWebFileCtxService_ConvertToAppRelPath(This,pszFilePath,pbstrAppRelPath)	\
    (This)->lpVtbl -> ConvertToAppRelPath(This,pszFilePath,pbstrAppRelPath)

#define IWebFileCtxService_CBMCallbackActive(This)	\
    (This)->lpVtbl -> CBMCallbackActive(This)

#define IWebFileCtxService_WaitForIntellisenseReady(This)	\
    (This)->lpVtbl -> WaitForIntellisenseReady(This)

#define IWebFileCtxService_IsDocumentInProject(This,pszFilePath,pItemID)	\
    (This)->lpVtbl -> IsDocumentInProject(This,pszFilePath,pItemID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWebFileCtxService_AddFileToIntellisense_Proxy( 
    IWebFileCtxService * This,
    /* [in] */ LPCWSTR pszFilePath,
    /* [out] */ VSITEMID *pItemID);


void __RPC_STUB IWebFileCtxService_AddFileToIntellisense_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWebFileCtxService_EnsureFileOpened_Proxy( 
    IWebFileCtxService * This,
    /* [in] */ VSITEMID itemid,
    /* [out] */ IVsWindowFrame **ppFrame);


void __RPC_STUB IWebFileCtxService_EnsureFileOpened_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWebFileCtxService_RemoveFileFromIntellisense_Proxy( 
    IWebFileCtxService * This,
    /* [in] */ LPCWSTR pszFilePath);


void __RPC_STUB IWebFileCtxService_RemoveFileFromIntellisense_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWebFileCtxService_GetWebRootPath_Proxy( 
    IWebFileCtxService * This,
    /* [out] */ BSTR *pbstrWebRootPath);


void __RPC_STUB IWebFileCtxService_GetWebRootPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWebFileCtxService_GetIntellisenseProjectName_Proxy( 
    IWebFileCtxService * This,
    /* [out] */ BSTR *pbstrProjectName);


void __RPC_STUB IWebFileCtxService_GetIntellisenseProjectName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWebFileCtxService_AddDependentAssemblyFile_Proxy( 
    IWebFileCtxService * This,
    /* [in] */ LPCWSTR pszFilePath);


void __RPC_STUB IWebFileCtxService_AddDependentAssemblyFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWebFileCtxService_RemoveDependentAssemblyFile_Proxy( 
    IWebFileCtxService * This,
    /* [in] */ LPCWSTR pszFilePath);


void __RPC_STUB IWebFileCtxService_RemoveDependentAssemblyFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWebFileCtxService_ConvertToAppRelPath_Proxy( 
    IWebFileCtxService * This,
    /* [in] */ LPCWSTR pszFilePath,
    /* [out] */ BSTR *pbstrAppRelPath);


void __RPC_STUB IWebFileCtxService_ConvertToAppRelPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWebFileCtxService_CBMCallbackActive_Proxy( 
    IWebFileCtxService * This);


void __RPC_STUB IWebFileCtxService_CBMCallbackActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWebFileCtxService_WaitForIntellisenseReady_Proxy( 
    IWebFileCtxService * This);


void __RPC_STUB IWebFileCtxService_WaitForIntellisenseReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWebFileCtxService_IsDocumentInProject_Proxy( 
    IWebFileCtxService * This,
    /* [in] */ LPCWSTR pszFilePath,
    /* [out] */ VSITEMID *pItemID);


void __RPC_STUB IWebFileCtxService_IsDocumentInProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWebFileCtxService_INTERFACE_DEFINED__ */

#endif /* __WebApplicationCtx_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


