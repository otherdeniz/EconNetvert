

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for IVsSccProjectEnlistmentFactory.idl:
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

#ifndef __IVsSccProjectEnlistmentFactory_h__
#define __IVsSccProjectEnlistmentFactory_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsSccProjectEnlistmentFactory_FWD_DEFINED__
#define __IVsSccProjectEnlistmentFactory_FWD_DEFINED__
typedef interface IVsSccProjectEnlistmentFactory IVsSccProjectEnlistmentFactory;
#endif 	/* __IVsSccProjectEnlistmentFactory_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_IVsSccProjectEnlistmentFactory_0000 */
/* [local] */ 


enum __VSSCCENLISTMENTFACTORYOPTIONS
    {	VSSCC_EFO_CANBROWSEENLISTMENTPATH	= 0x1,
	VSSCC_EFO_CANEDITENLISTMENTPATH	= 0x2,
	VSSCC_EFO_CANBROWSEDEBUGGINGPATH	= 0x4,
	VSSCC_EFO_CANEDITDEBUGGINGPATH	= 0x8
    } ;
typedef DWORD VSSCCENLISTMENTFACTORYOPTIONS;



extern RPC_IF_HANDLE __MIDL_itf_IVsSccProjectEnlistmentFactory_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IVsSccProjectEnlistmentFactory_0000_v0_0_s_ifspec;

#ifndef __IVsSccProjectEnlistmentFactory_INTERFACE_DEFINED__
#define __IVsSccProjectEnlistmentFactory_INTERFACE_DEFINED__

