

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for textmgr2.idl:
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

#ifndef __textmgr2_h__
#define __textmgr2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __VsExpansionManager_FWD_DEFINED__
#define __VsExpansionManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class VsExpansionManager VsExpansionManager;
#else
typedef struct VsExpansionManager VsExpansionManager;
#endif /* __cplusplus */

#endif 	/* __VsExpansionManager_FWD_DEFINED__ */


#ifndef __VsExpansionPackage_FWD_DEFINED__
#define __VsExpansionPackage_FWD_DEFINED__

#ifdef __cplusplus
typedef class VsExpansionPackage VsExpansionPackage;
#else
typedef struct VsExpansionPackage VsExpansionPackage;
#endif /* __cplusplus */

#endif 	/* __VsExpansionPackage_FWD_DEFINED__ */


#ifndef __IVsBufferExtraFiles_FWD_DEFINED__
#define __IVsBufferExtraFiles_FWD_DEFINED__
typedef interface IVsBufferExtraFiles IVsBufferExtraFiles;
#endif 	/* __IVsBufferExtraFiles_FWD_DEFINED__ */


#ifndef __IVsTextManager2_FWD_DEFINED__
#define __IVsTextManager2_FWD_DEFINED__
typedef interface IVsTextManager2 IVsTextManager2;
#endif 	/* __IVsTextManager2_FWD_DEFINED__ */


#ifndef __IVsInsertionUI_FWD_DEFINED__
#define __IVsInsertionUI_FWD_DEFINED__
typedef interface IVsInsertionUI IVsInsertionUI;
#endif 	/* __IVsInsertionUI_FWD_DEFINED__ */


#ifndef __IVsTextViewEx_FWD_DEFINED__
#define __IVsTextViewEx_FWD_DEFINED__
typedef interface IVsTextViewEx IVsTextViewEx;
#endif 	/* __IVsTextViewEx_FWD_DEFINED__ */


#ifndef __IVsCodeWindowEx_FWD_DEFINED__
#define __IVsCodeWindowEx_FWD_DEFINED__
typedef interface IVsCodeWindowEx IVsCodeWindowEx;
#endif 	/* __IVsCodeWindowEx_FWD_DEFINED__ */


#ifndef __IVsTextManagerEvents2_FWD_DEFINED__
#define __IVsTextManagerEvents2_FWD_DEFINED__
typedef interface IVsTextManagerEvents2 IVsTextManagerEvents2;
#endif 	/* __IVsTextManagerEvents2_FWD_DEFINED__ */


#ifndef __IVsFileExtensionMappingEvents_FWD_DEFINED__
#define __IVsFileExtensionMappingEvents_FWD_DEFINED__
typedef interface IVsFileExtensionMappingEvents IVsFileExtensionMappingEvents;
#endif 	/* __IVsFileExtensionMappingEvents_FWD_DEFINED__ */


#ifndef __IVsAutoOutliningClient_FWD_DEFINED__
#define __IVsAutoOutliningClient_FWD_DEFINED__
typedef interface IVsAutoOutliningClient IVsAutoOutliningClient;
#endif 	/* __IVsAutoOutliningClient_FWD_DEFINED__ */


#ifndef __IVsTextLineMarkerEx_FWD_DEFINED__
#define __IVsTextLineMarkerEx_FWD_DEFINED__
typedef interface IVsTextLineMarkerEx IVsTextLineMarkerEx;
#endif 	/* __IVsTextLineMarkerEx_FWD_DEFINED__ */


#ifndef __IVsTextMarkerClientAdvanced_FWD_DEFINED__
#define __IVsTextMarkerClientAdvanced_FWD_DEFINED__
typedef interface IVsTextMarkerClientAdvanced IVsTextMarkerClientAdvanced;
#endif 	/* __IVsTextMarkerClientAdvanced_FWD_DEFINED__ */


#ifndef __IVsTextMarkerClientEx_FWD_DEFINED__
#define __IVsTextMarkerClientEx_FWD_DEFINED__
typedef interface IVsTextMarkerClientEx IVsTextMarkerClientEx;
#endif 	/* __IVsTextMarkerClientEx_FWD_DEFINED__ */


#ifndef __IVsDropdownBarClientEx_FWD_DEFINED__
#define __IVsDropdownBarClientEx_FWD_DEFINED__
typedef interface IVsDropdownBarClientEx IVsDropdownBarClientEx;
#endif 	/* __IVsDropdownBarClientEx_FWD_DEFINED__ */


#ifndef __IVsHiddenRegionEx_FWD_DEFINED__
#define __IVsHiddenRegionEx_FWD_DEFINED__
typedef interface IVsHiddenRegionEx IVsHiddenRegionEx;
#endif 	/* __IVsHiddenRegionEx_FWD_DEFINED__ */


#ifndef __IVsHiddenTextClientEx_FWD_DEFINED__
#define __IVsHiddenTextClientEx_FWD_DEFINED__
typedef interface IVsHiddenTextClientEx IVsHiddenTextClientEx;
#endif 	/* __IVsHiddenTextClientEx_FWD_DEFINED__ */


#ifndef __IVsHiddenTextSessionEx_FWD_DEFINED__
#define __IVsHiddenTextSessionEx_FWD_DEFINED__
typedef interface IVsHiddenTextSessionEx IVsHiddenTextSessionEx;
#endif 	/* __IVsHiddenTextSessionEx_FWD_DEFINED__ */


#ifndef __IVsAtomicTextProvider_FWD_DEFINED__
#define __IVsAtomicTextProvider_FWD_DEFINED__
typedef interface IVsAtomicTextProvider IVsAtomicTextProvider;
#endif 	/* __IVsAtomicTextProvider_FWD_DEFINED__ */


#ifndef __IVsCompletionSetEx_FWD_DEFINED__
#define __IVsCompletionSetEx_FWD_DEFINED__
typedef interface IVsCompletionSetEx IVsCompletionSetEx;
#endif 	/* __IVsCompletionSetEx_FWD_DEFINED__ */


#ifndef __IVsCompletionSetBuilder_FWD_DEFINED__
#define __IVsCompletionSetBuilder_FWD_DEFINED__
typedef interface IVsCompletionSetBuilder IVsCompletionSetBuilder;
#endif 	/* __IVsCompletionSetBuilder_FWD_DEFINED__ */


#ifndef __IVsSmartTagData_FWD_DEFINED__
#define __IVsSmartTagData_FWD_DEFINED__
typedef interface IVsSmartTagData IVsSmartTagData;
#endif 	/* __IVsSmartTagData_FWD_DEFINED__ */


#ifndef __IVsSmartTagTipWindow_FWD_DEFINED__
#define __IVsSmartTagTipWindow_FWD_DEFINED__
typedef interface IVsSmartTagTipWindow IVsSmartTagTipWindow;
#endif 	/* __IVsSmartTagTipWindow_FWD_DEFINED__ */


#ifndef __VsSmartTagTipWindow_FWD_DEFINED__
#define __VsSmartTagTipWindow_FWD_DEFINED__

#ifdef __cplusplus
typedef class VsSmartTagTipWindow VsSmartTagTipWindow;
#else
typedef struct VsSmartTagTipWindow VsSmartTagTipWindow;
#endif /* __cplusplus */

#endif 	/* __VsSmartTagTipWindow_FWD_DEFINED__ */


#ifndef __IVsMethodDataEx_FWD_DEFINED__
#define __IVsMethodDataEx_FWD_DEFINED__
typedef interface IVsMethodDataEx IVsMethodDataEx;
#endif 	/* __IVsMethodDataEx_FWD_DEFINED__ */


#ifndef __IVsLanguageClipboardOpsEx_FWD_DEFINED__
#define __IVsLanguageClipboardOpsEx_FWD_DEFINED__
typedef interface IVsLanguageClipboardOpsEx IVsLanguageClipboardOpsEx;
#endif 	/* __IVsLanguageClipboardOpsEx_FWD_DEFINED__ */


#ifndef __IVsLanguageDragDropOps_FWD_DEFINED__
#define __IVsLanguageDragDropOps_FWD_DEFINED__
typedef interface IVsLanguageDragDropOps IVsLanguageDragDropOps;
#endif 	/* __IVsLanguageDragDropOps_FWD_DEFINED__ */


#ifndef __IVsLanguageDebugInfo2_FWD_DEFINED__
#define __IVsLanguageDebugInfo2_FWD_DEFINED__
typedef interface IVsLanguageDebugInfo2 IVsLanguageDebugInfo2;
#endif 	/* __IVsLanguageDebugInfo2_FWD_DEFINED__ */


#ifndef __IVsExpansionFunction_FWD_DEFINED__
#define __IVsExpansionFunction_FWD_DEFINED__
typedef interface IVsExpansionFunction IVsExpansionFunction;
#endif 	/* __IVsExpansionFunction_FWD_DEFINED__ */


#ifndef __IVsExpansionClient_FWD_DEFINED__
#define __IVsExpansionClient_FWD_DEFINED__
typedef interface IVsExpansionClient IVsExpansionClient;
#endif 	/* __IVsExpansionClient_FWD_DEFINED__ */


#ifndef __IVsExpansionEnumeration_FWD_DEFINED__
#define __IVsExpansionEnumeration_FWD_DEFINED__
typedef interface IVsExpansionEnumeration IVsExpansionEnumeration;
#endif 	/* __IVsExpansionEnumeration_FWD_DEFINED__ */


#ifndef __IVsExpansionManager_FWD_DEFINED__
#define __IVsExpansionManager_FWD_DEFINED__
typedef interface IVsExpansionManager IVsExpansionManager;
#endif 	/* __IVsExpansionManager_FWD_DEFINED__ */


#ifndef __IVsExpansion_FWD_DEFINED__
#define __IVsExpansion_FWD_DEFINED__
typedef interface IVsExpansion IVsExpansion;
#endif 	/* __IVsExpansion_FWD_DEFINED__ */


#ifndef __IVsExpansionSession_FWD_DEFINED__
#define __IVsExpansionSession_FWD_DEFINED__
typedef interface IVsExpansionSession IVsExpansionSession;
#endif 	/* __IVsExpansionSession_FWD_DEFINED__ */


#ifndef __IVsMethodTipWindow2_FWD_DEFINED__
#define __IVsMethodTipWindow2_FWD_DEFINED__
typedef interface IVsMethodTipWindow2 IVsMethodTipWindow2;
#endif 	/* __IVsMethodTipWindow2_FWD_DEFINED__ */


#ifndef __IVsIntellisenseOptions_FWD_DEFINED__
#define __IVsIntellisenseOptions_FWD_DEFINED__
typedef interface IVsIntellisenseOptions IVsIntellisenseOptions;
#endif 	/* __IVsIntellisenseOptions_FWD_DEFINED__ */


#ifndef __IVsColorizer2_FWD_DEFINED__
#define __IVsColorizer2_FWD_DEFINED__
typedef interface IVsColorizer2 IVsColorizer2;
#endif 	/* __IVsColorizer2_FWD_DEFINED__ */


#ifndef __IVsExpansionEvents_FWD_DEFINED__
#define __IVsExpansionEvents_FWD_DEFINED__
typedef interface IVsExpansionEvents IVsExpansionEvents;
#endif 	/* __IVsExpansionEvents_FWD_DEFINED__ */


#ifndef __IVsLanguageLineIndent_FWD_DEFINED__
#define __IVsLanguageLineIndent_FWD_DEFINED__
typedef interface IVsLanguageLineIndent IVsLanguageLineIndent;
#endif 	/* __IVsLanguageLineIndent_FWD_DEFINED__ */


#ifndef __IVsQueryUndoUnit_FWD_DEFINED__
#define __IVsQueryUndoUnit_FWD_DEFINED__
typedef interface IVsQueryUndoUnit IVsQueryUndoUnit;
#endif 	/* __IVsQueryUndoUnit_FWD_DEFINED__ */


#ifndef __IVsQueryUndoManager_FWD_DEFINED__
#define __IVsQueryUndoManager_FWD_DEFINED__
typedef interface IVsQueryUndoManager IVsQueryUndoManager;
#endif 	/* __IVsQueryUndoManager_FWD_DEFINED__ */


#ifndef __IPersistFileCheckSum_FWD_DEFINED__
#define __IPersistFileCheckSum_FWD_DEFINED__
typedef interface IPersistFileCheckSum IPersistFileCheckSum;
#endif 	/* __IPersistFileCheckSum_FWD_DEFINED__ */


#ifndef __IVsCodePageSelection_FWD_DEFINED__
#define __IVsCodePageSelection_FWD_DEFINED__
typedef interface IVsCodePageSelection IVsCodePageSelection;
#endif 	/* __IVsCodePageSelection_FWD_DEFINED__ */


#ifndef __IVsTextLines2_FWD_DEFINED__
#define __IVsTextLines2_FWD_DEFINED__
typedef interface IVsTextLines2 IVsTextLines2;
#endif 	/* __IVsTextLines2_FWD_DEFINED__ */


#ifndef __IVsTextLayer2_FWD_DEFINED__
#define __IVsTextLayer2_FWD_DEFINED__
typedef interface IVsTextLayer2 IVsTextLayer2;
#endif 	/* __IVsTextLayer2_FWD_DEFINED__ */


#ifndef __IVsTextImage2_FWD_DEFINED__
#define __IVsTextImage2_FWD_DEFINED__
typedef interface IVsTextImage2 IVsTextImage2;
#endif 	/* __IVsTextImage2_FWD_DEFINED__ */


#ifndef __IVsTextStorage2_FWD_DEFINED__
#define __IVsTextStorage2_FWD_DEFINED__
typedef interface IVsTextStorage2 IVsTextStorage2;
#endif 	/* __IVsTextStorage2_FWD_DEFINED__ */


#ifndef __IVsHiColorItem_FWD_DEFINED__
#define __IVsHiColorItem_FWD_DEFINED__
typedef interface IVsHiColorItem IVsHiColorItem;
#endif 	/* __IVsHiColorItem_FWD_DEFINED__ */


#ifndef __IVsTextBufferEx_FWD_DEFINED__
#define __IVsTextBufferEx_FWD_DEFINED__
typedef interface IVsTextBufferEx IVsTextBufferEx;
#endif 	/* __IVsTextBufferEx_FWD_DEFINED__ */


#ifndef __IVsReadOnlyViewNotification_FWD_DEFINED__
#define __IVsReadOnlyViewNotification_FWD_DEFINED__
typedef interface IVsReadOnlyViewNotification IVsReadOnlyViewNotification;
#endif 	/* __IVsReadOnlyViewNotification_FWD_DEFINED__ */


#ifndef __IVsOverrideTextViewAccessibilityState_FWD_DEFINED__
#define __IVsOverrideTextViewAccessibilityState_FWD_DEFINED__
typedef interface IVsOverrideTextViewAccessibilityState IVsOverrideTextViewAccessibilityState;
#endif 	/* __IVsOverrideTextViewAccessibilityState_FWD_DEFINED__ */


#ifndef __IVsCanCoordinatorClipTextSpan_FWD_DEFINED__
#define __IVsCanCoordinatorClipTextSpan_FWD_DEFINED__
typedef interface IVsCanCoordinatorClipTextSpan IVsCanCoordinatorClipTextSpan;
#endif 	/* __IVsCanCoordinatorClipTextSpan_FWD_DEFINED__ */


/* header files for imported files */
#include "IVsQueryEditQuerySave2.h"
#include "IVsQueryEditQuerySave80.h"
#include "msxml.h"
#include "context.h"
#include "textmgr.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_textmgr2_0000 */
/* [local] */ 

#pragma once
typedef long ViewCol;

typedef long CharIndex;

typedef __int64 TEXTADDR;


enum TipSuccesses2
    {	TIP_S_NODEFAULTTIP	= 4 << 16 | 0x5001
    } ;
typedef 
enum _LINESTYLE2
    {	LI_SMARTTAGFACT	= 5,
	LI_SMARTTAGFACTSIDE	= 6,
	LI_SMARTTAGEPHEM	= 7,
	LI_SMARTTAGEPHEMSIDE	= 8
    } 	LINESTYLE2;

typedef 
enum _markerbehaviorflags2
    {	MB_DONT_DELETE_IF_ZEROLEN	= 0x10,
	MB_INHERIT_FOREGROUND	= 0x20,
	MB_INHERIT_BACKGROUND	= 0x40,
	MB_VIEW_SPECIFIC	= 0x80
    } 	MARKERBEHAVIORFLAGS2;

typedef 
enum _GLDE_FLAGS2
    {	gldeUsePaintView	= 0x40
    } 	GLDE_FLAGS2;

typedef 
enum _MARKERVISUAL2
    {	MV_SMARTTAG	= 0x4000,
	MV_TRACK	= 0x8000,
	MV_ROUNDEDBORDER	= 0x10000,
	MV_BOLDTEXT	= 0x20000,
	MV_DISALLOWBGCHANGE	= 0x40000,
	MV_DISALLOWFGCHANGE	= 0x80000,
	MV_FORCE_CLOSEST_IF_HIDDEN	= 0x100000,
	MV_SELECT_WHOLE_LINE	= 0x200000
    } 	MARKERVISUAL2;

typedef 
enum _ChangeCommitGestureFlags2
    {	CCG_REFORMAT	= 0x100
    } 	ChangeCommitGestureFlags2;

typedef 
enum _LinkedTransactionFlags2
    {	mdtGlobal	= 0x2
    } 	LinkedTransactionFlags2;


enum TextBufferErrors2
    {	BUFFER_E_RELOAD_OCCURRED	= 0x80000000 | 4 << 16 | 0x1009
    } ;
typedef 
enum _TipWindowFlags2
    {	UTW_TIMER	= 0x8,
	UTW_EXPANDED	= 0x10
    } 	TipWindowFlags2;

typedef 
enum _MarkerCommandValues2
    {	mcvRightClickCommand	= 0x104
    } 	MarkerCommandValues2;





#define SID_SVsExpansionManager CLSID_VsExpansionManager
extern const __declspec(selectany) GUID GUID_VsBufferExtraFiles = { 0xfd494bf6, 0x1167, 0x4635, { 0xa2, 0xc, 0x5c, 0x24, 0xb2, 0xd7, 0xb3, 0x3d }};
extern const __declspec(selectany) GUID GUID_VsBufferFileReload = { 0x80d2b881, 0x81a3, 0x4f0b, { 0xbc, 0xf0, 0x70, 0xa0, 0x5, 0x4e, 0x67, 0x2f }};
extern const __declspec(selectany) GUID GUID_VsInitEncodingDialogFromUserData = { 0xc2382d84, 0x6650, 0x4386, { 0x86, 0xf, 0x24, 0x8e, 0xcb, 0x22, 0x2f, 0xc1 }};


extern RPC_IF_HANDLE __MIDL_itf_textmgr2_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_textmgr2_0000_v0_0_s_ifspec;


#ifndef __TextManagerInternal2_LIBRARY_DEFINED__
#define __TextManagerInternal2_LIBRARY_DEFINED__

/* library TextManagerInternal2 */
/* [version][uuid] */ 

typedef struct _LANGPREFERENCES2
    {
    CHAR szFileType[ 24 ];
    unsigned int fShowCompletion;
    unsigned int fShowSmartIndent;
    unsigned int fHideAdvancedAutoListMembers;
    unsigned int uTabSize;
    unsigned int uIndentSize;
    unsigned int fInsertTabs;
    vsIndentStyle IndentStyle;
    unsigned int fAutoListMembers;
    unsigned int fAutoListParams;
    unsigned int fVirtualSpace;
    unsigned int fWordWrap;
    unsigned int fTwoWayTreeview;
    unsigned int fHotURLs;
    unsigned int fDropdownBar;
    unsigned int fLineNumbers;
    GUID guidLang;
    unsigned int fWordWrapGlyphs;
    unsigned int fCutCopyBlanks;
    } 	LANGPREFERENCES2;

typedef struct _FRAMEPREFERENCES2
    {
    unsigned int fHorzScrollbar;
    unsigned int fVertScrollbar;
    } 	FRAMEPREFERENCES2;

typedef struct _VIEWPREFERENCES2
    {
    unsigned int fVisibleWhitespace;
    unsigned int fSelectionMargin;
    unsigned int fAutoDelimiterHighlight;
    unsigned int fGoToAnchorAfterEscape;
    unsigned int fDragDropEditing;
    unsigned int fUndoCaretMovements;
    unsigned int fOvertype;
    unsigned int fDragDropMove;
    unsigned int fWidgetMargin;
    unsigned int fReadOnly;
    unsigned int fActiveInModalState;
    unsigned int fClientDragDropFeedback;
    unsigned int fTrackChanges;
    unsigned int uCompletorSize;
    unsigned int fDetectUTF8;
    long lEditorEmulation;
    } 	VIEWPREFERENCES2;

typedef struct _FONTCOLORPREFERENCES2
    {
    /* [size_is] */ const GUID *pguidColorService;
    IUnknown *pColorTable;
    HFONT hRegularViewFont;
    HFONT hBoldViewFont;
    /* [size_is] */ const GUID *pguidFontCategory;
    /* [size_is] */ const GUID *pguidColorCategory;
    } 	FONTCOLORPREFERENCES2;

typedef 
enum _markertype2
    {	MARKER_WARNING	= 11,
	MARKER_SPAN_MAPPING	= MARKER_WARNING + 1,
	MARKER_REGION_COLLAPSED_NOGLYPH	= MARKER_SPAN_MAPPING + 1,
	MARKER_REGION_EXPANDED_NOGLYPH	= MARKER_REGION_COLLAPSED_NOGLYPH + 1,
	MARKER_EXSTENCIL	= MARKER_REGION_EXPANDED_NOGLYPH + 1,
	MARKER_EXSTENCIL_SELECTED	= MARKER_EXSTENCIL + 1,
	MARKER_SMARTTAG_NONVIS	= MARKER_EXSTENCIL_SELECTED + 1,
	MARKER_SMARTTAG_VIS	= MARKER_SMARTTAG_NONVIS + 1,
	MARKER_TRACK_NONSAVE	= MARKER_SMARTTAG_VIS + 1,
	MARKER_TRACK_SAVE	= MARKER_TRACK_NONSAVE + 1,
	MARKER_BOOKMARK_DISABLED	= MARKER_TRACK_SAVE + 1,
	MARKER_TRACK_PLACEHOLDER	= MARKER_BOOKMARK_DISABLED + 1,
	MARKER_SMARTTAG_FACTOID	= MARKER_TRACK_PLACEHOLDER + 1,
	MARKER_SMARTTAG_EPHEMERAL	= MARKER_SMARTTAG_FACTOID + 1,
	MARKER_BRACE_MATCHING	= MARKER_SMARTTAG_EPHEMERAL + 1,
	MARKER_EXSTENCIL_ENDMARKER	= MARKER_BRACE_MATCHING + 1,
	MARKER_CODEDEFWIN_BACKGROUND	= MARKER_EXSTENCIL_ENDMARKER + 1,
	MARKER_CODEDEFWIN_SELECTION	= MARKER_CODEDEFWIN_BACKGROUND + 1,
	MARKER_HIGHLIGHT_PATH	= MARKER_CODEDEFWIN_SELECTION + 1,
	MARKER_BRACE_MATCHING_BOLD	= MARKER_HIGHLIGHT_PATH + 1,
	MARKER_REFACTORING_BACKGROUND	= MARKER_BRACE_MATCHING_BOLD + 1,
	MARKER_EXSTENCIL_DEPFIELD	= MARKER_REFACTORING_BACKGROUND + 1,
	MARKER_REFACTORING_FIELD	= MARKER_EXSTENCIL_DEPFIELD + 1,
	MARKER_REFACTORING_DEPFIELD	= MARKER_REFACTORING_FIELD + 1,
	DEF_MARKER_COUNT_NEW	= MARKER_REFACTORING_DEPFIELD + 1
    } 	MARKERTYPE2;

