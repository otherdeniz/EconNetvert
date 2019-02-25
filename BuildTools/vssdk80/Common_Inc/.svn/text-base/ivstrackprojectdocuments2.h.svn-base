

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for IVsTrackProjectDocuments2.idl:
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

#ifndef __IVsTrackProjectDocuments2_h__
#define __IVsTrackProjectDocuments2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsTrackProjectDocuments2_FWD_DEFINED__
#define __IVsTrackProjectDocuments2_FWD_DEFINED__
typedef interface IVsTrackProjectDocuments2 IVsTrackProjectDocuments2;
#endif 	/* __IVsTrackProjectDocuments2_FWD_DEFINED__ */


#ifndef __SVsTrackProjectDocuments_FWD_DEFINED__
#define __SVsTrackProjectDocuments_FWD_DEFINED__
typedef interface SVsTrackProjectDocuments SVsTrackProjectDocuments;
#endif 	/* __SVsTrackProjectDocuments_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "IVsTrackProjectDocumentsEvents2.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_IVsTrackProjectDocuments2_0000 */
/* [local] */ 

#pragma once
#pragma once


extern RPC_IF_HANDLE __MIDL_itf_IVsTrackProjectDocuments2_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IVsTrackProjectDocuments2_0000_v0_0_s_ifspec;

#ifndef __IVsTrackProjectDocuments2_INTERFACE_DEFINED__
#define __IVsTrackProjectDocuments2_INTERFACE_DEFINED__

