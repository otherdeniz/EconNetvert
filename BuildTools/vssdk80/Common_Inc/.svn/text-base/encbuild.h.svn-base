

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for encbuild.idl:
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

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __encbuild_h__
#define __encbuild_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsENCRebuildableProjectCfg_FWD_DEFINED__
#define __IVsENCRebuildableProjectCfg_FWD_DEFINED__
typedef interface IVsENCRebuildableProjectCfg IVsENCRebuildableProjectCfg;
#endif 	/* __IVsENCRebuildableProjectCfg_FWD_DEFINED__ */


#ifndef __IVsENCRebuildableProjectCfg2_FWD_DEFINED__
#define __IVsENCRebuildableProjectCfg2_FWD_DEFINED__
typedef interface IVsENCRebuildableProjectCfg2 IVsENCRebuildableProjectCfg2;
#endif 	/* __IVsENCRebuildableProjectCfg2_FWD_DEFINED__ */


#ifndef __IEnumVsENCRebuildableProjectCfgs_FWD_DEFINED__
#define __IEnumVsENCRebuildableProjectCfgs_FWD_DEFINED__
typedef interface IEnumVsENCRebuildableProjectCfgs IEnumVsENCRebuildableProjectCfgs;
#endif 	/* __IEnumVsENCRebuildableProjectCfgs_FWD_DEFINED__ */


/* header files for imported files */
#include "oleidl.h"
#include "vsshell.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_encbuild_0000 */
/* [local] */ 


enum tagENC_REASON
    {	ENCReason_Precompile	= 0,
	ENCReason_Rebuild	= ENCReason_Precompile + 1
    } ;
typedef enum tagENC_REASON ENC_REASON;

#define S_ENC_NOT_SUPPORTED                 MAKE_HRESULT(0, FACILITY_ITF, 0x0001)
#define E_STATEMENT_DELETED                 MAKE_HRESULT(1, FACILITY_ITF, 0x0001)


extern RPC_IF_HANDLE __MIDL_itf_encbuild_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_encbuild_0000_v0_0_s_ifspec;

#ifndef __IVsENCRebuildableProjectCfg_INTERFACE_DEFINED__
#define __IVsENCRebuildableProjectCfg_INTERFACE_DEFINED__

