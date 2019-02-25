#pragma once

#ifndef __offcapi_h__
#define __offcapi_h__
#pragma pack( push, mso95api, 4 )
//////////////////////////////////////////////////////////////////////////////
//  FILE   : OFFCAPI.H
//  PURPOSE: Client apps of office.dll include this file for structs and exports.
//  HOW TO USE:
//      Either you can link the office.lib (import lib) with your app
//      or you can LoadLibrary and GetProcAddress the reqd office routine.
//
// FEATURE LIST:
//  IntelliSearch 	(STATUS:	gone, now in mso96 )
//  Shared FileNew
//  Extended doc properties
//  Office Visual (cool title bar)
//  Threaded status indicator
//
//////////////////////////////////////////////////////////////////////////////

//#ifndef INC_OLE2
//#define INC_OLE2
//#include <windows.h>
//#include <objbase.h>
//#include <oleauto.h>
//#endif // INC_OLE2
#if defined(OFFICE_BUILD) || defined(LIME_BUILD)
#include <commctrl.h>
#include <shlobj.h>
#endif

#define DLLIMPORT __declspec(dllimport)
#define DLLEXPORT __declspec(dllexport)
#ifdef DLLBUILD
#define DLLFUNC DLLEXPORT
#define OFC_CALLTYPE _stdcall
#else // !DLLBUILD
#define DLLFUNC DLLIMPORT
#ifndef OFC_CALLTYPE
#define OFC_CALLTYPE __stdcall
#endif // OFC_CALLTYPE
#endif // DLLBUILD

//	Call back functions implemented by client apps (those will be passed to mso96(95).dll
//	as function pointers) must explicitly declare its calling convention using the
//	OFC_CALLBACK macro
//	TODO: 	Will investigate if we define OFC_CALLBACK as  MSOSTDAPICALLTYPE, they are
//			defined as the same except in Mac builds, (of course Mso95 doesn't have a Mac
//			build, yet)
//	PRIORITY:6
//	DIFFICULTY:1
#define OFC_CALLBACK __stdcall


//	Flags passed by client apps when calling the function MsoOffice()
enum
	{
	ioffcInit,
	ioffcGetVer,
	ioffcUninit,
	ioffcCanDoMSNConnect,
	ioffcDoMSNConnect
	};


//msomsninfo is used to communicate MSN connection related info.
//Use it when calling ioffcDoMSNConnection.
//Right now it just needs the hwnd of the apps main window and
//the sticky center of the dialog position

//_ver is used to get the office.dll version no. using MsoOffice(ioffcGetVer)
typedef struct _ver
	{
	long rmjV;
	long rmmV;
	long rupV;
	}VER;

typedef struct _msomsninfo
	{
	HWND hwnd;
	LPPOINT pptDlg;		// Center of the the dialog
	}MSOMSNINFO;

/*****************************************************************************
 * Mso95 API, 
 * following the Mso96 naming convention, Usually when strings are
 * involved in params and return values, a Unicode version and an ANSI code
 * version of the same API are proived, MsoFooA is the ANSI version, while both
 * MsoFooW and MsoFooU stand for Unicode version of the API
 *
 * MsoOffice(UINT ioffc, // input flag 
 *			 void *lpv); // opaque param
 *
 * Module: wgoffice.c
 ******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
#ifndef __SDM_INTERFACE__
#define Office MsoOffice
#endif
// BOGUS fix since fileopen doesn't provide memory leak check online
//#undef Office
//MSOAPI_(LRESULT) Office(UINT ioffc, void *lpv);

#ifdef NOTYET
#if !defined(_M_ALPHA) && !defined(_M_PPC) && !defined(_M_MIPS)
MSOAPI_(void *) MsoMemmove(void * pDest, const void * pSrc, size_t cb);
#endif
#endif	// NOTYET

MSOAPI_(LRESULT ) MsoOffice(UINT ioffc, void *lpv);
//It returns the message number that you will get for ISearch ghosting.
#ifdef __cplusplus
}; // extern "C"
#endif // __cplusplus


/***********************************************************************
MsOffice() is called with ioffc.

2) ioffc=ioffcUninit :: Performs the office.dll UNInitialisation/cleanup before
				quitting.Call this before closing your app.
-----------------
set lpv=NULL.
call Office(ioffcUninit,NULL).

3) ioffc=ioffcGetVer :: Use this to get the version number of the dll
----------------
set lpv=&ver
returns with all the fields of ver set.

4) ioffcCanDoMSNConnect
-----------------------
Call this to find out if you mso95 can do MSN connection or not. If 
Set lpv=NULL. This will return TRUE if we can do the MSN connection, false
otherwise. Grey the menu if false.

5) ioffcDoMSNConnect
--------------------
Call this to do the MSN connection by mso95.
Set msomsninfo.hwnd=Handle of your main window.
Set lpv=&msomsninfo. This will bring up the choose topic dialog and connect
the user to MSN if s/he selects connect.

***********************************************************************/

