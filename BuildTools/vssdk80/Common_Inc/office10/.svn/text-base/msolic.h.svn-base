/****************************************************************************
	Msolic.h

	Owner: EricWong/MikeKell
 	Copyright (c) 1999 Microsoft Corporation

	Declarations for functions related to product licensing
****************************************************************************/

#pragma once

#ifndef MSOLIC_H
#define MSOLIC_H 1


/*---------------------------------------------------------------------------
	IMsoLicenseUser callback for License clients.  MSO clients that
	support annuity licenses or trial versions must implement this
	interface to enable communication between the MSO code that enforces
	licenses and the application clients.
----------------------------------------------------------------- MikeKell -*/

#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoLicenseUser

DECLARE_INTERFACE(IMsoLicenseUser)
{

	/* Debugging interface for this interface */
	MSODEBUGMETHOD

	/* FDisableApp is called by the MSO licensing code when license
	   expiration is detected.  The application should use this 
	   callback to effectively degrade app behavior to a 'viewer',
	   i.e. do not allow creation of new documents or content, and
	   do not allow editing of existing documents or content.  The
	   application should allow documents to be opened and printed. */
		
	MSOMETHOD_(BOOL, FDisableApp) (THIS_ BOOL fDisabled) PURE;

	/* FEnumDisabledTcids is called to allow the application to provide
	   app-specific TCIDs to disable when the application is being
	   disabled.  You should return TRUE as long as you have more
	   TCIDs and set tcid to the TCID to be disabled. itcid will increase
	   with each call.  */
	MSOMETHOD_(BOOL, FEnumDisabledTcids) (THIS_ unsigned itcid, int *ptcid) PURE;

	/* FEnumDisabledKeys is called to allow the application to provide
	   app-specific keyboard keys to disable when the application is being
	   disabled.  You should return TRUE as long as you have more
	   keys and set pnVK to the keycode to be disabled, including any modifiers
	   (shift, alt, control). itcid will increase with each call.  E.G.

	   	*pnVK = MAKELONG(VK_F11, FCONTROL | FSHIFT);		// Alt-Shift-F11

		disables Alt-Shift-F11
		
	   */
	MSOMETHOD_(BOOL, FEnumDisabledKeys) (THIS_ unsigned ikey, int *pnVK) PURE;

	/* HrUpdateCounter is called for the application set or get its counter count */
	
	// Counter Type can be assumed to only use the 0xff size of the iType
	MSOMETHOD_(HRESULT, HrUpdateCounter) (THIS_ unsigned iType, BOOL fSet, int *piCount) PURE;

	/* FOverrideDPCFeature allows the app to specify a different featurename to use for the 
		DPC MsiReinstallFeature call.  The size of the wzFeature buffer is MAX_PATH.
	*/
	MSOMETHOD_(BOOL, FOverrideDPCFeature) (THIS_ WCHAR* wzFeature) PURE;

};

#endif // MSO_NO_INTERFACES

/****************************************************************************
	Defines the IMsoLicense interface

	This interface is the core interface for all licensing interaction between the
	application and MSO.  It is created with MsoFInitLicensing. 
**************************************************************** MIKEKELL **/

#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoLicense

