

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for webmigration.idl:
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


#ifndef __webmigration_h__
#define __webmigration_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsWebMigrationService_FWD_DEFINED__
#define __IVsWebMigrationService_FWD_DEFINED__
typedef interface IVsWebMigrationService IVsWebMigrationService;
#endif 	/* __IVsWebMigrationService_FWD_DEFINED__ */


#ifndef __IVsWebMigration_FWD_DEFINED__
#define __IVsWebMigration_FWD_DEFINED__
typedef interface IVsWebMigration IVsWebMigration;
#endif 	/* __IVsWebMigration_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "vsshell80.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_webmigration_0000 */
/* [local] */ 

#define VSWEBMIGRATION_VER_MAJ    8
#define VSWEBMIGRATION_VER_MIN    0


extern RPC_IF_HANDLE __MIDL_itf_webmigration_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_webmigration_0000_v0_0_s_ifspec;


#ifndef __VSWebMigration_LIBRARY_DEFINED__
#define __VSWebMigration_LIBRARY_DEFINED__

/* library VSWebMigration */
/* [version][helpstring][uuid] */ 


#define SID_SVsWebMigrationService IID_IVsWebMigrationService

EXTERN_C const IID LIBID_VSWebMigration;

#ifndef __IVsWebMigrationService_INTERFACE_DEFINED__
#define __IVsWebMigrationService_INTERFACE_DEFINED__

