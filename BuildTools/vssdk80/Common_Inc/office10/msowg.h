#pragma once

/*************************************************************************
 	msowg.h

 	Owner: mikel
 	Copyright (c) 1994-1996  Microsoft Corporation

	Header file for workgroup features.
*************************************************************************/

#ifndef MSOWG_H
#define MSOWG_H

#include "msoprops.h"		// summary info props

// Initialization

// Call MsoFInitLogging to initialize event logging.  Call MsoUninitLogging
//		when you're done.  Usually you'll want to do this at app startup and
//		shutdown.  You can set registry keys to turn off journaling by default.

MSOAPI_(HANDLE)		MsoFInitLogging(const WCHAR *wzHostName);
MSOAPI_(void)			MsoUninitLogging(HANDLE hRen);

// API to manipulate Ren items.

// NOTE:  If you want to do more, a handle to an Office Ren item is an IDispatch
//			 pointer to the Ren Item.

typedef enum _MSORNT				/* rnt - ReN Type */
	{
	msorntAppt, msorntContact, msorntLog, msorntMail, msorntNote, msorntTask,
	} MSORNT;

typedef enum _MSORBT				/* rbt - Ren Body Type */
	{
	msorbtNone = 0, msorbtStream, msorbtText,
	} MSORBT;

typedef struct _MSORND			/* rnd - ReN item Description */
	{
	UINT				cb;					// structure size
	MSORNT			rnt;					// Type of Ren Item desired
	LPCWSTR			wzTitle;				// Title for the task
	MSORBT			rbt;					// Type for Body Text - Stream, or Text
	union {
		IStream 		*pstmRTF;			// Rich text description, uncompressed
		LPCWSTR		wzPlain;				// Plain text
		};
	const WCHAR		*wzFileName;		// wzFileName for link
	LPMONIKER		lpmon;
	} MSORND, *PMSORND;

MSOAPI_(HANDLE)		MsoCreateRenItem(HANDLE hRen, PMSORND prnd);
MSOAPI_(BOOL)			MsoFLaunchRenItem(HANDLE hrni);
MSOAPIX_(BOOL)			MsoFUpdateRenItem(HANDLE hrni, PMSORND prnd);
MSOAPI_(void)			MsoReleaseRenItem(HANDLE hrni);

// Event logging
typedef enum _MSOEVT
	{
	msoevtNew, msoevtOpen, msoevtSave, msoevtSaveAs, msoevtRoute,
	msoevtPrint, msoevtClose, msoevtSend, msoevtPost
	} MSOEVT;

typedef struct _MSOFPR			/* fpr */
	{
	UINT		cb;					// structure size
	LPCWSTR	wzFileName;			// file name (as before)
	LPSIOBJ	lpSIObj;				// Returned from Office '95 summary info
	LPDSIOBJ	lpDSIObj;
	LPUDOBJ	lpUDObj;				
	} MSOFPR, *PMSOFPR;

// MsoLogDocumentEvent returns a hori of type Journal, which corresponds
//			to the document being journaled and should be used in subsequent
//			calls to this api for this document in the current session.

MSOAPI_(HANDLE)		MsoLogDocumentEvent(HANDLE hRen, HANDLE hori,
												MSOEVT evt, PMSOFPR pfpr);

// MsoSetLogState turns logging on/off, but does NOT affect documents that
//			are or aren't currently being journaled.
//
// The API will ignore fState if Outlook is not installed on the user's machine.
//

MSOAPI_(BOOL)			MsoFGetLogState(HANDLE hRen);
#ifdef UNUSED
MSOAPIX_(void)			MsoSetLogState(HANDLE hRen, BOOL fState);
#endif

#if VSMSODEBUG
MSOAPI_(BOOL)			MsoFWriteRenBe(HANDLE hRen, LPARAM lParam, BOOL fWriteSelf);
MSOAPI_(BOOL)			MsoFWriteRenItemBe(HANDLE hrni, LPARAM lParam, BOOL fWriteSelf);
#endif