DECLARE_INTERFACE_(IMsoLicense, ISimpleUnknown)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	/* Debugging interface for this interface */
	MSODEBUGMETHOD

	/* Terminate yourself.  No refcounting, so always returns zero. */
	MSOMETHOD_(ULONG, Release) (THIS) PURE;
	
	/* FAppDisabled says whether the app should be disabled. */
		
	MSOMETHOD_(BOOL, FAppDisabled) (THIS) PURE;

	/* FTcidDisabled allows querying for whether a given msotcid is in the
	   disabled list.  This includes both the tcids that Office disables as 
	   well as app-specific ones provided through 
	   IMsoLicenseUser::FEnumDisabledTcids */
	MSOMETHOD_(BOOL, FTcidDisabled) (THIS_ int tcid) PURE;

	/* AddDisabledAccelerators allows the app to specify disabled keystrokes
	   as an accelerator table loaded from a resource rather than one by one
	   in the IMsoLicenseUser::FEnumDisabledKeys callback.  Both can be used
	   together if desired, i.e. the app can provide some through the callback and
	   others (e.g. the ones that are localized) with the accelerator table. The
	   app should not free the HANDLE passed in, it needs to have a lifetime of
	   the IMsoLicense (this will be true if you use LoadAccelerators to create the handle).
	   If you use CopyAcceleratorTable or CreateAcceleratorTable to create the
	   table, you should not call DestroyAcceleratorTable until you destroy the
	   IMsoLicense object by calling IMsoLicense::Release.
	 */
	MSOMETHOD_(void, AddDisabledAccelerators) (THIS_ HACCEL haccel) PURE;

	/* NotifyVisible allows the app to notify Mso that it is becoming visible to
	the user.  This notification allows licensing tasks to be performed when the
	app is operating as an out of proc OLE server. */
	MSOMETHOD_(void, NotifyVisible) (THIS) PURE;

	/* ForceLicenseValidationNow allows applications to force license validation
	to occur now.  This is intended for use when the app would like to
	run license validation before it has started processing idles (e.g. during a first 
	run boot; see Office10.252482.
	Note that this can bring up SDM UI(for multiple product dialog) and, if you
	pass in fShowWizardImmediately, it will also bring up the license wizard before
	returning.  Even if you pass fShowWizardImmediately as FALSE (recommended for security
	reasons) you will be notified on IMsoLicenseUser if you are disabled prior to this method
	returning, so you can do appropriate things at boot based on being in RFM. 
	If you pass FALSE for fShowWizardImmediately, the wizard will be shown at idle as
	normal, but you will know immediately if you are disabled.  */
	MSOMETHOD_(void, ForceLicenseValidationNow) (THIS_ BOOL fShowWizardImmediately) PURE;

	/* FEnsureAppCanRun
	   See Office10.223807.  This prevents running applications which should be
	   disabled through OLE Automation.
	*/
	MSOMETHOD_(BOOL, FEnsureAppCanRun) (THIS) PURE;

	/* SetWizardURL allows applications to override the default starting URL of the Activation Wizard
	   (default is MSOINTL.DLL/lwframe.htm)
	*/
	MSOMETHOD_(BOOL, FSetWizardURL) (THIS_ WCHAR* wzURL) PURE;
};
#endif // MSO_NO_INTERFACES


/*---------------------------------------------------------------------------
	MsoFInitLicensing

	Do initialization needed for licensing.  This allows the application
	to pass its IMsoLicenseUser.  This starts the license validation.  Note that this must
	have been called by first idle or the app will crash (to avoid having a simple hack
	be that you just patch in the app the call to MsoFInitLicensing).

	The MsoFInitLicensingEx version provides an additional flag (fOleLaunch) which
	indicates that the calling app is being launched as an OLE server.  This has the
	effect of performing minimal init at boot and deferring all unnecessary licensing
	operations until the app informs Mso that it is ready to perform licensing via
	IMsoLicense::NotifyVisible().

	See IMsoLicenseUser above for description of pilu. 
        You must implement this interface.
----------------------------------------------------------------- MikeKell -*/
#define MsoFInitLicensing(hinst,pilu,ppiml) MsoFInitLicensingEx((hinst),(pilu),(ppiml),FALSE)

MSOAPI_(BOOL) MsoFInitLicensingEx(HMSOINST hinst,
								  IMsoLicenseUser *pilu,
								  interface IMsoLicense **ppiml,
								  BOOL fOleLaunch);




/*----------------------------------------------------------------------------
	MSOAPI_(HRESULT) MsoLicenseVerification(HMSOINST hinst, HWND hwndOwner)

	Callback for Help|Registration menu items in apps
------------------------------------------------------------------- VadimC -*/
MSOAPI_(HRESULT) MsoLicenseVerification(HMSOINST hinst, HWND hwndOwner);


/*----------------------------------------------------------------------------*\
	MSOAPI_(BOOL) MsoFLicenseCDAutorun(char* szProductCode);

	Performs license validation, selects product using the product code,
	then launches the wizard
\*------------------------------------------------------------------- VadimC -*/
MSOAPI_(BOOL) MsoFLicenseCDAutorun(WCHAR* wzProductCode);


/** LicClock **/
/* Clock tampering detection functionality */

/*-----------------------------------------------------------------------------
	MsoFGetFileTime

	returns the latest file time found in a file.  Checks filesystem and OLE
		summaryinfo

------------------------------------------------------------------- AndrewH -*/
MSOAPIX_(BOOL) MsoFGetFileTime(WCHAR *wzFile, FILETIME* lpFileTime);

/*-----------------------------------------------------------------------------
	MsoFAddMailMRUItem

	Adds a mail item to the list of items to be processed on next idle.

	parses the messageid for the first 29 characters of the servername.
	Checks if the item is already in the previous 20 read messages of this
		session and skips if so.
	
------------------------------------------------------------------- AndrewH -*/
MSOAPI_(BOOL) MsoFAddMailMRUItem(FILETIME* lpMessageTime, LPCSTR szMessageID);

/*----------------------------------------------------------------------------
	MsoSetEnvelopeFrameHwnd

	Called by the Envelope whenever it becomes active.
------------------------------------------------------------------- AidanH -*/
MSOAPI_(VOID) MsoSetEnvelopeFrameHwnd(HWND hwndFrame);

/** end LicClock **/

#endif // MSOLIC_H