/* interface IVsTrackProjectDocuments2 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsTrackProjectDocuments2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53544C4D-6639-11d3-a60d-005004775ab1")
    IVsTrackProjectDocuments2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BeginBatch( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndBatch( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Flush( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQueryAddFiles( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSQUERYADDFILEFLAGS rgFlags[  ],
            /* [out] */ VSQUERYADDFILERESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYADDFILERESULTS rgResults[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterAddFilesEx( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSADDFILEFLAGS rgFlags[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterAddFiles( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterAddDirectoriesEx( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirectories,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSADDDIRECTORYFLAGS rgFlags[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterAddDirectories( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirectories,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterRemoveFiles( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSREMOVEFILEFLAGS rgFlags[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterRemoveDirectories( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirectories,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSREMOVEDIRECTORYFLAGS rgFlags[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQueryRenameFiles( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
            /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
            /* [size_is][in] */ const VSQUERYRENAMEFILEFLAGS rgflags[  ],
            /* [out] */ VSQUERYRENAMEFILERESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYRENAMEFILERESULTS rgResults[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQueryRenameFile( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ LPCOLESTR pszMkOldName,
            /* [in] */ LPCOLESTR pszMkNewName,
            /* [in] */ VSRENAMEFILEFLAGS flags,
            /* [out] */ BOOL *pfRenameCanContinue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterRenameFiles( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
            /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
            /* [size_is][in] */ const VSRENAMEFILEFLAGS rgflags[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterRenameFile( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ LPCOLESTR pszMkOldName,
            /* [in] */ LPCOLESTR pszMkNewName,
            /* [in] */ VSRENAMEFILEFLAGS flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQueryRenameDirectories( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirs,
            /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
            /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
            /* [size_is][in] */ const VSQUERYRENAMEDIRECTORYFLAGS rgflags[  ],
            /* [out] */ VSQUERYRENAMEDIRECTORYRESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYRENAMEDIRECTORYRESULTS rgResults[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterRenameDirectories( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirs,
            /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
            /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
            /* [size_is][in] */ const VSRENAMEDIRECTORYFLAGS rgflags[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AdviseTrackProjectDocumentsEvents( 
            /* [in] */ IVsTrackProjectDocumentsEvents2 *pEventSink,
            /* [out] */ VSCOOKIE *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnadviseTrackProjectDocumentsEvents( 
            /* [in] */ VSCOOKIE dwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQueryAddDirectories( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirectories,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSQUERYADDDIRECTORYFLAGS rgFlags[  ],
            /* [out] */ VSQUERYADDDIRECTORYRESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYADDDIRECTORYRESULTS rgResults[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQueryRemoveFiles( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSQUERYREMOVEFILEFLAGS rgFlags[  ],
            /* [out] */ VSQUERYREMOVEFILERESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYREMOVEFILERESULTS rgResults[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQueryRemoveDirectories( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirectories,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSQUERYREMOVEDIRECTORYFLAGS rgFlags[  ],
            /* [out] */ VSQUERYREMOVEDIRECTORYRESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYREMOVEDIRECTORYRESULTS rgResults[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterSccStatusChanged( 
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const DWORD rgdwSccStatus[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTrackProjectDocuments2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTrackProjectDocuments2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTrackProjectDocuments2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *BeginBatch )( 
            IVsTrackProjectDocuments2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *EndBatch )( 
            IVsTrackProjectDocuments2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Flush )( 
            IVsTrackProjectDocuments2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnQueryAddFiles )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSQUERYADDFILEFLAGS rgFlags[  ],
            /* [out] */ VSQUERYADDFILERESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYADDFILERESULTS rgResults[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterAddFilesEx )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSADDFILEFLAGS rgFlags[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterAddFiles )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterAddDirectoriesEx )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirectories,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSADDDIRECTORYFLAGS rgFlags[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterAddDirectories )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirectories,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterRemoveFiles )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSREMOVEFILEFLAGS rgFlags[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterRemoveDirectories )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirectories,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSREMOVEDIRECTORYFLAGS rgFlags[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnQueryRenameFiles )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
            /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
            /* [size_is][in] */ const VSQUERYRENAMEFILEFLAGS rgflags[  ],
            /* [out] */ VSQUERYRENAMEFILERESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYRENAMEFILERESULTS rgResults[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnQueryRenameFile )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ LPCOLESTR pszMkOldName,
            /* [in] */ LPCOLESTR pszMkNewName,
            /* [in] */ VSRENAMEFILEFLAGS flags,
            /* [out] */ BOOL *pfRenameCanContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterRenameFiles )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
            /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
            /* [size_is][in] */ const VSRENAMEFILEFLAGS rgflags[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterRenameFile )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ LPCOLESTR pszMkOldName,
            /* [in] */ LPCOLESTR pszMkNewName,
            /* [in] */ VSRENAMEFILEFLAGS flags);
        
        HRESULT ( STDMETHODCALLTYPE *OnQueryRenameDirectories )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirs,
            /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
            /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
            /* [size_is][in] */ const VSQUERYRENAMEDIRECTORYFLAGS rgflags[  ],
            /* [out] */ VSQUERYRENAMEDIRECTORYRESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYRENAMEDIRECTORYRESULTS rgResults[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterRenameDirectories )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirs,
            /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
            /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
            /* [size_is][in] */ const VSRENAMEDIRECTORYFLAGS rgflags[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *AdviseTrackProjectDocumentsEvents )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsTrackProjectDocumentsEvents2 *pEventSink,
            /* [out] */ VSCOOKIE *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnadviseTrackProjectDocumentsEvents )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ VSCOOKIE dwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *OnQueryAddDirectories )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirectories,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSQUERYADDDIRECTORYFLAGS rgFlags[  ],
            /* [out] */ VSQUERYADDDIRECTORYRESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYADDDIRECTORYRESULTS rgResults[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnQueryRemoveFiles )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSQUERYREMOVEFILEFLAGS rgFlags[  ],
            /* [out] */ VSQUERYREMOVEFILERESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYREMOVEFILERESULTS rgResults[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnQueryRemoveDirectories )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cDirectories,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const VSQUERYREMOVEDIRECTORYFLAGS rgFlags[  ],
            /* [out] */ VSQUERYREMOVEDIRECTORYRESULTS *pSummaryResult,
            /* [size_is][out] */ VSQUERYREMOVEDIRECTORYRESULTS rgResults[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterSccStatusChanged )( 
            IVsTrackProjectDocuments2 * This,
            /* [in] */ IVsProject *pProject,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
            /* [size_is][in] */ const DWORD rgdwSccStatus[  ]);
        
        END_INTERFACE
    } IVsTrackProjectDocuments2Vtbl;

    interface IVsTrackProjectDocuments2
    {
        CONST_VTBL struct IVsTrackProjectDocuments2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTrackProjectDocuments2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTrackProjectDocuments2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTrackProjectDocuments2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTrackProjectDocuments2_BeginBatch(This)	\
    (This)->lpVtbl -> BeginBatch(This)

#define IVsTrackProjectDocuments2_EndBatch(This)	\
    (This)->lpVtbl -> EndBatch(This)

#define IVsTrackProjectDocuments2_Flush(This)	\
    (This)->lpVtbl -> Flush(This)

#define IVsTrackProjectDocuments2_OnQueryAddFiles(This,pProject,cFiles,rgpszMkDocuments,rgFlags,pSummaryResult,rgResults)	\
    (This)->lpVtbl -> OnQueryAddFiles(This,pProject,cFiles,rgpszMkDocuments,rgFlags,pSummaryResult,rgResults)

#define IVsTrackProjectDocuments2_OnAfterAddFilesEx(This,pProject,cFiles,rgpszMkDocuments,rgFlags)	\
    (This)->lpVtbl -> OnAfterAddFilesEx(This,pProject,cFiles,rgpszMkDocuments,rgFlags)

#define IVsTrackProjectDocuments2_OnAfterAddFiles(This,pProject,cFiles,rgpszMkDocuments)	\
    (This)->lpVtbl -> OnAfterAddFiles(This,pProject,cFiles,rgpszMkDocuments)

#define IVsTrackProjectDocuments2_OnAfterAddDirectoriesEx(This,pProject,cDirectories,rgpszMkDocuments,rgFlags)	\
    (This)->lpVtbl -> OnAfterAddDirectoriesEx(This,pProject,cDirectories,rgpszMkDocuments,rgFlags)

#define IVsTrackProjectDocuments2_OnAfterAddDirectories(This,pProject,cDirectories,rgpszMkDocuments)	\
    (This)->lpVtbl -> OnAfterAddDirectories(This,pProject,cDirectories,rgpszMkDocuments)

#define IVsTrackProjectDocuments2_OnAfterRemoveFiles(This,pProject,cFiles,rgpszMkDocuments,rgFlags)	\
    (This)->lpVtbl -> OnAfterRemoveFiles(This,pProject,cFiles,rgpszMkDocuments,rgFlags)

#define IVsTrackProjectDocuments2_OnAfterRemoveDirectories(This,pProject,cDirectories,rgpszMkDocuments,rgFlags)	\
    (This)->lpVtbl -> OnAfterRemoveDirectories(This,pProject,cDirectories,rgpszMkDocuments,rgFlags)

#define IVsTrackProjectDocuments2_OnQueryRenameFiles(This,pProject,cFiles,rgszMkOldNames,rgszMkNewNames,rgflags,pSummaryResult,rgResults)	\
    (This)->lpVtbl -> OnQueryRenameFiles(This,pProject,cFiles,rgszMkOldNames,rgszMkNewNames,rgflags,pSummaryResult,rgResults)

#define IVsTrackProjectDocuments2_OnQueryRenameFile(This,pProject,pszMkOldName,pszMkNewName,flags,pfRenameCanContinue)	\
    (This)->lpVtbl -> OnQueryRenameFile(This,pProject,pszMkOldName,pszMkNewName,flags,pfRenameCanContinue)

#define IVsTrackProjectDocuments2_OnAfterRenameFiles(This,pProject,cFiles,rgszMkOldNames,rgszMkNewNames,rgflags)	\
    (This)->lpVtbl -> OnAfterRenameFiles(This,pProject,cFiles,rgszMkOldNames,rgszMkNewNames,rgflags)

#define IVsTrackProjectDocuments2_OnAfterRenameFile(This,pProject,pszMkOldName,pszMkNewName,flags)	\
    (This)->lpVtbl -> OnAfterRenameFile(This,pProject,pszMkOldName,pszMkNewName,flags)

#define IVsTrackProjectDocuments2_OnQueryRenameDirectories(This,pProject,cDirs,rgszMkOldNames,rgszMkNewNames,rgflags,pSummaryResult,rgResults)	\
    (This)->lpVtbl -> OnQueryRenameDirectories(This,pProject,cDirs,rgszMkOldNames,rgszMkNewNames,rgflags,pSummaryResult,rgResults)

#define IVsTrackProjectDocuments2_OnAfterRenameDirectories(This,pProject,cDirs,rgszMkOldNames,rgszMkNewNames,rgflags)	\
    (This)->lpVtbl -> OnAfterRenameDirectories(This,pProject,cDirs,rgszMkOldNames,rgszMkNewNames,rgflags)

#define IVsTrackProjectDocuments2_AdviseTrackProjectDocumentsEvents(This,pEventSink,pdwCookie)	\
    (This)->lpVtbl -> AdviseTrackProjectDocumentsEvents(This,pEventSink,pdwCookie)

#define IVsTrackProjectDocuments2_UnadviseTrackProjectDocumentsEvents(This,dwCookie)	\
    (This)->lpVtbl -> UnadviseTrackProjectDocumentsEvents(This,dwCookie)

#define IVsTrackProjectDocuments2_OnQueryAddDirectories(This,pProject,cDirectories,rgpszMkDocuments,rgFlags,pSummaryResult,rgResults)	\
    (This)->lpVtbl -> OnQueryAddDirectories(This,pProject,cDirectories,rgpszMkDocuments,rgFlags,pSummaryResult,rgResults)

#define IVsTrackProjectDocuments2_OnQueryRemoveFiles(This,pProject,cFiles,rgpszMkDocuments,rgFlags,pSummaryResult,rgResults)	\
    (This)->lpVtbl -> OnQueryRemoveFiles(This,pProject,cFiles,rgpszMkDocuments,rgFlags,pSummaryResult,rgResults)

#define IVsTrackProjectDocuments2_OnQueryRemoveDirectories(This,pProject,cDirectories,rgpszMkDocuments,rgFlags,pSummaryResult,rgResults)	\
    (This)->lpVtbl -> OnQueryRemoveDirectories(This,pProject,cDirectories,rgpszMkDocuments,rgFlags,pSummaryResult,rgResults)

#define IVsTrackProjectDocuments2_OnAfterSccStatusChanged(This,pProject,cFiles,rgpszMkDocuments,rgdwSccStatus)	\
    (This)->lpVtbl -> OnAfterSccStatusChanged(This,pProject,cFiles,rgpszMkDocuments,rgdwSccStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_BeginBatch_Proxy( 
    IVsTrackProjectDocuments2 * This);


void __RPC_STUB IVsTrackProjectDocuments2_BeginBatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_EndBatch_Proxy( 
    IVsTrackProjectDocuments2 * This);


void __RPC_STUB IVsTrackProjectDocuments2_EndBatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_Flush_Proxy( 
    IVsTrackProjectDocuments2 * This);


void __RPC_STUB IVsTrackProjectDocuments2_Flush_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnQueryAddFiles_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cFiles,
    /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
    /* [size_is][in] */ const VSQUERYADDFILEFLAGS rgFlags[  ],
    /* [out] */ VSQUERYADDFILERESULTS *pSummaryResult,
    /* [size_is][out] */ VSQUERYADDFILERESULTS rgResults[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnQueryAddFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnAfterAddFilesEx_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cFiles,
    /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
    /* [size_is][in] */ const VSADDFILEFLAGS rgFlags[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnAfterAddFilesEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnAfterAddFiles_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cFiles,
    /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnAfterAddFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnAfterAddDirectoriesEx_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cDirectories,
    /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
    /* [size_is][in] */ const VSADDDIRECTORYFLAGS rgFlags[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnAfterAddDirectoriesEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnAfterAddDirectories_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cDirectories,
    /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnAfterAddDirectories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnAfterRemoveFiles_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cFiles,
    /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
    /* [size_is][in] */ const VSREMOVEFILEFLAGS rgFlags[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnAfterRemoveFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnAfterRemoveDirectories_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cDirectories,
    /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
    /* [size_is][in] */ const VSREMOVEDIRECTORYFLAGS rgFlags[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnAfterRemoveDirectories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnQueryRenameFiles_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cFiles,
    /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
    /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
    /* [size_is][in] */ const VSQUERYRENAMEFILEFLAGS rgflags[  ],
    /* [out] */ VSQUERYRENAMEFILERESULTS *pSummaryResult,
    /* [size_is][out] */ VSQUERYRENAMEFILERESULTS rgResults[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnQueryRenameFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnQueryRenameFile_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ LPCOLESTR pszMkOldName,
    /* [in] */ LPCOLESTR pszMkNewName,
    /* [in] */ VSRENAMEFILEFLAGS flags,
    /* [out] */ BOOL *pfRenameCanContinue);


void __RPC_STUB IVsTrackProjectDocuments2_OnQueryRenameFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnAfterRenameFiles_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cFiles,
    /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
    /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
    /* [size_is][in] */ const VSRENAMEFILEFLAGS rgflags[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnAfterRenameFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnAfterRenameFile_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ LPCOLESTR pszMkOldName,
    /* [in] */ LPCOLESTR pszMkNewName,
    /* [in] */ VSRENAMEFILEFLAGS flags);


void __RPC_STUB IVsTrackProjectDocuments2_OnAfterRenameFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnQueryRenameDirectories_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cDirs,
    /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
    /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
    /* [size_is][in] */ const VSQUERYRENAMEDIRECTORYFLAGS rgflags[  ],
    /* [out] */ VSQUERYRENAMEDIRECTORYRESULTS *pSummaryResult,
    /* [size_is][out] */ VSQUERYRENAMEDIRECTORYRESULTS rgResults[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnQueryRenameDirectories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnAfterRenameDirectories_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cDirs,
    /* [size_is][in] */ const LPCOLESTR rgszMkOldNames[  ],
    /* [size_is][in] */ const LPCOLESTR rgszMkNewNames[  ],
    /* [size_is][in] */ const VSRENAMEDIRECTORYFLAGS rgflags[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnAfterRenameDirectories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_AdviseTrackProjectDocumentsEvents_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsTrackProjectDocumentsEvents2 *pEventSink,
    /* [out] */ VSCOOKIE *pdwCookie);


void __RPC_STUB IVsTrackProjectDocuments2_AdviseTrackProjectDocumentsEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_UnadviseTrackProjectDocumentsEvents_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ VSCOOKIE dwCookie);


void __RPC_STUB IVsTrackProjectDocuments2_UnadviseTrackProjectDocumentsEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnQueryAddDirectories_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cDirectories,
    /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
    /* [size_is][in] */ const VSQUERYADDDIRECTORYFLAGS rgFlags[  ],
    /* [out] */ VSQUERYADDDIRECTORYRESULTS *pSummaryResult,
    /* [size_is][out] */ VSQUERYADDDIRECTORYRESULTS rgResults[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnQueryAddDirectories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnQueryRemoveFiles_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cFiles,
    /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
    /* [size_is][in] */ const VSQUERYREMOVEFILEFLAGS rgFlags[  ],
    /* [out] */ VSQUERYREMOVEFILERESULTS *pSummaryResult,
    /* [size_is][out] */ VSQUERYREMOVEFILERESULTS rgResults[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnQueryRemoveFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnQueryRemoveDirectories_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cDirectories,
    /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
    /* [size_is][in] */ const VSQUERYREMOVEDIRECTORYFLAGS rgFlags[  ],
    /* [out] */ VSQUERYREMOVEDIRECTORYRESULTS *pSummaryResult,
    /* [size_is][out] */ VSQUERYREMOVEDIRECTORYRESULTS rgResults[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnQueryRemoveDirectories_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTrackProjectDocuments2_OnAfterSccStatusChanged_Proxy( 
    IVsTrackProjectDocuments2 * This,
    /* [in] */ IVsProject *pProject,
    /* [in] */ int cFiles,
    /* [size_is][in] */ const LPCOLESTR rgpszMkDocuments[  ],
    /* [size_is][in] */ const DWORD rgdwSccStatus[  ]);


void __RPC_STUB IVsTrackProjectDocuments2_OnAfterSccStatusChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTrackProjectDocuments2_INTERFACE_DEFINED__ */


#ifndef __SVsTrackProjectDocuments_INTERFACE_DEFINED__
#define __SVsTrackProjectDocuments_INTERFACE_DEFINED__

/* interface SVsTrackProjectDocuments */
/* [object][uuid] */ 


EXTERN_C const IID IID_SVsTrackProjectDocuments;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53544C4D-1639-11d3-a60d-005004775ab1")
    SVsTrackProjectDocuments : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct SVsTrackProjectDocumentsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            SVsTrackProjectDocuments * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            SVsTrackProjectDocuments * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            SVsTrackProjectDocuments * This);
        
        END_INTERFACE
    } SVsTrackProjectDocumentsVtbl;

    interface SVsTrackProjectDocuments
    {
        CONST_VTBL struct SVsTrackProjectDocumentsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define SVsTrackProjectDocuments_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define SVsTrackProjectDocuments_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define SVsTrackProjectDocuments_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __SVsTrackProjectDocuments_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IVsTrackProjectDocuments2_0668 */
/* [local] */ 

#define SID_SVsTrackProjectDocuments IID_SVsTrackProjectDocuments


extern RPC_IF_HANDLE __MIDL_itf_IVsTrackProjectDocuments2_0668_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IVsTrackProjectDocuments2_0668_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


