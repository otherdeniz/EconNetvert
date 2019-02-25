

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for ivssccopenfromsourcecontrol.idl:
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

#ifndef __ivssccopenfromsourcecontrol_h__
#define __ivssccopenfromsourcecontrol_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsSccOpenFromSourceControl_FWD_DEFINED__
#define __IVsSccOpenFromSourceControl_FWD_DEFINED__
typedef interface IVsSccOpenFromSourceControl IVsSccOpenFromSourceControl;
#endif 	/* __IVsSccOpenFromSourceControl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "vsshell.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_ivssccopenfromsourcecontrol_0000 */
/* [local] */ 

#pragma once

enum __VSOPENFROMSCCDLG
    {	VSOFSD_OPENSOLUTIONORPROJECT	= 1,
	VSOFSD_ADDEXISTINGITEM	= 2
    } ;
typedef LONG VSOPENFROMSCCDLG;



extern RPC_IF_HANDLE __MIDL_itf_ivssccopenfromsourcecontrol_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ivssccopenfromsourcecontrol_0000_v0_0_s_ifspec;

#ifndef __IVsSccOpenFromSourceControl_INTERFACE_DEFINED__
#define __IVsSccOpenFromSourceControl_INTERFACE_DEFINED__

/* interface IVsSccOpenFromSourceControl */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsSccOpenFromSourceControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A341396A-1B4A-4164-8E6E-BDDC527C861C")
    IVsSccOpenFromSourceControl : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OpenSolutionFromSourceControl( 
            /* [in] */ LPCOLESTR pszSolutionStoreUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddProjectFromSourceControl( 
            /* [in] */ LPCOLESTR pszProjectStoreUrl) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddItemFromSourceControl( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ ULONG cFilesToAdd,
            /* [size_is][in] */ LPCOLESTR rgpszFilesToAdd[  ],
            /* [in] */ HWND hwndDlgOwner,
            /* [in] */ VSSPECIFICEDITORFLAGS grfEditorFlags,
            /* [in] */ REFGUID rguidEditorType,
            /* [in] */ LPCOLESTR pszPhysicalView,
            /* [in] */ REFGUID rguidLogicalView,
            /* [retval][out] */ VSADDRESULT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNamespaceExtensionInformation( 
            /* [in] */ VSOPENFROMSCCDLG vsofsdDlg,
            /* [out] */ BSTR *pbstrNamespaceGUID,
            /* [out] */ BSTR *pbstrTrayDisplayName,
            /* [out] */ BSTR *pbstrProtocolPrefix) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSccOpenFromSourceControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSccOpenFromSourceControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSccOpenFromSourceControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSccOpenFromSourceControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *OpenSolutionFromSourceControl )( 
            IVsSccOpenFromSourceControl * This,
            /* [in] */ LPCOLESTR pszSolutionStoreUrl);
        
        HRESULT ( STDMETHODCALLTYPE *AddProjectFromSourceControl )( 
            IVsSccOpenFromSourceControl * This,
            /* [in] */ LPCOLESTR pszProjectStoreUrl);
        
        HRESULT ( STDMETHODCALLTYPE *AddItemFromSourceControl )( 
            IVsSccOpenFromSourceControl * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ ULONG cFilesToAdd,
            /* [size_is][in] */ LPCOLESTR rgpszFilesToAdd[  ],
            /* [in] */ HWND hwndDlgOwner,
            /* [in] */ VSSPECIFICEDITORFLAGS grfEditorFlags,
            /* [in] */ REFGUID rguidEditorType,
            /* [in] */ LPCOLESTR pszPhysicalView,
            /* [in] */ REFGUID rguidLogicalView,
            /* [retval][out] */ VSADDRESULT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetNamespaceExtensionInformation )( 
            IVsSccOpenFromSourceControl * This,
            /* [in] */ VSOPENFROMSCCDLG vsofsdDlg,
            /* [out] */ BSTR *pbstrNamespaceGUID,
            /* [out] */ BSTR *pbstrTrayDisplayName,
            /* [out] */ BSTR *pbstrProtocolPrefix);
        
        END_INTERFACE
    } IVsSccOpenFromSourceControlVtbl;

    interface IVsSccOpenFromSourceControl
    {
        CONST_VTBL struct IVsSccOpenFromSourceControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSccOpenFromSourceControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSccOpenFromSourceControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSccOpenFromSourceControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSccOpenFromSourceControl_OpenSolutionFromSourceControl(This,pszSolutionStoreUrl)	\
    (This)->lpVtbl -> OpenSolutionFromSourceControl(This,pszSolutionStoreUrl)

#define IVsSccOpenFromSourceControl_AddProjectFromSourceControl(This,pszProjectStoreUrl)	\
    (This)->lpVtbl -> AddProjectFromSourceControl(This,pszProjectStoreUrl)

#define IVsSccOpenFromSourceControl_AddItemFromSourceControl(This,pProject,itemidLoc,cFilesToAdd,rgpszFilesToAdd,hwndDlgOwner,grfEditorFlags,rguidEditorType,pszPhysicalView,rguidLogicalView,pResult)	\
    (This)->lpVtbl -> AddItemFromSourceControl(This,pProject,itemidLoc,cFilesToAdd,rgpszFilesToAdd,hwndDlgOwner,grfEditorFlags,rguidEditorType,pszPhysicalView,rguidLogicalView,pResult)

#define IVsSccOpenFromSourceControl_GetNamespaceExtensionInformation(This,vsofsdDlg,pbstrNamespaceGUID,pbstrTrayDisplayName,pbstrProtocolPrefix)	\
    (This)->lpVtbl -> GetNamespaceExtensionInformation(This,vsofsdDlg,pbstrNamespaceGUID,pbstrTrayDisplayName,pbstrProtocolPrefix)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSccOpenFromSourceControl_OpenSolutionFromSourceControl_Proxy( 
    IVsSccOpenFromSourceControl * This,
    /* [in] */ LPCOLESTR pszSolutionStoreUrl);


void __RPC_STUB IVsSccOpenFromSourceControl_OpenSolutionFromSourceControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSccOpenFromSourceControl_AddProjectFromSourceControl_Proxy( 
    IVsSccOpenFromSourceControl * This,
    /* [in] */ LPCOLESTR pszProjectStoreUrl);


void __RPC_STUB IVsSccOpenFromSourceControl_AddProjectFromSourceControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSccOpenFromSourceControl_AddItemFromSourceControl_Proxy( 
    IVsSccOpenFromSourceControl * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ VSITEMID itemidLoc,
    /* [in] */ ULONG cFilesToAdd,
    /* [size_is][in] */ LPCOLESTR rgpszFilesToAdd[  ],
    /* [in] */ HWND hwndDlgOwner,
    /* [in] */ VSSPECIFICEDITORFLAGS grfEditorFlags,
    /* [in] */ REFGUID rguidEditorType,
    /* [in] */ LPCOLESTR pszPhysicalView,
    /* [in] */ REFGUID rguidLogicalView,
    /* [retval][out] */ VSADDRESULT *pResult);


void __RPC_STUB IVsSccOpenFromSourceControl_AddItemFromSourceControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSccOpenFromSourceControl_GetNamespaceExtensionInformation_Proxy( 
    IVsSccOpenFromSourceControl * This,
    /* [in] */ VSOPENFROMSCCDLG vsofsdDlg,
    /* [out] */ BSTR *pbstrNamespaceGUID,
    /* [out] */ BSTR *pbstrTrayDisplayName,
    /* [out] */ BSTR *pbstrProtocolPrefix);


void __RPC_STUB IVsSccOpenFromSourceControl_GetNamespaceExtensionInformation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSccOpenFromSourceControl_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


