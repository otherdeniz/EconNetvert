

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for singlefileeditor.idl:
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

#ifndef __singlefileeditor_h__
#define __singlefileeditor_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsIntellisenseHost_FWD_DEFINED__
#define __IVsIntellisenseHost_FWD_DEFINED__
typedef interface IVsIntellisenseHost IVsIntellisenseHost;
#endif 	/* __IVsIntellisenseHost_FWD_DEFINED__ */


#ifndef __IVsTextViewIntellisenseHost_FWD_DEFINED__
#define __IVsTextViewIntellisenseHost_FWD_DEFINED__
typedef interface IVsTextViewIntellisenseHost IVsTextViewIntellisenseHost;
#endif 	/* __IVsTextViewIntellisenseHost_FWD_DEFINED__ */


#ifndef __IVsTextViewIntellisenseHostProvider_FWD_DEFINED__
#define __IVsTextViewIntellisenseHostProvider_FWD_DEFINED__
typedef interface IVsTextViewIntellisenseHostProvider IVsTextViewIntellisenseHostProvider;
#endif 	/* __IVsTextViewIntellisenseHostProvider_FWD_DEFINED__ */


#ifndef __VsIntellisenseCompletor_FWD_DEFINED__
#define __VsIntellisenseCompletor_FWD_DEFINED__

#ifdef __cplusplus
typedef class VsIntellisenseCompletor VsIntellisenseCompletor;
#else
typedef struct VsIntellisenseCompletor VsIntellisenseCompletor;
#endif /* __cplusplus */

#endif 	/* __VsIntellisenseCompletor_FWD_DEFINED__ */


#ifndef __IVsIntellisenseCompletor_FWD_DEFINED__
#define __IVsIntellisenseCompletor_FWD_DEFINED__
typedef interface IVsIntellisenseCompletor IVsIntellisenseCompletor;
#endif 	/* __IVsIntellisenseCompletor_FWD_DEFINED__ */


#ifndef __VsIntellisenseLangTip_FWD_DEFINED__
#define __VsIntellisenseLangTip_FWD_DEFINED__

#ifdef __cplusplus
typedef class VsIntellisenseLangTip VsIntellisenseLangTip;
#else
typedef struct VsIntellisenseLangTip VsIntellisenseLangTip;
#endif /* __cplusplus */

#endif 	/* __VsIntellisenseLangTip_FWD_DEFINED__ */


#ifndef __IVsIntellisenseLangTip_FWD_DEFINED__
#define __IVsIntellisenseLangTip_FWD_DEFINED__
typedef interface IVsIntellisenseLangTip IVsIntellisenseLangTip;
#endif 	/* __IVsIntellisenseLangTip_FWD_DEFINED__ */


#ifndef __IVsContainedLanguageHost_FWD_DEFINED__
#define __IVsContainedLanguageHost_FWD_DEFINED__
typedef interface IVsContainedLanguageHost IVsContainedLanguageHost;
#endif 	/* __IVsContainedLanguageHost_FWD_DEFINED__ */


#ifndef __IVsContainedLanguageHostEvents_FWD_DEFINED__
#define __IVsContainedLanguageHostEvents_FWD_DEFINED__
typedef interface IVsContainedLanguageHostEvents IVsContainedLanguageHostEvents;
#endif 	/* __IVsContainedLanguageHostEvents_FWD_DEFINED__ */


#ifndef __IVsContainedLanguage_FWD_DEFINED__
#define __IVsContainedLanguage_FWD_DEFINED__
typedef interface IVsContainedLanguage IVsContainedLanguage;
#endif 	/* __IVsContainedLanguage_FWD_DEFINED__ */


#ifndef __IVsContainedLanguageColorizer_FWD_DEFINED__
#define __IVsContainedLanguageColorizer_FWD_DEFINED__
typedef interface IVsContainedLanguageColorizer IVsContainedLanguageColorizer;
#endif 	/* __IVsContainedLanguageColorizer_FWD_DEFINED__ */


#ifndef __IVsContainedLanguageCodeSupport_FWD_DEFINED__
#define __IVsContainedLanguageCodeSupport_FWD_DEFINED__
typedef interface IVsContainedLanguageCodeSupport IVsContainedLanguageCodeSupport;
#endif 	/* __IVsContainedLanguageCodeSupport_FWD_DEFINED__ */


#ifndef __IVsContainedLanguageStaticEventBinding_FWD_DEFINED__
#define __IVsContainedLanguageStaticEventBinding_FWD_DEFINED__
typedef interface IVsContainedLanguageStaticEventBinding IVsContainedLanguageStaticEventBinding;
#endif 	/* __IVsContainedLanguageStaticEventBinding_FWD_DEFINED__ */


#ifndef __IVsWebFormDesignerSupport_FWD_DEFINED__
#define __IVsWebFormDesignerSupport_FWD_DEFINED__
typedef interface IVsWebFormDesignerSupport IVsWebFormDesignerSupport;
#endif 	/* __IVsWebFormDesignerSupport_FWD_DEFINED__ */


#ifndef __IVsEnumCodeBlocks_FWD_DEFINED__
#define __IVsEnumCodeBlocks_FWD_DEFINED__
typedef interface IVsEnumCodeBlocks IVsEnumCodeBlocks;
#endif 	/* __IVsEnumCodeBlocks_FWD_DEFINED__ */


#ifndef __IVsContainedCode_FWD_DEFINED__
#define __IVsContainedCode_FWD_DEFINED__
typedef interface IVsContainedCode IVsContainedCode;
#endif 	/* __IVsContainedCode_FWD_DEFINED__ */


#ifndef __IVsContainedLanguageFactory_FWD_DEFINED__
#define __IVsContainedLanguageFactory_FWD_DEFINED__
typedef interface IVsContainedLanguageFactory IVsContainedLanguageFactory;
#endif 	/* __IVsContainedLanguageFactory_FWD_DEFINED__ */


#ifndef __IVsContainedLanguageProjectNameProvider_FWD_DEFINED__
#define __IVsContainedLanguageProjectNameProvider_FWD_DEFINED__
typedef interface IVsContainedLanguageProjectNameProvider IVsContainedLanguageProjectNameProvider;
#endif 	/* __IVsContainedLanguageProjectNameProvider_FWD_DEFINED__ */


#ifndef __IVsEnumBufferCoordinatorSpans_FWD_DEFINED__
#define __IVsEnumBufferCoordinatorSpans_FWD_DEFINED__
typedef interface IVsEnumBufferCoordinatorSpans IVsEnumBufferCoordinatorSpans;
#endif 	/* __IVsEnumBufferCoordinatorSpans_FWD_DEFINED__ */


#ifndef __VsTextBufferCoordinator_FWD_DEFINED__
#define __VsTextBufferCoordinator_FWD_DEFINED__

#ifdef __cplusplus
typedef class VsTextBufferCoordinator VsTextBufferCoordinator;
#else
typedef struct VsTextBufferCoordinator VsTextBufferCoordinator;
#endif /* __cplusplus */

#endif 	/* __VsTextBufferCoordinator_FWD_DEFINED__ */


#ifndef __IVsTextBufferCoordinator_FWD_DEFINED__
#define __IVsTextBufferCoordinator_FWD_DEFINED__
typedef interface IVsTextBufferCoordinator IVsTextBufferCoordinator;
#endif 	/* __IVsTextBufferCoordinator_FWD_DEFINED__ */


#ifndef __IVsSetSpanMappingEvents_FWD_DEFINED__
#define __IVsSetSpanMappingEvents_FWD_DEFINED__
typedef interface IVsSetSpanMappingEvents IVsSetSpanMappingEvents;
#endif 	/* __IVsSetSpanMappingEvents_FWD_DEFINED__ */


#ifndef __IVsExternalCompletionSet_FWD_DEFINED__
#define __IVsExternalCompletionSet_FWD_DEFINED__
typedef interface IVsExternalCompletionSet IVsExternalCompletionSet;
#endif 	/* __IVsExternalCompletionSet_FWD_DEFINED__ */


#ifndef __IVsExpansionIntellisenseHost_FWD_DEFINED__
#define __IVsExpansionIntellisenseHost_FWD_DEFINED__
typedef interface IVsExpansionIntellisenseHost IVsExpansionIntellisenseHost;
#endif 	/* __IVsExpansionIntellisenseHost_FWD_DEFINED__ */


#ifndef __IVsReportExternalErrors_FWD_DEFINED__
#define __IVsReportExternalErrors_FWD_DEFINED__
typedef interface IVsReportExternalErrors IVsReportExternalErrors;
#endif 	/* __IVsReportExternalErrors_FWD_DEFINED__ */


#ifndef __IVsEnumExternalErrors_FWD_DEFINED__
#define __IVsEnumExternalErrors_FWD_DEFINED__
typedef interface IVsEnumExternalErrors IVsEnumExternalErrors;
#endif 	/* __IVsEnumExternalErrors_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "oleidl.h"
#include "textmgr.h"
#include "textmgr2.h"
#include "vsshell.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_singlefileeditor_0000 */
/* [local] */ 

#pragma once













typedef struct _TEXTSPANPAIR
    {
    TextSpan span1;
    TextSpan span2;
    } 	TextSpanPair;

typedef struct _TEXTSPANANDCOOKIE
    {
    ULONG ulHTMLCookie;
    TextSpan CodeSpan;
    } 	TextSpanAndCookie;


enum IntellisenseHostFlags
    {	IHF_READONLYCONTEXT	= 0x1,
	IHF_NOSEPARATESUBJECT	= 0x2,
	IHF_SINGLELINESUBJECT	= 0x4,
	IHF_FORCECOMMITTOCONTEXT	= 0x8,
	IHF_OVERTYPE	= 0x10
    } ;
typedef 
enum _CODEMEMBERTYPE
    {	CODEMEMBERTYPE_EVENTS	= 0x1,
	CODEMEMBERTYPE_EVENT_HANDLERS	= 0x2,
	CODEMEMBERTYPE_USER_FUNCTIONS	= 0x4
    } 	CODEMEMBERTYPE;


enum ContainedLanguageRefreshMode
    {	CLRM_COMPILEFILE	= 1,
	CLRM_COMPILEPROJECT	= 2
    } ;
typedef 
enum _CONTAINEDLANGUAGERENAMETYPE
    {	CLRT_CLASS	= 0,
	CLRT_CLASSMEMBER	= CLRT_CLASS + 1,
	CLRT_NAMESPACE	= CLRT_CLASSMEMBER + 1,
	CLRT_OTHER	= CLRT_NAMESPACE + 1
    } 	ContainedLanguageRenameType;



extern RPC_IF_HANDLE __MIDL_itf_singlefileeditor_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_singlefileeditor_0000_v0_0_s_ifspec;


#ifndef __SingleFileEditor_LIBRARY_DEFINED__
#define __SingleFileEditor_LIBRARY_DEFINED__

/* library SingleFileEditor */
/* [version][uuid] */ 

#define E_CONTAINEDLANGUAGE_CANNOTFINDITEM MAKE_HRESULT(1, FACILITY_ITF, 0x8003)
#define E_CONTAINEDLANGUAGE_RENAMECANCELLED MAKE_HRESULT(1, FACILITY_ITF, 0x8004)
typedef struct _tag_NewSpanMapping
    {
    TextSpanPair tspSpans;
    VARIANT varUserData;
    } 	NewSpanMapping;

typedef struct _tag_ExternalError
    {
    long iLine;
    long iCol;
    long iErrorID;
    BOOL fError;
    BSTR bstrText;
    BSTR bstrFileName;
    } 	ExternalError;


enum BufferCoordinatorReplicationDirection
    {	BCRD_PRIMARY_TO_SECONDARY	= 1,
	BCRD_SECONDARY_TO_PRIMARY	= 2
    } ;

enum _BufferCoordinatorMappingMode
    {	BCMM_NORMAL	= 0,
	BCMM_EXTENDEDLEFT	= 0x2,
	BCMM_EXTENDEDRIGHT	= 0x1,
	BCMM_EXTENDED	= 0x3,
	BCMM_ENTIREBUFFER	= 0x4
    } ;
typedef DWORD BufferCoordinatorMappingMode;


EXTERN_C const IID LIBID_SingleFileEditor;

#ifndef __IVsIntellisenseHost_INTERFACE_DEFINED__
#define __IVsIntellisenseHost_INTERFACE_DEFINED__