// Read and write the USER ID stuff.  Owner SalimI.  Code is in wgusrdef.cpp.
MSOAPI_(BOOL) MsoFReadInfo(WCHAR *, int, WCHAR *, int, BOOL, HMSOINST hmsoinst);
MSOAPI_(BOOL) MsoFWriteInfo(const WCHAR *, const WCHAR *);

/*-----------------------------------------------------------------------------
	MSOAPI_ MsoFReadInfoEx

	Attempt to read Office user info, putting up UI if necessary.  Perform
	exhaustive check (verifying both Darwin and MSO info for completeness)
	if we haven't done it before for this app.  Will use cached information
	(not calling Darwin) on subsequent runs; call MsoFReadInfo if you 
	absolutely must have real, uncached, up-to-the-minute data.
	
	wzUserName must point to a buffer of at least msocchUsernameMax + 1.
	wzUserInitials must point to NULL or a buffer of at least msocchUserInitialsMax + 1.
	wzOrg must point to NULL OR a buffer of at least msocchCompanyMax + 1.
----------------------------------------------------------------- JoelDow ---*/
MSOAPI_(BOOL) MsoFReadInfoEx(WCHAR *wzUserName, WCHAR *wzUserInitials, WCHAR* wzOrg,
	BOOL fAlert, HMSOINST hmsoinst);

MSOAPI_(BOOL) MsoFReadDefInfo(WCHAR *wtzUserName, WCHAR *wtzUserInitials);
MSOAPI_(VOID) MsoPrivacyOOM(VOID);

//
//following stuff is for the 'Microsoft on the Web' feature
//author: NavPal
//

//_msowwwinfo is used for Exec www cmd
typedef struct _msowwwinfo
	{
	int cb; //size of this struct
	int imsowwwcmd;
	const WCHAR *pwzProductName;
	const WCHAR *pwzVer;
	const WCHAR *pwzSubProdName;
	const WCHAR *pwzFullProdName; //e.g. 'microsoft word' used only for imsowwwcmdLoadConv
	IMsoPref *pipref;//used only for imsowwwcmdLoadConv to get the custom info.
	}MSOWWWINFO;

#define cwzwww	10
//_msowwwinfo is used for GetCmdInfo
typedef struct _msowci
	{
	int imsowwwcmd;
	WCHAR *pwzName;
	BOOL fEnabled;//indicates whether this cmd should be enabled or not
	WCHAR *pwz[cwzwww];
	}MSOWCI;


//Web menu index chosen by user
#define	imsowwwcmd1	1
#define	imsowwwcmd2	2
#define	imsowwwcmd3	3
#define	imsowwwcmd4	4
#define	imsowwwcmd5	5
#define	imsowwwcmd6	6
#define	imsowwwcmd7	7
#define	imsowwwcmd8	8
#define	imsowwwcmd9	 9 
#define	imsowwwcmd10 10
#define	imsowwwcmd11 11
#define	imsowwwcmd12 12
#define	imsowwwcmd13 13
#define	imsowwwcmd14 14
#define	imsowwwcmd15 15
#define	imsowwwcmd16 16
#define imsowwwcmd17 17
#define imsowwwcmdMax (imsowwwcmd17+1)
#define imsowwwcmdProdMax (imsowwwcmd8+1)
#define cmsowwwcmdProdDefault 4
#define cmsowwwcmdOfficeDefault 5

#define imsowwwcmdLoadConv	-1	//used to call MsoFExecWWWHelp for loading a future ver converter

MSOAPI_(void) MsoGetWWWCmdInfo(int imsowwwcmd, IMsoPref *pipref_Unused, MSOWCI **ppmsowci, HMSOINST hmsoinst, BOOL fVB);
MSOAPI_(BOOL) MsoFExecWWWHelp(MSOWWWINFO *pmsowwwinfo, HMSOINST hmsoinst);
MSOAPI_(BOOL) MsoFExecWWWOffice(HMSOINST hmsoinst);
MSOAPI_(BOOL) MsoFNavUrl(HMSOINST hmsoinst, WCHAR *wzUrl);
MSOAPI_(BOOL) MsoFCanDoWWWHelp(HMSOINST hmsoinst);


#endif	// MSOWG_H