/////////////////////////////////////////////////////////////////////////
// Progress Report Thermometer (PRT) routines and data structure       //
/////////////////////////////////////////////////////////////////////////
/* Usage:                               
1.  Most of the functions are performed asynchronously, which means that
	your call causes a message to be sent to a (low-priority) thread,
	that later performs the operation you requested.  This implies that
	you don't really know when the thing your requested is going to happen.
	Thus, you should not touch the status line window until you are
	sure the thread is done painting in it.  Since this implies you need
	some synchronization, the EndPRT function (described below) is
	made synchronous--after it returns, you are guaranteed the thread
	will not touch the window until you call StartPRT again.
	
	All the functions except StartPRT are BOOL--they return TRUE in case of success
	and FALSE in case of failure.  StartPRT return NULL in case of failure.
	The kinds of failures that may occur are described below, next to each stub.

	Multiple progress report thermometers can be run in different windows
	at one time.

2.      A few notes on drawing:  the PRT functions do not validate any areas
	of your window, nor do they change any attributes of the Device Context
	for the window that you pass in to StartPRT or they get with GetDC (which
	they do if the hdc you pass in to StartPRT is NULL).  So, if you want the
	device context attributes (e.g., font) to other than standard,
	you have to take care of that.  UpdatePRT assumes the window has
	been untouched since the last PRT call (i.e., it draws the minimum
	needed).  RedrawPRT and StartPRT repaint the whole window.

3.  The data structure. As there are variables my functions need to share
	and access, and we can't package them into a class (as we are working
	in C, not in C++), for every instance of a progress indicator we
	allocate a data structure in StartPRT, whose pointer will always
	be the first argument UpdatePRT, RedrawPRT and EndPRT.
	The data structure's name is PRT; the application need
	not worry/know about what the data structure contains.  All it needs
	to do is save its pointer (of type LPPRT) returned by StartPRT and keep
	it around until calling EndPRT.  EndPRT will free it.
																	
4.  StartPRT.  To be called every time you need a new progress report.
	Redraws the window completely, putting eveyrthing needed into it.
	Aside from the pointer to PRT structure, takes:
	1) HWND hwnd--the handle to the window where the progress report
		needs to appear.  UNTIL CALLING EndPRT, THE APPLICATION SHOULD
		NOT TOUCH THIS WINDOW.  See RedrawPRT for information on how
		to process WM_PAINT messages to it.
	2) HDC hdc--optional handle to the window's client area device context, with the
		attributes you want selected into it (you cannot change the text
		background color, because the window has to be all background
		cvBtnFace.  All the other attributes can be changed).  If it is NULL,
		we will get the DC by GetDC(hwnd) every time we draw and release it when
		done drawing.  See also "A Few Notes on Drawing" above.
	2) WORD nMost--the number of "little things" it has to accomplish.
		Used a scaling factor--i.e., the progress report tells the user
		that nDone/nMost things are done.  The user will not have
		any idea what nMost is, since the ratio nDone/nMost is all
		that is reflected in the indicator.  E.g., if the application has
		37 disk blocks to write (assuming every write takes about the
		same time), nMost should be 37.
	3) lpszTitle. A string, to appear as a title to the left of the
		progress indicator.  E.g., "Saving the data:"  Note that the string
		has to remain unchanged and readable until the call to EndPRT for
		that instance.
    4) WORD nFrame -- This is a bitfield that indicates which sides of the
	    status bar should be painted with a 3D style side. Use the PRT_FRAME_?
		macros to select the side. Use PRT_FRAM_HIDE to do not want a fram. Use
		PRT_FRAME_SHOW if you want a complete frame around the status bar. Note
		that you want to use PRT_FRAME_TOP if you are displaying the status
		barat the bottom of the window, because the window border itself will
		provide the left, right and bottom side of the status bar.
	
	Returns the pointer to the new prt data structure
	(see "The Data Structure" above).
	Fails and returns NULL if:
	1) Cannot allocate the new data structure.
	2) For some strange reason synchronization failed or it was not able
		to communicate to the thread.
	
5.  UpdatePRT.  To be called whenever you've made some progress.  Aside
	from the pointer to PRT structure, takes one argument--WORD nDone,
	which is to indicate how much you accomplished.  In order for
	things to work well, nDone should be not greater than nMost and
	at least as big as nDone with which you previously called us
	(after all, we are a progress indicator, not a regress indicator).
    If nDone is greater than nMost, it will force nDone to equal nMost,
	i.e., simply fill up the indicator to its capacity.
	
	Assumes the window hasn't been touched since the last PRT call--i.e.,
	draws the minimum needed to indicate the change.

	Returns FALSE if:
	1) The pointer to the PRT was not writeable.
	2) it had trouble communicating with the thread.

6.  RedrawPRT.  To be called whenever you need the window repainted
	(remember, the application is not allowed to touch the window),
	i.e., whenever you get the WM_PAINT message for that window.  Make
	sure to validate the rectangle by calling BeginPaint--EndPaint before
	that (otherwise you will keep getting WM_PAINT messages RedrawPRT
	doesn't validate anything).  Redraws the entire window--the little
	white line on top, the title and the thermometer.  Takes no arguments
	other than the pointer to PRT.

	Returns FALSE if:
	1) The pointer to the PRT was not writeable.
	2) it had trouble communicating with the thread.

7.  AdjustPRT. To be called when either one of the input parameters of
    StartPRT are to be changed, i.e. the title, the hdc, and/or the
    progress extent (nMost). Use zero or NULL to keep the existing
	value, e.g. AdjustPRT(lpprt, NULL, 0, "xyz") will only change the
	title. Note that this api will only change the internal state of
	the progress bar. A call to RedrawPRT() or      UpdatePRT() may be
	needed to updated the screen, depending on the input parameters: 
    
    1) Title and HDC: RedrawPRT() must be called to force the change
	to be updated on the screen.  
    
    2) nMost: RedrawPRT() is not needed, as the next call to UpdatePRT()
    will use the new value. Note that changing this value will not
    result in that a fewer number of boxes is painted when UpdatePRT() is
    called, even if nMost is increased. Use RedrawPRT() to completely redraw
    the progress bar with the correct (possibly shortened) length.

8.  EndPRT.  To be called when you don't want the progress report any more,
	and need to draw in the window.  Is the only
	synchronous procedure--doesn't return until it is sure the thread
	will not touch the window any more.  Thus, you might have to wait
	a little bit for the thread to finish painting.  But, if it
	succeeded, you are guaranteed that the thread will not mess with the
	window any more.

	Takes no arguments other than the pointer to PRT.  Frees that pointer.

	Returns FALSE if:
	1) The pointer to the PRT was not writeable.
	2) It has trouble communticating with the thread, or if it had to wait
	for the thread to finish painting for more than PRT_WAIT_TIMEOUT
	milliseconds (in which case it gives up waiting).  You are NOT
	guaranteed that the thread will not touch your window if EndPRT
	returned FALSE.
*/