typedef 
enum _hidden_region_behavior2
    {	hrbClientDrawn	= 0x2,
	hrbNoUserControls	= 0x4
    } 	HIDDEN_REGION_BEHAVIOR2;

typedef 
enum _VSTFF2
    {	VSTFF_NOUTF8_NOSIG	= 0x10000000,
	VSTFF_KEEPANSI	= 0x20000000
    } 	VSTFF2;


enum _VIEWFRAMETYPE
    {	vftAny	= 0,
	vftCodeWindow	= 0x1,
	vftToolWindow	= 0x2
    } ;
typedef DWORD VIEWFRAMETYPE;

typedef 
enum _TextViewInitFlags2
    {	VIF_READONLY	= 0x200,
	VIF_ACTIVEINMODALSTATE	= 0x400,
	VIF_SUPPRESS_STATUS_BAR_UPDATE	= 0x800,
	VIF_SUPPRESSTRACKCHANGES	= 0x1000,
	VIF_SUPPRESSBORDER	= 0x2000,
	VIF_SUPPRESSTRACKGOBACK	= 0x4000
    } 	TextViewInitFlags2;


enum _HighlightMatchingBraceFlags
    {	HMB_SUPPRESS_STATUS_BAR_UPDATE	= 0x1,
	HMB_USERECTANGLEBRACES	= 0x2
    } ;
typedef DWORD HIGHLIGHTMATCHINGBRACEFLAGS;


enum _codewindowbehaviorflags
    {	CWB_DEFAULT	= 0,
	CWB_DISABLEDROPDOWNBAR	= 0x1,
	CWB_DISABLESPLITTER	= 0x2
    } ;
typedef DWORD CODEWINDOWBEHAVIORFLAGS;

typedef struct _tag_NewHiddenRegionEx
    {
    long iType;
    DWORD dwBehavior;
    DWORD dwState;
    TextSpan tsHiddenText;
    LPCWSTR pszBanner;
    DWORD_PTR dwClient;
    DWORD dwLength;
    /* [size_is] */ ULONG *pBannerAttr;
    } 	NewHiddenRegionEx;

typedef 
enum _AtomicTextProviderFlags
    {	atpDefault	= 0,
	atpGlyph	= 0x1,
	atpTextAttributes	= 0x2
    } 	AtomicTextProviderFlags;

typedef struct _smarttagsizedata
    {
    SIZE size;
    } 	SMARTTAGSIZEDATA;

typedef 
enum _ST_IMAGEINDEX
    {	ST_DEFAULTIMAGE	= 0,
	ST_ERROR	= 1,
	ST_REFACTOR	= 2
    } 	ST_IMAGEINDEX;

typedef 
enum _commonlanguageblock
    {	CLB_TRY_BLOCK	= 0,
	CLB_EXCEPTION_BLOCK	= CLB_TRY_BLOCK + 1,
	CLB_FINAL_BLOCK	= CLB_EXCEPTION_BLOCK + 1
    } 	COMMONLANGUAGEBLOCK;


enum _ExpansionFunctionType
    {	eft_List	= 0,
	eft_Value	= eft_List + 1
    } ;
typedef DWORD ExpansionFunctionType;

typedef struct _VsExpansion
    {
    BSTR path;
    BSTR title;
    BSTR shortcut;
    BSTR description;
    } 	VsExpansion;


enum _ExpansionToken
    {	ET_MyDocs	= 1,
	ET_InstallRoot	= 2
    } ;
typedef DWORD ExpansionToken;

EXTERN_GUID(Vs_guidSourceHashMD5, 0x406ea660, 0x64cf, 0x4c82, 0xb6, 0xf0, 0x42, 0xd4, 0x81, 0x72, 0xa7, 0x99);
EXTERN_GUID(Vs_guidSourceHashSHA1, 0xff1816ec, 0xaa5e, 0x4d10, 0x87, 0xf7, 0x6f, 0x49, 0x63, 0x83, 0x34, 0x60);

enum __tagVSCOLORDATA
    {	CD_FOREGROUND	= 0,
	CD_BACKGROUND	= 1,
	CD_LINECOLOR	= 2
    } ;
typedef LONG VSCOLORDATA;


enum _EOLTYPE2
    {	eolUNI_NEL	= 7,
	MAX_EOLTYPES2	= eolUNI_NEL + 1
    } ;
typedef DWORD EOLTYPE2;


enum __VSEDITPROPID2
    {	VSEDITPROPID_ViewGeneral_AccessibilityStateOverride	= -0x12007
    } ;
typedef LONG VSEDITPROPID2;


EXTERN_C const IID LIBID_TextManagerInternal2;

EXTERN_C const CLSID CLSID_VsExpansionManager;

#ifdef __cplusplus

class DECLSPEC_UUID("4970C2BC-AF33-4a73-A34F-18B0584C40E4")
VsExpansionManager;
#endif

EXTERN_C const CLSID CLSID_VsExpansionPackage;

#ifdef __cplusplus

class DECLSPEC_UUID("0B680757-2C29-4531-80FA-535A5178AA98")
VsExpansionPackage;
#endif

#ifndef __IVsBufferExtraFiles_INTERFACE_DEFINED__
#define __IVsBufferExtraFiles_INTERFACE_DEFINED__