/* interface IVsSccProjectEnlistmentFactory */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSccProjectEnlistmentFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53544c4d-00f8-11d0-8e5e-00a0c911005a")
    IVsSccProjectEnlistmentFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDefaultEnlistment( 
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [out] */ BSTR *pbstrDefaultEnlistment,
            /* [out] */ BSTR *pbstrDefaultEnlistmentUNC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnlistmentFactoryOptions( 
            /* [retval][out] */ VSSCCENLISTMENTFACTORYOPTIONS *pvscefoOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ValidateEnlistmentEdit( 
            /* [in] */ BOOL fQuick,
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [in] */ LPCOLESTR lpszChosenEnlistment,
            /* [out] */ BSTR *pbstrChosenEnlistmentUNC,
            /* [out] */ BOOL *pfValidEnlistment) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BrowseEnlistment( 
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [in] */ LPCOLESTR lpszInitialEnlistment,
            /* [out] */ BSTR *pbstrChosenEnlistment,
            /* [out] */ BSTR *pbstrChosenEnlistmentUNC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnBeforeEnlistmentCreate( 
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [in] */ LPCOLESTR lpszEnlistment,
            /* [in] */ LPCOLESTR lpszEnlistmentUNC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterEnlistmentCreate( 
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [in] */ LPCOLESTR lpszEnlistment,
            /* [in] */ LPCOLESTR lpszEnlistmentUNC) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSccProjectEnlistmentFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSccProjectEnlistmentFactory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSccProjectEnlistmentFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSccProjectEnlistmentFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultEnlistment )( 
            IVsSccProjectEnlistmentFactory * This,
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [out] */ BSTR *pbstrDefaultEnlistment,
            /* [out] */ BSTR *pbstrDefaultEnlistmentUNC);
        
        HRESULT ( STDMETHODCALLTYPE *GetEnlistmentFactoryOptions )( 
            IVsSccProjectEnlistmentFactory * This,
            /* [retval][out] */ VSSCCENLISTMENTFACTORYOPTIONS *pvscefoOptions);
        
        HRESULT ( STDMETHODCALLTYPE *ValidateEnlistmentEdit )( 
            IVsSccProjectEnlistmentFactory * This,
            /* [in] */ BOOL fQuick,
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [in] */ LPCOLESTR lpszChosenEnlistment,
            /* [out] */ BSTR *pbstrChosenEnlistmentUNC,
            /* [out] */ BOOL *pfValidEnlistment);
        
        HRESULT ( STDMETHODCALLTYPE *BrowseEnlistment )( 
            IVsSccProjectEnlistmentFactory * This,
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [in] */ LPCOLESTR lpszInitialEnlistment,
            /* [out] */ BSTR *pbstrChosenEnlistment,
            /* [out] */ BSTR *pbstrChosenEnlistmentUNC);
        
        HRESULT ( STDMETHODCALLTYPE *OnBeforeEnlistmentCreate )( 
            IVsSccProjectEnlistmentFactory * This,
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [in] */ LPCOLESTR lpszEnlistment,
            /* [in] */ LPCOLESTR lpszEnlistmentUNC);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterEnlistmentCreate )( 
            IVsSccProjectEnlistmentFactory * This,
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [in] */ LPCOLESTR lpszEnlistment,
            /* [in] */ LPCOLESTR lpszEnlistmentUNC);
        
        END_INTERFACE
    } IVsSccProjectEnlistmentFactoryVtbl;

    interface IVsSccProjectEnlistmentFactory
    {
        CONST_VTBL struct IVsSccProjectEnlistmentFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSccProjectEnlistmentFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSccProjectEnlistmentFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSccProjectEnlistmentFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSccProjectEnlistmentFactory_GetDefaultEnlistment(This,lpszProjectPath,pbstrDefaultEnlistment,pbstrDefaultEnlistmentUNC)	\
    (This)->lpVtbl -> GetDefaultEnlistment(This,lpszProjectPath,pbstrDefaultEnlistment,pbstrDefaultEnlistmentUNC)

#define IVsSccProjectEnlistmentFactory_GetEnlistmentFactoryOptions(This,pvscefoOptions)	\
    (This)->lpVtbl -> GetEnlistmentFactoryOptions(This,pvscefoOptions)

#define IVsSccProjectEnlistmentFactory_ValidateEnlistmentEdit(This,fQuick,lpszProjectPath,lpszChosenEnlistment,pbstrChosenEnlistmentUNC,pfValidEnlistment)	\
    (This)->lpVtbl -> ValidateEnlistmentEdit(This,fQuick,lpszProjectPath,lpszChosenEnlistment,pbstrChosenEnlistmentUNC,pfValidEnlistment)

#define IVsSccProjectEnlistmentFactory_BrowseEnlistment(This,lpszProjectPath,lpszInitialEnlistment,pbstrChosenEnlistment,pbstrChosenEnlistmentUNC)	\
    (This)->lpVtbl -> BrowseEnlistment(This,lpszProjectPath,lpszInitialEnlistment,pbstrChosenEnlistment,pbstrChosenEnlistmentUNC)

#define IVsSccProjectEnlistmentFactory_OnBeforeEnlistmentCreate(This,lpszProjectPath,lpszEnlistment,lpszEnlistmentUNC)	\
    (This)->lpVtbl -> OnBeforeEnlistmentCreate(This,lpszProjectPath,lpszEnlistment,lpszEnlistmentUNC)

#define IVsSccProjectEnlistmentFactory_OnAfterEnlistmentCreate(This,lpszProjectPath,lpszEnlistment,lpszEnlistmentUNC)	\
    (This)->lpVtbl -> OnAfterEnlistmentCreate(This,lpszProjectPath,lpszEnlistment,lpszEnlistmentUNC)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSccProjectEnlistmentFactory_GetDefaultEnlistment_Proxy( 
    IVsSccProjectEnlistmentFactory * This,
    /* [in] */ LPCOLESTR lpszProjectPath,
    /* [out] */ BSTR *pbstrDefaultEnlistment,
    /* [out] */ BSTR *pbstrDefaultEnlistmentUNC);


void __RPC_STUB IVsSccProjectEnlistmentFactory_GetDefaultEnlistment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSccProjectEnlistmentFactory_GetEnlistmentFactoryOptions_Proxy( 
    IVsSccProjectEnlistmentFactory * This,
    /* [retval][out] */ VSSCCENLISTMENTFACTORYOPTIONS *pvscefoOptions);


void __RPC_STUB IVsSccProjectEnlistmentFactory_GetEnlistmentFactoryOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSccProjectEnlistmentFactory_ValidateEnlistmentEdit_Proxy( 
    IVsSccProjectEnlistmentFactory * This,
    /* [in] */ BOOL fQuick,
    /* [in] */ LPCOLESTR lpszProjectPath,
    /* [in] */ LPCOLESTR lpszChosenEnlistment,
    /* [out] */ BSTR *pbstrChosenEnlistmentUNC,
    /* [out] */ BOOL *pfValidEnlistment);


void __RPC_STUB IVsSccProjectEnlistmentFactory_ValidateEnlistmentEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSccProjectEnlistmentFactory_BrowseEnlistment_Proxy( 
    IVsSccProjectEnlistmentFactory * This,
    /* [in] */ LPCOLESTR lpszProjectPath,
    /* [in] */ LPCOLESTR lpszInitialEnlistment,
    /* [out] */ BSTR *pbstrChosenEnlistment,
    /* [out] */ BSTR *pbstrChosenEnlistmentUNC);


void __RPC_STUB IVsSccProjectEnlistmentFactory_BrowseEnlistment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSccProjectEnlistmentFactory_OnBeforeEnlistmentCreate_Proxy( 
    IVsSccProjectEnlistmentFactory * This,
    /* [in] */ LPCOLESTR lpszProjectPath,
    /* [in] */ LPCOLESTR lpszEnlistment,
    /* [in] */ LPCOLESTR lpszEnlistmentUNC);


void __RPC_STUB IVsSccProjectEnlistmentFactory_OnBeforeEnlistmentCreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSccProjectEnlistmentFactory_OnAfterEnlistmentCreate_Proxy( 
    IVsSccProjectEnlistmentFactory * This,
    /* [in] */ LPCOLESTR lpszProjectPath,
    /* [in] */ LPCOLESTR lpszEnlistment,
    /* [in] */ LPCOLESTR lpszEnlistmentUNC);


void __RPC_STUB IVsSccProjectEnlistmentFactory_OnAfterEnlistmentCreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSccProjectEnlistmentFactory_INTERFACE_DEFINED__ */


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