/* interface IVsENCRebuildableProjectCfg */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsENCRebuildableProjectCfg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BF031840-AFB9-11d2-AE14-00A0C9110055")
    IVsENCRebuildableProjectCfg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ENCRebuild( 
            /* [in] */ IUnknown *in_pProgram,
            /* [out] */ IUnknown **out_ppSnapshot) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelENC( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ENCRelink( 
            /* [in] */ IUnknown *pENCRelinkInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartDebugging( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopDebugging( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BelongToProject( 
            /* [in] */ LPCOLESTR in_szFileName,
            /* [in] */ ENC_REASON in_ENCReason,
            /* [in] */ BOOL in_fOnContinue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetENCProjectBuildOption( 
            /* [in] */ REFGUID in_guidOption,
            /* [in] */ LPCOLESTR in_szOptionValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ENCComplete( 
            /* [in] */ BOOL in_fENCSuccess) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsENCRebuildableProjectCfgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsENCRebuildableProjectCfg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsENCRebuildableProjectCfg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsENCRebuildableProjectCfg * This);
        
        HRESULT ( STDMETHODCALLTYPE *ENCRebuild )( 
            IVsENCRebuildableProjectCfg * This,
            /* [in] */ IUnknown *in_pProgram,
            /* [out] */ IUnknown **out_ppSnapshot);
        
        HRESULT ( STDMETHODCALLTYPE *CancelENC )( 
            IVsENCRebuildableProjectCfg * This);
        
        HRESULT ( STDMETHODCALLTYPE *ENCRelink )( 
            IVsENCRebuildableProjectCfg * This,
            /* [in] */ IUnknown *pENCRelinkInfo);
        
        HRESULT ( STDMETHODCALLTYPE *StartDebugging )( 
            IVsENCRebuildableProjectCfg * This);
        
        HRESULT ( STDMETHODCALLTYPE *StopDebugging )( 
            IVsENCRebuildableProjectCfg * This);
        
        HRESULT ( STDMETHODCALLTYPE *BelongToProject )( 
            IVsENCRebuildableProjectCfg * This,
            /* [in] */ LPCOLESTR in_szFileName,
            /* [in] */ ENC_REASON in_ENCReason,
            /* [in] */ BOOL in_fOnContinue);
        
        HRESULT ( STDMETHODCALLTYPE *SetENCProjectBuildOption )( 
            IVsENCRebuildableProjectCfg * This,
            /* [in] */ REFGUID in_guidOption,
            /* [in] */ LPCOLESTR in_szOptionValue);
        
        HRESULT ( STDMETHODCALLTYPE *ENCComplete )( 
            IVsENCRebuildableProjectCfg * This,
            /* [in] */ BOOL in_fENCSuccess);
        
        END_INTERFACE
    } IVsENCRebuildableProjectCfgVtbl;

    interface IVsENCRebuildableProjectCfg
    {
        CONST_VTBL struct IVsENCRebuildableProjectCfgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsENCRebuildableProjectCfg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsENCRebuildableProjectCfg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsENCRebuildableProjectCfg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsENCRebuildableProjectCfg_ENCRebuild(This,in_pProgram,out_ppSnapshot)	\
    (This)->lpVtbl -> ENCRebuild(This,in_pProgram,out_ppSnapshot)

#define IVsENCRebuildableProjectCfg_CancelENC(This)	\
    (This)->lpVtbl -> CancelENC(This)

#define IVsENCRebuildableProjectCfg_ENCRelink(This,pENCRelinkInfo)	\
    (This)->lpVtbl -> ENCRelink(This,pENCRelinkInfo)

#define IVsENCRebuildableProjectCfg_StartDebugging(This)	\
    (This)->lpVtbl -> StartDebugging(This)

#define IVsENCRebuildableProjectCfg_StopDebugging(This)	\
    (This)->lpVtbl -> StopDebugging(This)

#define IVsENCRebuildableProjectCfg_BelongToProject(This,in_szFileName,in_ENCReason,in_fOnContinue)	\
    (This)->lpVtbl -> BelongToProject(This,in_szFileName,in_ENCReason,in_fOnContinue)

#define IVsENCRebuildableProjectCfg_SetENCProjectBuildOption(This,in_guidOption,in_szOptionValue)	\
    (This)->lpVtbl -> SetENCProjectBuildOption(This,in_guidOption,in_szOptionValue)

#define IVsENCRebuildableProjectCfg_ENCComplete(This,in_fENCSuccess)	\
    (This)->lpVtbl -> ENCComplete(This,in_fENCSuccess)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg_ENCRebuild_Proxy( 
    IVsENCRebuildableProjectCfg * This,
    /* [in] */ IUnknown *in_pProgram,
    /* [out] */ IUnknown **out_ppSnapshot);


void __RPC_STUB IVsENCRebuildableProjectCfg_ENCRebuild_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg_CancelENC_Proxy( 
    IVsENCRebuildableProjectCfg * This);


void __RPC_STUB IVsENCRebuildableProjectCfg_CancelENC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg_ENCRelink_Proxy( 
    IVsENCRebuildableProjectCfg * This,
    /* [in] */ IUnknown *pENCRelinkInfo);


void __RPC_STUB IVsENCRebuildableProjectCfg_ENCRelink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg_StartDebugging_Proxy( 
    IVsENCRebuildableProjectCfg * This);


void __RPC_STUB IVsENCRebuildableProjectCfg_StartDebugging_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg_StopDebugging_Proxy( 
    IVsENCRebuildableProjectCfg * This);


void __RPC_STUB IVsENCRebuildableProjectCfg_StopDebugging_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg_BelongToProject_Proxy( 
    IVsENCRebuildableProjectCfg * This,
    /* [in] */ LPCOLESTR in_szFileName,
    /* [in] */ ENC_REASON in_ENCReason,
    /* [in] */ BOOL in_fOnContinue);


void __RPC_STUB IVsENCRebuildableProjectCfg_BelongToProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg_SetENCProjectBuildOption_Proxy( 
    IVsENCRebuildableProjectCfg * This,
    /* [in] */ REFGUID in_guidOption,
    /* [in] */ LPCOLESTR in_szOptionValue);


void __RPC_STUB IVsENCRebuildableProjectCfg_SetENCProjectBuildOption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg_ENCComplete_Proxy( 
    IVsENCRebuildableProjectCfg * This,
    /* [in] */ BOOL in_fENCSuccess);


void __RPC_STUB IVsENCRebuildableProjectCfg_ENCComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsENCRebuildableProjectCfg_INTERFACE_DEFINED__ */


#ifndef __IVsENCRebuildableProjectCfg2_INTERFACE_DEFINED__
#define __IVsENCRebuildableProjectCfg2_INTERFACE_DEFINED__

/* interface IVsENCRebuildableProjectCfg2 */
/* [unique][uuid][object] */ 


enum enum_ENC_BREAKSTATE_REASON
    {	ENC_BREAK_NORMAL	= 0,
	ENC_BREAK_EXCEPTION	= ENC_BREAK_NORMAL + 1
    } ;
typedef DWORD ENC_BREAKSTATE_REASON;


enum enum_ASINFO
    {	ASINFO_NONE	= 0,
	ASINFO_LEAF	= 0x1,
	ASINFO_MIDSTATEMENT	= 0x2,
	ASINFO_NONUSER	= 0x4
    } ;
typedef DWORD ASINFO;


enum enum_POSITION_TYPE
    {	TEXT_POSITION_ACTIVE_STATEMENT	= 1,
	TEXT_POSITION_NEARBY_STATEMENT	= 2,
	TEXT_POSITION_NONE	= 3
    } ;
typedef DWORD POSITION_TYPE;

typedef struct _ACTVSTMT
    {
    UINT32 id;
    UINT32 methodToken;
    TextSpan tsPosition;
    BSTR filename;
    ASINFO asInfo;
    POSITION_TYPE posType;
    } 	ENC_ACTIVE_STATEMENT;

typedef /* [public][public] */ 
enum __MIDL_IVsENCRebuildableProjectCfg2_0001
    {	ENC_NOT_MODIFIED	= 0,
	ENC_NONCONTINUABLE_ERRORS	= ENC_NOT_MODIFIED + 1,
	ENC_COMPILE_ERRORS	= ENC_NONCONTINUABLE_ERRORS + 1,
	ENC_APPLY_READY	= ENC_COMPILE_ERRORS + 1
    } 	ENC_BUILD_STATE;

typedef struct _EXCEPTIONSPAN
    {
    UINT32 id;
    UINT32 methodToken;
    TextSpan tsPosition;
    } 	ENC_EXCEPTION_SPAN;


EXTERN_C const IID IID_IVsENCRebuildableProjectCfg2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D13E943A-9EE0-457f-8766-7D8B6BC06565")
    IVsENCRebuildableProjectCfg2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartDebuggingPE( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnterBreakStateOnPE( 
            /* [in] */ ENC_BREAKSTATE_REASON encBreakReason,
            /* [in] */ ENC_ACTIVE_STATEMENT *pActiveStatements,
            /* [in] */ UINT32 cActiveStatements) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BuildForEnc( 
            /* [in] */ IUnknown *pUpdatePE) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExitBreakStateOnPE( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopDebuggingPE( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetENCBuildState( 
            /* [out] */ ENC_BUILD_STATE *pENCBuildState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentActiveStatementPosition( 
            /* [in] */ UINT32 id,
            /* [out] */ TextSpan *ptsNewPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPEidentity( 
            /* [out] */ GUID *pMVID,
            /* [out] */ BSTR *pbstrPEName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExceptionSpanCount( 
            /* [out] */ UINT32 *pcExceptionSpan) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExceptionSpans( 
            /* [in] */ UINT32 celt,
            /* [length_is][size_is][out] */ ENC_EXCEPTION_SPAN *rgelt,
            /* [out][in] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentExceptionSpanPosition( 
            /* [in] */ UINT32 id,
            /* [out] */ TextSpan *ptsNewPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EncApplySucceeded( 
            /* [in] */ HRESULT hrApplyResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPEBuildTimeStamp( 
            /* [out][in] */ FILETIME *pTimeStamp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsENCRebuildableProjectCfg2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsENCRebuildableProjectCfg2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsENCRebuildableProjectCfg2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsENCRebuildableProjectCfg2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *StartDebuggingPE )( 
            IVsENCRebuildableProjectCfg2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnterBreakStateOnPE )( 
            IVsENCRebuildableProjectCfg2 * This,
            /* [in] */ ENC_BREAKSTATE_REASON encBreakReason,
            /* [in] */ ENC_ACTIVE_STATEMENT *pActiveStatements,
            /* [in] */ UINT32 cActiveStatements);
        
        HRESULT ( STDMETHODCALLTYPE *BuildForEnc )( 
            IVsENCRebuildableProjectCfg2 * This,
            /* [in] */ IUnknown *pUpdatePE);
        
        HRESULT ( STDMETHODCALLTYPE *ExitBreakStateOnPE )( 
            IVsENCRebuildableProjectCfg2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *StopDebuggingPE )( 
            IVsENCRebuildableProjectCfg2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetENCBuildState )( 
            IVsENCRebuildableProjectCfg2 * This,
            /* [out] */ ENC_BUILD_STATE *pENCBuildState);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentActiveStatementPosition )( 
            IVsENCRebuildableProjectCfg2 * This,
            /* [in] */ UINT32 id,
            /* [out] */ TextSpan *ptsNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *GetPEidentity )( 
            IVsENCRebuildableProjectCfg2 * This,
            /* [out] */ GUID *pMVID,
            /* [out] */ BSTR *pbstrPEName);
        
        HRESULT ( STDMETHODCALLTYPE *GetExceptionSpanCount )( 
            IVsENCRebuildableProjectCfg2 * This,
            /* [out] */ UINT32 *pcExceptionSpan);
        
        HRESULT ( STDMETHODCALLTYPE *GetExceptionSpans )( 
            IVsENCRebuildableProjectCfg2 * This,
            /* [in] */ UINT32 celt,
            /* [length_is][size_is][out] */ ENC_EXCEPTION_SPAN *rgelt,
            /* [out][in] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentExceptionSpanPosition )( 
            IVsENCRebuildableProjectCfg2 * This,
            /* [in] */ UINT32 id,
            /* [out] */ TextSpan *ptsNewPosition);
        
        HRESULT ( STDMETHODCALLTYPE *EncApplySucceeded )( 
            IVsENCRebuildableProjectCfg2 * This,
            /* [in] */ HRESULT hrApplyResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetPEBuildTimeStamp )( 
            IVsENCRebuildableProjectCfg2 * This,
            /* [out][in] */ FILETIME *pTimeStamp);
        
        END_INTERFACE
    } IVsENCRebuildableProjectCfg2Vtbl;

    interface IVsENCRebuildableProjectCfg2
    {
        CONST_VTBL struct IVsENCRebuildableProjectCfg2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsENCRebuildableProjectCfg2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsENCRebuildableProjectCfg2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsENCRebuildableProjectCfg2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsENCRebuildableProjectCfg2_StartDebuggingPE(This)	\
    (This)->lpVtbl -> StartDebuggingPE(This)

#define IVsENCRebuildableProjectCfg2_EnterBreakStateOnPE(This,encBreakReason,pActiveStatements,cActiveStatements)	\
    (This)->lpVtbl -> EnterBreakStateOnPE(This,encBreakReason,pActiveStatements,cActiveStatements)

#define IVsENCRebuildableProjectCfg2_BuildForEnc(This,pUpdatePE)	\
    (This)->lpVtbl -> BuildForEnc(This,pUpdatePE)

#define IVsENCRebuildableProjectCfg2_ExitBreakStateOnPE(This)	\
    (This)->lpVtbl -> ExitBreakStateOnPE(This)

#define IVsENCRebuildableProjectCfg2_StopDebuggingPE(This)	\
    (This)->lpVtbl -> StopDebuggingPE(This)

#define IVsENCRebuildableProjectCfg2_GetENCBuildState(This,pENCBuildState)	\
    (This)->lpVtbl -> GetENCBuildState(This,pENCBuildState)

#define IVsENCRebuildableProjectCfg2_GetCurrentActiveStatementPosition(This,id,ptsNewPosition)	\
    (This)->lpVtbl -> GetCurrentActiveStatementPosition(This,id,ptsNewPosition)

#define IVsENCRebuildableProjectCfg2_GetPEidentity(This,pMVID,pbstrPEName)	\
    (This)->lpVtbl -> GetPEidentity(This,pMVID,pbstrPEName)

#define IVsENCRebuildableProjectCfg2_GetExceptionSpanCount(This,pcExceptionSpan)	\
    (This)->lpVtbl -> GetExceptionSpanCount(This,pcExceptionSpan)

#define IVsENCRebuildableProjectCfg2_GetExceptionSpans(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> GetExceptionSpans(This,celt,rgelt,pceltFetched)

#define IVsENCRebuildableProjectCfg2_GetCurrentExceptionSpanPosition(This,id,ptsNewPosition)	\
    (This)->lpVtbl -> GetCurrentExceptionSpanPosition(This,id,ptsNewPosition)

#define IVsENCRebuildableProjectCfg2_EncApplySucceeded(This,hrApplyResult)	\
    (This)->lpVtbl -> EncApplySucceeded(This,hrApplyResult)

#define IVsENCRebuildableProjectCfg2_GetPEBuildTimeStamp(This,pTimeStamp)	\
    (This)->lpVtbl -> GetPEBuildTimeStamp(This,pTimeStamp)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_StartDebuggingPE_Proxy( 
    IVsENCRebuildableProjectCfg2 * This);


void __RPC_STUB IVsENCRebuildableProjectCfg2_StartDebuggingPE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_EnterBreakStateOnPE_Proxy( 
    IVsENCRebuildableProjectCfg2 * This,
    /* [in] */ ENC_BREAKSTATE_REASON encBreakReason,
    /* [in] */ ENC_ACTIVE_STATEMENT *pActiveStatements,
    /* [in] */ UINT32 cActiveStatements);


void __RPC_STUB IVsENCRebuildableProjectCfg2_EnterBreakStateOnPE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_BuildForEnc_Proxy( 
    IVsENCRebuildableProjectCfg2 * This,
    /* [in] */ IUnknown *pUpdatePE);


void __RPC_STUB IVsENCRebuildableProjectCfg2_BuildForEnc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_ExitBreakStateOnPE_Proxy( 
    IVsENCRebuildableProjectCfg2 * This);


void __RPC_STUB IVsENCRebuildableProjectCfg2_ExitBreakStateOnPE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_StopDebuggingPE_Proxy( 
    IVsENCRebuildableProjectCfg2 * This);


void __RPC_STUB IVsENCRebuildableProjectCfg2_StopDebuggingPE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_GetENCBuildState_Proxy( 
    IVsENCRebuildableProjectCfg2 * This,
    /* [out] */ ENC_BUILD_STATE *pENCBuildState);


void __RPC_STUB IVsENCRebuildableProjectCfg2_GetENCBuildState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_GetCurrentActiveStatementPosition_Proxy( 
    IVsENCRebuildableProjectCfg2 * This,
    /* [in] */ UINT32 id,
    /* [out] */ TextSpan *ptsNewPosition);


void __RPC_STUB IVsENCRebuildableProjectCfg2_GetCurrentActiveStatementPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_GetPEidentity_Proxy( 
    IVsENCRebuildableProjectCfg2 * This,
    /* [out] */ GUID *pMVID,
    /* [out] */ BSTR *pbstrPEName);


void __RPC_STUB IVsENCRebuildableProjectCfg2_GetPEidentity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_GetExceptionSpanCount_Proxy( 
    IVsENCRebuildableProjectCfg2 * This,
    /* [out] */ UINT32 *pcExceptionSpan);


void __RPC_STUB IVsENCRebuildableProjectCfg2_GetExceptionSpanCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_GetExceptionSpans_Proxy( 
    IVsENCRebuildableProjectCfg2 * This,
    /* [in] */ UINT32 celt,
    /* [length_is][size_is][out] */ ENC_EXCEPTION_SPAN *rgelt,
    /* [out][in] */ ULONG *pceltFetched);


void __RPC_STUB IVsENCRebuildableProjectCfg2_GetExceptionSpans_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_GetCurrentExceptionSpanPosition_Proxy( 
    IVsENCRebuildableProjectCfg2 * This,
    /* [in] */ UINT32 id,
    /* [out] */ TextSpan *ptsNewPosition);


void __RPC_STUB IVsENCRebuildableProjectCfg2_GetCurrentExceptionSpanPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_EncApplySucceeded_Proxy( 
    IVsENCRebuildableProjectCfg2 * This,
    /* [in] */ HRESULT hrApplyResult);


void __RPC_STUB IVsENCRebuildableProjectCfg2_EncApplySucceeded_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsENCRebuildableProjectCfg2_GetPEBuildTimeStamp_Proxy( 
    IVsENCRebuildableProjectCfg2 * This,
    /* [out][in] */ FILETIME *pTimeStamp);


void __RPC_STUB IVsENCRebuildableProjectCfg2_GetPEBuildTimeStamp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsENCRebuildableProjectCfg2_INTERFACE_DEFINED__ */


#ifndef __IEnumVsENCRebuildableProjectCfgs_INTERFACE_DEFINED__
#define __IEnumVsENCRebuildableProjectCfgs_INTERFACE_DEFINED__

/* interface IEnumVsENCRebuildableProjectCfgs */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IEnumVsENCRebuildableProjectCfgs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3909921B-BACD-11d2-BD66-00C04FA302E2")
    IEnumVsENCRebuildableProjectCfgs : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IVsENCRebuildableProjectCfg **rgelt,
            /* [out][in] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IEnumVsENCRebuildableProjectCfgs **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcelt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEnumVsENCRebuildableProjectCfgsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEnumVsENCRebuildableProjectCfgs * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEnumVsENCRebuildableProjectCfgs * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEnumVsENCRebuildableProjectCfgs * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IEnumVsENCRebuildableProjectCfgs * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IVsENCRebuildableProjectCfg **rgelt,
            /* [out][in] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IEnumVsENCRebuildableProjectCfgs * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IEnumVsENCRebuildableProjectCfgs * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IEnumVsENCRebuildableProjectCfgs * This,
            /* [out] */ IEnumVsENCRebuildableProjectCfgs **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IEnumVsENCRebuildableProjectCfgs * This,
            /* [out] */ ULONG *pcelt);
        
        END_INTERFACE
    } IEnumVsENCRebuildableProjectCfgsVtbl;

    interface IEnumVsENCRebuildableProjectCfgs
    {
        CONST_VTBL struct IEnumVsENCRebuildableProjectCfgsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEnumVsENCRebuildableProjectCfgs_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IEnumVsENCRebuildableProjectCfgs_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IEnumVsENCRebuildableProjectCfgs_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IEnumVsENCRebuildableProjectCfgs_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IEnumVsENCRebuildableProjectCfgs_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IEnumVsENCRebuildableProjectCfgs_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IEnumVsENCRebuildableProjectCfgs_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#define IEnumVsENCRebuildableProjectCfgs_GetCount(This,pcelt)	\
    (This)->lpVtbl -> GetCount(This,pcelt)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IEnumVsENCRebuildableProjectCfgs_Next_Proxy( 
    IEnumVsENCRebuildableProjectCfgs * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IVsENCRebuildableProjectCfg **rgelt,
    /* [out][in] */ ULONG *pceltFetched);


void __RPC_STUB IEnumVsENCRebuildableProjectCfgs_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumVsENCRebuildableProjectCfgs_Skip_Proxy( 
    IEnumVsENCRebuildableProjectCfgs * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IEnumVsENCRebuildableProjectCfgs_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumVsENCRebuildableProjectCfgs_Reset_Proxy( 
    IEnumVsENCRebuildableProjectCfgs * This);


void __RPC_STUB IEnumVsENCRebuildableProjectCfgs_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumVsENCRebuildableProjectCfgs_Clone_Proxy( 
    IEnumVsENCRebuildableProjectCfgs * This,
    /* [out] */ IEnumVsENCRebuildableProjectCfgs **ppEnum);


void __RPC_STUB IEnumVsENCRebuildableProjectCfgs_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IEnumVsENCRebuildableProjectCfgs_GetCount_Proxy( 
    IEnumVsENCRebuildableProjectCfgs * This,
    /* [out] */ ULONG *pcelt);


void __RPC_STUB IEnumVsENCRebuildableProjectCfgs_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IEnumVsENCRebuildableProjectCfgs_INTERFACE_DEFINED__ */


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