/* interface IVsBufferExtraFiles */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsBufferExtraFiles;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("66EE1DDE-6336-4a1e-9C99-D2864285ABA6")
    IVsBufferExtraFiles : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetQueryEditFilesDocuments( 
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [out] */ BSTR *bstrMkDocuments) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsBufferExtraFilesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsBufferExtraFiles * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsBufferExtraFiles * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsBufferExtraFiles * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetQueryEditFilesDocuments )( 
            IVsBufferExtraFiles * This,
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [out] */ BSTR *bstrMkDocuments);
        
        END_INTERFACE
    } IVsBufferExtraFilesVtbl;

    interface IVsBufferExtraFiles
    {
        CONST_VTBL struct IVsBufferExtraFilesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsBufferExtraFiles_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsBufferExtraFiles_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsBufferExtraFiles_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsBufferExtraFiles_GetQueryEditFilesDocuments(This,pBuffer,bstrMkDocuments)	\
    (This)->lpVtbl -> GetQueryEditFilesDocuments(This,pBuffer,bstrMkDocuments)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsBufferExtraFiles_GetQueryEditFilesDocuments_Proxy( 
    IVsBufferExtraFiles * This,
    /* [in] */ IVsTextBuffer *pBuffer,
    /* [out] */ BSTR *bstrMkDocuments);


void __RPC_STUB IVsBufferExtraFiles_GetQueryEditFilesDocuments_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsBufferExtraFiles_INTERFACE_DEFINED__ */


#ifndef __IVsTextManager2_INTERFACE_DEFINED__
#define __IVsTextManager2_INTERFACE_DEFINED__

/* interface IVsTextManager2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("072A28FD-1AF3-48af-9C85-C79404DBA30C")
    IVsTextManager2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBufferSccStatus3( 
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [string][in] */ LPCOLESTR pszFileName,
            /* [out] */ BOOL *pbCheckoutSucceeded,
            /* [out] */ int *piStatusFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AttemptToCheckOutBufferFromScc3( 
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [string][in] */ LPCOLESTR pszFileName,
            /* [in] */ DWORD dwQueryEditFlags,
            /* [out] */ BOOL *pbCheckoutSucceeded,
            /* [out] */ int *piStatusFlags) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetUserPreferences2( 
            /* [out] */ VIEWPREFERENCES2 *pViewPrefs,
            /* [out] */ FRAMEPREFERENCES2 *pFramePrefs,
            /* [out][in] */ LANGPREFERENCES2 *pLangPrefs,
            /* [out][in] */ FONTCOLORPREFERENCES2 *pColorPrefs) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE SetUserPreferences2( 
            /* [in] */ const VIEWPREFERENCES2 *pViewPrefs,
            /* [in] */ const FRAMEPREFERENCES2 *pFramePrefs,
            /* [in] */ const LANGPREFERENCES2 *pLangPrefs,
            /* [in] */ const FONTCOLORPREFERENCES2 *pColorPrefs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetColorableItems( 
            /* [in] */ GUID guidLang) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExpansionManager( 
            /* [out] */ IVsExpansionManager **pExpansionManager) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActiveView2( 
            /* [in] */ BOOL fMustHaveFocus,
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ VIEWFRAMETYPE grfIncludeViewFrameType,
            /* [out] */ IVsTextView **ppView) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NavigateToPosition2( 
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ REFGUID guidDocViewType,
            /* [in] */ long iPos,
            /* [in] */ long iLen,
            /* [in] */ VIEWFRAMETYPE grfIncludeViewFrameType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NavigateToLineAndColumn2( 
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ REFGUID guidDocViewType,
            /* [in] */ long iStartRow,
            /* [in] */ CharIndex iStartIndex,
            /* [in] */ long iEndRow,
            /* [in] */ CharIndex iEndIndex,
            /* [in] */ VIEWFRAMETYPE grfIncludeViewFrameType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FireReplaceAllInFilesBegin( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FireReplaceAllInFilesEnd( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextManager2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextManager2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextManager2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextManager2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBufferSccStatus3 )( 
            IVsTextManager2 * This,
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [string][in] */ LPCOLESTR pszFileName,
            /* [out] */ BOOL *pbCheckoutSucceeded,
            /* [out] */ int *piStatusFlags);
        
        HRESULT ( STDMETHODCALLTYPE *AttemptToCheckOutBufferFromScc3 )( 
            IVsTextManager2 * This,
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [string][in] */ LPCOLESTR pszFileName,
            /* [in] */ DWORD dwQueryEditFlags,
            /* [out] */ BOOL *pbCheckoutSucceeded,
            /* [out] */ int *piStatusFlags);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetUserPreferences2 )( 
            IVsTextManager2 * This,
            /* [out] */ VIEWPREFERENCES2 *pViewPrefs,
            /* [out] */ FRAMEPREFERENCES2 *pFramePrefs,
            /* [out][in] */ LANGPREFERENCES2 *pLangPrefs,
            /* [out][in] */ FONTCOLORPREFERENCES2 *pColorPrefs);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetUserPreferences2 )( 
            IVsTextManager2 * This,
            /* [in] */ const VIEWPREFERENCES2 *pViewPrefs,
            /* [in] */ const FRAMEPREFERENCES2 *pFramePrefs,
            /* [in] */ const LANGPREFERENCES2 *pLangPrefs,
            /* [in] */ const FONTCOLORPREFERENCES2 *pColorPrefs);
        
        HRESULT ( STDMETHODCALLTYPE *ResetColorableItems )( 
            IVsTextManager2 * This,
            /* [in] */ GUID guidLang);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpansionManager )( 
            IVsTextManager2 * This,
            /* [out] */ IVsExpansionManager **pExpansionManager);
        
        HRESULT ( STDMETHODCALLTYPE *GetActiveView2 )( 
            IVsTextManager2 * This,
            /* [in] */ BOOL fMustHaveFocus,
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ VIEWFRAMETYPE grfIncludeViewFrameType,
            /* [out] */ IVsTextView **ppView);
        
        HRESULT ( STDMETHODCALLTYPE *NavigateToPosition2 )( 
            IVsTextManager2 * This,
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ REFGUID guidDocViewType,
            /* [in] */ long iPos,
            /* [in] */ long iLen,
            /* [in] */ VIEWFRAMETYPE grfIncludeViewFrameType);
        
        HRESULT ( STDMETHODCALLTYPE *NavigateToLineAndColumn2 )( 
            IVsTextManager2 * This,
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ REFGUID guidDocViewType,
            /* [in] */ long iStartRow,
            /* [in] */ CharIndex iStartIndex,
            /* [in] */ long iEndRow,
            /* [in] */ CharIndex iEndIndex,
            /* [in] */ VIEWFRAMETYPE grfIncludeViewFrameType);
        
        HRESULT ( STDMETHODCALLTYPE *FireReplaceAllInFilesBegin )( 
            IVsTextManager2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *FireReplaceAllInFilesEnd )( 
            IVsTextManager2 * This);
        
        END_INTERFACE
    } IVsTextManager2Vtbl;

    interface IVsTextManager2
    {
        CONST_VTBL struct IVsTextManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextManager2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextManager2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextManager2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextManager2_GetBufferSccStatus3(This,pBuffer,pszFileName,pbCheckoutSucceeded,piStatusFlags)	\
    (This)->lpVtbl -> GetBufferSccStatus3(This,pBuffer,pszFileName,pbCheckoutSucceeded,piStatusFlags)

#define IVsTextManager2_AttemptToCheckOutBufferFromScc3(This,pBuffer,pszFileName,dwQueryEditFlags,pbCheckoutSucceeded,piStatusFlags)	\
    (This)->lpVtbl -> AttemptToCheckOutBufferFromScc3(This,pBuffer,pszFileName,dwQueryEditFlags,pbCheckoutSucceeded,piStatusFlags)

#define IVsTextManager2_GetUserPreferences2(This,pViewPrefs,pFramePrefs,pLangPrefs,pColorPrefs)	\
    (This)->lpVtbl -> GetUserPreferences2(This,pViewPrefs,pFramePrefs,pLangPrefs,pColorPrefs)

#define IVsTextManager2_SetUserPreferences2(This,pViewPrefs,pFramePrefs,pLangPrefs,pColorPrefs)	\
    (This)->lpVtbl -> SetUserPreferences2(This,pViewPrefs,pFramePrefs,pLangPrefs,pColorPrefs)

#define IVsTextManager2_ResetColorableItems(This,guidLang)	\
    (This)->lpVtbl -> ResetColorableItems(This,guidLang)

#define IVsTextManager2_GetExpansionManager(This,pExpansionManager)	\
    (This)->lpVtbl -> GetExpansionManager(This,pExpansionManager)

#define IVsTextManager2_GetActiveView2(This,fMustHaveFocus,pBuffer,grfIncludeViewFrameType,ppView)	\
    (This)->lpVtbl -> GetActiveView2(This,fMustHaveFocus,pBuffer,grfIncludeViewFrameType,ppView)

#define IVsTextManager2_NavigateToPosition2(This,pBuffer,guidDocViewType,iPos,iLen,grfIncludeViewFrameType)	\
    (This)->lpVtbl -> NavigateToPosition2(This,pBuffer,guidDocViewType,iPos,iLen,grfIncludeViewFrameType)

#define IVsTextManager2_NavigateToLineAndColumn2(This,pBuffer,guidDocViewType,iStartRow,iStartIndex,iEndRow,iEndIndex,grfIncludeViewFrameType)	\
    (This)->lpVtbl -> NavigateToLineAndColumn2(This,pBuffer,guidDocViewType,iStartRow,iStartIndex,iEndRow,iEndIndex,grfIncludeViewFrameType)

#define IVsTextManager2_FireReplaceAllInFilesBegin(This)	\
    (This)->lpVtbl -> FireReplaceAllInFilesBegin(This)

#define IVsTextManager2_FireReplaceAllInFilesEnd(This)	\
    (This)->lpVtbl -> FireReplaceAllInFilesEnd(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextManager2_GetBufferSccStatus3_Proxy( 
    IVsTextManager2 * This,
    /* [in] */ IVsTextBuffer *pBuffer,
    /* [string][in] */ LPCOLESTR pszFileName,
    /* [out] */ BOOL *pbCheckoutSucceeded,
    /* [out] */ int *piStatusFlags);


void __RPC_STUB IVsTextManager2_GetBufferSccStatus3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManager2_AttemptToCheckOutBufferFromScc3_Proxy( 
    IVsTextManager2 * This,
    /* [in] */ IVsTextBuffer *pBuffer,
    /* [string][in] */ LPCOLESTR pszFileName,
    /* [in] */ DWORD dwQueryEditFlags,
    /* [out] */ BOOL *pbCheckoutSucceeded,
    /* [out] */ int *piStatusFlags);


void __RPC_STUB IVsTextManager2_AttemptToCheckOutBufferFromScc3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local] */ HRESULT STDMETHODCALLTYPE IVsTextManager2_GetUserPreferences2_Proxy( 
    IVsTextManager2 * This,
    /* [out] */ VIEWPREFERENCES2 *pViewPrefs,
    /* [out] */ FRAMEPREFERENCES2 *pFramePrefs,
    /* [out][in] */ LANGPREFERENCES2 *pLangPrefs,
    /* [out][in] */ FONTCOLORPREFERENCES2 *pColorPrefs);


void __RPC_STUB IVsTextManager2_GetUserPreferences2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local] */ HRESULT STDMETHODCALLTYPE IVsTextManager2_SetUserPreferences2_Proxy( 
    IVsTextManager2 * This,
    /* [in] */ const VIEWPREFERENCES2 *pViewPrefs,
    /* [in] */ const FRAMEPREFERENCES2 *pFramePrefs,
    /* [in] */ const LANGPREFERENCES2 *pLangPrefs,
    /* [in] */ const FONTCOLORPREFERENCES2 *pColorPrefs);


void __RPC_STUB IVsTextManager2_SetUserPreferences2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManager2_ResetColorableItems_Proxy( 
    IVsTextManager2 * This,
    /* [in] */ GUID guidLang);


void __RPC_STUB IVsTextManager2_ResetColorableItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManager2_GetExpansionManager_Proxy( 
    IVsTextManager2 * This,
    /* [out] */ IVsExpansionManager **pExpansionManager);


void __RPC_STUB IVsTextManager2_GetExpansionManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManager2_GetActiveView2_Proxy( 
    IVsTextManager2 * This,
    /* [in] */ BOOL fMustHaveFocus,
    /* [in] */ IVsTextBuffer *pBuffer,
    /* [in] */ VIEWFRAMETYPE grfIncludeViewFrameType,
    /* [out] */ IVsTextView **ppView);


void __RPC_STUB IVsTextManager2_GetActiveView2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManager2_NavigateToPosition2_Proxy( 
    IVsTextManager2 * This,
    /* [in] */ IVsTextBuffer *pBuffer,
    /* [in] */ REFGUID guidDocViewType,
    /* [in] */ long iPos,
    /* [in] */ long iLen,
    /* [in] */ VIEWFRAMETYPE grfIncludeViewFrameType);


void __RPC_STUB IVsTextManager2_NavigateToPosition2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManager2_NavigateToLineAndColumn2_Proxy( 
    IVsTextManager2 * This,
    /* [in] */ IVsTextBuffer *pBuffer,
    /* [in] */ REFGUID guidDocViewType,
    /* [in] */ long iStartRow,
    /* [in] */ CharIndex iStartIndex,
    /* [in] */ long iEndRow,
    /* [in] */ CharIndex iEndIndex,
    /* [in] */ VIEWFRAMETYPE grfIncludeViewFrameType);


void __RPC_STUB IVsTextManager2_NavigateToLineAndColumn2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManager2_FireReplaceAllInFilesBegin_Proxy( 
    IVsTextManager2 * This);


void __RPC_STUB IVsTextManager2_FireReplaceAllInFilesBegin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManager2_FireReplaceAllInFilesEnd_Proxy( 
    IVsTextManager2 * This);


void __RPC_STUB IVsTextManager2_FireReplaceAllInFilesEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextManager2_INTERFACE_DEFINED__ */


#ifndef __IVsInsertionUI_INTERFACE_DEFINED__
#define __IVsInsertionUI_INTERFACE_DEFINED__

/* interface IVsInsertionUI */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsInsertionUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BB73A6E1-B824-42a1-9AB1-2F254386DFFC")
    IVsInsertionUI : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetWindowHandle( 
            /* [out] */ HWND *hwnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Hide( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsInsertionUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsInsertionUI * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsInsertionUI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsInsertionUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetWindowHandle )( 
            IVsInsertionUI * This,
            /* [out] */ HWND *hwnd);
        
        HRESULT ( STDMETHODCALLTYPE *Hide )( 
            IVsInsertionUI * This);
        
        END_INTERFACE
    } IVsInsertionUIVtbl;

    interface IVsInsertionUI
    {
        CONST_VTBL struct IVsInsertionUIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsInsertionUI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsInsertionUI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsInsertionUI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsInsertionUI_GetWindowHandle(This,hwnd)	\
    (This)->lpVtbl -> GetWindowHandle(This,hwnd)

#define IVsInsertionUI_Hide(This)	\
    (This)->lpVtbl -> Hide(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsInsertionUI_GetWindowHandle_Proxy( 
    IVsInsertionUI * This,
    /* [out] */ HWND *hwnd);


void __RPC_STUB IVsInsertionUI_GetWindowHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsInsertionUI_Hide_Proxy( 
    IVsInsertionUI * This);


void __RPC_STUB IVsInsertionUI_Hide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsInsertionUI_INTERFACE_DEFINED__ */


#ifndef __IVsTextViewEx_INTERFACE_DEFINED__
#define __IVsTextViewEx_INTERFACE_DEFINED__

/* interface IVsTextViewEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextViewEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EAF1EA5B-EB6D-4852-9D87-666E09BC4BEE")
    IVsTextViewEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetHoverWaitTimer( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PersistOutliningState( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateSmartTagWindow( 
            /* [in] */ IVsSmartTagTipWindow *pSmartTagWnd,
            /* [in] */ DWORD dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSmartTagRect( 
            /* [out] */ RECT *rcSmartTag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InvokeInsertionUI( 
            /* [in] */ IVsCompletionSet *pCompSet,
            /* [in] */ BSTR bstrPrefixText,
            /* [in] */ BSTR bstrCompletionChar,
            /* [out] */ IVsInsertionUI **pInsertionUI) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWindowFrame( 
            /* [out] */ IUnknown **ppFrame) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsCompletorWindowActive( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClusterRange( 
            /* [in] */ long iLine,
            /* [in] */ INT iDisplayCol,
            /* [out] */ INT *picCharacter,
            /* [out] */ INT *piStartCol,
            /* [out] */ INT *piEndCol) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIgnoreMarkerTypes( 
            /* [in] */ long iCountMarkerTypes,
            /* [in] */ DWORD *rgIgnoreMarkerTypes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AppendViewOnlyMarkerTypes( 
            /* [in] */ unsigned int iCountViewMarkerOnly,
            /* [in] */ const DWORD *rgViewMarkerOnly) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveViewOnlyMarkerTypes( 
            /* [in] */ unsigned int iCountViewMarkerOnly,
            /* [in] */ const DWORD *rgViewMarkerOnly) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBackgroundColorIndex( 
            /* [in] */ long iBackgroundIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsExpansionUIActive( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsReadOnly( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextViewExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextViewEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextViewEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextViewEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetHoverWaitTimer )( 
            IVsTextViewEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *PersistOutliningState )( 
            IVsTextViewEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateSmartTagWindow )( 
            IVsTextViewEx * This,
            /* [in] */ IVsSmartTagTipWindow *pSmartTagWnd,
            /* [in] */ DWORD dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetSmartTagRect )( 
            IVsTextViewEx * This,
            /* [out] */ RECT *rcSmartTag);
        
        HRESULT ( STDMETHODCALLTYPE *InvokeInsertionUI )( 
            IVsTextViewEx * This,
            /* [in] */ IVsCompletionSet *pCompSet,
            /* [in] */ BSTR bstrPrefixText,
            /* [in] */ BSTR bstrCompletionChar,
            /* [out] */ IVsInsertionUI **pInsertionUI);
        
        HRESULT ( STDMETHODCALLTYPE *GetWindowFrame )( 
            IVsTextViewEx * This,
            /* [out] */ IUnknown **ppFrame);
        
        HRESULT ( STDMETHODCALLTYPE *IsCompletorWindowActive )( 
            IVsTextViewEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClusterRange )( 
            IVsTextViewEx * This,
            /* [in] */ long iLine,
            /* [in] */ INT iDisplayCol,
            /* [out] */ INT *picCharacter,
            /* [out] */ INT *piStartCol,
            /* [out] */ INT *piEndCol);
        
        HRESULT ( STDMETHODCALLTYPE *SetIgnoreMarkerTypes )( 
            IVsTextViewEx * This,
            /* [in] */ long iCountMarkerTypes,
            /* [in] */ DWORD *rgIgnoreMarkerTypes);
        
        HRESULT ( STDMETHODCALLTYPE *AppendViewOnlyMarkerTypes )( 
            IVsTextViewEx * This,
            /* [in] */ unsigned int iCountViewMarkerOnly,
            /* [in] */ const DWORD *rgViewMarkerOnly);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveViewOnlyMarkerTypes )( 
            IVsTextViewEx * This,
            /* [in] */ unsigned int iCountViewMarkerOnly,
            /* [in] */ const DWORD *rgViewMarkerOnly);
        
        HRESULT ( STDMETHODCALLTYPE *SetBackgroundColorIndex )( 
            IVsTextViewEx * This,
            /* [in] */ long iBackgroundIndex);
        
        HRESULT ( STDMETHODCALLTYPE *IsExpansionUIActive )( 
            IVsTextViewEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsReadOnly )( 
            IVsTextViewEx * This);
        
        END_INTERFACE
    } IVsTextViewExVtbl;

    interface IVsTextViewEx
    {
        CONST_VTBL struct IVsTextViewExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextViewEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextViewEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextViewEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextViewEx_SetHoverWaitTimer(This)	\
    (This)->lpVtbl -> SetHoverWaitTimer(This)

#define IVsTextViewEx_PersistOutliningState(This)	\
    (This)->lpVtbl -> PersistOutliningState(This)

#define IVsTextViewEx_UpdateSmartTagWindow(This,pSmartTagWnd,dwFlags)	\
    (This)->lpVtbl -> UpdateSmartTagWindow(This,pSmartTagWnd,dwFlags)

#define IVsTextViewEx_GetSmartTagRect(This,rcSmartTag)	\
    (This)->lpVtbl -> GetSmartTagRect(This,rcSmartTag)

#define IVsTextViewEx_InvokeInsertionUI(This,pCompSet,bstrPrefixText,bstrCompletionChar,pInsertionUI)	\
    (This)->lpVtbl -> InvokeInsertionUI(This,pCompSet,bstrPrefixText,bstrCompletionChar,pInsertionUI)

#define IVsTextViewEx_GetWindowFrame(This,ppFrame)	\
    (This)->lpVtbl -> GetWindowFrame(This,ppFrame)

#define IVsTextViewEx_IsCompletorWindowActive(This)	\
    (This)->lpVtbl -> IsCompletorWindowActive(This)

#define IVsTextViewEx_GetClusterRange(This,iLine,iDisplayCol,picCharacter,piStartCol,piEndCol)	\
    (This)->lpVtbl -> GetClusterRange(This,iLine,iDisplayCol,picCharacter,piStartCol,piEndCol)

#define IVsTextViewEx_SetIgnoreMarkerTypes(This,iCountMarkerTypes,rgIgnoreMarkerTypes)	\
    (This)->lpVtbl -> SetIgnoreMarkerTypes(This,iCountMarkerTypes,rgIgnoreMarkerTypes)

#define IVsTextViewEx_AppendViewOnlyMarkerTypes(This,iCountViewMarkerOnly,rgViewMarkerOnly)	\
    (This)->lpVtbl -> AppendViewOnlyMarkerTypes(This,iCountViewMarkerOnly,rgViewMarkerOnly)

#define IVsTextViewEx_RemoveViewOnlyMarkerTypes(This,iCountViewMarkerOnly,rgViewMarkerOnly)	\
    (This)->lpVtbl -> RemoveViewOnlyMarkerTypes(This,iCountViewMarkerOnly,rgViewMarkerOnly)

#define IVsTextViewEx_SetBackgroundColorIndex(This,iBackgroundIndex)	\
    (This)->lpVtbl -> SetBackgroundColorIndex(This,iBackgroundIndex)

#define IVsTextViewEx_IsExpansionUIActive(This)	\
    (This)->lpVtbl -> IsExpansionUIActive(This)

#define IVsTextViewEx_IsReadOnly(This)	\
    (This)->lpVtbl -> IsReadOnly(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextViewEx_SetHoverWaitTimer_Proxy( 
    IVsTextViewEx * This);


void __RPC_STUB IVsTextViewEx_SetHoverWaitTimer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_PersistOutliningState_Proxy( 
    IVsTextViewEx * This);


void __RPC_STUB IVsTextViewEx_PersistOutliningState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_UpdateSmartTagWindow_Proxy( 
    IVsTextViewEx * This,
    /* [in] */ IVsSmartTagTipWindow *pSmartTagWnd,
    /* [in] */ DWORD dwFlags);


void __RPC_STUB IVsTextViewEx_UpdateSmartTagWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_GetSmartTagRect_Proxy( 
    IVsTextViewEx * This,
    /* [out] */ RECT *rcSmartTag);


void __RPC_STUB IVsTextViewEx_GetSmartTagRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_InvokeInsertionUI_Proxy( 
    IVsTextViewEx * This,
    /* [in] */ IVsCompletionSet *pCompSet,
    /* [in] */ BSTR bstrPrefixText,
    /* [in] */ BSTR bstrCompletionChar,
    /* [out] */ IVsInsertionUI **pInsertionUI);


void __RPC_STUB IVsTextViewEx_InvokeInsertionUI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_GetWindowFrame_Proxy( 
    IVsTextViewEx * This,
    /* [out] */ IUnknown **ppFrame);


void __RPC_STUB IVsTextViewEx_GetWindowFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_IsCompletorWindowActive_Proxy( 
    IVsTextViewEx * This);


void __RPC_STUB IVsTextViewEx_IsCompletorWindowActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_GetClusterRange_Proxy( 
    IVsTextViewEx * This,
    /* [in] */ long iLine,
    /* [in] */ INT iDisplayCol,
    /* [out] */ INT *picCharacter,
    /* [out] */ INT *piStartCol,
    /* [out] */ INT *piEndCol);


void __RPC_STUB IVsTextViewEx_GetClusterRange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_SetIgnoreMarkerTypes_Proxy( 
    IVsTextViewEx * This,
    /* [in] */ long iCountMarkerTypes,
    /* [in] */ DWORD *rgIgnoreMarkerTypes);


void __RPC_STUB IVsTextViewEx_SetIgnoreMarkerTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_AppendViewOnlyMarkerTypes_Proxy( 
    IVsTextViewEx * This,
    /* [in] */ unsigned int iCountViewMarkerOnly,
    /* [in] */ const DWORD *rgViewMarkerOnly);


void __RPC_STUB IVsTextViewEx_AppendViewOnlyMarkerTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_RemoveViewOnlyMarkerTypes_Proxy( 
    IVsTextViewEx * This,
    /* [in] */ unsigned int iCountViewMarkerOnly,
    /* [in] */ const DWORD *rgViewMarkerOnly);


void __RPC_STUB IVsTextViewEx_RemoveViewOnlyMarkerTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_SetBackgroundColorIndex_Proxy( 
    IVsTextViewEx * This,
    /* [in] */ long iBackgroundIndex);


void __RPC_STUB IVsTextViewEx_SetBackgroundColorIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_IsExpansionUIActive_Proxy( 
    IVsTextViewEx * This);


void __RPC_STUB IVsTextViewEx_IsExpansionUIActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextViewEx_IsReadOnly_Proxy( 
    IVsTextViewEx * This);


void __RPC_STUB IVsTextViewEx_IsReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextViewEx_INTERFACE_DEFINED__ */


#ifndef __IVsCodeWindowEx_INTERFACE_DEFINED__
#define __IVsCodeWindowEx_INTERFACE_DEFINED__

/* interface IVsCodeWindowEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsCodeWindowEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("186F17A5-7270-4bc5-A8DE-72F4A0E49647")
    IVsCodeWindowEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ CODEWINDOWBEHAVIORFLAGS grfCodeWindowBehaviorFlags,
            /* [in] */ VSUSERCONTEXTATTRIBUTEUSAGE usageAuxUserContext,
            /* [in] */ LPCOLESTR szNameAuxUserContext,
            /* [in] */ LPCOLESTR szValueAuxUserContext,
            /* [in] */ DWORD InitViewFlags,
            /* [in] */ const INITVIEW *pInitView) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsReadOnly( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCodeWindowExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCodeWindowEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCodeWindowEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCodeWindowEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IVsCodeWindowEx * This,
            /* [in] */ CODEWINDOWBEHAVIORFLAGS grfCodeWindowBehaviorFlags,
            /* [in] */ VSUSERCONTEXTATTRIBUTEUSAGE usageAuxUserContext,
            /* [in] */ LPCOLESTR szNameAuxUserContext,
            /* [in] */ LPCOLESTR szValueAuxUserContext,
            /* [in] */ DWORD InitViewFlags,
            /* [in] */ const INITVIEW *pInitView);
        
        HRESULT ( STDMETHODCALLTYPE *IsReadOnly )( 
            IVsCodeWindowEx * This);
        
        END_INTERFACE
    } IVsCodeWindowExVtbl;

    interface IVsCodeWindowEx
    {
        CONST_VTBL struct IVsCodeWindowExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCodeWindowEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCodeWindowEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCodeWindowEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCodeWindowEx_Initialize(This,grfCodeWindowBehaviorFlags,usageAuxUserContext,szNameAuxUserContext,szValueAuxUserContext,InitViewFlags,pInitView)	\
    (This)->lpVtbl -> Initialize(This,grfCodeWindowBehaviorFlags,usageAuxUserContext,szNameAuxUserContext,szValueAuxUserContext,InitViewFlags,pInitView)

#define IVsCodeWindowEx_IsReadOnly(This)	\
    (This)->lpVtbl -> IsReadOnly(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCodeWindowEx_Initialize_Proxy( 
    IVsCodeWindowEx * This,
    /* [in] */ CODEWINDOWBEHAVIORFLAGS grfCodeWindowBehaviorFlags,
    /* [in] */ VSUSERCONTEXTATTRIBUTEUSAGE usageAuxUserContext,
    /* [in] */ LPCOLESTR szNameAuxUserContext,
    /* [in] */ LPCOLESTR szValueAuxUserContext,
    /* [in] */ DWORD InitViewFlags,
    /* [in] */ const INITVIEW *pInitView);


void __RPC_STUB IVsCodeWindowEx_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCodeWindowEx_IsReadOnly_Proxy( 
    IVsCodeWindowEx * This);


void __RPC_STUB IVsCodeWindowEx_IsReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCodeWindowEx_INTERFACE_DEFINED__ */


#ifndef __IVsTextManagerEvents2_INTERFACE_DEFINED__
#define __IVsTextManagerEvents2_INTERFACE_DEFINED__

/* interface IVsTextManagerEvents2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextManagerEvents2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4697E418-183E-414e-9173-E5FBF27692A9")
    IVsTextManagerEvents2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnRegisterMarkerType( 
            /* [in] */ long iMarkerType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRegisterView( 
            /* [in] */ IVsTextView *pView) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnUnregisterView( 
            /* [in] */ IVsTextView *pView) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE OnUserPreferencesChanged2( 
            /* [in] */ const VIEWPREFERENCES2 *pViewPrefs,
            /* [in] */ const FRAMEPREFERENCES2 *pFramePrefs,
            /* [in] */ const LANGPREFERENCES2 *pLangPrefs,
            /* [in] */ const FONTCOLORPREFERENCES2 *pColorPrefs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnReplaceAllInFilesBegin( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnReplaceAllInFilesEnd( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextManagerEvents2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextManagerEvents2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextManagerEvents2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextManagerEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnRegisterMarkerType )( 
            IVsTextManagerEvents2 * This,
            /* [in] */ long iMarkerType);
        
        HRESULT ( STDMETHODCALLTYPE *OnRegisterView )( 
            IVsTextManagerEvents2 * This,
            /* [in] */ IVsTextView *pView);
        
        HRESULT ( STDMETHODCALLTYPE *OnUnregisterView )( 
            IVsTextManagerEvents2 * This,
            /* [in] */ IVsTextView *pView);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *OnUserPreferencesChanged2 )( 
            IVsTextManagerEvents2 * This,
            /* [in] */ const VIEWPREFERENCES2 *pViewPrefs,
            /* [in] */ const FRAMEPREFERENCES2 *pFramePrefs,
            /* [in] */ const LANGPREFERENCES2 *pLangPrefs,
            /* [in] */ const FONTCOLORPREFERENCES2 *pColorPrefs);
        
        HRESULT ( STDMETHODCALLTYPE *OnReplaceAllInFilesBegin )( 
            IVsTextManagerEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnReplaceAllInFilesEnd )( 
            IVsTextManagerEvents2 * This);
        
        END_INTERFACE
    } IVsTextManagerEvents2Vtbl;

    interface IVsTextManagerEvents2
    {
        CONST_VTBL struct IVsTextManagerEvents2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextManagerEvents2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextManagerEvents2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextManagerEvents2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextManagerEvents2_OnRegisterMarkerType(This,iMarkerType)	\
    (This)->lpVtbl -> OnRegisterMarkerType(This,iMarkerType)

#define IVsTextManagerEvents2_OnRegisterView(This,pView)	\
    (This)->lpVtbl -> OnRegisterView(This,pView)

#define IVsTextManagerEvents2_OnUnregisterView(This,pView)	\
    (This)->lpVtbl -> OnUnregisterView(This,pView)

#define IVsTextManagerEvents2_OnUserPreferencesChanged2(This,pViewPrefs,pFramePrefs,pLangPrefs,pColorPrefs)	\
    (This)->lpVtbl -> OnUserPreferencesChanged2(This,pViewPrefs,pFramePrefs,pLangPrefs,pColorPrefs)

#define IVsTextManagerEvents2_OnReplaceAllInFilesBegin(This)	\
    (This)->lpVtbl -> OnReplaceAllInFilesBegin(This)

#define IVsTextManagerEvents2_OnReplaceAllInFilesEnd(This)	\
    (This)->lpVtbl -> OnReplaceAllInFilesEnd(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextManagerEvents2_OnRegisterMarkerType_Proxy( 
    IVsTextManagerEvents2 * This,
    /* [in] */ long iMarkerType);


void __RPC_STUB IVsTextManagerEvents2_OnRegisterMarkerType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManagerEvents2_OnRegisterView_Proxy( 
    IVsTextManagerEvents2 * This,
    /* [in] */ IVsTextView *pView);


void __RPC_STUB IVsTextManagerEvents2_OnRegisterView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManagerEvents2_OnUnregisterView_Proxy( 
    IVsTextManagerEvents2 * This,
    /* [in] */ IVsTextView *pView);


void __RPC_STUB IVsTextManagerEvents2_OnUnregisterView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local] */ HRESULT STDMETHODCALLTYPE IVsTextManagerEvents2_OnUserPreferencesChanged2_Proxy( 
    IVsTextManagerEvents2 * This,
    /* [in] */ const VIEWPREFERENCES2 *pViewPrefs,
    /* [in] */ const FRAMEPREFERENCES2 *pFramePrefs,
    /* [in] */ const LANGPREFERENCES2 *pLangPrefs,
    /* [in] */ const FONTCOLORPREFERENCES2 *pColorPrefs);


void __RPC_STUB IVsTextManagerEvents2_OnUserPreferencesChanged2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManagerEvents2_OnReplaceAllInFilesBegin_Proxy( 
    IVsTextManagerEvents2 * This);


void __RPC_STUB IVsTextManagerEvents2_OnReplaceAllInFilesBegin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextManagerEvents2_OnReplaceAllInFilesEnd_Proxy( 
    IVsTextManagerEvents2 * This);


void __RPC_STUB IVsTextManagerEvents2_OnReplaceAllInFilesEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextManagerEvents2_INTERFACE_DEFINED__ */


#ifndef __IVsFileExtensionMappingEvents_INTERFACE_DEFINED__
#define __IVsFileExtensionMappingEvents_INTERFACE_DEFINED__

/* interface IVsFileExtensionMappingEvents */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsFileExtensionMappingEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D1ABEDEB-5163-4235-ADE6-17EFAA3A5549")
    IVsFileExtensionMappingEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnFileExtensionsReset( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsFileExtensionMappingEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsFileExtensionMappingEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsFileExtensionMappingEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsFileExtensionMappingEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileExtensionsReset )( 
            IVsFileExtensionMappingEvents * This);
        
        END_INTERFACE
    } IVsFileExtensionMappingEventsVtbl;

    interface IVsFileExtensionMappingEvents
    {
        CONST_VTBL struct IVsFileExtensionMappingEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsFileExtensionMappingEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsFileExtensionMappingEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsFileExtensionMappingEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsFileExtensionMappingEvents_OnFileExtensionsReset(This)	\
    (This)->lpVtbl -> OnFileExtensionsReset(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsFileExtensionMappingEvents_OnFileExtensionsReset_Proxy( 
    IVsFileExtensionMappingEvents * This);


void __RPC_STUB IVsFileExtensionMappingEvents_OnFileExtensionsReset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsFileExtensionMappingEvents_INTERFACE_DEFINED__ */


#ifndef __IVsAutoOutliningClient_INTERFACE_DEFINED__
#define __IVsAutoOutliningClient_INTERFACE_DEFINED__

/* interface IVsAutoOutliningClient */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsAutoOutliningClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5151882E-58E1-4856-BFE8-4F17A30BE839")
    IVsAutoOutliningClient : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryWaitForAutoOutliningCallback( 
            /* [out] */ BOOL *fWait) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsAutoOutliningClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsAutoOutliningClient * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsAutoOutliningClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsAutoOutliningClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryWaitForAutoOutliningCallback )( 
            IVsAutoOutliningClient * This,
            /* [out] */ BOOL *fWait);
        
        END_INTERFACE
    } IVsAutoOutliningClientVtbl;

    interface IVsAutoOutliningClient
    {
        CONST_VTBL struct IVsAutoOutliningClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsAutoOutliningClient_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsAutoOutliningClient_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsAutoOutliningClient_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsAutoOutliningClient_QueryWaitForAutoOutliningCallback(This,fWait)	\
    (This)->lpVtbl -> QueryWaitForAutoOutliningCallback(This,fWait)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsAutoOutliningClient_QueryWaitForAutoOutliningCallback_Proxy( 
    IVsAutoOutliningClient * This,
    /* [out] */ BOOL *fWait);


void __RPC_STUB IVsAutoOutliningClient_QueryWaitForAutoOutliningCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsAutoOutliningClient_INTERFACE_DEFINED__ */


#ifndef __IVsTextLineMarkerEx_INTERFACE_DEFINED__
#define __IVsTextLineMarkerEx_INTERFACE_DEFINED__

/* interface IVsTextLineMarkerEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextLineMarkerEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C31EE6E-FC66-4fc8-8CC5-6A4134369F4E")
    IVsTextLineMarkerEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetClientData( 
            /* [out] */ DWORD_PTR *pdwData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetClientData( 
            /* [in] */ DWORD_PTR dwData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextLineMarkerExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextLineMarkerEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextLineMarkerEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextLineMarkerEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClientData )( 
            IVsTextLineMarkerEx * This,
            /* [out] */ DWORD_PTR *pdwData);
        
        HRESULT ( STDMETHODCALLTYPE *SetClientData )( 
            IVsTextLineMarkerEx * This,
            /* [in] */ DWORD_PTR dwData);
        
        END_INTERFACE
    } IVsTextLineMarkerExVtbl;

    interface IVsTextLineMarkerEx
    {
        CONST_VTBL struct IVsTextLineMarkerExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextLineMarkerEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextLineMarkerEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextLineMarkerEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextLineMarkerEx_GetClientData(This,pdwData)	\
    (This)->lpVtbl -> GetClientData(This,pdwData)

#define IVsTextLineMarkerEx_SetClientData(This,dwData)	\
    (This)->lpVtbl -> SetClientData(This,dwData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextLineMarkerEx_GetClientData_Proxy( 
    IVsTextLineMarkerEx * This,
    /* [out] */ DWORD_PTR *pdwData);


void __RPC_STUB IVsTextLineMarkerEx_GetClientData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextLineMarkerEx_SetClientData_Proxy( 
    IVsTextLineMarkerEx * This,
    /* [in] */ DWORD_PTR dwData);


void __RPC_STUB IVsTextLineMarkerEx_SetClientData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextLineMarkerEx_INTERFACE_DEFINED__ */


#ifndef __IVsTextMarkerClientAdvanced_INTERFACE_DEFINED__
#define __IVsTextMarkerClientAdvanced_INTERFACE_DEFINED__

/* interface IVsTextMarkerClientAdvanced */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextMarkerClientAdvanced;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4B874D3-1491-4f13-8B9E-17249EC4902B")
    IVsTextMarkerClientAdvanced : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnMarkerTextChanged( 
            /* [in] */ IVsTextMarker *pMarker) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextMarkerClientAdvancedVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextMarkerClientAdvanced * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextMarkerClientAdvanced * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextMarkerClientAdvanced * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnMarkerTextChanged )( 
            IVsTextMarkerClientAdvanced * This,
            /* [in] */ IVsTextMarker *pMarker);
        
        END_INTERFACE
    } IVsTextMarkerClientAdvancedVtbl;

    interface IVsTextMarkerClientAdvanced
    {
        CONST_VTBL struct IVsTextMarkerClientAdvancedVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextMarkerClientAdvanced_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextMarkerClientAdvanced_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextMarkerClientAdvanced_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextMarkerClientAdvanced_OnMarkerTextChanged(This,pMarker)	\
    (This)->lpVtbl -> OnMarkerTextChanged(This,pMarker)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextMarkerClientAdvanced_OnMarkerTextChanged_Proxy( 
    IVsTextMarkerClientAdvanced * This,
    /* [in] */ IVsTextMarker *pMarker);


void __RPC_STUB IVsTextMarkerClientAdvanced_OnMarkerTextChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextMarkerClientAdvanced_INTERFACE_DEFINED__ */


#ifndef __IVsTextMarkerClientEx_INTERFACE_DEFINED__
#define __IVsTextMarkerClientEx_INTERFACE_DEFINED__

/* interface IVsTextMarkerClientEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextMarkerClientEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA48A96D-40E9-4723-BDD8-B99072A1A426")
    IVsTextMarkerClientEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE MarkerInvalidated( 
            IVsTextLines *pBuffer,
            IVsTextMarker *pMarker) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnHoverOverMarker( 
            /* [in] */ IVsTextView *pView,
            /* [in] */ IVsTextMarker *pMarker,
            /* [in] */ BOOL fShowUI) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextMarkerClientExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextMarkerClientEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextMarkerClientEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextMarkerClientEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *MarkerInvalidated )( 
            IVsTextMarkerClientEx * This,
            IVsTextLines *pBuffer,
            IVsTextMarker *pMarker);
        
        HRESULT ( STDMETHODCALLTYPE *OnHoverOverMarker )( 
            IVsTextMarkerClientEx * This,
            /* [in] */ IVsTextView *pView,
            /* [in] */ IVsTextMarker *pMarker,
            /* [in] */ BOOL fShowUI);
        
        END_INTERFACE
    } IVsTextMarkerClientExVtbl;

    interface IVsTextMarkerClientEx
    {
        CONST_VTBL struct IVsTextMarkerClientExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextMarkerClientEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextMarkerClientEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextMarkerClientEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextMarkerClientEx_MarkerInvalidated(This,pBuffer,pMarker)	\
    (This)->lpVtbl -> MarkerInvalidated(This,pBuffer,pMarker)

#define IVsTextMarkerClientEx_OnHoverOverMarker(This,pView,pMarker,fShowUI)	\
    (This)->lpVtbl -> OnHoverOverMarker(This,pView,pMarker,fShowUI)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextMarkerClientEx_MarkerInvalidated_Proxy( 
    IVsTextMarkerClientEx * This,
    IVsTextLines *pBuffer,
    IVsTextMarker *pMarker);


void __RPC_STUB IVsTextMarkerClientEx_MarkerInvalidated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextMarkerClientEx_OnHoverOverMarker_Proxy( 
    IVsTextMarkerClientEx * This,
    /* [in] */ IVsTextView *pView,
    /* [in] */ IVsTextMarker *pMarker,
    /* [in] */ BOOL fShowUI);


void __RPC_STUB IVsTextMarkerClientEx_OnHoverOverMarker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextMarkerClientEx_INTERFACE_DEFINED__ */


#ifndef __IVsDropdownBarClientEx_INTERFACE_DEFINED__
#define __IVsDropdownBarClientEx_INTERFACE_DEFINED__

/* interface IVsDropdownBarClientEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsDropdownBarClientEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F74462E6-2E8E-477c-BA7D-F03D336DCB36")
    IVsDropdownBarClientEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEntryIndent( 
            /* [in] */ long iCombo,
            /* [in] */ long iIndex,
            /* [out] */ ULONG *pIndent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsDropdownBarClientExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsDropdownBarClientEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsDropdownBarClientEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsDropdownBarClientEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetEntryIndent )( 
            IVsDropdownBarClientEx * This,
            /* [in] */ long iCombo,
            /* [in] */ long iIndex,
            /* [out] */ ULONG *pIndent);
        
        END_INTERFACE
    } IVsDropdownBarClientExVtbl;

    interface IVsDropdownBarClientEx
    {
        CONST_VTBL struct IVsDropdownBarClientExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsDropdownBarClientEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsDropdownBarClientEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsDropdownBarClientEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsDropdownBarClientEx_GetEntryIndent(This,iCombo,iIndex,pIndent)	\
    (This)->lpVtbl -> GetEntryIndent(This,iCombo,iIndex,pIndent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsDropdownBarClientEx_GetEntryIndent_Proxy( 
    IVsDropdownBarClientEx * This,
    /* [in] */ long iCombo,
    /* [in] */ long iIndex,
    /* [out] */ ULONG *pIndent);


void __RPC_STUB IVsDropdownBarClientEx_GetEntryIndent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsDropdownBarClientEx_INTERFACE_DEFINED__ */


#ifndef __IVsHiddenRegionEx_INTERFACE_DEFINED__
#define __IVsHiddenRegionEx_INTERFACE_DEFINED__

/* interface IVsHiddenRegionEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsHiddenRegionEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FA54DAC7-23D3-4c27-B46E-0D2591E5CF0A")
    IVsHiddenRegionEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBannerAttr( 
            /* [in] */ DWORD dwLength,
            /* [size_is][out] */ ULONG *pColorAttr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBannerAttr( 
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ ULONG *pColorAttr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsHiddenRegionExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsHiddenRegionEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsHiddenRegionEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsHiddenRegionEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBannerAttr )( 
            IVsHiddenRegionEx * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][out] */ ULONG *pColorAttr);
        
        HRESULT ( STDMETHODCALLTYPE *SetBannerAttr )( 
            IVsHiddenRegionEx * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][in] */ ULONG *pColorAttr);
        
        END_INTERFACE
    } IVsHiddenRegionExVtbl;

    interface IVsHiddenRegionEx
    {
        CONST_VTBL struct IVsHiddenRegionExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsHiddenRegionEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsHiddenRegionEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsHiddenRegionEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsHiddenRegionEx_GetBannerAttr(This,dwLength,pColorAttr)	\
    (This)->lpVtbl -> GetBannerAttr(This,dwLength,pColorAttr)

#define IVsHiddenRegionEx_SetBannerAttr(This,dwLength,pColorAttr)	\
    (This)->lpVtbl -> SetBannerAttr(This,dwLength,pColorAttr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsHiddenRegionEx_GetBannerAttr_Proxy( 
    IVsHiddenRegionEx * This,
    /* [in] */ DWORD dwLength,
    /* [size_is][out] */ ULONG *pColorAttr);


void __RPC_STUB IVsHiddenRegionEx_GetBannerAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsHiddenRegionEx_SetBannerAttr_Proxy( 
    IVsHiddenRegionEx * This,
    /* [in] */ DWORD dwLength,
    /* [size_is][in] */ ULONG *pColorAttr);


void __RPC_STUB IVsHiddenRegionEx_SetBannerAttr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsHiddenRegionEx_INTERFACE_DEFINED__ */


#ifndef __IVsHiddenTextClientEx_INTERFACE_DEFINED__
#define __IVsHiddenTextClientEx_INTERFACE_DEFINED__

/* interface IVsHiddenTextClientEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsHiddenTextClientEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("225F2F59-39CF-4ae3-A08E-44CF751DE700")
    IVsHiddenTextClientEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBannerGlyphWidth( 
            /* [in] */ long iPixSpaceWidth,
            /* [out] */ long *pGlyphPix) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DrawBannerGlyph( 
            /* [in] */ IVsHiddenRegion *pHidReg,
            /* [in] */ DWORD dwFlags,
            /* [in] */ HDC hdc,
            /* [in] */ RECT *pRect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsHiddenTextClientExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsHiddenTextClientEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsHiddenTextClientEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsHiddenTextClientEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBannerGlyphWidth )( 
            IVsHiddenTextClientEx * This,
            /* [in] */ long iPixSpaceWidth,
            /* [out] */ long *pGlyphPix);
        
        HRESULT ( STDMETHODCALLTYPE *DrawBannerGlyph )( 
            IVsHiddenTextClientEx * This,
            /* [in] */ IVsHiddenRegion *pHidReg,
            /* [in] */ DWORD dwFlags,
            /* [in] */ HDC hdc,
            /* [in] */ RECT *pRect);
        
        END_INTERFACE
    } IVsHiddenTextClientExVtbl;

    interface IVsHiddenTextClientEx
    {
        CONST_VTBL struct IVsHiddenTextClientExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsHiddenTextClientEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsHiddenTextClientEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsHiddenTextClientEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsHiddenTextClientEx_GetBannerGlyphWidth(This,iPixSpaceWidth,pGlyphPix)	\
    (This)->lpVtbl -> GetBannerGlyphWidth(This,iPixSpaceWidth,pGlyphPix)

#define IVsHiddenTextClientEx_DrawBannerGlyph(This,pHidReg,dwFlags,hdc,pRect)	\
    (This)->lpVtbl -> DrawBannerGlyph(This,pHidReg,dwFlags,hdc,pRect)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsHiddenTextClientEx_GetBannerGlyphWidth_Proxy( 
    IVsHiddenTextClientEx * This,
    /* [in] */ long iPixSpaceWidth,
    /* [out] */ long *pGlyphPix);


void __RPC_STUB IVsHiddenTextClientEx_GetBannerGlyphWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsHiddenTextClientEx_DrawBannerGlyph_Proxy( 
    IVsHiddenTextClientEx * This,
    /* [in] */ IVsHiddenRegion *pHidReg,
    /* [in] */ DWORD dwFlags,
    /* [in] */ HDC hdc,
    /* [in] */ RECT *pRect);


void __RPC_STUB IVsHiddenTextClientEx_DrawBannerGlyph_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsHiddenTextClientEx_INTERFACE_DEFINED__ */


#ifndef __IVsHiddenTextSessionEx_INTERFACE_DEFINED__
#define __IVsHiddenTextSessionEx_INTERFACE_DEFINED__

/* interface IVsHiddenTextSessionEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsHiddenTextSessionEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A43C0083-755F-4385-9574-4C14BFFC4344")
    IVsHiddenTextSessionEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddHiddenRegionsEx( 
            /* [in] */ DWORD dwUpdateFlags,
            /* [in] */ long cRegions,
            /* [size_is][in] */ NewHiddenRegionEx *rgHidReg,
            /* [out] */ IVsEnumHiddenRegions **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsHiddenTextSessionExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsHiddenTextSessionEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsHiddenTextSessionEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsHiddenTextSessionEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddHiddenRegionsEx )( 
            IVsHiddenTextSessionEx * This,
            /* [in] */ DWORD dwUpdateFlags,
            /* [in] */ long cRegions,
            /* [size_is][in] */ NewHiddenRegionEx *rgHidReg,
            /* [out] */ IVsEnumHiddenRegions **ppEnum);
        
        END_INTERFACE
    } IVsHiddenTextSessionExVtbl;

    interface IVsHiddenTextSessionEx
    {
        CONST_VTBL struct IVsHiddenTextSessionExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsHiddenTextSessionEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsHiddenTextSessionEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsHiddenTextSessionEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsHiddenTextSessionEx_AddHiddenRegionsEx(This,dwUpdateFlags,cRegions,rgHidReg,ppEnum)	\
    (This)->lpVtbl -> AddHiddenRegionsEx(This,dwUpdateFlags,cRegions,rgHidReg,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsHiddenTextSessionEx_AddHiddenRegionsEx_Proxy( 
    IVsHiddenTextSessionEx * This,
    /* [in] */ DWORD dwUpdateFlags,
    /* [in] */ long cRegions,
    /* [size_is][in] */ NewHiddenRegionEx *rgHidReg,
    /* [out] */ IVsEnumHiddenRegions **ppEnum);


void __RPC_STUB IVsHiddenTextSessionEx_AddHiddenRegionsEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsHiddenTextSessionEx_INTERFACE_DEFINED__ */


#ifndef __IVsAtomicTextProvider_INTERFACE_DEFINED__
#define __IVsAtomicTextProvider_INTERFACE_DEFINED__

/* interface IVsAtomicTextProvider */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsAtomicTextProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29CDD341-0F95-42f2-B71C-75BC51A7EB72")
    IVsAtomicTextProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAtomFlags( 
            /* [out] */ DWORD *pdwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAtomAttributes( 
            /* [in] */ DWORD dwLength,
            /* [size_is][out] */ ULONG *pColorAttr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAtomGlyphWidth( 
            /* [in] */ long iPixSpaceWidth,
            /* [out] */ long *pGlyphPix) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DrawAtomGlyph( 
            /* [in] */ DWORD dwFlags,
            /* [in] */ HDC hdc,
            /* [in] */ RECT *pRect) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsAtomicTextProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsAtomicTextProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsAtomicTextProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsAtomicTextProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAtomFlags )( 
            IVsAtomicTextProvider * This,
            /* [out] */ DWORD *pdwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetAtomAttributes )( 
            IVsAtomicTextProvider * This,
            /* [in] */ DWORD dwLength,
            /* [size_is][out] */ ULONG *pColorAttr);
        
        HRESULT ( STDMETHODCALLTYPE *GetAtomGlyphWidth )( 
            IVsAtomicTextProvider * This,
            /* [in] */ long iPixSpaceWidth,
            /* [out] */ long *pGlyphPix);
        
        HRESULT ( STDMETHODCALLTYPE *DrawAtomGlyph )( 
            IVsAtomicTextProvider * This,
            /* [in] */ DWORD dwFlags,
            /* [in] */ HDC hdc,
            /* [in] */ RECT *pRect);
        
        END_INTERFACE
    } IVsAtomicTextProviderVtbl;

    interface IVsAtomicTextProvider
    {
        CONST_VTBL struct IVsAtomicTextProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsAtomicTextProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsAtomicTextProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsAtomicTextProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsAtomicTextProvider_GetAtomFlags(This,pdwFlags)	\
    (This)->lpVtbl -> GetAtomFlags(This,pdwFlags)

#define IVsAtomicTextProvider_GetAtomAttributes(This,dwLength,pColorAttr)	\
    (This)->lpVtbl -> GetAtomAttributes(This,dwLength,pColorAttr)

#define IVsAtomicTextProvider_GetAtomGlyphWidth(This,iPixSpaceWidth,pGlyphPix)	\
    (This)->lpVtbl -> GetAtomGlyphWidth(This,iPixSpaceWidth,pGlyphPix)

#define IVsAtomicTextProvider_DrawAtomGlyph(This,dwFlags,hdc,pRect)	\
    (This)->lpVtbl -> DrawAtomGlyph(This,dwFlags,hdc,pRect)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsAtomicTextProvider_GetAtomFlags_Proxy( 
    IVsAtomicTextProvider * This,
    /* [out] */ DWORD *pdwFlags);


void __RPC_STUB IVsAtomicTextProvider_GetAtomFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAtomicTextProvider_GetAtomAttributes_Proxy( 
    IVsAtomicTextProvider * This,
    /* [in] */ DWORD dwLength,
    /* [size_is][out] */ ULONG *pColorAttr);


void __RPC_STUB IVsAtomicTextProvider_GetAtomAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAtomicTextProvider_GetAtomGlyphWidth_Proxy( 
    IVsAtomicTextProvider * This,
    /* [in] */ long iPixSpaceWidth,
    /* [out] */ long *pGlyphPix);


void __RPC_STUB IVsAtomicTextProvider_GetAtomGlyphWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAtomicTextProvider_DrawAtomGlyph_Proxy( 
    IVsAtomicTextProvider * This,
    /* [in] */ DWORD dwFlags,
    /* [in] */ HDC hdc,
    /* [in] */ RECT *pRect);


void __RPC_STUB IVsAtomicTextProvider_DrawAtomGlyph_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsAtomicTextProvider_INTERFACE_DEFINED__ */


#ifndef __IVsCompletionSetEx_INTERFACE_DEFINED__
#define __IVsCompletionSetEx_INTERFACE_DEFINED__

/* interface IVsCompletionSetEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsCompletionSetEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F710016-58D5-4887-AD76-936D1A45A588")
    IVsCompletionSetEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCompletionItemColor( 
            /* [in] */ long iIndex,
            /* [out] */ COLORREF *dwFGColor,
            /* [out] */ COLORREF *dwBGColor) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFilterLevel( 
            /* [out] */ long *iFilterLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IncreaseFilterLevel( 
            /* [in] */ long iSelectedItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DecreaseFilterLevel( 
            /* [in] */ long iSelectedItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareItems( 
            /* [in] */ const BSTR bstrSoFar,
            /* [in] */ const BSTR bstrOther,
            /* [in] */ long lCharactersToCompare,
            /* [out] */ long *plResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCommitComplete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCompletionSetExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCompletionSetEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCompletionSetEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCompletionSetEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletionItemColor )( 
            IVsCompletionSetEx * This,
            /* [in] */ long iIndex,
            /* [out] */ COLORREF *dwFGColor,
            /* [out] */ COLORREF *dwBGColor);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilterLevel )( 
            IVsCompletionSetEx * This,
            /* [out] */ long *iFilterLevel);
        
        HRESULT ( STDMETHODCALLTYPE *IncreaseFilterLevel )( 
            IVsCompletionSetEx * This,
            /* [in] */ long iSelectedItem);
        
        HRESULT ( STDMETHODCALLTYPE *DecreaseFilterLevel )( 
            IVsCompletionSetEx * This,
            /* [in] */ long iSelectedItem);
        
        HRESULT ( STDMETHODCALLTYPE *CompareItems )( 
            IVsCompletionSetEx * This,
            /* [in] */ const BSTR bstrSoFar,
            /* [in] */ const BSTR bstrOther,
            /* [in] */ long lCharactersToCompare,
            /* [out] */ long *plResult);
        
        HRESULT ( STDMETHODCALLTYPE *OnCommitComplete )( 
            IVsCompletionSetEx * This);
        
        END_INTERFACE
    } IVsCompletionSetExVtbl;

    interface IVsCompletionSetEx
    {
        CONST_VTBL struct IVsCompletionSetExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCompletionSetEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCompletionSetEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCompletionSetEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCompletionSetEx_GetCompletionItemColor(This,iIndex,dwFGColor,dwBGColor)	\
    (This)->lpVtbl -> GetCompletionItemColor(This,iIndex,dwFGColor,dwBGColor)

#define IVsCompletionSetEx_GetFilterLevel(This,iFilterLevel)	\
    (This)->lpVtbl -> GetFilterLevel(This,iFilterLevel)

#define IVsCompletionSetEx_IncreaseFilterLevel(This,iSelectedItem)	\
    (This)->lpVtbl -> IncreaseFilterLevel(This,iSelectedItem)

#define IVsCompletionSetEx_DecreaseFilterLevel(This,iSelectedItem)	\
    (This)->lpVtbl -> DecreaseFilterLevel(This,iSelectedItem)

#define IVsCompletionSetEx_CompareItems(This,bstrSoFar,bstrOther,lCharactersToCompare,plResult)	\
    (This)->lpVtbl -> CompareItems(This,bstrSoFar,bstrOther,lCharactersToCompare,plResult)

#define IVsCompletionSetEx_OnCommitComplete(This)	\
    (This)->lpVtbl -> OnCommitComplete(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCompletionSetEx_GetCompletionItemColor_Proxy( 
    IVsCompletionSetEx * This,
    /* [in] */ long iIndex,
    /* [out] */ COLORREF *dwFGColor,
    /* [out] */ COLORREF *dwBGColor);


void __RPC_STUB IVsCompletionSetEx_GetCompletionItemColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCompletionSetEx_GetFilterLevel_Proxy( 
    IVsCompletionSetEx * This,
    /* [out] */ long *iFilterLevel);


void __RPC_STUB IVsCompletionSetEx_GetFilterLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCompletionSetEx_IncreaseFilterLevel_Proxy( 
    IVsCompletionSetEx * This,
    /* [in] */ long iSelectedItem);


void __RPC_STUB IVsCompletionSetEx_IncreaseFilterLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCompletionSetEx_DecreaseFilterLevel_Proxy( 
    IVsCompletionSetEx * This,
    /* [in] */ long iSelectedItem);


void __RPC_STUB IVsCompletionSetEx_DecreaseFilterLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCompletionSetEx_CompareItems_Proxy( 
    IVsCompletionSetEx * This,
    /* [in] */ const BSTR bstrSoFar,
    /* [in] */ const BSTR bstrOther,
    /* [in] */ long lCharactersToCompare,
    /* [out] */ long *plResult);


void __RPC_STUB IVsCompletionSetEx_CompareItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCompletionSetEx_OnCommitComplete_Proxy( 
    IVsCompletionSetEx * This);


void __RPC_STUB IVsCompletionSetEx_OnCommitComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCompletionSetEx_INTERFACE_DEFINED__ */


#ifndef __IVsCompletionSetBuilder_INTERFACE_DEFINED__
#define __IVsCompletionSetBuilder_INTERFACE_DEFINED__

/* interface IVsCompletionSetBuilder */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsCompletionSetBuilder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CB570E9B-7B88-4159-9819-6F7E71EFFA95")
    IVsCompletionSetBuilder : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBuilderCount( 
            long *piCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuilderDisplayText( 
            /* [in] */ long iIndex,
            /* [out] */ BSTR *pbstrText,
            /* [optional][out] */ long *piGlyph) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuilderDescriptionText( 
            /* [in] */ long iIndex,
            /* [out] */ BSTR *pbstrDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuilderImageList( 
            /* [out] */ HANDLE *phImages) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnBuilderCommit( 
            /* [in] */ long iIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuilderItemColor( 
            /* [in] */ long iIndex,
            /* [out] */ COLORREF *dwFGColor,
            /* [out] */ COLORREF *dwBGColor) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCompletionSetBuilderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCompletionSetBuilder * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCompletionSetBuilder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCompletionSetBuilder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuilderCount )( 
            IVsCompletionSetBuilder * This,
            long *piCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuilderDisplayText )( 
            IVsCompletionSetBuilder * This,
            /* [in] */ long iIndex,
            /* [out] */ BSTR *pbstrText,
            /* [optional][out] */ long *piGlyph);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuilderDescriptionText )( 
            IVsCompletionSetBuilder * This,
            /* [in] */ long iIndex,
            /* [out] */ BSTR *pbstrDescription);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuilderImageList )( 
            IVsCompletionSetBuilder * This,
            /* [out] */ HANDLE *phImages);
        
        HRESULT ( STDMETHODCALLTYPE *OnBuilderCommit )( 
            IVsCompletionSetBuilder * This,
            /* [in] */ long iIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuilderItemColor )( 
            IVsCompletionSetBuilder * This,
            /* [in] */ long iIndex,
            /* [out] */ COLORREF *dwFGColor,
            /* [out] */ COLORREF *dwBGColor);
        
        END_INTERFACE
    } IVsCompletionSetBuilderVtbl;

    interface IVsCompletionSetBuilder
    {
        CONST_VTBL struct IVsCompletionSetBuilderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCompletionSetBuilder_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCompletionSetBuilder_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCompletionSetBuilder_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCompletionSetBuilder_GetBuilderCount(This,piCount)	\
    (This)->lpVtbl -> GetBuilderCount(This,piCount)

#define IVsCompletionSetBuilder_GetBuilderDisplayText(This,iIndex,pbstrText,piGlyph)	\
    (This)->lpVtbl -> GetBuilderDisplayText(This,iIndex,pbstrText,piGlyph)

#define IVsCompletionSetBuilder_GetBuilderDescriptionText(This,iIndex,pbstrDescription)	\
    (This)->lpVtbl -> GetBuilderDescriptionText(This,iIndex,pbstrDescription)

#define IVsCompletionSetBuilder_GetBuilderImageList(This,phImages)	\
    (This)->lpVtbl -> GetBuilderImageList(This,phImages)

#define IVsCompletionSetBuilder_OnBuilderCommit(This,iIndex)	\
    (This)->lpVtbl -> OnBuilderCommit(This,iIndex)

#define IVsCompletionSetBuilder_GetBuilderItemColor(This,iIndex,dwFGColor,dwBGColor)	\
    (This)->lpVtbl -> GetBuilderItemColor(This,iIndex,dwFGColor,dwBGColor)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCompletionSetBuilder_GetBuilderCount_Proxy( 
    IVsCompletionSetBuilder * This,
    long *piCount);


void __RPC_STUB IVsCompletionSetBuilder_GetBuilderCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCompletionSetBuilder_GetBuilderDisplayText_Proxy( 
    IVsCompletionSetBuilder * This,
    /* [in] */ long iIndex,
    /* [out] */ BSTR *pbstrText,
    /* [optional][out] */ long *piGlyph);


void __RPC_STUB IVsCompletionSetBuilder_GetBuilderDisplayText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCompletionSetBuilder_GetBuilderDescriptionText_Proxy( 
    IVsCompletionSetBuilder * This,
    /* [in] */ long iIndex,
    /* [out] */ BSTR *pbstrDescription);


void __RPC_STUB IVsCompletionSetBuilder_GetBuilderDescriptionText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCompletionSetBuilder_GetBuilderImageList_Proxy( 
    IVsCompletionSetBuilder * This,
    /* [out] */ HANDLE *phImages);


void __RPC_STUB IVsCompletionSetBuilder_GetBuilderImageList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCompletionSetBuilder_OnBuilderCommit_Proxy( 
    IVsCompletionSetBuilder * This,
    /* [in] */ long iIndex);


void __RPC_STUB IVsCompletionSetBuilder_OnBuilderCommit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCompletionSetBuilder_GetBuilderItemColor_Proxy( 
    IVsCompletionSetBuilder * This,
    /* [in] */ long iIndex,
    /* [out] */ COLORREF *dwFGColor,
    /* [out] */ COLORREF *dwBGColor);


void __RPC_STUB IVsCompletionSetBuilder_GetBuilderItemColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCompletionSetBuilder_INTERFACE_DEFINED__ */


#ifndef __IVsSmartTagData_INTERFACE_DEFINED__
#define __IVsSmartTagData_INTERFACE_DEFINED__

/* interface IVsSmartTagData */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsSmartTagData;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8C2A8A68-8844-4e55-B0A1-805B4DA0DEB2")
    IVsSmartTagData : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetImageIndex( 
            /* [out] */ long *piIndex) = 0;
        
        virtual /* [custom] */ HRESULT STDMETHODCALLTYPE GetContextMenuInfo( 
            /* [out] */ GUID *guidID,
            /* [out] */ long *nMenuID,
            /* [out] */ IOleCommandTarget **pCmdTarget) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextStream( 
            /* [out] */ long *piPos,
            /* [out] */ long *piLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDismiss( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnInvocation( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateView( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTimerInterval( 
            /* [out] */ long *piTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLeftJustified( 
            /* [out] */ BOOL *pfIsLeftJustified) = 0;
        
        virtual /* [custom] */ HRESULT STDMETHODCALLTYPE GetTipText( 
            /* [out] */ BSTR *pbstrTipText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSmartTagDataVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSmartTagData * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSmartTagData * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSmartTagData * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetImageIndex )( 
            IVsSmartTagData * This,
            /* [out] */ long *piIndex);
        
        /* [custom] */ HRESULT ( STDMETHODCALLTYPE *GetContextMenuInfo )( 
            IVsSmartTagData * This,
            /* [out] */ GUID *guidID,
            /* [out] */ long *nMenuID,
            /* [out] */ IOleCommandTarget **pCmdTarget);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextStream )( 
            IVsSmartTagData * This,
            /* [out] */ long *piPos,
            /* [out] */ long *piLength);
        
        HRESULT ( STDMETHODCALLTYPE *OnDismiss )( 
            IVsSmartTagData * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnInvocation )( 
            IVsSmartTagData * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateView )( 
            IVsSmartTagData * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTimerInterval )( 
            IVsSmartTagData * This,
            /* [out] */ long *piTime);
        
        HRESULT ( STDMETHODCALLTYPE *IsLeftJustified )( 
            IVsSmartTagData * This,
            /* [out] */ BOOL *pfIsLeftJustified);
        
        /* [custom] */ HRESULT ( STDMETHODCALLTYPE *GetTipText )( 
            IVsSmartTagData * This,
            /* [out] */ BSTR *pbstrTipText);
        
        END_INTERFACE
    } IVsSmartTagDataVtbl;

    interface IVsSmartTagData
    {
        CONST_VTBL struct IVsSmartTagDataVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSmartTagData_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSmartTagData_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSmartTagData_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSmartTagData_GetImageIndex(This,piIndex)	\
    (This)->lpVtbl -> GetImageIndex(This,piIndex)

#define IVsSmartTagData_GetContextMenuInfo(This,guidID,nMenuID,pCmdTarget)	\
    (This)->lpVtbl -> GetContextMenuInfo(This,guidID,nMenuID,pCmdTarget)

#define IVsSmartTagData_GetContextStream(This,piPos,piLength)	\
    (This)->lpVtbl -> GetContextStream(This,piPos,piLength)

#define IVsSmartTagData_OnDismiss(This)	\
    (This)->lpVtbl -> OnDismiss(This)

#define IVsSmartTagData_OnInvocation(This)	\
    (This)->lpVtbl -> OnInvocation(This)

#define IVsSmartTagData_UpdateView(This)	\
    (This)->lpVtbl -> UpdateView(This)

#define IVsSmartTagData_GetTimerInterval(This,piTime)	\
    (This)->lpVtbl -> GetTimerInterval(This,piTime)

#define IVsSmartTagData_IsLeftJustified(This,pfIsLeftJustified)	\
    (This)->lpVtbl -> IsLeftJustified(This,pfIsLeftJustified)

#define IVsSmartTagData_GetTipText(This,pbstrTipText)	\
    (This)->lpVtbl -> GetTipText(This,pbstrTipText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSmartTagData_GetImageIndex_Proxy( 
    IVsSmartTagData * This,
    /* [out] */ long *piIndex);


void __RPC_STUB IVsSmartTagData_GetImageIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [custom] */ HRESULT STDMETHODCALLTYPE IVsSmartTagData_GetContextMenuInfo_Proxy( 
    IVsSmartTagData * This,
    /* [out] */ GUID *guidID,
    /* [out] */ long *nMenuID,
    /* [out] */ IOleCommandTarget **pCmdTarget);


void __RPC_STUB IVsSmartTagData_GetContextMenuInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSmartTagData_GetContextStream_Proxy( 
    IVsSmartTagData * This,
    /* [out] */ long *piPos,
    /* [out] */ long *piLength);


void __RPC_STUB IVsSmartTagData_GetContextStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSmartTagData_OnDismiss_Proxy( 
    IVsSmartTagData * This);


void __RPC_STUB IVsSmartTagData_OnDismiss_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSmartTagData_OnInvocation_Proxy( 
    IVsSmartTagData * This);


void __RPC_STUB IVsSmartTagData_OnInvocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSmartTagData_UpdateView_Proxy( 
    IVsSmartTagData * This);


void __RPC_STUB IVsSmartTagData_UpdateView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSmartTagData_GetTimerInterval_Proxy( 
    IVsSmartTagData * This,
    /* [out] */ long *piTime);


void __RPC_STUB IVsSmartTagData_GetTimerInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSmartTagData_IsLeftJustified_Proxy( 
    IVsSmartTagData * This,
    /* [out] */ BOOL *pfIsLeftJustified);


void __RPC_STUB IVsSmartTagData_IsLeftJustified_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [custom] */ HRESULT STDMETHODCALLTYPE IVsSmartTagData_GetTipText_Proxy( 
    IVsSmartTagData * This,
    /* [out] */ BSTR *pbstrTipText);


void __RPC_STUB IVsSmartTagData_GetTipText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSmartTagData_INTERFACE_DEFINED__ */


#ifndef __IVsSmartTagTipWindow_INTERFACE_DEFINED__
#define __IVsSmartTagTipWindow_INTERFACE_DEFINED__

/* interface IVsSmartTagTipWindow */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsSmartTagTipWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E2DECE2A-3A77-4fd3-A4B2-FA5EC4EA41D9")
    IVsSmartTagTipWindow : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetContextStream( 
            /* [out] */ long *piPos,
            /* [out] */ long *piLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSizePreferences( 
            /* [in] */ const RECT *prcCtxBounds,
            /* [out] */ SMARTTAGSIZEDATA *pSizeData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Paint( 
            /* [in] */ HDC hdc,
            /* [in] */ const RECT *prc,
            /* [in] */ COLORREF pColor,
            /* [in] */ COLORREF pColorText,
            /* [in] */ BOOL fSel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Dismiss( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WndProc( 
            /* [in] */ HWND hwnd,
            /* [in] */ UINT iMsg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            LRESULT *pLResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSmartTagData( 
            /* [in] */ IVsSmartTagData *pSmartTagData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSmartTagTipWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSmartTagTipWindow * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSmartTagTipWindow * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSmartTagTipWindow * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextStream )( 
            IVsSmartTagTipWindow * This,
            /* [out] */ long *piPos,
            /* [out] */ long *piLength);
        
        HRESULT ( STDMETHODCALLTYPE *GetSizePreferences )( 
            IVsSmartTagTipWindow * This,
            /* [in] */ const RECT *prcCtxBounds,
            /* [out] */ SMARTTAGSIZEDATA *pSizeData);
        
        HRESULT ( STDMETHODCALLTYPE *Paint )( 
            IVsSmartTagTipWindow * This,
            /* [in] */ HDC hdc,
            /* [in] */ const RECT *prc,
            /* [in] */ COLORREF pColor,
            /* [in] */ COLORREF pColorText,
            /* [in] */ BOOL fSel);
        
        HRESULT ( STDMETHODCALLTYPE *Dismiss )( 
            IVsSmartTagTipWindow * This);
        
        HRESULT ( STDMETHODCALLTYPE *WndProc )( 
            IVsSmartTagTipWindow * This,
            /* [in] */ HWND hwnd,
            /* [in] */ UINT iMsg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam,
            LRESULT *pLResult);
        
        HRESULT ( STDMETHODCALLTYPE *SetSmartTagData )( 
            IVsSmartTagTipWindow * This,
            /* [in] */ IVsSmartTagData *pSmartTagData);
        
        END_INTERFACE
    } IVsSmartTagTipWindowVtbl;

    interface IVsSmartTagTipWindow
    {
        CONST_VTBL struct IVsSmartTagTipWindowVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSmartTagTipWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSmartTagTipWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSmartTagTipWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSmartTagTipWindow_GetContextStream(This,piPos,piLength)	\
    (This)->lpVtbl -> GetContextStream(This,piPos,piLength)

#define IVsSmartTagTipWindow_GetSizePreferences(This,prcCtxBounds,pSizeData)	\
    (This)->lpVtbl -> GetSizePreferences(This,prcCtxBounds,pSizeData)

#define IVsSmartTagTipWindow_Paint(This,hdc,prc,pColor,pColorText,fSel)	\
    (This)->lpVtbl -> Paint(This,hdc,prc,pColor,pColorText,fSel)

#define IVsSmartTagTipWindow_Dismiss(This)	\
    (This)->lpVtbl -> Dismiss(This)

#define IVsSmartTagTipWindow_WndProc(This,hwnd,iMsg,wParam,lParam,pLResult)	\
    (This)->lpVtbl -> WndProc(This,hwnd,iMsg,wParam,lParam,pLResult)

#define IVsSmartTagTipWindow_SetSmartTagData(This,pSmartTagData)	\
    (This)->lpVtbl -> SetSmartTagData(This,pSmartTagData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSmartTagTipWindow_GetContextStream_Proxy( 
    IVsSmartTagTipWindow * This,
    /* [out] */ long *piPos,
    /* [out] */ long *piLength);


void __RPC_STUB IVsSmartTagTipWindow_GetContextStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSmartTagTipWindow_GetSizePreferences_Proxy( 
    IVsSmartTagTipWindow * This,
    /* [in] */ const RECT *prcCtxBounds,
    /* [out] */ SMARTTAGSIZEDATA *pSizeData);


void __RPC_STUB IVsSmartTagTipWindow_GetSizePreferences_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSmartTagTipWindow_Paint_Proxy( 
    IVsSmartTagTipWindow * This,
    /* [in] */ HDC hdc,
    /* [in] */ const RECT *prc,
    /* [in] */ COLORREF pColor,
    /* [in] */ COLORREF pColorText,
    /* [in] */ BOOL fSel);


void __RPC_STUB IVsSmartTagTipWindow_Paint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSmartTagTipWindow_Dismiss_Proxy( 
    IVsSmartTagTipWindow * This);


void __RPC_STUB IVsSmartTagTipWindow_Dismiss_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSmartTagTipWindow_WndProc_Proxy( 
    IVsSmartTagTipWindow * This,
    /* [in] */ HWND hwnd,
    /* [in] */ UINT iMsg,
    /* [in] */ WPARAM wParam,
    /* [in] */ LPARAM lParam,
    LRESULT *pLResult);


void __RPC_STUB IVsSmartTagTipWindow_WndProc_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSmartTagTipWindow_SetSmartTagData_Proxy( 
    IVsSmartTagTipWindow * This,
    /* [in] */ IVsSmartTagData *pSmartTagData);


void __RPC_STUB IVsSmartTagTipWindow_SetSmartTagData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSmartTagTipWindow_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_VsSmartTagTipWindow;

#ifdef __cplusplus

class DECLSPEC_UUID("5A46C6DE-1FE4-43b8-8E1E-598AE65F184A")
VsSmartTagTipWindow;
#endif

#ifndef __IVsMethodDataEx_INTERFACE_DEFINED__
#define __IVsMethodDataEx_INTERFACE_DEFINED__

/* interface IVsMethodDataEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsMethodDataEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("28ABE611-DCB8-4684-9793-105C92839AAB")
    IVsMethodDataEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCopyTipText( 
            /* [in] */ long iMethod,
            /* [out] */ BSTR *pbstrTipText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsMethodDataExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsMethodDataEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsMethodDataEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsMethodDataEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCopyTipText )( 
            IVsMethodDataEx * This,
            /* [in] */ long iMethod,
            /* [out] */ BSTR *pbstrTipText);
        
        END_INTERFACE
    } IVsMethodDataExVtbl;

    interface IVsMethodDataEx
    {
        CONST_VTBL struct IVsMethodDataExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsMethodDataEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsMethodDataEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsMethodDataEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsMethodDataEx_GetCopyTipText(This,iMethod,pbstrTipText)	\
    (This)->lpVtbl -> GetCopyTipText(This,iMethod,pbstrTipText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsMethodDataEx_GetCopyTipText_Proxy( 
    IVsMethodDataEx * This,
    /* [in] */ long iMethod,
    /* [out] */ BSTR *pbstrTipText);


void __RPC_STUB IVsMethodDataEx_GetCopyTipText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsMethodDataEx_INTERFACE_DEFINED__ */


#ifndef __IVsLanguageClipboardOpsEx_INTERFACE_DEFINED__
#define __IVsLanguageClipboardOpsEx_INTERFACE_DEFINED__

/* interface IVsLanguageClipboardOpsEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsLanguageClipboardOpsEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E36E3541-45D6-4ad8-B5AF-DDCB3E02CF3F")
    IVsLanguageClipboardOpsEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsTextDataEx( 
            /* [in] */ IDataObject *pDO,
            /* [in] */ IVsTextLines *pBuffer,
            /* [out] */ BOOL *pfIsTextData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsLanguageClipboardOpsExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsLanguageClipboardOpsEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsLanguageClipboardOpsEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsLanguageClipboardOpsEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsTextDataEx )( 
            IVsLanguageClipboardOpsEx * This,
            /* [in] */ IDataObject *pDO,
            /* [in] */ IVsTextLines *pBuffer,
            /* [out] */ BOOL *pfIsTextData);
        
        END_INTERFACE
    } IVsLanguageClipboardOpsExVtbl;

    interface IVsLanguageClipboardOpsEx
    {
        CONST_VTBL struct IVsLanguageClipboardOpsExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsLanguageClipboardOpsEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsLanguageClipboardOpsEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsLanguageClipboardOpsEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsLanguageClipboardOpsEx_IsTextDataEx(This,pDO,pBuffer,pfIsTextData)	\
    (This)->lpVtbl -> IsTextDataEx(This,pDO,pBuffer,pfIsTextData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsLanguageClipboardOpsEx_IsTextDataEx_Proxy( 
    IVsLanguageClipboardOpsEx * This,
    /* [in] */ IDataObject *pDO,
    /* [in] */ IVsTextLines *pBuffer,
    /* [out] */ BOOL *pfIsTextData);


void __RPC_STUB IVsLanguageClipboardOpsEx_IsTextDataEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsLanguageClipboardOpsEx_INTERFACE_DEFINED__ */


#ifndef __IVsLanguageDragDropOps_INTERFACE_DEFINED__
#define __IVsLanguageDragDropOps_INTERFACE_DEFINED__

/* interface IVsLanguageDragDropOps */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsLanguageDragDropOps;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B3F95731-540E-4f1c-B6D9-1A7FF6DEC782")
    IVsLanguageDragDropOps : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DragSetup( 
            /* [in] */ IDataObject *pDO,
            /* [in] */ IVsTextLines *pBuffer,
            /* [out] */ BOOL *pfDocumentContainsTextData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsTextDataAtLocation( 
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ long iLine,
            /* [in] */ long iCol,
            /* [out] */ BOOL *pfIsTextDataValidAtLoc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DragCleanup( 
            /* [in] */ IVsTextLines *pBuffer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsLanguageDragDropOpsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsLanguageDragDropOps * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsLanguageDragDropOps * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsLanguageDragDropOps * This);
        
        HRESULT ( STDMETHODCALLTYPE *DragSetup )( 
            IVsLanguageDragDropOps * This,
            /* [in] */ IDataObject *pDO,
            /* [in] */ IVsTextLines *pBuffer,
            /* [out] */ BOOL *pfDocumentContainsTextData);
        
        HRESULT ( STDMETHODCALLTYPE *IsTextDataAtLocation )( 
            IVsLanguageDragDropOps * This,
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ long iLine,
            /* [in] */ long iCol,
            /* [out] */ BOOL *pfIsTextDataValidAtLoc);
        
        HRESULT ( STDMETHODCALLTYPE *DragCleanup )( 
            IVsLanguageDragDropOps * This,
            /* [in] */ IVsTextLines *pBuffer);
        
        END_INTERFACE
    } IVsLanguageDragDropOpsVtbl;

    interface IVsLanguageDragDropOps
    {
        CONST_VTBL struct IVsLanguageDragDropOpsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsLanguageDragDropOps_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsLanguageDragDropOps_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsLanguageDragDropOps_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsLanguageDragDropOps_DragSetup(This,pDO,pBuffer,pfDocumentContainsTextData)	\
    (This)->lpVtbl -> DragSetup(This,pDO,pBuffer,pfDocumentContainsTextData)

#define IVsLanguageDragDropOps_IsTextDataAtLocation(This,pBuffer,iLine,iCol,pfIsTextDataValidAtLoc)	\
    (This)->lpVtbl -> IsTextDataAtLocation(This,pBuffer,iLine,iCol,pfIsTextDataValidAtLoc)

#define IVsLanguageDragDropOps_DragCleanup(This,pBuffer)	\
    (This)->lpVtbl -> DragCleanup(This,pBuffer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsLanguageDragDropOps_DragSetup_Proxy( 
    IVsLanguageDragDropOps * This,
    /* [in] */ IDataObject *pDO,
    /* [in] */ IVsTextLines *pBuffer,
    /* [out] */ BOOL *pfDocumentContainsTextData);


void __RPC_STUB IVsLanguageDragDropOps_DragSetup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLanguageDragDropOps_IsTextDataAtLocation_Proxy( 
    IVsLanguageDragDropOps * This,
    /* [in] */ IVsTextLines *pBuffer,
    /* [in] */ long iLine,
    /* [in] */ long iCol,
    /* [out] */ BOOL *pfIsTextDataValidAtLoc);


void __RPC_STUB IVsLanguageDragDropOps_IsTextDataAtLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLanguageDragDropOps_DragCleanup_Proxy( 
    IVsLanguageDragDropOps * This,
    /* [in] */ IVsTextLines *pBuffer);


void __RPC_STUB IVsLanguageDragDropOps_DragCleanup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsLanguageDragDropOps_INTERFACE_DEFINED__ */


#ifndef __IVsLanguageDebugInfo2_INTERFACE_DEFINED__
#define __IVsLanguageDebugInfo2_INTERFACE_DEFINED__

/* interface IVsLanguageDebugInfo2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsLanguageDebugInfo2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F1AF0080-C965-4E73-8763-3C6309707D59")
    IVsLanguageDebugInfo2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryCommonLanguageBlock( 
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ long iLine,
            /* [in] */ long iCol,
            /* [in] */ DWORD dwFlag,
            /* [out] */ BOOL *pfInBlock) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ValidateInstructionpointLocation( 
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ long iLine,
            /* [in] */ long iCol,
            /* [out] */ TextSpan *pCodeSpan) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryCatchLineSpan( 
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ long iLine,
            /* [in] */ long iCol,
            /* [out] */ BOOL *pfIsInCatch,
            /* [out] */ TextSpan *ptsCatchLine) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsLanguageDebugInfo2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsLanguageDebugInfo2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsLanguageDebugInfo2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsLanguageDebugInfo2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryCommonLanguageBlock )( 
            IVsLanguageDebugInfo2 * This,
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ long iLine,
            /* [in] */ long iCol,
            /* [in] */ DWORD dwFlag,
            /* [out] */ BOOL *pfInBlock);
        
        HRESULT ( STDMETHODCALLTYPE *ValidateInstructionpointLocation )( 
            IVsLanguageDebugInfo2 * This,
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ long iLine,
            /* [in] */ long iCol,
            /* [out] */ TextSpan *pCodeSpan);
        
        HRESULT ( STDMETHODCALLTYPE *QueryCatchLineSpan )( 
            IVsLanguageDebugInfo2 * This,
            /* [in] */ IVsTextBuffer *pBuffer,
            /* [in] */ long iLine,
            /* [in] */ long iCol,
            /* [out] */ BOOL *pfIsInCatch,
            /* [out] */ TextSpan *ptsCatchLine);
        
        END_INTERFACE
    } IVsLanguageDebugInfo2Vtbl;

    interface IVsLanguageDebugInfo2
    {
        CONST_VTBL struct IVsLanguageDebugInfo2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsLanguageDebugInfo2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsLanguageDebugInfo2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsLanguageDebugInfo2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsLanguageDebugInfo2_QueryCommonLanguageBlock(This,pBuffer,iLine,iCol,dwFlag,pfInBlock)	\
    (This)->lpVtbl -> QueryCommonLanguageBlock(This,pBuffer,iLine,iCol,dwFlag,pfInBlock)

#define IVsLanguageDebugInfo2_ValidateInstructionpointLocation(This,pBuffer,iLine,iCol,pCodeSpan)	\
    (This)->lpVtbl -> ValidateInstructionpointLocation(This,pBuffer,iLine,iCol,pCodeSpan)

#define IVsLanguageDebugInfo2_QueryCatchLineSpan(This,pBuffer,iLine,iCol,pfIsInCatch,ptsCatchLine)	\
    (This)->lpVtbl -> QueryCatchLineSpan(This,pBuffer,iLine,iCol,pfIsInCatch,ptsCatchLine)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsLanguageDebugInfo2_QueryCommonLanguageBlock_Proxy( 
    IVsLanguageDebugInfo2 * This,
    /* [in] */ IVsTextBuffer *pBuffer,
    /* [in] */ long iLine,
    /* [in] */ long iCol,
    /* [in] */ DWORD dwFlag,
    /* [out] */ BOOL *pfInBlock);


void __RPC_STUB IVsLanguageDebugInfo2_QueryCommonLanguageBlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLanguageDebugInfo2_ValidateInstructionpointLocation_Proxy( 
    IVsLanguageDebugInfo2 * This,
    /* [in] */ IVsTextBuffer *pBuffer,
    /* [in] */ long iLine,
    /* [in] */ long iCol,
    /* [out] */ TextSpan *pCodeSpan);


void __RPC_STUB IVsLanguageDebugInfo2_ValidateInstructionpointLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLanguageDebugInfo2_QueryCatchLineSpan_Proxy( 
    IVsLanguageDebugInfo2 * This,
    /* [in] */ IVsTextBuffer *pBuffer,
    /* [in] */ long iLine,
    /* [in] */ long iCol,
    /* [out] */ BOOL *pfIsInCatch,
    /* [out] */ TextSpan *ptsCatchLine);


void __RPC_STUB IVsLanguageDebugInfo2_QueryCatchLineSpan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsLanguageDebugInfo2_INTERFACE_DEFINED__ */


#ifndef __IVsExpansionFunction_INTERFACE_DEFINED__
#define __IVsExpansionFunction_INTERFACE_DEFINED__

/* interface IVsExpansionFunction */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsExpansionFunction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("563011A2-1611-48ed-B3B1-189060064F66")
    IVsExpansionFunction : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFunctionType( 
            /* [out] */ ExpansionFunctionType *pFuncType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetListCount( 
            /* [out] */ long *iCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetListText( 
            /* [in] */ long iIndex,
            /* [out] */ BSTR *pbstrText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultValue( 
            /* [out] */ BSTR *bstrValue,
            /* [out] */ BOOL *fHasDefaultValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FieldChanged( 
            /* [in] */ BSTR bstrField,
            /* [out] */ BOOL *fRequeryFunction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentValue( 
            /* [out] */ BSTR *bstrValue,
            /* [out] */ BOOL *fHasCurrentValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseFunction( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsExpansionFunctionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsExpansionFunction * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsExpansionFunction * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsExpansionFunction * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFunctionType )( 
            IVsExpansionFunction * This,
            /* [out] */ ExpansionFunctionType *pFuncType);
        
        HRESULT ( STDMETHODCALLTYPE *GetListCount )( 
            IVsExpansionFunction * This,
            /* [out] */ long *iCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetListText )( 
            IVsExpansionFunction * This,
            /* [in] */ long iIndex,
            /* [out] */ BSTR *pbstrText);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultValue )( 
            IVsExpansionFunction * This,
            /* [out] */ BSTR *bstrValue,
            /* [out] */ BOOL *fHasDefaultValue);
        
        HRESULT ( STDMETHODCALLTYPE *FieldChanged )( 
            IVsExpansionFunction * This,
            /* [in] */ BSTR bstrField,
            /* [out] */ BOOL *fRequeryFunction);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentValue )( 
            IVsExpansionFunction * This,
            /* [out] */ BSTR *bstrValue,
            /* [out] */ BOOL *fHasCurrentValue);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseFunction )( 
            IVsExpansionFunction * This);
        
        END_INTERFACE
    } IVsExpansionFunctionVtbl;

    interface IVsExpansionFunction
    {
        CONST_VTBL struct IVsExpansionFunctionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsExpansionFunction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsExpansionFunction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsExpansionFunction_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsExpansionFunction_GetFunctionType(This,pFuncType)	\
    (This)->lpVtbl -> GetFunctionType(This,pFuncType)

#define IVsExpansionFunction_GetListCount(This,iCount)	\
    (This)->lpVtbl -> GetListCount(This,iCount)

#define IVsExpansionFunction_GetListText(This,iIndex,pbstrText)	\
    (This)->lpVtbl -> GetListText(This,iIndex,pbstrText)

#define IVsExpansionFunction_GetDefaultValue(This,bstrValue,fHasDefaultValue)	\
    (This)->lpVtbl -> GetDefaultValue(This,bstrValue,fHasDefaultValue)

#define IVsExpansionFunction_FieldChanged(This,bstrField,fRequeryFunction)	\
    (This)->lpVtbl -> FieldChanged(This,bstrField,fRequeryFunction)

#define IVsExpansionFunction_GetCurrentValue(This,bstrValue,fHasCurrentValue)	\
    (This)->lpVtbl -> GetCurrentValue(This,bstrValue,fHasCurrentValue)

#define IVsExpansionFunction_ReleaseFunction(This)	\
    (This)->lpVtbl -> ReleaseFunction(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsExpansionFunction_GetFunctionType_Proxy( 
    IVsExpansionFunction * This,
    /* [out] */ ExpansionFunctionType *pFuncType);


void __RPC_STUB IVsExpansionFunction_GetFunctionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionFunction_GetListCount_Proxy( 
    IVsExpansionFunction * This,
    /* [out] */ long *iCount);


void __RPC_STUB IVsExpansionFunction_GetListCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionFunction_GetListText_Proxy( 
    IVsExpansionFunction * This,
    /* [in] */ long iIndex,
    /* [out] */ BSTR *pbstrText);


void __RPC_STUB IVsExpansionFunction_GetListText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionFunction_GetDefaultValue_Proxy( 
    IVsExpansionFunction * This,
    /* [out] */ BSTR *bstrValue,
    /* [out] */ BOOL *fHasDefaultValue);


void __RPC_STUB IVsExpansionFunction_GetDefaultValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionFunction_FieldChanged_Proxy( 
    IVsExpansionFunction * This,
    /* [in] */ BSTR bstrField,
    /* [out] */ BOOL *fRequeryFunction);


void __RPC_STUB IVsExpansionFunction_FieldChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionFunction_GetCurrentValue_Proxy( 
    IVsExpansionFunction * This,
    /* [out] */ BSTR *bstrValue,
    /* [out] */ BOOL *fHasCurrentValue);


void __RPC_STUB IVsExpansionFunction_GetCurrentValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionFunction_ReleaseFunction_Proxy( 
    IVsExpansionFunction * This);


void __RPC_STUB IVsExpansionFunction_ReleaseFunction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsExpansionFunction_INTERFACE_DEFINED__ */


#ifndef __IVsExpansionClient_INTERFACE_DEFINED__
#define __IVsExpansionClient_INTERFACE_DEFINED__

/* interface IVsExpansionClient */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsExpansionClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9DD0F39A-9502-4068-93B7-B6ADAB33ECD8")
    IVsExpansionClient : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetExpansionFunction( 
            /* [in] */ IXMLDOMNode *xmlFunctionNode,
            /* [in] */ BSTR bstrFieldName,
            /* [out] */ IVsExpansionFunction **pFunc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FormatSpan( 
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ TextSpan *ts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndExpansion( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsValidType( 
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ TextSpan *ts,
            /* [size_is][in] */ BSTR *rgTypes,
            /* [in] */ int iCountTypes,
            /* [out] */ BOOL *pfIsValidType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsValidKind( 
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ TextSpan *ts,
            /* [in] */ BSTR bstrKind,
            /* [out] */ BOOL *pfIsValidKind) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnBeforeInsertion( 
            IVsExpansionSession *pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterInsertion( 
            IVsExpansionSession *pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PositionCaretForEditing( 
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ TextSpan *ts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnItemChosen( 
            /* [in] */ BSTR pszTitle,
            /* [in] */ BSTR pszPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsExpansionClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsExpansionClient * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsExpansionClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsExpansionClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpansionFunction )( 
            IVsExpansionClient * This,
            /* [in] */ IXMLDOMNode *xmlFunctionNode,
            /* [in] */ BSTR bstrFieldName,
            /* [out] */ IVsExpansionFunction **pFunc);
        
        HRESULT ( STDMETHODCALLTYPE *FormatSpan )( 
            IVsExpansionClient * This,
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ TextSpan *ts);
        
        HRESULT ( STDMETHODCALLTYPE *EndExpansion )( 
            IVsExpansionClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsValidType )( 
            IVsExpansionClient * This,
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ TextSpan *ts,
            /* [size_is][in] */ BSTR *rgTypes,
            /* [in] */ int iCountTypes,
            /* [out] */ BOOL *pfIsValidType);
        
        HRESULT ( STDMETHODCALLTYPE *IsValidKind )( 
            IVsExpansionClient * This,
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ TextSpan *ts,
            /* [in] */ BSTR bstrKind,
            /* [out] */ BOOL *pfIsValidKind);
        
        HRESULT ( STDMETHODCALLTYPE *OnBeforeInsertion )( 
            IVsExpansionClient * This,
            IVsExpansionSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterInsertion )( 
            IVsExpansionClient * This,
            IVsExpansionSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *PositionCaretForEditing )( 
            IVsExpansionClient * This,
            /* [in] */ IVsTextLines *pBuffer,
            /* [in] */ TextSpan *ts);
        
        HRESULT ( STDMETHODCALLTYPE *OnItemChosen )( 
            IVsExpansionClient * This,
            /* [in] */ BSTR pszTitle,
            /* [in] */ BSTR pszPath);
        
        END_INTERFACE
    } IVsExpansionClientVtbl;

    interface IVsExpansionClient
    {
        CONST_VTBL struct IVsExpansionClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsExpansionClient_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsExpansionClient_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsExpansionClient_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsExpansionClient_GetExpansionFunction(This,xmlFunctionNode,bstrFieldName,pFunc)	\
    (This)->lpVtbl -> GetExpansionFunction(This,xmlFunctionNode,bstrFieldName,pFunc)

#define IVsExpansionClient_FormatSpan(This,pBuffer,ts)	\
    (This)->lpVtbl -> FormatSpan(This,pBuffer,ts)

#define IVsExpansionClient_EndExpansion(This)	\
    (This)->lpVtbl -> EndExpansion(This)

#define IVsExpansionClient_IsValidType(This,pBuffer,ts,rgTypes,iCountTypes,pfIsValidType)	\
    (This)->lpVtbl -> IsValidType(This,pBuffer,ts,rgTypes,iCountTypes,pfIsValidType)

#define IVsExpansionClient_IsValidKind(This,pBuffer,ts,bstrKind,pfIsValidKind)	\
    (This)->lpVtbl -> IsValidKind(This,pBuffer,ts,bstrKind,pfIsValidKind)

#define IVsExpansionClient_OnBeforeInsertion(This,pSession)	\
    (This)->lpVtbl -> OnBeforeInsertion(This,pSession)

#define IVsExpansionClient_OnAfterInsertion(This,pSession)	\
    (This)->lpVtbl -> OnAfterInsertion(This,pSession)

#define IVsExpansionClient_PositionCaretForEditing(This,pBuffer,ts)	\
    (This)->lpVtbl -> PositionCaretForEditing(This,pBuffer,ts)

#define IVsExpansionClient_OnItemChosen(This,pszTitle,pszPath)	\
    (This)->lpVtbl -> OnItemChosen(This,pszTitle,pszPath)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsExpansionClient_GetExpansionFunction_Proxy( 
    IVsExpansionClient * This,
    /* [in] */ IXMLDOMNode *xmlFunctionNode,
    /* [in] */ BSTR bstrFieldName,
    /* [out] */ IVsExpansionFunction **pFunc);


void __RPC_STUB IVsExpansionClient_GetExpansionFunction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionClient_FormatSpan_Proxy( 
    IVsExpansionClient * This,
    /* [in] */ IVsTextLines *pBuffer,
    /* [in] */ TextSpan *ts);


void __RPC_STUB IVsExpansionClient_FormatSpan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionClient_EndExpansion_Proxy( 
    IVsExpansionClient * This);


void __RPC_STUB IVsExpansionClient_EndExpansion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionClient_IsValidType_Proxy( 
    IVsExpansionClient * This,
    /* [in] */ IVsTextLines *pBuffer,
    /* [in] */ TextSpan *ts,
    /* [size_is][in] */ BSTR *rgTypes,
    /* [in] */ int iCountTypes,
    /* [out] */ BOOL *pfIsValidType);


void __RPC_STUB IVsExpansionClient_IsValidType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionClient_IsValidKind_Proxy( 
    IVsExpansionClient * This,
    /* [in] */ IVsTextLines *pBuffer,
    /* [in] */ TextSpan *ts,
    /* [in] */ BSTR bstrKind,
    /* [out] */ BOOL *pfIsValidKind);


void __RPC_STUB IVsExpansionClient_IsValidKind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionClient_OnBeforeInsertion_Proxy( 
    IVsExpansionClient * This,
    IVsExpansionSession *pSession);


void __RPC_STUB IVsExpansionClient_OnBeforeInsertion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionClient_OnAfterInsertion_Proxy( 
    IVsExpansionClient * This,
    IVsExpansionSession *pSession);


void __RPC_STUB IVsExpansionClient_OnAfterInsertion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionClient_PositionCaretForEditing_Proxy( 
    IVsExpansionClient * This,
    /* [in] */ IVsTextLines *pBuffer,
    /* [in] */ TextSpan *ts);


void __RPC_STUB IVsExpansionClient_PositionCaretForEditing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionClient_OnItemChosen_Proxy( 
    IVsExpansionClient * This,
    /* [in] */ BSTR pszTitle,
    /* [in] */ BSTR pszPath);


void __RPC_STUB IVsExpansionClient_OnItemChosen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsExpansionClient_INTERFACE_DEFINED__ */


#ifndef __IVsExpansionEnumeration_INTERFACE_DEFINED__
#define __IVsExpansionEnumeration_INTERFACE_DEFINED__

/* interface IVsExpansionEnumeration */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsExpansionEnumeration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("341E80BE-5B26-4dee-A111-32A8373D1B51")
    IVsExpansionEnumeration : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            ULONG celt,
            /* [length_is][size_is][out] */ VsExpansion **rgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsExpansionEnumerationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsExpansionEnumeration * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsExpansionEnumeration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsExpansionEnumeration * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsExpansionEnumeration * This,
            ULONG celt,
            /* [length_is][size_is][out] */ VsExpansion **rgelt,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsExpansionEnumeration * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IVsExpansionEnumeration * This,
            /* [out] */ ULONG *pCount);
        
        END_INTERFACE
    } IVsExpansionEnumerationVtbl;

    interface IVsExpansionEnumeration
    {
        CONST_VTBL struct IVsExpansionEnumerationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsExpansionEnumeration_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsExpansionEnumeration_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsExpansionEnumeration_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsExpansionEnumeration_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IVsExpansionEnumeration_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsExpansionEnumeration_GetCount(This,pCount)	\
    (This)->lpVtbl -> GetCount(This,pCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsExpansionEnumeration_Next_Proxy( 
    IVsExpansionEnumeration * This,
    ULONG celt,
    /* [length_is][size_is][out] */ VsExpansion **rgelt,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsExpansionEnumeration_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionEnumeration_Reset_Proxy( 
    IVsExpansionEnumeration * This);


void __RPC_STUB IVsExpansionEnumeration_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionEnumeration_GetCount_Proxy( 
    IVsExpansionEnumeration * This,
    /* [out] */ ULONG *pCount);


void __RPC_STUB IVsExpansionEnumeration_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsExpansionEnumeration_INTERFACE_DEFINED__ */


#ifndef __IVsExpansionManager_INTERFACE_DEFINED__
#define __IVsExpansionManager_INTERFACE_DEFINED__

/* interface IVsExpansionManager */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsExpansionManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CA09E5EA-FEE7-4b52-AFE6-8EA2EC53F681")
    IVsExpansionManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumerateExpansions( 
            /* [in] */ GUID guidLang,
            /* [in] */ BOOL fShortCutOnly,
            /* [size_is][in] */ BSTR *bstrTypes,
            /* [in] */ long iCountTypes,
            /* [in] */ BOOL fIncludeNULLType,
            /* [in] */ BOOL fIncludeDuplicates,
            /* [out] */ IVsExpansionEnumeration **pEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InvokeInsertionUI( 
            /* [in] */ IVsTextView *pView,
            /* [in] */ IVsExpansionClient *pClient,
            /* [in] */ GUID guidLang,
            /* [size_is][in] */ BSTR *bstrTypes,
            /* [in] */ long iCountTypes,
            /* [in] */ BOOL fIncludeNULLType,
            /* [size_is][in] */ BSTR *bstrKinds,
            /* [in] */ long iCountKinds,
            /* [in] */ BOOL fIncludeNULLKind,
            /* [in] */ BSTR bstrPrefixText,
            /* [in] */ BSTR bstrCompletionChar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExpansionByShortcut( 
            /* [in] */ IVsExpansionClient *pClient,
            /* [in] */ GUID guidLang,
            /* [string][in] */ LPOLESTR szShortcut,
            /* [in] */ IVsTextView *pView,
            /* [in] */ TextSpan *pts,
            /* [in] */ BOOL fShowUI,
            /* [out] */ BSTR *pszExpansionPath,
            /* [out] */ BSTR *pszTitle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTokenPath( 
            /* [in] */ ExpansionToken token,
            /* [out] */ BSTR *pbstrPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSnippetShortCutKeybindingState( 
            /* [out] */ BOOL *fBound) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsExpansionManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsExpansionManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsExpansionManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsExpansionManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumerateExpansions )( 
            IVsExpansionManager * This,
            /* [in] */ GUID guidLang,
            /* [in] */ BOOL fShortCutOnly,
            /* [size_is][in] */ BSTR *bstrTypes,
            /* [in] */ long iCountTypes,
            /* [in] */ BOOL fIncludeNULLType,
            /* [in] */ BOOL fIncludeDuplicates,
            /* [out] */ IVsExpansionEnumeration **pEnum);
        
        HRESULT ( STDMETHODCALLTYPE *InvokeInsertionUI )( 
            IVsExpansionManager * This,
            /* [in] */ IVsTextView *pView,
            /* [in] */ IVsExpansionClient *pClient,
            /* [in] */ GUID guidLang,
            /* [size_is][in] */ BSTR *bstrTypes,
            /* [in] */ long iCountTypes,
            /* [in] */ BOOL fIncludeNULLType,
            /* [size_is][in] */ BSTR *bstrKinds,
            /* [in] */ long iCountKinds,
            /* [in] */ BOOL fIncludeNULLKind,
            /* [in] */ BSTR bstrPrefixText,
            /* [in] */ BSTR bstrCompletionChar);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpansionByShortcut )( 
            IVsExpansionManager * This,
            /* [in] */ IVsExpansionClient *pClient,
            /* [in] */ GUID guidLang,
            /* [string][in] */ LPOLESTR szShortcut,
            /* [in] */ IVsTextView *pView,
            /* [in] */ TextSpan *pts,
            /* [in] */ BOOL fShowUI,
            /* [out] */ BSTR *pszExpansionPath,
            /* [out] */ BSTR *pszTitle);
        
        HRESULT ( STDMETHODCALLTYPE *GetTokenPath )( 
            IVsExpansionManager * This,
            /* [in] */ ExpansionToken token,
            /* [out] */ BSTR *pbstrPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetSnippetShortCutKeybindingState )( 
            IVsExpansionManager * This,
            /* [out] */ BOOL *fBound);
        
        END_INTERFACE
    } IVsExpansionManagerVtbl;

    interface IVsExpansionManager
    {
        CONST_VTBL struct IVsExpansionManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsExpansionManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsExpansionManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsExpansionManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsExpansionManager_EnumerateExpansions(This,guidLang,fShortCutOnly,bstrTypes,iCountTypes,fIncludeNULLType,fIncludeDuplicates,pEnum)	\
    (This)->lpVtbl -> EnumerateExpansions(This,guidLang,fShortCutOnly,bstrTypes,iCountTypes,fIncludeNULLType,fIncludeDuplicates,pEnum)

#define IVsExpansionManager_InvokeInsertionUI(This,pView,pClient,guidLang,bstrTypes,iCountTypes,fIncludeNULLType,bstrKinds,iCountKinds,fIncludeNULLKind,bstrPrefixText,bstrCompletionChar)	\
    (This)->lpVtbl -> InvokeInsertionUI(This,pView,pClient,guidLang,bstrTypes,iCountTypes,fIncludeNULLType,bstrKinds,iCountKinds,fIncludeNULLKind,bstrPrefixText,bstrCompletionChar)

#define IVsExpansionManager_GetExpansionByShortcut(This,pClient,guidLang,szShortcut,pView,pts,fShowUI,pszExpansionPath,pszTitle)	\
    (This)->lpVtbl -> GetExpansionByShortcut(This,pClient,guidLang,szShortcut,pView,pts,fShowUI,pszExpansionPath,pszTitle)

#define IVsExpansionManager_GetTokenPath(This,token,pbstrPath)	\
    (This)->lpVtbl -> GetTokenPath(This,token,pbstrPath)

#define IVsExpansionManager_GetSnippetShortCutKeybindingState(This,fBound)	\
    (This)->lpVtbl -> GetSnippetShortCutKeybindingState(This,fBound)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsExpansionManager_EnumerateExpansions_Proxy( 
    IVsExpansionManager * This,
    /* [in] */ GUID guidLang,
    /* [in] */ BOOL fShortCutOnly,
    /* [size_is][in] */ BSTR *bstrTypes,
    /* [in] */ long iCountTypes,
    /* [in] */ BOOL fIncludeNULLType,
    /* [in] */ BOOL fIncludeDuplicates,
    /* [out] */ IVsExpansionEnumeration **pEnum);


void __RPC_STUB IVsExpansionManager_EnumerateExpansions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionManager_InvokeInsertionUI_Proxy( 
    IVsExpansionManager * This,
    /* [in] */ IVsTextView *pView,
    /* [in] */ IVsExpansionClient *pClient,
    /* [in] */ GUID guidLang,
    /* [size_is][in] */ BSTR *bstrTypes,
    /* [in] */ long iCountTypes,
    /* [in] */ BOOL fIncludeNULLType,
    /* [size_is][in] */ BSTR *bstrKinds,
    /* [in] */ long iCountKinds,
    /* [in] */ BOOL fIncludeNULLKind,
    /* [in] */ BSTR bstrPrefixText,
    /* [in] */ BSTR bstrCompletionChar);


void __RPC_STUB IVsExpansionManager_InvokeInsertionUI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionManager_GetExpansionByShortcut_Proxy( 
    IVsExpansionManager * This,
    /* [in] */ IVsExpansionClient *pClient,
    /* [in] */ GUID guidLang,
    /* [string][in] */ LPOLESTR szShortcut,
    /* [in] */ IVsTextView *pView,
    /* [in] */ TextSpan *pts,
    /* [in] */ BOOL fShowUI,
    /* [out] */ BSTR *pszExpansionPath,
    /* [out] */ BSTR *pszTitle);


void __RPC_STUB IVsExpansionManager_GetExpansionByShortcut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionManager_GetTokenPath_Proxy( 
    IVsExpansionManager * This,
    /* [in] */ ExpansionToken token,
    /* [out] */ BSTR *pbstrPath);


void __RPC_STUB IVsExpansionManager_GetTokenPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionManager_GetSnippetShortCutKeybindingState_Proxy( 
    IVsExpansionManager * This,
    /* [out] */ BOOL *fBound);


void __RPC_STUB IVsExpansionManager_GetSnippetShortCutKeybindingState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsExpansionManager_INTERFACE_DEFINED__ */


#ifndef __IVsExpansion_INTERFACE_DEFINED__
#define __IVsExpansion_INTERFACE_DEFINED__

/* interface IVsExpansion */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsExpansion;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("798CC43B-7714-4dc1-925A-47863C24630D")
    IVsExpansion : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InsertExpansion( 
            /* [in] */ TextSpan tsContext,
            /* [in] */ TextSpan tsInsertPos,
            /* [in] */ IVsExpansionClient *pExpansionClient,
            /* [in] */ GUID guidLang,
            /* [out] */ IVsExpansionSession **pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertNamedExpansion( 
            /* [in] */ BSTR bstrTitle,
            /* [in] */ BSTR bstrPath,
            /* [in] */ TextSpan tsInsertPos,
            /* [in] */ IVsExpansionClient *pExpansionClient,
            /* [in] */ GUID guidLang,
            /* [in] */ BOOL fShowDisambiguationUI,
            /* [out] */ IVsExpansionSession **pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertSpecificExpansion( 
            /* [in] */ IXMLDOMNode *pSnippet,
            /* [in] */ TextSpan tsInsertPos,
            /* [in] */ IVsExpansionClient *pExpansionClient,
            /* [in] */ GUID guidLang,
            /* [in] */ BSTR pszRelativePath,
            /* [out] */ IVsExpansionSession **pSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsExpansionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsExpansion * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsExpansion * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsExpansion * This);
        
        HRESULT ( STDMETHODCALLTYPE *InsertExpansion )( 
            IVsExpansion * This,
            /* [in] */ TextSpan tsContext,
            /* [in] */ TextSpan tsInsertPos,
            /* [in] */ IVsExpansionClient *pExpansionClient,
            /* [in] */ GUID guidLang,
            /* [out] */ IVsExpansionSession **pSession);
        
        HRESULT ( STDMETHODCALLTYPE *InsertNamedExpansion )( 
            IVsExpansion * This,
            /* [in] */ BSTR bstrTitle,
            /* [in] */ BSTR bstrPath,
            /* [in] */ TextSpan tsInsertPos,
            /* [in] */ IVsExpansionClient *pExpansionClient,
            /* [in] */ GUID guidLang,
            /* [in] */ BOOL fShowDisambiguationUI,
            /* [out] */ IVsExpansionSession **pSession);
        
        HRESULT ( STDMETHODCALLTYPE *InsertSpecificExpansion )( 
            IVsExpansion * This,
            /* [in] */ IXMLDOMNode *pSnippet,
            /* [in] */ TextSpan tsInsertPos,
            /* [in] */ IVsExpansionClient *pExpansionClient,
            /* [in] */ GUID guidLang,
            /* [in] */ BSTR pszRelativePath,
            /* [out] */ IVsExpansionSession **pSession);
        
        END_INTERFACE
    } IVsExpansionVtbl;

    interface IVsExpansion
    {
        CONST_VTBL struct IVsExpansionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsExpansion_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsExpansion_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsExpansion_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsExpansion_InsertExpansion(This,tsContext,tsInsertPos,pExpansionClient,guidLang,pSession)	\
    (This)->lpVtbl -> InsertExpansion(This,tsContext,tsInsertPos,pExpansionClient,guidLang,pSession)

#define IVsExpansion_InsertNamedExpansion(This,bstrTitle,bstrPath,tsInsertPos,pExpansionClient,guidLang,fShowDisambiguationUI,pSession)	\
    (This)->lpVtbl -> InsertNamedExpansion(This,bstrTitle,bstrPath,tsInsertPos,pExpansionClient,guidLang,fShowDisambiguationUI,pSession)

#define IVsExpansion_InsertSpecificExpansion(This,pSnippet,tsInsertPos,pExpansionClient,guidLang,pszRelativePath,pSession)	\
    (This)->lpVtbl -> InsertSpecificExpansion(This,pSnippet,tsInsertPos,pExpansionClient,guidLang,pszRelativePath,pSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsExpansion_InsertExpansion_Proxy( 
    IVsExpansion * This,
    /* [in] */ TextSpan tsContext,
    /* [in] */ TextSpan tsInsertPos,
    /* [in] */ IVsExpansionClient *pExpansionClient,
    /* [in] */ GUID guidLang,
    /* [out] */ IVsExpansionSession **pSession);


void __RPC_STUB IVsExpansion_InsertExpansion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansion_InsertNamedExpansion_Proxy( 
    IVsExpansion * This,
    /* [in] */ BSTR bstrTitle,
    /* [in] */ BSTR bstrPath,
    /* [in] */ TextSpan tsInsertPos,
    /* [in] */ IVsExpansionClient *pExpansionClient,
    /* [in] */ GUID guidLang,
    /* [in] */ BOOL fShowDisambiguationUI,
    /* [out] */ IVsExpansionSession **pSession);


void __RPC_STUB IVsExpansion_InsertNamedExpansion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansion_InsertSpecificExpansion_Proxy( 
    IVsExpansion * This,
    /* [in] */ IXMLDOMNode *pSnippet,
    /* [in] */ TextSpan tsInsertPos,
    /* [in] */ IVsExpansionClient *pExpansionClient,
    /* [in] */ GUID guidLang,
    /* [in] */ BSTR pszRelativePath,
    /* [out] */ IVsExpansionSession **pSession);


void __RPC_STUB IVsExpansion_InsertSpecificExpansion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsExpansion_INTERFACE_DEFINED__ */


#ifndef __IVsExpansionSession_INTERFACE_DEFINED__
#define __IVsExpansionSession_INTERFACE_DEFINED__

/* interface IVsExpansionSession */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsExpansionSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3DFA7603-3B51-4484-81CD-FF1470123C7C")
    IVsExpansionSession : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EndCurrentExpansion( 
            /* [in] */ BOOL fLeaveCaret) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GoToNextExpansionField( 
            /* [in] */ BOOL fCommitIfLast) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GoToPreviousExpansionField( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFieldValue( 
            /* [in] */ BSTR bstrFieldName,
            /* [out] */ BSTR *pbstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFieldDefault( 
            /* [in] */ BSTR bstrFieldName,
            /* [in] */ BSTR bstrNewValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFieldSpan( 
            /* [in] */ BSTR bstrField,
            /* [out] */ TextSpan *ptsSpan) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHeaderNode( 
            /* [in] */ BSTR bstrNode,
            /* [out] */ IXMLDOMNode **pNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeclarationNode( 
            /* [in] */ BSTR bstrNode,
            /* [out] */ IXMLDOMNode **pNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSnippetNode( 
            /* [in] */ BSTR bstrNode,
            /* [out] */ IXMLDOMNode **pNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSnippetSpan( 
            /* [out] */ TextSpan *pts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEndSpan( 
            /* [in] */ TextSpan ts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEndSpan( 
            /* [out] */ TextSpan *pts) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsExpansionSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsExpansionSession * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsExpansionSession * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsExpansionSession * This);
        
        HRESULT ( STDMETHODCALLTYPE *EndCurrentExpansion )( 
            IVsExpansionSession * This,
            /* [in] */ BOOL fLeaveCaret);
        
        HRESULT ( STDMETHODCALLTYPE *GoToNextExpansionField )( 
            IVsExpansionSession * This,
            /* [in] */ BOOL fCommitIfLast);
        
        HRESULT ( STDMETHODCALLTYPE *GoToPreviousExpansionField )( 
            IVsExpansionSession * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFieldValue )( 
            IVsExpansionSession * This,
            /* [in] */ BSTR bstrFieldName,
            /* [out] */ BSTR *pbstrValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetFieldDefault )( 
            IVsExpansionSession * This,
            /* [in] */ BSTR bstrFieldName,
            /* [in] */ BSTR bstrNewValue);
        
        HRESULT ( STDMETHODCALLTYPE *GetFieldSpan )( 
            IVsExpansionSession * This,
            /* [in] */ BSTR bstrField,
            /* [out] */ TextSpan *ptsSpan);
        
        HRESULT ( STDMETHODCALLTYPE *GetHeaderNode )( 
            IVsExpansionSession * This,
            /* [in] */ BSTR bstrNode,
            /* [out] */ IXMLDOMNode **pNode);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeclarationNode )( 
            IVsExpansionSession * This,
            /* [in] */ BSTR bstrNode,
            /* [out] */ IXMLDOMNode **pNode);
        
        HRESULT ( STDMETHODCALLTYPE *GetSnippetNode )( 
            IVsExpansionSession * This,
            /* [in] */ BSTR bstrNode,
            /* [out] */ IXMLDOMNode **pNode);
        
        HRESULT ( STDMETHODCALLTYPE *GetSnippetSpan )( 
            IVsExpansionSession * This,
            /* [out] */ TextSpan *pts);
        
        HRESULT ( STDMETHODCALLTYPE *SetEndSpan )( 
            IVsExpansionSession * This,
            /* [in] */ TextSpan ts);
        
        HRESULT ( STDMETHODCALLTYPE *GetEndSpan )( 
            IVsExpansionSession * This,
            /* [out] */ TextSpan *pts);
        
        END_INTERFACE
    } IVsExpansionSessionVtbl;

    interface IVsExpansionSession
    {
        CONST_VTBL struct IVsExpansionSessionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsExpansionSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsExpansionSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsExpansionSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsExpansionSession_EndCurrentExpansion(This,fLeaveCaret)	\
    (This)->lpVtbl -> EndCurrentExpansion(This,fLeaveCaret)

#define IVsExpansionSession_GoToNextExpansionField(This,fCommitIfLast)	\
    (This)->lpVtbl -> GoToNextExpansionField(This,fCommitIfLast)

#define IVsExpansionSession_GoToPreviousExpansionField(This)	\
    (This)->lpVtbl -> GoToPreviousExpansionField(This)

#define IVsExpansionSession_GetFieldValue(This,bstrFieldName,pbstrValue)	\
    (This)->lpVtbl -> GetFieldValue(This,bstrFieldName,pbstrValue)

#define IVsExpansionSession_SetFieldDefault(This,bstrFieldName,bstrNewValue)	\
    (This)->lpVtbl -> SetFieldDefault(This,bstrFieldName,bstrNewValue)

#define IVsExpansionSession_GetFieldSpan(This,bstrField,ptsSpan)	\
    (This)->lpVtbl -> GetFieldSpan(This,bstrField,ptsSpan)

#define IVsExpansionSession_GetHeaderNode(This,bstrNode,pNode)	\
    (This)->lpVtbl -> GetHeaderNode(This,bstrNode,pNode)

#define IVsExpansionSession_GetDeclarationNode(This,bstrNode,pNode)	\
    (This)->lpVtbl -> GetDeclarationNode(This,bstrNode,pNode)

#define IVsExpansionSession_GetSnippetNode(This,bstrNode,pNode)	\
    (This)->lpVtbl -> GetSnippetNode(This,bstrNode,pNode)

#define IVsExpansionSession_GetSnippetSpan(This,pts)	\
    (This)->lpVtbl -> GetSnippetSpan(This,pts)

#define IVsExpansionSession_SetEndSpan(This,ts)	\
    (This)->lpVtbl -> SetEndSpan(This,ts)

#define IVsExpansionSession_GetEndSpan(This,pts)	\
    (This)->lpVtbl -> GetEndSpan(This,pts)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsExpansionSession_EndCurrentExpansion_Proxy( 
    IVsExpansionSession * This,
    /* [in] */ BOOL fLeaveCaret);


void __RPC_STUB IVsExpansionSession_EndCurrentExpansion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionSession_GoToNextExpansionField_Proxy( 
    IVsExpansionSession * This,
    /* [in] */ BOOL fCommitIfLast);


void __RPC_STUB IVsExpansionSession_GoToNextExpansionField_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionSession_GoToPreviousExpansionField_Proxy( 
    IVsExpansionSession * This);


void __RPC_STUB IVsExpansionSession_GoToPreviousExpansionField_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionSession_GetFieldValue_Proxy( 
    IVsExpansionSession * This,
    /* [in] */ BSTR bstrFieldName,
    /* [out] */ BSTR *pbstrValue);


void __RPC_STUB IVsExpansionSession_GetFieldValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionSession_SetFieldDefault_Proxy( 
    IVsExpansionSession * This,
    /* [in] */ BSTR bstrFieldName,
    /* [in] */ BSTR bstrNewValue);


void __RPC_STUB IVsExpansionSession_SetFieldDefault_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionSession_GetFieldSpan_Proxy( 
    IVsExpansionSession * This,
    /* [in] */ BSTR bstrField,
    /* [out] */ TextSpan *ptsSpan);


void __RPC_STUB IVsExpansionSession_GetFieldSpan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionSession_GetHeaderNode_Proxy( 
    IVsExpansionSession * This,
    /* [in] */ BSTR bstrNode,
    /* [out] */ IXMLDOMNode **pNode);


void __RPC_STUB IVsExpansionSession_GetHeaderNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionSession_GetDeclarationNode_Proxy( 
    IVsExpansionSession * This,
    /* [in] */ BSTR bstrNode,
    /* [out] */ IXMLDOMNode **pNode);


void __RPC_STUB IVsExpansionSession_GetDeclarationNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionSession_GetSnippetNode_Proxy( 
    IVsExpansionSession * This,
    /* [in] */ BSTR bstrNode,
    /* [out] */ IXMLDOMNode **pNode);


void __RPC_STUB IVsExpansionSession_GetSnippetNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionSession_GetSnippetSpan_Proxy( 
    IVsExpansionSession * This,
    /* [out] */ TextSpan *pts);


void __RPC_STUB IVsExpansionSession_GetSnippetSpan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionSession_SetEndSpan_Proxy( 
    IVsExpansionSession * This,
    /* [in] */ TextSpan ts);


void __RPC_STUB IVsExpansionSession_SetEndSpan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionSession_GetEndSpan_Proxy( 
    IVsExpansionSession * This,
    /* [out] */ TextSpan *pts);


void __RPC_STUB IVsExpansionSession_GetEndSpan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsExpansionSession_INTERFACE_DEFINED__ */


#ifndef __IVsMethodTipWindow2_INTERFACE_DEFINED__
#define __IVsMethodTipWindow2_INTERFACE_DEFINED__

/* interface IVsMethodTipWindow2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsMethodTipWindow2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E9E55E72-13BC-4362-B80A-A2EB33A75809")
    IVsMethodTipWindow2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NextMethod( 
            /* [out] */ BOOL *pfSuccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrevMethod( 
            /* [out] */ BOOL *pfSuccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOverloadCount( 
            long *piCount) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsMethodTipWindow2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsMethodTipWindow2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsMethodTipWindow2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsMethodTipWindow2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *NextMethod )( 
            IVsMethodTipWindow2 * This,
            /* [out] */ BOOL *pfSuccess);
        
        HRESULT ( STDMETHODCALLTYPE *PrevMethod )( 
            IVsMethodTipWindow2 * This,
            /* [out] */ BOOL *pfSuccess);
        
        HRESULT ( STDMETHODCALLTYPE *GetOverloadCount )( 
            IVsMethodTipWindow2 * This,
            long *piCount);
        
        END_INTERFACE
    } IVsMethodTipWindow2Vtbl;

    interface IVsMethodTipWindow2
    {
        CONST_VTBL struct IVsMethodTipWindow2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsMethodTipWindow2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsMethodTipWindow2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsMethodTipWindow2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsMethodTipWindow2_NextMethod(This,pfSuccess)	\
    (This)->lpVtbl -> NextMethod(This,pfSuccess)

#define IVsMethodTipWindow2_PrevMethod(This,pfSuccess)	\
    (This)->lpVtbl -> PrevMethod(This,pfSuccess)

#define IVsMethodTipWindow2_GetOverloadCount(This,piCount)	\
    (This)->lpVtbl -> GetOverloadCount(This,piCount)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsMethodTipWindow2_NextMethod_Proxy( 
    IVsMethodTipWindow2 * This,
    /* [out] */ BOOL *pfSuccess);


void __RPC_STUB IVsMethodTipWindow2_NextMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsMethodTipWindow2_PrevMethod_Proxy( 
    IVsMethodTipWindow2 * This,
    /* [out] */ BOOL *pfSuccess);


void __RPC_STUB IVsMethodTipWindow2_PrevMethod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsMethodTipWindow2_GetOverloadCount_Proxy( 
    IVsMethodTipWindow2 * This,
    long *piCount);


void __RPC_STUB IVsMethodTipWindow2_GetOverloadCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsMethodTipWindow2_INTERFACE_DEFINED__ */


#ifndef __IVsIntellisenseOptions_INTERFACE_DEFINED__
#define __IVsIntellisenseOptions_INTERFACE_DEFINED__

/* interface IVsIntellisenseOptions */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsIntellisenseOptions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("592346B2-C79C-4d3f-885A-3DA61899EE4B")
    IVsIntellisenseOptions : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetCompletorSize( 
            /* [in] */ long uSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompletorSize( 
            /* [out] */ long *uSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsIntellisenseOptionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsIntellisenseOptions * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsIntellisenseOptions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsIntellisenseOptions * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetCompletorSize )( 
            IVsIntellisenseOptions * This,
            /* [in] */ long uSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletorSize )( 
            IVsIntellisenseOptions * This,
            /* [out] */ long *uSize);
        
        END_INTERFACE
    } IVsIntellisenseOptionsVtbl;

    interface IVsIntellisenseOptions
    {
        CONST_VTBL struct IVsIntellisenseOptionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsIntellisenseOptions_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsIntellisenseOptions_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsIntellisenseOptions_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsIntellisenseOptions_SetCompletorSize(This,uSize)	\
    (This)->lpVtbl -> SetCompletorSize(This,uSize)

#define IVsIntellisenseOptions_GetCompletorSize(This,uSize)	\
    (This)->lpVtbl -> GetCompletorSize(This,uSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsIntellisenseOptions_SetCompletorSize_Proxy( 
    IVsIntellisenseOptions * This,
    /* [in] */ long uSize);


void __RPC_STUB IVsIntellisenseOptions_SetCompletorSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsIntellisenseOptions_GetCompletorSize_Proxy( 
    IVsIntellisenseOptions * This,
    /* [out] */ long *uSize);


void __RPC_STUB IVsIntellisenseOptions_GetCompletorSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsIntellisenseOptions_INTERFACE_DEFINED__ */


#ifndef __IVsColorizer2_INTERFACE_DEFINED__
#define __IVsColorizer2_INTERFACE_DEFINED__

/* interface IVsColorizer2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsColorizer2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("868A4381-537A-4d61-803C-301819CE2C2F")
    IVsColorizer2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BeginColorization( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndColorization( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsColorizer2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsColorizer2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsColorizer2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsColorizer2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *BeginColorization )( 
            IVsColorizer2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *EndColorization )( 
            IVsColorizer2 * This);
        
        END_INTERFACE
    } IVsColorizer2Vtbl;

    interface IVsColorizer2
    {
        CONST_VTBL struct IVsColorizer2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsColorizer2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsColorizer2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsColorizer2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsColorizer2_BeginColorization(This)	\
    (This)->lpVtbl -> BeginColorization(This)

#define IVsColorizer2_EndColorization(This)	\
    (This)->lpVtbl -> EndColorization(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsColorizer2_BeginColorization_Proxy( 
    IVsColorizer2 * This);


void __RPC_STUB IVsColorizer2_BeginColorization_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsColorizer2_EndColorization_Proxy( 
    IVsColorizer2 * This);


void __RPC_STUB IVsColorizer2_EndColorization_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsColorizer2_INTERFACE_DEFINED__ */


#ifndef __IVsExpansionEvents_INTERFACE_DEFINED__
#define __IVsExpansionEvents_INTERFACE_DEFINED__

/* interface IVsExpansionEvents */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsExpansionEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08107089-905F-47ab-989F-E365C5087402")
    IVsExpansionEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnAfterSnippetsUpdate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterSnippetsKeyBindingChange( 
            /* [in] */ DWORD dwCmdGuid,
            /* [in] */ DWORD dwCmdId,
            /* [in] */ BOOL fBound) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsExpansionEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsExpansionEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsExpansionEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsExpansionEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterSnippetsUpdate )( 
            IVsExpansionEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterSnippetsKeyBindingChange )( 
            IVsExpansionEvents * This,
            /* [in] */ DWORD dwCmdGuid,
            /* [in] */ DWORD dwCmdId,
            /* [in] */ BOOL fBound);
        
        END_INTERFACE
    } IVsExpansionEventsVtbl;

    interface IVsExpansionEvents
    {
        CONST_VTBL struct IVsExpansionEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsExpansionEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsExpansionEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsExpansionEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsExpansionEvents_OnAfterSnippetsUpdate(This)	\
    (This)->lpVtbl -> OnAfterSnippetsUpdate(This)

#define IVsExpansionEvents_OnAfterSnippetsKeyBindingChange(This,dwCmdGuid,dwCmdId,fBound)	\
    (This)->lpVtbl -> OnAfterSnippetsKeyBindingChange(This,dwCmdGuid,dwCmdId,fBound)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsExpansionEvents_OnAfterSnippetsUpdate_Proxy( 
    IVsExpansionEvents * This);


void __RPC_STUB IVsExpansionEvents_OnAfterSnippetsUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsExpansionEvents_OnAfterSnippetsKeyBindingChange_Proxy( 
    IVsExpansionEvents * This,
    /* [in] */ DWORD dwCmdGuid,
    /* [in] */ DWORD dwCmdId,
    /* [in] */ BOOL fBound);


void __RPC_STUB IVsExpansionEvents_OnAfterSnippetsKeyBindingChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsExpansionEvents_INTERFACE_DEFINED__ */


#ifndef __IVsLanguageLineIndent_INTERFACE_DEFINED__
#define __IVsLanguageLineIndent_INTERFACE_DEFINED__

/* interface IVsLanguageLineIndent */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsLanguageLineIndent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E5A25E79-4A3C-4fcb-B375-196F5E8D1B2D")
    IVsLanguageLineIndent : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetIndentPosition( 
            /* [in] */ IVsTextLayer *pBaseLayer,
            /* [in] */ long BaseBufferLineIndex,
            /* [out] */ long *pIndentPosition) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsLanguageLineIndentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsLanguageLineIndent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsLanguageLineIndent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsLanguageLineIndent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIndentPosition )( 
            IVsLanguageLineIndent * This,
            /* [in] */ IVsTextLayer *pBaseLayer,
            /* [in] */ long BaseBufferLineIndex,
            /* [out] */ long *pIndentPosition);
        
        END_INTERFACE
    } IVsLanguageLineIndentVtbl;

    interface IVsLanguageLineIndent
    {
        CONST_VTBL struct IVsLanguageLineIndentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsLanguageLineIndent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsLanguageLineIndent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsLanguageLineIndent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsLanguageLineIndent_GetIndentPosition(This,pBaseLayer,BaseBufferLineIndex,pIndentPosition)	\
    (This)->lpVtbl -> GetIndentPosition(This,pBaseLayer,BaseBufferLineIndex,pIndentPosition)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsLanguageLineIndent_GetIndentPosition_Proxy( 
    IVsLanguageLineIndent * This,
    /* [in] */ IVsTextLayer *pBaseLayer,
    /* [in] */ long BaseBufferLineIndex,
    /* [out] */ long *pIndentPosition);


void __RPC_STUB IVsLanguageLineIndent_GetIndentPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsLanguageLineIndent_INTERFACE_DEFINED__ */


#ifndef __IVsQueryUndoUnit_INTERFACE_DEFINED__
#define __IVsQueryUndoUnit_INTERFACE_DEFINED__

/* interface IVsQueryUndoUnit */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsQueryUndoUnit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("036FBE7A-9ABD-4894-B7F6-1ED3BD0EE247")
    IVsQueryUndoUnit : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ActionWouldBeAborted( 
            /* [out] */ BOOL *pbWouldBeAborted) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsQueryUndoUnitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsQueryUndoUnit * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsQueryUndoUnit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsQueryUndoUnit * This);
        
        HRESULT ( STDMETHODCALLTYPE *ActionWouldBeAborted )( 
            IVsQueryUndoUnit * This,
            /* [out] */ BOOL *pbWouldBeAborted);
        
        END_INTERFACE
    } IVsQueryUndoUnitVtbl;

    interface IVsQueryUndoUnit
    {
        CONST_VTBL struct IVsQueryUndoUnitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsQueryUndoUnit_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsQueryUndoUnit_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsQueryUndoUnit_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsQueryUndoUnit_ActionWouldBeAborted(This,pbWouldBeAborted)	\
    (This)->lpVtbl -> ActionWouldBeAborted(This,pbWouldBeAborted)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsQueryUndoUnit_ActionWouldBeAborted_Proxy( 
    IVsQueryUndoUnit * This,
    /* [out] */ BOOL *pbWouldBeAborted);


void __RPC_STUB IVsQueryUndoUnit_ActionWouldBeAborted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsQueryUndoUnit_INTERFACE_DEFINED__ */


#ifndef __IVsQueryUndoManager_INTERFACE_DEFINED__
#define __IVsQueryUndoManager_INTERFACE_DEFINED__

/* interface IVsQueryUndoManager */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsQueryUndoManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6ED9A1CD-E8FD-460a-8690-DD6E5E44B02D")
    IVsQueryUndoManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsLinkedTransactionOpen( 
            /* [out] */ BOOL *pbTransactionIsOpen) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsQueryUndoManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsQueryUndoManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsQueryUndoManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsQueryUndoManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLinkedTransactionOpen )( 
            IVsQueryUndoManager * This,
            /* [out] */ BOOL *pbTransactionIsOpen);
        
        END_INTERFACE
    } IVsQueryUndoManagerVtbl;

    interface IVsQueryUndoManager
    {
        CONST_VTBL struct IVsQueryUndoManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsQueryUndoManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsQueryUndoManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsQueryUndoManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsQueryUndoManager_IsLinkedTransactionOpen(This,pbTransactionIsOpen)	\
    (This)->lpVtbl -> IsLinkedTransactionOpen(This,pbTransactionIsOpen)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsQueryUndoManager_IsLinkedTransactionOpen_Proxy( 
    IVsQueryUndoManager * This,
    /* [out] */ BOOL *pbTransactionIsOpen);


void __RPC_STUB IVsQueryUndoManager_IsLinkedTransactionOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsQueryUndoManager_INTERFACE_DEFINED__ */


#ifndef __IPersistFileCheckSum_INTERFACE_DEFINED__
#define __IPersistFileCheckSum_INTERFACE_DEFINED__

/* interface IPersistFileCheckSum */
/* [object][uuid] */ 


EXTERN_C const IID IID_IPersistFileCheckSum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35355DA7-3EEA-452e-89F3-68344278F806")
    IPersistFileCheckSum : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CalculateCheckSum( 
            /* [in] */ REFGUID guidCheckSumAlgorithm,
            /* [in] */ DWORD cbBufferSize,
            /* [size_is][out] */ BYTE *pbHash,
            /* [out] */ DWORD *pcbActualSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistFileCheckSumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPersistFileCheckSum * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPersistFileCheckSum * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPersistFileCheckSum * This);
        
        HRESULT ( STDMETHODCALLTYPE *CalculateCheckSum )( 
            IPersistFileCheckSum * This,
            /* [in] */ REFGUID guidCheckSumAlgorithm,
            /* [in] */ DWORD cbBufferSize,
            /* [size_is][out] */ BYTE *pbHash,
            /* [out] */ DWORD *pcbActualSize);
        
        END_INTERFACE
    } IPersistFileCheckSumVtbl;

    interface IPersistFileCheckSum
    {
        CONST_VTBL struct IPersistFileCheckSumVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistFileCheckSum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistFileCheckSum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistFileCheckSum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistFileCheckSum_CalculateCheckSum(This,guidCheckSumAlgorithm,cbBufferSize,pbHash,pcbActualSize)	\
    (This)->lpVtbl -> CalculateCheckSum(This,guidCheckSumAlgorithm,cbBufferSize,pbHash,pcbActualSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPersistFileCheckSum_CalculateCheckSum_Proxy( 
    IPersistFileCheckSum * This,
    /* [in] */ REFGUID guidCheckSumAlgorithm,
    /* [in] */ DWORD cbBufferSize,
    /* [size_is][out] */ BYTE *pbHash,
    /* [out] */ DWORD *pcbActualSize);


void __RPC_STUB IPersistFileCheckSum_CalculateCheckSum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPersistFileCheckSum_INTERFACE_DEFINED__ */


#ifndef __IVsCodePageSelection_INTERFACE_DEFINED__
#define __IVsCodePageSelection_INTERFACE_DEFINED__

/* interface IVsCodePageSelection */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsCodePageSelection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("49539BFE-84DD-4b7e-8A82-B9E1C7639940")
    IVsCodePageSelection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShowEncodingDialog( 
            /* [in] */ LPCOLESTR pszFileName,
            /* [in] */ IVsUserData *pUserData) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCodePageSelectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCodePageSelection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCodePageSelection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCodePageSelection * This);
        
        HRESULT ( STDMETHODCALLTYPE *ShowEncodingDialog )( 
            IVsCodePageSelection * This,
            /* [in] */ LPCOLESTR pszFileName,
            /* [in] */ IVsUserData *pUserData);
        
        END_INTERFACE
    } IVsCodePageSelectionVtbl;

    interface IVsCodePageSelection
    {
        CONST_VTBL struct IVsCodePageSelectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCodePageSelection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCodePageSelection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCodePageSelection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCodePageSelection_ShowEncodingDialog(This,pszFileName,pUserData)	\
    (This)->lpVtbl -> ShowEncodingDialog(This,pszFileName,pUserData)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCodePageSelection_ShowEncodingDialog_Proxy( 
    IVsCodePageSelection * This,
    /* [in] */ LPCOLESTR pszFileName,
    /* [in] */ IVsUserData *pUserData);


void __RPC_STUB IVsCodePageSelection_ShowEncodingDialog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCodePageSelection_INTERFACE_DEFINED__ */


#ifndef __IVsTextLines2_INTERFACE_DEFINED__
#define __IVsTextLines2_INTERFACE_DEFINED__

/* interface IVsTextLines2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextLines2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("181B18A3-A0E8-436B-8AEF-500043C7CC78")
    IVsTextLines2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEolTypeEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ DWORD *piEolType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEolLengthEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ unsigned int *piEolType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEolTextEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ BSTR *pbstrEolText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextLines2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextLines2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextLines2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextLines2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolTypeEx )( 
            IVsTextLines2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ DWORD *piEolType);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolLengthEx )( 
            IVsTextLines2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ unsigned int *piEolType);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolTextEx )( 
            IVsTextLines2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ BSTR *pbstrEolText);
        
        END_INTERFACE
    } IVsTextLines2Vtbl;

    interface IVsTextLines2
    {
        CONST_VTBL struct IVsTextLines2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextLines2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextLines2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextLines2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextLines2_GetEolTypeEx(This,pld,piEolType)	\
    (This)->lpVtbl -> GetEolTypeEx(This,pld,piEolType)

#define IVsTextLines2_GetEolLengthEx(This,pld,piEolType)	\
    (This)->lpVtbl -> GetEolLengthEx(This,pld,piEolType)

#define IVsTextLines2_GetEolTextEx(This,pld,pbstrEolText)	\
    (This)->lpVtbl -> GetEolTextEx(This,pld,pbstrEolText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextLines2_GetEolTypeEx_Proxy( 
    IVsTextLines2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ DWORD *piEolType);


void __RPC_STUB IVsTextLines2_GetEolTypeEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextLines2_GetEolLengthEx_Proxy( 
    IVsTextLines2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ unsigned int *piEolType);


void __RPC_STUB IVsTextLines2_GetEolLengthEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextLines2_GetEolTextEx_Proxy( 
    IVsTextLines2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ BSTR *pbstrEolText);


void __RPC_STUB IVsTextLines2_GetEolTextEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextLines2_INTERFACE_DEFINED__ */


#ifndef __IVsTextLayer2_INTERFACE_DEFINED__
#define __IVsTextLayer2_INTERFACE_DEFINED__

/* interface IVsTextLayer2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextLayer2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1FE22AB1-40CA-45A0-BD56-7E65FA3B774C")
    IVsTextLayer2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEolTypeEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ DWORD *piEolType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEolLengthEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ unsigned int *piEolType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEolTextEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ BSTR *pbstrEolText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextLayer2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextLayer2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextLayer2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextLayer2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolTypeEx )( 
            IVsTextLayer2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ DWORD *piEolType);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolLengthEx )( 
            IVsTextLayer2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ unsigned int *piEolType);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolTextEx )( 
            IVsTextLayer2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ BSTR *pbstrEolText);
        
        END_INTERFACE
    } IVsTextLayer2Vtbl;

    interface IVsTextLayer2
    {
        CONST_VTBL struct IVsTextLayer2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextLayer2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextLayer2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextLayer2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextLayer2_GetEolTypeEx(This,pld,piEolType)	\
    (This)->lpVtbl -> GetEolTypeEx(This,pld,piEolType)

#define IVsTextLayer2_GetEolLengthEx(This,pld,piEolType)	\
    (This)->lpVtbl -> GetEolLengthEx(This,pld,piEolType)

#define IVsTextLayer2_GetEolTextEx(This,pld,pbstrEolText)	\
    (This)->lpVtbl -> GetEolTextEx(This,pld,pbstrEolText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextLayer2_GetEolTypeEx_Proxy( 
    IVsTextLayer2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ DWORD *piEolType);


void __RPC_STUB IVsTextLayer2_GetEolTypeEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextLayer2_GetEolLengthEx_Proxy( 
    IVsTextLayer2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ unsigned int *piEolType);


void __RPC_STUB IVsTextLayer2_GetEolLengthEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextLayer2_GetEolTextEx_Proxy( 
    IVsTextLayer2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ BSTR *pbstrEolText);


void __RPC_STUB IVsTextLayer2_GetEolTextEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextLayer2_INTERFACE_DEFINED__ */


#ifndef __IVsTextImage2_INTERFACE_DEFINED__
#define __IVsTextImage2_INTERFACE_DEFINED__

/* interface IVsTextImage2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextImage2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F86209FE-6BAA-40DC-AA5D-6C9E83B032B9")
    IVsTextImage2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEolTypeEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ DWORD *piEolType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEolLengthEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ unsigned int *piEolType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEolTextEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ BSTR *pbstrEolText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextImage2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextImage2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextImage2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextImage2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolTypeEx )( 
            IVsTextImage2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ DWORD *piEolType);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolLengthEx )( 
            IVsTextImage2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ unsigned int *piEolType);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolTextEx )( 
            IVsTextImage2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ BSTR *pbstrEolText);
        
        END_INTERFACE
    } IVsTextImage2Vtbl;

    interface IVsTextImage2
    {
        CONST_VTBL struct IVsTextImage2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextImage2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextImage2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextImage2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextImage2_GetEolTypeEx(This,pld,piEolType)	\
    (This)->lpVtbl -> GetEolTypeEx(This,pld,piEolType)

#define IVsTextImage2_GetEolLengthEx(This,pld,piEolType)	\
    (This)->lpVtbl -> GetEolLengthEx(This,pld,piEolType)

#define IVsTextImage2_GetEolTextEx(This,pld,pbstrEolText)	\
    (This)->lpVtbl -> GetEolTextEx(This,pld,pbstrEolText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextImage2_GetEolTypeEx_Proxy( 
    IVsTextImage2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ DWORD *piEolType);


void __RPC_STUB IVsTextImage2_GetEolTypeEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextImage2_GetEolLengthEx_Proxy( 
    IVsTextImage2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ unsigned int *piEolType);


void __RPC_STUB IVsTextImage2_GetEolLengthEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextImage2_GetEolTextEx_Proxy( 
    IVsTextImage2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ BSTR *pbstrEolText);


void __RPC_STUB IVsTextImage2_GetEolTextEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextImage2_INTERFACE_DEFINED__ */


#ifndef __IVsTextStorage2_INTERFACE_DEFINED__
#define __IVsTextStorage2_INTERFACE_DEFINED__

/* interface IVsTextStorage2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextStorage2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("92FE8718-09DF-4615-9BC8-492E67EEB1AB")
    IVsTextStorage2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetEolTypeEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ DWORD *piEolType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEolLengthEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ unsigned int *piEolType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEolTextEx( 
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ BSTR *pbstrEolText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionCookie( 
            /* [out] */ DWORD *pdwVersionCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextStorage2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextStorage2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextStorage2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextStorage2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolTypeEx )( 
            IVsTextStorage2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ DWORD *piEolType);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolLengthEx )( 
            IVsTextStorage2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ unsigned int *piEolType);
        
        HRESULT ( STDMETHODCALLTYPE *GetEolTextEx )( 
            IVsTextStorage2 * This,
            /* [in] */ const LINEDATAEX *pld,
            /* [out] */ BSTR *pbstrEolText);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionCookie )( 
            IVsTextStorage2 * This,
            /* [out] */ DWORD *pdwVersionCookie);
        
        END_INTERFACE
    } IVsTextStorage2Vtbl;

    interface IVsTextStorage2
    {
        CONST_VTBL struct IVsTextStorage2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextStorage2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextStorage2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextStorage2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextStorage2_GetEolTypeEx(This,pld,piEolType)	\
    (This)->lpVtbl -> GetEolTypeEx(This,pld,piEolType)

#define IVsTextStorage2_GetEolLengthEx(This,pld,piEolType)	\
    (This)->lpVtbl -> GetEolLengthEx(This,pld,piEolType)

#define IVsTextStorage2_GetEolTextEx(This,pld,pbstrEolText)	\
    (This)->lpVtbl -> GetEolTextEx(This,pld,pbstrEolText)

#define IVsTextStorage2_GetVersionCookie(This,pdwVersionCookie)	\
    (This)->lpVtbl -> GetVersionCookie(This,pdwVersionCookie)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextStorage2_GetEolTypeEx_Proxy( 
    IVsTextStorage2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ DWORD *piEolType);


void __RPC_STUB IVsTextStorage2_GetEolTypeEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextStorage2_GetEolLengthEx_Proxy( 
    IVsTextStorage2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ unsigned int *piEolType);


void __RPC_STUB IVsTextStorage2_GetEolLengthEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextStorage2_GetEolTextEx_Proxy( 
    IVsTextStorage2 * This,
    /* [in] */ const LINEDATAEX *pld,
    /* [out] */ BSTR *pbstrEolText);


void __RPC_STUB IVsTextStorage2_GetEolTextEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextStorage2_GetVersionCookie_Proxy( 
    IVsTextStorage2 * This,
    /* [out] */ DWORD *pdwVersionCookie);


void __RPC_STUB IVsTextStorage2_GetVersionCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextStorage2_INTERFACE_DEFINED__ */


#ifndef __IVsHiColorItem_INTERFACE_DEFINED__
#define __IVsHiColorItem_INTERFACE_DEFINED__

/* interface IVsHiColorItem */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsHiColorItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("16C240B3-4773-43c2-932A-1E8DD2F6F0F8")
    IVsHiColorItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetColorData( 
            /* [in] */ VSCOLORDATA cdElement,
            /* [out] */ COLORREF *pcrColor) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsHiColorItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsHiColorItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsHiColorItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsHiColorItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetColorData )( 
            IVsHiColorItem * This,
            /* [in] */ VSCOLORDATA cdElement,
            /* [out] */ COLORREF *pcrColor);
        
        END_INTERFACE
    } IVsHiColorItemVtbl;

    interface IVsHiColorItem
    {
        CONST_VTBL struct IVsHiColorItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsHiColorItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsHiColorItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsHiColorItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsHiColorItem_GetColorData(This,cdElement,pcrColor)	\
    (This)->lpVtbl -> GetColorData(This,cdElement,pcrColor)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsHiColorItem_GetColorData_Proxy( 
    IVsHiColorItem * This,
    /* [in] */ VSCOLORDATA cdElement,
    /* [out] */ COLORREF *pcrColor);


void __RPC_STUB IVsHiColorItem_GetColorData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsHiColorItem_INTERFACE_DEFINED__ */


#ifndef __IVsTextBufferEx_INTERFACE_DEFINED__
#define __IVsTextBufferEx_INTERFACE_DEFINED__

/* interface IVsTextBufferEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTextBufferEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9F0823E9-544D-4fa0-9400-0D602C9A510E")
    IVsTextBufferEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTrackChanges( 
            /* [out] */ BOOL *pfIsTracking) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTrackChangesSuppression( 
            /* [in] */ BOOL fSupress) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTextBufferExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTextBufferEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTextBufferEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTextBufferEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrackChanges )( 
            IVsTextBufferEx * This,
            /* [out] */ BOOL *pfIsTracking);
        
        HRESULT ( STDMETHODCALLTYPE *SetTrackChangesSuppression )( 
            IVsTextBufferEx * This,
            /* [in] */ BOOL fSupress);
        
        END_INTERFACE
    } IVsTextBufferExVtbl;

    interface IVsTextBufferEx
    {
        CONST_VTBL struct IVsTextBufferExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTextBufferEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTextBufferEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTextBufferEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTextBufferEx_GetTrackChanges(This,pfIsTracking)	\
    (This)->lpVtbl -> GetTrackChanges(This,pfIsTracking)

#define IVsTextBufferEx_SetTrackChangesSuppression(This,fSupress)	\
    (This)->lpVtbl -> SetTrackChangesSuppression(This,fSupress)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTextBufferEx_GetTrackChanges_Proxy( 
    IVsTextBufferEx * This,
    /* [out] */ BOOL *pfIsTracking);


void __RPC_STUB IVsTextBufferEx_GetTrackChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTextBufferEx_SetTrackChangesSuppression_Proxy( 
    IVsTextBufferEx * This,
    /* [in] */ BOOL fSupress);


void __RPC_STUB IVsTextBufferEx_SetTrackChangesSuppression_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTextBufferEx_INTERFACE_DEFINED__ */


#ifndef __IVsReadOnlyViewNotification_INTERFACE_DEFINED__
#define __IVsReadOnlyViewNotification_INTERFACE_DEFINED__

/* interface IVsReadOnlyViewNotification */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsReadOnlyViewNotification;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FC62B6C7-6E71-44c6-8DD8-016FD5952612")
    IVsReadOnlyViewNotification : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnDisabledEditingCommand( 
            /* [in][unique] */ const GUID *pguidCmdGuid,
            /* [in] */ DWORD dwCmdId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsReadOnlyViewNotificationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsReadOnlyViewNotification * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsReadOnlyViewNotification * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsReadOnlyViewNotification * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnDisabledEditingCommand )( 
            IVsReadOnlyViewNotification * This,
            /* [in][unique] */ const GUID *pguidCmdGuid,
            /* [in] */ DWORD dwCmdId);
        
        END_INTERFACE
    } IVsReadOnlyViewNotificationVtbl;

    interface IVsReadOnlyViewNotification
    {
        CONST_VTBL struct IVsReadOnlyViewNotificationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsReadOnlyViewNotification_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsReadOnlyViewNotification_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsReadOnlyViewNotification_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsReadOnlyViewNotification_OnDisabledEditingCommand(This,pguidCmdGuid,dwCmdId)	\
    (This)->lpVtbl -> OnDisabledEditingCommand(This,pguidCmdGuid,dwCmdId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsReadOnlyViewNotification_OnDisabledEditingCommand_Proxy( 
    IVsReadOnlyViewNotification * This,
    /* [in][unique] */ const GUID *pguidCmdGuid,
    /* [in] */ DWORD dwCmdId);


void __RPC_STUB IVsReadOnlyViewNotification_OnDisabledEditingCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsReadOnlyViewNotification_INTERFACE_DEFINED__ */


#ifndef __IVsOverrideTextViewAccessibilityState_INTERFACE_DEFINED__
#define __IVsOverrideTextViewAccessibilityState_INTERFACE_DEFINED__

/* interface IVsOverrideTextViewAccessibilityState */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsOverrideTextViewAccessibilityState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("805DB878-BC47-4149-862A-A12725DBC434")
    IVsOverrideTextViewAccessibilityState : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetOverrides( 
            /* [out] */ DWORD *pdwMask,
            /* [out] */ DWORD *pdwFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsOverrideTextViewAccessibilityStateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsOverrideTextViewAccessibilityState * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsOverrideTextViewAccessibilityState * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsOverrideTextViewAccessibilityState * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetOverrides )( 
            IVsOverrideTextViewAccessibilityState * This,
            /* [out] */ DWORD *pdwMask,
            /* [out] */ DWORD *pdwFlags);
        
        END_INTERFACE
    } IVsOverrideTextViewAccessibilityStateVtbl;

    interface IVsOverrideTextViewAccessibilityState
    {
        CONST_VTBL struct IVsOverrideTextViewAccessibilityStateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsOverrideTextViewAccessibilityState_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsOverrideTextViewAccessibilityState_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsOverrideTextViewAccessibilityState_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsOverrideTextViewAccessibilityState_GetOverrides(This,pdwMask,pdwFlags)	\
    (This)->lpVtbl -> GetOverrides(This,pdwMask,pdwFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsOverrideTextViewAccessibilityState_GetOverrides_Proxy( 
    IVsOverrideTextViewAccessibilityState * This,
    /* [out] */ DWORD *pdwMask,
    /* [out] */ DWORD *pdwFlags);


void __RPC_STUB IVsOverrideTextViewAccessibilityState_GetOverrides_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsOverrideTextViewAccessibilityState_INTERFACE_DEFINED__ */


#ifndef __IVsCanCoordinatorClipTextSpan_INTERFACE_DEFINED__
#define __IVsCanCoordinatorClipTextSpan_INTERFACE_DEFINED__

/* interface IVsCanCoordinatorClipTextSpan */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsCanCoordinatorClipTextSpan;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("215564F6-7007-4826-9384-9ED0E962DE27")
    IVsCanCoordinatorClipTextSpan : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShouldClipSpanToValidSpanInSecondaryBuffer( 
            /* [in] */ const IVsTextLines *pPrimaryBuffer,
            /* [in] */ const IVsTextLines *pSecondaryBuffer,
            /* [in] */ const TextSpan *ptsTextSpanInPrimaryBuffer,
            /* [out] */ BOOL *pfShouldClipTextSpan) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCanCoordinatorClipTextSpanVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCanCoordinatorClipTextSpan * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCanCoordinatorClipTextSpan * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCanCoordinatorClipTextSpan * This);
        
        HRESULT ( STDMETHODCALLTYPE *ShouldClipSpanToValidSpanInSecondaryBuffer )( 
            IVsCanCoordinatorClipTextSpan * This,
            /* [in] */ const IVsTextLines *pPrimaryBuffer,
            /* [in] */ const IVsTextLines *pSecondaryBuffer,
            /* [in] */ const TextSpan *ptsTextSpanInPrimaryBuffer,
            /* [out] */ BOOL *pfShouldClipTextSpan);
        
        END_INTERFACE
    } IVsCanCoordinatorClipTextSpanVtbl;

    interface IVsCanCoordinatorClipTextSpan
    {
        CONST_VTBL struct IVsCanCoordinatorClipTextSpanVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCanCoordinatorClipTextSpan_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCanCoordinatorClipTextSpan_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCanCoordinatorClipTextSpan_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCanCoordinatorClipTextSpan_ShouldClipSpanToValidSpanInSecondaryBuffer(This,pPrimaryBuffer,pSecondaryBuffer,ptsTextSpanInPrimaryBuffer,pfShouldClipTextSpan)	\
    (This)->lpVtbl -> ShouldClipSpanToValidSpanInSecondaryBuffer(This,pPrimaryBuffer,pSecondaryBuffer,ptsTextSpanInPrimaryBuffer,pfShouldClipTextSpan)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCanCoordinatorClipTextSpan_ShouldClipSpanToValidSpanInSecondaryBuffer_Proxy( 
    IVsCanCoordinatorClipTextSpan * This,
    /* [in] */ const IVsTextLines *pPrimaryBuffer,
    /* [in] */ const IVsTextLines *pSecondaryBuffer,
    /* [in] */ const TextSpan *ptsTextSpanInPrimaryBuffer,
    /* [out] */ BOOL *pfShouldClipTextSpan);


void __RPC_STUB IVsCanCoordinatorClipTextSpan_ShouldClipSpanToValidSpanInSecondaryBuffer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCanCoordinatorClipTextSpan_INTERFACE_DEFINED__ */

#endif /* __TextManagerInternal2_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