/* Data structure where PRT stores its info */
typedef struct tagPRT * LPPRT;

#define PRT_FRAME_LEFT          0x01
#define PRT_FRAME_RIGHT         0x02
#define PRT_FRAME_TOP           0x04
#define PRT_FRAME_BOTTOM        0x08
#define PRT_FRAME_HIDE          0x00
#define PRT_FRAME_SHOW          (PRT_FRAME_LEFT|PRT_FRAME_TOP|PRT_FRAME_RIGHT|PRT_FRAME_BOTTOM)


/*****************************************************************************
 * Mso95 API, 
 * following the Mso96 naming convention, Usually when strings are
 * involved in params and return values, a Unicode version and an ANSI code
 * version of the same API are proived, MsoFooA is the ANSI version, while both
 * MsoFooW and MsoFooU stand for Unicode version of the API
 *
 * Module: wgprt.c
 *
 *****************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
#ifndef __SDM_INTERFACE__
#define StartPRT MsoStartPRT
#endif
MSOAPI_(LPPRT ) MsoStartPRT(HWND hwnd, HDC hdc,
					const DWORD nMost, LPCWSTR lpwzTitle,
										const WORD nFrame);
MSOAPI_(LPPRT) MsoStartPRTA(HWND hwnd, HDC hdc, 
							const DWORD nMost, LPCSTR lpszTilte,
							const WORD nFrame);

#ifndef __SDM_INTERFACE__
#define UpdatePRT MsoUpdatePRT
#endif
MSOAPI_(BOOL  ) MsoUpdatePRT(LPPRT lpprt, const DWORD nDone);

#ifndef __SDM_INTERFACE__
#define RedrawPRT MsoRedrawPRT
#endif
MSOAPI_(BOOL  ) MsoRedrawPRT(LPPRT lpprt);

#ifndef __SDM_INTERFACE__
#define AdjustPRT MsoAdjustPRTW
#endif
MSOAPI_(BOOL  ) MsoAdjustPRT(LPPRT lprrt, HDC hdc,
					 const DWORD nMost,
										 LPCWSTR lpwzTitle,
										 const WORD nFrame);

#ifndef __SDM_INTERFACE__
#define EndPRT MsoEndPRT
#endif
MSOAPI_(BOOL  ) MsoEndPRT(LPPRT lpprt);
#ifdef __cplusplus
}; //Extern "C"
#endif


#ifdef TASKBTN
/*-------------------------------------------------------------------------
   Task bar button Functions
--------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
MSOAPI_(BOOL ) MsoMDIInit(void);
MSOAPI_(BOOL ) MsoMDICleanUp(void);
MSOAPI_(HWND ) MsoMDIChildCreate(HWND hwndAssoc);
MSOAPI_(void ) MsoMDIChildDestroy(HWND hwndBtn);
MSOAPI_(void ) MsoMDIChildActive(HWND hwndBtn);
MSOAPI_(void ) MsoMDIChildDestroy(HWND hwndBtn);

#define MsoMDIChildSetText(hwnd, txt) SetWindowText(hwnd, txt)
#define MsoMDIChildSetIcon(hwnd, hi) SendMessage(hwnd, WM_SETICON, 0, hi)

#ifdef __cplusplus
}; // extern "C"
#endif // __cplusplus
#endif


/*--------------------------------------------------------------------------------
|
| This function will return the hwnd of the current Office dialog (Properties,
| File New, Post To Exchange, etc)
|
| If an Office alert (message box) is up, the function will return 0xFFFFFFFF.
|
| If no Office alert or dialog is up, the function will return NULL.
|
|--------------------------------------------------------------------------------*/
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

MSOAPI_(HWND ) MsoHwndDlgCur();

MSOMACAPI_(BOOL) FEnsureMso5Intl( void );

#ifdef __cplusplus
}; // extern "C"
#endif // __cplusplus
#pragma pack( pop, mso95api )

#endif // __offcapi_h__