/* interface IVsWebMigrationService */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsWebMigrationService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB0AD857-2F21-40c2-80F2-7CB9300F9DCA")
    IVsWebMigrationService : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MigrateWeb( 
            /* [in] */ IVsProject *pIVsProj,
            /* [in] */ LPCOLESTR pszLocation,
            /* [in] */ LPCOLESTR pszProjFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsWebProject( 
            /* [in] */ LPCOLESTR pszProjFile,
            /* [out] */ BOOL *pIsWeb) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProjectSCCInfo( 
            /* [in] */ BSTR bstrProjectFIle,
            /* [out] */ BSTR *pbstrSccProjectName,
            /* [out] */ BSTR *pbstrSccAuxPath,
            /* [out] */ BSTR *pbstrSccLocalPath,
            /* [out] */ BSTR *pbstrProvider) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsWebMigrationServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsWebMigrationService * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsWebMigrationService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsWebMigrationService * This);
        
        HRESULT ( STDMETHODCALLTYPE *MigrateWeb )( 
            IVsWebMigrationService * This,
            /* [in] */ IVsProject *pIVsProj,
            /* [in] */ LPCOLESTR pszLocation,
            /* [in] */ LPCOLESTR pszProjFile);
        
        HRESULT ( STDMETHODCALLTYPE *IsWebProject )( 
            IVsWebMigrationService * This,
            /* [in] */ LPCOLESTR pszProjFile,
            /* [out] */ BOOL *pIsWeb);
        
        HRESULT ( STDMETHODCALLTYPE *GetProjectSCCInfo )( 
            IVsWebMigrationService * This,
            /* [in] */ BSTR bstrProjectFIle,
            /* [out] */ BSTR *pbstrSccProjectName,
            /* [out] */ BSTR *pbstrSccAuxPath,
            /* [out] */ BSTR *pbstrSccLocalPath,
            /* [out] */ BSTR *pbstrProvider);
        
        END_INTERFACE
    } IVsWebMigrationServiceVtbl;

    interface IVsWebMigrationService
    {
        CONST_VTBL struct IVsWebMigrationServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsWebMigrationService_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsWebMigrationService_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsWebMigrationService_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsWebMigrationService_MigrateWeb(This,pIVsProj,pszLocation,pszProjFile)	\
    (This)->lpVtbl -> MigrateWeb(This,pIVsProj,pszLocation,pszProjFile)

#define IVsWebMigrationService_IsWebProject(This,pszProjFile,pIsWeb)	\
    (This)->lpVtbl -> IsWebProject(This,pszProjFile,pIsWeb)

#define IVsWebMigrationService_GetProjectSCCInfo(This,bstrProjectFIle,pbstrSccProjectName,pbstrSccAuxPath,pbstrSccLocalPath,pbstrProvider)	\
    (This)->lpVtbl -> GetProjectSCCInfo(This,bstrProjectFIle,pbstrSccProjectName,pbstrSccAuxPath,pbstrSccLocalPath,pbstrProvider)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsWebMigrationService_MigrateWeb_Proxy( 
    IVsWebMigrationService * This,
    /* [in] */ IVsProject *pIVsProj,
    /* [in] */ LPCOLESTR pszLocation,
    /* [in] */ LPCOLESTR pszProjFile);


void __RPC_STUB IVsWebMigrationService_MigrateWeb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebMigrationService_IsWebProject_Proxy( 
    IVsWebMigrationService * This,
    /* [in] */ LPCOLESTR pszProjFile,
    /* [out] */ BOOL *pIsWeb);


void __RPC_STUB IVsWebMigrationService_IsWebProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebMigrationService_GetProjectSCCInfo_Proxy( 
    IVsWebMigrationService * This,
    /* [in] */ BSTR bstrProjectFIle,
    /* [out] */ BSTR *pbstrSccProjectName,
    /* [out] */ BSTR *pbstrSccAuxPath,
    /* [out] */ BSTR *pbstrSccLocalPath,
    /* [out] */ BSTR *pbstrProvider);


void __RPC_STUB IVsWebMigrationService_GetProjectSCCInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsWebMigrationService_INTERFACE_DEFINED__ */


#ifndef __IVsWebMigration_INTERFACE_DEFINED__
#define __IVsWebMigration_INTERFACE_DEFINED__

/* interface IVsWebMigration */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IVsWebMigration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1D1851BE-913D-40f4-AD7C-AD1F69A34E27")
    IVsWebMigration : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadAssembly( 
            /* [in] */ BSTR bstrFilePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBaseType( 
            /* [in] */ BSTR bstrClassName,
            /* [out] */ BSTR *pbstrBaseClass) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unload( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsWebMigrationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsWebMigration * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsWebMigration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsWebMigration * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadAssembly )( 
            IVsWebMigration * This,
            /* [in] */ BSTR bstrFilePath);
        
        HRESULT ( STDMETHODCALLTYPE *GetBaseType )( 
            IVsWebMigration * This,
            /* [in] */ BSTR bstrClassName,
            /* [out] */ BSTR *pbstrBaseClass);
        
        HRESULT ( STDMETHODCALLTYPE *Unload )( 
            IVsWebMigration * This);
        
        END_INTERFACE
    } IVsWebMigrationVtbl;

    interface IVsWebMigration
    {
        CONST_VTBL struct IVsWebMigrationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsWebMigration_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsWebMigration_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsWebMigration_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsWebMigration_LoadAssembly(This,bstrFilePath)	\
    (This)->lpVtbl -> LoadAssembly(This,bstrFilePath)

#define IVsWebMigration_GetBaseType(This,bstrClassName,pbstrBaseClass)	\
    (This)->lpVtbl -> GetBaseType(This,bstrClassName,pbstrBaseClass)

#define IVsWebMigration_Unload(This)	\
    (This)->lpVtbl -> Unload(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsWebMigration_LoadAssembly_Proxy( 
    IVsWebMigration * This,
    /* [in] */ BSTR bstrFilePath);


void __RPC_STUB IVsWebMigration_LoadAssembly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebMigration_GetBaseType_Proxy( 
    IVsWebMigration * This,
    /* [in] */ BSTR bstrClassName,
    /* [out] */ BSTR *pbstrBaseClass);


void __RPC_STUB IVsWebMigration_GetBaseType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebMigration_Unload_Proxy( 
    IVsWebMigration * This);


void __RPC_STUB IVsWebMigration_Unload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsWebMigration_INTERFACE_DEFINED__ */

#endif /* __VSWebMigration_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