/* interface IVsIntellisenseHost */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsIntellisenseHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0377986B-C450-453c-A7BE-67116C9129A6")
    IVsIntellisenseHost : public IOleCommandTarget
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetHostFlags( 
            /* [retval][out] */ DWORD *pdwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextBuffer( 
            /* [retval][out] */ IVsTextLines **ppCtxBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextFocalPoint( 
            /* [out] */ TextSpan *pSpan,
            long *piLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetContextCaretPos( 
            /* [in] */ long iLine,
            /* [in] */ long iIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextCaretPos( 
            /* [out] */ long *piLine,
            /* [out] */ long *piIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetContextSelection( 
            /* [in] */ long iStartLine,
            /* [in] */ long iStartIndex,
            /* [in] */ long iEndLine,
            /* [in] */ long iEndIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextSelection( 
            /* [out] */ TextSpan *pSelectionSpan) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubjectText( 
            /* [retval][out] */ BSTR *pbstrSubjectText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSubjectCaretPos( 
            /* [in] */ long iIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubjectCaretPos( 
            /* [out] */ long *piIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSubjectSelection( 
            /* [in] */ long iAnchorIndex,
            /* [in] */ long iEndIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubjectSelection( 
            /* [out] */ long *piAnchorIndex,
            /* [out] */ long *piEndIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReplaceSubjectTextSpan( 
            /* [in] */ long iStartIndex,
            /* [in] */ long iEndIndex,
            /* [in] */ LPCWSTR pszText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateCompletionStatus( 
            /* [in] */ IVsCompletionSet *pCompSet,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateTipWindow( 
            /* [in] */ IVsTipWindow *pTipWindow,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HighlightMatchingBrace( 
            /* [in] */ DWORD dwFlags,
            /* [in] */ ULONG cSpans,
            /* [size_is][in] */ TextSpan *rgBaseSpans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeforeCompletorCommit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AfterCompletorCommit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServiceProvider( 
            /* [out] */ IServiceProvider **ppSP) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHostWindow( 
            /* [out] */ HWND *hwnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextLocation( 
            /* [in] */ long iPos,
            /* [in] */ long iLen,
            /* [in] */ BOOL fUseCaretPosition,
            /* [out] */ RECT *prc,
            /* [out] */ long *piTopX) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateSmartTagWindow( 
            /* [in] */ IVsSmartTagTipWindow *pSmartTagWnd,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSmartTagRect( 
            /* [out] */ RECT *rcSmartTag) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsIntellisenseHostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsIntellisenseHost * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsIntellisenseHost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsIntellisenseHost * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IVsIntellisenseHost * This,
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ ULONG cCmds,
            /* [out][in][size_is] */ OLECMD prgCmds[  ],
            /* [unique][out][in] */ OLECMDTEXT *pCmdText);
        
        HRESULT ( STDMETHODCALLTYPE *Exec )( 
            IVsIntellisenseHost * This,
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ DWORD nCmdID,
            /* [in] */ DWORD nCmdexecopt,
            /* [unique][in] */ VARIANT *pvaIn,
            /* [unique][out][in] */ VARIANT *pvaOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetHostFlags )( 
            IVsIntellisenseHost * This,
            /* [retval][out] */ DWORD *pdwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextBuffer )( 
            IVsIntellisenseHost * This,
            /* [retval][out] */ IVsTextLines **ppCtxBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextFocalPoint )( 
            IVsIntellisenseHost * This,
            /* [out] */ TextSpan *pSpan,
            long *piLen);
        
        HRESULT ( STDMETHODCALLTYPE *SetContextCaretPos )( 
            IVsIntellisenseHost * This,
            /* [in] */ long iLine,
            /* [in] */ long iIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextCaretPos )( 
            IVsIntellisenseHost * This,
            /* [out] */ long *piLine,
            /* [out] */ long *piIndex);
        
        HRESULT ( STDMETHODCALLTYPE *SetContextSelection )( 
            IVsIntellisenseHost * This,
            /* [in] */ long iStartLine,
            /* [in] */ long iStartIndex,
            /* [in] */ long iEndLine,
            /* [in] */ long iEndIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextSelection )( 
            IVsIntellisenseHost * This,
            /* [out] */ TextSpan *pSelectionSpan);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubjectText )( 
            IVsIntellisenseHost * This,
            /* [retval][out] */ BSTR *pbstrSubjectText);
        
        HRESULT ( STDMETHODCALLTYPE *SetSubjectCaretPos )( 
            IVsIntellisenseHost * This,
            /* [in] */ long iIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubjectCaretPos )( 
            IVsIntellisenseHost * This,
            /* [out] */ long *piIndex);
        
        HRESULT ( STDMETHODCALLTYPE *SetSubjectSelection )( 
            IVsIntellisenseHost * This,
            /* [in] */ long iAnchorIndex,
            /* [in] */ long iEndIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubjectSelection )( 
            IVsIntellisenseHost * This,
            /* [out] */ long *piAnchorIndex,
            /* [out] */ long *piEndIndex);
        
        HRESULT ( STDMETHODCALLTYPE *ReplaceSubjectTextSpan )( 
            IVsIntellisenseHost * This,
            /* [in] */ long iStartIndex,
            /* [in] */ long iEndIndex,
            /* [in] */ LPCWSTR pszText);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateCompletionStatus )( 
            IVsIntellisenseHost * This,
            /* [in] */ IVsCompletionSet *pCompSet,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateTipWindow )( 
            IVsIntellisenseHost * This,
            /* [in] */ IVsTipWindow *pTipWindow,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *HighlightMatchingBrace )( 
            IVsIntellisenseHost * This,
            /* [in] */ DWORD dwFlags,
            /* [in] */ ULONG cSpans,
            /* [size_is][in] */ TextSpan *rgBaseSpans);
        
        HRESULT ( STDMETHODCALLTYPE *BeforeCompletorCommit )( 
            IVsIntellisenseHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *AfterCompletorCommit )( 
            IVsIntellisenseHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceProvider )( 
            IVsIntellisenseHost * This,
            /* [out] */ IServiceProvider **ppSP);
        
        HRESULT ( STDMETHODCALLTYPE *GetHostWindow )( 
            IVsIntellisenseHost * This,
            /* [out] */ HWND *hwnd);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextLocation )( 
            IVsIntellisenseHost * This,
            /* [in] */ long iPos,
            /* [in] */ long iLen,
            /* [in] */ BOOL fUseCaretPosition,
            /* [out] */ RECT *prc,
            /* [out] */ long *piTopX);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateSmartTagWindow )( 
            IVsIntellisenseHost * This,
            /* [in] */ IVsSmartTagTipWindow *pSmartTagWnd,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetSmartTagRect )( 
            IVsIntellisenseHost * This,
            /* [out] */ RECT *rcSmartTag);
        
        END_INTERFACE
    } IVsIntellisenseHostVtbl;

    interface IVsIntellisenseHost
    {
        CONST_VTBL struct IVsIntellisenseHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsIntellisenseHost_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsIntellisenseHost_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsIntellisenseHost_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsIntellisenseHost_QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText)	\
    (This)->lpVtbl -> QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText)

#define IVsIntellisenseHost_Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut)	\
    (This)->lpVtbl -> Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut)


#define IVsIntellisenseHost_GetHostFlags(This,pdwFlags)	\
    (This)->lpVtbl -> GetHostFlags(This,pdwFlags)

#define IVsIntellisenseHost_GetContextBuffer(This,ppCtxBuffer)	\
    (This)->lpVtbl -> GetContextBuffer(This,ppCtxBuffer)

#define IVsIntellisenseHost_GetContextFocalPoint(This,pSpan,piLen)	\
    (This)->lpVtbl -> GetContextFocalPoint(This,pSpan,piLen)

#define IVsIntellisenseHost_SetContextCaretPos(This,iLine,iIndex)	\
    (This)->lpVtbl -> SetContextCaretPos(This,iLine,iIndex)

#define IVsIntellisenseHost_GetContextCaretPos(This,piLine,piIndex)	\
    (This)->lpVtbl -> GetContextCaretPos(This,piLine,piIndex)

#define IVsIntellisenseHost_SetContextSelection(This,iStartLine,iStartIndex,iEndLine,iEndIndex)	\
    (This)->lpVtbl -> SetContextSelection(This,iStartLine,iStartIndex,iEndLine,iEndIndex)

#define IVsIntellisenseHost_GetContextSelection(This,pSelectionSpan)	\
    (This)->lpVtbl -> GetContextSelection(This,pSelectionSpan)

#define IVsIntellisenseHost_GetSubjectText(This,pbstrSubjectText)	\
    (This)->lpVtbl -> GetSubjectText(This,pbstrSubjectText)

#define IVsIntellisenseHost_SetSubjectCaretPos(This,iIndex)	\
    (This)->lpVtbl -> SetSubjectCaretPos(This,iIndex)

#define IVsIntellisenseHost_GetSubjectCaretPos(This,piIndex)	\
    (This)->lpVtbl -> GetSubjectCaretPos(This,piIndex)

#define IVsIntellisenseHost_SetSubjectSelection(This,iAnchorIndex,iEndIndex)	\
    (This)->lpVtbl -> SetSubjectSelection(This,iAnchorIndex,iEndIndex)

#define IVsIntellisenseHost_GetSubjectSelection(This,piAnchorIndex,piEndIndex)	\
    (This)->lpVtbl -> GetSubjectSelection(This,piAnchorIndex,piEndIndex)

#define IVsIntellisenseHost_ReplaceSubjectTextSpan(This,iStartIndex,iEndIndex,pszText)	\
    (This)->lpVtbl -> ReplaceSubjectTextSpan(This,iStartIndex,iEndIndex,pszText)

#define IVsIntellisenseHost_UpdateCompletionStatus(This,pCompSet,dwFlags)	\
    (This)->lpVtbl -> UpdateCompletionStatus(This,pCompSet,dwFlags)

#define IVsIntellisenseHost_UpdateTipWindow(This,pTipWindow,dwFlags)	\
    (This)->lpVtbl -> UpdateTipWindow(This,pTipWindow,dwFlags)

#define IVsIntellisenseHost_HighlightMatchingBrace(This,dwFlags,cSpans,rgBaseSpans)	\
    (This)->lpVtbl -> HighlightMatchingBrace(This,dwFlags,cSpans,rgBaseSpans)

#define IVsIntellisenseHost_BeforeCompletorCommit(This)	\
    (This)->lpVtbl -> BeforeCompletorCommit(This)

#define IVsIntellisenseHost_AfterCompletorCommit(This)	\
    (This)->lpVtbl -> AfterCompletorCommit(This)

#define IVsIntellisenseHost_GetServiceProvider(This,ppSP)	\
    (This)->lpVtbl -> GetServiceProvider(This,ppSP)

#define IVsIntellisenseHost_GetHostWindow(This,hwnd)	\
    (This)->lpVtbl -> GetHostWindow(This,hwnd)

#define IVsIntellisenseHost_GetContextLocation(This,iPos,iLen,fUseCaretPosition,prc,piTopX)	\
    (This)->lpVtbl -> GetContextLocation(This,iPos,iLen,fUseCaretPosition,prc,piTopX)

#define IVsIntellisenseHost_UpdateSmartTagWindow(This,pSmartTagWnd,dwFlags)	\
    (This)->lpVtbl -> UpdateSmartTagWindow(This,pSmartTagWnd,dwFlags)

#define IVsIntellisenseHost_GetSmartTagRect(This,rcSmartTag)	\
    (This)->lpVtbl -> GetSmartTagRect(This,rcSmartTag)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetHostFlags_Proxy( 
    IVsIntellisenseHost * This,
    /* [retval][out] */ DWORD *pdwFlags);


void __RPC_STUB IVsIntellisenseHost_GetHostFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetContextBuffer_Proxy( 
    IVsIntellisenseHost * This,
    /* [retval][out] */ IVsTextLines **ppCtxBuffer);


void __RPC_STUB IVsIntellisenseHost_GetContextBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetContextFocalPoint_Proxy( 
    IVsIntellisenseHost * This,
    /* [out] */ TextSpan *pSpan,
    long *piLen);


void __RPC_STUB IVsIntellisenseHost_GetContextFocalPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_SetContextCaretPos_Proxy( 
    IVsIntellisenseHost * This,
    /* [in] */ long iLine,
    /* [in] */ long iIndex);


void __RPC_STUB IVsIntellisenseHost_SetContextCaretPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetContextCaretPos_Proxy( 
    IVsIntellisenseHost * This,
    /* [out] */ long *piLine,
    /* [out] */ long *piIndex);


void __RPC_STUB IVsIntellisenseHost_GetContextCaretPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_SetContextSelection_Proxy( 
    IVsIntellisenseHost * This,
    /* [in] */ long iStartLine,
    /* [in] */ long iStartIndex,
    /* [in] */ long iEndLine,
    /* [in] */ long iEndIndex);


void __RPC_STUB IVsIntellisenseHost_SetContextSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetContextSelection_Proxy( 
    IVsIntellisenseHost * This,
    /* [out] */ TextSpan *pSelectionSpan);


void __RPC_STUB IVsIntellisenseHost_GetContextSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetSubjectText_Proxy( 
    IVsIntellisenseHost * This,
    /* [retval][out] */ BSTR *pbstrSubjectText);


void __RPC_STUB IVsIntellisenseHost_GetSubjectText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_SetSubjectCaretPos_Proxy( 
    IVsIntellisenseHost * This,
    /* [in] */ long iIndex);


void __RPC_STUB IVsIntellisenseHost_SetSubjectCaretPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetSubjectCaretPos_Proxy( 
    IVsIntellisenseHost * This,
    /* [out] */ long *piIndex);


void __RPC_STUB IVsIntellisenseHost_GetSubjectCaretPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_SetSubjectSelection_Proxy( 
    IVsIntellisenseHost * This,
    /* [in] */ long iAnchorIndex,
    /* [in] */ long iEndIndex);


void __RPC_STUB IVsIntellisenseHost_SetSubjectSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetSubjectSelection_Proxy( 
    IVsIntellisenseHost * This,
    /* [out] */ long *piAnchorIndex,
    /* [out] */ long *piEndIndex);


void __RPC_STUB IVsIntellisenseHost_GetSubjectSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_ReplaceSubjectTextSpan_Proxy( 
    IVsIntellisenseHost * This,
    /* [in] */ long iStartIndex,
    /* [in] */ long iEndIndex,
    /* [in] */ LPCWSTR pszText);


void __RPC_STUB IVsIntellisenseHost_ReplaceSubjectTextSpan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_UpdateCompletionStatus_Proxy( 
    IVsIntellisenseHost * This,
    /* [in] */ IVsCompletionSet *pCompSet,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IVsIntellisenseHost_UpdateCompletionStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_UpdateTipWindow_Proxy( 
    IVsIntellisenseHost * This,
    /* [in] */ IVsTipWindow *pTipWindow,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IVsIntellisenseHost_UpdateTipWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_HighlightMatchingBrace_Proxy( 
    IVsIntellisenseHost * This,
    /* [in] */ DWORD dwFlags,
    /* [in] */ ULONG cSpans,
    /* [size_is][in] */ TextSpan *rgBaseSpans);


void __RPC_STUB IVsIntellisenseHost_HighlightMatchingBrace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_BeforeCompletorCommit_Proxy( 
    IVsIntellisenseHost * This);


void __RPC_STUB IVsIntellisenseHost_BeforeCompletorCommit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_AfterCompletorCommit_Proxy( 
    IVsIntellisenseHost * This);


void __RPC_STUB IVsIntellisenseHost_AfterCompletorCommit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetServiceProvider_Proxy( 
    IVsIntellisenseHost * This,
    /* [out] */ IServiceProvider **ppSP);


void __RPC_STUB IVsIntellisenseHost_GetServiceProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetHostWindow_Proxy( 
    IVsIntellisenseHost * This,
    /* [out] */ HWND *hwnd);


void __RPC_STUB IVsIntellisenseHost_GetHostWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetContextLocation_Proxy( 
    IVsIntellisenseHost * This,
    /* [in] */ long iPos,
    /* [in] */ long iLen,
    /* [in] */ BOOL fUseCaretPosition,
    /* [out] */ RECT *prc,
    /* [out] */ long *piTopX);


void __RPC_STUB IVsIntellisenseHost_GetContextLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_UpdateSmartTagWindow_Proxy( 
    IVsIntellisenseHost * This,
    /* [in] */ IVsSmartTagTipWindow *pSmartTagWnd,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IVsIntellisenseHost_UpdateSmartTagWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseHost_GetSmartTagRect_Proxy( 
    IVsIntellisenseHost * This,
    /* [out] */ RECT *rcSmartTag);


void __RPC_STUB IVsIntellisenseHost_GetSmartTagRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsIntellisenseHost_INTERFACE_DEFINED__ */


#ifndef __IVsTextViewIntellisenseHost_INTERFACE_DEFINED__
#define __IVsTextViewIntellisenseHost_INTERFACE_DEFINED__

/* interface IVsTextViewIntellisenseHost */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextViewIntellisenseHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0816A38B-2B41-4d2a-B1FF-23C1E28D8A18")
    IVsTextViewIntellisenseHost : public IVsIntellisenseHost
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetSubjectFromPrimaryBuffer( 
            TextSpan *pSpanInPrimary) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextViewIntellisenseHostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextViewIntellisenseHost * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextViewIntellisenseHost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextViewIntellisenseHost * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IVsTextViewIntellisenseHost * This,
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ ULONG cCmds,
            /* [out][in][size_is] */ OLECMD prgCmds[  ],
            /* [unique][out][in] */ OLECMDTEXT *pCmdText);
        
        HRESULT ( STDMETHODCALLTYPE *Exec )( 
            IVsTextViewIntellisenseHost * This,
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ DWORD nCmdID,
            /* [in] */ DWORD nCmdexecopt,
            /* [unique][in] */ VARIANT *pvaIn,
            /* [unique][out][in] */ VARIANT *pvaOut);
        
        HRESULT ( STDMETHODCALLTYPE *GetHostFlags )( 
            IVsTextViewIntellisenseHost * This,
            /* [retval][out] */ DWORD *pdwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextBuffer )( 
            IVsTextViewIntellisenseHost * This,
            /* [retval][out] */ IVsTextLines **ppCtxBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextFocalPoint )( 
            IVsTextViewIntellisenseHost * This,
            /* [out] */ TextSpan *pSpan,
            long *piLen);
        
        HRESULT ( STDMETHODCALLTYPE *SetContextCaretPos )( 
            IVsTextViewIntellisenseHost * This,
            /* [in] */ long iLine,
            /* [in] */ long iIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextCaretPos )( 
            IVsTextViewIntellisenseHost * This,
            /* [out] */ long *piLine,
            /* [out] */ long *piIndex);
        
        HRESULT ( STDMETHODCALLTYPE *SetContextSelection )( 
            IVsTextViewIntellisenseHost * This,
            /* [in] */ long iStartLine,
            /* [in] */ long iStartIndex,
            /* [in] */ long iEndLine,
            /* [in] */ long iEndIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextSelection )( 
            IVsTextViewIntellisenseHost * This,
            /* [out] */ TextSpan *pSelectionSpan);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubjectText )( 
            IVsTextViewIntellisenseHost * This,
            /* [retval][out] */ BSTR *pbstrSubjectText);
        
        HRESULT ( STDMETHODCALLTYPE *SetSubjectCaretPos )( 
            IVsTextViewIntellisenseHost * This,
            /* [in] */ long iIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubjectCaretPos )( 
            IVsTextViewIntellisenseHost * This,
            /* [out] */ long *piIndex);
        
        HRESULT ( STDMETHODCALLTYPE *SetSubjectSelection )( 
            IVsTextViewIntellisenseHost * This,
            /* [in] */ long iAnchorIndex,
            /* [in] */ long iEndIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubjectSelection )( 
            IVsTextViewIntellisenseHost * This,
            /* [out] */ long *piAnchorIndex,
            /* [out] */ long *piEndIndex);
        
        HRESULT ( STDMETHODCALLTYPE *ReplaceSubjectTextSpan )( 
            IVsTextViewIntellisenseHost * This,
            /* [in] */ long iStartIndex,
            /* [in] */ long iEndIndex,
            /* [in] */ LPCWSTR pszText);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateCompletionStatus )( 
            IVsTextViewIntellisenseHost * This,
            /* [in] */ IVsCompletionSet *pCompSet,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateTipWindow )( 
            IVsTextViewIntellisenseHost * This,
            /* [in] */ IVsTipWindow *pTipWindow,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *HighlightMatchingBrace )( 
            IVsTextViewIntellisenseHost * This,
            /* [in] */ DWORD dwFlags,
            /* [in] */ ULONG cSpans,
            /* [size_is][in] */ TextSpan *rgBaseSpans);
        
        HRESULT ( STDMETHODCALLTYPE *BeforeCompletorCommit )( 
            IVsTextViewIntellisenseHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *AfterCompletorCommit )( 
            IVsTextViewIntellisenseHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetServiceProvider )( 
            IVsTextViewIntellisenseHost * This,
            /* [out] */ IServiceProvider **ppSP);
        
        HRESULT ( STDMETHODCALLTYPE *GetHostWindow )( 
            IVsTextViewIntellisenseHost * This,
            /* [out] */ HWND *hwnd);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextLocation )( 
            IVsTextViewIntellisenseHost * This,
            /* [in] */ long iPos,
            /* [in] */ long iLen,
            /* [in] */ BOOL fUseCaretPosition,
            /* [out] */ RECT *prc,
            /* [out] */ long *piTopX);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateSmartTagWindow )( 
            IVsTextViewIntellisenseHost * This,
            /* [in] */ IVsSmartTagTipWindow *pSmartTagWnd,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetSmartTagRect )( 
            IVsTextViewIntellisenseHost * This,
            /* [out] */ RECT *rcSmartTag);
        
        HRESULT ( STDMETHODCALLTYPE *SetSubjectFromPrimaryBuffer )( 
            IVsTextViewIntellisenseHost * This,
            TextSpan *pSpanInPrimary);
        
        END_INTERFACE
    } IVsTextViewIntellisenseHostVtbl;

    interface IVsTextViewIntellisenseHost
    {
        CONST_VTBL struct IVsTextViewIntellisenseHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextViewIntellisenseHost_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextViewIntellisenseHost_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextViewIntellisenseHost_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextViewIntellisenseHost_QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText)	\
    (This)->lpVtbl -> QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText)

#define IVsTextViewIntellisenseHost_Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut)	\
    (This)->lpVtbl -> Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut)


#define IVsTextViewIntellisenseHost_GetHostFlags(This,pdwFlags)	\
    (This)->lpVtbl -> GetHostFlags(This,pdwFlags)

#define IVsTextViewIntellisenseHost_GetContextBuffer(This,ppCtxBuffer)	\
    (This)->lpVtbl -> GetContextBuffer(This,ppCtxBuffer)

#define IVsTextViewIntellisenseHost_GetContextFocalPoint(This,pSpan,piLen)	\
    (This)->lpVtbl -> GetContextFocalPoint(This,pSpan,piLen)

#define IVsTextViewIntellisenseHost_SetContextCaretPos(This,iLine,iIndex)	\
    (This)->lpVtbl -> SetContextCaretPos(This,iLine,iIndex)

#define IVsTextViewIntellisenseHost_GetContextCaretPos(This,piLine,piIndex)	\
    (This)->lpVtbl -> GetContextCaretPos(This,piLine,piIndex)

#define IVsTextViewIntellisenseHost_SetContextSelection(This,iStartLine,iStartIndex,iEndLine,iEndIndex)	\
    (This)->lpVtbl -> SetContextSelection(This,iStartLine,iStartIndex,iEndLine,iEndIndex)

#define IVsTextViewIntellisenseHost_GetContextSelection(This,pSelectionSpan)	\
    (This)->lpVtbl -> GetContextSelection(This,pSelectionSpan)

#define IVsTextViewIntellisenseHost_GetSubjectText(This,pbstrSubjectText)	\
    (This)->lpVtbl -> GetSubjectText(This,pbstrSubjectText)

#define IVsTextViewIntellisenseHost_SetSubjectCaretPos(This,iIndex)	\
    (This)->lpVtbl -> SetSubjectCaretPos(This,iIndex)

#define IVsTextViewIntellisenseHost_GetSubjectCaretPos(This,piIndex)	\
    (This)->lpVtbl -> GetSubjectCaretPos(This,piIndex)

#define IVsTextViewIntellisenseHost_SetSubjectSelection(This,iAnchorIndex,iEndIndex)	\
    (This)->lpVtbl -> SetSubjectSelection(This,iAnchorIndex,iEndIndex)

#define IVsTextViewIntellisenseHost_GetSubjectSelection(This,piAnchorIndex,piEndIndex)	\
    (This)->lpVtbl -> GetSubjectSelection(This,piAnchorIndex,piEndIndex)

#define IVsTextViewIntellisenseHost_ReplaceSubjectTextSpan(This,iStartIndex,iEndIndex,pszText)	\
    (This)->lpVtbl -> ReplaceSubjectTextSpan(This,iStartIndex,iEndIndex,pszText)

#define IVsTextViewIntellisenseHost_UpdateCompletionStatus(This,pCompSet,dwFlags)	\
    (This)->lpVtbl -> UpdateCompletionStatus(This,pCompSet,dwFlags)

#define IVsTextViewIntellisenseHost_UpdateTipWindow(This,pTipWindow,dwFlags)	\
    (This)->lpVtbl -> UpdateTipWindow(This,pTipWindow,dwFlags)

#define IVsTextViewIntellisenseHost_HighlightMatchingBrace(This,dwFlags,cSpans,rgBaseSpans)	\
    (This)->lpVtbl -> HighlightMatchingBrace(This,dwFlags,cSpans,rgBaseSpans)

#define IVsTextViewIntellisenseHost_BeforeCompletorCommit(This)	\
    (This)->lpVtbl -> BeforeCompletorCommit(This)

#define IVsTextViewIntellisenseHost_AfterCompletorCommit(This)	\
    (This)->lpVtbl -> AfterCompletorCommit(This)

#define IVsTextViewIntellisenseHost_GetServiceProvider(This,ppSP)	\
    (This)->lpVtbl -> GetServiceProvider(This,ppSP)

#define IVsTextViewIntellisenseHost_GetHostWindow(This,hwnd)	\
    (This)->lpVtbl -> GetHostWindow(This,hwnd)

#define IVsTextViewIntellisenseHost_GetContextLocation(This,iPos,iLen,fUseCaretPosition,prc,piTopX)	\
    (This)->lpVtbl -> GetContextLocation(This,iPos,iLen,fUseCaretPosition,prc,piTopX)

#define IVsTextViewIntellisenseHost_UpdateSmartTagWindow(This,pSmartTagWnd,dwFlags)	\
    (This)->lpVtbl -> UpdateSmartTagWindow(This,pSmartTagWnd,dwFlags)

#define IVsTextViewIntellisenseHost_GetSmartTagRect(This,rcSmartTag)	\
    (This)->lpVtbl -> GetSmartTagRect(This,rcSmartTag)


#define IVsTextViewIntellisenseHost_SetSubjectFromPrimaryBuffer(This,pSpanInPrimary)	\
    (This)->lpVtbl -> SetSubjectFromPrimaryBuffer(This,pSpanInPrimary)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextViewIntellisenseHost_SetSubjectFromPrimaryBuffer_Proxy( 
    IVsTextViewIntellisenseHost * This,
    TextSpan *pSpanInPrimary);


void __RPC_STUB IVsTextViewIntellisenseHost_SetSubjectFromPrimaryBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextViewIntellisenseHost_INTERFACE_DEFINED__ */


#ifndef __IVsTextViewIntellisenseHostProvider_INTERFACE_DEFINED__
#define __IVsTextViewIntellisenseHostProvider_INTERFACE_DEFINED__

/* interface IVsTextViewIntellisenseHostProvider */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextViewIntellisenseHostProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2E758295-344B-48d6-86AC-BD81F89CB4B8")
    IVsTextViewIntellisenseHostProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateIntellisenseHost( 
            /* [in] */ IVsTextBufferCoordinator *pBufferCoordinator,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppunkHost) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextViewIntellisenseHostProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextViewIntellisenseHostProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextViewIntellisenseHostProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextViewIntellisenseHostProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateIntellisenseHost )( 
            IVsTextViewIntellisenseHostProvider * This,
            /* [in] */ IVsTextBufferCoordinator *pBufferCoordinator,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppunkHost);
        
        END_INTERFACE
    } IVsTextViewIntellisenseHostProviderVtbl;

    interface IVsTextViewIntellisenseHostProvider
    {
        CONST_VTBL struct IVsTextViewIntellisenseHostProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextViewIntellisenseHostProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextViewIntellisenseHostProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextViewIntellisenseHostProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextViewIntellisenseHostProvider_CreateIntellisenseHost(This,pBufferCoordinator,riid,ppunkHost)	\
    (This)->lpVtbl -> CreateIntellisenseHost(This,pBufferCoordinator,riid,ppunkHost)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextViewIntellisenseHostProvider_CreateIntellisenseHost_Proxy( 
    IVsTextViewIntellisenseHostProvider * This,
    /* [in] */ IVsTextBufferCoordinator *pBufferCoordinator,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppunkHost);


void __RPC_STUB IVsTextViewIntellisenseHostProvider_CreateIntellisenseHost_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextViewIntellisenseHostProvider_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_VsIntellisenseCompletor;

#ifdef __cplusplus

class DECLSPEC_UUID("F2073DB0-75B9-43ae-8681-0962C0CD4BE2")
VsIntellisenseCompletor;
#endif

#ifndef __IVsIntellisenseCompletor_INTERFACE_DEFINED__
#define __IVsIntellisenseCompletor_INTERFACE_DEFINED__

/* interface IVsIntellisenseCompletor */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsIntellisenseCompletor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("05DFCF7A-C78A-4e20-AAFB-4A0F4D26E0FB")
    IVsIntellisenseCompletor : public IOleCommandTarget
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            IVsIntellisenseHost *pHost,
            HWND hwndParent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Update( 
            IVsCompletionSet *pCompSet,
            DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWidth( 
            DWORD *dwWidth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHeight( 
            DWORD *dwHeight) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompletionSpan( 
            TextSpan *ts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLocation( 
            POINT *p) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Hide( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsActive( 
            /* [out] */ BOOL *pfIsActive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWindowHandle( 
            /* [out] */ HWND *phwnd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsIntellisenseCompletorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsIntellisenseCompletor * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsIntellisenseCompletor * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsIntellisenseCompletor * This);
        
        /* [input_sync] */ HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IVsIntellisenseCompletor * This,
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ ULONG cCmds,
            /* [out][in][size_is] */ OLECMD prgCmds[  ],
            /* [unique][out][in] */ OLECMDTEXT *pCmdText);
        
        HRESULT ( STDMETHODCALLTYPE *Exec )( 
            IVsIntellisenseCompletor * This,
            /* [unique][in] */ const GUID *pguidCmdGroup,
            /* [in] */ DWORD nCmdID,
            /* [in] */ DWORD nCmdexecopt,
            /* [unique][in] */ VARIANT *pvaIn,
            /* [unique][out][in] */ VARIANT *pvaOut);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IVsIntellisenseCompletor * This,
            IVsIntellisenseHost *pHost,
            HWND hwndParent);
        
        HRESULT ( STDMETHODCALLTYPE *Update )( 
            IVsIntellisenseCompletor * This,
            IVsCompletionSet *pCompSet,
            DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetWidth )( 
            IVsIntellisenseCompletor * This,
            DWORD *dwWidth);
        
        HRESULT ( STDMETHODCALLTYPE *GetHeight )( 
            IVsIntellisenseCompletor * This,
            DWORD *dwHeight);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletionSpan )( 
            IVsIntellisenseCompletor * This,
            TextSpan *ts);
        
        HRESULT ( STDMETHODCALLTYPE *SetLocation )( 
            IVsIntellisenseCompletor * This,
            POINT *p);
        
        HRESULT ( STDMETHODCALLTYPE *Hide )( 
            IVsIntellisenseCompletor * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsActive )( 
            IVsIntellisenseCompletor * This,
            /* [out] */ BOOL *pfIsActive);
        
        HRESULT ( STDMETHODCALLTYPE *GetWindowHandle )( 
            IVsIntellisenseCompletor * This,
            /* [out] */ HWND *phwnd);
        
        END_INTERFACE
    } IVsIntellisenseCompletorVtbl;

    interface IVsIntellisenseCompletor
    {
        CONST_VTBL struct IVsIntellisenseCompletorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsIntellisenseCompletor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsIntellisenseCompletor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsIntellisenseCompletor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsIntellisenseCompletor_QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText)	\
    (This)->lpVtbl -> QueryStatus(This,pguidCmdGroup,cCmds,prgCmds,pCmdText)

#define IVsIntellisenseCompletor_Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut)	\
    (This)->lpVtbl -> Exec(This,pguidCmdGroup,nCmdID,nCmdexecopt,pvaIn,pvaOut)


#define IVsIntellisenseCompletor_Initialize(This,pHost,hwndParent)	\
    (This)->lpVtbl -> Initialize(This,pHost,hwndParent)

#define IVsIntellisenseCompletor_Update(This,pCompSet,dwFlags)	\
    (This)->lpVtbl -> Update(This,pCompSet,dwFlags)

#define IVsIntellisenseCompletor_GetWidth(This,dwWidth)	\
    (This)->lpVtbl -> GetWidth(This,dwWidth)

#define IVsIntellisenseCompletor_GetHeight(This,dwHeight)	\
    (This)->lpVtbl -> GetHeight(This,dwHeight)

#define IVsIntellisenseCompletor_GetCompletionSpan(This,ts)	\
    (This)->lpVtbl -> GetCompletionSpan(This,ts)

#define IVsIntellisenseCompletor_SetLocation(This,p)	\
    (This)->lpVtbl -> SetLocation(This,p)

#define IVsIntellisenseCompletor_Hide(This)	\
    (This)->lpVtbl -> Hide(This)

#define IVsIntellisenseCompletor_IsActive(This,pfIsActive)	\
    (This)->lpVtbl -> IsActive(This,pfIsActive)

#define IVsIntellisenseCompletor_GetWindowHandle(This,phwnd)	\
    (This)->lpVtbl -> GetWindowHandle(This,phwnd)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsIntellisenseCompletor_Initialize_Proxy( 
    IVsIntellisenseCompletor * This,
    IVsIntellisenseHost *pHost,
    HWND hwndParent);


void __RPC_STUB IVsIntellisenseCompletor_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseCompletor_Update_Proxy( 
    IVsIntellisenseCompletor * This,
    IVsCompletionSet *pCompSet,
    DWORD dwFlags);


void __RPC_STUB IVsIntellisenseCompletor_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseCompletor_GetWidth_Proxy( 
    IVsIntellisenseCompletor * This,
    DWORD *dwWidth);


void __RPC_STUB IVsIntellisenseCompletor_GetWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseCompletor_GetHeight_Proxy( 
    IVsIntellisenseCompletor * This,
    DWORD *dwHeight);


void __RPC_STUB IVsIntellisenseCompletor_GetHeight_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseCompletor_GetCompletionSpan_Proxy( 
    IVsIntellisenseCompletor * This,
    TextSpan *ts);


void __RPC_STUB IVsIntellisenseCompletor_GetCompletionSpan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseCompletor_SetLocation_Proxy( 
    IVsIntellisenseCompletor * This,
    POINT *p);


void __RPC_STUB IVsIntellisenseCompletor_SetLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseCompletor_Hide_Proxy( 
    IVsIntellisenseCompletor * This);


void __RPC_STUB IVsIntellisenseCompletor_Hide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseCompletor_IsActive_Proxy( 
    IVsIntellisenseCompletor * This,
    /* [out] */ BOOL *pfIsActive);


void __RPC_STUB IVsIntellisenseCompletor_IsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseCompletor_GetWindowHandle_Proxy( 
    IVsIntellisenseCompletor * This,
    /* [out] */ HWND *phwnd);


void __RPC_STUB IVsIntellisenseCompletor_GetWindowHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsIntellisenseCompletor_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_VsIntellisenseLangTip;

#ifdef __cplusplus

class DECLSPEC_UUID("39F4B568-7166-42b3-87E6-6B856864AE55")
VsIntellisenseLangTip;
#endif

#ifndef __IVsIntellisenseLangTip_INTERFACE_DEFINED__
#define __IVsIntellisenseLangTip_INTERFACE_DEFINED__

/* interface IVsIntellisenseLangTip */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsIntellisenseLangTip;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1E34D422-7120-4d9e-96FF-E880B665D30D")
    IVsIntellisenseLangTip : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IVsIntellisenseHost *pHost) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSizePreferences( 
            /* [in] */ RECT *prcCtxBounds,
            /* [in] */ TIPSIZEDATA *pSizeData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ IVsTipWindow *pTipWnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Update( 
            /* [in] */ IVsTipWindow *pTipWnd,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdatePosition( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSizeY( 
            /* [out] */ short *pSizeY) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( 
            /* [in] */ BOOL fDeleteThis) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsActive( 
            /* [out] */ BOOL *pfIsActive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOverloadCount( 
            /* [out] */ long *plOverloadCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScrollUp( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScrollDown( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsIntellisenseLangTipVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsIntellisenseLangTip * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsIntellisenseLangTip * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsIntellisenseLangTip * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IVsIntellisenseLangTip * This,
            /* [in] */ IVsIntellisenseHost *pHost);
        
        HRESULT ( STDMETHODCALLTYPE *GetSizePreferences )( 
            IVsIntellisenseLangTip * This,
            /* [in] */ RECT *prcCtxBounds,
            /* [in] */ TIPSIZEDATA *pSizeData);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            IVsIntellisenseLangTip * This,
            /* [in] */ IVsTipWindow *pTipWnd);
        
        HRESULT ( STDMETHODCALLTYPE *Update )( 
            IVsIntellisenseLangTip * This,
            /* [in] */ IVsTipWindow *pTipWnd,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *UpdatePosition )( 
            IVsIntellisenseLangTip * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSizeY )( 
            IVsIntellisenseLangTip * This,
            /* [out] */ short *pSizeY);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVsIntellisenseLangTip * This,
            /* [in] */ BOOL fDeleteThis);
        
        HRESULT ( STDMETHODCALLTYPE *IsActive )( 
            IVsIntellisenseLangTip * This,
            /* [out] */ BOOL *pfIsActive);
        
        HRESULT ( STDMETHODCALLTYPE *GetOverloadCount )( 
            IVsIntellisenseLangTip * This,
            /* [out] */ long *plOverloadCount);
        
        HRESULT ( STDMETHODCALLTYPE *ScrollUp )( 
            IVsIntellisenseLangTip * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScrollDown )( 
            IVsIntellisenseLangTip * This);
        
        END_INTERFACE
    } IVsIntellisenseLangTipVtbl;

    interface IVsIntellisenseLangTip
    {
        CONST_VTBL struct IVsIntellisenseLangTipVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsIntellisenseLangTip_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsIntellisenseLangTip_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsIntellisenseLangTip_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsIntellisenseLangTip_Initialize(This,pHost)	\
    (This)->lpVtbl -> Initialize(This,pHost)

#define IVsIntellisenseLangTip_GetSizePreferences(This,prcCtxBounds,pSizeData)	\
    (This)->lpVtbl -> GetSizePreferences(This,prcCtxBounds,pSizeData)

#define IVsIntellisenseLangTip_Create(This,pTipWnd)	\
    (This)->lpVtbl -> Create(This,pTipWnd)

#define IVsIntellisenseLangTip_Update(This,pTipWnd,dwFlags)	\
    (This)->lpVtbl -> Update(This,pTipWnd,dwFlags)

#define IVsIntellisenseLangTip_UpdatePosition(This)	\
    (This)->lpVtbl -> UpdatePosition(This)

#define IVsIntellisenseLangTip_GetSizeY(This,pSizeY)	\
    (This)->lpVtbl -> GetSizeY(This,pSizeY)

#define IVsIntellisenseLangTip_Close(This,fDeleteThis)	\
    (This)->lpVtbl -> Close(This,fDeleteThis)

#define IVsIntellisenseLangTip_IsActive(This,pfIsActive)	\
    (This)->lpVtbl -> IsActive(This,pfIsActive)

#define IVsIntellisenseLangTip_GetOverloadCount(This,plOverloadCount)	\
    (This)->lpVtbl -> GetOverloadCount(This,plOverloadCount)

#define IVsIntellisenseLangTip_ScrollUp(This)	\
    (This)->lpVtbl -> ScrollUp(This)

#define IVsIntellisenseLangTip_ScrollDown(This)	\
    (This)->lpVtbl -> ScrollDown(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsIntellisenseLangTip_Initialize_Proxy( 
    IVsIntellisenseLangTip * This,
    /* [in] */ IVsIntellisenseHost *pHost);


void __RPC_STUB IVsIntellisenseLangTip_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseLangTip_GetSizePreferences_Proxy( 
    IVsIntellisenseLangTip * This,
    /* [in] */ RECT *prcCtxBounds,
    /* [in] */ TIPSIZEDATA *pSizeData);


void __RPC_STUB IVsIntellisenseLangTip_GetSizePreferences_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseLangTip_Create_Proxy( 
    IVsIntellisenseLangTip * This,
    /* [in] */ IVsTipWindow *pTipWnd);


void __RPC_STUB IVsIntellisenseLangTip_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseLangTip_Update_Proxy( 
    IVsIntellisenseLangTip * This,
    /* [in] */ IVsTipWindow *pTipWnd,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IVsIntellisenseLangTip_Update_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseLangTip_UpdatePosition_Proxy( 
    IVsIntellisenseLangTip * This);


void __RPC_STUB IVsIntellisenseLangTip_UpdatePosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseLangTip_GetSizeY_Proxy( 
    IVsIntellisenseLangTip * This,
    /* [out] */ short *pSizeY);


void __RPC_STUB IVsIntellisenseLangTip_GetSizeY_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseLangTip_Close_Proxy( 
    IVsIntellisenseLangTip * This,
    /* [in] */ BOOL fDeleteThis);


void __RPC_STUB IVsIntellisenseLangTip_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseLangTip_IsActive_Proxy( 
    IVsIntellisenseLangTip * This,
    /* [out] */ BOOL *pfIsActive);


void __RPC_STUB IVsIntellisenseLangTip_IsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseLangTip_GetOverloadCount_Proxy( 
    IVsIntellisenseLangTip * This,
    /* [out] */ long *plOverloadCount);


void __RPC_STUB IVsIntellisenseLangTip_GetOverloadCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseLangTip_ScrollUp_Proxy( 
    IVsIntellisenseLangTip * This);


void __RPC_STUB IVsIntellisenseLangTip_ScrollUp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseLangTip_ScrollDown_Proxy( 
    IVsIntellisenseLangTip * This);


void __RPC_STUB IVsIntellisenseLangTip_ScrollDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsIntellisenseLangTip_INTERFACE_DEFINED__ */


#ifndef __IVsContainedLanguageHost_INTERFACE_DEFINED__
#define __IVsContainedLanguageHost_INTERFACE_DEFINED__

/* interface IVsContainedLanguageHost */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsContainedLanguageHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0429916F-69E1-4336-AB7E-72086FB0D6BC")
    IVsContainedLanguageHost : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ IVsContainedLanguageHostEvents *pHost,
            /* [out] */ VSCOOKIE *pvsCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unadvise( 
            /* [in] */ VSCOOKIE vsCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLineIndent( 
            /* [in] */ long lLineNumber,
            /* [out] */ BSTR *pbstrIndentString,
            /* [out] */ long *plParentIndentLevel,
            /* [out] */ long *plIndentSize,
            /* [out] */ BOOL *pfTabs,
            /* [out] */ long *plTabSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanReformatCode( 
            /* [out] */ BOOL *pfCanReformat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNearestVisibleToken( 
            /* [in] */ TextSpan tsSecondaryToken,
            /* [out] */ TextSpan *ptsPrimaryToken) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnsureSpanVisible( 
            /* [in] */ TextSpan tsPrimary) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryEditFile( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRenamed( 
            /* [in] */ ContainedLanguageRenameType clrt,
            /* [in] */ BSTR bstrOldID,
            /* [in] */ BSTR bstrNewID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertControl( 
            /* [in] */ const WCHAR *pwcFullType,
            /* [in] */ const WCHAR *pwcID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertReference( 
            /* [in] */ const WCHAR *__MIDL_0011) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVSHierarchy( 
            /* [out] */ IVsHierarchy **ppVsHierarchy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetErrorProviderInformation( 
            /* [out] */ BSTR *pbstrTaskProviderName,
            /* [out] */ GUID *pguidTaskProviderGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertImportsDirective( 
            /* [in] */ const WCHAR *__MIDL_0012) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnContainedLanguageEditorSettingsChange( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnsureSecondaryBufferReady( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsContainedLanguageHostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsContainedLanguageHost * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsContainedLanguageHost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsContainedLanguageHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *Advise )( 
            IVsContainedLanguageHost * This,
            /* [in] */ IVsContainedLanguageHostEvents *pHost,
            /* [out] */ VSCOOKIE *pvsCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Unadvise )( 
            IVsContainedLanguageHost * This,
            /* [in] */ VSCOOKIE vsCookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetLineIndent )( 
            IVsContainedLanguageHost * This,
            /* [in] */ long lLineNumber,
            /* [out] */ BSTR *pbstrIndentString,
            /* [out] */ long *plParentIndentLevel,
            /* [out] */ long *plIndentSize,
            /* [out] */ BOOL *pfTabs,
            /* [out] */ long *plTabSize);
        
        HRESULT ( STDMETHODCALLTYPE *CanReformatCode )( 
            IVsContainedLanguageHost * This,
            /* [out] */ BOOL *pfCanReformat);
        
        HRESULT ( STDMETHODCALLTYPE *GetNearestVisibleToken )( 
            IVsContainedLanguageHost * This,
            /* [in] */ TextSpan tsSecondaryToken,
            /* [out] */ TextSpan *ptsPrimaryToken);
        
        HRESULT ( STDMETHODCALLTYPE *EnsureSpanVisible )( 
            IVsContainedLanguageHost * This,
            /* [in] */ TextSpan tsPrimary);
        
        HRESULT ( STDMETHODCALLTYPE *QueryEditFile )( 
            IVsContainedLanguageHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnRenamed )( 
            IVsContainedLanguageHost * This,
            /* [in] */ ContainedLanguageRenameType clrt,
            /* [in] */ BSTR bstrOldID,
            /* [in] */ BSTR bstrNewID);
        
        HRESULT ( STDMETHODCALLTYPE *InsertControl )( 
            IVsContainedLanguageHost * This,
            /* [in] */ const WCHAR *pwcFullType,
            /* [in] */ const WCHAR *pwcID);
        
        HRESULT ( STDMETHODCALLTYPE *InsertReference )( 
            IVsContainedLanguageHost * This,
            /* [in] */ const WCHAR *__MIDL_0011);
        
        HRESULT ( STDMETHODCALLTYPE *GetVSHierarchy )( 
            IVsContainedLanguageHost * This,
            /* [out] */ IVsHierarchy **ppVsHierarchy);
        
        HRESULT ( STDMETHODCALLTYPE *GetErrorProviderInformation )( 
            IVsContainedLanguageHost * This,
            /* [out] */ BSTR *pbstrTaskProviderName,
            /* [out] */ GUID *pguidTaskProviderGuid);
        
        HRESULT ( STDMETHODCALLTYPE *InsertImportsDirective )( 
            IVsContainedLanguageHost * This,
            /* [in] */ const WCHAR *__MIDL_0012);
        
        HRESULT ( STDMETHODCALLTYPE *OnContainedLanguageEditorSettingsChange )( 
            IVsContainedLanguageHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnsureSecondaryBufferReady )( 
            IVsContainedLanguageHost * This);
        
        END_INTERFACE
    } IVsContainedLanguageHostVtbl;

    interface IVsContainedLanguageHost
    {
        CONST_VTBL struct IVsContainedLanguageHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsContainedLanguageHost_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsContainedLanguageHost_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsContainedLanguageHost_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsContainedLanguageHost_Advise(This,pHost,pvsCookie)	\
    (This)->lpVtbl -> Advise(This,pHost,pvsCookie)

#define IVsContainedLanguageHost_Unadvise(This,vsCookie)	\
    (This)->lpVtbl -> Unadvise(This,vsCookie)

#define IVsContainedLanguageHost_GetLineIndent(This,lLineNumber,pbstrIndentString,plParentIndentLevel,plIndentSize,pfTabs,plTabSize)	\
    (This)->lpVtbl -> GetLineIndent(This,lLineNumber,pbstrIndentString,plParentIndentLevel,plIndentSize,pfTabs,plTabSize)

#define IVsContainedLanguageHost_CanReformatCode(This,pfCanReformat)	\
    (This)->lpVtbl -> CanReformatCode(This,pfCanReformat)

#define IVsContainedLanguageHost_GetNearestVisibleToken(This,tsSecondaryToken,ptsPrimaryToken)	\
    (This)->lpVtbl -> GetNearestVisibleToken(This,tsSecondaryToken,ptsPrimaryToken)

#define IVsContainedLanguageHost_EnsureSpanVisible(This,tsPrimary)	\
    (This)->lpVtbl -> EnsureSpanVisible(This,tsPrimary)

#define IVsContainedLanguageHost_QueryEditFile(This)	\
    (This)->lpVtbl -> QueryEditFile(This)

#define IVsContainedLanguageHost_OnRenamed(This,clrt,bstrOldID,bstrNewID)	\
    (This)->lpVtbl -> OnRenamed(This,clrt,bstrOldID,bstrNewID)

#define IVsContainedLanguageHost_InsertControl(This,pwcFullType,pwcID)	\
    (This)->lpVtbl -> InsertControl(This,pwcFullType,pwcID)

#define IVsContainedLanguageHost_InsertReference(This,__MIDL_0011)	\
    (This)->lpVtbl -> InsertReference(This,__MIDL_0011)

#define IVsContainedLanguageHost_GetVSHierarchy(This,ppVsHierarchy)	\
    (This)->lpVtbl -> GetVSHierarchy(This,ppVsHierarchy)

#define IVsContainedLanguageHost_GetErrorProviderInformation(This,pbstrTaskProviderName,pguidTaskProviderGuid)	\
    (This)->lpVtbl -> GetErrorProviderInformation(This,pbstrTaskProviderName,pguidTaskProviderGuid)

#define IVsContainedLanguageHost_InsertImportsDirective(This,__MIDL_0012)	\
    (This)->lpVtbl -> InsertImportsDirective(This,__MIDL_0012)

#define IVsContainedLanguageHost_OnContainedLanguageEditorSettingsChange(This)	\
    (This)->lpVtbl -> OnContainedLanguageEditorSettingsChange(This)

#define IVsContainedLanguageHost_EnsureSecondaryBufferReady(This)	\
    (This)->lpVtbl -> EnsureSecondaryBufferReady(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_Advise_Proxy( 
    IVsContainedLanguageHost * This,
    /* [in] */ IVsContainedLanguageHostEvents *pHost,
    /* [out] */ VSCOOKIE *pvsCookie);


void __RPC_STUB IVsContainedLanguageHost_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_Unadvise_Proxy( 
    IVsContainedLanguageHost * This,
    /* [in] */ VSCOOKIE vsCookie);


void __RPC_STUB IVsContainedLanguageHost_Unadvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_GetLineIndent_Proxy( 
    IVsContainedLanguageHost * This,
    /* [in] */ long lLineNumber,
    /* [out] */ BSTR *pbstrIndentString,
    /* [out] */ long *plParentIndentLevel,
    /* [out] */ long *plIndentSize,
    /* [out] */ BOOL *pfTabs,
    /* [out] */ long *plTabSize);


void __RPC_STUB IVsContainedLanguageHost_GetLineIndent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_CanReformatCode_Proxy( 
    IVsContainedLanguageHost * This,
    /* [out] */ BOOL *pfCanReformat);


void __RPC_STUB IVsContainedLanguageHost_CanReformatCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_GetNearestVisibleToken_Proxy( 
    IVsContainedLanguageHost * This,
    /* [in] */ TextSpan tsSecondaryToken,
    /* [out] */ TextSpan *ptsPrimaryToken);


void __RPC_STUB IVsContainedLanguageHost_GetNearestVisibleToken_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_EnsureSpanVisible_Proxy( 
    IVsContainedLanguageHost * This,
    /* [in] */ TextSpan tsPrimary);


void __RPC_STUB IVsContainedLanguageHost_EnsureSpanVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_QueryEditFile_Proxy( 
    IVsContainedLanguageHost * This);


void __RPC_STUB IVsContainedLanguageHost_QueryEditFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_OnRenamed_Proxy( 
    IVsContainedLanguageHost * This,
    /* [in] */ ContainedLanguageRenameType clrt,
    /* [in] */ BSTR bstrOldID,
    /* [in] */ BSTR bstrNewID);


void __RPC_STUB IVsContainedLanguageHost_OnRenamed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_InsertControl_Proxy( 
    IVsContainedLanguageHost * This,
    /* [in] */ const WCHAR *pwcFullType,
    /* [in] */ const WCHAR *pwcID);


void __RPC_STUB IVsContainedLanguageHost_InsertControl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_InsertReference_Proxy( 
    IVsContainedLanguageHost * This,
    /* [in] */ const WCHAR *__MIDL_0011);


void __RPC_STUB IVsContainedLanguageHost_InsertReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_GetVSHierarchy_Proxy( 
    IVsContainedLanguageHost * This,
    /* [out] */ IVsHierarchy **ppVsHierarchy);


void __RPC_STUB IVsContainedLanguageHost_GetVSHierarchy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_GetErrorProviderInformation_Proxy( 
    IVsContainedLanguageHost * This,
    /* [out] */ BSTR *pbstrTaskProviderName,
    /* [out] */ GUID *pguidTaskProviderGuid);


void __RPC_STUB IVsContainedLanguageHost_GetErrorProviderInformation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_InsertImportsDirective_Proxy( 
    IVsContainedLanguageHost * This,
    /* [in] */ const WCHAR *__MIDL_0012);


void __RPC_STUB IVsContainedLanguageHost_InsertImportsDirective_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_OnContainedLanguageEditorSettingsChange_Proxy( 
    IVsContainedLanguageHost * This);


void __RPC_STUB IVsContainedLanguageHost_OnContainedLanguageEditorSettingsChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageHost_EnsureSecondaryBufferReady_Proxy( 
    IVsContainedLanguageHost * This);


void __RPC_STUB IVsContainedLanguageHost_EnsureSecondaryBufferReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsContainedLanguageHost_INTERFACE_DEFINED__ */


#ifndef __IVsContainedLanguageHostEvents_INTERFACE_DEFINED__
#define __IVsContainedLanguageHostEvents_INTERFACE_DEFINED__

/* interface IVsContainedLanguageHostEvents */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsContainedLanguageHostEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F2A52136-803E-4cef-BBA7-52D610FE34BA")
    IVsContainedLanguageHostEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnViewChange( 
            /* [in] */ BOOL fTextView) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsContainedLanguageHostEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsContainedLanguageHostEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsContainedLanguageHostEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsContainedLanguageHostEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnViewChange )( 
            IVsContainedLanguageHostEvents * This,
            /* [in] */ BOOL fTextView);
        
        END_INTERFACE
    } IVsContainedLanguageHostEventsVtbl;

    interface IVsContainedLanguageHostEvents
    {
        CONST_VTBL struct IVsContainedLanguageHostEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsContainedLanguageHostEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsContainedLanguageHostEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsContainedLanguageHostEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsContainedLanguageHostEvents_OnViewChange(This,fTextView)	\
    (This)->lpVtbl -> OnViewChange(This,fTextView)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsContainedLanguageHostEvents_OnViewChange_Proxy( 
    IVsContainedLanguageHostEvents * This,
    /* [in] */ BOOL fTextView);


void __RPC_STUB IVsContainedLanguageHostEvents_OnViewChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsContainedLanguageHostEvents_INTERFACE_DEFINED__ */


#ifndef __IVsContainedLanguage_INTERFACE_DEFINED__
#define __IVsContainedLanguage_INTERFACE_DEFINED__

/* interface IVsContainedLanguage */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsContainedLanguage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("518ab114-e3c6-4bbc-a469-99279f1a54e9")
    IVsContainedLanguage : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetHost( 
            /* [in] */ IVsContainedLanguageHost *pHost) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColorizer( 
            /* [retval][out] */ IVsColorizer **ppColorizer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTextViewFilter( 
            /* [in] */ IVsIntellisenseHost *pISenseHost,
            /* [in] */ IOleCommandTarget *pNextCmdTarget,
            /* [retval][out] */ IVsTextViewFilter **pTextViewFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLanguageServiceID( 
            /* [out] */ GUID *pguidLangService) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferCoordinator( 
            /* [in] */ IVsTextBufferCoordinator *pBC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Refresh( 
            /* [in] */ DWORD dwRefreshMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitForReadyState( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsContainedLanguageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsContainedLanguage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsContainedLanguage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsContainedLanguage * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetHost )( 
            IVsContainedLanguage * This,
            /* [in] */ IVsContainedLanguageHost *pHost);
        
        HRESULT ( STDMETHODCALLTYPE *GetColorizer )( 
            IVsContainedLanguage * This,
            /* [retval][out] */ IVsColorizer **ppColorizer);
        
        HRESULT ( STDMETHODCALLTYPE *GetTextViewFilter )( 
            IVsContainedLanguage * This,
            /* [in] */ IVsIntellisenseHost *pISenseHost,
            /* [in] */ IOleCommandTarget *pNextCmdTarget,
            /* [retval][out] */ IVsTextViewFilter **pTextViewFilter);
        
        HRESULT ( STDMETHODCALLTYPE *GetLanguageServiceID )( 
            IVsContainedLanguage * This,
            /* [out] */ GUID *pguidLangService);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferCoordinator )( 
            IVsContainedLanguage * This,
            /* [in] */ IVsTextBufferCoordinator *pBC);
        
        HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            IVsContainedLanguage * This,
            /* [in] */ DWORD dwRefreshMode);
        
        HRESULT ( STDMETHODCALLTYPE *WaitForReadyState )( 
            IVsContainedLanguage * This);
        
        END_INTERFACE
    } IVsContainedLanguageVtbl;

    interface IVsContainedLanguage
    {
        CONST_VTBL struct IVsContainedLanguageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsContainedLanguage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsContainedLanguage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsContainedLanguage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsContainedLanguage_SetHost(This,pHost)	\
    (This)->lpVtbl -> SetHost(This,pHost)

#define IVsContainedLanguage_GetColorizer(This,ppColorizer)	\
    (This)->lpVtbl -> GetColorizer(This,ppColorizer)

#define IVsContainedLanguage_GetTextViewFilter(This,pISenseHost,pNextCmdTarget,pTextViewFilter)	\
    (This)->lpVtbl -> GetTextViewFilter(This,pISenseHost,pNextCmdTarget,pTextViewFilter)

#define IVsContainedLanguage_GetLanguageServiceID(This,pguidLangService)	\
    (This)->lpVtbl -> GetLanguageServiceID(This,pguidLangService)

#define IVsContainedLanguage_SetBufferCoordinator(This,pBC)	\
    (This)->lpVtbl -> SetBufferCoordinator(This,pBC)

#define IVsContainedLanguage_Refresh(This,dwRefreshMode)	\
    (This)->lpVtbl -> Refresh(This,dwRefreshMode)

#define IVsContainedLanguage_WaitForReadyState(This)	\
    (This)->lpVtbl -> WaitForReadyState(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsContainedLanguage_SetHost_Proxy( 
    IVsContainedLanguage * This,
    /* [in] */ IVsContainedLanguageHost *pHost);


void __RPC_STUB IVsContainedLanguage_SetHost_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguage_GetColorizer_Proxy( 
    IVsContainedLanguage * This,
    /* [retval][out] */ IVsColorizer **ppColorizer);


void __RPC_STUB IVsContainedLanguage_GetColorizer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguage_GetTextViewFilter_Proxy( 
    IVsContainedLanguage * This,
    /* [in] */ IVsIntellisenseHost *pISenseHost,
    /* [in] */ IOleCommandTarget *pNextCmdTarget,
    /* [retval][out] */ IVsTextViewFilter **pTextViewFilter);


void __RPC_STUB IVsContainedLanguage_GetTextViewFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguage_GetLanguageServiceID_Proxy( 
    IVsContainedLanguage * This,
    /* [out] */ GUID *pguidLangService);


void __RPC_STUB IVsContainedLanguage_GetLanguageServiceID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguage_SetBufferCoordinator_Proxy( 
    IVsContainedLanguage * This,
    /* [in] */ IVsTextBufferCoordinator *pBC);


void __RPC_STUB IVsContainedLanguage_SetBufferCoordinator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguage_Refresh_Proxy( 
    IVsContainedLanguage * This,
    /* [in] */ DWORD dwRefreshMode);


void __RPC_STUB IVsContainedLanguage_Refresh_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguage_WaitForReadyState_Proxy( 
    IVsContainedLanguage * This);


void __RPC_STUB IVsContainedLanguage_WaitForReadyState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsContainedLanguage_INTERFACE_DEFINED__ */


#ifndef __IVsContainedLanguageColorizer_INTERFACE_DEFINED__
#define __IVsContainedLanguageColorizer_INTERFACE_DEFINED__

/* interface IVsContainedLanguageColorizer */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsContainedLanguageColorizer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("88105779-D75B-459e-B7AD-78F63BD40714")
    IVsContainedLanguageColorizer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ColorizeLineFragment( 
            /* [in] */ long iLine,
            /* [in] */ long iIndex,
            /* [in] */ long iLength,
            /* [in] */ const WCHAR *pszText,
            /* [in] */ long iState,
            /* [out] */ ULONG *pAttributes,
            /* [out] */ long *piNewState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsContainedLanguageColorizerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsContainedLanguageColorizer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsContainedLanguageColorizer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsContainedLanguageColorizer * This);
        
        HRESULT ( STDMETHODCALLTYPE *ColorizeLineFragment )( 
            IVsContainedLanguageColorizer * This,
            /* [in] */ long iLine,
            /* [in] */ long iIndex,
            /* [in] */ long iLength,
            /* [in] */ const WCHAR *pszText,
            /* [in] */ long iState,
            /* [out] */ ULONG *pAttributes,
            /* [out] */ long *piNewState);
        
        END_INTERFACE
    } IVsContainedLanguageColorizerVtbl;

    interface IVsContainedLanguageColorizer
    {
        CONST_VTBL struct IVsContainedLanguageColorizerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsContainedLanguageColorizer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsContainedLanguageColorizer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsContainedLanguageColorizer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsContainedLanguageColorizer_ColorizeLineFragment(This,iLine,iIndex,iLength,pszText,iState,pAttributes,piNewState)	\
    (This)->lpVtbl -> ColorizeLineFragment(This,iLine,iIndex,iLength,pszText,iState,pAttributes,piNewState)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsContainedLanguageColorizer_ColorizeLineFragment_Proxy( 
    IVsContainedLanguageColorizer * This,
    /* [in] */ long iLine,
    /* [in] */ long iIndex,
    /* [in] */ long iLength,
    /* [in] */ const WCHAR *pszText,
    /* [in] */ long iState,
    /* [out] */ ULONG *pAttributes,
    /* [out] */ long *piNewState);


void __RPC_STUB IVsContainedLanguageColorizer_ColorizeLineFragment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsContainedLanguageColorizer_INTERFACE_DEFINED__ */


#ifndef __IVsContainedLanguageCodeSupport_INTERFACE_DEFINED__
#define __IVsContainedLanguageCodeSupport_INTERFACE_DEFINED__

/* interface IVsContainedLanguageCodeSupport */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsContainedLanguageCodeSupport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f386be91-0e80-43af-8eb6-8b829fa06282")
    IVsContainedLanguageCodeSupport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateUniqueEventName( 
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectName,
            /* [in] */ LPCWSTR pszNameOfEvent,
            /* [out] */ BSTR *pbstrEventHandlerName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnsureEventHandler( 
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectTypeName,
            /* [in] */ LPCWSTR pszNameOfEvent,
            /* [in] */ LPCWSTR pszEventHandlerName,
            /* [in] */ VSITEMID itemidInsertionPoint,
            /* [out] */ BSTR *pbstrUniqueMemberID,
            /* [out] */ BSTR *pbstrEventBody,
            /* [out] */ TextSpan *pSpanInsertionPoint) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMemberNavigationPoint( 
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszUniqueMemberID,
            /* [out] */ TextSpan *pSpanNavPoint,
            /* [out] */ VSITEMID *pItemID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMembers( 
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ DWORD dwFlags,
            /* [out] */ int *pcMembers,
            /* [out] */ BSTR **ppbstrDisplayNames,
            /* [out] */ BSTR **ppbstrMemberIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRenamed( 
            /* [in] */ ContainedLanguageRenameType clrt,
            /* [in] */ BSTR bstrOldID,
            /* [in] */ BSTR bstrNewID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsValidID( 
            /* [in] */ BSTR bstrID,
            /* [out] */ VARIANT_BOOL *pfIsValidID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBaseClassName( 
            /* [in] */ LPCWSTR pszClassName,
            /* [out] */ BSTR *pbstrBaseClassName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEventHandlerMemberID( 
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectTypeName,
            /* [in] */ LPCWSTR pszNameOfEvent,
            /* [in] */ LPCWSTR pszEventHandlerName,
            /* [out] */ BSTR *pbstrUniqueMemberID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompatibleEventHandlers( 
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectTypeName,
            /* [in] */ LPCWSTR pszNameOfEvent,
            /* [out] */ int *pcMembers,
            /* [out] */ BSTR **ppbstrEventHandlerNames,
            /* [out] */ BSTR **ppbstrMemberIDs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsContainedLanguageCodeSupportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsContainedLanguageCodeSupport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsContainedLanguageCodeSupport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsContainedLanguageCodeSupport * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateUniqueEventName )( 
            IVsContainedLanguageCodeSupport * This,
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectName,
            /* [in] */ LPCWSTR pszNameOfEvent,
            /* [out] */ BSTR *pbstrEventHandlerName);
        
        HRESULT ( STDMETHODCALLTYPE *EnsureEventHandler )( 
            IVsContainedLanguageCodeSupport * This,
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectTypeName,
            /* [in] */ LPCWSTR pszNameOfEvent,
            /* [in] */ LPCWSTR pszEventHandlerName,
            /* [in] */ VSITEMID itemidInsertionPoint,
            /* [out] */ BSTR *pbstrUniqueMemberID,
            /* [out] */ BSTR *pbstrEventBody,
            /* [out] */ TextSpan *pSpanInsertionPoint);
        
        HRESULT ( STDMETHODCALLTYPE *GetMemberNavigationPoint )( 
            IVsContainedLanguageCodeSupport * This,
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszUniqueMemberID,
            /* [out] */ TextSpan *pSpanNavPoint,
            /* [out] */ VSITEMID *pItemID);
        
        HRESULT ( STDMETHODCALLTYPE *GetMembers )( 
            IVsContainedLanguageCodeSupport * This,
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ DWORD dwFlags,
            /* [out] */ int *pcMembers,
            /* [out] */ BSTR **ppbstrDisplayNames,
            /* [out] */ BSTR **ppbstrMemberIDs);
        
        HRESULT ( STDMETHODCALLTYPE *OnRenamed )( 
            IVsContainedLanguageCodeSupport * This,
            /* [in] */ ContainedLanguageRenameType clrt,
            /* [in] */ BSTR bstrOldID,
            /* [in] */ BSTR bstrNewID);
        
        HRESULT ( STDMETHODCALLTYPE *IsValidID )( 
            IVsContainedLanguageCodeSupport * This,
            /* [in] */ BSTR bstrID,
            /* [out] */ VARIANT_BOOL *pfIsValidID);
        
        HRESULT ( STDMETHODCALLTYPE *GetBaseClassName )( 
            IVsContainedLanguageCodeSupport * This,
            /* [in] */ LPCWSTR pszClassName,
            /* [out] */ BSTR *pbstrBaseClassName);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventHandlerMemberID )( 
            IVsContainedLanguageCodeSupport * This,
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectTypeName,
            /* [in] */ LPCWSTR pszNameOfEvent,
            /* [in] */ LPCWSTR pszEventHandlerName,
            /* [out] */ BSTR *pbstrUniqueMemberID);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompatibleEventHandlers )( 
            IVsContainedLanguageCodeSupport * This,
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectTypeName,
            /* [in] */ LPCWSTR pszNameOfEvent,
            /* [out] */ int *pcMembers,
            /* [out] */ BSTR **ppbstrEventHandlerNames,
            /* [out] */ BSTR **ppbstrMemberIDs);
        
        END_INTERFACE
    } IVsContainedLanguageCodeSupportVtbl;

    interface IVsContainedLanguageCodeSupport
    {
        CONST_VTBL struct IVsContainedLanguageCodeSupportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsContainedLanguageCodeSupport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsContainedLanguageCodeSupport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsContainedLanguageCodeSupport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsContainedLanguageCodeSupport_CreateUniqueEventName(This,pszClassName,pszObjectName,pszNameOfEvent,pbstrEventHandlerName)	\
    (This)->lpVtbl -> CreateUniqueEventName(This,pszClassName,pszObjectName,pszNameOfEvent,pbstrEventHandlerName)

#define IVsContainedLanguageCodeSupport_EnsureEventHandler(This,pszClassName,pszObjectTypeName,pszNameOfEvent,pszEventHandlerName,itemidInsertionPoint,pbstrUniqueMemberID,pbstrEventBody,pSpanInsertionPoint)	\
    (This)->lpVtbl -> EnsureEventHandler(This,pszClassName,pszObjectTypeName,pszNameOfEvent,pszEventHandlerName,itemidInsertionPoint,pbstrUniqueMemberID,pbstrEventBody,pSpanInsertionPoint)

#define IVsContainedLanguageCodeSupport_GetMemberNavigationPoint(This,pszClassName,pszUniqueMemberID,pSpanNavPoint,pItemID)	\
    (This)->lpVtbl -> GetMemberNavigationPoint(This,pszClassName,pszUniqueMemberID,pSpanNavPoint,pItemID)

#define IVsContainedLanguageCodeSupport_GetMembers(This,pszClassName,dwFlags,pcMembers,ppbstrDisplayNames,ppbstrMemberIDs)	\
    (This)->lpVtbl -> GetMembers(This,pszClassName,dwFlags,pcMembers,ppbstrDisplayNames,ppbstrMemberIDs)

#define IVsContainedLanguageCodeSupport_OnRenamed(This,clrt,bstrOldID,bstrNewID)	\
    (This)->lpVtbl -> OnRenamed(This,clrt,bstrOldID,bstrNewID)

#define IVsContainedLanguageCodeSupport_IsValidID(This,bstrID,pfIsValidID)	\
    (This)->lpVtbl -> IsValidID(This,bstrID,pfIsValidID)

#define IVsContainedLanguageCodeSupport_GetBaseClassName(This,pszClassName,pbstrBaseClassName)	\
    (This)->lpVtbl -> GetBaseClassName(This,pszClassName,pbstrBaseClassName)

#define IVsContainedLanguageCodeSupport_GetEventHandlerMemberID(This,pszClassName,pszObjectTypeName,pszNameOfEvent,pszEventHandlerName,pbstrUniqueMemberID)	\
    (This)->lpVtbl -> GetEventHandlerMemberID(This,pszClassName,pszObjectTypeName,pszNameOfEvent,pszEventHandlerName,pbstrUniqueMemberID)

#define IVsContainedLanguageCodeSupport_GetCompatibleEventHandlers(This,pszClassName,pszObjectTypeName,pszNameOfEvent,pcMembers,ppbstrEventHandlerNames,ppbstrMemberIDs)	\
    (This)->lpVtbl -> GetCompatibleEventHandlers(This,pszClassName,pszObjectTypeName,pszNameOfEvent,pcMembers,ppbstrEventHandlerNames,ppbstrMemberIDs)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsContainedLanguageCodeSupport_CreateUniqueEventName_Proxy( 
    IVsContainedLanguageCodeSupport * This,
    /* [in] */ LPCWSTR pszClassName,
    /* [in] */ LPCWSTR pszObjectName,
    /* [in] */ LPCWSTR pszNameOfEvent,
    /* [out] */ BSTR *pbstrEventHandlerName);


void __RPC_STUB IVsContainedLanguageCodeSupport_CreateUniqueEventName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageCodeSupport_EnsureEventHandler_Proxy( 
    IVsContainedLanguageCodeSupport * This,
    /* [in] */ LPCWSTR pszClassName,
    /* [in] */ LPCWSTR pszObjectTypeName,
    /* [in] */ LPCWSTR pszNameOfEvent,
    /* [in] */ LPCWSTR pszEventHandlerName,
    /* [in] */ VSITEMID itemidInsertionPoint,
    /* [out] */ BSTR *pbstrUniqueMemberID,
    /* [out] */ BSTR *pbstrEventBody,
    /* [out] */ TextSpan *pSpanInsertionPoint);


void __RPC_STUB IVsContainedLanguageCodeSupport_EnsureEventHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageCodeSupport_GetMemberNavigationPoint_Proxy( 
    IVsContainedLanguageCodeSupport * This,
    /* [in] */ LPCWSTR pszClassName,
    /* [in] */ LPCWSTR pszUniqueMemberID,
    /* [out] */ TextSpan *pSpanNavPoint,
    /* [out] */ VSITEMID *pItemID);


void __RPC_STUB IVsContainedLanguageCodeSupport_GetMemberNavigationPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageCodeSupport_GetMembers_Proxy( 
    IVsContainedLanguageCodeSupport * This,
    /* [in] */ LPCWSTR pszClassName,
    /* [in] */ DWORD dwFlags,
    /* [out] */ int *pcMembers,
    /* [out] */ BSTR **ppbstrDisplayNames,
    /* [out] */ BSTR **ppbstrMemberIDs);


void __RPC_STUB IVsContainedLanguageCodeSupport_GetMembers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageCodeSupport_OnRenamed_Proxy( 
    IVsContainedLanguageCodeSupport * This,
    /* [in] */ ContainedLanguageRenameType clrt,
    /* [in] */ BSTR bstrOldID,
    /* [in] */ BSTR bstrNewID);


void __RPC_STUB IVsContainedLanguageCodeSupport_OnRenamed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageCodeSupport_IsValidID_Proxy( 
    IVsContainedLanguageCodeSupport * This,
    /* [in] */ BSTR bstrID,
    /* [out] */ VARIANT_BOOL *pfIsValidID);


void __RPC_STUB IVsContainedLanguageCodeSupport_IsValidID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageCodeSupport_GetBaseClassName_Proxy( 
    IVsContainedLanguageCodeSupport * This,
    /* [in] */ LPCWSTR pszClassName,
    /* [out] */ BSTR *pbstrBaseClassName);


void __RPC_STUB IVsContainedLanguageCodeSupport_GetBaseClassName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageCodeSupport_GetEventHandlerMemberID_Proxy( 
    IVsContainedLanguageCodeSupport * This,
    /* [in] */ LPCWSTR pszClassName,
    /* [in] */ LPCWSTR pszObjectTypeName,
    /* [in] */ LPCWSTR pszNameOfEvent,
    /* [in] */ LPCWSTR pszEventHandlerName,
    /* [out] */ BSTR *pbstrUniqueMemberID);


void __RPC_STUB IVsContainedLanguageCodeSupport_GetEventHandlerMemberID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageCodeSupport_GetCompatibleEventHandlers_Proxy( 
    IVsContainedLanguageCodeSupport * This,
    /* [in] */ LPCWSTR pszClassName,
    /* [in] */ LPCWSTR pszObjectTypeName,
    /* [in] */ LPCWSTR pszNameOfEvent,
    /* [out] */ int *pcMembers,
    /* [out] */ BSTR **ppbstrEventHandlerNames,
    /* [out] */ BSTR **ppbstrMemberIDs);


void __RPC_STUB IVsContainedLanguageCodeSupport_GetCompatibleEventHandlers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsContainedLanguageCodeSupport_INTERFACE_DEFINED__ */


#ifndef __IVsContainedLanguageStaticEventBinding_INTERFACE_DEFINED__
#define __IVsContainedLanguageStaticEventBinding_INTERFACE_DEFINED__

/* interface IVsContainedLanguageStaticEventBinding */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsContainedLanguageStaticEventBinding;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("22ff7776-2c9a-48c4-809f-39e5184cc32d")
    IVsContainedLanguageStaticEventBinding : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStaticEventBindingsForObject( 
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectName,
            /* [out] */ int *pcMembers,
            /* [out] */ BSTR **ppbstrEventNames,
            /* [out] */ BSTR **ppbstrDisplayNames,
            /* [out] */ BSTR **ppbstrMemberIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveStaticEventBinding( 
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszUniqueMemberID,
            /* [in] */ LPCWSTR pszObjectName,
            /* [in] */ LPCWSTR pszNameOfEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddStaticEventBinding( 
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszUniqueMemberID,
            /* [in] */ LPCWSTR pszObjectName,
            /* [in] */ LPCWSTR pszNameOfEvent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnsureStaticEventHandler( 
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectTypeName,
            /* [in] */ LPCWSTR pszObjectName,
            /* [in] */ LPCWSTR pszNameOfEvent,
            /* [in] */ LPCWSTR pszEventHandlerName,
            /* [in] */ VSITEMID itemidInsertionPoint,
            /* [out] */ BSTR *pbstrUniqueMemberID,
            /* [out] */ BSTR *pbstrEventBody,
            /* [out] */ TextSpan *pSpanInsertionPoint) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsContainedLanguageStaticEventBindingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsContainedLanguageStaticEventBinding * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsContainedLanguageStaticEventBinding * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsContainedLanguageStaticEventBinding * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetStaticEventBindingsForObject )( 
            IVsContainedLanguageStaticEventBinding * This,
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectName,
            /* [out] */ int *pcMembers,
            /* [out] */ BSTR **ppbstrEventNames,
            /* [out] */ BSTR **ppbstrDisplayNames,
            /* [out] */ BSTR **ppbstrMemberIDs);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveStaticEventBinding )( 
            IVsContainedLanguageStaticEventBinding * This,
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszUniqueMemberID,
            /* [in] */ LPCWSTR pszObjectName,
            /* [in] */ LPCWSTR pszNameOfEvent);
        
        HRESULT ( STDMETHODCALLTYPE *AddStaticEventBinding )( 
            IVsContainedLanguageStaticEventBinding * This,
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszUniqueMemberID,
            /* [in] */ LPCWSTR pszObjectName,
            /* [in] */ LPCWSTR pszNameOfEvent);
        
        HRESULT ( STDMETHODCALLTYPE *EnsureStaticEventHandler )( 
            IVsContainedLanguageStaticEventBinding * This,
            /* [in] */ LPCWSTR pszClassName,
            /* [in] */ LPCWSTR pszObjectTypeName,
            /* [in] */ LPCWSTR pszObjectName,
            /* [in] */ LPCWSTR pszNameOfEvent,
            /* [in] */ LPCWSTR pszEventHandlerName,
            /* [in] */ VSITEMID itemidInsertionPoint,
            /* [out] */ BSTR *pbstrUniqueMemberID,
            /* [out] */ BSTR *pbstrEventBody,
            /* [out] */ TextSpan *pSpanInsertionPoint);
        
        END_INTERFACE
    } IVsContainedLanguageStaticEventBindingVtbl;

    interface IVsContainedLanguageStaticEventBinding
    {
        CONST_VTBL struct IVsContainedLanguageStaticEventBindingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsContainedLanguageStaticEventBinding_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsContainedLanguageStaticEventBinding_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsContainedLanguageStaticEventBinding_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsContainedLanguageStaticEventBinding_GetStaticEventBindingsForObject(This,pszClassName,pszObjectName,pcMembers,ppbstrEventNames,ppbstrDisplayNames,ppbstrMemberIDs)	\
    (This)->lpVtbl -> GetStaticEventBindingsForObject(This,pszClassName,pszObjectName,pcMembers,ppbstrEventNames,ppbstrDisplayNames,ppbstrMemberIDs)

#define IVsContainedLanguageStaticEventBinding_RemoveStaticEventBinding(This,pszClassName,pszUniqueMemberID,pszObjectName,pszNameOfEvent)	\
    (This)->lpVtbl -> RemoveStaticEventBinding(This,pszClassName,pszUniqueMemberID,pszObjectName,pszNameOfEvent)

#define IVsContainedLanguageStaticEventBinding_AddStaticEventBinding(This,pszClassName,pszUniqueMemberID,pszObjectName,pszNameOfEvent)	\
    (This)->lpVtbl -> AddStaticEventBinding(This,pszClassName,pszUniqueMemberID,pszObjectName,pszNameOfEvent)

#define IVsContainedLanguageStaticEventBinding_EnsureStaticEventHandler(This,pszClassName,pszObjectTypeName,pszObjectName,pszNameOfEvent,pszEventHandlerName,itemidInsertionPoint,pbstrUniqueMemberID,pbstrEventBody,pSpanInsertionPoint)	\
    (This)->lpVtbl -> EnsureStaticEventHandler(This,pszClassName,pszObjectTypeName,pszObjectName,pszNameOfEvent,pszEventHandlerName,itemidInsertionPoint,pbstrUniqueMemberID,pbstrEventBody,pSpanInsertionPoint)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsContainedLanguageStaticEventBinding_GetStaticEventBindingsForObject_Proxy( 
    IVsContainedLanguageStaticEventBinding * This,
    /* [in] */ LPCWSTR pszClassName,
    /* [in] */ LPCWSTR pszObjectName,
    /* [out] */ int *pcMembers,
    /* [out] */ BSTR **ppbstrEventNames,
    /* [out] */ BSTR **ppbstrDisplayNames,
    /* [out] */ BSTR **ppbstrMemberIDs);


void __RPC_STUB IVsContainedLanguageStaticEventBinding_GetStaticEventBindingsForObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageStaticEventBinding_RemoveStaticEventBinding_Proxy( 
    IVsContainedLanguageStaticEventBinding * This,
    /* [in] */ LPCWSTR pszClassName,
    /* [in] */ LPCWSTR pszUniqueMemberID,
    /* [in] */ LPCWSTR pszObjectName,
    /* [in] */ LPCWSTR pszNameOfEvent);


void __RPC_STUB IVsContainedLanguageStaticEventBinding_RemoveStaticEventBinding_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageStaticEventBinding_AddStaticEventBinding_Proxy( 
    IVsContainedLanguageStaticEventBinding * This,
    /* [in] */ LPCWSTR pszClassName,
    /* [in] */ LPCWSTR pszUniqueMemberID,
    /* [in] */ LPCWSTR pszObjectName,
    /* [in] */ LPCWSTR pszNameOfEvent);


void __RPC_STUB IVsContainedLanguageStaticEventBinding_AddStaticEventBinding_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedLanguageStaticEventBinding_EnsureStaticEventHandler_Proxy( 
    IVsContainedLanguageStaticEventBinding * This,
    /* [in] */ LPCWSTR pszClassName,
    /* [in] */ LPCWSTR pszObjectTypeName,
    /* [in] */ LPCWSTR pszObjectName,
    /* [in] */ LPCWSTR pszNameOfEvent,
    /* [in] */ LPCWSTR pszEventHandlerName,
    /* [in] */ VSITEMID itemidInsertionPoint,
    /* [out] */ BSTR *pbstrUniqueMemberID,
    /* [out] */ BSTR *pbstrEventBody,
    /* [out] */ TextSpan *pSpanInsertionPoint);


void __RPC_STUB IVsContainedLanguageStaticEventBinding_EnsureStaticEventHandler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsContainedLanguageStaticEventBinding_INTERFACE_DEFINED__ */


#ifndef __IVsWebFormDesignerSupport_INTERFACE_DEFINED__
#define __IVsWebFormDesignerSupport_INTERFACE_DEFINED__

/* interface IVsWebFormDesignerSupport */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsWebFormDesignerSupport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2139dfc1-b0ad-4c17-a817-74f2ba47c714")
    IVsWebFormDesignerSupport : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCodeDomProvider( 
            /* [out] */ IUnknown **ppProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddReference( 
            /* [in] */ LPCWSTR pszReference) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsWebFormDesignerSupportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsWebFormDesignerSupport * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsWebFormDesignerSupport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsWebFormDesignerSupport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCodeDomProvider )( 
            IVsWebFormDesignerSupport * This,
            /* [out] */ IUnknown **ppProvider);
        
        HRESULT ( STDMETHODCALLTYPE *AddReference )( 
            IVsWebFormDesignerSupport * This,
            /* [in] */ LPCWSTR pszReference);
        
        END_INTERFACE
    } IVsWebFormDesignerSupportVtbl;

    interface IVsWebFormDesignerSupport
    {
        CONST_VTBL struct IVsWebFormDesignerSupportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsWebFormDesignerSupport_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsWebFormDesignerSupport_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsWebFormDesignerSupport_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsWebFormDesignerSupport_GetCodeDomProvider(This,ppProvider)	\
    (This)->lpVtbl -> GetCodeDomProvider(This,ppProvider)

#define IVsWebFormDesignerSupport_AddReference(This,pszReference)	\
    (This)->lpVtbl -> AddReference(This,pszReference)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsWebFormDesignerSupport_GetCodeDomProvider_Proxy( 
    IVsWebFormDesignerSupport * This,
    /* [out] */ IUnknown **ppProvider);


void __RPC_STUB IVsWebFormDesignerSupport_GetCodeDomProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebFormDesignerSupport_AddReference_Proxy( 
    IVsWebFormDesignerSupport * This,
    /* [in] */ LPCWSTR pszReference);


void __RPC_STUB IVsWebFormDesignerSupport_AddReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsWebFormDesignerSupport_INTERFACE_DEFINED__ */


#ifndef __IVsEnumCodeBlocks_INTERFACE_DEFINED__
#define __IVsEnumCodeBlocks_INTERFACE_DEFINED__

/* interface IVsEnumCodeBlocks */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsEnumCodeBlocks;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("07a45a82-5354-4dde-ac7d-60f2cdd5573b")
    IVsEnumCodeBlocks : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ TextSpanAndCookie *rgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumCodeBlocks **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumCodeBlocksVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumCodeBlocks * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumCodeBlocks * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumCodeBlocks * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumCodeBlocks * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ TextSpanAndCookie *rgelt,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumCodeBlocks * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumCodeBlocks * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumCodeBlocks * This,
            /* [out] */ IVsEnumCodeBlocks **ppenum);
        
        END_INTERFACE
    } IVsEnumCodeBlocksVtbl;

    interface IVsEnumCodeBlocks
    {
        CONST_VTBL struct IVsEnumCodeBlocksVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumCodeBlocks_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumCodeBlocks_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumCodeBlocks_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumCodeBlocks_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IVsEnumCodeBlocks_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IVsEnumCodeBlocks_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumCodeBlocks_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumCodeBlocks_Next_Proxy( 
    IVsEnumCodeBlocks * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ TextSpanAndCookie *rgelt,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsEnumCodeBlocks_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumCodeBlocks_Skip_Proxy( 
    IVsEnumCodeBlocks * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IVsEnumCodeBlocks_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumCodeBlocks_Reset_Proxy( 
    IVsEnumCodeBlocks * This);


void __RPC_STUB IVsEnumCodeBlocks_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumCodeBlocks_Clone_Proxy( 
    IVsEnumCodeBlocks * This,
    /* [out] */ IVsEnumCodeBlocks **ppenum);


void __RPC_STUB IVsEnumCodeBlocks_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumCodeBlocks_INTERFACE_DEFINED__ */


#ifndef __IVsContainedCode_INTERFACE_DEFINED__
#define __IVsContainedCode_INTERFACE_DEFINED__

/* interface IVsContainedCode */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsContainedCode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("171a72ae-bae6-4b66-9a58-4691f08ed9f2")
    IVsContainedCode : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumOriginalCodeBlocks( 
            /* [out] */ IVsEnumCodeBlocks **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HostSpansUpdated( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsContainedCodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsContainedCode * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsContainedCode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsContainedCode * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumOriginalCodeBlocks )( 
            IVsContainedCode * This,
            /* [out] */ IVsEnumCodeBlocks **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *HostSpansUpdated )( 
            IVsContainedCode * This);
        
        END_INTERFACE
    } IVsContainedCodeVtbl;

    interface IVsContainedCode
    {
        CONST_VTBL struct IVsContainedCodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsContainedCode_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsContainedCode_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsContainedCode_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsContainedCode_EnumOriginalCodeBlocks(This,ppEnum)	\
    (This)->lpVtbl -> EnumOriginalCodeBlocks(This,ppEnum)

#define IVsContainedCode_HostSpansUpdated(This)	\
    (This)->lpVtbl -> HostSpansUpdated(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsContainedCode_EnumOriginalCodeBlocks_Proxy( 
    IVsContainedCode * This,
    /* [out] */ IVsEnumCodeBlocks **ppEnum);


void __RPC_STUB IVsContainedCode_EnumOriginalCodeBlocks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContainedCode_HostSpansUpdated_Proxy( 
    IVsContainedCode * This);


void __RPC_STUB IVsContainedCode_HostSpansUpdated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsContainedCode_INTERFACE_DEFINED__ */


#ifndef __IVsContainedLanguageFactory_INTERFACE_DEFINED__
#define __IVsContainedLanguageFactory_INTERFACE_DEFINED__

/* interface IVsContainedLanguageFactory */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsContainedLanguageFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9fd1bd52-9d32-4697-b446-36582b865c34")
    IVsContainedLanguageFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLanguage( 
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [in] */ VSITEMID itemid,
            /* [in] */ IVsTextBufferCoordinator *pBufferCoordinator,
            /* [retval][out] */ IVsContainedLanguage **ppLanguage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsContainedLanguageFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsContainedLanguageFactory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsContainedLanguageFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsContainedLanguageFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetLanguage )( 
            IVsContainedLanguageFactory * This,
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [in] */ VSITEMID itemid,
            /* [in] */ IVsTextBufferCoordinator *pBufferCoordinator,
            /* [retval][out] */ IVsContainedLanguage **ppLanguage);
        
        END_INTERFACE
    } IVsContainedLanguageFactoryVtbl;

    interface IVsContainedLanguageFactory
    {
        CONST_VTBL struct IVsContainedLanguageFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsContainedLanguageFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsContainedLanguageFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsContainedLanguageFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsContainedLanguageFactory_GetLanguage(This,pHierarchy,itemid,pBufferCoordinator,ppLanguage)	\
    (This)->lpVtbl -> GetLanguage(This,pHierarchy,itemid,pBufferCoordinator,ppLanguage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsContainedLanguageFactory_GetLanguage_Proxy( 
    IVsContainedLanguageFactory * This,
    /* [in] */ IVsHierarchy *pHierarchy,
    /* [in] */ VSITEMID itemid,
    /* [in] */ IVsTextBufferCoordinator *pBufferCoordinator,
    /* [retval][out] */ IVsContainedLanguage **ppLanguage);


void __RPC_STUB IVsContainedLanguageFactory_GetLanguage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsContainedLanguageFactory_INTERFACE_DEFINED__ */


#ifndef __IVsContainedLanguageProjectNameProvider_INTERFACE_DEFINED__
#define __IVsContainedLanguageProjectNameProvider_INTERFACE_DEFINED__

/* interface IVsContainedLanguageProjectNameProvider */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsContainedLanguageProjectNameProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f77b0dd6-420b-4e7c-a0b3-c8d5b10a0997")
    IVsContainedLanguageProjectNameProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetProjectName( 
            /* [in] */ VSITEMID itemid,
            /* [retval][out] */ BSTR *pbstrProjectName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsContainedLanguageProjectNameProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsContainedLanguageProjectNameProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsContainedLanguageProjectNameProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsContainedLanguageProjectNameProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProjectName )( 
            IVsContainedLanguageProjectNameProvider * This,
            /* [in] */ VSITEMID itemid,
            /* [retval][out] */ BSTR *pbstrProjectName);
        
        END_INTERFACE
    } IVsContainedLanguageProjectNameProviderVtbl;

    interface IVsContainedLanguageProjectNameProvider
    {
        CONST_VTBL struct IVsContainedLanguageProjectNameProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsContainedLanguageProjectNameProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsContainedLanguageProjectNameProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsContainedLanguageProjectNameProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsContainedLanguageProjectNameProvider_GetProjectName(This,itemid,pbstrProjectName)	\
    (This)->lpVtbl -> GetProjectName(This,itemid,pbstrProjectName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsContainedLanguageProjectNameProvider_GetProjectName_Proxy( 
    IVsContainedLanguageProjectNameProvider * This,
    /* [in] */ VSITEMID itemid,
    /* [retval][out] */ BSTR *pbstrProjectName);


void __RPC_STUB IVsContainedLanguageProjectNameProvider_GetProjectName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsContainedLanguageProjectNameProvider_INTERFACE_DEFINED__ */


#ifndef __IVsEnumBufferCoordinatorSpans_INTERFACE_DEFINED__
#define __IVsEnumBufferCoordinatorSpans_INTERFACE_DEFINED__

/* interface IVsEnumBufferCoordinatorSpans */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsEnumBufferCoordinatorSpans;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5FCEEA4C-D49F-4acd-B816-130A5DCD4C54")
    IVsEnumBufferCoordinatorSpans : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out][in] */ NewSpanMapping *rgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumBufferCoordinatorSpans **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumBufferCoordinatorSpansVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumBufferCoordinatorSpans * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumBufferCoordinatorSpans * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumBufferCoordinatorSpans * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumBufferCoordinatorSpans * This,
            /* [in] */ ULONG celt,
            /* [out][in] */ NewSpanMapping *rgelt,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumBufferCoordinatorSpans * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumBufferCoordinatorSpans * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumBufferCoordinatorSpans * This,
            /* [out] */ IVsEnumBufferCoordinatorSpans **ppEnum);
        
        END_INTERFACE
    } IVsEnumBufferCoordinatorSpansVtbl;

    interface IVsEnumBufferCoordinatorSpans
    {
        CONST_VTBL struct IVsEnumBufferCoordinatorSpansVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumBufferCoordinatorSpans_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumBufferCoordinatorSpans_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumBufferCoordinatorSpans_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumBufferCoordinatorSpans_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IVsEnumBufferCoordinatorSpans_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IVsEnumBufferCoordinatorSpans_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumBufferCoordinatorSpans_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumBufferCoordinatorSpans_Next_Proxy( 
    IVsEnumBufferCoordinatorSpans * This,
    /* [in] */ ULONG celt,
    /* [out][in] */ NewSpanMapping *rgelt,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsEnumBufferCoordinatorSpans_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumBufferCoordinatorSpans_Skip_Proxy( 
    IVsEnumBufferCoordinatorSpans * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IVsEnumBufferCoordinatorSpans_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumBufferCoordinatorSpans_Reset_Proxy( 
    IVsEnumBufferCoordinatorSpans * This);


void __RPC_STUB IVsEnumBufferCoordinatorSpans_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumBufferCoordinatorSpans_Clone_Proxy( 
    IVsEnumBufferCoordinatorSpans * This,
    /* [out] */ IVsEnumBufferCoordinatorSpans **ppEnum);


void __RPC_STUB IVsEnumBufferCoordinatorSpans_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumBufferCoordinatorSpans_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_VsTextBufferCoordinator;

#ifdef __cplusplus

class DECLSPEC_UUID("3e77fa94-526f-4233-bf81-b2b0329a62b9")
VsTextBufferCoordinator;
#endif

#ifndef __IVsTextBufferCoordinator_INTERFACE_DEFINED__
#define __IVsTextBufferCoordinator_INTERFACE_DEFINED__

/* interface IVsTextBufferCoordinator */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextBufferCoordinator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("84465401-2886-4ce0-af50-c0560226ed40")
    IVsTextBufferCoordinator : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetBuffers( 
            /* [in] */ IVsTextLines *pPrimaryBuffer,
            /* [in] */ IVsTextLines *pSecondaryBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSpanMappings( 
            /* [in] */ long cSpans,
            /* [size_is][in] */ NewSpanMapping *rgSpans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MapPrimaryToSecondarySpan( 
            /* [in] */ TextSpan tsPrimary,
            /* [out] */ TextSpan *ptsSecondary) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MapSecondaryToPrimarySpan( 
            /* [in] */ TextSpan tsSecondary,
            /* [out] */ TextSpan *ptsPrimary) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrimaryBuffer( 
            /* [out] */ IVsTextLines **ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSecondaryBuffer( 
            /* [out] */ IVsTextLines **ppBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableReplication( 
            /* [in] */ DWORD bcrd,
            /* [in] */ BOOL fEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMappingOfPrimaryPosition( 
            /* [in] */ long lPosition,
            /* [out] */ TextSpan *ptsPrimary,
            /* [out] */ TextSpan *ptsSecondary) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBufferMappingModes( 
            /* [in] */ DWORD bcmmPrimary,
            /* [in] */ DWORD bcmmSecondary) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumSpans( 
            IVsEnumBufferCoordinatorSpans **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextBufferCoordinatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextBufferCoordinator * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextBufferCoordinator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextBufferCoordinator * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetBuffers )( 
            IVsTextBufferCoordinator * This,
            /* [in] */ IVsTextLines *pPrimaryBuffer,
            /* [in] */ IVsTextLines *pSecondaryBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *SetSpanMappings )( 
            IVsTextBufferCoordinator * This,
            /* [in] */ long cSpans,
            /* [size_is][in] */ NewSpanMapping *rgSpans);
        
        HRESULT ( STDMETHODCALLTYPE *MapPrimaryToSecondarySpan )( 
            IVsTextBufferCoordinator * This,
            /* [in] */ TextSpan tsPrimary,
            /* [out] */ TextSpan *ptsSecondary);
        
        HRESULT ( STDMETHODCALLTYPE *MapSecondaryToPrimarySpan )( 
            IVsTextBufferCoordinator * This,
            /* [in] */ TextSpan tsSecondary,
            /* [out] */ TextSpan *ptsPrimary);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrimaryBuffer )( 
            IVsTextBufferCoordinator * This,
            /* [out] */ IVsTextLines **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *GetSecondaryBuffer )( 
            IVsTextBufferCoordinator * This,
            /* [out] */ IVsTextLines **ppBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *EnableReplication )( 
            IVsTextBufferCoordinator * This,
            /* [in] */ DWORD bcrd,
            /* [in] */ BOOL fEnable);
        
        HRESULT ( STDMETHODCALLTYPE *GetMappingOfPrimaryPosition )( 
            IVsTextBufferCoordinator * This,
            /* [in] */ long lPosition,
            /* [out] */ TextSpan *ptsPrimary,
            /* [out] */ TextSpan *ptsSecondary);
        
        HRESULT ( STDMETHODCALLTYPE *SetBufferMappingModes )( 
            IVsTextBufferCoordinator * This,
            /* [in] */ DWORD bcmmPrimary,
            /* [in] */ DWORD bcmmSecondary);
        
        HRESULT ( STDMETHODCALLTYPE *EnumSpans )( 
            IVsTextBufferCoordinator * This,
            IVsEnumBufferCoordinatorSpans **ppEnum);
        
        END_INTERFACE
    } IVsTextBufferCoordinatorVtbl;

    interface IVsTextBufferCoordinator
    {
        CONST_VTBL struct IVsTextBufferCoordinatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextBufferCoordinator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextBufferCoordinator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextBufferCoordinator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextBufferCoordinator_SetBuffers(This,pPrimaryBuffer,pSecondaryBuffer)	\
    (This)->lpVtbl -> SetBuffers(This,pPrimaryBuffer,pSecondaryBuffer)

#define IVsTextBufferCoordinator_SetSpanMappings(This,cSpans,rgSpans)	\
    (This)->lpVtbl -> SetSpanMappings(This,cSpans,rgSpans)

#define IVsTextBufferCoordinator_MapPrimaryToSecondarySpan(This,tsPrimary,ptsSecondary)	\
    (This)->lpVtbl -> MapPrimaryToSecondarySpan(This,tsPrimary,ptsSecondary)

#define IVsTextBufferCoordinator_MapSecondaryToPrimarySpan(This,tsSecondary,ptsPrimary)	\
    (This)->lpVtbl -> MapSecondaryToPrimarySpan(This,tsSecondary,ptsPrimary)

#define IVsTextBufferCoordinator_GetPrimaryBuffer(This,ppBuffer)	\
    (This)->lpVtbl -> GetPrimaryBuffer(This,ppBuffer)

#define IVsTextBufferCoordinator_GetSecondaryBuffer(This,ppBuffer)	\
    (This)->lpVtbl -> GetSecondaryBuffer(This,ppBuffer)

#define IVsTextBufferCoordinator_EnableReplication(This,bcrd,fEnable)	\
    (This)->lpVtbl -> EnableReplication(This,bcrd,fEnable)

#define IVsTextBufferCoordinator_GetMappingOfPrimaryPosition(This,lPosition,ptsPrimary,ptsSecondary)	\
    (This)->lpVtbl -> GetMappingOfPrimaryPosition(This,lPosition,ptsPrimary,ptsSecondary)

#define IVsTextBufferCoordinator_SetBufferMappingModes(This,bcmmPrimary,bcmmSecondary)	\
    (This)->lpVtbl -> SetBufferMappingModes(This,bcmmPrimary,bcmmSecondary)

#define IVsTextBufferCoordinator_EnumSpans(This,ppEnum)	\
    (This)->lpVtbl -> EnumSpans(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextBufferCoordinator_SetBuffers_Proxy( 
    IVsTextBufferCoordinator * This,
    /* [in] */ IVsTextLines *pPrimaryBuffer,
    /* [in] */ IVsTextLines *pSecondaryBuffer);


void __RPC_STUB IVsTextBufferCoordinator_SetBuffers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextBufferCoordinator_SetSpanMappings_Proxy( 
    IVsTextBufferCoordinator * This,
    /* [in] */ long cSpans,
    /* [size_is][in] */ NewSpanMapping *rgSpans);


void __RPC_STUB IVsTextBufferCoordinator_SetSpanMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextBufferCoordinator_MapPrimaryToSecondarySpan_Proxy( 
    IVsTextBufferCoordinator * This,
    /* [in] */ TextSpan tsPrimary,
    /* [out] */ TextSpan *ptsSecondary);


void __RPC_STUB IVsTextBufferCoordinator_MapPrimaryToSecondarySpan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextBufferCoordinator_MapSecondaryToPrimarySpan_Proxy( 
    IVsTextBufferCoordinator * This,
    /* [in] */ TextSpan tsSecondary,
    /* [out] */ TextSpan *ptsPrimary);


void __RPC_STUB IVsTextBufferCoordinator_MapSecondaryToPrimarySpan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextBufferCoordinator_GetPrimaryBuffer_Proxy( 
    IVsTextBufferCoordinator * This,
    /* [out] */ IVsTextLines **ppBuffer);


void __RPC_STUB IVsTextBufferCoordinator_GetPrimaryBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextBufferCoordinator_GetSecondaryBuffer_Proxy( 
    IVsTextBufferCoordinator * This,
    /* [out] */ IVsTextLines **ppBuffer);


void __RPC_STUB IVsTextBufferCoordinator_GetSecondaryBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextBufferCoordinator_EnableReplication_Proxy( 
    IVsTextBufferCoordinator * This,
    /* [in] */ DWORD bcrd,
    /* [in] */ BOOL fEnable);


void __RPC_STUB IVsTextBufferCoordinator_EnableReplication_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextBufferCoordinator_GetMappingOfPrimaryPosition_Proxy( 
    IVsTextBufferCoordinator * This,
    /* [in] */ long lPosition,
    /* [out] */ TextSpan *ptsPrimary,
    /* [out] */ TextSpan *ptsSecondary);


void __RPC_STUB IVsTextBufferCoordinator_GetMappingOfPrimaryPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextBufferCoordinator_SetBufferMappingModes_Proxy( 
    IVsTextBufferCoordinator * This,
    /* [in] */ DWORD bcmmPrimary,
    /* [in] */ DWORD bcmmSecondary);


void __RPC_STUB IVsTextBufferCoordinator_SetBufferMappingModes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextBufferCoordinator_EnumSpans_Proxy( 
    IVsTextBufferCoordinator * This,
    IVsEnumBufferCoordinatorSpans **ppEnum);


void __RPC_STUB IVsTextBufferCoordinator_EnumSpans_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextBufferCoordinator_INTERFACE_DEFINED__ */


#ifndef __IVsSetSpanMappingEvents_INTERFACE_DEFINED__
#define __IVsSetSpanMappingEvents_INTERFACE_DEFINED__

/* interface IVsSetSpanMappingEvents */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsSetSpanMappingEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("98CEEDBD-07A4-4376-ADE8-5A46B7F5F384")
    IVsSetSpanMappingEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnBeginSetSpanMappings( 
            /* [in] */ long cSpans,
            /* [size_is][in] */ NewSpanMapping *rgSpans) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEndSetSpanMappings( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnMarkerInvalidated( 
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ IVsTextMarker *pMarker) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSetSpanMappingEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSetSpanMappingEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSetSpanMappingEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSetSpanMappingEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnBeginSetSpanMappings )( 
            IVsSetSpanMappingEvents * This,
            /* [in] */ long cSpans,
            /* [size_is][in] */ NewSpanMapping *rgSpans);
        
        HRESULT ( STDMETHODCALLTYPE *OnEndSetSpanMappings )( 
            IVsSetSpanMappingEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnMarkerInvalidated )( 
            IVsSetSpanMappingEvents * This,
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ IVsTextMarker *pMarker);
        
        END_INTERFACE
    } IVsSetSpanMappingEventsVtbl;

    interface IVsSetSpanMappingEvents
    {
        CONST_VTBL struct IVsSetSpanMappingEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSetSpanMappingEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSetSpanMappingEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSetSpanMappingEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSetSpanMappingEvents_OnBeginSetSpanMappings(This,cSpans,rgSpans)	\
    (This)->lpVtbl -> OnBeginSetSpanMappings(This,cSpans,rgSpans)

#define IVsSetSpanMappingEvents_OnEndSetSpanMappings(This)	\
    (This)->lpVtbl -> OnEndSetSpanMappings(This)

#define IVsSetSpanMappingEvents_OnMarkerInvalidated(This,pBuffer,pMarker)	\
    (This)->lpVtbl -> OnMarkerInvalidated(This,pBuffer,pMarker)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSetSpanMappingEvents_OnBeginSetSpanMappings_Proxy( 
    IVsSetSpanMappingEvents * This,
    /* [in] */ long cSpans,
    /* [size_is][in] */ NewSpanMapping *rgSpans);


void __RPC_STUB IVsSetSpanMappingEvents_OnBeginSetSpanMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetSpanMappingEvents_OnEndSetSpanMappings_Proxy( 
    IVsSetSpanMappingEvents * This);


void __RPC_STUB IVsSetSpanMappingEvents_OnEndSetSpanMappings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetSpanMappingEvents_OnMarkerInvalidated_Proxy( 
    IVsSetSpanMappingEvents * This,
    /* [in] */ IVsTextLines *pBuffer,
    /* [in] */ IVsTextMarker *pMarker);


void __RPC_STUB IVsSetSpanMappingEvents_OnMarkerInvalidated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSetSpanMappingEvents_INTERFACE_DEFINED__ */


#ifndef __IVsExternalCompletionSet_INTERFACE_DEFINED__
#define __IVsExternalCompletionSet_INTERFACE_DEFINED__

/* interface IVsExternalCompletionSet */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsExternalCompletionSet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("373A9399-FDF5-4f64-8866-E14B7F2CFFF7")
    IVsExternalCompletionSet : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetIntellisenseHost( 
            /* [in] */ IVsIntellisenseHost *pHost) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateCompSet( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsExternalCompletionSetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsExternalCompletionSet * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsExternalCompletionSet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsExternalCompletionSet * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIntellisenseHost )( 
            IVsExternalCompletionSet * This,
            /* [in] */ IVsIntellisenseHost *pHost);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateCompSet )( 
            IVsExternalCompletionSet * This);
        
        END_INTERFACE
    } IVsExternalCompletionSetVtbl;

    interface IVsExternalCompletionSet
    {
        CONST_VTBL struct IVsExternalCompletionSetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsExternalCompletionSet_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsExternalCompletionSet_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsExternalCompletionSet_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsExternalCompletionSet_SetIntellisenseHost(This,pHost)	\
    (This)->lpVtbl -> SetIntellisenseHost(This,pHost)

#define IVsExternalCompletionSet_UpdateCompSet(This)	\
    (This)->lpVtbl -> UpdateCompSet(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsExternalCompletionSet_SetIntellisenseHost_Proxy( 
    IVsExternalCompletionSet * This,
    /* [in] */ IVsIntellisenseHost *pHost);


void __RPC_STUB IVsExternalCompletionSet_SetIntellisenseHost_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExternalCompletionSet_UpdateCompSet_Proxy( 
    IVsExternalCompletionSet * This);


void __RPC_STUB IVsExternalCompletionSet_UpdateCompSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsExternalCompletionSet_INTERFACE_DEFINED__ */


#ifndef __IVsExpansionIntellisenseHost_INTERFACE_DEFINED__
#define __IVsExpansionIntellisenseHost_INTERFACE_DEFINED__

/* interface IVsExpansionIntellisenseHost */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsExpansionIntellisenseHost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DEF59D57-46FE-4984-8CA4-5EFA3AC5D16E")
    IVsExpansionIntellisenseHost : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTextLen( 
            /* [out] */ long *iLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetText( 
            /* [out] */ BSTR *bstrText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSelection( 
            /* [out] */ long *iStart,
            /* [out] */ long *iEnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSelection( 
            /* [in] */ long iStart,
            /* [in] */ long iEnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetText( 
            /* [in] */ BSTR bstrText,
            /* [in] */ BOOL fReplaceAll) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentLevel( 
            /* [out] */ long *pLevel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsExpansionIntellisenseHostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsExpansionIntellisenseHost * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsExpansionIntellisenseHost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsExpansionIntellisenseHost * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTextLen )( 
            IVsExpansionIntellisenseHost * This,
            /* [out] */ long *iLen);
        
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            IVsExpansionIntellisenseHost * This,
            /* [out] */ BSTR *bstrText);
        
        HRESULT ( STDMETHODCALLTYPE *GetSelection )( 
            IVsExpansionIntellisenseHost * This,
            /* [out] */ long *iStart,
            /* [out] */ long *iEnd);
        
        HRESULT ( STDMETHODCALLTYPE *SetSelection )( 
            IVsExpansionIntellisenseHost * This,
            /* [in] */ long iStart,
            /* [in] */ long iEnd);
        
        HRESULT ( STDMETHODCALLTYPE *SetText )( 
            IVsExpansionIntellisenseHost * This,
            /* [in] */ BSTR bstrText,
            /* [in] */ BOOL fReplaceAll);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentLevel )( 
            IVsExpansionIntellisenseHost * This,
            /* [out] */ long *pLevel);
        
        END_INTERFACE
    } IVsExpansionIntellisenseHostVtbl;

    interface IVsExpansionIntellisenseHost
    {
        CONST_VTBL struct IVsExpansionIntellisenseHostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsExpansionIntellisenseHost_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsExpansionIntellisenseHost_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsExpansionIntellisenseHost_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsExpansionIntellisenseHost_GetTextLen(This,iLen)	\
    (This)->lpVtbl -> GetTextLen(This,iLen)

#define IVsExpansionIntellisenseHost_GetText(This,bstrText)	\
    (This)->lpVtbl -> GetText(This,bstrText)

#define IVsExpansionIntellisenseHost_GetSelection(This,iStart,iEnd)	\
    (This)->lpVtbl -> GetSelection(This,iStart,iEnd)

#define IVsExpansionIntellisenseHost_SetSelection(This,iStart,iEnd)	\
    (This)->lpVtbl -> SetSelection(This,iStart,iEnd)

#define IVsExpansionIntellisenseHost_SetText(This,bstrText,fReplaceAll)	\
    (This)->lpVtbl -> SetText(This,bstrText,fReplaceAll)

#define IVsExpansionIntellisenseHost_GetCurrentLevel(This,pLevel)	\
    (This)->lpVtbl -> GetCurrentLevel(This,pLevel)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsExpansionIntellisenseHost_GetTextLen_Proxy( 
    IVsExpansionIntellisenseHost * This,
    /* [out] */ long *iLen);


void __RPC_STUB IVsExpansionIntellisenseHost_GetTextLen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionIntellisenseHost_GetText_Proxy( 
    IVsExpansionIntellisenseHost * This,
    /* [out] */ BSTR *bstrText);


void __RPC_STUB IVsExpansionIntellisenseHost_GetText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionIntellisenseHost_GetSelection_Proxy( 
    IVsExpansionIntellisenseHost * This,
    /* [out] */ long *iStart,
    /* [out] */ long *iEnd);


void __RPC_STUB IVsExpansionIntellisenseHost_GetSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionIntellisenseHost_SetSelection_Proxy( 
    IVsExpansionIntellisenseHost * This,
    /* [in] */ long iStart,
    /* [in] */ long iEnd);


void __RPC_STUB IVsExpansionIntellisenseHost_SetSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionIntellisenseHost_SetText_Proxy( 
    IVsExpansionIntellisenseHost * This,
    /* [in] */ BSTR bstrText,
    /* [in] */ BOOL fReplaceAll);


void __RPC_STUB IVsExpansionIntellisenseHost_SetText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionIntellisenseHost_GetCurrentLevel_Proxy( 
    IVsExpansionIntellisenseHost * This,
    /* [out] */ long *pLevel);


void __RPC_STUB IVsExpansionIntellisenseHost_GetCurrentLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsExpansionIntellisenseHost_INTERFACE_DEFINED__ */


#ifndef __IVsReportExternalErrors_INTERFACE_DEFINED__
#define __IVsReportExternalErrors_INTERFACE_DEFINED__

/* interface IVsReportExternalErrors */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsReportExternalErrors;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("96F0CABD-DB51-428f-A42D-C756057D35C2")
    IVsReportExternalErrors : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ClearAllErrors( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddNewErrors( 
            /* [in] */ IVsEnumExternalErrors *pErrors) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetErrors( 
            /* [out] */ IVsEnumExternalErrors **pErrors) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsReportExternalErrorsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsReportExternalErrors * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsReportExternalErrors * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsReportExternalErrors * This);
        
        HRESULT ( STDMETHODCALLTYPE *ClearAllErrors )( 
            IVsReportExternalErrors * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddNewErrors )( 
            IVsReportExternalErrors * This,
            /* [in] */ IVsEnumExternalErrors *pErrors);
        
        HRESULT ( STDMETHODCALLTYPE *GetErrors )( 
            IVsReportExternalErrors * This,
            /* [out] */ IVsEnumExternalErrors **pErrors);
        
        END_INTERFACE
    } IVsReportExternalErrorsVtbl;

    interface IVsReportExternalErrors
    {
        CONST_VTBL struct IVsReportExternalErrorsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsReportExternalErrors_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsReportExternalErrors_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsReportExternalErrors_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsReportExternalErrors_ClearAllErrors(This)	\
    (This)->lpVtbl -> ClearAllErrors(This)

#define IVsReportExternalErrors_AddNewErrors(This,pErrors)	\
    (This)->lpVtbl -> AddNewErrors(This,pErrors)

#define IVsReportExternalErrors_GetErrors(This,pErrors)	\
    (This)->lpVtbl -> GetErrors(This,pErrors)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsReportExternalErrors_ClearAllErrors_Proxy( 
    IVsReportExternalErrors * This);


void __RPC_STUB IVsReportExternalErrors_ClearAllErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsReportExternalErrors_AddNewErrors_Proxy( 
    IVsReportExternalErrors * This,
    /* [in] */ IVsEnumExternalErrors *pErrors);


void __RPC_STUB IVsReportExternalErrors_AddNewErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsReportExternalErrors_GetErrors_Proxy( 
    IVsReportExternalErrors * This,
    /* [out] */ IVsEnumExternalErrors **pErrors);


void __RPC_STUB IVsReportExternalErrors_GetErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsReportExternalErrors_INTERFACE_DEFINED__ */


#ifndef __IVsEnumExternalErrors_INTERFACE_DEFINED__
#define __IVsEnumExternalErrors_INTERFACE_DEFINED__

/* interface IVsEnumExternalErrors */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsEnumExternalErrors;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("20890A77-47C8-44dd-ABC7-3F0920C1B79A")
    IVsEnumExternalErrors : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [out][in] */ ExternalError *rgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumExternalErrors **ppErrors) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumExternalErrorsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumExternalErrors * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumExternalErrors * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumExternalErrors * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumExternalErrors * This,
            /* [in] */ ULONG celt,
            /* [out][in] */ ExternalError *rgelt,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumExternalErrors * This,
            /* [in] */ ULONG celts);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumExternalErrors * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumExternalErrors * This,
            /* [out] */ IVsEnumExternalErrors **ppErrors);
        
        END_INTERFACE
    } IVsEnumExternalErrorsVtbl;

    interface IVsEnumExternalErrors
    {
        CONST_VTBL struct IVsEnumExternalErrorsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumExternalErrors_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumExternalErrors_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumExternalErrors_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumExternalErrors_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IVsEnumExternalErrors_Skip(This,celts)	\
    (This)->lpVtbl -> Skip(This,celts)

#define IVsEnumExternalErrors_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumExternalErrors_Clone(This,ppErrors)	\
    (This)->lpVtbl -> Clone(This,ppErrors)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumExternalErrors_Next_Proxy( 
    IVsEnumExternalErrors * This,
    /* [in] */ ULONG celt,
    /* [out][in] */ ExternalError *rgelt,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsEnumExternalErrors_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumExternalErrors_Skip_Proxy( 
    IVsEnumExternalErrors * This,
    /* [in] */ ULONG celts);


void __RPC_STUB IVsEnumExternalErrors_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumExternalErrors_Reset_Proxy( 
    IVsEnumExternalErrors * This);


void __RPC_STUB IVsEnumExternalErrors_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumExternalErrors_Clone_Proxy( 
    IVsEnumExternalErrors * This,
    /* [out] */ IVsEnumExternalErrors **ppErrors);


void __RPC_STUB IVsEnumExternalErrors_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumExternalErrors_INTERFACE_DEFINED__ */

#endif /* __SingleFileEditor_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


