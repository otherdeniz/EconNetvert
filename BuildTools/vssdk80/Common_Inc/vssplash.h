

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for vssplash.idl:
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

#ifndef __vssplash_h__
#define __vssplash_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsInstalledProduct_FWD_DEFINED__
#define __IVsInstalledProduct_FWD_DEFINED__
typedef interface IVsInstalledProduct IVsInstalledProduct;
#endif 	/* __IVsInstalledProduct_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_vssplash_0000 */
/* [local] */ 

#define VS_SPLASH_BMP_HEIGHT 70
#define VS_SPLASH_BMP_WIDTH 88


extern RPC_IF_HANDLE __MIDL_itf_vssplash_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vssplash_0000_v0_0_s_ifspec;

#ifndef __IVsInstalledProduct_INTERFACE_DEFINED__
#define __IVsInstalledProduct_INTERFACE_DEFINED__

/* interface IVsInstalledProduct */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsInstalledProduct;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("098FCA58-5F42-11d3-8BDC-00C04F8EC28C")
    IVsInstalledProduct : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IdBmpSplash( 
            /* [retval][out] */ UINT *pIdBmp) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_OfficialName( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProductID( 
            /* [retval][out] */ BSTR *pbstrPID) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProductDetails( 
            /* [retval][out] */ BSTR *pbstrProductDetails) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IdIcoLogoForAboutbox( 
            /* [retval][out] */ UINT *pIdIco) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsInstalledProductVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsInstalledProduct * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsInstalledProduct * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsInstalledProduct * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IdBmpSplash )( 
            IVsInstalledProduct * This,
            /* [retval][out] */ UINT *pIdBmp);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_OfficialName )( 
            IVsInstalledProduct * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProductID )( 
            IVsInstalledProduct * This,
            /* [retval][out] */ BSTR *pbstrPID);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_ProductDetails )( 
            IVsInstalledProduct * This,
            /* [retval][out] */ BSTR *pbstrProductDetails);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IdIcoLogoForAboutbox )( 
            IVsInstalledProduct * This,
            /* [retval][out] */ UINT *pIdIco);
        
        END_INTERFACE
    } IVsInstalledProductVtbl;

    interface IVsInstalledProduct
    {
        CONST_VTBL struct IVsInstalledProductVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsInstalledProduct_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsInstalledProduct_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsInstalledProduct_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsInstalledProduct_get_IdBmpSplash(This,pIdBmp)	\
    (This)->lpVtbl -> get_IdBmpSplash(This,pIdBmp)

#define IVsInstalledProduct_get_OfficialName(This,pbstrName)	\
    (This)->lpVtbl -> get_OfficialName(This,pbstrName)

#define IVsInstalledProduct_get_ProductID(This,pbstrPID)	\
    (This)->lpVtbl -> get_ProductID(This,pbstrPID)

#define IVsInstalledProduct_get_ProductDetails(This,pbstrProductDetails)	\
    (This)->lpVtbl -> get_ProductDetails(This,pbstrProductDetails)

#define IVsInstalledProduct_get_IdIcoLogoForAboutbox(This,pIdIco)	\
    (This)->lpVtbl -> get_IdIcoLogoForAboutbox(This,pIdIco)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IVsInstalledProduct_get_IdBmpSplash_Proxy( 
    IVsInstalledProduct * This,
    /* [retval][out] */ UINT *pIdBmp);


void __RPC_STUB IVsInstalledProduct_get_IdBmpSplash_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsInstalledProduct_get_OfficialName_Proxy( 
    IVsInstalledProduct * This,
    /* [retval][out] */ BSTR *pbstrName);


void __RPC_STUB IVsInstalledProduct_get_OfficialName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsInstalledProduct_get_ProductID_Proxy( 
    IVsInstalledProduct * This,
    /* [retval][out] */ BSTR *pbstrPID);


void __RPC_STUB IVsInstalledProduct_get_ProductID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsInstalledProduct_get_ProductDetails_Proxy( 
    IVsInstalledProduct * This,
    /* [retval][out] */ BSTR *pbstrProductDetails);


void __RPC_STUB IVsInstalledProduct_get_ProductDetails_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsInstalledProduct_get_IdIcoLogoForAboutbox_Proxy( 
    IVsInstalledProduct * This,
    /* [retval][out] */ UINT *pIdIco);


void __RPC_STUB IVsInstalledProduct_get_IdIcoLogoForAboutbox_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsInstalledProduct_INTERFACE_DEFINED__ */


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


