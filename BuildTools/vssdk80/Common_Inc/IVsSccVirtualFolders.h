

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for ivssccvirtualfolders.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
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

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ivssccvirtualfolders_h__
#define __ivssccvirtualfolders_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsSccVirtualFolders_FWD_DEFINED__
#define __IVsSccVirtualFolders_FWD_DEFINED__
typedef interface IVsSccVirtualFolders IVsSccVirtualFolders;
#endif 	/* __IVsSccVirtualFolders_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "vsshell.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IVsSccVirtualFolders_INTERFACE_DEFINED__
#define __IVsSccVirtualFolders_INTERFACE_DEFINED__

/* interface IVsSccVirtualFolders */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVsSccVirtualFolders;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53544C4D-0ADC-4F55-BD82-7E8383C02CFB")
    IVsSccVirtualFolders : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVirtualFolders( 
            /* [in] */ VSITEMID itemid,
            /* [out] */ CALPOLESTR *pCaStringsOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsItemChildOfVirtualFolder( 
            /* [in] */ LPCOLESTR pszItemName,
            /* [out] */ VARIANT_BOOL *pfResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSccVirtualFoldersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSccVirtualFolders * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSccVirtualFolders * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSccVirtualFolders * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetVirtualFolders )( 
            IVsSccVirtualFolders * This,
            /* [in] */ VSITEMID itemid,
            /* [out] */ CALPOLESTR *pCaStringsOut);
        
        HRESULT ( STDMETHODCALLTYPE *IsItemChildOfVirtualFolder )( 
            IVsSccVirtualFolders * This,
            /* [in] */ LPCOLESTR pszItemName,
            /* [out] */ VARIANT_BOOL *pfResult);
        
        END_INTERFACE
    } IVsSccVirtualFoldersVtbl;

    interface IVsSccVirtualFolders
    {
        CONST_VTBL struct IVsSccVirtualFoldersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSccVirtualFolders_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSccVirtualFolders_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSccVirtualFolders_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSccVirtualFolders_GetVirtualFolders(This,itemid,pCaStringsOut)	\
    (This)->lpVtbl -> GetVirtualFolders(This,itemid,pCaStringsOut)

#define IVsSccVirtualFolders_IsItemChildOfVirtualFolder(This,pszItemName,pfResult)	\
    (This)->lpVtbl -> IsItemChildOfVirtualFolder(This,pszItemName,pfResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSccVirtualFolders_GetVirtualFolders_Proxy( 
    IVsSccVirtualFolders * This,
    /* [in] */ VSITEMID itemid,
    /* [out] */ CALPOLESTR *pCaStringsOut);


void __RPC_STUB IVsSccVirtualFolders_GetVirtualFolders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSccVirtualFolders_IsItemChildOfVirtualFolder_Proxy( 
    IVsSccVirtualFolders * This,
    /* [in] */ LPCOLESTR pszItemName,
    /* [out] */ VARIANT_BOOL *pfResult);


void __RPC_STUB IVsSccVirtualFolders_IsItemChildOfVirtualFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSccVirtualFolders_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


