#pragma once

/****************************************************************************
	MsoTB.h

	Owner: DavePa
	Copyright (c) 1994 Microsoft Corporation

	This file contains the exported interfaces and declarations for
	Office Toolbars and related components.
****************************************************************************/

#ifndef MSOTB_H
#define MSOTB_H


/****************************************************************************
	Toolbar structures and constants
**************************************************************** RAVINDRA **/

// Move this?
#define spinInc 0
#define spinDec 1

// Strip Flags for MsoPwchStripWtz()
#define msofStripOddAmpersands	0x00000001
#define msofStripTrailingColon	0x00000002
#define msofStripTrailingElipses	0x00000004
#define msofStripAccelarator		0x00000008 // will remove OddAmpersand and also (&N)

/* Button Type options, used for the tbct for MsoFCreateControl for buttons.
	These options can be OR-ed together.  Some of these are just optimizations
	to prevent certain callbacks to the IMsoButtonUser interface.
	See also msotbctXXX flags below. */
#define msotbbtAuto	          0x0000 // Show text only when in menu
#define msotbbtPict           0x0001 // Show icon on toolbar, text only in menu
#define msotbbtText           0x0002 // Show text
#define msotbbtBoth           0x0003 // Show icon and text
#define msotbbtMask           0x0003 // Mask for non-optimzation options
// To use the next flag you MUST pass in an OwnerButtonControlUser object
#define msotbbtOwnerDraw      0x0004 // Owner drawn button

// Pass in this flag at create time to allow smaller than normal button sizes
#define msotbbtTinySizes      0x0008 // Enable tcr sizing

// Optimization options for buttons
#define msotbbtOneState       0x0010 // Assume msotbbsUp for Tbbs()
#define msotbbtNoSetCursor    0x0020 // Don't call FSetCursor()
#define msotbbtNoAccel        0x0040 // Don't call FWtzGetAccelerator()
#define msotbbtChgAccel       0x0080 // Accelerator can change over time

#define msotbbtSticky         0x0100 // Menu Won't fold up when clicked on

// Edit/dropdown/combo options (tbct for MsoFCreateControl)
#define msotbdtLabel          0x0001 // Show label next to the control
#define msotbdtNoIME          0x0002 // IME will be disabled for this control (edits/combos only)
#define msotbetNoIME    msotbdtNoIME // compatibility
#define msotbdtWysiwyg        0x0004 // Show dropdown Wysiwyg style. Must use a WysiwygUser
#define msotbdtNoAutoComplete 0x0008 // Don't autocomplete in this control
#define msotbdtSendTab        0x0010 // Send an msomdExitTab (rather than an
                                     // msomdExitReturn) to the user when a Tab
                                     // is hit.

// Owner-drawn menu options (tbct for use with msotctOwnerMenu only)
#define msotbmtAuto           0x0000 // Show text only when in menu
#define msotbmtPict           0x0001 // Show icon on toolbar, text only in menu
#define msotbmtText           0x0002 // Show text
#define msotbmtBoth           0x0003 // Show icon and text
#define msotbmtSDMDropdown    0x0010 // looks like a SDM dropdown, owner-drawn part is only the "white" part
#define msotbmtSDMNoBkgd      0x0020 // if SDM dropdown, don't draw background	// FUTURE: predraw/postdraw

// Makes msotctMenuButton owner-drawn (calls back on TbbodDraw)
#define msotbmtOwnerDraw      0x0004	// Owner drawn menu

// Labels (including owner-drawn)
#define msotbltAuto           0x0000 // Defaults to simple label
#define msotbltText           0x0001 // Simple text label
#define msotbltLine           0x0002 // A horizontal line
#define msotbltTextLine       0x0003 // Text followed by horizontal line
#define msotbltOwnerDraw      0x0004 // Owner drawn label
#define msotbltMask           0x0007 // tblt bit mask
#define msotbltAutoSizeVert   0x0008 // Autosize horizontally
#define msotbltAutoSizeHorz   0x0010 // Autosize vertically

// tbct for the pane control
#define msotbptAutoSizeVert   0x0001   // Autosize vertically in vertical docks
#define msotbptAutoSizeHorz   0x0002   // Autosize horizontally in horizontal docks

/* General flags and optimization options that can be OR-ed into the tbct for 
	MsoFCreateControl       for all control types.  Some of these are just 
	optimizations that prevent      certain callbacks to the IMsoControlUser 
	interfaces. */
#define msotbctAlwaysEnabled  0x00010000 // Assume TRUE for FEnabled()
#define msotbbtAlwaysEnabled  msotbctAlwaysEnabled     // support old name
#define msotbctAlwaysVisible  0x00020000 // Assume TRUE for FAutoVisible()
#define msotbctNoChangeLabel  0x00040000 // Never call FChangeLabel()
#define msotbctKeepLabel      0x00080000 // No FChangeLabel() unless control is reset
#define msotbctNoQueryTooltip 0x00100000 // FQueryString() not called for tooltips

/* By default locale-sensitive UI strings such as label, accelerator, 
	tooltip, and status text are not FSave'd for built-in controls if the app 
	sets a new one	(the assumption being you are just changing strings on the 
	fly).  This saves space for load/save file and allows the app to reassign 
	the strings after load so that switching languages works.  However, if the 
	end user changes the strings, we want to save them (and punt language 
	changes).  The normal cases of end user changes (VBA and Customize UI) are 
	handled internal to Office and will end up setting this flag.  If the app 
	wants to simulate an end user change or otherwise force saving, it can set 
	this flag too via SetTbct (set before making changes). */
#define msotbctSaveUIStrings  0x00200000

/* Sometimes a menu control needs to make sure that the popup it is going to drop
	is exclusive custom toolbar. An example is custom menus with custom popups.
	When this tbct is used we would deny setting a pitb to control, if the pitb is
	already is referred to by another control. Pitb must be a msotbidCustom toolbar.
	Also if the control is cloned, we would clone the popup, giving it a new name.
*/
#define msotbctExclusiveCustomPopup	0x00400000

// Use the Office default for IMsoControlUser::TbcuOleUsage based on the tcid
#define msotbctDefaultTbcu		0x00800000

// This tbct indicates that the app will handle all of the reset functionality.
// (This was added mostly for Project98 in the A-Release Bug 202220)
#define msotbctAppHandlesReset	0x01000000

// Two more button styles.  These must match msotbbsxWrapText and msotbbsxTextBelow.
#define msotbctWrapText			0x02000000
#define msotbctTextBelow		0x04000000

// Can be used by the app for whatever they want
#define msotbctAppReserved2   0x20000000
#define msotbctAppReserved    0x40000000

/* Special option for SetTbct calls to disable dirtying the toolbar just
	because an optimization option was changed. */
#define msotbctDontDirty      0x80000000


// Owner-drawing mode for TbbodDraw on all Users (owner-draw callback)
#define msoodmPostdraw			0x00	// called just after Office draws the background
#define msoodmPredraw			0x01	// called after Office draws icon, text, frame, etc
#define msoodmUpdate				0x02	// does your owner-draw control need to redraw?
#define msoodmPaletteChange	0x04	// the palette changed, do you need to redraw?

// Return value flags for IMsoButtonUser::TbbodDraw
#define msotbbodNone   0x0000   // No control drawing terminate immediately
#define msotbbodText   0x0001   // Draw the label in the menu if applicable
#define msotbbodBlank  0x0002   // Draw a blank face for the button
#define msotbbodFace   0x0004   // Draw the stored face for the button
#define msotbbodAll    0x0007   // Draw the stored face for the button

// Values for the tbbsx param to IMsoButtonUser::TbbodDraw
// These are the bit definitions for the various appearances of a button
#define msotbbsxRaised				0x00000001  // The button is popped up
#define msotbbsxLowered				0x00000002  // The button is depressed in
#define msotbbsxOffset1				0x00000004  // The image is to be drawn down and over 1
#define msotbbsxOffset2				0x00000008  // The image is to be drawn down and over 2
#define msotbbsxHilite				0x00000010  // The image background should be highlited
#define msotbbsxDisable				0x00000020  // The button should be disabled
#define msotbbsxUseCbv				0x00000040  // Cbv drawing should be used.
#define msotbbsxFocus				0x00000080  // Control has the focus
#define msotbbsxSplitBtn			0x00000100  // Is this really a split button w/ arrow?
#define msotbbsxSplitLowered		0x00000300  // The split half is depressed
#define msotbbsxSplitRaised		    0x00000500  // The split half is raised
#define msotbbsxOnlySplit			0x00000900  // Render only the split btn half
#define msotbbsxOnlyBtn				0x00001100  // Render only the button half
#define msotbbsxSplitHilite		    0x00002000  // Split button itself is highlighted
#define msotbbsxOnlyFrame			0x00004000  // Don't draw the interior at all
#define msotbbsxValid				0x00008000  // Is the tbbs really a tbbsx?
#define msotbbsxSplitBtnDisabled	0x00010000  // Split button, ONLY the button is disabled
#define msotbbsxPad					0x00020000  // Add padding to right and left of text
// todo: gregl: this is ONLY (?) set for text menus which already set msotcidNil.....
#define msotbbsxNoIcon				0x00040000  // No icon/button on left part if in menu
#define msotbbsxRightArrow			0x00080000  // For split button in menu, draw an menu (right) arrow instead of a split (down) arrow
#define msotbbsxArrowFrame			0x00100000  // For split button in menu, turns on arrow separator (redudant if split button)
#define msotbbsxNoClip				0x00200000	// Doesn't clip text, which does wonders for performance
#define msotbbsxNoCenter			0x00400000	// Never center the text, always left-justify it
#define msotbbsxSDM					0x00800000	// SDM visuals should be used
#define msotbbsxIconBox				0x01000000	// When in a menu, draw a box for an icon, even if there's no icon
#define msotbbsxWrapText			0x02000000	// Wrap the text description of a button
#define msotbbsxTextBelow			0x04000000	// Display the text below the button icon
#define msotbbsxNotOpaque			0x08000000	// Don't set background as Opaque
#define msotbbsxDontFullCenter		0x10000000	// Don't full center icon only center vertically or horz opposite of ceo.fVertical
#define msotbbsxNoLeftEdge			0x20000000  // Used by draw border only
#define msotbbsxNoRightEdge			0x40000000  // Used by draw border only
#define msotbbsxMenuArrow			0x80000000  // Used by DrawButtonEx to draw menu arrow

// These are combos of the above to form the standard list of suspects
#define msotbbsxFlat    (msotbbsxValid)  // Non-selected look
#define msotbbsxUp      (msotbbsxValid | msotbbsxRaised)
#define msotbbsxDown    (msotbbsxValid | msotbbsxLowered | msotbbsxOffset1 | msotbbsxHilite)
#define msotbbsxDownDk  (msotbbsxValid | msotbbsxLowered | msotbbsxOffset1)
#define msotbbsxDownDk2 (msotbbsxValid | msotbbsxLowered | msotbbsxOffset2)

#define msotbbsxSplitFlat (msotbbsxValid | msotbbsxSplitBtn)
#define msotbbsxSplitUp   (msotbbsxValid | msotbbsxSplitBtn | msotbbsxSplitRaised)
#define msotbbsxSplitDown (msotbbsxValid | msotbbsxSplitBtn | msotbbsxSplitLowered)

// Values for tbbsx2 parameter to DrawButtonEx
#define msotbbsx2None               0x00000000 // None
#define msotbbsx2SplitBtnNoLine     0x00000001 // Draws a splitbtn without a split button line
#define msotbbsx2WPIconTextGap      0x00000002 // Uses ICON_TEXT_GAP spacing in drawing icons with text

// These are just better names, useful in CBV code
#define msotbbsxMouseOver     msotbbsxRaised
#define msotbbsxMouseDown     msotbbsxLowered
#define msotbbsxSelected      msotbbsxHilite

// Return values for IMsoSwatch::FChangeSelection
#define msosupdNone			0	// no update, nothing changed at all
#define msosupdSelection	1	// only the selection changed
#define msosupdAll			2	// Need full redraw of swatch (example: all colors have been shifted in a MRU swatch)


// Types of OLE sessions
enum
	{
	msotbosNone = 0,
	msotbosNonOfficeServer, // We are server in non-Office app
	msotbosNonOfficeClient, // Non-Office app is embedded in us
	msotbosOfficeServer,            // We are server in Office toolbar app
	msotbosOfficeClient             // Office app is embedded in us
	};

// Control OLE merge support
enum
	{
	msotbcuNotFound = -1,	// bad return from IMsoControl::TbcuGet()
	msotbcuNeither = 0,
	msotbcuServer,          // Control stays on toolbar of Server
	msotbcuClient,          // Control stays on toolbar of Container
	msotbcuBoth,
	};

// Menu group for OLE menu merging
enum
	{
	msotbmgNone = -1,
	msotbmgFile = 0,
	msotbmgEdit,
	msotbmgContainer,
	msotbmgObject,
	msotbmgWindow,
	msotbmgHelp
	};


// Level of toolbar merging allowed by clinet.
enum
	{
	msoOleFullMerge = 0,
	msoOleNoMerge,
	msoOleMergeMainCmdBar
	};

// Type of notifications that are sent to a containers
// toobar set user to inform him of when significant inplace toolbar
// operations are about to occur.
enum
	{
	msoInplaceActivate = 1,
	msoInplaceDeactivate,
	msoUIActivate,
	msoUIDeactivate,
	msoMergeNotification,
	msoOleException,
	msoToolbarPosChange,
	msoRemToolbarSetVisible,
	msoRemTbBeforeShow,     // Toolbar is about to be shown. BUG 111040
	msoRemTbAfterHide      // Toolbar was hidden. BUG 111040
	};

#define msoDefaultActivation 0x00000000 
#define msoNoActivation		0x00000001  // Do not call Activate on the ToolbarSet
#define msoNoVisibilitySet	0x00000002  // Do not call SetVisible on the ToolbarSet
#define msoUpdate			0x00000004  // Call FUpdate to enusre we are up to date with client.
	
		
// Menu width subscripts for OLEMENUGROUPWIDTHS array
enum
	{       
	msotbmwMenuWidthFile = 0,
	msotbmwMenuWidthEdit,
	msotbmwMenuWidthCont,
	msotbmwMenuWidthObjt,
	msotbmwMenuWidthWind,
	msotbmwMenuWidthHelp
	};


// values for IMsoToolbarSet::RemUpdateToolbar and
//			  IMsoToolbar::RemUpdateToolbar	
#define msoRemForceUpdate				0x00000001
#define msoRemRequestUpdate				0x00000002
#define msoRemForceRemerge				0x00000004
#define msoRemUpdateAll					0x80000000

// values for IMsoToolbarSet::RequestServerUpdate
enum
	{ 
	msowpForceUpdate = 0,
	msowpRequestUpdate,
	msowpForceRemerge,
	};
	
// Toolbar Dock States
enum
	{
	msotbdsInvalid = -1,
	// Docked on App Frame
	msotbdsFrmLeft = 0,
	msotbdsFrmTop,
	msotbdsFrmRight,
	msotbdsFrmBottom,
	// Floating
	msotbdsFloating,
	msotbdsMenuBar,
	msotbdsMax,
	};

// Toolbar Visibility
enum
	{
	msotbvHidden = 0,
	msotbvVisible,
	msotbvAutomatic,
	};

// Toolbar iRow
enum
	{
	msotbirowMin =  -3,	msotbirowDragging = -3,
	msotbirowAppend = -2,
	msotbirowPrepend = -1,
	msotbirowMax = 127,
	};
	
// Toolbar Expand Operations
enum
	{
	msotbeopTip = 0x01,
	msotbeopFlash = 0x02,
	msotbeopExpand = 0x04,
	};

// Toolbar Clone flags 
 enum
	{
	msotbcfHiddenTb        = 0x0001,   // Clone hidden toolbars
	msotbcfControls        = 0x0002,   // Clone controls
	msotbcfCustomTb        = 0x0004,   // Force the cloning of custom toolbars even hidden ones)
	msotbcfCustomTbCtl     = 0x0008,   // Force the cloning of controls on custom toolbars
	msotbcfNoBuiltInPopup  = 0x0010,   // Don't clone builtin popups even if msotbcfHiddenTb is set
	};


// The toolbar is built-in and in its default state or is not a saveable toolbar
#define msotbcsNoChange			0x0000

// Controls have changed this session or the toolbar was added this session.
// Need to full save the toolbar (save toolbar and controls).
#define msotbcsCurCtlChanged	0x0001	

// Controls have changed since the default state or the bar is msotbidCustom.
// Need to save controls (full save) if saving the toolbar.
#define msotbcsCtlChanged		0x0002

// The toolbar position, visibility, etc. was changed this session.
// Need to at least partial save the toolbar.
#define msotbcsCurChanged		0x0004

// The toolbar position, visibility, etc. was changed from the default state.
// Need to at least partial save the toolbar if saving the toolbar set.
#define msotbcsChanged			0x0008


// Flags for IMsoControlSite::SetCtlModified
enum
	{
	msoscmInit = 0,	// Controls are in default state and not modified by user
	msoscmChange = 1,	// Controls were changed by the user
	msoscmReset = 2,	// Controls were changed back to default state in this session
	};

/****************************************************************************
	Command Bar Visuals
****************************************************************************/

// Microsoft Office Command Bar Visuals Counts of Pixels - for dimensions
typedef enum
	{
	/***********************************************
	Values that never change based on system metrics
	***********************************************/
	msocbvcpxCmdBarFloatingInnerBorderX = 1,
	msocbvcpxCmdBarFloatingInnerBorderY = 1,
	msocbvcpxCmdBarDockedInnerBorderX = 1,
	msocbvcpxCmdBarDockedInnerBorderY = 1,
	msocbvcpxCmdBarDockedOuterBorderX = 1,
	msocbvcpxCmdBarDockedOuterBorderY = 1,

	msocbvcpxWPFloatingInnerBorderX = 1,
	msocbvcpxWPFloatingInnerBorderY = 1,
	msocbvcpxWPDockedInnerBorderX = 1,
	msocbvcpxWPDockedInnerBorderY = 1,
	msocbvcpxWPDockedOuterBorderX = 2,
	msocbvcpxWPDockedOuterBorderY = 2,

	msocbvcpxMenuInnerBorderX = 0,
	msocbvcpxMenuInnerBorderY = 1,
	msocbvcpxMenuOuterBorderX = 1,
	msocbvcpxMenuOuterBorderY = 1,

	msocbvcpxCtrlEdgeX = 4,
	msocbvcpxCtrlEdgeY = 4,

	msocbvcpxWPScollArrowY = 10,
	msocbvcpxCmdBarDragHandleX = 6,
	msocbvcpxCmdBarSplitterLineX = 6,
	msocbvcpxCmdBarSplitterLineY = 6,
	msocbvcpxTearOffStripeX = 33,
	msocbvcpxMenuSeparatorY = 2,        // Height of a separator bar in menus
	msocbvcpxMenuItemPadding = 3,       // Padding around text and icon in menus, used lots of places

	msocbvcpxMainMenuBarSpacing = 5,  // + MenuItemPadding = 8 total per side
	// TODO JEFFREYK - make into #define's, get them out of the CBVCPX, and remove them from the NewLook debug dialog!
	// Or, leave them in the CBVCPX, but please clean up the dialog box!!! - dmorton
	msocbvcpxMenuShadowWidthNoTransparency = 2,
	msocbvcpxMenuShadowWidth = 4,
	msocbvcpxMenuShadowTransparencyPct = 25,
	msocbvcpxMenuShadowOffset = 0,

	msocbvcpxDitherThreshold = 31, // when we convert from 1x1 dithering to 2x2 dithering

	/*****************************************
	Values that change based on system metrics
	*****************************************/

	// Values that are not constant should be placed between
	// msocbvcpxMinVariableDimensions and msocbvcpxMax.

	msocbvcpxMinVariableDimensions = 256,
	msocbvcpxCmdBarCaptionY = msocbvcpxMinVariableDimensions,
	msocbvcpxCmdBarFloatingOuterBorderX,
	msocbvcpxCmdBarFloatingOuterBorderY,

	// This group and the SDMMenu group below must remain contiguous.
	// These are metrics that depends on font size.
	// If you change anything in these two groups, please double
	// check that you haven't broken anything in CbvCreateDimensions functions!
	msocbvcpxMenuIconStripWidth,        // Width of icon strip on the left side of menus
	msocbvcpxMenuTextInset,             // Distance between icon strip and left edge of text
	msocbvcpxMenuTextAccelGap,          // Minimum distance between text and accelerator
	msocbvcpxMenuAcceleratorInset,      // Distance between right edge of menu and right edge of accelerator text
	msocbvcpxMenuCheckColumn,           // Width of check-mark column in Add/Remove Buttons
	msocbvcpxMenuItemHeight,            // Height of a standard menu item
	msocbvcpxMenuTearoffHandle,         // Height of the tear-off handle

	// Note: if you try to access msocbvcpxSDM* directly, you will be hosed.  These are
	// only used in the command well right now and are inited in MsoCpxCbvGetAccurate.
	msocbvcpxSDMMenuIconStripWidth,
	msocbvcpxSDMMenuTextInset,
	msocbvcpxSDMMenuTextAccelGap,
	msocbvcpxSDMMenuAcceleratorInset,
	msocbvcpxSDMMenuCheckColumn,
	msocbvcpxSDMMenuItemHeight,
	msocbvcpxSDMMenuTearoffHandle,

	msocbvcpxMax, // NOT a valid dimension, just a place holder

	/******************************************************
	Values that are simply alternate names for other values
	******************************************************/

	// Values that should never differ should be placed here.
	msocbvcpxCmdBarCaptionBtnX = msocbvcpxCmdBarCaptionY,
	msocbvcpxCmdBarCaptionBtnY = msocbvcpxCmdBarCaptionY,
	msocbvcpxWPFloatingOuterBorderX = msocbvcpxCmdBarFloatingOuterBorderX,
	msocbvcpxWPFloatingOuterBorderY = msocbvcpxCmdBarFloatingOuterBorderY,

	} MSOCBVCPX;

/* NOTE: within just a few weeks of using these names thing got very confusing.
	With so many colors, it became difficult to distinguish them based on their
	name.  So, we are adopting a better naming scheme.  The names will all
	follow the following layout:

	<Feature><Item><States>

  Features:
	CB - Command Bars
	WP - Work Pane
	SB - Status Bar
	OB - Outlook Bar
	GD - Grid (Excel and Access)
	SD - Speech/Dictation
	<add more as needed>

  Item:
	Ctl  - Control
	Bkgd - Background
	Bdr  - Border
	Text - Text (wow, what a concept)
	<add more as needed>
	
  State:
	Disabled
	Selected
	MouseOver
	MouseDown
	<add more as needed>

  Feel free to use multiple items and states to accurately discribe your color.
  ie. "CtlBkgd" or "MouseOverSelected".

  HBRUSHs are expensive compared to COLORREFs.  I suggest you use color refs
  and ExtTextOut to draw rectangles, rather than brushes and functions like
  PatBlt or Rectangle.
*/

// Microsoft Office Command Bar Visuals Color References
typedef enum _msocbvcr
	{
	msocbvcrCBBkgd = 0,
	msocbvcrCBDragHandle,
	msocbvcrCBSplitterLine,
	msocbvcrCBTitleBkgd,
	msocbvcrCBTitleText,
	msocbvcrCBBdrOuterFloating,
	msocbvcrCBBdrOuterDocked,
	msocbvcrCBTearOffHandle,
	msocbvcrCBTearOffHandleMouseOver,

	msocbvcrCBCtlBkgd,
	msocbvcrCBCtlText,
	msocbvcrCBCtlTextDisabled,
	msocbvcrCBCtlBkgdMouseOver,
	msocbvcrCBCtlBdrMouseOver,
	msocbvcrCBCtlTextMouseOver,
	msocbvcrCBCtlBkgdMouseDown,
	msocbvcrCBCtlBdrMouseDown,
	msocbvcrCBCtlTextMouseDown,
	msocbvcrCBCtlBkgdSelected,
	msocbvcrCBCtlBdrSelected,
	msocbvcrCBCtlBkgdSelectedMouseOver,
	msocbvcrCBCtlBdrSelectedMouseOver,
	msocbvcrCBCtlBkgdLight,
	msocbvcrCBCtlTextLight,

	msocbvcrCBMainMenuBkgd,
	msocbvcrCBMenuBkgd,
	msocbvcrCBMenuCtlText,
	msocbvcrCBMenuCtlTextDisabled,
	msocbvcrCBMenuBdrOuter,
	msocbvcrCBMenuIconBkgd,
	msocbvcrCBMenuIconBkgdDropped,
	msocbvcrCBMenuSplitArrow,

	msocbvcrWPBkgd,
	msocbvcrWPText, // text that lies directly on the background, like check box text
	msocbvcrWPTitleBkgdActive,
	msocbvcrWPTitleBkgdInactive,
	msocbvcrWPTitleTextActive,
	msocbvcrWPTitleTextInactive,
	msocbvcrWPBdrOuterFloating,
	msocbvcrWPBdrOuterDocked,
	msocbvcrWPCtlBdr,
	msocbvcrWPCtlText,
	msocbvcrWPCtlBkgd,
	msocbvcrWPCtlBdrDisabled,
	msocbvcrWPCtlTextDisabled,
	msocbvcrWPCtlBkgdDisabled,
	msocbvcrWPCtlBdrDefault,
	msocbvcrWPGroupline,

	msocbvcrSBBdr,

	msocbvcrOBBkgdBdr,
	msocbvcrOBBkgdBdrContrast,

	msocbvcrOABBkgd,

	msocbvcrGDHeaderBkgd,
	msocbvcrGDHeaderBdr,
	msocbvcrGDHeaderCellBdr,
	msocbvcrGDHeaderSeeThroughSelection,

	msocbvcrMax, // NOT a valid color, just a place holder

	// Only the colors that must always match with other colors should be placed here....
	msocbvcrCBBdrInnerFloating = msocbvcrCBBkgd,
	msocbvcrCBBdrInnerDocked = msocbvcrCBBkgd,
	msocbvcrCBCtlTextSelected = msocbvcrCBCtlTextMouseOver,
	msocbvcrCBCtlTextSelectedMouseOver = msocbvcrCBCtlTextMouseDown,
	msocbvcrCBMenuCtlBkgd = msocbvcrCBMenuBkgd,
	msocbvcrCBMenuBdrInner = msocbvcrCBMenuBkgd,
	msocbvcrWPBdrInnerFloating = msocbvcrWPBkgd,
	msocbvcrWPBdrInnerDocked = msocbvcrWPBkgd,
	msocbvcrWPCtlBkgdMouseOver = msocbvcrCBCtlBkgdMouseOver,
	msocbvcrWPCtlBdrMouseOver = msocbvcrCBCtlBdrMouseOver,
	msocbvcrWPCtlTextMouseOver = msocbvcrCBCtlTextMouseOver,
	msocbvcrWPCtlBkgdMouseDown = msocbvcrCBCtlBkgdMouseDown,
	msocbvcrWPCtlBdrMouseDown = msocbvcrCBCtlBdrMouseDown,
	msocbvcrWPCtlTextMouseDown = msocbvcrCBCtlTextMouseDown,
	msocbvcrWPCtlRadioCheckBkgd = msocbvcrWPBkgd,
	msocbvcrOBBkgd = msocbvcrCBCtlBkgd,
	msocbvcrOBText = msocbvcrCBCtlText,
	msocbvcrOBBkgdMouseOver = msocbvcrCBCtlBkgdMouseOver,
	msocbvcrOBBdrMouseOver = msocbvcrCBCtlBdrMouseOver,
	msocbvcrOBTextMouseOver = msocbvcrCBCtlTextMouseOver,
	msocbvcrOBBkgdMouseDown = msocbvcrCBCtlBkgdMouseDown,
	msocbvcrOBBdrMouseDown = msocbvcrCBCtlBdrMouseDown,
	msocbvcrOBTextMouseDown = msocbvcrCBCtlTextMouseDown,
	msocbvcrGDHeaderCellBkgd = msocbvcrCBCtlBkgd,
	msocbvcrGDHeaderCellText = msocbvcrCBCtlText,
	msocbvcrGDHeaderCellBkgdSelected = msocbvcrCBCtlBkgdMouseOver,
	msocbvcrGDHeaderCellBdrSelected = msocbvcrCBCtlBdrMouseOver,
	msocbvcrGDHeaderCellTextSelected = msocbvcrCBCtlTextMouseOver,
	msocbvcrOBBkgdSelected = msocbvcrCBCtlBkgdSelected,
	msocbvcrOBBdrSelected = msocbvcrCBCtlBdrSelected,
	msocbvcrOBTextSelected = msocbvcrCBCtlTextSelected,
	msocbvcrOBBkgdSelectedMouseOver = msocbvcrCBCtlBkgdSelectedMouseOver,
	msocbvcrOBBdrSelectedMouseOver = msocbvcrCBCtlBdrSelectedMouseOver,
	msocbvcrOBTextSelectedMouseOver = msocbvcrCBCtlTextSelectedMouseOver,
	msocbvcrSDFeedback = msocbvcrCBCtlBkgdMouseDown,
	} MSOCBVCR;

// Toolbar Set Flags for IMsoToolbarSet::SetFlags
#define msotbsfNormal               0x00000000
#define msotbsfNoContextMenu        0x00000001 // no bar show/hide context menu
#define msotbsfNoCustomizeEntry     0x00000002 // no Customize choice on context menu
#define msotbsfNoCustomizeAtAll     0x00000004 // don't allow UI customize mode
#define msotbsfNoInactiveExecute    0x00000008 // don't allow automation FClick, etc. when TBS is inactive
#define msotbsfNoRedrawBars         0x00000010 // supress all redraws for floating and docked bars
#define msotbsfDisableCustomize     0x00000020 // disable Customize entry in menus
#define msotbsfNoMDIIcons           0x00000040 // no MDI Icons will be added to NonOffice Menu
#define msotbsfAllowDupVBANames     0x00000080 // allow duplicate bar names from VBA unless app checks and fails itself
#define msotbsfQueryAppForDupNames  0x00000100 // allow duplicate bar names from Customize UI unless app checks and fails itself
#define msotbsfNoFlushOLEUnmatched  0x00000200 // don't flush top-level bars looking for unmatched client toolbar when merging
#define msotbsfNoShowDuringTbLoad   0x00000400 // don't show the toolbar during IMsoToolbar::FLoad()
#define msotbsfShowMDIClose         0x00000800 // Has Close box on main menu
#define msotbsfNoAdaptivemenus      0x00001000 // Don't use adaptive menus
#define msotbsfNoDockWindows        0x00002000 // Don't create dock windows for this TBS (should only be used by GCC's TBS)
#define msotbsfOAFindLocalName      0x00004000 // On a DISPTBS::get_Item search both English and localized strings 
// DON'T use msotbsfOAFindLocalName unless you are VBE.
		// This WILL go away in the future only here for backwards compatibility
#define msotbsfNoSpeechCmds         0x00008000 // TRUE if the toolbarset doesn't support voice Cmds
#define msotbsfSDILikeMDIControls   0x00010000 // TRUE if App is using SDI-Like MDI controls (not showing Min & Restore on menubar)
#define msotbsfNoAWDropdown         0x00020000 // TRUE if the TBS does not want to
                                               // provide the AWDropdown special control

// Options for IMsoToolbarSet::SetAllowOAWhenMerged
#define msotboamAddBar				0x0001
#define msotboamDeleteBar			0x0002
#define msotboamAddControl			0x0004
#define msotboamCopyControl		0x0008
#define msotboamMoveControl		0x0010
#define msotboamDeleteControl		0x0020
#define msotboamChangeControl		0x0040
#define msotboamExecuteControl	0x0080
#define msotboamManipulateUI		0x0100

// Generic Control Container Resize Opertions
enum
	{
	msogccResizeAsk = 1,
	msogccResizeNotify,
	};

// Gcc flags.
enum
	{
	/* SDM specific */
	msogcc3D                     = 0x0001,
	msogccLarge                  = 0x0002,
	msogccAltColors              = 0x0004,
	msogccNoToolTip              = 0x0008,
	msogccCenterH                = 0x0010,
	msogccCenterV                = 0x0020,
	msogccNoCenterCtlsH          = 0x0040,
	msogccFocusDepressed         = 0x0080, // put focus on 1st depressed button
	msogccFGccKeepUnderline      = 0x0100, // keep the underline 
	msogccReturnKeys             = 0x0200, // Return keys to app

	/* Generic GCC */
	msogccUseNewLook             = 0x0400, // use the new look for gccs
	msogccButtonFaceBkg          = 0x0800, // use a button face background for gcc.
	msogccAltColors2 = msogccButtonFaceBkg, // same as above
	msogccNothingFancy           = 0x1000, // no desaturation, shadow, pop-up effects
	};	

// Notification codes for FNotifyAction methods
enum
	{
	msotbaCtlSelect = 0,    // control selected (hilited) by mouse-over or keyboard
	msotbaCtlDeselect,      // control deselected
	msotbaCtlDisabledClick, // control clicked on when disabled
	msotbaUnused,           // XXX use me for new tba XXX
	msotbaToggleAssistant,  // User pressed F1.  Show/Hide FC
	msotbaTbRename,         // Toolbar was renamed
	msotbaTbBeforeShow,     // Toolbar is about to be shown
	msotbaTbAfterHide,      // Toolbar was hidden
	msotbaChgSelCtlInCust,  // Selected control for customization changed
	msotbaCtlReset,         // control has been reset
	msotbaTbBeforeRename,   // Called before Toolbar is about to be renamed
	msotbaFlushTopLevelTbs, // Create all top-level toolbars not yet created
	msotbaRefreshTbsList, 	// Called before View-Toolbars list is refreshed
	msotbaTbUpdateForOA,		// Good time to update bar before OLE Automation queries
	msotbaCtlUpdateForOA,	// Good time to update control before OLE Automation queries
	msotbaBeginUpdate,		// Called at beginning of toolbar set FUpdate, and OLE cache update for container
	msotbaUnused2,          // XXX use me for new tba XXX
	msotbaCtlBeforeReset,   // Called before control is going to be reset
	msotbaEndUpdate,			// Called at end of toolbar set FUpdate, and OLE cache update for container
	msotbaCtlTempDelete,		// Called when a control is FTempDelete'd
	msotbaCtlTBAttached,		// sub-toolbar has been attached (see IMsoControl::PitbGet)
	msotbaEnableCustomize,  // last chance to change msotbsfDisableCustomize
	msotbaEndDrag,				// Called after toobar drag.
	msotbaFullCustomizeEnd, // full customize ended, client can activate its component if needed
	msotbaCtlDragOff,			// Notification to Control user that a control is being dragged off 
	// Additional notification codes only for FEmNotifyAction methods, although
	// they might someday be useful to FNotifyAction methods also.  Negative
	// value of any msotba indicates pre-action notification to event monitor.
	// Not all events generate a pre-action, but all do generate a post-action.
	msotbaCtlClickEm,			// control clicked on when enabled
	msotbaPickEm,				// dropdown item selected
	msotbaEnterTextEm,		// edit control text entered
	msotbaSwatchSelectEm,	// swatch item selected
	msotbaGridSelectEm,		// grid swatch item selected
	// Back to regularly scheduled notification codes for FNotifyAction.
	msotbaCtlWantDragOff,	// Asking Control User if it wants to drag off (Office should release capture)
	msotbaSetFocus,         // FNotifyFocus is asking that SetFocus be called
	msotbaCloseTb,          // Toolbar was closed by user action (click on X or through VB)
	msotbaOaShowTB,         // Toolbar was shown through VB
	msotbaTbDockChange,     // Toolbar is moved between docks.
	msotbaTbDontShowClipboard, // Return TRUE if the clipboard shouldn't be shown
	msotbaTbAfterShow,		// Toolbar is now shown
	msotbaTbDelete,         // Toolbar deleted by user or VB action
	msotbaReleaseFocus,     // FNotifyFocus is asking ctl to release focus
	msotbaFlushTopLevelMinTbs, // Create all really top-level toolbars not yet created (no menus or tear-offs)
	msotbaTBSSetEnvelope,   // Allow app to set the active envelope
	msotbaBeginUpdateTb,    // Toolbar is about to be updated
	msotbaBeginShowTb,      // Toolbar is about to be shown
	msotbaEndUpdateTb,      // Toolbar is done updating
	msotbaEndShowTb,       // Toolbar is down Showing.
	msotbaMCButtonDisabled, // The button in the face should be disabled
	msotbaMCButtonAutoVis,  // Notification to MRU Button in a menuControler that the TBCMC is getting FAutoVis call
	msotbaCtlSelectKeyboard, // control selected (hilited) by keyboard Sent immediately after msotbaCtlSelect when keyboard is used
	msotbaClonedTB,          // Newly created toolbar created by a cloning
	msotbaCtlBeforeClickEvent, // Notification to button in FireClickEvent
#ifdef UNDO_WEBPANE_CUT
	msotbaTbDontShowWebPane, // Return TRUE if the webpane shouldn't be shown
#endif
	msotbaTbCreatedWorkPane,	// Return value ignored - use this time to override default workpane state (docking, etc).
	msotbaTbForceDisabled,   // If app returns TRUE, this toolbar will be disabled. (sent to ToolbarUser with pitb = toolbar in question)
	msotbaRegisterWorkpanes, // Send when building workpanes menu, for registration of application specific workpanes
	msotbaDisableWorkpane,   // Sent to find out whether the app is in a semi-modeless scenario where the workpane should be disabled.
	};


// Flags for MsoFLoadToolbarSetEx
enum
	{
	msotbsLoadNormal                  = 0x0001,
	msotbsLoadNoOfficeTBs             = 0x0002,
	};
	

// Options for IMsoControlSite::GetCtlenv
#define msoctlenvfFull	0x0000	// Get a full MSOCTLENV
#define msoctlenvfNoDC	0x0001	// Don't get the hdc (set to NULL)

// Operations on converting Gaps to and fro NonGap indexes.
#define msogapopGetGap				0x00
#define msogapopGetNonGap			0x01
#define msogapopFromMenu			0x02
#define msogapopIgnoreVisibility	0x04
#define msogapopSkipGaps			0x08
#define msogapopDelete				0x10

// Operations on setting a control to temp, or delting a control.
#define msotempopCtlTemp 0x03 // Mark the Ctrl Temp or delete the control
#define msotempopCtlPerm 0x02	// Mark the Ctrl Perm
#define msotempopGapTemp 0x0c	// Mark the Gap Temp or delete the gap
#define msotempopGapPerm 0x08	// Mark the Gap Perm
#define msotempopCtlQuery 0x10  // Query the Ctrl Temp state

/* tbtr - Toolbar Type and Restrictions

	We assume 32 bit long in implementation and have reserved most significant 8 bits
	for toolbar types and rest 24 bits for restrictions.

	Toolbar Types - Regular Toolbar, Main Menu Bar, Menu Drop Down, Popup Menu
	Toolbar Restrictions - Don't Resize, Don't Move etc.

	NOTE: App will be able to modify restrictions of only the basic toolbars in the
	run time. It will NOT be able to modify tbtr for the MainMenuBar, MenuDropDown or
	PopupMenu etc. at all - it must be enforced in FSetProperties(). Also the app will
	NOT be able to change the toolbar type at azll i.e. a regular toolbar can not be
	converted into a menu-drop down or such by the App.
*/
// Toolbar Types
#define msotbtrBasicToolBar     0x00000000
#define msotbtrMainMenuBar      0x01000000
#define msotbtrPopupMenu        0x02000000
#define msotbtrGenContainer     0x04000000

#define msotbtMask              0xff000000


// Toolbar Restrictions or Protections
#define msotbtrNoRestrictions		0x00000000

#define msotbtrNoAddDelCtl			0x00000001 // Can't add or remove controls in Toolbar
#define msotbtrNoResize				0x00000002 // Can't resize a Floating Toolbar
#define msotbtrNoMove				0x00000004 // Can't move either by dragging or dbl-clk
#define msotbtrNoChangeVisible		0x00000008 // Can't change its visibility

#define msotbtrNoChangeDock			0x00000010 // Can't transit between floating and docked
#define msotbtrNoVerticalDock		0x00000020 // Only single-row horizontal layout
#define msotbtrNoHorizontalDock		0x00000040 // Only single-column vertical layout
#define msotbtrNoBorder				0x00000080 // No title bar, border, etc. when floating
#define msotbtrNoTbContextMenu		0x00000100 // Do NOT show this toolbar in context menu
#define msotbtrCommandWellOnly		0x00000200 // This toolbar is for customization purposes only
#define msotbtrYesTearOff			0x00000400 // Can be torn off
#define msotbtrNotTopLevel			0x00000800 // Is always child of another toolbar, never top-level
#define msotbtrNoVBARecord			0x00001000 // Don't do VBA recording on changes to this bar
#define msotbtrYesTornOff			0x00002000 // Torn-off (floating) version of a tear-off toolbar
#define msotbtrFullScreenMenu		0x00004000 // Full Screen Toolbar (for Word's Full Screen mode)
#define msotbtrLiveInCustomize		0x00008000 // Live in Customize mode
#define msotbtrAlphaSearchInCW		0x00010000 // Enable search for matching entry for typed char in CommandWell
#define msotbtrMenuReflow			0x00020000 // Reflows like a menu (one column, all controls expanded to full width)
#define msotbtrNoSave				0x00040000 // Don't Save this Toolbar
#define msotbtrFullExtent			0x00080000 // When docked, the toolbar will fill the row it is on.
#define msotbtrNoMerging			0x00100000 // No OLE item level merging is allowed. 
#define msotbtrRestrictedCustomize1	0x00200000 // Used for toolbars which host menu controls hooked up
													// to context menus. This toolbar itself cannot be customized
													// but it will drop menus and let them be customized.
#define msotbtrNoKeyboardFocus   0x00400000 // Can't take the keyboard foucs
#define msotbrMask      			0x007fffff
#define msotbtrDontDirty  			0x00800000 // Don't set dirty flag on change

// Useful MsoTbtr combos
#define msotbtrForMenus         (msotbtrNoResize | \
										msotbtrNoChangeDock | \
										msotbtrNoTbContextMenu | \
										msotbtrNoMove)
#define msotbtrForGenCc         (msotbtrNoResize | \
										msotbtrNoChangeDock | \
										msotbtrNoMove | \
										msotbtrNoAddDelCtl | \
										msotbtrNoVBARecord | \
										msotbtrNoBorder)
#define msotbtrIsMenu           (msotbtrPopupMenu)

// MsoTbtr combos to be used by the Apps to create the command bars
#define msotbtrTbBasic          (msotbtrBasicToolBar |\
										msotbtrNoRestrictions)
#define msotbtrTbMainMenu       (msotbtrMainMenuBar |\
										msotbtrNoRestrictions)
#define msotbtrTbPopupMenu      (msotbtrPopupMenu |\
										msotbtrForMenus | \
										msotbtrNoBorder)
#define msotbtrTbGenCc          (msotbtrGenContainer |\
										msotbtrForGenCc)

#define msotbtrTbDropdownToolbar (msotbtrTbBasic |\
										msotbtrForMenus |\
										msotbtrNoBorder |\
										msotbtrNotTopLevel)
#define msotbtrTbTearOff        (msotbtrTbDropdownToolbar |\
										msotbtrYesTearOff)
#define msotbtrTbDropdownMenu (msotbtrTbPopupMenu |\
										msotbtrNotTopLevel)

#define msotbtrTBQCExtraControls (msotbtrNotTopLevel |\
                                  msotbtrNoChangeVisible |\
                                  msotbtrNoAddDelCtl)

#define msotbtrPopupToolbar msotbtrTbDropdownToolbar // compatibility

// Torn off toolbars use their ID plus this constant
#define msotbidTearoff   0x1000
#define msotbidQuickCustomize 0x2000 // Quick customize TB's have this bit set
#define msotbidStandardExtra (msotbidStandard | msotbidQuickCustomize)
#define msotbidFormattingExtra (msotbidFormatting | msotbidQuickCustomize)
#define msotbidPivotTableExtra (msotbidPivotTable | msotbidQuickCustomize)
#define msotbidDrawingExtra (msotbidDrawing | msotbidQuickCustomize)
#define msotbidTablesAndBordersExtra (msotbidTablesAndBorders | msotbidQuickCustomize)
#define msotbidMailMergeExtra (msotbidMailMergeMain | msotbidQuickCustomize)

// MsoTbtr2 defines - Used when calling the IMsoToolbar::FSetTbtr2 function
// Bitfield - make sure all are unique bits.
#define msotbtr2None            0
#define msotbtr2Pane            (1 << 0) // Full extent in all docks, resizable.  Only usable with 1 control
	                    		            //		of type msotctPane, msotctWorkPane, msotctActiveX, etc.
#define msotbtr2F6Loop          (1 << 1) // Toolbar (with a pane control) is in the F6 loop and will receive
	                    		            //		activation on F6 keypresses.
#define msotbtr2NoMoveAway      (1 << 2) // Toolbar won't be auto-moved away from selections.
#define msotbtr2DockedCaption   (1 << 3) // Have a caption bar, even when docked - expected to be used with pane style command bars
#define msotbtr2NoDockedQCMenu  (1 << 4) // Hide the QC menu on the docked toolbar
#define msotbtr2Win32GCC        (1 << 5) // A GCC in a Win32 dialog

// Defines for Priorities
#define msotbPrioMax			7		// Maximum priority - if this changes,
											//		the number of bits used to store it
											//		also needs to change in MSOTCR, and
											//		the Control Info Cache in tb.i
#define msotbPrioDefMenu	1		// Default Priority for a Menu Control.
#define msotbPrioDefOther	3		// Default Priority for all other controls.

/****************************************************************************
	Forward declaration of interfaces to allow mutual reference
****************************************************************************/
#ifndef MSO_NO_INTERFACES

interface IMsoControlUser;
interface IMsoControl;
interface IMsoControlSite;
interface IMsoToolbarUser;
interface IMsoToolbar;
interface IMsoToolbarSetUser;
interface IMsoToolbarSet;
interface IMsoControlContainer;
interface IMsoTbFrame;
interface IMsoTFC;

#endif // MSO_NO_INTERFACES


#ifndef MSO_NO_INTERFACES

// Toolbar Dock / Position Information
// NOTE: iMetaRow is an internally computed value.  Changing it has no
//		effect.

#ifndef MSOTBDP_DEFINED
#define MSOTBDP_DEFINED

typedef struct _msotbdp
	{
	int tbds; // current tbds floating or docked
	int tbv;                        // current visibility (tbv_xxx)
	int tbdsDock;   // most recent (may be current) docked state (not floating)
	int iRow;               // row within dock
	int iMetaRow;	 // Toolbars with the same meta row want to be on the same row.
	RECT rcDock;    // RECT for dock in client co-ordinates
	RECT rcFloat;   // RECT for floating toolbar in screen co-ordinates
	} MSOTBDP;
#endif // MSOTBDP_DEFINED


#endif

// we are going to restrict the number of views that an App can have, mostly to
// check for bugs, because there really is no need for too many of these.
#define msoctbdpMax 8   // maximum number of views that a set can have.

// ToolBar Properties
#ifndef MSO_NO_INTERFACES

enum
	{
	msodotcDrawDropFeedback = 0, // draws drop feedback
	msodotcEraseDropFeedback, // erases drop feedback
	msodotcComputeDropFeedback, // doesn't draw or erase, only computes the rc
	};	

// type used when draging controls in toolbars
typedef struct _msoctldragflags
	{
	union
		{
		unsigned long dwFlags;
		struct
			{
			unsigned long fLeftHalf:1,	// TRUE if the given pt is on left half of control
					fBeginGroup:1,
					fNoCtlCustomize:1,
					fNoCtlCustomizeBefore:1,
					fNoCtlCustomizeAfter:1,
					fDragLeft:1,
					fDragRight:1,
					unused:25;
			};
		};
	} MSOCDFLAGS;


#ifndef MSOTBP_DEFINED
#define MSOTBP_DEFINED

typedef struct _msotbp
	{
	int tbtr;			// Toolbar Type and Restrictions
	int cRowsDefault;	// Default number of rows when floating
	// A toolbar may have one or more of MSOTBDP. Only the current MSOTBDP is here.
	MSOTBDP tbdp;           //      Current toolbar dock / position
	} MSOTBP;

#endif // MSOTBP_DEFINED


// Mso Customize Dialog's Command Helpers
enum
	{
	msocdhNil = 0,
	msocdhPreviewBox, // if App is going to draw a picture for command
	msocdhTextBox,	// if App is going to display a text stream for command
	msocdhQuickTip, // only if a control in App's existing TB is selected

	msocdhMax
	};

enum { // list of App defined extensions in customize dialog
	msocdeKeyboardBtn = 0,
	msocdeContextDD,
	msocdeAllocCmdsDD,
	msocdeAttachBtn,
	msocdeCmdsExtraEdit,
	msocdeMax
	};

enum { // list of tabs in the Customize dialog
	msocdtDefault = 0,
	msocdtCommandBars = 1,
	msocdtCommands,
	msocdtOptions,
	};

enum { // customize extensions for IMsoToolbarSet::FDoCustomizeExtension()
	msocxSelectControl = 0,
	msocxWizardBalloon,
	msocxFIsPitbInToolbarList,
	msocxRefreshToolbarList,
	};

enum {
	msotbstBeginTransaction = 0,
	msotbstEndTransaction,
	msotbstUndoTransaction,
	};

typedef struct _msocustdlgext
	{
	interface IMsoControlUser *picu;	// control user for extension
	void * pvClient;	// App should keep their pvClient for extension here
	} MSOCUSTDLGEXT;

typedef struct _msocustext
	{	// select which customize extenstion i.e. attach etc. was selected
		// then we figure out whether to tunnel or whatever
	int ext;
	} MSOCUSTEXT;

typedef struct _msocustdlginfo
	{
	interface IMsoToolbar *pitbInCommandBarList;
	interface IMsoToolbar *pitbInCommandsCategory; // NULL if new or built-in menus
	interface IMsoControl *picInCommands; // NULL if new or built-in menus
	int ictlInCommands; // -1 if new or built-in menus
	interface IMsoToolbar *pitbSelectedInApp; // maybe NULL
	interface IMsoControl *picSelectedInApp; // maybe NULL
	int ictlSelectedInApp; // maybe -1
	int cdh;
	} MSOCUSTDLGINFO;

	/* MSOCUSTCB is passed in IMsoToolbarSet::FSetupCustomize(). App can
		specify the extensions it is going to use and supply control users
		for them. App can also add its own extensions to ModifySelection
		popup. Dialog extensions are predefined.

		ppitbModifySelection - Every time IMsoToolbarSet::FCustomize() is
		called we free all the controls of ModifySelection menu and recreate
		the default ones supplied by Office DLL. App must recreate the controls
		that it wants to add and modify Office supplied controls again. If you
		wish to not to have ModifySelection menu on customize toolbar then you
		should call the IMsoToolbar::Delete method on *ppitbModifySelection and
		also set *ppitbModifySelection to NULL. [setting it to NULL without
		calling Delete on it will result in problems]

		ppitbAddCommand - App must create a toolbar with msotbidAddCommand and
		msotbtrTbPopupMenu in this toolbar set. *ppitbAddCommand points to the
		current AddCommand toolbar, if any. We do NOT free its controls for each
		customize call. For most of the Apps this pitb is not going to change
		from call to call. However if App wants to it could modify this one. To
		disable this menu app could set *ppitbAddCommand to NULL - and it is NOT
		mandatory that App delete the pitbAddCommand. But App should be aware
		that pitbAddCommand is still there in this toolbar set.

		It may fail, if App fails to create pitbAddCommand or a control that
		App wanted to add to ModifySelection menu and such.

		pctcid - App should return the number of tcid it wants to show in the
		Choose Icon dropdown.

		prgtcid - App should return the pointer to the array of tcids. If this
		array is an alloc off heap it is the responsibility of the App to free
		it up when Office calls back to App during QuitCustomize() or keep it
		around for later usage.

		rgcde[] - If App is going to use an extension (already defined in the
		customize dialog) App should specify an IMsoControlUser for that, and
		also supply a pvClient for it. Since there would not be an IMsoControl
		corresponding to that in the dialog, Office is going to call back using
		NULL for IMsoControl, which should be a signal to the App that it is
		from the Office Command Bar Customize dialog. However we are going to
		pass back the pvClient, supplied by the App. This gives us a general
		and extensible mechanism to support dialog extensions.

		ppfnUGraphicPreviewProc - SDM picture proc for Preview Box
		wParamGPP - wParam passed to the call back fn above, to help Apps
		tmcGPP - passed from Office to App to help them with SDM proc. App should not change it.

		ppfnURenderCmdText - SDM render proc for Cmd Text Box
		wParamRCT - wParam passed to the call back fn above, to help Apps
		tmcRCT - passed from Office to App to help them with SDM proc. App should not change it.

		icdt - App can choose which Customize Dialog Tab will come up first by this.

		Notes: We currently do not pass IMsoControlSite for the toolbars that
		may be modified by the app e.g. ppitbModifySelection, because when it
		has atleast one control and the app can find out control site by that.
		*/
typedef struct _msocustcb // customize command bars
	{
	struct {
			unsigned long fEndCustomize:1,
							fNewMenuCategory:1,
							fForceModeless:1,
							fHideShortcutKeyCheckBox:1,
							fUnused:28;
			};
	interface IMsoToolbar *pitbModifySelection;
	interface IMsoToolbar *pitbAddCommand;
	int ctcid;
	int *rgtcid;
	MSOCUSTDLGEXT rgcde[msocdeMax];
	void *pfnUGraphicPreviewProc;
	unsigned int wParamGPP;
	int tmcGPP; // passed from Office to App. App should not change it.
	void *pfnURenderCmdText;
	unsigned int wParamRCT;
	int tmcRCT; // passed from Office to App. App should not change it.
	int icdt;
	} MSOCUSTCB;

#endif // MSO_NO_INTERFACES

// Save options
enum
	{
	msotbsaveAll,           // Save object and sub-objects too
	msotbsavePartial,       // Save object, but not sub objects
	msotbsavePartialEachTb,	// For TBS::FSave, do msotbsavePartial for each TB
	msotbsaveInternal,      // DO NOT USE!  
	// saveMinimal doesn't work properly.  We have added a new option, minimalReal,
	// that works the way minimal was meant to work.  If you are using the old
	// msotbsaveMinimal and you want the existing behavior, use minimalBogus, otherwise
	// you should switch to minimalReal.
	msotbsaveMinimalBOGUS,  // Don't save a builtin Toolbar at all if it hasn't changed 
	msotbsaveMinimalReal,   // Proper minimal save 
	};

// Load options
enum
	{
	msotbloadPublic,
	msotbloadInternal               // DO NOT USE!
	};

// Customize Operation Codes for IMsoToolbarUser::FCtlCustomized
enum
	{
	msocopDelete = 0,
	msocopInsert,
	msocopMove,
	msocopChangeGapBefore,
	msocopReset,
	msocopChgCtlPresentation,
	msocopInsertOleProxy,
	msocopDeleteOleProxy,
	msocopChangeLabel,
	msocopChangeSize,
	msocopChangeBtnFace,
	msocopResetBtnFace,
	msocopChangeStatusText,
	msocopChangeParameter,
	msocopChangeTag,
	msocopChangeTooltip,
	msocopChangeHelpId,
	msocopChangeHelpFile,
	msocopChangeOnAction,
	msocopChangePriority,
	msocopChangeShortcut,
	msocopChangeEnabled,
	msocopChangeOLEUsage,
	msocopChangeVisible,
	msocopChangeTbbsState,
	msocopChangeOLEMenuGroup,
	msocopChangeCustomDropdown,
	};

// Flags to get/set through F(Get/Set)Flag
enum
	{
	msotbflagNeedsPositioning = 0,
	};
	
// TBM could be useful to contain few platform differences
// ToolBar Metrics - all dimensions are in pixels
#ifndef MSO_NO_INTERFACES

// Office9 version of MSOTBM structure
typedef struct _msotbm9
	{
	int dxpButton;  // large or small button size
	int dypButton;
	int dxpMargin;  // space around edges of toolbars
	int dypMargin;
	int dxpRow;     // row widths (horz and vert docking, resp)
	int dypRow;
	int dxpGap;     // gap widths
	int dypGap;
	int dxCaptionBtn;
	int dyCaptionBtn;
	HFONT hfontHalfHtTitle;
	} MSOTBM9;

// Office 10 version of MSOTBM structure
typedef struct _msotbm
	{
	union
		{
		MSOTBM9 tbm9;
		struct
			{
			int dxpButton;  // large or small button size
			int dypButton;
			int dxpMargin;  // space around edges of toolbars
			int dypMargin;
			int dxpRow;     // row widths (horz and vert docking, resp)
			int dypRow;
			int dxpGap;     // gap widths
			int dypGap;
			int dxCaptionBtn;
			int dyCaptionBtn;
			HFONT hfontHalfHtTitle;
			};
		};
	// Office10 members should be added after this line.
	int dxDockedCaptionBtn;
	int dyDockedCaptionBtn;
	} MSOTBM;

#endif // MSO_NO_INTERFACES

/* MSOTCR "Toolbar Control Record" contains the specification of a control 
	and its placement in the container.

	fCurVisibility == (msotcr.fHidden ? 0 : pic->FAutoVisible())

	As shown above fCurVisibility depends on the control's behavior in current
	App state and the control-user.
	NOTE: fCurVisibility is a read only bit, setting it has no effect on Office.

	uPriority:  Specifies the priority of the control for dropping and wrapping
		purposes.  If the priority == 0, it is considered the default state.  If
		the priority == 1, the control will never be dropped and will be wrapped
		when needed.  Otherwise the higher the number, the sooner the control will
		be dropped.
*/
#ifndef MSO_NO_INTERFACES
typedef struct _msotcr
	{
	interface IMsoControl *pic;    // the control object
	union {
		ULONG uFlags;
		struct {
			ULONG   fHidden : 1,     // TRUE if the control is hidden
				fBeginGroup : 1,      // TRUE if a gap/separator should preceed the control
				fOwnLine : 1,         // TRUE if a control should be on its own line in 2-d
				fHasAParameter:1,		// TRUE if a control is going to have allocated command
				fCurVisibility : 1,   // TRUE if control is currently visible in toolbar
				fNoCustomize : 1,     // TRUE if control shouldn't be altered by customization
				uPriority : 3,			 // Priority of the Control: 0-7 - See above.
				fReserved1 : 1,       // Used internally by Office (currently free).
				fReserved2 : 1,       // Used internally by Office.
				fBeginLine : 1,       // TRUE if the control starts a new line (Same as BG withought the separator)
				fUnused : 20;
			};
		};
	int dxp;                       // horz size in pixels or 0 for default
	int dyp;                       // vert size in pixels or 0 for default
	} MSOTCR;
#endif //MSO_NO_INTERFACES

// the simple TCR for use by FDoSimpleContextMenu
// NOTE: nothing is this structure is ever freed by Office.
#ifndef MSO_NO_INTERFACES
typedef struct _msostcr
	{
	int tcid;				// tcid of button, required
	int tbbs;				// state of button if different than enabled unchecked (= msotbbsUp = 0)
	BOOL fBeginGroup;		// TRUE if you want a separator before, FALSE otherwise
	BOOL fNoCustomize;	// TRUE if this control should not be customizable (doesn't matter for short-lived context menus)
	BOOL fDisabled;		// TRUE if control should be disabled
	WCHAR *wtz;				// label if you want to override, NULL otherwise
	WCHAR *wtzHelpFile;  // helpfile for quicktip
	int iHelpContext;		// help id for quicktip
	void *ppv;				// ignored by FDoSimpleContextMenu, put what you want there
	} MSOSTCR;

// MSOSTCR's extended cousin for FDoComplexContextMenu.
// Currently supports only three control types
// - msotctButton - set tcid and/or wtz
// - msotctLabel - set wtz
// - msotctMenu - set tcid (from msomenu.h) and pitb
typedef struct _msoctcr
	{
	int tcid;				// tcid of control
	int tbbs;				// state of button if different than enabled unchecked (= msotbbsUp = 0)
	int tbct;				// toolbar control type, use msotbbt settings here.
	BOOL fBeginGroup;		// TRUE if you want a separator before, FALSE otherwise
	BOOL fNoCustomize;	// TRUE if this control should not be customizable (doesn't matter for short-lived context menus)
	BOOL fDisabled;		// TRUE if control should be disabled
	WCHAR *wtz;				// label if you want to override, NULL otherwise
	WCHAR *wtzHelpFile;  // helpfile for quicktip
	int iHelpContext;		// help id for quicktip
	void *ppv;				// ignored by FDoComplexContextMenu, put what you want there
	int tct;					// Type of control: msotctButton, msotctMenu or msotctLabel
	interface IMsoControlUser *picu; 
								// Control user for really complex controls.  Use NULL in most cases.
	interface IMsoToolbar *pitb;
								// Toolbar set of submenu (must set tct=msotctMenu) else NULL.
	union
		{
		ULONG uFlags;
		struct
			{
			ULONG
				fRadio	: 1,	// fTrue iff it should be managed as a radio button
				unused	: 31;	// Future expansion.
			};
		};
	} MSOCTCR;

#endif //MSO_NO_INTERFACES

#ifndef MSO_NO_INTERFACES
typedef struct _msogccr
	{
	interface IMsoControlContainer *picc;   // the control container object
	HWND hwndgcc;
	int dx;
	int dy;
	} MSOGCCR;
#endif //MSO_NO_INTERFACES

// Toolbar Update Options (can be ORed together)
#define msotuoFull               0x00  // Normal update (redraw if necc, no interrupts)
#define msotuoNoDraw             0x01  // Don't redraw new state
#define msotuoInterrupt          0x02  // Update is interruptable if input event occurs
#define msotuoMetricChange       0x04  // System metrics have changed, some controls may need to resize
#define msotuoReverseUpdateOrder 0x08  // Causes the sorting order for Toolbar update to be reversed.
                                       //    Used only with TBS::Activate currently.
#define msotuoMainMenuOnly       0x10  // main menu bar only
#define msotuoPaletteChange      0x20  // Palette has changed, some controls may need to redraw
#define msotuoForceDockReflow    0x40  // Force docks to collapse unneccesary space (exiting customize)
#define msotuoUpdateHidden       0x80  // Force an update even though the toolbar is hidden (for GCCs in autolayout)

#ifndef MSO_NO_INTERFACES
// All toolbar and control-related event monitor notifications use this
// structure to pass their arguments
typedef struct _msotbemargs
	{
	interface IMsoToolbarSet *pitbs;	// toolbar set the action occurred in
	interface IMsoToolbar *pitb;		// toolbar the action occurred in
	interface IMsoControl *pic;		// control the action occurred in
	WCHAR *wtz;								// text entered for msotbaEnterTextEm
	int i;									// index for Pick/SwatchSelect/GridSelectEm
	int j;									// index for msotbaSwatchSelect/GridSelectEm
	int mdExit;								// exit code for msotbaPickEm
	int tbbs;								// button state for msotbaCtlClickEm
	} MSOTBEMARGS;
#endif // MSO_NO_INTERFACES

/****************************************************************************
	Toolbar Control structures and constants
****************************************************************** JEFFJO **/

/* Defines for standard office control types.  If a new type is added, 
	update ControlType in mso9.odl, mptctWzName in tb.cpp, and make
	sure you pass word and publisher checkin tests. */
enum
	{
	msotctNil    = -1,     		// Not a valid tct
	msotctCustom = 0,      		// Application-defined control type
	msotctButton = 1,      		// Standard toolbar button

	msotctEdit   = 2,      		// Standard toolbar edit control
	msotctDropdown = 3,    		// Standard toolbar dropdown control
	msotctCombo  = 4,      		// Standard toolbar combo dropdown control
	msotctButtonDropdown = 5,  // Standard toolbar button dropdown control
	msotctSplitDropdown = 6,   // Standard toolbar split-button dropdown control
	msotctOCXDrop = 7,     		// Standard toolbar OCX dropdown control              
	msotctGenericDropdown = 8, // Standard toolbar generic dropdown control
	msotctOwnerDropdown = 9,   // Standard toolbar owner-drawn dropdown control

	// STANDARD MENU CONTROLS
	// Definition of a menu: a control that drops another toolbar
	// All menus use IMsoMenuUser. Not all callbacks are used by all menu types,
	// refer to IMsoMenuUser interface for details.

	// Top part looks like a menu (text + arrow, that rotate if necessary).
	msotctMenu       = 10,

	// Owner-drawn menu control. Two styles, depending on tbct:
	// 0						owner-drawn part is whole control area except for 1 pixel border
	//							on all sides.
	//							Office draws the flat look 3D selection and the background
	// tbmtSDMDropdown	owner-drawn part is "white" area of a SDM-dropdown-look-alike
	//							(subtract (4+scrollbar width) width, 4 height).
	//							Office draws the arrow, border, and "white" background
	// Restriction: when initializing this control, fill its tcr with a sensible size.
	msotctOwnerMenu  = 11,

	// Top part looks like a button.
	// Restriction: when initializating this control, give it a button tcid (for its
	// icon and label).
	msotctMenuButton = 12,

	// Top part looks like a split button.
	// Button part is drawn by the app.
	msotctSplitMenu  = 13,
	
	// Top part looks like a split button.
	// The "button" part is handled by the ButtonUser of the last button clicked 
	// in the toolbar the "arrow" part drops down. All MenuUser functions apply to
	// the arrow part.
	msotctMenuController = 14,

	// label control, it's just static text on the toolbar, uses IMsoLabelExUser
	msotctLabel      = 15,

	// EXPANDING GRID CONTROLS

	// Top part looks like a button.
	// uses IMsoExpandingGridUser
	msotctExpandingGrid = 16,

	// expanding grid control with a split button on top
	// if the button is clicked, SelectSwatch(-1, -1) is called
	// uses IMsoExpandingGridUser
	msotctSplitExpandingGrid = 17,

	// Standard toolbar swatch control
	msotctSwatch     = 18,

	msotctGauge      = 19,

	// Owner drawn dropdown with edit on top
	msotctOwnerCombo  = 20,

	// Supports a 'resizeable' window control. Cannot be saved.
	msotctPane = 21,

	// Hosts an ActiveX or DocObj
	msotctActiveX = 22,

	// A spinner control, derived from dropdown.  Edit + spin controls
	msotctSpinner = 23,

	// Extended label control
	msotctLabelEx = 24,

	// WorkPane control - hosts a dialog. Cannot be saved.
	msotctWorkPane = 25,

#ifdef UNDO_WEBPANE_CUT
	// WebPane Control
	// NOTE (rolandr): We have to make the next number identical because outlook assumes that this is the case
	msotctWebPane = 26,
#endif

	// Dropdown with IE 5 auto completion enabled
	msotctAutoCompleteCombo = 26,

	msotctMax       // ********** End of list (add above this line) ********
	};

/* bit fields for control properties, used by IMsoControl::QueryControlProperties() */
#define msocpfRotates	0x00000001	// control rotates by 90 degrees when drawing
												// in vertical dock.
												// If msocpfRotates is true then the following are reversed
												// If the control is msocpfAutosizeH (the long direction)
												// in the top dock, it will still autosize the long direction
												// in the vertical dock when msocpfRotates is set.
#define msocpfAutosizeH     0x00000002  // Autosize in the Vertical direction
#define msocpfAutosizeV     0x00000004  // Autosize in the Horizontal direction
#define msocpfAdminDisabled 0x00000008  // This control was disabled by the admin.
#define msocpfHlType        0x00000010 // Just returns whether it is hyperlink type or not
#define msocpfSticky        0x00000020 // Will this control cause the menu to stay visible even on activation
#define msocpfDropped       0x00000040 // Does this control have its UI dropped (menu, dropdown, etc dropped)
#define msocpfTemporary     0x00000080 // Is this control a temporary control

#include "msobar.h"     // Generated file holding enum for toolbars
#include "msobtn.h"     // Generated file holding enum for buttons
#include "msomenu.h"   // Generated file holding enum for menu controls

#define msotcidUser 32768 // app-custom controls should use tcid >= msotcidUser
#define msotbidUser 32768 // app-custom toolbars should use tbid >= msotbidUser

#define msotcidCustomEdit     msotcidCustom     
#define msotcidCustomDropdown msotcidCustom     
#define msotcidCustomCombo    msotcidCustom     

#define msotcidDropdownStart  7000	// Must be > msotcidBtnMax

/* Control Drag Parts for cdp parameter to FConstrainSize (can be OR-ed together) */
#define msocdpfTop      0x0001
#define msocdpfLeft     0x0002
#define msocdpfBottom   0x0004
#define msocdpfRight    0x0008
#define msocdpfLogical  0x1000 // Do NOT inflate to match current font size

/* Some new msotcid's that haven't officially been changed yet
	defined in terms of their old name. */
/* FUTURE peteren: Make sure we rename these for real. */

#define msotcidCalloutWordRightAngle msotcidCallout // MUST FIX
#define msotcidCalloutWordOneSegment msotcidCallout // MUST FIX
#define msotcidCalloutWordTwoSegment msotcidCallout // MUST FIX
#define msotcidCalloutWordThreeSegment msotcidCallout // MUST FIX



/* This structure currently used to hold the current control style that
	is passed through the control interface via the msoctlenv structure */
#ifndef MSO_NO_INTERFACES
typedef struct _msoceo
	{
	union
		{
		ULONG uceo;     // for bulk init, compares..
		struct
			{
			ULONG wStyle:8,         // bits 0 - 7: 0 == sys standard, 1-127 reserved
			      maskUnused:1,     // bits 8: unused and reserved
			      f3Ddisplay:1,     // bit  9: should the controls be drawn 3 D or flat
			      fInContextMenu:1, // bit 10: in context menu (or dropping from context menu)
			      fInCommandWell:1, // bit 11: in command well in the Customize dialog
			      fInHMenu:1,       // bit 12: The control is currently on an Hmenu
			      fInSDM:1,         // bit 13: The control is in a Gcc inside an SDM dialog
			      fMetricChange:1,  // bit 14: QuerySize should assume metric changes
			      fUnderlineMode:1, // bit 15: draw underline under first &
			      fForceFocus:1,    // bit 16: force selected look (opposite of fForceNoFocus) - only used in command well (?) 
			      fInMainMenu:1,    // bit 17: in a main menu bar
			      fInGcc:1,         // bit 18: is the control in a Gcc (should strip "_" from menu
			      fDropLeft:1,      // bit 19: cascading dropdown should drop to the left
			      fNotTopLevel:1,   // bit 20: control is in bar popped up by another
			      fInMenu:1,        // bit 21: control resides in a menu bar
			      fInCustomize:1,   // bit 22: is the command bar in customize mode?
			      fForceNoFocus:1,  // bit 23: do NOT draw selected, even if it is (opposite of fForceFocus)
				  fUseTextForBlack:1, // bit 24: TRUE if black should be replaced by 3D Text color
			      fMirror:1,        // bit 25: mirrored orientation (rotate 180), see note below
			      fVertical:1,      // bit 26: vertical orientation (rotate left 90)
			      fUNUSED2:1, //fExtraSize:1,     /* UNUSED?? */ // bit 27: extra large if TRUE, else extra small
			      fLarge:1,         // bit 28: standard small or large format
			      fDocked:1,        // bit 29: use standard-size docked state
			      fUNUSED3:1, //fNoGray:1,        /* UNUSED?? */ // bit 30: suppress gray scale (pure B/W)
			      fUNUSED4:1; //fNoColor:1;       /* UNUSED?? */ // bit 31: suppress any non-gray color
			};
		};
	union
		{
		ULONG uceo2;     // for bulk init, compares..
		struct
			{
			ULONG fAltColors:1,
			fSDMLarge:1,
			fNoToolTip:1,
			fMenuReflow:1,          // analogous to setting msotbrMenuReflow
			fAltColors2:1,
			fNoCenterH:1,           // Only valid for Wrapped text buttons
			fCenterBtnText:1,       // Will center the text portion of a splitbutton menu
			fFocusDepressed:1,      // SDMGcc 1st depressed button will take focus on tmmFocus
			fGccKeepUnderline:1,    // Keep the apmersand on the Gcc (for SDM or other reason)
			fReturnKeys:1,          // PreTranslate won't eat keys
			fHyperlinkLook:1,       // Draw button with blue text and underline
			fInWorkPane:1,          // in a workpane command bar
			// NOTE: InCaption, InWPActiveCaption and InWPInactiveCaption represent 4 possible
			// states, so really we only need 2 bits, not 3 for these flags, and check
			// their combinations.  When the day comes we are running low on bits, we can
			// make this change.
			fInCaption:1,           // in a caption bar (like a close button)
			fInWPActiveCaption:1,   // in an active WP caption bar
			fInWPInactiveCaption:1, // in an inactiave WP caption bar
			fNestedGcc:1,           // Non-SDM GCCs nested in panes: changes focus drawing
			fWideItems:1,           // Used for quick-customize menu items
			fSecondPass:1,          // Used for quick-customize menu items
			fDroppedMenuControl:1,  // Control is a menu control, and has its menu dropped
			fGccUseNewLook:1,       // Use the new look for gcc's
			fNothingFancy:1,        // Override desaturation, shadows & popping up, and enables bitmap scaling
			fSwatch:1,              // So drawing knows which background color to use
			fFadeControl:1,         // Fade the control out using info in vai if possible
			fUnused2:9;
			};
		};
	} MSOCEO;       // ctlenv options
#endif // MSO_NO_INTERFACES

/*
NOTE on fMirror and fVertical:
fVertical = 0, fMirror = 0  => horizontal, upright
fVertical = 0, fMirror = 1  => horizontal upside-down, not used
fVertical = 1, fMirror = 0  => rotated 90 left (e.g. docked left if fDocked)
fVertical = 1, fMirror = 1  => rotated 90 right (e.g. docked right if fDocked)
*/

/* This structure is passed through the control interface and
	fully specifies the environment the control lives in.     */
#ifndef MSO_NO_INTERFACES
typedef struct _msoctlenv
	{
	HWND hwnd;		// hwnd containing control
	HDC hdc;       // hdc to draw into
	RECT rc;       // bounding rect of control
	MSOCEO ceo;    // Appearance and behavior options.  See msoceoxxx constants
	RECT *prcUpdate; // bounding rect of Update area (used for WM_PAINTs calling FDraw)
						  //    (if null, there is no update in progress.)
	} MSOCTLENV;
#endif //MSO_NO_INTERFACES


/* This structure is passed into MsoFCreateButtonEx to specify additional
   button attributes. */
#ifndef MSO_NO_INTERFACES
typedef struct _msobax // Button Attributes eXtra
	{
	int tcidFace;   // Specifies a different face, msotcidNil to ignore
	HANDLE hBitmap; // Either a DIB or DDB (or NULL)
	union
		{
		ULONG flags;     // for bulk init, compares..
		struct
			{
			ULONG  fDib:1,    // Is the hBitmap a DIB?
	     	       fDown:1,   // Is the button down?
		          unused:30;
			};
		};
	} MSOBAX;
#endif //MSO_NO_INTERFACES


// Flags for IMsoButtonUser::FClick's grf
#define msobClickNormal	0x0000
#define msobClickDbl		0x0001	// Double-click


// Button states
typedef enum
	{
	msotbbsUp = 0,
	msotbbsDown,
	msotbbsHeld,
	msotbbsNinched,
	msotbbsMax
	} TBBS;

typedef enum
	{
	msotbgasIncrease = 0,
	msotbgasDecrease,
	msotbgasDown,
	msotbgasDrag,
	msotbgasRelease,
	} TBGAS; // Gauge State

// Exit codes for Dropdown/Edit/Combo controls
#define msomdExitClick  0   // user clicked off the control with an item/text selected
#define msomdExitReturn 1   // user pressed return or clicked to select an item/text
#define msomdExitEscape 2   // user pressed Esc key or otherwise cancelled
#define msomdExitTab    3   // User pressed Tab or Shift-Tab.  Set msotbdtSendTab
                            // to get this message rather than a msmdExitReturn.

// Flags for FCanTakeFocus methods
enum { msoctfMouseMove, msoctfMouseDown };

// constants for IMsoToolbar::FPlacePopup
#define msoppNil              0x00000000
#define msoppSticky           0x00000001
#define msoppSelectFirst      0x00000002
#define msoppNoAnimation      0x00000004
#define msoppTbContext        0x00000008
#define msoppPreferLeft       0x00000010
#define msoppPreferRight      0x00000020
#define msoppRightAlign       0x00000040
#define msoppUseMonitorSpace  0x00000080   // for screen use rcMonitor, not rcWork per MONITORINFO
#define msoppGalleryContext   0x00000100   // don't use this
#define msoppNoMenuShadows    0x00000200


// ***** Flags for ghosting (IMsoToolbarSet::FGhostControl) *****

// Search flags. Searching for the control to ghost occurs in this order:
// a) top-level toolbars, other than the main menu
// b) the main menu bar, and all children
// c) all children on top-level toolbars other than the main menu
// a) and c) occur only if msoghostTopLevel is turned on. b) only occurs if msoghostMainMenu is on.
#define msoghostMainMenu		0x01	// search main menu
#define msoghostTopLevel		0x02	// search any top-level toolbar except the main menu

// Animation flags
#define msoghostAnimate			0x10	// does the ghosting animation, else just returns the search results
#define msoghostExecute			0x20	// call Execute on control at end of animation

// Typical uses
#define msoghostDefault			(msoghostMainMenu | msoghostTopLevel | msoghostAnimate)
#define msoghostFull				(msoghostDefault | msoghostExecute)


// used in specifying how the focus should be set or cancelled
// see RequestFocus and NotifyFocus methods
// A means useful on activate, D on deactivate
// (A ) just the focus, with no extra info
#define msotbcFocusOnly				0x0000
// (A ) drop down your UI if you have any
#define msotbcFocusDropdown		0x0001
// (AD) do it instantly, no UI delay
#define msotbcFocusImmediate		0x0002
// (A ) focus was set using keyboard
#define msotbcFocusKeyboard		0x0004
// (A ) do your thing (drop your toolbar, enter edit mode, etc)
#define msotbcFocusActivate		0x0008
// (A ) control was activated/deactivated using Tab
//                      (used by some controls like Edit to activate instantly)
#define msotbcFocusTab				0x0010
// (A ) do as if focus was received from next control (instead of previous)
//                      (used by swatches to activate their last cell)
#define msotbcFocusReverse			0x0020
// (A ) focus is being changed by the control itself
#define msotbcFocusSame				0x0040
// (A ) the mouse button is up (control activated on mouse up)
#define msotbcFocusMouseUp			0x0080
// (AD) the focus is moving vertically (up or down)
#define msotbcFocusVertical		0x0100
// note: 0x0200 and 0x0400 are available
// ( D) for SDM
#define msotbcFocusSDMTerminate		0x0800
// ( D) all popups must be dismissed
#define msotbcFocusTerminate		0x1000
// ( D) sent by control: I carried out my default action, stop tracking (implies Terminate)
#define msotbcFocusComplete		0x2000
// ( D) sent by control: Don't play any button complete sounds. 
//			(Only useful when the control lives on a menu and msotbcFocusComplete is specified.)
#define msotbcNoSound				0x4000
// ( D) sent by control: don't move selection (to minimize flicker in some cases)
#define msotbcFocusDontMove		0x8000

// Flags for IMsoToolbarSet::CToolbars
#define msotbsctTopLevel			0x00
#define msotbsctAll					0x01
#define msotbsctAllFlush			0x02
#define msotbsctGcc					0x03
// This call returns the current count of top level toolbars but only flushes
// the really top level toolbars (no menus, no context menus, no tearoffs, etc)
// Note that this means the count returned can change.
#define msotbsctTopLevelMinFlush	0x04

// Flags for MsoRenderColorSwatch
#define msocsColor					0
// WARNING! Starting here, must be in the same order as the msoidscs constants in ostrman.pp
#define msocsAutomatic				1						// Automatic, with a little color square
#define msocsMoreColor				2
#define msocsNoFill					3
#define msocsNoColor					4
#define msocsNone						5
#define msocsNoLine					6
#define msocsNoShadow				7
#define msocsNo3D						8
#define msocsMoreLineColor			9
#define msocsMoreFillColor			10
#define msocsMoreUnderline			11

#ifdef OBSOLETE
#ifndef MSO_NO_INTERFACES

typedef struct _msotboc         // Proxy list for Toolbar Ole Controls
	{ 
	SHORT fVisible;						// control is in a visible toolbar
	SHORT fOldOleControl;				// control was proxy before remerging
	interface IMsoControl *picClient; // control's address in Client space
	interface IMsoControl *picServer; // proxy control's address in Server space
	} MSOTBOC, *PMSOTBOC;

#endif // MSO_NO_INTERFACES
#endif


/* Enum of string types for the FGetString methods.  Note that the app can 
	map more than one to the same string if they want. */
enum
	{
	msotbstrTooltip = 0,				// Tooltip text to override normal label, if any
	msotbstrStatusText,				// Normal Status bar and/or control description
	msotbstrDisabledStatusText,	// Disabled Status bar and/or control description
	msotbstrBalloonHelp,				// Normal Balloon help text
	msotbstrDisabledBalloonHelp,	// Disabled Balloon help text
	msotbstrParameter,				// Command parameter string (IMsoControl only)
	msotbstrTag,						// User tag string (IMsoControl only)
	msotbstrMSAAText,					// Accessibility text if different from tooltip (swatches only)
	msotbstrGreyText,					// Ask for Click and Type text
	msotbstrMSAAValueText,			// Accessibility value text (for overriding defaults)
	};

#ifndef MSO_NO_INTERFACES
/* WorkPane Callback function pointer definition.
		idWP is the id of the workpane
		tbwpc is the message (see enum below)
		wpInfo is dialog manager specific - for SDM dialogs, it is an MSOWPSDM *
		param1 & param2 are message specific
*/
typedef BOOL (MSOPRIVCALLTYPE* MSOPFNWPCALLBACK)(int idWP, int tbwpc, void * pwpInfo, 
				void * param1, void * param2);

/* Registered WorkPane Invoke callback function pointer definition.
		idWP is the id of the workpane
*/
typedef void (MSOPRIVCALLTYPE* MSOPFNRWPINVOKE)(int idWP, interface IMsoToolbarSet *pitbs);

/* WorkPane Callback enum list */
enum
	{
#ifdef VSMSODEBUG
	// All debug only events should be negative
	
	/* Called when FDebugMessage is called on the workpane
			- at this point SaveBe should be called on the pwpInfo structure
	    in:  param1 = HWND           HWND of dialog
	         param2 = MSOWPCDBGMSG * Debug info needed for SaveBe (see below) */
	msotbwpcDebugMessage = -1,
#endif

	/* Called when the Dialog needs to be created
	    in:  param1 = HWND           Parent's HWND
	    out: param2 = HWND *         HWND of newly created Dialog */
	msotbwpcCreateWindow = 0,

	/* Called when the dialog needs to be destroyed
	    in:  param1 = HWND           HWND of dialog 
	         param2 = unused */
	msotbwpcDestroyWindow,

	/* Called when the window size changes
	    in:  param1 = HWND           HWND of dialog
	         param2 = RECT *         New rectangle */
	msotbwpcSizeWindow,

	/* Called whenever the WorkPane toolbar is updated
	    in:  param1 = HWND           HWND of dialog 
	         param2 = unused */
	msotbwpcUpdate,

	/* Called when the pwpInfo passed into FShowWorkPane is no longer needed
	    in:  param1 = unused
	         param2 = unused */
	msotbwpcFreePwpInfo,
	
	/* Called when the dialog is hidden or shown (notification, not a request)
	    in:  param1 = HWND           HWND of dialog
	         param2 = BOOL           TRUE if showing, FALSE if hiding */
	msotbwpcShowWindow,

	/* Called when the dialog should enter or exit "What's This" help mode
	    in:  param1 = HWND           HWND of dialog
	         param2 = BOOL           TRUE if should enter help mode, FALSE otherwise*/
	msotbwpcSetHelpMode,

	/* Called when the dialog is starting or ending a resizing operation
	    in:  param1 = HWND           HWND of dialog
	         param2 = BOOL           TRUE if resizing is begginning, FALSE if ending*/
	msotbwpcResizing,

	/* Called only for the lite versions of the workpane.  
		in:  param1 = HWND           HWND of dialog
             param2 = MSOWPCMINMAX * (see below) to be filled in 
		return value of FALSE indicates defaults should be used */
	msotbwpcGetMinMax,

	/* Called when the dialog is gaining focus from commandbar land (i.e., as a
		result of a call to FNotifyFocus).
	    in:  param1 = HWND           HWND of dialog
	         param2 = unused */
	msotbwpcSetFocus,

	/* Called when the dialog is losing focus from commandbar land
	    in:  param1 = HWND           HWND of dialog
	         param2 = HWND           HWND of window that should be given focus */
	msotbwpcKillFocus,

	/* Called when a new pane is made current 
		(this is sent regardless of visiblity of the window)
	    in:  param1 = HWND           HWND of dialog
	         param2 = unused */
	msotbwpcNewCurrentPane,
	
	/* Asks whether the given mouse location is over any dropped dialog UI
	   (dropdowns, etc. that exist outside the dialog's rect).  This message should
	   never be sent for a point inside the dialog's rect.
	    in:  param1 = HWND           HWND of dialog
	         param2 = POINT          Cursor point to test
	    returns true if point is in any dialog UI */
	msotbwpcPointInDroppedUI,
	
	/* Sent any time the workpane gains or loses keyboard activation.  Send either
	   on receipt of a msoomWPGainFocus/msoomWPLoseFocus message, or after sending
	   a msotbwpcSetFocus/msotbwpcKillFocus message.
	    in:  param1 = HWND           HWND of dialog
	         param2 = BOOL           TRUE on activation, FALSE on deactivation */
	msotbwpcActivate,

	/* Sent to the currently visible workpane when the app receives a 
		WM_PALETTECHANGED message.
	    in:  param1 = HWND           HWND of dialog
	         param2 = the wParam from the message */
	msotbwpcWM_PALETTECHANGED,

	/* Sent to the currently visible workpane when the app receives a 
		WM_QUERYNEWPALETTE message.
	    in:  param1 = HWND           HWND of dialog
	         param2 = unused */
	msotbwpcWM_QUERYNEWPALETTE,
	};

/* Flags for IMsoToolbarSet::FRegisterWorkPane */
enum
	{
	msorwpDefault       = 0x00000000, // Default registration
	msorwpBeginGroup    = 0x00000001, // Has a menu seperator before it
	msorwpDisabled      = 0x00000002, // Control should be disabled (workpane not currently available)
	msorwpSelected      = 0x00000004, // Item should appear with check mark beside it, or icon highlighted
	};

/* SDM WorkPane struct - filled out partially by the caller, partially by
		creation of the dialog */
typedef struct _msowpsdm
	{
	// To be filled out by caller before passing to TBS::FShowWorkPane
	int 					cabi;		// CAB index for this dialog
	long					dlt;		// dlt for this dialog (from des file)
	int					ctm;		// ctm for this dialog (usually ctmdltFoo)
	interface IMsoToolbarSet * pitbs;	// toolbar set this wp lives in
	void *				pv;		// dialog specific info (anything can be stored here)
										// Note that the dialog will need to handle any SaveBe code for this.
	HINSTANCE		hinst;		// Hinst where the dialog lives - if NULL, we will use vhinstMsoIntl (Dialogs not in Office need to set this)
	void ** 			rgpfn;		// rgpfn for the app where the dialog lives - if NULL, we will use Office's (Dialogs not in Office need to set this)

	RECT 			rc;				// position and size to resize the hwnd.
	// To be filled out by standard pfn when msotbwpcCreateWindow is called
	void *				pComp;	// this will be an MLDComp *.
	void *				hcab;		// this will be an HCAB.
	} MSOWPSDM;

#ifdef VSMSODEBUG
// used for the msotbwpcDebugMessage
typedef struct _msowpcdbgmsg
	{
	HMSOINST hinst;
	UINT message;
	WPARAM wParam;
	LPARAM lParam;
	} MSOWPCDBGMSG;
#endif // VSMSODEBUG

// used for the msotbwpcGetMinMax callback
typedef struct _msowpcMinMax
	{
	int dxMin;
	int dyMin;
	int dxMax;
	int dyMax;
	} MSOWPCMINMAX;

// WorkPane WM_MSO Message wParam defines
// These are also declared in sdmengw.c and MUST remain in sync.
#define msoomWPGainFocus           1000
#define msoomWPLoseFocus           1001
#define msoomWPGetToolbarSet       1002
#define msoomWPGetOrientation      1003
#define msoomWPSetTitle			   1004
#define msoomWPScrollRect          1005
#define msoomWPQueryMouseFocus     1006
#define msoomWPExitedHelpMode      1007
#define msoomWPGetResizingMode     1008
#define msoomWPClientChangedSize  1010

typedef struct _msowpSetTitleInfo
	{
	int	idWP;
	WCHAR * wtzTitle;
	} MSOWPSETTITLEINFO;

/* FindControl callback function pointer definition.  Used by an app to preserve
   tcid mappings to old tcids when the object model does a FindControl. */
typedef BOOL (MSOPRIVCALLTYPE* MSOPFNFCCALLBACK)(int tcid, int *ptcid);

// Possible font types for menus and text buttons
//		Note - additions to this enum list requires changes to 
//			GetOrientedFont and to the size of the font cache, vrghfn.
enum
	{
	msotbftSystem = 0,
	msotbftMenu,
	msotbftLabel,
	msotbftDropdown,
	msotbftTooltip,
	msotbftSDM,
	msotbftToolbarCaption,
	};

#endif // MSO_NO_INTERFACES

/****************************************************************************
	Defines the IMsoControlUser interface

	This interface is the core contract that all application user objects
	must live up to.  This class is never passed to a control user, as
	each control type has a different cu interface which is derived from
	this class.

	The ppv parameter that is passed to each of these methods is the user
	defined data that was specified at control creation time.  This
	pointer to a pointer may be modified by the application at will, and
	is never directly used by MSO.
****************************************************************** JEFFJO **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoControlUser

DECLARE_INTERFACE_(IMsoControlUser, ISimpleUnknown)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	/* Standard FDebugMessage method, with ppv passed in lParam. */
	MSODEBUGMETHOD

	/* Let the user clone the data, return FALSE if unable to do so. If the
		App wants app can also change the IMsoControlUser e.g. during customize
		an app could have different users for command well and regular controls. */
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;

	/* Called just before Release */
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;

	/* User should save contol's client data in open stream pistm */
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;

	/* Return TRUE if control should be visible */
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;

	/* Return TRUE if control should be enabled */
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, void **ppv) 
												PURE;

	/* User creates and returns an IMsoControl of push button type and
		hooks it up to the proper user object and places its address in ppic
		if this particular button has   a shift-state behavior, or if this is a
		non-button control then it has an alternate control for vertical dock.
		The user should return FALSE if no shift state behavior or alternate
		control is desired. */
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;

	/* Lets the app change the label on the fly. The control calls this just
		before using the string for toolbar positioning (reflow).
		wtzOld points to the current label and is read-only. If the app wants
		to change the label, it should copy it in the 257-length buffer that
		wtzNew points to. To keep the label as is, return FALSE. */
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) 
												PURE;

	/* Notification that the action given by 'tba' occurred to the control.
		Return TRUE if the notification was processed.  Returning FALSE will cause
		the notification to be delegated to IMsoToolbarSetUser::FNotifyAction
		if the control lives in a toolbar set. */
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;

	/* Returns whether the control is available for OLE Command bar merging on
		the container side, the server side, neither or both (see msotbcuXXX).  */
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;

	/* Asks the control for a string based on the value of tbstr
		(see msotbstrXXX).  The control should return the string in the wtz
		buffer (limited to 255 chars).  If the control returns FALSE, no string 
		is assumed to have been returned and a generated default will be used
		if necessary. If the control returns TRUE, but the length of the
		string is 0, then no tooltip will be generated or displayed. */
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
			void **ppv, int tbstr, WCHAR *wtz) PURE;
												
	/* Asks the app for the QuickTip help file (in wtzHelpFile, limited to 255 
		chars) and help context (in pidHelpContext).  Unless overridden, this 
		will be called	every time a quick tip is displayed.  Return FALSE if no 
		quick tip is available.  */
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

};
#endif // MSO_NO_INTERFACES

/*****************************************************************************
	 Defines the IMsoPaneUser interface, used by Toolbar Buttons to
	 send messages to the app.
	 A Pane supports a Generic Window.
****************************************************************** JEFFJO **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoPaneUser

DECLARE_INTERFACE_(IMsoPaneUser, IMsoControlUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
													void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	MSOMETHOD_(BOOL, FCreateWindow)(THIS_ interface IMsoControl *pic, 
							void **ppv, HWND hwndParent, RECT *prc) PURE;

	MSOMETHOD_(BOOL, FDestroyWindow)(THIS_ interface IMsoControl *pic, 
							void **ppv) PURE;
	MSOMETHOD_(BOOL, FShowWindow)(THIS_ interface IMsoControl *pic, 
							void **ppv, int nCmdShow) PURE;
	MSOMETHOD_(BOOL, FSetWindowPos)(THIS_ interface IMsoControl *pic, 
							void **ppv, HWND hwndInsertAfter, int x, int y, 
							int dx, int dy, UINT fuFlags) PURE;
	MSOMETHOD_(BOOL, FGetMinMax)(THIS_ interface IMsoControl *pic,
							MSOCTLENV *pce, int * pdxMin, int * pdyMin, int * pdxMax, int * pdyMax);
};
#endif // MSO_NO_INTERFACES

// This is used to specify the action to be taken when
// user clicks on a button customized to be a hyperlink
enum
	{
	msotbbchlQuerySupport = -1,		// To ask if they want Assign Hyperlink control on the customize menu
	msotbbchlTypeNoHyperlink = 0,
	msotbbchlTypeOpenInBrowser,
	msotbbchlTypeInsertPicInFile,
	};

/*****************************************************************************
	 Defines the IMsoButtonUser interface, used by Toolbar Buttons to
	 send messages to the app.
****************************************************************** JEFFJO **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoButtonUser

DECLARE_INTERFACE_(IMsoButtonUser, IMsoControlUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	/* Tbbs is called to determine ToolbarButtonState i.e. which state to draw
		the button in. Return values are msotbbs values above.  */
	MSOMETHOD_(UINT, Tbbs) (THIS_ interface IMsoControl *pic, void **ppv) PURE;

	/* Returns TRUE iff the cursor was set.  If FALSE, Office will pick the
		cursor.  ppv points to the control data; msotbbs is the button's up/down
		state. */
	MSOMETHOD_(BOOL, FSetCursor) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbbs) PURE;

	/* The Click method is called to notify the User that the button has been
		clicked with a new button state of msotbbs and msobClick flags of grf.
		A pointer to the tbbs is is passed as the method is expected to pass
		back the proper resultant state of the button. Method returns TRUE
		iff it processes the click.  In particular, returning TRUE when the
		grf is msobDblClick will prevent any further tracking.  This message is
		send in the DblClick case BEFORE the mouse up to allow buttons to
		"lock" down without any flickering.  The return value in the single
		click case is currently ignored. */
	MSOMETHOD_(BOOL, FClick) (THIS_ interface IMsoControl *pic, 
												void **ppv, int *ptbbs, int grf) PURE;   

	/* If a button's ID is unknown to Office, we call the User to pass us back
		for ID id, pointers to the button strip handle phbstrip, and index to
		the image within that strip piBtn. fLargeBtns determines whether the
		large or small images should be returned. Return FALSE if you don't
		have or want an icon for this button (or were unable to load it), and
		Office will give it a blank/checkmark icon. */
	MSOMETHOD_(BOOL, FFindCustomBtnface) (THIS_ interface IMsoControl *pic, 
													void **ppv, BOOL fDisabled, int id, 
													HBSTRIP *phbstrip,
													int *piBtn, BOOL fLargeBtns) PURE;

	/* If the control has no accelerator, return FALSE, otherwise return TRUE
		and copy the accelerator string in wtz (limit is 255). */
	MSOMETHOD_(BOOL, FWtzGetAccelerator) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz) PURE;

	/* Only called if msotbbtOwnerDraw is passed in to MsoFCreateControl.  User should just
	   return msotbbodNone if not interested in this functionality.

	   Owner is to draw the representation for the control into hdc.  The bounding rect for the
	   control is prcCtl, the bitmap rectangle is prcFace, may be null if no face is appropriate. The
	   ceo provides the context and tbbsx describes state and appearance of the button.
		Depending on odm:

		- odmPredraw: no drawing has occured. Return bitfield described below.
		- odmPostdraw: the control has already drawn it's prescribed parts. Return bitfield below.
		- odmUpdate: the control wants to know if it should redraw. Returns msotbbodNone for no,
			anything else for yes.

	   Returns: a bitfield describing the parts to be drawn by the control if fPreDraw is TRUE,
	   otherwise the return is ignored. See msotbbod* for options. */
	MSOMETHOD_(int, TbbodDraw)(THIS_ interface IMsoControl *pic, void **ppv,
	                             HDC hdc, RECT *prcCtl, RECT *prcFace, MSOCEO ceo,
	                             int tbbsx, int odm) PURE;
};
#endif // MSO_NO_INTERFACES


/*****************************************************************************
	 Defines the IMsoExtButtonUser interface, used by Toolbar Buttons to
	 send messages to the app.
****************************************************************** NITING ***/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoExtButtonUser

DECLARE_INTERFACE_(IMsoExtButtonUser, IMsoButtonUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	// IMsoButtonUser methods
	MSOMETHOD_(UINT, Tbbs) (THIS_ interface IMsoControl *pic, void **ppv) PURE;
	MSOMETHOD_(BOOL, FSetCursor) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbbs) PURE;
	MSOMETHOD_(BOOL, FClick) (THIS_ interface IMsoControl *pic, 
												void **ppv, int *ptbbs, int grf) PURE;   
	MSOMETHOD_(BOOL, FFindCustomBtnface) (THIS_ interface IMsoControl *pic, 
													void **ppv, BOOL fDisabled, int id, 
													HBSTRIP *phbstrip,
													int *piBtn, BOOL fLargeBtns) PURE;
	MSOMETHOD_(BOOL, FWtzGetAccelerator) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz) PURE;
	MSOMETHOD_(int, TbbodDraw)(THIS_ interface IMsoControl *pic, void **ppv,
	                             HDC hdc, RECT *prcCtl, RECT *prcFace, MSOCEO ceo,
	                             int tbbsx, int odm) PURE;

	// IMsoExtButtonUser methods
	/* Returns the subclassed button user */
	MSOMETHOD_(BOOL, FGetAppControlUser)(THIS_ interface IMsoControl *pic, void **ppv,
	                                       interface IMsoControlUser **ppicuApp) PURE;
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoDropdownUser interface

	This is the contract that a user of the dropdown control must support.
****************************************************************** JEFFJO **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoDropdownUser

DECLARE_INTERFACE_(IMsoDropdownUser, IMsoControlUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	/* Return TRUE if the display of the dropdown in its closed state
		is known to have changed since the last time this control was queried.
		It is only necessary to return TRUE if the control has changed in a way
		not normally detected by the control itself (see below).  Most controls 
		can return FALSE and have the control automatically detect changes 
		as explained below.  Note that the "closed" state is the undropped
		state, so only the selected item/text is shown.  Note that this 
		query is per instance of the control, so answering TRUE only applies to 
		one instance (complex optimizations on the app side will require 
		per-instance state in the ppv on the app size).  Answering TRUE will 
		cause the control to redraw.  Answering FALSE will result in the control 
		trying to determine if it needs to redraw as follows:
		   > All dropdown types will call FEnabled and redraw if the enabling 
		     state changes.
			> Text dropdowns, edits, and combos will call GetText and redraw if
			  the text returned is different from that last drawn in the control.
			> Owner-draw dropdowns will call ISelection and redraw if the 
			  selection index changes from what was last drawn.
		Generic dropdown types have only a button in the closed state and 
		therefore do not use this method and redraw automatically only if the 
		enabling changes. */
	MSOMETHOD_(BOOL, FUpdate) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;

	/* Return the text in the display/edit area in wtz (limited to 255 chars). */
	MSOMETHOD_(VOID, GetText) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz) PURE;

	/* Return the iItem-th string in wtz (limited to 255 chars).  
		Set *ptcid to the icon to display to the left of the text, 
		or msotcidNil for no icon, or   msotcidNoIcon for a blank icon. */
	MSOMETHOD_(VOID, GetDropItem) (THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtz, int iItem, int *ptcid) PURE;

	/* Return the number of items.  User should set *pcMRU to the number
	   of items in their MRU list.  Users ignore setting pcMRU if they
	   do not want an MRU.  NOTE:  pcMRU may be NULL if it is not appropriate
		to change the cached value at the time the method is called.  If an
		app wants an MRU, it must check pcMRU for NULL before setting.
		A value of -1 means no MRU, 0 means an empty MRU which will draw
		1/2 the MRU line above the first item.  If you set pfFullSel to
		TRUE, then all items from the top of the list through the currently
		selected item will display as selected.  This value defaults to
		FALSE when passed in. NOTE: pfFullSel may be NULL if it is not
		appropriate to change the cached value. */
	MSOMETHOD_(int, CItems) (THIS_ interface IMsoControl *pic, 
							void **ppv, int *pcMRU, int *pfFullSel) PURE;

	/* Return the selected item index or -1 if none */
	MSOMETHOD_(int, ISelection) (THIS_ interface IMsoControl *pic, void **ppv) PURE;

	/* Item i was just selected, and the user exited via mdExit.  If the
	   dropdown is a split-btn variety, Pick will be called with i == -2
	   when the push button was pressed. */
	MSOMETHOD_(VOID, Pick) (THIS_ interface IMsoControl *pic, 
												void **ppv, int i, int mdExit) PURE;

	/* Returns the text typed in the edit (limited to 255 chars),
		mdExit says how the user left the dropdown. 
		We might sometimes fire EnterText even though the actual text in the
		dropdown has not changed at all; at this point, this is legacy behaviour
		that just to many apps rely on, so we cannot change this and you
		will have to work around or live with it on your side. */
	MSOMETHOD_(VOID, EnterText) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz, int mdExit) PURE;

	/* Return the number of lines the dropdown should display.  The
	   actual size of the dropdown will be smaller if CItems() is
	   less.  Return value of <= 0 allows office to auto-size the
	   dropdown */
	MSOMETHOD_(int, CDropdownLines) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;

	/* Return the width in pixels that the interior of the dropdown
	   should be.  This excludes the width of borders and the scroll
	   bar.  A return value of 0 will make the dropdown the width of
	   the sample, a value of -1 will cause Office to enumerate all
	   strings via GetDropItem and set the width to accomodate the
	   widest string.  After the enum is finished, CDropdownLines
	   will be called again passing in the optimal width in dxOptimal.
	   When dxOptimal is > 0 the user object should just return dxOptimal.
	   This call allows the user to cache the optimal value. */
	MSOMETHOD_(int, DxDropdown) (THIS_ interface IMsoControl *pic, 
												void **ppv, int dxOptimal) PURE;

	/* Return the height of each dropdown item.  A return of 0 will
	   auto-size the elements.  If the return value is too small for
	   the font being used, the value will be increased.  Ignoring
	   pdyStatusBar or setting it to 0 will cause no status bar to be
	   displayed in the dropdown.  -1 causes the height to auto-size to
	   allow a line of text to fit, any positive value will cause the
	   status bar to be that height. */
	MSOMETHOD_(int, DyDropdownItem) (THIS_ interface IMsoControl *pic, 
												void **ppv, int *pdyStatusBar) PURE;

	/* This method is called just before a dropdown is dropped.  This call
	   will precede any calls to ISelection, CItems, and GetDropItem.  Calls
	   to those 3 methods will only occur between the Dropping call an the
	   exit method call (either Pick or EnterText).  NOTE:  Dropping may be
	   called multiple times before a Pick or EnterText is sent.  This can
	   occur when the user hits CTRL-Down multiple times to hide and reshow
	   the dropdown. hfont is the font that will be used to render strings
	   drawn by office.  It is passed to allow apps to perform any sizing
	   calculations they may need to determine what strings to display. 
	   App should check hfont against NULL before using. */
	MSOMETHOD_(void, Dropping) (THIS_ interface IMsoControl *pic, 
												void **ppv, HFONT hfont) PURE;

	/* This method is called on dropdowns that indicated they want a status
	   bar in the DyDropdownItem call.  iSelection is the item that the mouse
		is currently over, iSelection is -1 when the mouse if off the left
		or right edge of the dropdown, -2 when the mouse is off the bottom
		or top.  The user should return the string to be displayed in wtz. */
	MSOMETHOD_(void, UpdateStatusBar) (THIS_ interface IMsoControl *pic, 
												void **ppv, int iSelection, WCHAR *wtz) PURE;
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoWysiwygDropdownUser interface

	This is the contract that a user of the WYSIWYG Font dropdown control 
	must support.
****************************************************************** JEFFJO **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoWysiwygDropdownUser

DECLARE_INTERFACE_(IMsoWysiwygDropdownUser, IMsoDropdownUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;
	MSOMETHOD_(BOOL, FUpdate) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	// IMsoDropdownUser Methods
	MSOMETHOD_(VOID, GetText) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz) PURE;
	MSOMETHOD_(VOID, GetDropItem) (THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtz, int iItem, int *ptcid) PURE;
	MSOMETHOD_(int, CItems) (THIS_ interface IMsoControl *pic, 
							void **ppv, int *pcMRU, int *pfFullSel) PURE;
	MSOMETHOD_(int, ISelection) (THIS_ interface IMsoControl *pic, void **ppv) PURE;
	MSOMETHOD_(VOID, Pick) (THIS_ interface IMsoControl *pic, 
												void **ppv, int i, int mdExit) PURE;
	MSOMETHOD_(VOID, EnterText) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz, int mdExit) PURE;
	MSOMETHOD_(int, CDropdownLines) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(int, DxDropdown) (THIS_ interface IMsoControl *pic, 
												void **ppv, int dxOptimal) PURE;
	MSOMETHOD_(int, DyDropdownItem) (THIS_ interface IMsoControl *pic, 
												void **ppv, int *pdyStatusBar) PURE;
	MSOMETHOD_(void, Dropping) (THIS_ interface IMsoControl *pic, 
												void **ppv, HFONT hfont) PURE;
	MSOMETHOD_(void, UpdateStatusBar) (THIS_ interface IMsoControl *pic, 
												void **ppv, int iSelection, WCHAR *wtz) PURE;

	// IMsoWysiwygUserMethods
	/* This method is called when the Display Font in Font Text is checked
		in the customize dialog. dyHeight is the height of the font in pixels.
		Return the correct LogFont from the ith-item. */
	MSOMETHOD_(BOOL, FGetLogfont) (THIS_ interface IMsoControl *pic,
											void **ppv, int iItem, int dyHeight, LOGFONT *lfw) PURE;
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoSpinnerUser interface

	This is the contract that a user of the spinner control must support.
****************************************************************** TCoon **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoSpinnerUser

DECLARE_INTERFACE_(IMsoSpinnerUser, IMsoDropdownUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	/* IMsoDropdownUser methods */
	MSOMETHOD_(BOOL, FUpdate) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(VOID, GetText) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz) PURE;
	MSOMETHOD_(VOID, GetDropItem) (THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtz, int iItem, int *ptcid) PURE;
	MSOMETHOD_(int, CItems) (THIS_ interface IMsoControl *pic, 
							void **ppv, int *pcMRU, int *pfFullSel) PURE;
	MSOMETHOD_(int, ISelection) (THIS_ interface IMsoControl *pic, void **ppv) PURE;
	MSOMETHOD_(VOID, Pick) (THIS_ interface IMsoControl *pic, 
												void **ppv, int i, int mdExit) PURE;
	MSOMETHOD_(VOID, EnterText) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz, int mdExit) PURE;
	MSOMETHOD_(int, CDropdownLines) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(int, DxDropdown) (THIS_ interface IMsoControl *pic, 
												void **ppv, int dxOptimal) PURE;
	MSOMETHOD_(int, DyDropdownItem) (THIS_ interface IMsoControl *pic, 
												void **ppv, int *pdyStatusBar) PURE;
	MSOMETHOD_(void, Dropping) (THIS_ interface IMsoControl *pic, 
												void **ppv, HFONT hfont) PURE;
	MSOMETHOD_(void, UpdateStatusBar) (THIS_ interface IMsoControl *pic, 
												void **ppv, int iSelection, WCHAR *wtz) PURE;

	/* IMsoSpinnerUser methods */
	MSOMETHOD_(void, IncDec) (THIS_ interface IMsoControl *pic,
												void **ppv, int spinAction, DWORD dwTime) PURE;
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoOCXDropUser interface

	This is the contract that a user of the OCX dropdown control
	must support.
****************************************************************** t-sanjab */
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoOCXDropUser

DECLARE_INTERFACE_(IMsoOCXDropUser, IMsoControlUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	/* Return TRUE to force dropdown to update its contents. */
	MSOMETHOD_(BOOL, FUpdate) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;

	/* Called after the user picks an entry or cancels.  The wtzClsid will be
		NULL if mdExit is msomdExitEscape or if the user picked the Register
		Custom Control item, else it indicates the item picked. */
	MSOMETHOD_(void, Pick) (THIS_ interface IMsoControl *pic,void **ppv, WCHAR *wtzClsid, int mdExit) PURE; 

	/* Called just before the dropdown drops. */
	MSOMETHOD_(void, Dropping) (THIS_ interface IMsoControl *pic,void **ppv, HFONT hfont) PURE;
	
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoOwnerDropdownUser interface

	This is the contract that a user of the owner draw dropdown control
	must support.
****************************************************************** JEFFJO **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoOwnerDropdownUser

DECLARE_INTERFACE_(IMsoOwnerDropdownUser, IMsoDropdownUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	// IMsoDropdownUser methods
	MSOMETHOD_(BOOL, FUpdate) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(VOID, GetText) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz) PURE;
	MSOMETHOD_(VOID, GetDropItem) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz, int i, int *ptcidIcon) PURE;
	MSOMETHOD_(int, CItems) (THIS_ interface IMsoControl *pic, 
												void **ppv, int *pcMRU, int *pfFullSel) PURE;
	MSOMETHOD_(int, ISelection) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(VOID, Pick) (THIS_ interface IMsoControl *pic, 
												void **ppv, int i, int mdExit) PURE;
	MSOMETHOD_(VOID, EnterText) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz, int mdExit) PURE;
	MSOMETHOD_(int, CDropdownLines) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(int, DxDropdown) (THIS_ interface IMsoControl *pic, 
												void **ppv, int dxOptimal) PURE;
	MSOMETHOD_(int, DyDropdownItem) (THIS_ interface IMsoControl *pic, 
												void **ppv, int *pdyStatusBar) PURE;
	MSOMETHOD_(void, Dropping) (THIS_ interface IMsoControl *pic, 
												void **ppv, HFONT hfont) PURE;
	MSOMETHOD_(void, UpdateStatusBar) (THIS_ interface IMsoControl *pic, 
												void **ppv, int iSelection, WCHAR *wtz) PURE;

	// IMsoOwnerDropdownUser methods

	/* Render give the user a hdc and a prc to draw iItem in.  The owner
	   is expected to respect the prc and not draw outside of it.  The user
		draws the item with respect to fSelected, if fSample is true, the
		user is expected to draw the item as the edit box sample. */
	MSOMETHOD_(VOID, Render) (THIS_ interface IMsoControl *pic, void **ppv, 
				HDC hdc, RECT *prc, int iItem, BOOL fSelected, BOOL fSample) PURE;
};
#endif // MSO_NO_INTERFACES


// The following #defines are used for the return value LDropdownEvent
#define msotcgddProcessed  0  // Continue tracking the dropdown
#define msotcgddTerminate  1  // Roll up the dropdown
#define msotcgddBtnUp      2  // Raise the dropdown button, continue tracking


/****************************************************************************
	Defines the IMsoGenericDropdownUser interface

	This is the contract that a user of the generic draw dropdown control
	must support.
****************************************************************** JEFFJO **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoGenericDropdownUser

DECLARE_INTERFACE_(IMsoGenericDropdownUser, IMsoControlUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	/* This method is not used by Generic dropdowns. */
	MSOMETHOD_(BOOL, FUpdate) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;

	/* This method is called just before a dropdown is dropped. */
	MSOMETHOD_(void, Dropping) (THIS_ interface IMsoControl *pic, 
												void **ppv, HFONT hfont) PURE;

	/* Return the size the dropdown should be in ppt. */
	MSOMETHOD_(void, GetDroppedSize) (THIS_ interface IMsoControl *pic, 
												void **ppv, POINT *ppt) PURE;

	/* Sends mouse and keyboard messages to the user.  lResult is to contain
	   the value to return to windows, m_hwndDrop is the dropdown window.
		The user should one of the msotbgdd flags as appropriate. */
	MSOMETHOD_(LRESULT, LDropdownEvent) (THIS_ interface IMsoControl *pic, 
			void **ppv, LRESULT *lResult, HWND hwndDrop, UINT uMessage, 
			WPARAM wParam, LPARAM lParam) PURE;

	/* Draw the prcPaint sub-area of prcWindow of hwnd into hdc. Note
	   that prcWindow insets from the entire hwnd area to account for
		3d borders. */
	MSOMETHOD_(void, Draw) (THIS_ interface IMsoControl *pic, void **ppv, 
			HWND hwnd, HDC hdc, RECT *prcWindow, RECT *prcPaint) PURE;
};
#endif // MSO_NO_INTERFACES

/****************************************************************************
	Defines the IMsoAutoCompleteDropdownUser interface

	This is the contract that a user of the IE 5 autocomplete dropdown control
	must support.
****************************************************************** BILLAV **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoAutoCompleteDropdownUser

DECLARE_INTERFACE_(IMsoAutoCompleteDropdownUser, IMsoDropdownUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	// IMsoDropdownUser methods
	MSOMETHOD_(BOOL, FUpdate) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(VOID, GetText) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz) PURE;
	MSOMETHOD_(VOID, GetDropItem) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz, int i, int *ptcidIcon) PURE;
	MSOMETHOD_(int, CItems) (THIS_ interface IMsoControl *pic, 
												void **ppv, int *pcMRU, int *pfFullSel) PURE;
	MSOMETHOD_(int, ISelection) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(VOID, Pick) (THIS_ interface IMsoControl *pic, 
												void **ppv, int i, int mdExit) PURE;
	MSOMETHOD_(VOID, EnterText) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz, int mdExit) PURE;
	MSOMETHOD_(int, CDropdownLines) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(int, DxDropdown) (THIS_ interface IMsoControl *pic, 
												void **ppv, int dxOptimal) PURE;
	MSOMETHOD_(int, DyDropdownItem) (THIS_ interface IMsoControl *pic, 
												void **ppv, int *pdyStatusBar) PURE;
	MSOMETHOD_(void, Dropping) (THIS_ interface IMsoControl *pic, 
												void **ppv, HFONT hfont) PURE;
	MSOMETHOD_(void, UpdateStatusBar) (THIS_ interface IMsoControl *pic, 
												void **ppv, int iSelection, WCHAR *wtz) PURE;

	// IMsoAutoCompleteDropdownUser methods

	/* Retrieve the AutoComplete list.  The object must provide an IEnumString interface,
		and it may optionally provide an IACList interface. */
	MSOMETHOD_(BOOL, FGetACList) (THIS_ interface IMsoControl *pic, void **ppv, 
				LPUNKNOWN* ppUnk) PURE;
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoMenuUser interface

	This is the contract that a user of the menu control must support.
******************************************************************* JBELT **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoMenuUser

DECLARE_INTERFACE_(IMsoMenuUser, IMsoControlUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// Overrides
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;
	
	/* Called by: all menu types
		Returns the menu group to which this menu belongs, if any. */
	MSOMETHOD_(int,  IMenuGroup) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;

	/* Called by: msotctSplitMenu
		Just like IMsoButtonUser::Tbbs, this gets the state of the button part of
		a split menu. */
	MSOMETHOD_(UINT, Tbbs) (THIS_ interface IMsoControl *pic, void **ppv) PURE;

	/* Called by: msotctOwnerMenu
		Menu face must be drawn in hdc and be entirely contained in prc. Office
		has already drawn the background unless msotbmtSDMDropdown and msotbmtSDMNoBkgd
		were specified. prc fits exactly in the space inside the 3D borders - if
		you want some space between your drawing and the borders, you have to
		shrink prc a little. ptcidIcon and fPreDraw are useless, return value is
		ignored. */
	/* Called by: msotctSplitMenu
					  msotctMenuButton (if msotbmtOwnerDraw was specified)
		Called twice (predraw/postdraw, see ButtonUser::TbbodDraw)
		Same as above, except prc contains the button area only. Return value must
		be a msotbbod constant above. If that return value includes msotbbodFace,
		the icon drawn will be the one corresponding to ptcidIcon (by default,
		Office sets it to the tcid of the control). */
	MSOMETHOD_(int, TbbodDraw) (THIS_ interface IMsoControl *pic, void **ppv,
			HDC hdc, RECT *prc, int *ptcidIcon, MSOCEO ceo, int tbbsx, int odm) PURE;

	/* Called by: msotctSplitMenu
		Called when the button part of a split menu is clicked. */
	MSOMETHOD_(BOOL, FClick) (THIS_ interface IMsoControl *pic, void **ppv,
			int *ptbbs) PURE;
};
#endif // MSO_NO_INTERFACES

#ifdef OWSME
/****************************************************************************
	Defines the IMsoMultiEditUser interface

	This is the contract that a user of the multi-line edit control must support.
****************************************************************** JEFFJO **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoMultiEditUser

DECLARE_INTERFACE_(IMsoMultiEditUser, IMsoControlUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	/* Return TRUE if the display of the dropdown in its closed state
		is known to have changed since the last time this control was queried.
		It is only necessary to return TRUE if the control has changed in a way
		not normally detected by the control itself (see below).  Most controls 
		can return FALSE and have the control automatically detect changes 
		as explained below.  Note that the "closed" state is the undropped
		state, so only the selected item/text is shown.  Note that this 
		query is per instance of the control, so answering TRUE only applies to 
		one instance (complex optimizations on the app side will require 
		per-instance state in the ppv on the app size).  Answering TRUE will 
		cause the control to redraw.  Answering FALSE will result in the control 
		trying to determine if it needs to redraw as follows:
		   > All dropdown types will call FEnabled and redraw if the enabling 
		     state changes.
			> Text dropdowns, edits, and combos will call GetText and redraw if
			  the text returned is different from that last drawn in the control.
			> Owner-draw dropdowns will call ISelection and redraw if the 
			  selection index changes from what was last drawn.
		Generic dropdown types have only a button in the closed state and 
		therefore do not use this method and redraw automatically only if the 
		enabling changes. */
	MSOMETHOD_(BOOL, FUpdate) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
};
#endif // MSO_NO_INTERFACES

#endif //OWSME

/****************************************************************************
	Defines the IMsoLabelUser interface

	This is the contract that a user of the label control must support.
******************************************************************* JEFFJO */
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoLabelUser

DECLARE_INTERFACE_(IMsoLabelUser, IMsoControlUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser overrides
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	// No extra methods!
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoLabelExUser interface

	This is the contract that a user of the extended label control must support.
******************************************************************* JEFFJO */
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoLabelExUser

DECLARE_INTERFACE_(IMsoLabelExUser, IMsoLabelUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser overrides
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	// IMsoLabelExUser ownerdraw method
	/* Note that the hdc passed in may be different from the hdc that would
	   be returned in the ctlenv from a call to GetCtlenv.  A workaround is to
	   copy the hdc into the ctlenv and then restore it before calling
	   ReleaseCtlenv. */
	MSOMETHOD_(BOOL, FDraw)(THIS_ interface IMsoControl *pic, void **ppv, 
				            HDC hdc, RECT *prc) PURE;
	// Let owner specify size
	MSOMETHOD_(void, QuerySize)(THIS_ interface IMsoControl *pic, void **ppv, 
	                            MSOCTLENV *pce, int *pdx, int *pdy) PURE;
};
#endif // MSO_NO_INTERFACES


/*****************************************************************************
	 Defines the IMsoExpandingGridUser interface. Grid controls have a status 
	 bar.
	 Uses: expanding table, expanding columns, highlighting pen...
******************************************************************* JBELT ***/
#ifndef MSO_NO_INTERFACES
typedef struct _msotbcegi {
	int tcid;
	HBITMAP hbmp;
	BOOL fIdentical;
	int dx, dy;
	int cx, cy;
	int cxMax, cyMax;
	int dxBetween, dyBetween;
	BOOL fSelectFromOrigin;
} MSOTBCEGI;    // MSO ToolBar Control Expanding Grid Info, see comments below in FGetSwatches
#endif // MSO_NO_INTERFACES

#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoExpandingGridUser

DECLARE_INTERFACE_(IMsoExpandingGridUser, IMsoButtonUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
   MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	// IMsoButtonUser methods

	// Important note: the methods marked with (*) will be called:
	// - by SplitExpandingGrid, to update the button part
	// - by ExpandingGrid, if FGetSwatches failed or ran out of memory.
	// Other methods are not called by the grids.

	// Called, to get the button part's state (*)	
	MSOMETHOD_(UINT, Tbbs) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;

	MSOMETHOD_(BOOL, FSetCursor) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbbs) PURE;

	// Called, a click occured on the button part (*)	
	MSOMETHOD_(BOOL, FClick) (THIS_ interface IMsoControl *pic, 
												void **ppv, int *ptbbs, int grf) PURE;
	MSOMETHOD_(BOOL, FFindCustomBtnface) (THIS_ interface IMsoControl *pic, 
												void **ppv, BOOL fDisabled, int id, 
												HBSTRIP *phbstrip, int *piBtn,
												BOOL fLargeBtns) PURE;
	MSOMETHOD_(BOOL, FWtzGetAccelerator) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz) PURE;

	/* Called by all grids to let you decorate the button. */
	MSOMETHOD_(int, TbbodDraw)(THIS_ interface IMsoControl *pic, void **ppv,
	                             HDC hdc, RECT *prcCtl, RECT *prcFace, MSOCEO ceo,
	                             int tbbsx, int odm) PURE;

	/* Called when the control first drops down its thing. App must fill pegi.
		depending on tcid:

		case tcid == msotcidNil: app-custom bitmaps or renderings
			{
			if hbmp != NULL, all swatches will use that same bitmap for their patterns
								  (fIdentical is forced to TRUE). Background is white, or 
							     selected color if selected. Only monochrome bitmaps supported.
			if hbmp == NULL,
				if fIdentical == TRUE,
								  Office will draw empty swatches with white/selection color.
				if fIdentical == FALSE,
								  TcidRenderSwatch will be called for each swatch.
			dx and dy specify the size of each swatch (must match size of bitmap if given).
			}

		case tcid == msotcidUser: different Office bitmap in each swatch
			{
			dx and dy are ignored, hbmp should be NULL, fIdentical should be FALSE
			Office will set the swatch size (dx and dy) to be whatever the current button size,
			and expect to be returned an Office tcid when calling the app on TcidRenderSwatch.
			The app should return a different tcid for each swatch, and Office will draw the
			bitmap there. *** The returned tcid must always be < msotcidUser ***
			}

		case tcid > msotcidNil (for instance, tcid = msotcidPagePreview):
			{
			dx and dy are ignored, hbmp should be NULL, fIdentical should be TRUE
			Office will set the swatch size (dx and dy) to be whatever the current button size,
			and will draw in each swatch the bitmap corresponding to tcid. TcidRenderSwatch is
			never called.
			}

		cx and cy are the initial number of columns & lines.
		cxMax and cyMax are the maximum number of columns & lines. The control limits
			this to the available space on screen, so MAXINT is safe.
		dxBetween and dyBetween is the number of pixels between each cell (excluding the
			border around each). Default is 2.
		fSelectFromOrigin should be TRUE if, when swatch (x, y) is selected, all 
			swatches down to (1, 1) should be selected as well. Note that swatch indexes
			go from (0, 0) to (cxMax-1, cyMax-1).
		This callback is queried each time the control is dropped, allowing for instance
			Word to change its cxMax and cyMax for the Multiple Page button in Print Preview.
		If app returns FALSE, then the expanding grid control behaves just like a button
			(like Word's Table control does when the cursor is already in a table). */
	MSOMETHOD_(BOOL, FGetSwatches) (THIS_ interface IMsoControl *pic, 
												void **ppv, MSOTBCEGI *pegi) PURE;

	/* Tells the app to render swatch (x, y), in context hdc and rectangle prc.
		If returned value is != msotcidNil, Office draws the built-in bitmap in
		the swatch. So, depending on the case:

		- app-custom rendering: don't draw outside prc, since no clipping is done. 
		If fSelected is TRUE, swatch should be rendered in "selected" state. Return
		msotcidNil.

		- you want Office to draw a built-in bitmap itself: return the tcid you want
		Office to draw in this swatch. */
	MSOMETHOD_(int, TcidRenderSwatch) (THIS_ interface IMsoControl *pic, 
				void **ppv, HDC hdc, RECT *prc, int x, int y, BOOL fSelected) PURE;

	/* App should fill wtz with text to draw in the status bar. (x, y) is the 
		swatch currently selected, if x == -1, it means no swatch is selected at 
		all. */
	MSOMETHOD_(void, UpdateStatusBar) (THIS_ interface IMsoControl *pic, 
												void **ppv, int x, int y, WCHAR *wtz) PURE;

	/* Tells the app swatch (x, y) was selected, (-1, -1) means the grid was cancelled. */
	MSOMETHOD_(void, SwatchSelect) (THIS_ interface IMsoControl *pic, 
												void **ppv, int x, int y) PURE;
};
#endif // MSO_NO_INTERFACES


/*****************************************************************************
	Defines the IMsoSwatchUser interface. No status bar.
	Uses: Pattern, Color, Border, Chart, Tools pickers.
******************************************************************* JBELT ***/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoSwatchUser

// built-in default swatch sizes
// cells will be sized either small or large, depending on where the swatch lives:
//		top-level toolbar: MsoFGetButtonSize() setting
//		SDM GCC or dropping from a SDM GCC: always small
#define msodssdxButton		-1	// default button width
#define msodssdyButton		-1	//	default button height
#define msodssdxColorText8	-2	// default text color cell width: assume 8 color cells with dxBetween = 2
#define msodssdyColorText	-2	// default text color cell height appropriate for "None" and "Automatic" swatches drawn with MsoRenderColorSwatch
#define msodssdxColor		-3	// default color cell width (16 or 24)
#define msodssdyColor		-3	// default color cell height (16 or 24)

// swatch flags
#define msoswfNoDrawTrack					0x0001	// if you want to draw the 3D thing around the cell yourself
#define msoswfRedrawOnPaletteChange		0x0002	// if you are sensitive to palettes
// FUTURE: msotbctPaletteSensitive for all controls

typedef struct _msoswatchinfo
	{
	int swf;				// swatch flags, use msoswfxxx
	int dxCtl, dyCtl; // preferred width and height of whole control
							// Office will override if too small; use 0 if don't care
	int dx;				// width of each cell
							// if msodssdxButton (default), Office will use current button width
							// if msodssdxColor, Office will use default color cell width
	int dy;				// height of each cell.
							// if msodssdyButton (default), Office will use current button height
							// if msodssdyColorText, Office will use height appropriate for "None" and "Automatic" swatches drawn with MsoRenderColorSwatch
							// if msodssdyColor, Office will use default color cell height
	int cx, cy;       // number of columns and lines
	int dxBetween,  	// number of horizontal pixels between each cell (default: 2)
		 dyBetween;    // number of horizontal pixels between each cell (default: 2)
	int xCur, yCur; 	// current selection, set xCur = -1 (default) if none
	} MSOSWATCHINFO;

DECLARE_INTERFACE_(IMsoSwatchUser, IMsoControlUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;

	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	/* App should fill psi. See comments for MSOSWATCHINFO above. */
	MSOMETHOD_(void, GetSwatches) (THIS_ interface IMsoControl *pic, 
												void **ppv, MSOSWATCHINFO *psi) PURE;

	/* pxCur and pyCur contain the current selection. If you want to change it,
		store new values in pxCur and pyCur. Return values:
		- msosupdNone: nothing changed at all.
		- msosupdSelection: only pxCur and pyCur changed.
		- msosupdAll: contents of cells may have changed, so the whole control
			must be redrawn (example: colors rotating in a MRU swatch). */
	MSOMETHOD_(int, SupdUpdate) (THIS_ interface IMsoControl *pic, 
												void **ppv, int *pxCur, int *pyCur) PURE;

	/* Tells the app to render swatch (x, y) in context hdc and rectangle prc. 
		fCurrent is TRUE if that swatch is the current selection. If you draw your
		own thing in the swatch, return msotcidNil. You can also return the
		msotcidxxx of a control to have Office draw that icon in there (I suggest
		you return dx = dy = -1 in GetSwatches to have Office set the size too).
		tbbsx is a set of msotbbsx flags, of primary interest is msotbbsxDisabled.
		If you set fDrawTrack to FALSE in GetSwatches, then the following applies:
		- you should inflate prc to draw the mouse selection _around_ the cell. 
		- fSelected is TRUE if the swatch is currently selected by the mouse
			or the keyboard.
		- prc is never "pressed" down. */
	MSOMETHOD_(int, TcidRenderSwatch) (THIS_ interface IMsoControl *pic,
												void **ppv, HDC hdc, RECT *prc,
												int x, int y, BOOL fSelected, BOOL fCurrent,
												int tbbsx) PURE;

	/* Tells the app swatch (x, y) was selected. If you return TRUE, the current
		selection is moved to swatch (x, y). */
	MSOMETHOD_(BOOL, FSwatchSelect) (THIS_ interface IMsoControl *pic, 
												void **ppv, int x, int y) PURE;

	/* Same as FGetString, but also gives row and column number. This is currently
		used only for tooltips (msotbstrTooltip), and enable the app to give a
		different tooltip for each cell. On failure, falls back on FGetString.
		NOTE: it is impossible to override a per-cell tooltip. */
	MSOMETHOD_(BOOL, FGetStringEx) (THIS_ interface IMsoControl *pic, 
			void **ppv, int tbstr, WCHAR *wtz, int x, int y) PURE;

	/* App should return number of "enabled" cells in the swatch. Inactive cells
		won't track and will look like they don't exist at all (example: MRU swatch).
		Any value outside 0 -> total number of cells will make all cells enabled. */
	MSOMETHOD_(int, CCells) (THIS_ interface IMsoControl *pic, void **ppv) PURE;

	/* Typically, when you draw something palette-dependent in an owner-drawn control,
		you select your palette in the hdc, draw your stuff, and select the old palette
		back in. Swatches may have many owner-drawn elements, so here is a callback
		for optimization.
		If what you render in each cell is palette-dependent (like colors swatches),
		you should select and realize your palette in the given hdc. Return the old
		palette. Office will call TcidRenderSwatch (possibly on multiple cells), then
		will select the old palette back.
		Return NULL if you didn't change the current palette or don't care about
		this functionality.
		Called only if you specified msoswfRedrawOnPaletteChange. */
	MSOMETHOD_(HPALETTE, HpalRealize) (THIS_ interface IMsoControl *pic,
			void **ppv, HDC hdc) PURE;
};
#endif // MSO_NO_INTERFACES


/*****************************************************************************
	 Defines the IMsoGaugeUser interface, used by Toolbar gauges to
	 send messages to the app.
***************************************************************** chrismcb **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoGaugeUser

DECLARE_INTERFACE_(IMsoGaugeUser, IMsoControlUser)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlUser methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoControl *pic, 
												void *pvSrc, void **ppvDest,
												IMsoControlUser **ppicu) PURE;
	MSOMETHOD_(void, NotifyDelete) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ interface IMsoControl *pic, 
												void **ppv, LPSTREAM pistm) PURE;
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FEnabled) (THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetAlternateControl) (THIS_ interface IMsoControl *pic, 
												void **ppv, interface IMsoControl **ppic)
												PURE;
	MSOMETHOD_(BOOL, FChangeLabel) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtzOld, WCHAR *wtzNew) PURE;
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tba) PURE;
	MSOMETHOD_(int, TbcuOleUsage)(THIS_ interface IMsoControl *pic, 
												void **ppv) PURE;
	MSOMETHOD_(BOOL, FGetString) (THIS_ interface IMsoControl *pic, 
												void **ppv, int tbstr, WCHAR *wtz) PURE;
	MSOMETHOD_(BOOL, FGetQuickTip)(THIS_ interface IMsoControl *pic, 
							void **ppv, WCHAR *wtzHelpFile, int *pidHelpContext) PURE;

	/* Tells the app the current state. App returns the percentage (0-100), and
		TRUE if the text should be updated */
	MSOMETHOD_(BOOL, FClick) (THIS_ interface IMsoControl *pic, void **ppv, 
				int gas, int *pprcnt) PURE;

	MSOMETHOD_(BOOL, FGetDisplayedText) (THIS_ interface IMsoControl *pic, 
												void **ppv, WCHAR *wtz) PURE;

	MSOMETHOD_(int, PrcntGet) (THIS_ interface IMsoControl *pic, void **ppv) PURE;
};
#endif // MSO_NO_INTERFACES



/*****************************************************************************
	 Defines the IMsoFilterKeyEvents interface, which can be supported as an
	 additional interface off of some control user interfaces to allow the 
	 control user to process keys that would normally be sent to the control.
	 Currently only supported as an extention of IMsoDropdownUser for edits 
	 and combo boxes.
******************************************************************* DAVEPA **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoFilterKeyEvents

DECLARE_INTERFACE_(IMsoFilterKeyEvents, ISimpleUnknown)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	/* Return TRUE to prevent further processing of the keyboard message given
		by (msg, wParam, lParam), which is being processed by the given control. */
	MSOMETHOD_(BOOL, FFilterKeyMessage) (THIS_ interface IMsoControl *pic, 
			void **ppv,	UINT msg, WPARAM wParam, LPARAM lParam) PURE;
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoControl interface

	This interface is the contract that all MSO controls must live up to.
	It defines all the messages a control must be able to respond to.  This
	contract must be valid for application created controls as well.
****************************************************************** JEFFJO **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoControl

DECLARE_INTERFACE_(IMsoControl, ISimpleUnknown)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	/* Standard FDebugMessage method */
	MSODEBUGMETHOD

	/* Free the control. */
	MSOMETHOD_(void, Free) (THIS) PURE;

	/* Make an identical but disjoint copy of the current control.
		A pointer to the new Control is returned
		Returns TRUE if control is created */
	MSOMETHOD_(BOOL, FClone) (THIS_ interface IMsoControl **ppicNew,
					interface IMsoControlSite *pics) PURE;

	/* If 'fDisable' then disable the control (which overrides whether the
		control would normally be enabled at any given time), else return
		to automatic enabling.  Do not redraw any appearance changes yet
		(mark the control dirty and wait for FUpdate or FDraw). */
	MSOMETHOD_(void, Disable) (THIS_ BOOL fDisable) PURE;

	/* Return TRUE if the control has been disabled via Disable(). 
		Note that this returns just the overridden disabled state, not the
		current automatic enabling (see FAutoEnabled()). */
	MSOMETHOD_(BOOL, FDisabled) (THIS) PURE;

	/* Return TRUE if the control would normally be enabled based on the 
		current state of the app, regardless of whether the control has been
		disabled via Disable().  Thus the actual current enabled state of a 
		control is determined by (!FDisabled() && FAutoEnabled()). */
	MSOMETHOD_(BOOL, FAutoEnabled) (THIS) PURE;

	/* Returns TRUE only if the control is displaying its label, according
		to its own internal flags, and the flags in pceo. Used by the toolbar
		to know which accelerator keys are currently active (for instance, a
		standard button not living in a menu returns FALSE so that pressing 
		Alt-Char doesn't activate it by mistake). */
	MSOMETHOD_(BOOL, FLabelDisplayed) (THIS_ MSOCEO *pceo) PURE;

	/* Update the state of the control to match the current state in the app.
		The control is currently visible if 'fVisible' (controls can use this
		to detect visibility changes and show/hide any contained windows).
		Redraw the control as necessary unless 'tuo' includes msotuoNoDraw.  
		When redrawing, the control can assume that all the bits under the 
		control are valid; they just might be drawn for the wrong state (else
		FDraw will be called).  If 'tuo' contains msotuoInterrupt then 
		the operation should be interrupted if possibly lengthy and an input 
		event becomes available.  Return FALSE if the update was interrupted
		or failed. Set fChanged to true if the control was changed*/
	MSOMETHOD_(BOOL, FUpdate) (THIS_ MSOCTLENV *pctlenv, int tuo, 
			BOOL fVisible, BOOL *pfChanged) PURE;

	/* Draw the control into the hdc and position in 'pctlenv'.
		Return FALSE if failure. */
	MSOMETHOD_(BOOL, FDraw) (THIS_ MSOCTLENV *pctlenv) PURE;

	/* Process the window keyboard or mouse event given by (uMessage,
		wParam, lParam ) for the control at pce and return the
		appropriate WndProc result code.  The control will receive
		keyboard events if it has the focus.  The control will receive
		mouse events whenever the       pointer is inside the control's
		rectangle, unless another control or window has the capture,
		or if the control itself has the capture. */
	MSOMETHOD_(LRESULT, LInputEvent) (THIS_ MSOCTLENV *pce, UINT uMessage,
		   WPARAM wParam, LPARAM lParam) PURE;

	/* Return 0 if offset (x,y) within the control at pce is inside the
		control, or an approximate miss distance in pixels or MAXINT if
		not even close */
	MSOMETHOD_(int, DxyHitTest) (THIS_ MSOCTLENV *pce, int x, int y) PURE;

	/* Set the appropriate cursor for the control at pce with the mouse at
		offset (x,y) within the control.  Return TRUE if a cursor was set or 
		FALSE to use the standard pointer. */
	MSOMETHOD_(BOOL, FSetCursor) (THIS_ MSOCTLENV *pce, int x, int y) PURE;

	/* Return the minimum and maximum horizontal and vertical size for
		the control at pce, and set pce->rect to a rectangle of the
		default size for this control (0,0,dx,dy).  For run mode
		(ceo_fDesignMode is FALSE), a non-equal min and max indicates
		that the control can resize in response to the container
		resize if necessary. */
	MSOMETHOD_(void, QuerySize) (THIS_ MSOCTLENV *pce, int *pdxMin,
				     int *pdxMax, int *pdyMin, int *pdyMax) PURE;

	/* The container is requesting that the control at pce take the size
		indicated by pce->rect.  If this size is not appropriate then
		change pce->rect as little as possible by changing the part(s)
		indicated by cdp (see msocdpfxxx constants) if possible (change
		others too if necessary) to make an appropriate size.  Return
		TRUE if pce->rect was changed or FALSE if the given size is
		acceptable. */
	MSOMETHOD_(BOOL, FConstrainSize) (THIS_ MSOCTLENV *pce, int cdp) PURE;

	/* Save any control type-specific info into 'pistm'.  Return fSuccess. */
	MSOMETHOD_(BOOL, FSave) (THIS_ LPSTREAM pistm, int tbsave) PURE;

	/* Load any control type-specific info from 'pistm', with 'nVer'
		as the version number as loaded by MsoFLoadControl.  Return fSuccess. */
	MSOMETHOD_(BOOL, FLoad) (THIS_ LPSTREAM pistm, int nVer, int tbload) PURE;

	/* Get the control's type (i.e. msotctXXXX).  Non-Office control types
		must return msotctCustom.  */
	MSOMETHOD_(int, TctGet) (THIS) PURE;

	/* Get the control's id (i.e. msotcidXXXX). */
	MSOMETHOD_(int, TcidGet) (THIS) PURE;

	/* Set the control's tcid.  The caller must ensure the id is valid
		for the control's type. */
	MSOMETHOD_(void, SetTcid) (THIS_ int tcid) PURE;

	/* Get the label text of the control (see FSetLabel).   
		The label is limited to 255 chars.  If 'fCurrent' then allow the
		app to change the label on the fly now if allowed, else return the 
		last-queried state (usually current as of the last bar-level FUpdate). */
	MSOMETHOD_(void, GetLabel) (THIS_ WCHAR *wtzLabel, BOOL fCurrent) PURE;

	/* Set the label text of the control.  Label text is used and/or displayed
		in a control-type-depenedent way (perhaps not at all), but all controls
		must at least store and remember a label.  The control object allocates 
		and frees memory for a copy of 'wtzLabel'.  The label is limited to 255 
		chars and passing NULL is allowed to represent an empty label.
		Return FALSE if failure.*/
	MSOMETHOD_(BOOL, FSetLabel) (THIS_ const WCHAR *wtzLabel) PURE;

	/* Return the name of the help file for context help for this control
		in wtz, which has room for 255 chars, or return FALSE if none. */
	MSOMETHOD_(BOOL, FGetHelpFile) (THIS_ WCHAR *wtz) PURE;
	
	/* Set the name of the help file for context help for this control
		to wtz or return FALSE if not allowed to change or failure. */
	MSOMETHOD_(BOOL, FSetHelpFile) (THIS_ WCHAR *wtz) PURE;
	
	/* Return the context help id for this control in 'pid', or return FALSE
		if none. */
	MSOMETHOD_(BOOL, FGetHelpId) (THIS_ int *pid) PURE;

	/* Set the context help id of the control or return FALSE if not allowed
		to change or failure. */
	MSOMETHOD_(BOOL, FSetHelpId) (THIS_ int id) PURE;

	/* Asks the control for a string based on the value of tbstr
		(see msotbstrXXX).  The control should return the string in the wtz
		buffer (limited to 255 chars).  If fGenerate then the control should 
		attempt to generate a default string if there is no special one
		available.  Return FALSE if failure or no string available. */
	MSOMETHOD_(BOOL, FGetString) (THIS_ int tbstr, BOOL fGenerate, WCHAR *wtz) PURE;
												
	/* Set the string given by tbstr (see msotbstrXXX) for the control to
		wtz (limited to 255 chars).  Return FALSE if failure or if the control
		does not support setting that string.  The control may map more than
		one string given by tbstr onto the same string.  In this case, the
		method should still return TRUE if it changed any state.  */
	MSOMETHOD_(BOOL, FSetString) (THIS_ int tbstr, WCHAR *wtz) PURE;

	/* Return the address of the pvClient data pointer in this control,
		or NULL if this control type does not support client data. */
	MSOMETHOD_(void **, PpvClientGet) (THIS) PURE;

	/* Create an IDispatch object for the control-implemented automation 
		object corresponding to the control, if any, and return it in ppidisp,
		or return NULL if this control implements no type-specific automation.
		The IMsoToolbarSet for the containing toolbar set is given by pitbs.  
		Return fSuccess (TRUE if NULL is returned). */
	MSOMETHOD_(BOOL, FGetIDispatchControl) (THIS_
			interface IMsoToolbarSet *pitbs, IDispatch **ppidisp) PURE;

	/* Return the IMsoControlSite object associated with the control. */
	MSOMETHOD_(interface IMsoControlSite *, PicsGetControlSite) (THIS) PURE;

	/* Notifies the control that the focus will be set to pic. The control
		must activate if pic is itself, and deactivate otherwise. This
		means (un)highlighting, showing or hiding popups, etc. Use pce for
		redraw if necessary (pce is always the CTLENV of the control this
		this method is called on, and not the CTLENV of pic). fuFocus further
		specifies how the focus is to be set or released on the control
		(see msotbcFocusxxx constants). Must return TRUE. */
	MSOMETHOD_(BOOL, FNotifyFocus) (THIS_ MSOCTLENV *pctlenv,
			BOOL fGaining, interface IMsoControl *pic, UINT fuFocus) PURE;

	/* Notifies the control that the action given by 'tba' occured
		(see msotbaXXX). */
	MSOMETHOD_(void, NotifyAction) (THIS_ int tba) PURE;

	/* Execute the control's default action, if any.  For example, button
		controls execute their click action, menu controls drop their menu.
		User-defined controls will execute their "OnAction" code, if any. 
		Return FALSE iff failure (return TRUE if no default action). */
	MSOMETHOD_(BOOL, FExecute) (THIS) PURE;

	/* Ask a control, which may have its own HWND to destroy it's current HWND
		and recreate it with a new parent. This method is used to regenerate the
		toolbar during dock transitions.  NOTE:  If hwndToolbar is NULL this
		means that the toolbar window is about to be destroyed and the
		control should destroy any windows it is currently displaying and
		reset it's internal state to reflect this. */
	MSOMETHOD_(BOOL, FHwndRecreate) (THIS_ HWND hwndToolbar) PURE;

	/* This routine gets the alternate control, if we haven't yet queried the
		App for alternate control it will do so. */
	MSOMETHOD_(IMsoControl *, PicAlternateGet) (THIS) PURE;

	/* Return TRUE if the control should normally be visible with the given 
		ceo.  Note that the container can override this and force a control
		to be hidden (but it cannot force it to be visible). Implementation of
		this method may/should call picu->FAutoVisible() to determine visibility
		when necessary. */
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ MSOCEO *pceo) PURE;

	/* Return TRUE if the control supports OnAction macros. */
	MSOMETHOD_(BOOL, FSupportsOnAction) (THIS) PURE;

	/* Set the OnAction macro reference string for the control to a copy of wtz
		(limited to 255 chars).  If wtz is NULL then remove any macro reference.  
		Return FALSE if failure. */
	MSOMETHOD_(BOOL, FSetOnAction) (THIS_ WCHAR *wtz) PURE;

	/* If the contol has an OnAction macro reference then copy it into wtz
		if non-NULL (limited to 255 chars) and return TRUE, else return FALSE.  
		If wtz is NULL then just return TRUE if the control has a macro. */
	MSOMETHOD_(BOOL, FGetOnAction) (THIS_ WCHAR *wtz) PURE;

	/* If the control has no accelerator, return FALSE, otherwise return TRUE
		and copy the accelerator string in wtz (limit is 255). */
	MSOMETHOD_(BOOL, FGetAccelerator) (THIS_ WCHAR *wtz) PURE;

	/* Return the control's tbidMenu (see MsoFCreateControl), or msotbidNil 
		if none. */
	MSOMETHOD_(int, TbidMenuGet) (THIS) PURE;

	/* Return the 'sub' toolbar associated with this control.
		For example, a menu control will return the toolbar that it pops up */
	MSOMETHOD_(interface IMsoToolbar *, PitbGet) (THIS) PURE;

	/* Set the 'sub' toolbar associated with this control.
		return FALSE if unable, or unwilling to set it. */
	MSOMETHOD_(BOOL, FSetPitb) (THIS_ interface IMsoToolbar *pitb) PURE;

	/* Get the control's tbct flags (see MsoFCreateControl()). */
	MSOMETHOD_(int, TbctGet) (THIS) PURE;

	/* Set the control's tbct flags (see MsoFCreateControl()). */
	MSOMETHOD_(void, SetTbct) (THIS_ int tbct) PURE;

	/* Resets a builtin control to its builtin state*/
	MSOMETHOD_(BOOL, FReset) (THIS) PURE;
	
	/* Set the control site for this control.  USE WITH CAUTION!! */
	MSOMETHOD_(void, SetPics) (THIS_ interface IMsoControlSite *pics) PURE;
	
	/* Display a quick tip under this control */
	MSOMETHOD_(BOOL, FShowQuickTip)(THIS_ MSOCTLENV *pce) PURE;

	/* Get the current button face id i.e. a tcid which corresponds to button
		id as well. For custom button faces e.g. they have been edited it
		would return msotcidNil. Currently for non button controls it will
		return msotcidNil. */
	MSOMETHOD_(int, TcidButtonFaceGet) (THIS) PURE;

	/* Set the current button face id i.e. a tcid which corresponds to button
		id as well. If the tcid doesn't correspond to a valid button id, this
		function will return with failure. Currently it will always fail for
		non button controls. */
	MSOMETHOD_(BOOL, FSetButtonFaceTcid) (THIS_ int tcid) PURE;

	/* Find out if there is a quick tip under this control */
	MSOMETHOD_(BOOL, FHasQuickTip)(THIS) PURE;

	/* Get the default Ole Usage for standard Office controls.  
		WARNING:  Check for msotbcuNotFound return */
	MSOMETHOD_(int, TbcuGetDefault) (THIS) PURE;

	/* If this control has a control user (e.g. a built-in control type),
		return the control user in ppicu and return TRUE, else set *ppicu 
		to NULL and return FALSE. */
	MSOMETHOD_(BOOL, FGetControlUser) (THIS_ interface IMsoControlUser **ppicu) PURE;
	
	/* Returns whether the control is available for OLE Command bar merging on
		the container side, the server side, neither or both (see msotbcuXXX).  */
	MSOMETHOD_(int, TbcuOleUsage)(THIS) PURE;

	/*	The toolbar is getting ready to kill tracking because a click occured outside
		of itself and all its cascading parents. The control should check if the 
		given point in screen coordinates is within its dropped UI if any (dropdowns,
		grids, etc). The point is guaranteed to be outside the toolbar, so it's
		outside the control rectangle and there's no need to check that. If the control
		returns TRUE, then toolbar will kill tracking and end up calling
		FNotifyFocus(Terminate) on the control. If it returns FALSE, the toolbar
		will assume the mouse is within control-specific UI and will do nothing.

		This is called during the PeekMessage stage. It is far preferable to
		dismiss during this stage than after GetMessage, because this lets the
		toolbar not repost messages (which there is no clean way to do in Windows,
		so is pretty buggy in many borderline cases).

		Typical controls do dismiss, because if the click occured outside the
		toolbar, it occured outside themselves. */
	MSOMETHOD_(BOOL, FDismissOnPeekedMouseDown) (THIS_ POINT pt) PURE;
	
	/* Returns flags for control's propetries, specified by msocpf. Caller should
		set bits corresponding to properties of interest to 1. It should return an
		int using same method i.e. setting the bits to 1 if property holds otherwise
		setting it to 0. */
	MSOMETHOD_(int, QueryControlProperties)(THIS_ int cpf) PURE;

	/* Sets whether a custom control is available for OLE Command bar merging on
		the container side, the server side, neither or both (see msotbcuXXX).  
		Only valid on custom (msotcidCustom) controls. */
	MSOMETHOD_(BOOL, FSetTbcu)(THIS_ int tbcu) PURE;

	/* Same as SetTcid but fDirtyTB specifies whether to dirty the toolbar. */
	MSOMETHOD_(void, SetTcidEx) (THIS_ int tcid, BOOL fDirtyTB) PURE;

	/* Same as FSetButtonFaceTcid but fDirtyTB specifies whether to dirty the toolbar. */
	MSOMETHOD_(BOOL, FSetButtonFaceTcidEx) (THIS_ int tcid, BOOL fDirtyTB) PURE;

	/* If the control supports a separate accelerator display (e.g. "Ctrl+S")
		and can set it, then set it to wtz and return TRUE, else return FALSE. */
	MSOMETHOD_(BOOL, FSetAccelerator) (THIS_ WCHAR *wtz) PURE;
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoControlSite interface
****************************************************************** JEFFJO **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE   IMsoControlSite

DECLARE_INTERFACE_(IMsoControlSite, ISimpleUnknown)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;

	/* Standard FDebugMessage method */
	MSODEBUGMETHOD

	// NOTE: no PitbGetToolbar because QueryInterface will get it for you
	
	/* Get the control environment options (MSOCEO) for the control site. */
	MSOMETHOD_(void, GetCeo) (THIS_ MSOCEO *pceo) PURE;

	/* Get a MSOCTLENV for the control at 'pic' for temporary use.  
		If 'pic' is NULL then the MSOCTLENV.rc will be returned as empty.
		Other options are determined by ctlenvf (see msoctlenvfXXX).
		The MSOCTLENV must be released with ReleaseCtlenv when done. */
	MSOMETHOD_(void, GetCtlenv) (THIS_ interface IMsoControl *pic, 
			int ctlenvf, MSOCTLENV *pctlenv) PURE;

	/* Release a MSOCTLENV that was fetched by GetCtlEnv. */
	MSOMETHOD_(void, ReleaseCtlenv) (THIS_ MSOCTLENV *pctlenv) PURE;

	/* Take the mouse capture so that all mouse messages are sent to the
		control at pic.  If hwnd is non-NULL, then the capture should go to
		this subwindow of the control. */
	MSOMETHOD_(void, TakeCapture) (THIS_ interface IMsoControl *pic, HWND hwnd) PURE;

	/* Release the mouse capture from the control at pic and/or its
		subwindow at hwnd (hwnd should be NULL if none) and restore the
		previous capture, if any. */
	MSOMETHOD_(void, ReleaseCapture) (THIS_ interface IMsoControl *pic, HWND hwnd) PURE;

	/* Tells the site the control has called SetFocus() on its window hwnd. */
	MSOMETHOD_(void, TakeKeyboard) (THIS_ IMsoControl *pic, HWND hwnd) PURE;

	/* Tells the site that the control has released the keyboard focus, the site 
		must now reset it to somewhere decent (typically to the toolbar window 
		itself). */
	MSOMETHOD_(void, ReleaseKeyboard) (THIS_ IMsoControl *pic) PURE;

	/* Sends a FRequestFocus to the toolbar attached to this control site.
		See IMsoToolbar::FRequestFocus. */
	MSOMETHOD_(BOOL, FRequestFocus) (THIS_ interface IMsoControl *pic,
			UINT fuFocus) PURE;

	/* Relayed to IMsoToolbar::FCanTakeFocus. */
	MSOMETHOD_(BOOL, FCanTakeFocus) (THIS_ int ctf) PURE;

	/* Returns the MSOInst associated with the control site */
	MSOMETHOD_(HMSOINST *, HinstGet) (THIS) PURE;

	/* Sends the unprocessed message back for the toolbar to handle.
		If it's a mouse message, hwnd must be the window that originally
		got the message, otherwise give the toolbar window. */
	MSOMETHOD_(LRESULT, LProcessInputMsg) (THIS_ HWND hwnd, UINT msg,
			WPARAM wParam, LPARAM lParam) PURE;
			
	/* Indicate that controls in this control site have been modified
		according to the msoscmXXX constants. */
	MSOMETHOD_(void, SetCtlModified) (THIS_ int scm) PURE;

	/* Returns whether or not the control is currently in a valid state for
	drawing.  Checks the Toolbar's visibility, the control's visibility,
	and makes sure the pce is still valid.  If this returns FALSE, it is
	probably a bad idea for the control to draw with its current state. */

	MSOMETHOD_(BOOL, FIsControlStateValid) (THIS_ interface IMsoControl *pic,
						 MSOCTLENV * pce) PURE;

	/* Returns whether or not the control has another that is trying to
	   mirror its state.  If so, ppicMirror is that control.  This method
	   should be used any time the user via UI changes the control state and
	   is about to cause the default action to occur.  In practice this call
	   is used to correctly update the Mirrored control on a toolbar when the
		control copy in the well is executed.  The caller on a return of TRUE
		should update the state of ppicMirror to match pic. */
	MSOMETHOD_(BOOL, FFindMirroredControl) (THIS_ interface IMsoControl *pic,
	                interface IMsoControl **ppicMirror) PURE;
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoControlContainerUser interface

	This will be used only by generic control container implementation
***************************************************************** RAVINDRA **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE   IMsoControlContainerUser

DECLARE_INTERFACE_(IMsoControlContainerUser, ISimpleUnknown)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	/* Standard FDebugMessage method, with ppv passed in lParam. */
	MSODEBUGMETHOD

	/* Called just before Release */
	MSOMETHOD_(void, NotifyDelete) (THIS_ void **ppv, interface IMsoControlContainer *picc) PURE;

	/*      Called by an Office Control Continaer with op == msogccresizeAsk when the
	Control Container is about      to be resized. The user may change the values of
	*piWidth and/or *piHeight to suggest a better size for the Control Container.
	Then the Control Container will call back to the user with
	op == msogccresizeNotify with the new width and height in *piWidth and *piHeight.
	(The user is not allowed to modify *piWidth or *piHeight when
	op == msogccresizeNotify).*/
	MSOMETHOD_(void, NotifyResize) (THIS_ void **ppv,
											interface IMsoControlContainer *picc,
											int *pdWidth, int *pdHeight, int op) PURE;
};
#endif // MSO_NO_INTERFACES

/****************************************************************************
	Defines the IMsoControlContainer interface
***************************************************************** RAVINDRA **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE   IMsoControlContainer

DECLARE_INTERFACE_(IMsoControlContainer, ISimpleUnknown)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	/* Standard FDebugMessage method */
	MSODEBUGMETHOD

	/* Set the controls for the toolbar to be those in rgctls. If fFreeControls
		is TRUE, Office frees any existing controls on this toolbar, otherwise
		it is up to the app to free/release or otherwise account for them. The
		new controls should already be hooked up to the IMsoControlSite interface 
		of the toolbar. If cctl is -1 then set the bar to the lazy-init state
		(IMsoToolbarUser::FSetToolbarControls will be called when the controls
		are needed). Return fSuccess. */
	MSOMETHOD_(BOOL, FSetControls) (THIS_ int cctl, MSOTCR *rgtcr,
		BOOL fFreeControls) PURE;

	/* Return the number of controls on the toolbar. */
	MSOMETHOD_(int, CControls) (THIS) PURE;

	/* Handle the passed in standard windows message, returning the
		appropriate windows return value */
	MSOMETHOD_(LRESULT, LProcessInputMsg) (THIS_ HWND hwnd, UINT msg,
			WPARAM wParam, LPARAM lParam) PURE;

	/* Update the state of the controls to match the current state in the app.
		Redraw the controls as necessary unless 'tuo' includes msotuoNoDraw.  
		If 'tuo' contains msotuoInterrupt then the operation should be 
		interrupted if possibly lengthy and an input event becomes available.  
		Return FALSE if the update was interrupted, can't be peroformed now
		(e.g. when menu tracking), or failed. */
	MSOMETHOD_(BOOL, FUpdate) (THIS_ int tuo, BOOL *pfChanged) PURE;

	/* Copy the MSOTCR for the control at index ictl in the container
		to ptcr.  Return FALSE iff ictl is out of range. */
	MSOMETHOD_(BOOL, FGetControl) (THIS_ int ictl, MSOTCR *ptcr) PURE;

	/* Set the MSOTCR for the control at index ictl in the container
		to ptcr.  If the IMsoControl field is different than the existing
		one then the old control is NOT freed, so this must be handled by
		the client as necessary.        Return FALSE if failure. */
	MSOMETHOD_(BOOL, FSetControl) (THIS_ int ictl, MSOTCR *ptcr) PURE;

	/* Insert the control in ptcr at index ictl.  Update the display
		if fUpdate.  Return fSuccess. */
	MSOMETHOD_(BOOL, FInsertControl) (THIS_ MSOTCR *ptcr, int ictl, BOOL fUpdate) PURE;

	/* Remove the control at ictl from the container.  If ptcr is NULL then
		free the control, else copy its MSOTCR to *ptcr.  Return fSuccess. */
	MSOMETHOD_(BOOL, FDeleteControl) (THIS_ int ictl, MSOTCR *ptcr) PURE;

	/* Return the address of the pvClient data pointer in this container. */
	MSOMETHOD_(void **, PpvClientGet) (THIS) PURE;

	/* Return the control container user object for this control container,
		which can be NULL for a GCC if none was supplied. */
	MSOMETHOD_(interface IMsoControlContainerUser *, PiccuGetControlContainerUser) (THIS) PURE;

	/* Delete the container from its toolbar set (if any) and free it. */
	MSOMETHOD_(void, Delete) (THIS) PURE;

	/* Returns the visibility of the toolbar. If it is FALSE then toolbar is
		currently hidden. If it is TRUE and the ToolbarSet is visible then this
		toolbar will be showing, or if the ToolbarSet is hidden, this toolbar
		will show if the toolbar set is made visible.

		For Generic Control Containers however it would be actual visibility.
	*/
	MSOMETHOD_(BOOL, FVisible) (THIS) PURE;

	/* Sets the toolbar visibility. If the ToolbarSet is visible the effect is
		immediate, otherwise only the visibility state is updated.

		It will return FALSE if the toolbar is disabled. It will NOT show a
		disabled toolbar, it will hide, but still return FALSE. We determine if
		a toolbar is enabled by IMsoToolbarUser::FEnabled() method.

		For Generic Control Containers however it would be immediate effect.
	*/
	MSOMETHOD_(BOOL, FSetVisible)(THIS_ BOOL fShow) PURE;

	/* Return the toolbar set object that this control container is contained in. */
	MSOMETHOD_(interface IMsoToolbarSet *, PitbsGetToolbarSet) (THIS) PURE;

	/* Returns the Control that has the focus. */
	MSOMETHOD_(int, IctlFocusGet)(THIS) PURE;
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoToolbarUser interface
***************************************************************** RAVINDRA **/

#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoToolbarUser

DECLARE_INTERFACE_(IMsoToolbarUser, ISimpleUnknown)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	/* Standard FDebugMessage method, with ppv passed in lParam. */
	MSODEBUGMETHOD

	/* Return TRUE if the toolbar is normally visible in the current state of
		the App, return FALSE otherwise. For most built in basic toolbars (i.e.
		not menus) it is always TRUE. However some toolbars e.g. Excel's VB bar
		would return TRUE only if the macro ply was currently active, and FALSE
		otherwise. Office96 will assign proper tbv to the toolbars based on this
		query and if the toolbar is about to be shown or hidden.        */
	MSOMETHOD_(BOOL, FAutoVisible) (THIS_ void **ppv, interface IMsoToolbar *pitb) PURE;

	/* Return TRUE if the toolbar at pITB should be enabled based on the
		current state of the document.  Client data pointer at ppv can be
		read or modified. */
	MSOMETHOD_(BOOL, FEnabled) (THIS_ void **ppv, interface IMsoToolbar *pitb) PURE;

	/* User should save contol's client data in open file */
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ void **ppv, LPSTREAM pistm,
												interface IMsoToolbar *pitb) PURE;

	/* User should read contol's client data from open file and set size
		pcb and pointer to it ppv */
	MSOMETHOD_(BOOL, FLoadUserData) (THIS_ void **ppv, LPSTREAM pistm,
												interface IMsoToolbar *pitb) PURE;

	/* When a control is customized, Office will call back ToolbarUser with
		control's old and new (if moved) indice within this toolbar, Customize
		Operation Code, and MSOTCR for the control, so that App could update
		its structures to account for customize. IMsoControlUser::FNotifyDelete()
		is called AFTER we call FCtlCustomized with msocopDelete. */
	MSOMETHOD_(BOOL, FCtlCustomized) (THIS_ void **ppvToolbar, void **ppvControl,
												int iCtl, int iCtlNew, int iCop,
												MSOTCR *ptcr,
												interface IMsoToolbar *pitb,
												BOOL fFullCustomize) PURE;

	/* If the toolbar doesn't have any controls, due to lazy init implementation
		of toolbar by App, we call the App before showing a toolbar and show on
		to init the toolbar by creating necessary controls and then calling Office
		via IMsoToolbar::FSetControls(). App should return FALSE if it cannot create
		any controls or some such failures.. This call is however to be used in other
		situations as well e.g. when a menu is dropped Office will call back the
		App with this to let App make any changes to menu e.g. update a file/window
		list. This call will also be used to reset a menu/toolbar during customization
		by asking the App to fill it with default set of controls. msotbfid are used
		to designate these tasks. */
	MSOMETHOD_(BOOL, FSetToolbarControls) (THIS_ void **ppv, int tbfid,
														interface IMsoToolbar *pitb) PURE;

	/* Called just before Release */
	MSOMETHOD_(void, NotifyDelete) (THIS_ void **ppv, interface IMsoToolbar *pitb) PURE;

	// App generates a string context for us (they'll make any empty string if none)
	MSOMETHOD_(void, GetContext) (THIS_ void **ppv, WCHAR *wtz, interface IMsoToolbar *pitb) PURE;

	// Set new context, or return FALSE if invalid context
	MSOMETHOD_(BOOL, FSetContext) (THIS_ void **ppv, WCHAR *wtz, interface IMsoToolbar *pitb) PURE;

	/* Returns the tbid of the floating toolbar corresponding to this tear-off toolbar.
		This callback is only used if the toolbar was created with msotbtrYesTearOff.
		To be clean, return msotbidNil if you have no tear-offs at all. */
	MSOMETHOD_(int, TbidGetTearOff) (THIS_ void **ppv, interface IMsoToolbar *pitb) PURE;

	/* Let the user clone the data, return FALSE if unable to do so. App will
		also have a chance to change the toolbar user if they want to. */
	MSOMETHOD_(BOOL, FCloneUserClient) (THIS_ interface IMsoToolbar *pitb, 
													void *pvSrc, void **ppvDest,
													IMsoToolbarUser **ppitbu) PURE;

	/* Office calls back to the App to figure out which of the helpers should
		be visible at this time i.e. preview box or cmd text or quick tips!
		App should return value from amond msocdhXXX (defined in this file) in
		the parm piHelper. *piHelper will have the current msocdhXXX in it.

		If needed App can call IMsoToolbarSet::FGetCustomizeDlgInfo() to get
		information about the state of custmoize dialog box selections.
	*/
	MSOMETHOD_(BOOL, FSelectCmdHelper) (THIS_ interface IMsoToolbar *pitb,
													void **ppv, int *piHelper) PURE;

	/* When during customize a user drags a control to create a new control
		on same or another toolbar, Office will call back to the App, to give
		App a chance to create this control for us. This gives App an opportunity
		to modify the necessary properties of control if it so desires. If App
		wants Office to do the default thing, it should just return FALSE, if
		the App returns TRUE, Office would assume that App has done the right
		thing.
	*/
	MSOMETHOD_(BOOL, FCreateControlForCustomize) (THIS_ interface IMsoToolbar *pitb,
													void **ppv, MSOTCR *ptcrSrc,
													interface IMsoToolbar *pitbSrc, BOOL fSrcFromCustDlg,
													MSOTCR *ptcrNew) PURE;

	/* Notification that the action given by 'tba' occurred to the toolbar.
		Return TRUE if the notification was processed.  Returning FALSE will cause
		the notification to be delegated to IMsoToolbarSetUser::FNotifyAction.
	*/
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoToolbar *pitb,
												void **ppv, int tba) PURE;
	MSOMETHOD_(void, SelectTBPalette) (THIS_ interface IMsoToolbar *pitb, 
										HDC hdc, COLORREF cr) PURE;

	/* Ask the app to provide the English string for the given toolbar. Return FALSE
		if you want the Office provided string or the Office 97 behavior. wtz is large
		enough for 255 characters plus the preceeding length and the NULL terminator.
	*/
	MSOMETHOD_(BOOL, FGetNameEnu) (THIS_ interface IMsoToolbar *pitb, void **ppv, 
										WCHAR *wtz) PURE;
};
#endif // MSO_NO_INTERFACES


/****************************************************************************
	Defines the IMsoToolbar interface, it is used by Toolbars.
***************************************************************** RAVINDRA **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE IMsoToolbar

DECLARE_INTERFACE_(IMsoToolbar, IMsoControlContainer)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	// IMsoControlContainer methods
	MSODEBUGMETHOD
	MSOMETHOD_(BOOL, FSetControls) (THIS_ int cCtls, MSOTCR *rgtcr, BOOL fSetControls) PURE;
	MSOMETHOD_(int, CControls) (THIS) PURE;
	MSOMETHOD_(LRESULT, LProcessInputMsg) (THIS_ HWND hwnd, UINT msg,
			WPARAM wParam, LPARAM lParam) PURE;
	MSOMETHOD_(BOOL, FUpdate) (THIS_ int tuo, BOOL *pfUpdate) PURE;
	MSOMETHOD_(BOOL, FGetControl) (THIS_ int ictl, MSOTCR *ptcr) PURE;
	MSOMETHOD_(BOOL, FSetControl) (THIS_ int ictl, MSOTCR *ptcr) PURE;
	MSOMETHOD_(BOOL, FInsertControl) (THIS_ MSOTCR *ptcr, int ictl, BOOL fUpdate) PURE;
	MSOMETHOD_(BOOL, FDeleteControl) (THIS_ int ictl, MSOTCR *ptcr) PURE;
	MSOMETHOD_(void **, PpvClientGet) (THIS) PURE;
	MSOMETHOD_(interface IMsoControlContainerUser *, PiccuGetControlContainerUser) (THIS) PURE;
	MSOMETHOD_(void, Delete) (THIS) PURE;
	MSOMETHOD_(BOOL, FVisible) (THIS) PURE;
	MSOMETHOD_(BOOL, FSetVisible)(THIS_ BOOL fShow) PURE;
	MSOMETHOD_(interface IMsoToolbarSet *, PitbsGetToolbarSet) (THIS) PURE;
	MSOMETHOD_(int, IctlFocusGet)(THIS) PURE;

	/* Set the menu (tracking) focus to ictl, or release it if ictl
		is -1. The container will ask any other control that currently has the
		focus to release it (through FNotifyFocus). fuFocus is a combination
		of msotbcFocusxxx flags that further specify the reason for
		setting/releasing the focus. */
	MSOMETHOD_(BOOL, FRequestFocus) (THIS_ int ictl, UINT fuFocus) PURE;

	/* Return the toolbar user object that this toolbar is connected to. */
	MSOMETHOD_(interface IMsoToolbarUser *, PitbuGetToolbarUser) (THIS) PURE;

	/* Store the properties of the toolbar in ptbp for view specified by itbdp.
		If itbdp is -1 it would return tbp for current current view. If itbdp
		is invalid it would fail. */
	MSOMETHOD_(BOOL, FGetProperties) (THIS_ MSOTBP *ptbp, int itbdp) PURE;

	/* Set the toolbar properties to those at ptbp.  Return fSuccess. Dirty
		the toolbar unless msotbtrDontDirty is set  */
	MSOMETHOD_(BOOL, FSetProperties) (THIS_ const MSOTBP *ptbp, int itbdp) PURE;

	/* Store the name of the toolbar in 'wtz' (limited to 255 chars). */
	MSOMETHOD_(void, GetName) (THIS_ WCHAR *wtz) PURE;

	/* Set the name of the toolbar to 'wtz'.  The name is limited to 255 chars
		and must be a unique name within the toolbar set.
		Return FALSE if failure (name too long, toolbar already in use by another 
		toolbar in this set, if it is a built in toolbar, or OOM). */
	MSOMETHOD_(BOOL, FSetName) (THIS_ const WCHAR *wtz) PURE;

	/* Return the toolbar ID */
	MSOMETHOD_(int, TbidGet) (THIS) PURE;

	/* Save into the open stream pistm the toolbar state corresponding to this
		object to be used to restore it during next session.
		If tbsave == msotbsaveAll, control detail is saved.  Otherwise, only
		toolbar data is saved.  */
	MSOMETHOD_(BOOL, FSave) (THIS_ LPSTREAM pistm, int tbsave) PURE;

	/* Create an IDispatch object for the Toolbar automation object 
		corresponding to this toolbar and return it in 'ppidisp'. 
		return fSuccess. */
	MSOMETHOD_(BOOL, FGetIDispatchToolbar) (THIS_ IDispatch **ppidisp) PURE;

	/* Create an IDispatch object for the ToolbarControls collection 
		automation object corresponding to this toolbar and return it in
		'ppidisp'.  Return fSuccess. */
	MSOMETHOD_(BOOL, FGetIDispatchControls) (THIS_ IDispatch **ppidisp) PURE;

	/* Create an IDispatch object for the ToolbarControl automation object 
		corresponding to the control at index ictl on the toolbar and 
		return it in 'ppidisp'.  Return FALSE if failure and SetLastError to
		DISP_E_BADINDEX if ictl is out of range, or another error. */
	MSOMETHOD_(BOOL, FGetIDispatchControl) (THIS_ int ictl,
			IDispatch **ppidisp) PURE;

	/* Pop up a context menu (command bar) down and to the right of the point
		x, y (adjust position if necessary for visibility). This is to
		be used for top-level popups, and is a modal call.  The pp parameter 
		(stands for PlacePopup) is a bitfield for the msopp* values to change
		how the popup is placed.
		if prc is non-null, it will be passed on as the Rectangle to avoid.
		Otherwise, positioning is done using x,y */
	MSOMETHOD_(BOOL, FPopup) (THIS_ int x, int y, int pp, RECT * prc) PURE;

	/* Mark the Control/Gap  as temporary */
	MSOMETHOD_(BOOL, FSetCtlTemp) (THIS_ int iCtl, int msotempop) PURE;

	/* Mark this toolbar as temporary or not be setting or clearing the 
		msotbtrNoSave flag. */
	MSOMETHOD_(void, SetTBTemp) (THIS_ BOOL fTemp) PURE;

	/* Temporarily Delete the control from the TB, will be added back in
		at save time 
		Returns True if able to delete the control. */
	MSOMETHOD_(BOOL, FTempDelete) (THIS_ int iCtl, int msotempop) PURE;

	/* Make an identical but disjoint copy of the current toolbar hooked
		up to toolbar set pitbs.  A pointer to the new toolbar is given in 
		ppitbNew.  */
	MSOMETHOD_(BOOL, FClone) (THIS_ interface IMsoToolbarSet *pitbs,
							interface IMsoToolbar **ppitbNew) PURE;
	
	/* Determines whether the toolbar has been changed since load or
		initialization.  If not, don't bother saving it! */
	MSOMETHOD_(BOOL, FSaveNeeded) (THIS) PURE;

	/* Returns the control that is currently dropping or that last dropped
		this toolbar. Be careful! Since one toolbar can be dropped by different
		menu controls, the parent can change over time. Returns FALSE if the
		toolbar has no current parent. */
	MSOMETHOD_(BOOL, FGetParentControl) (THIS_ interface IMsoControl **ppic) PURE;

	/* Returns true if the Toolbar is enabled (not disabled through VBA and 
		ToolbarUser response TRUE to FEnabled. */
	MSOMETHOD_(BOOL, FEnabled)(THIS) PURE;

	/* Returns bit flags showing whether the toolbar or its controls has been
		changed and hence needs to be saved (see enum above) */
	MSOMETHOD_(int, TbcsChangeStatus)(THIS) PURE;

	/* If you wish to create your toolbar in a messy way but not have it
		saved as changed, call this when you are done building it.
		Changes after this call will make FSaveNeeded return TRUE. */
	MSOMETHOD_(void, SetInitializationComplete) (THIS) PURE;

	MSOMETHOD(RemUpdateToolbar)(THIS_ int msowp) PURE;
	MSOMETHOD(RemGetProperties)(THIS_ MSOTBP *ptbp, int itbdp) PURE;
	MSOMETHOD(RemSetProperties)(THIS_ MSOTBP *ptbp, int itbdp) PURE;
	MSOMETHOD_(void, Expand)(THIS_ int tbeop) PURE;
	MSOMETHOD_(BOOL, FPriorityDropped) (THIS_ int ictl) PURE;

	/* Make an identical (based on the flags) but disjoint copy of
		the current toolbar hooked up to toolbar set pitbs.  A pointer
		to the new toolbar is given in ppitbNew.  */
	MSOMETHOD_(BOOL, FCloneEx) (THIS_ interface IMsoToolbarSet *pitbs,
							interface IMsoToolbar **ppitbNew,
							UINT grftcFlags) PURE;

	/* Has the toolbar been populated with controls?  Returns true if
	   we aren't waiting to lazy init the array of controls. */
	MSOMETHOD_(BOOL, FControlsCreated)(THIS) PURE;
	MSOMETHOD_(BOOL, FAdaptiveMenus)(THIS) PURE;


	/* Turns off adaptive menus for the toolbar. This is NOT to be called
		without without permission from the Office PM Consitancy police.
		NOTE: only extreme cases for very odd menus will be allowed to
		call this function.
	*/
	MSOMETHOD_(void, SetAdaptiveMenus)(THIS_ BOOL fAdaptiveMenus) PURE;

	/* Mark all controls on the bar as being PIP decayable next session */
	MSOMETHOD_(void, AllowMenuDecay)(THIS) PURE;

	MSOMETHOD_(BOOL, FGetControlPic) (THIS_ IMsoControl * pic, MSOTCR *ptcr) PURE;
	MSOMETHOD_(BOOL, FSetControlPic) (THIS_ IMsoControl * pic, MSOTCR *ptcr) PURE;

	MSOMETHOD_(BOOL, FSetTbtr2) (THIS_ int tbtr2) PURE;
	MSOMETHOD_(int, GetTbtr2) (THIS) PURE;

	// Returns whether the toolbar (menu) is expanded or not
	MSOMETHOD_(BOOL, FExpanded) (THIS) PURE;

	// Sets/Gets one of the private flag members (m_fNeedsPositioning for now)
	MSOMETHOD_(BOOL, FGetFlag) (THIS_ int iFlag) PURE;
	MSOMETHOD_(void, SetFlag) (THIS_ int iFlag, BOOL fVal) PURE;

	// Creates a Workpane lite - don't use without talking to a workpane dev.
	MSOMETHOD_(BOOL, FCreateWPControl) (THIS_  int idWP, MSOPFNWPCALLBACK pfnWPC, 
					void * pwpInfo) PURE;
	MSOMETHOD_(BOOL, FGetMenuLocation) (THIS_ RECT * prcMenu, IMsoControl * pic);
	MSOMETHOD_(BOOL, FCopyDockProperties) (THIS_ IMsoToolbar * pitb);

	/* Determines whether the toolbar has been changed since load or
		initialization.  If not, don't bother saving it!
		The Ex version differs from FSaveNeeded in that the Ex version checks for
		"orphaned" toolbars which need not be saved - Office10: 129230 */
	MSOMETHOD_(BOOL, FSaveNeededEx) (THIS) PURE;

	/* Same as FGetProperties/FSetProperties, only the iRow is defined to be
		visual, not literal. (only if itbdp is the current view or -1 - otherwise
		the iRow is taken as literal...) */
	MSOMETHOD_(BOOL, FGetPropertiesVisualRow) (THIS_ MSOTBP *ptbp, int itbdp) PURE;
	MSOMETHOD_(BOOL, FSetPropertiesVisualRow) (THIS_ const MSOTBP *ptbp, int itbdp) PURE;

	MSOMETHOD_(BOOL, FOfficeOwned) (THIS) PURE;
};
	

#endif // MSO_NO_INTERFACES


/*****************************************************************************
	Defines the IMsoToolbarSetUser interface used for callbacks to the
	application from the ToolbarSet
***************************************************************** RAVINDRA **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE   IMsoToolbarSetUser

DECLARE_INTERFACE_(IMsoToolbarSetUser, ISimpleUnknown)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	/* Standard FDebugMessage method, with ppv passed in lParam. */
	MSODEBUGMETHOD

	/* A control given by tct, tcid, tbct, and tbidMenu needs to be created.  
		If tct != msotctCustom then MsoFCreateControl should be called 
		to create the standard control and hook it up to pics, otherwise 
		the app needs to create the control and hook it up to pics.
		If tct == msotctNil then the app should create a control of default
		type given the tcid if possible.  In all cases, the app should 
		return FALSE if a control consistent with tct and tcid cannot be 
		created.  If successful, return the control in ppic. */
	MSOMETHOD_(BOOL, FCreateControl) (THIS_ 
			interface IMsoToolbarSet *pitbs, void **ppv, int tct, int tcid, 
			int tbct, int tbidMenu, interface IMsoControlSite *pics, 
			interface IMsoControl **ppic) PURE;

	/*      A custom toolbar needs to be created. Application should create a blank
		toolbar and return pitb back to Office96. App should use msotbidCustom
		as tbid when creating the toolbar. And the name should again be selected
		by the App e.g. CustomToolbar1, or UserToolbar2 or whatever they want.
		User would be able to change the name anyway. The function returns TRUE
		if it succeeds, and FALSE otherwise. */
	MSOMETHOD_(BOOL, FCreateCustomToolbar) (THIS_ 
			interface IMsoToolbarSet *pitbs, void **ppv, 
			MSOTBP *ptbp, WCHAR *wtzName, interface IMsoToolbar **ppitb) PURE;

	/*      Requests the Toolbar User to be associated with the toolbar having id
		tbid    and name wtzName.  Used when loading saved toolbar state. Client
		data in ppv can be read or modified.  */
	MSOMETHOD_(interface IMsoToolbarUser *, PitbuGetToolbarUser) (THIS_
			interface IMsoToolbarSet *pitbs, void **ppv, 
			int tbid, WCHAR *wtzName) PURE;

	/* Requests the Control User to be associated with the control having ID
		tcid and control type tct.  The user should load the ppvControl from
		the contents of the open stream pistm (saved by the control user's 
		FSaveUserData)  */
	MSOMETHOD_(interface IMsoControlUser *, PicuLoadUserData) (THIS_ 
			interface IMsoToolbarSet *pitbs, void **ppvTbs, int tcid, int tct,
			LPSTREAM pistm, void **ppvControl) PURE;

	/* Returns a RECT structure in which we can place toolbars */
	MSOMETHOD_(HRESULT, HrGetBorder) (THIS_ 
			interface IMsoToolbarSet *pitbs, void **ppv, RECT * prcBorder) PURE;

	/* Requests the app to resize its client rectangle to leave room
		for docked toolbars given by pbw. */
	MSOMETHOD_(HRESULT, HrSetBorderSpace) (THIS_ 
			interface IMsoToolbarSet *pitbs, void **ppv, LPCBORDERWIDTHS pbw) PURE;
	
	/* Return the toolbar representing the main menu for OLE non-Office 
		toolbar negotiation */                  
	MSOMETHOD_(interface IMsoToolbar *, PitbGetMainMenu) (THIS_ 
			interface IMsoToolbarSet *pitbs, void **ppv) PURE;                      

	/* User should save contol's client data in open stream pistm.
		Return FALSE if the entire toobar set save should be aborted.  */
	MSOMETHOD_(BOOL, FSaveUserData) (THIS_ 
			interface IMsoToolbarSet *pitbs, void **ppv, LPSTREAM pistm) PURE;

	/* User should read contol's client data from open stream pistm and
		set size pcb and pointer to it ppv. 
		Return FALSE if the entire toobar set load should be aborted.  */
	MSOMETHOD_(BOOL, FLoadUserData) (THIS_ 
			interface IMsoToolbarSet *pitbs, void **ppv, LPSTREAM pistm) PURE;

	/* Return the IDispatch object that should be the Parent of this 
		toolbar set in ppidisp.  Return fSuccess. */
	MSOMETHOD_(BOOL, FGetIDispatchParent)(THIS_ 
			interface IMsoToolbarSet *pitbs, void **ppv, IDispatch **ppidisp) PURE;

	/* The toolbar set has changed its own state internally (due to, e.g. 
		automation) and the client should make a note to to call 
		IMsoToolbarSet::FUpdate at its next convenience. */
	MSOMETHOD_(void, UpdateNeeded) (THIS_ 
			interface IMsoToolbarSet *pitbs, void **ppv) PURE;

	/* This is a call back from IMsoToolbarSet::FCustomize(). By this App
		can supply the AddCommand dropdown, and add its own extensions to
		ModifySelection menu, hook up CustomizeKeyboard and so on.

		Please note that IMsoToolbarSet::FCustomize() is called both by App
		through its menus and by Office96() through toolbar context menu,
		hence we need to have this call back to fill in the gap. Also for
		extensibility support and such we need to provide pitbs to the app so
		that they can add/remove/modify the necessary controls.

		pcustcb - details are specified above with the typedef.
		*/
	MSOMETHOD_(BOOL, FSetupCustomize) (THIS_ interface IMsoToolbarSet *pitbs,
									void **ppv, MSOCUSTCB *pcustcb) PURE;

	/* App must create toolbar tbid/wzName (by calling IMsoToolbarSet::FCreateToolbar) 
		and return a pointer to it and fSuccess. Return TRUE if the tbid/wtzName
		is meaningful to you and you were able to create the toolbar (calling us
		on MsoFCreateControl, TBS::FCreateToolbar and so on didn't fail). Return
		FALSE if you don't know what this tbid is or you're currently unable to
		create the toolbar.
		If TRUE and the toolbar you return is lazy-inited, Office will call you back
		right away on IMsoToolbarUser::FSetControls. */
	MSOMETHOD_(BOOL, FCreateToolbar)(THIS_ interface IMsoToolbarSet *pitbs, 
			void **ppv, int tbid, const WCHAR *wtzName, IMsoToolbar **ppitb) PURE;

	/* Notification that the action given by 'tba' occurred to a control or to
		a toolbar or the toolbar set as a whole.
		If 'pic' is non-NULL, then the action is on that control (possibly
		delegated from an IMsoControlUser::FNotifyAction), else the action is
		If 'pitb' is non-NULL, then the action is on that toolbar (possibly
		delegated from an IMsoToolbarUser::FNotifyAction).
		Otherwise the action is on the toolbar set.  Return TRUE if the
		notification was processed.
	*/
	MSOMETHOD_(BOOL, FNotifyAction) (THIS_ interface IMsoToolbarSet *pitbs, 
												void **ppv, interface IMsoToolbar *pitb,
												interface IMsoControl *pic, int tba) PURE;

	/* App should return its MDI client window and fSuccess. If TRUE, *phwdClient
		must be a real MDICLIENT window, or at least able to process WM_MDI messages
		(specifically, WM_MDIGETACTIVE, WM_MDIRESTORE and WM_MDIMAXIMIZE) correctly.
		This will turn on Office's support for MDI system controls on the main menu
		toolbars. See near the bottom of this file for some more details on MDI. */
	MSOMETHOD_(BOOL, FGetMDIClientWindow) (THIS_ interface IMsoToolbarSet *pitbs,
			void **ppv, HWND *phwnd) PURE;

	/* The app should return the appropriate (client) toolbar to merge with 
		the server's toolbar with id tbid, or return FALSE in 
		order to request Office to use a simple algorithm of its own to find 
		the right toolbar. FAlreadyMerged will be TRUE on the second (and 
		subsequent) times a server toolbar is shown.  Returning a toolbar 
		pointer in ppitb will cause re-merging, while returning NULL for the
		toolbar (or FALSE) will cause re-merging not to happen. */

	MSOMETHOD_(BOOL, FClientToolbarGet) (THIS_ interface IMsoToolbarSet *pitbs,
			void **ppv, BOOL fAlreadyMerged, int tbid, IMsoToolbar **ppitb) PURE;

	/* If the app owns their own dock windows, they should return in prc the rectangle
		of the dock for the tbds passed in.  If the app does not own their own dock
		windows, return FALSE. */
	MSOMETHOD_(BOOL, FGetUserOwnedDockWindowRect) (THIS_ interface IMsoToolbarSet *pitbs,
			void **ppv, int tbds, RECT * prc) PURE;

	/* The toolbar set's window has received a WM_MSOTCIDCOMMAND with
		wParam equal to tcid and the given lParam.  Return TRUE to have an
		FClick generated for a button of the appropriate tcid (Office will 
		create a temporary one if necessary).  Returning FALSE will result 
		in no further action. */
	MSOMETHOD_(BOOL, FTcidCommandMessage) (THIS_ interface IMsoToolbarSet *pitbs,
			void **ppv, int tcid, LPARAM lParam) PURE;

	/* The container application should return the type of merging that it is
		allowing to occur.
	*/

	MSOMETHOD_(HRESULT, HrGetMergeOptions) (THIS_ interface IMsoToolbarSet *pitbs,
			void **ppv, DWORD *pdwMergeOptions) PURE;

	MSOMETHOD_(HRESULT, HrNotifyOfOleAction) (THIS_ interface IMsoToolbarSet *pitbs,
			void **ppv, DWORD dwOleAction, DWORD dwParam) PURE;

	/* Called when inplace merging is first occurring. ( During TBS::InplaceActivate).
	The container should respond with ANY tbid's that it wants to ensure
	will be merged with the Office Server's toolbar set.
	Normally, only toolbars that exist in the server toolbarset will be merged.
	By responding to this method, and FClientToolbarGetTBSU, the container can
	force it's own ToolBars to be merged.
	In the case of Office in Non-Office, the container must be prepared to 
	show it's toolbars via an alternative UI.
	
	This method will be called by Office until the application return S_FALSE,
	indicating that it has no more toolbars to contribute. The container will
	return the toolbar id for each of it's toolbars in ptbid.
	*/
	MSOMETHOD_(HRESULT, HrEnumClientToolbars) (THIS_ interface IMsoToolbarSet *pitbs,
			void **ppv, int *ptbid) PURE;

	/* This is used to query the App during customize for duplicate toolbar names,
		if msotbsfQueryAppForDupNames is set, when user tries to create a new toolbar
		or rename an existing one, either in UI or VBA. Typically apps may not want
		to set msotbsfQueryAppForDupNames, and in that case we will do the full flush
		of toolbar set from within Office to look for duplicate name.
	*/
	MSOMETHOD_(BOOL, FIsTbNameDuplicate) (THIS_ interface IMsoToolbarSet *pitbs,
														void **ppv, WCHAR *wtzName) PURE;

	#if LATER
	/* App should return the window of the OLE server embedded in it, and NULL on
		failure (should never happen). This method is only called when you're a
		Office-in-Office OLE client. */
	MSOMETHOD_(BOOL, FGetOLEInPlaceActiveObjectWindow) (THIS_ interface IMsoToolbarSet *pitbs,
			void **ppv, HWND *phwnd) PURE;
	#endif
};
#endif // MSO_NO_INTERFACES


/*****************************************************************************
	 Defines the IMsoToolbarSet interface.
	 A Toolbar Set contains a collection of toolbars in various states.
	 An app's main window can have only one active toolbar set at a time.
***************************************************************** RAVINDRA **/
#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE   IMsoToolbarSet

DECLARE_INTERFACE_(IMsoToolbarSet, ISimpleUnknown)
{
	// ISimpleUnknown methods
	MSOMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppvObj) PURE;
	
	/* Standard FDebugMessage method */
	MSODEBUGMETHOD

	/* Return the toolbar set user object that this toolbar set is connected
		to. */
	MSOMETHOD_(interface IMsoToolbarSetUser *, PitbsuGetToolbarSetUser) (THIS) PURE;

	/* Return the address of the pvClient data pointer in this toolbar set. */
	MSOMETHOD_(void **, PpvClientGet) (THIS) PURE;

	/* Create an empty Control Container and hook it up to the user object at
   	piccu, returning its address in ppicc and its HWND in phwndgcc.  Return
	   TRUE, or FALSE if error.  The Control Container is initially hidden;
	   Use IMsoControlContainer::Show to show it (or use ShowWindow(*phwndgcc)
	   to show it).  The piccu is optional and can be NULL if notifications
	   are not needed. */
	MSOMETHOD_(BOOL, FCreateGenericContainer) (THIS_ 
														IMsoControlContainerUser *piccu,
														void *pvClient, HWND hwndParent,
														DWORD ws, IMsoControlSite **ppics,
														IMsoControlContainer **ppicc,
														HWND *phwndgcc) PURE;

	/* Create an empty toolbar named based on its id tbid, or if custom,
		named wtzName, with TB properties given by ptbp (pass NULL to use
		default settings). Add it to the toolbar set and hook it up to the
		User object at pitbsu. The pointer to the toolbar is returned in
		pitb.  The function returns TRUE if it succeeds.   */
	MSOMETHOD_(BOOL, FCreateToolbar) (THIS_ int tbid,       const WCHAR *wtzName,
					void *pvClient, const MSOTBP *ptbp,     
					interface IMsoToolbarUser *pitbu,
					interface IMsoControlSite **ppics, 
					interface IMsoToolbar **ppitb) PURE;

	/* Create an IMsoTbFrame object.  pUnkOuter should be a pointer to the
		app's IOleInPlaceFrame, which must be prepared to aggregate for
		this object.  If the function succeeds, the interface to release
		when the frame is no longer needed is returned in ppUnk.  The
		frame pointer itself should not be needed but can be gotten by QI  */
	MSOMETHOD_(BOOL, FCreateTbFrame) (THIS_ LPUNKNOWN pUnkOuter, 
					LPUNKNOWN *ppUnk) PURE;
						
	/* Loads toolbar from the open stream pistm and adds it to the 
		toolbar set. A pointer to the toolbar is returned in ppitb if it's
		not NULL.  The function returns TRUE if it succeeds.   */
	MSOMETHOD_(BOOL, FLoadToolbar) (THIS_ LPSTREAM pistm, 
					interface IMsoToolbar **ppitb) PURE;

	/* When the app is deactivated (say by clicking on another app) we
		deactivate the toolbars.  Hide any floating ones and (perhaps)
		change look of docked bars to disabled, later. */
	MSOMETHOD_(void, Deactivate) (THIS) PURE;

	/* Activate the Toolbar set if it is not already active. */
	MSOMETHOD_(void, Activate) (THIS) PURE;

	/* Save the ToolbarSet on an open stream provided by the user in pistm.
		If tbsave is msotbsaveAll, all information about the toolbar set will
		be saved down to the control level.  If it is msotbsavePartial, only the
		toolbar set information will be saved.  if it is msotbsavePartialEachTb
		then the toolbar set info and then "partial" info for each toolbar
		will be saved.  Returns TRUE if successful */
	MSOMETHOD_(BOOL, FSave) (THIS_ LPSTREAM pistm, int tbsave) PURE;

	/* Update the state of all visible controls in the toolbar set to match 
		the current state in the app.  Redraw the controls as necessary unless 
		'tuo' includes msotuoNoDraw.  If 'tuo' contains msotuoInterrupt then 
		the operation should be interrupted if possibly lengthy and an input 
		event becomes available.  Return FALSE if the update was interrupted. */
	MSOMETHOD_(BOOL, FUpdate) (THIS_ int tuo) PURE;

	/* Return the number of toolbars in the collection (not just those
		that are visible). Meaning of tbsct:
			msotbsctTopLevel: returns the count of top-level toolbars only.
				0 to CToolbars(msoctTopLevel-1) goes through all top-level
				toolbars.
			msotbsctAll: returns the count of all toolbars currently in the
				set. This count may not include all toolbars that are
				dropped by menu controls.
			msotbsctAllFlush: calls IMsoToolbarSetUser::FCreateToolbar to
				create all toolbars that Office thinks should be created,
				then returns the total count.
		*/
	MSOMETHOD_(int, CToolbars) (THIS_ int tbsct) PURE;

	/* Store the toolbar interface for the toolbar at index itb in
		the collection in ppitb, or return FALSE if itb is out of range. */
	MSOMETHOD_(BOOL, FGetToolbar) (THIS_ int itb, 
			interface IMsoToolbar **ppitb) PURE;

	/* Store the toolbar interface for the toolbar named wtzName (or if
		wtzName is NULL, the toolbar with the same tbid) in the collection 
		in ppitb, or return FALSE if not found.

		We support FindFirst and FindNext in this API. If *ppitb is NULL then
		we return the first match for tbid/wtzName, otherwise we return the
		one after the given *ppitb. If no match is found, or their is no match
		after the given *ppitb then we return FALSE.
	*/
	MSOMETHOD_(BOOL, FFindToolbar) (THIS_ int tbid, const WCHAR *wtzName, 
			interface IMsoToolbar **ppitb) PURE;

	/* Search for a control matching the given characteristics in the toolbar
		set.  If tct != msotctNil then the control must match that tct.
		If tcid != msotcidNil then the control must match that tcid.  If fVisible
		is TRUE then the control must be visible in the current UI state.  If
		fFlush then flush all uninitialized bars if necessary to find the control.
		If pitb and pictl are non-NULL, then start the search after the ictl-th
		control on the itb-th toolbar and update these indexes to reference
		the found control if one is found, else start from the beginning of 
		the set.  To start from the beginning when pitb and pictl are specified,
		use 0 and -1, respectively.  If the control is found then return it 
		in ppic if ppic is non-NULL and return TRUE, else return FALSE. */
	MSOMETHOD_(BOOL, FFindControl) (THIS_ int tct, int tcid, BOOL fVisible,
			BOOL fFlush, int *pitb, int *pictl, interface IMsoControl **ppic) PURE;

	/* Delete the toolbars object and all contained toolbar objects */
	MSOMETHOD_(void, Delete) (THIS) PURE;

	/* Calls when the app wants to explicitely give the toolbar set some
		system messages to trigger some behavior. An "normal" app should never
		have to call this, because most messages are trapped by the Component
		Manager or through other means. When these other means fail however
		(for instance, Mac Excel's Component Manager is not 100% functional),
		then the app can call this function directly.
		Returns TRUE if the message was consumed, FALSE if it should go on the
		message chain. */
	MSOMETHOD_(LRESULT, LRSysRequestEx) (THIS_ int nRequest, WPARAM wParam, LPARAM lParam) PURE;

	/* Create an IDispatch object for the Toolbars collection automation 
		object corresponding to this toolbar set and return it in 'ppidisp'.
		Return fSuccess. */
	MSOMETHOD_(BOOL, FGetIDispatchToolbars) (THIS_ IDispatch **ppidisp) PURE;

	/* Notifies toolbars that the frame window has been resized
		so the Toolbardock windows can be adjusted.
		NOTE:  This doesn't use exactly the same parameters as
		IOleInPlaceActiveObject::ResizeBorder, but is the same in spirit. */
	MSOMETHOD(HrResizeBorder) (THIS_ LPCRECT prcBorder) PURE;

	/* Is this window owned by current toolbar set i.e. if it is a toolbar,
		container or a control belonging to this toolbar set */
	MSOMETHOD_(BOOL, FIsWindowInTbs) (THIS_ HWND hwnd) PURE;

	/* Customize this toolbar set and menus etc. App initates customization by
		calling this API into Office96. Office96 then handles bringing up all
		the necessary toolbars, dialogs and so on. Office96 will let App know of
		the changes and returns to App when user finishes with customization.

		App should call FCustomize(TRUE) to get into customize mode. Generally
		speaking app doesn't need to call FCustomize(FALSE), however if the app
		wants to provide some way other than given by Office to get out of the
		customization mode, it is possible.
	*/
	MSOMETHOD_(BOOL, FCustomize)(THIS_ BOOL fShow) PURE;

	/* returns the number of views/modes for this toolbar set. Must be >= 1 */
	MSOMETHOD_(int, CTbdpGet)(THIS) PURE;

	/* sets the current view, by supplying the view number. It will be 0 to
		ctbdp i.e. index into rgtbdp. This call does an FUpdate() for the user
		for complete effect. */
	MSOMETHOD_(BOOL, FSelectTbdp)(THIS_ int itbdp) PURE;

	/* returns the current view/mode for this toolbar set. It will be 0 to
		ctbdp i.e. index into rgtbdp. */
	MSOMETHOD_(int, ITbdpGet)(THIS) PURE;

	/* Generates and displays the popup command bar giving the list of toolbars
		which the user can display or hide, and allows them to be displayed or
		hidden. Also has a Customize button. ppt is in Screen coordinates. */
	MSOMETHOD_(BOOL, FShowTBContextMenu) (THIS_ POINT *ppt, BOOL fKeyboard) PURE;

	/* If an app (like Excel) wants to be responsible for handling its own
		toolbar docks, it can call FSetUserDocks passing in the hwnds of the
		four docks.  The app is then responsible for showing, hiding, position-
		ing and destroying toolbar docks, all but the last in response to
		IMsoToolbarSetUser::HrSetBorderSpace.  DO NOT CALL THIS unless you are
		sure you want that responsibility.  You must call it before placing any
		toolbars on docks.  */
	MSOMETHOD_(BOOL, FSetUserDocks)(THIS_ HWND hwndLeft, HWND hwndTop,
					HWND hwndRight, HWND hwndBottom) PURE;

	/* Returns the visibility of the toolbar set. If it is FALSE then toolbar
		set is currently hidden and none of the toolbars of this set will be
		showing. If it is TRUE then all appropriate toolbars will show.
	*/
	MSOMETHOD_(BOOL, FVisible) (THIS) PURE;

	/* Sets the visibility of toolbar set, which results in either hiding or
		showing appropriate toolbars.

		Generic Control Containers are NOT affected by this, because they don't
		belong to any toolbar set.
	*/
	MSOMETHOD_(void, SetVisible)(THIS_ BOOL fShow) PURE;

	/* Returns the selected control during customize. It will fail if the
		toolbar set is not in customize mode. If no control is selected for
		customize it returns NULL in *ppic. We also return the
		control's site, toolbar and ictl for app's convenience. */
	MSOMETHOD_(BOOL, FGetSelectedCtl)(THIS_ IMsoControl **ppic,
												IMsoControlSite **ppics,
												IMsoToolbar ** ppitb, int *pictl) PURE;

	#if VSMSODEBUG
		/* writes duplicate hotkeys for a command bar to a file called 'hotkeys.txt' and
		reports/warns user if there are duplicates with an on-screen message box */
		MSOMETHOD_(void, HotKeyDuplicates)(THIS_ BOOL fDisplayTbPath) PURE;
	#endif
		
	/* If the argument is true then the toolbar that is define as tbtrMainMenu and
	is Visible will be converted into an HMenu. If this function is TRUE and the
	toolbar set is saved, or if the argument is FALSe then all toolbars that
	are tbtrMainMenu will be docked into the Top Dock. */
	MSOMETHOD_(BOOL, FUseHMenus)(THIS_ BOOL fUseMenu) PURE;
		
	/* Handles the menu messages that do not pass through FHandleMessage
		but get sent directly to the window proc.       */      
	MSOMETHOD_(BOOL, FHandleMenuMsg)(THIS_ HWND hwnd, UINT message, WPARAM wParam, 
					LPARAM lParam) PURE;
					
	/* Set various flags which affect the toolbar set (see msotbsfXXX). */
	MSOMETHOD_(void, SetFlags)(THIS_ UINT tbsf) PURE;
	
	/* Get various flags which affect the toolbar set (see msotbsfXXX). 
		(Note: should really be called TbsfGetFlags). */
	MSOMETHOD_(UINT, RgfGetFlags)(THIS) PURE;  
	
	/* Make an identical but disjoint copy of the current toolbar set
		referencing the window hwnd and with client data of ppv.    
		A pointer to the new toolbar set is given in ppitbsNew. picm
		is the Component Manager to hook the cloned toolbar set to,
		set to NULL if you don't care. */
	MSOMETHOD_(BOOL, FClone) (THIS_ interface IMsoToolbarSet **ppitbsNew,
			HWND hwnd, void **ppv, interface IMsoComponentManager *picm) PURE;

	/* Do-it-all context menu function: give it a point, and an array of MSOSTCR,
		and it creates everything necessary, pops up the context menu, waits for
		a click, cleans up after itself, and returns fSuccess. If TRUE, pictl 
		contains the index of the selected item (from 0 to cctl-1), or -1 if 
		menu was cancelled by user. The tbid parameter specifies the id of the
		toolbar you want the temporary toolbar to create; specify msotbidNil if
		you don't care, fSticky is passed along to FPopup.
	If you're not sure what the state of your toolbar set is (modal, inactive, whatever),
		you can call MsoFDoSimpleContextMenu instead, which does not require a toolbar
		set.
	// Sample code for IMsoToolbarSet::FDoSimpleContextMenu
	// N is the number of controls, pitbs a pointer to a toolbar set
	MSOSTCR rgstcr[N];
	memset(&rgstcr, 0, sizeof(rgstcr));
	for (ictl = 0 ; ictl < N ; ictl++)
		{
		rgstcr[ictl].tcid = // whatever control id you need here
		rgstcr[ictl].fBeginGroup = TRUE if you want a separator before this item
		}
	POINT pt;       // and set pt.x and pt.y to what you need
	if ((pitbs->FDoSimpleContextMenu(pt, msotbidNil, N, &rgstcr, &ictl)) && (ictl != -1))
		// then control #ictl was chosen (and its id is rgstcr[ictl].tcid) */
	MSOMETHOD_(BOOL, FDoSimpleContextMenu) (THIS_ POINT pt, int tbid, int cctl,
			MSOSTCR *rgstcr, BOOL fSticky, int *pictl) PURE;
	
	/* Find out what our Ole situation is */
	MSOMETHOD_(int, TbosGetOleStatus) (THIS) PURE;
	
	/* Call this when your default toolbar set initialization is complete.
		Changes after this call will make FSaveNeeded return TRUE. */
	MSOMETHOD_(void, SetInitializationComplete) (THIS) PURE;
	
	/* Determines whether the toolbar set has been changed since load or
		initialization.  If not, don't bother saving it! */
	MSOMETHOD_(BOOL, FSaveNeeded) (THIS) PURE;
	
	/*	Searches for the control with the given tct/tcid according to msoghostxxx
		flags defined at the top of this file. If msoghostAnimate is on, goes on
		to actually do the ghosting animation, and finally execute the control
		if msoghostExecute is on. Returns fSuccess (control found according to
		search criteria, and any animations carried out successfully). All
		menus are folded at the end of the animation, whether the control was
		animated or executed or not. */
	MSOMETHOD_(BOOL, FGhostControl) (THIS_ int tct, int tcid, UINT gf) PURE;

	/* For MDI child windows only. Just before calling Windows' DefMDIFrameProc,
		calls this first. If it returns TRUE, return *plr from your child WndProc,
		else call DefMDIFrameProc as you normally would. This enables Office to
		take over the MDI system menu even when the child window is not maximized. */
	MSOMETHOD_(BOOL, FMDIChildProc) (THIS_ HWND hwnd, UINT msg, WPARAM wParam,
			LPARAM lParam, LRESULT *plr) PURE;

	/* Filters out and processes WM_SYSCOMMAND messages for menu keyboard support.
		Insert in message loop. */
	MSOMETHOD_(BOOL, FHandledMessage) (THIS_ MSG *pmsg) PURE;

	/* This returns the state of customize dialog i.e. selection etc. if Office
		command bars are being customized. If we are not in customize mode then
		it returns FALSE.
	*/
	MSOMETHOD_(BOOL, FGetCustomizeDlgInfo) (THIS_ MSOCUSTDLGINFO *pcdi) PURE;

	/* Accounts for the TBFrame object memory */
	MSOMETHOD_(BOOL, FDebugMessagePitf) (THIS_ HMSOINST hinst, UINT message,
      WPARAM wParam, LPARAM lParam, LPUNKNOWN pitf) PURE;

	/*	Find if give pt (screen co-ordinates) is in a visible toolbar in the
		toolbar set that can have controls added to it.

		dotc: one of the msodotc, used to define if Office should draw drop
		feedback, erase it, or don't draw and just compute the ictl etc.

		ppitb: returns the pitb for the toolbar mouse is on
		pictl: returns the ictl where the dropped stuff should go
		phwndTb: returns the hwnd corresponding to the toolbar mouse is on
		pcdflags: returns some minute information about the control's neigbors
	*/
	MSOMETHOD_(BOOL, FIsPtOnToolbar) (THIS_ POINT pt, int dotc, IMsoToolbar **ppitb,
												int *pictl, HWND *phwndTb, MSOCDFLAGS *pcdflags) PURE;

	/* Returns True if underline Mode is currently on */
	MSOMETHOD_(BOOL, FGetUnderlineMode) (THIS) PURE;

	/* Turns underline mode on or off */
	MSOMETHOD_(void, SetUnderlineMode) (THIS_ BOOL fMode) PURE;

	/* When an Office client changes its toolbar set & needs the server to
		update so the change will be immediately visible, call this.  
		msowp is from the enum above. */
	MSOMETHOD_(void, RequestServerUpdate) (THIS_ int msowp) PURE;

	/* Starts keyboard tracking on the toolbar. */
	MSOMETHOD_(BOOL, FBeginKeyboardTracking) (THIS) PURE;

	MSOMETHOD_(BOOL, FDeferActivation) (THIS) PURE;

	// A replacement functions for FMerge, EndOleSession, ReactivateOleSession and
	// DeactivateOleSession.
	MSOMETHOD(InplaceActivate)(THIS_ LPUNKNOWN pIMsoTbFrame, DWORD grfFlags,
			interface IMsoComponentManager *picm) PURE;
	MSOMETHOD(InplaceDeactivate)(THIS_ DWORD dwReserved) PURE;

	// A replacement function for FMerge.
	MSOMETHOD(UIActivate)(THIS_ DWORD grfFlags) PURE;
	MSOMETHOD(UIDeactivate)(THIS_ DWORD grfFlags) PURE;

	/* Indicates whether the app is in Full Screen mode.  Allows the
		behavoir change that the task bar is hidden (covered) by the 
		app window.  Returns the previous setting. */
	MSOMETHOD_(BOOL, FSetFullScreenMode) (THIS_ BOOL fFullScreen) PURE;

	/* Execute an extension to Commmand Bar Customization, for Apps which
		need it. pv is dependent on cx passed. Following are the extensions:

		msocxSelectControl: pv is pic (i.e. a ptr to IMsoControl). If pic is
									NULL then Customize ensures that no control is
									selected within Customize, returns TRUE. If pic
									is not NULL and in a visible, customizable toolbar
									in current toolbar set being customized, and not
									in Command well, then we will select this control
									and return TRUE otherwise we will return FALSE.
		msocxWizardBalloon: pv has a BOOL value for this. FALSE for Suspend and
									TRUE for Resume. When an app adds extensions to
									ModifySelection menu which can bring up a UI e.g.
									a dialog they should call this extension with
									FALSE i.e. Suspend and before closing that UI and
									returning back to Office it should call this
									extension with TRUE i.e. RESUME.
		msocxFIsPitbInToolbarList: pv should be a pitb. It will return TRUE if
									this toolbar can be visible in the toolbar list in
									the customize dialog. Otherwise it will return FALSE.
		msocxRefreshToolbarList: Rebuild the toolbar list for customize dialog,
									and also updates all the references for its members
									within Customize dialog data structures. Office
									assumes that toplevel toolbars in the toolbar
									set have changed, however NOTHING should be changed
									for the toolbars belonging to the 'command well'.
									pv should be pitb of a toplevel toolbar to be selected
									in this list. It can be NULL for no selection. If
									pv is non NULL, the pitb should be the one that will
									appear in toolbar list in Customize dialog, otherwise
									this operation will FAIL and return FALSE.
	*/
	MSOMETHOD_(BOOL, FDoCustomizeExtension) (THIS_ int cx, void *pv) PURE;

	MSOMETHOD(OleException)(THIS_ DWORD grfFlags, DWORD dwReserved) PURE;
	MSOMETHOD_(void, SetDeferActivation) (THIS_ BOOL fDefer) PURE;

	MSOMETHOD(InsertMenus)(	THIS_ HMENU hmenuShared, LPOLEMENUGROUPWIDTHS pMenuWidths,
							IMsoToolbar *ptbMainMenuBar, BOOL fContainer, DWORD dwReserved) PURE;
	MSOMETHOD(SetMenu)(THIS_ HMENU hmenuShared, BOOL fContainer, DWORD dwReserved) PURE;
	MSOMETHOD(RemoveMenus)(THIS_ HMENU hmenuShared, LPOLEMENUGROUPWIDTHS pMenuWidths,
								 BOOL fContainer, DWORD dwReserved) PURE;
	MSOMETHOD(EnableModeless) (THIS_ BOOL fEnable) PURE;

	// Container is requesting to have the visibility of ToolBar with id tbid
	// set to the value of fShow. TRUE == Show it. FALSE == Hide it.
	MSOMETHOD(HrSetVisibleRemoteTb) (THIS_ int tbid, BOOL fShow) PURE;

	// Container wants to know the CURRENT visibililty of the toobar with
	// id tbid.
	MSOMETHOD(HrGetVisibleRemoteTb) (THIS_ int tbid, BOOL *pfShow) PURE;

	/* Specify what kinds of certain OLE Automation modifications should be 
		allowed on the toolbar set when it is merged (see msotboamXXX).  
		Defaults to none of these operations.  Note that Office does not
		automatically handle these operations completely and additional 
		app work may be required to get them to work properly. */
	MSOMETHOD_(void, SetAllowOAWhenMerged) (THIS_ int tboam) PURE;
	MSOMETHOD_(void, EnableWindows) (THIS_ BOOL fEnable) PURE;

	MSOMETHOD(RemUpdateToolbar)(THIS_ int tbid, int msowp) PURE;
	MSOMETHOD(RemGetProperties)(THIS_ int tbid, MSOTBP *ptbp, int itbdp) PURE;
	MSOMETHOD(RemSetProperties)(THIS_ int tbid, MSOTBP *ptbp, int itbdp) PURE;

	MSOMETHOD(RemTranslateKeyMsg)(THIS_ MSG *pMsg, DWORD dwReserved) PURE;

	/* Make an identical (based on the flags passed in)
		but disjoint copy of the current toolbar set
		referencing the window hwnd and with client data of ppv.    
		A pointer to the new toolbar set is given in ppitbsNew. picm
		is the Component Manager to hook the cloned toolbar set to,
		set to NULL if you don't care. */
	MSOMETHOD_(BOOL, FCloneEx) (THIS_ interface IMsoToolbarSet **ppitbsNew,
			HWND hwnd, void **ppv, interface IMsoComponentManager *picm,
			UINT grftcFlags) PURE;

	/* This function is identical to FFindToolbar, except that if the toolbar is
	   not found, there is no flush, whatsoever. */
	MSOMETHOD_(BOOL, FFindToolbarNoFlush) (THIS_ int tbid, const WCHAR *wtzName, 
			interface IMsoToolbar **ppitb) PURE;

	/* Returns whether or not there is a toolbar docked in the bottom dock */
	MSOMETHOD_(BOOL, FTbDockedAtBottom) (THIS) PURE;

	/* Migrate the pip data so custom controls*/ 
	MSOMETHOD_(void, MigratePip) (THIS) PURE;

	MSOMETHOD_(int, Transaction)(THIS_ int tbst, int tran) PURE;

	/* Save Office-owned toolbars into an appropriate reg key.  Returns TRUE if
	   successful */
	MSOMETHOD_(BOOL, FSaveOffice) (THIS_ int tbsave) PURE;

	/* Loads saved Office-owned toolbars into the current ToolbarSet.  Typically
	   called after a successful call to MsoFLoadToolbarSet.  Returns FALSE on
	   failure. */
	MSOMETHOD_(BOOL, FLoadOffice) (THIS) PURE;

	MSOMETHOD_(BOOL, FShowWorkPane)(THIS_ int idWP, MSOPFNWPCALLBACK pfnWPC, 
					void * pwpInfo) PURE;
	MSOMETHOD_(int, IdGetWorkPane)(THIS) PURE;
	MSOMETHOD_(BOOL, FGetWorkPaneInfo)(THIS_ int idWP, void ** ppwpInfo) PURE;
	MSOMETHOD_(void, DeleteAllWorkpanes)(THIS) PURE;
	MSOMETHOD_(BOOL, FIsWorkPaneButtonEnabled)(THIS) PURE;
	MSOMETHOD_(BOOL, FIsWorkPaneButtonChecked)(THIS) PURE;
	MSOMETHOD_(void, WorkPaneButtonClicked)(THIS) PURE;

	/* Same as FDoSimpleContextMenu, only takes a rectangle to avoid and any of the
		msopp values. */
	MSOMETHOD_(BOOL, FDoSimpleContextMenuEx) (THIS_ POINT pt, int tbid, int cctl,
			MSOSTCR *rgstcr, BOOL fSticky, int *pictl, RECT * prcAvoid, int pp) PURE;

	/* Same as FDoSimpleContextMenuEx, except that you use MSOCTCR instead of 
	   MSOSTCR, allowing more complex controls like menus and labels. */
	MSOMETHOD_(BOOL, FDoComplexContextMenu) (THIS_ POINT pt, int tbid, int cctl,
			MSOCTCR *rgctcr, BOOL fKeyboard, int *pictl, RECT * prcAvoid, int pp) PURE;

	MSOMETHOD_(BOOL, FDestroyWorkPane)(THIS_ int idWP) PURE;
	MSOMETHOD_(BOOL, FHideWorkPane)(THIS_ int idWP) PURE;

	MSOMETHOD_(BOOL, FShowWorkPaneNoForceVisible)(THIS_ int idWP, MSOPFNWPCALLBACK pfnWPC, 
					void * pwpInfo) PURE;

	MSOMETHOD_(void, RegisterFindControlCallback)(THIS_ MSOPFNFCCALLBACK pfnFCC) PURE;

	MSOMETHOD_(BOOL, FFindSpecialControl)(THIS_ int tct, int tcid, BOOL fVisible,
			BOOL fFlush, int *pitb, int *pictl, IMsoControl **ppic) PURE;

	MSOMETHOD_(BOOL, FPreventFlicker)(THIS) PURE;
	// Is the toolbarset active?
	MSOMETHOD_(BOOL, FActive)(THIS) PURE;

	MSOMETHOD_(BOOL, FRegisterWorkPane)(THIS_ int idWP, MSOPFNRWPINVOKE pfnRWPI,
	                                    const WCHAR *wtzLabel, int grfRWP) PURE;
	MSOMETHOD_(void, DeleteAllInactiveWorkpanes)(THIS) PURE;

	// Get the current visibility state of the AWDropdown control.
	MSOMETHOD_(BOOL, FGetAWDropdownVisible) (THIS) PURE;

	// API to get and set the m_fInClickViaKeyboard variable - used when command execution
	//  doesn't happen under an FClick callback.
	MSOMETHOD_(BOOL, FInClickViaKeyboard)(THIS) PURE;
	MSOMETHOD_(void, SetInClickViaKeyboard)(THIS_ BOOL fInClickViaKeyboard) PURE;

	MSOMETHOD_(void, SetInsituHwnd)(THIS_ HWND hwndInsitu) PURE;
};
#endif // MSO_NO_INTERFACES



#ifdef UNDO_WEBPANE_CUT

/****************************************************************************
	Defines the IMsoWebPane interface
***************************************************************** rolandr **/

// To create a WebPane, use MsoFCreateWebPane
// The IWebBrowser2 interface can be found in <exdisp.h>

#ifndef MSO_NO_INTERFACES
#undef  INTERFACE
#define INTERFACE  IMsoWebPane

DECLARE_INTERFACE(IMsoWebPane)
{
	/* Navigate to URL
	*/
	MSOMETHOD_(HRESULT, HrNavigate)(BSTR wzUrl);

	/* Get the URL or the Title of the current page
	*/
	MSOMETHOD_(HRESULT, HrLocation)(BSTR *pwzUrl);
	MSOMETHOD_(HRESULT, HrName)(BSTR *pwzName);

	/* Navigate the browser stack
	*/
	MSOMETHOD_(HRESULT, HrBack)();
	MSOMETHOD_(HRESULT, HrForward)();

	/* Stop and Refreshing loading
	*/
	MSOMETHOD_(HRESULT, HrStop)();
	MSOMETHOD_(HRESULT, HrRefresh)();

	/* Get the IWebBrowser2 interface of the WebPane
	*/
	MSOMETHOD_(BOOL,    FWebBrowser)(interface IWebBrowser2 **ppiwb2);

	/* Show or Hide the WebPane toolbar
	*/
	MSOMETHOD_(BOOL,    FShow)();
	MSOMETHOD_(BOOL,    FHide)();
};

#endif // MSO_NO_INTERFACES
#endif UNDO_WEBPANE_CUT


/****************************************************************************
	Global DLL API's
****************************************************************************/
#ifndef MSO_NO_INTERFACES

/*	Return the Office9 version of toolbar metrics used for all toolbars in 'ptbm'.

	All the clients that are compiled with mso9 headers will continue
	calling MsoGetToolbarMetrics() and will get MSOTBM9 structure which is
	Office9 version of MSOTBM structure. All clients compiled with mso10
	headers will call MsoGetToolbarMetrics10() and get MSOTBM structure
	that contains all the extra information that Office10 supports.*/
	
MSOAPI_(void) MsoGetToolbarMetrics(MSOTBM9 *ptbm);

#define MsoGetToolbarMetrics(ptbm) MsoGetToolbarMetrics10(ptbm)

/* Return the Office10 versions of toolbar metrics used for all toolbars in 'ptbm'.*/
MSOAPI_(void) MsoGetToolbarMetrics10(MSOTBM *ptbm);

/* Change all office instances to use either small or large toolbar
	buttons. Returns TRUE iff the size is changed. */
MSOAPI_(BOOL) MsoFSetButtonSize(BOOL fLargeButtons);

/* Change all office instances to use either short or long menus
	buttons. Returns TRUE iff the size is changed. */
MSOAPI_(BOOL) MsoFSetLongMenus(BOOL fLongMenus);

/* Change all office instances to allow/disallow transparent
   floating toolbars.  Returns TRUE iff the state changes. */
MSOAPI_(BOOL) MsoFSetTbTransparent(BOOL fTransparent);

/* Gets "large button" mode. */
MSOAPI_(BOOL) MsoFGetButtonSize();

/* Returns a good, zero-sized rectangle for a new floating toolbar.*/
MSOAPI_(void) MsoGetValidTBPos(RECT * prc);

/* Create a standard toolbar control for the instance of Office given by
	'hinst' with type as determined by given by tct. The tcid is the id of the
	control to be created; Office built-in controls (with tcid < msotcidUser)
	come with predefined strings (and icons for buttons); app custom-controls 
	should have a tcid >= msotcidUser, and set the control label and other 
	features as necessary.  The tbct is an extra argument that is a 
	combination of standard tbct flags and control-dependent flags (e.g. tbbt 
	for buttons).  The tbidMenu is used only for menu controls and specifies 
	the tbid of the toolbar to drop down.  The tbidMenu is optional and if 
	given as msotbidNil then the client must specify the bar to drop via 
	IMsoControl::Setpitb.  A pointer to client data, pvClient, is stored in 
	the object. Hook up the control to the control site interface at pics and 
	to the User object at picu. Return the control interface in ppic, and TRUE 
	iff creation succeeded. */
MSOAPI_(BOOL) MsoFCreateControl(HMSOINST hinst, int tct, int tcid, 
										  int tbct, int tbidMenu, void *pvClient, 
										  interface IMsoControlSite *pics,
										  interface IMsoControlUser *picu,
										  interface IMsoControl **ppic);

/* Creates a toolbar button control with extended attributes.  Unless you
   have need for these specific properties, you should call
	MsoFCreateControl instead of this routine.  See previous description
	for parameter info.  Extra parameters are passed in the pbax.  See
	the def of MSOBAX for a description of the params. */
MSOAPI_(BOOL) MsoFCreateButtonEx(HMSOINST hinst, int tcid, 
										   int tbct, int tbidMenu, void *pvClient, 
										   interface IMsoControlSite *pics,
										   interface IMsoControlUser *picu,
										   interface IMsoControl **ppic,
										   MSOBAX *pbax);

/* Create an empty Toolbar set for the instance of Office given by 'hinst'
	(only one instance can use a given toolbar set) and hook it up to the user
	object at pitbu, returning its address in ppitbs.  Docks are attached to 
	the window at hwndDockFrame (the container app if we're an OLE server). 
	picm is the Component Manager this toolbar set should be hooked up to;
	if you only have one in your app, you can set picm to NULL.
	Return TRUE, or FALSE if error.  The Toolbar set is initially hidden; 
	use IMsoToolbarSet::Activate to show and activate it. */
MSOAPI_(BOOL) MsoFCreateToolbarSet(HMSOINST hinst, 
											  interface IMsoToolbarSetUser *pitbsu,
											  void *pvClient,
											  HWND hwndDockFrame,
											  int ctbdp,
											  interface IMsoComponentManager *picm,
											  interface IMsoToolbarSet **ppitbs);

#ifdef UNDO_WEBPANE_CUT
/* Create a WebPane toolbar in the TBS indicated and navigate to wzUrl.
	Returns an IMsoWebPane interface. */
MSOAPI_(BOOL) MsoFCreateWebPane(interface IMsoToolbarSet *pitbs,
										  BSTR wzUrl,
										  interface IMsoWebPane **ppiweb);
#endif

/* Create an empty Control Container for the instance of Office given by 
	'hinst' (only one instance can use a given control container) and hook it 
	up to the user object at piccu, returning its address in ppicc and its 
	HWND in phwndCc.  Return TRUE, or FALSE if error.  The Control Container 
	is initially hidden; use IMsoControlContainer::Show to show and activate 
	it. This is a very basic stuff and doesn't support resizing, reflowing and 
	so on.  The piccu is optional and can be NULL if notifications are not 
	needed. 
	Note: Not all control types are supported in GCCs.  Specifically, buttons
	and menus are supported, but edits/dropdown/combos are NOT. Email MsoTbQs
	for more information. */
MSOAPI_(BOOL) MsoFCreateGenericContainer(HMSOINST hinst,
														IMsoControlContainerUser *piccu,
														void *pvClient, HWND hwndParent,
														DWORD ws, IMsoControlSite **ppics,
														IMsoControlContainer **ppicc,
														HWND *phwndCc);

/* Create a Control Container and hook it up to the user object pinst->piccu.
	Then create a control (based on the parameters) to put inside it.
	Return TRUE, or FALSE if error.
	The position the Control Container so it is centered in rc, and show the Control
	Container.  Return a pointer to the control container and the hwnd in the
	pgccr. */
MSOAPIX_(BOOL) MsoFCreatePictureContainer(HMSOINST hinst, HWND hwndParent,
													MSOGCCR *pgccr);


/* Save the control record at 'ptcr' and the contained control into the
	stream 'pistm' (the control's FSave method will be called).
	The 'tbsave' is as passed down from a higher-level save (or pass tbsaveAll
	for a normal save).  Return fSuccess. */
MSOAPI_(BOOL) MsoFSaveControl(HMSOINST hinst, MSOTCR *ptcr, LPSTREAM pistm, 
										int tbsave);

/* Load a control record and the contained control into 'ptcr'
	from the stream 'pistm' as saved by MsoFSaveControl.  The type of the 
	control will be determined and the control created (application defined 
	control types are created by calling IMsoToolbarSetUser::FCreateControl) 
	and then the control's FLoad method will be called.  Hook up the control 
	to the control site at 'pics'.  Return fSuccess. */
MSOAPI_(BOOL) MsoFLoadControl(HMSOINST hinst, LPSTREAM pistm,
										interface IMsoControlSite *pics,
										interface IMsoToolbarSet *pitbs,
										MSOTCR *ptcr);

/* Create a Toolbar set for the instance of Office given by 'hinst' and hook 
	it up to the user  object at pitbu, returning its address in ppitbs.  
	Docks are attached to the window at hwndDockFrame (the container app if OLE).
	Load it from the save set in the open stream pistm. picm is the Component Manager
	this toolbar set should be hooked up to; if you only have one in your app, you
	can set picm to NULL. Return TRUE, or FALSE if error. The Toolbar set is
	initially hidden; use IMsoToolbarSet::Activate to show and activate it.  

	uflags are composed of the msotbsLoad* flags.  */
MSOAPI_(BOOL) MsoFLoadToolbarSetEx(HMSOINST hinst, LPSTREAM pistm,
											interface IMsoToolbarSetUser *pitbsu,
											HWND hwndDockFrame,
											interface IMsoComponentManager *picm,
											interface IMsoToolbarSet **ppitbs,
											UINT uflags);

/* Identical to MsoFLoadToolbarSetEx without the flags parameter  */
MSOAPI_(BOOL) MsoFLoadToolbarSet(HMSOINST hinst, LPSTREAM pistm,
											interface IMsoToolbarSetUser *pitbsu,
											HWND hwndDockFrame,
											interface IMsoComponentManager *picm,
											interface IMsoToolbarSet **ppitbs);

/* This guy will enumerate all running instances of Office and send a
   WM_MSO message to the registered hwnd in the inst with wParam and
   lParam as the arguments. */
MSOAPIX_(BOOL) MsoFSendMsoMessageToAllInstances(int wParam, int lParam);

/* This guy will enumerate all running instances of Office and post a   
   WM_MSO message to the registered hwnd in the inst with wParam and
   lParam as the arguments. */
MSOAPIX_(BOOL) MsoFPostMsoMessageToAllInstances(int wParam, int lParam);

/* Returns TRUE iff Office tooltips are enabled. */
MSOAPI_(BOOL) MsoFGetTooltips();

/* Tells all office instances whether or not to display tooltips.
Returns TRUE iff the state is changed. */
MSOAPI_(BOOL) MsoFSetTooltips(BOOL fTooltips);

/* Activates this control, which must be visible (no ghosting support). Fails
	if the control is hidden, its toolbar is hidden, or it doesn't belong to a
	toolbar. */
MSOAPI_(BOOL) MsoFActivateControl(IMsoControl *pic);

/* Converts Gap index to and fro Nongap indexes */
MSOAPI_(void) MsoConvertIndex(IMsoToolbar *pitb, int iSrc, int *piDest,
										BOOL *fGap, int msogapType, BOOL *pfOnToolbar);

/* Edits the button face for the given control*/
MSOAPI_(BOOL) MsoFEditBtnFace(IMsoControl *pic);
MSOAPI_(BOOL) MsoFGetButtonFace(IMsoControl *pic, HBITMAP *hFace, HBITMAP *hMask);
MSOAPI_(BOOL) MsoFSetButtonFace(IMsoControl *pic, HDC hdc, HBITMAP hFace, HBITMAP hMask, COLORREF crTransparent);

/* Undeletes a control that was "temporarily" deleted. If this control does not
	exist in the temp list, or fails for any other reason it will return 0.
	Otherwise it will place it back in its "correct" position (that is the position
	it was in prior to being deleted. */
MSOAPI_(int) MsoFRestoreCtrl(IMsoToolbar *pitb, WCHAR *wtzName);

/* Notify the instance that context help mode has been turned on or
	off.  If the toolbar set user is notified that help mode is completed
	this method does not need to be called as toolbars will call it.
   Return fSuccess.     */
MSOAPI_(BOOL) MsoFSetHelpMode(HMSOINST hinst, BOOL fHelpMode);

/* Get the current help mode for the instance.  If the instance is invalid,
	will just return FALSE. */
MSOAPI_(BOOL) MsoFGetHelpMode(HMSOINST hinst);

/* Get the GCC flags for the given IMsoControlContainer */
MSOAPI_(UINT) MsoPiccGetGCCFlags(IMsoControlContainer *picc);

/* Set the GCC flags for the given IMsoControlContainer */
MSOAPI_(void) MsoPiccSetGCCFlags(IMsoControlContainer *picc, UINT uflags);

/* Set the GCC flags for the given IMsoControlContainer */
MSOAPI_(BOOL) MsoFPiccSetTbtr2Flags(IMsoControlContainer *picc, UINT uflags);

/* Pass a message intended for a Gcc's child menu to the child menu*/
MSOAPI_(BOOL) MsoFPreTranslateMessagePicc(IMsoControlContainer *picc, MSG *pmsg);

/* Set the restricting rect of a toolbar */
MSOAPI_(BOOL)MsoFPiccRestrictRect(IMsoControlContainer *picc, RECT *prc);

/* Returns TRUE if the current toolbar control with focus is Cicero-enabled (i.e., has an edit). */
MSOAPI_(BOOL)MsoFCiceroEnabledTrackingControl(void);

/*	********** Office MDI (Windows only) **********

MDI apps, rejoice! Office is your friend. MDI apps *must* implement the
ToolbarSetUser::FGetMDIClientWindow, and the window returned by that call
must answer the WM_MDI* calls listed in the comment. Also, MDI apps must call
IMsoToolbarSet::FMDIChildProc in their children's WndProc.

Now we come to the fun stuff: overriding the MDI system toolbar. Office uses
in place of Windows' MDI system menu, the toolbar returned by
IMsoToolbarSet::FFindToolbar(msotbidMDISystem). If your IMsoToolbarSetUser::
FGetToolbar does nothing special for that id, Office will provide a default
toolbar filled with the six typical buttons: Restore, Minimize, Close, etc.
If you wish to, you may override this toolbar in several ways:

- call FFindToolbar(msotbidMDISystem), and mess around with the pitb returned
	to you. (If you call pitb->Delete, the next call to FFindToolbar will
	re-create the default toolbar.)

- provide your very own msotbidMDISystem toolbar, created the same way all of
	your toolbars are.

Whichever solution you choose, you may have to replace some of the default MDI
buttons there. You may do so. Office exposes in the following two APIs the
FEnabled and FClick code it uses if you *don't* override them. These functions
expect to be called by msotctButton's with the id's msotcidRestoreWindow,
msotcidCloseWindow and so on. The buttons must belong to a toolbar set, that
reponds properly to IMsoToolbarSetUser::FGetMDIClientWindow().

WARNING: don't be tempted to create your own MDI controls on random toolbars.
By the same token, make sure that if you override the MDI system toolbar,
it is non-customizable. We don't want these controls to be saved or loaded,
and will get rid of them when SDI finally comes. */

/* FEnabled for MDI buttons. */
MSOAPIX_(BOOL) MsoFMDIButtonEnabled(IMsoControl *pic);

/* FClick for MDI buttons. */
MSOAPIX_(BOOL) MsoFMDIButtonClick(interface IMsoControl *pic, int *ptbbs, int grf);

/* Return the build-in resource label text associated with a given control 
	type and id and return it in wtzLabel. */
MSOAPI_(void) MsoGetLabelFromTcid(int tct, int tcid, WCHAR *wtzLabel);

/* Return the build-in tooltip override associated with a given control 
	type and id and return it in wtzTip, or return an empty string if there
	is no override (meaning the built-in tooltip is the same as the label). */
MSOAPI_(void) MsoGetTooltipOverrideFromTcid(int tct, int tcid, WCHAR *wtzTip);

/* Return the build-in resource label text associated with a given command 
	bar and return it in wtzLabel. */
MSOAPI_(void) MsoGetLabelFromTbid(int tbid, WCHAR *wtzLabel, BOOL fLocalized);

/* Strip odd '&' chars from the string 'wtz' in place, and return a pointer 
	to the character after the last odd '&' (the character to underline 
	as per Windows DrawText rules), or NULL if none.  As per DrawText,
	consecutive pairs of '&'s will leave a real '&' character, and all
	odd '&'s are removed even though only the last may be underlined. */
MSOAPI_(WCHAR *) MsoPwchStripAmpersandsWtz(WCHAR *wtz);

/*	Strip odd '&' chars from the string 'wtz' in place.  As per DrawText,
	consecutive pairs of '&'s will leave a real '&' character, and all
	odd '&'s are removed even though only the last may be underlined.
	Also strips off trailing colons.  If an & occurs inside of parens then
	the parens and the character following the & are also stripped out. */
MSOAPI_(void) MsoStripTooltipWtz(WCHAR *wtz);


/*	Yet another version of StripAmpersand. However this is going to be a super
	set of MsoPwchStripAmpersandsWtz() and MsoStripTooltipWtz(). You can
	specify flags for one or all of the following strip operations on the wtz.
	All the strip flags msofStripXYZ are defined above.
	
	Strip odd '&' chars from the string 'wtz' in place.  As per DrawText,
	consecutive pairs of '&'s will leave a real '&' character, and all
	odd '&'s are removed even though only the last may be underlined.

	Strips off trailing colon.
	
	If an & occurs inside of parens then the parens and the character following
	the & are also stripped out. This is useful to remove accelarator strings of
	format (&N) which are appended to label in some FE language versions.
	NOTE: We do not check for language to do this i.e. we assume that there isn't
	any realistic label in other languages with (&N) stuck in.
*/
MSOAPI_(WCHAR *) MsoPwchStripWtz(WCHAR *wtz, int rgfStrip);

/* Reposts the left or right mouse down to the proper window, converting to 
	a NC message if necessary. Use this when you had the capture and you want to 
	resend the mouse down to whoever should had got it first. */
MSOAPI_(void) MsoRepostMouseDown(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam, BOOL fClient);

/*	Determines which window the mouse is over (if any) and sends them a proper
	WM_SETCURSOR message.  Use this when you have the capture and you want to 
	force the cursor to be set to whatever it normally would be set to.
	This routine uses the current location of the cursor. */
MSOAPIX_(void) MsoForceCursor(void);

/*	Fills prc with the rectangle of the screen.
	If fWorkspace is TRUE, the rectangle returned is the Screen Workspace,
	otherwise it is the entire screen.
	On the Mac, pptNear is used to determine which screen to return, if the
	point is on a screen, that screen is used, otherwise the main screen
	is used. NULL can be passed in and the main screen will be returned. */
MSOAPI_(void) MsoGetScreenRect(RECT *prc, BOOL fWorkspace, POINT * pptNear);

/*	Forces prc to be on screen.  If it is completely off screen, it is moved
	in a straight line to the main monitor.

	Takes into account multiple monitors on both Win and Mac.

	If fWorkspace is true, it will use the workspace rectangles when moving
	the rectangles.

	Return value is TRUE if the rectangle was moved. */
MSOAPIX_(BOOL) FForceRectOnScreen(RECT * prc, BOOL fWorkspace);
MSOAPI_(BOOL) FForceRectOnScreenCore(RECT * prc, BOOL fWorkspace, BOOL fForceEntire);

/* Set the values of phbstrip and piBtn which point to the strip and
	offset for the buttonface given by id */
MSOAPI_(BOOL) MsoFFindBtnFace(int id, HBSTRIP *phbstrip, int *piBtn);

	/*	Smoothly moves the mouse cursor to the given screen coordinates. Typically
		used when ghosting something. Windows only. */
	MSOAPIX_(void) MsoSmoothSetCursorPos(int x, int y);

// Flags for tooltip actions passed to MsoFShowTooltip
enum
	{
	msottDestroyWindow = 0, // Hide & destroy tip window SLOW!!!
	msottHide,              // Destroy the current tip, not the window
	msottImmediate,         // Show tip right now!
	msottNowIfNecessary,    // Immediate if another tip was just up, else delayed
	msottDelayed,           // Bring up after the appropriate wait interval
	msottQuery,             // Does nothing, just returns tip state
	msottMax,
	};

/* Shows or hides a tooltip, wtz, after the appropriate interval at
   the current cursor location.  Tip is no wider than dxMax.  Returns
   TRUE iff a tip is currently visible.
   msott: DestroyWindow, Hide, and Query do not require a wtz.
   Strings now wrap on newline characters in the string. */
MSOAPI_(BOOL) MsoFShowTooltip(WCHAR *wtz, int tt);

/* Shows or hides a tooltip, wtz, after the appropriate interval at
   the current passive tooltip location.  Tip is no wider than dxMax.
   Returns TRUE iff a passive tip is currently visible.
   msott: DestroyWindow, Hide, and Query do not require a wtz.
   Strings now wrap on newline characters in the string. */
MSOAPIX_(BOOL) MsoFShowPassiveTooltip(WCHAR *wtz, int tt);
MSOAPIX_(BOOL) MsoFShowPassiveTooltipEx(WCHAR *wtz, int tt, int fmt);
MSOAPI_(void) MsoSetPassiveTooltipTcid(int tcid, int dSize);
MSOAPI_(void) MsoSetPassiveTooltipTcid(int tcid, int dSize);

/*	Just like IMsoToolbarSet::FDoSimpleContextMenu, except you don't have to give
	a toolbar set. Just the Office instance will do. This one is slower than
	the IMsoToolbarSet method, but safer as you don't risk using a toolbar set
	that's inactive or in a modal state. */
MSOAPI_(BOOL) MsoFDoSimpleContextMenu(HMSOINST hinst, POINT pt, int tbid, int cctl,
		MSOSTCR *rgstcr, BOOL fSticky, int *pictl);
MSOAPIX_(BOOL) MsoFDoSimpleContextMenuEx(HMSOINST hinst, POINT pt, int tbid, int cctl,
		MSOSTCR *rgstcr, BOOL fSticky, int *pictl, RECT * prcAvoid, int pp);

/*	Just like MsoFDoSimpleContextMenu, except that you use MSOCTCR instead of 
   MSOSTCR, allowing more complex controls like menus and labels.*/
MSOAPI_(BOOL) MsoFDoComplexContextMenu(HMSOINST hinst, POINT pt, int tbid, int cctl,
		MSOCTCR *rgctcr, BOOL fKeyboard, int *pictl, RECT * prcAvoid, int pp);

/* Means of creating a relatively simple menu with more control types than 
	"simple" menus.  Useful for submenus off MsoFDoComplexContextMenu() above.*/
MSOAPI_(BOOL) MsoFCreateComplexMenu(HMSOINST hinst, int tbid, WCHAR *wtzName, int cctl, MSOCTCR *rgctcr, 
		IMsoToolbarUser *pitbu, IMsoButtonUser *pibu, IMsoToolbar **ppitb,
		BOOL fUseIndex, int tbtr);
/****************************************************************************
	Command Bar Visuals
****************************************************************************/

/* Get a COLORREF from an msocbvcr* enum. */
MSOAPI_(COLORREF) MsoCrCbvGet(MSOCBVCR msocbvcr);
MSOAPI_(COLORREF) MsoCrCbvSet(MSOCBVCR msocbvcr, COLORREF cr);
MSOAPI_(COLORREF) MsoCrCbvGetAccurate(MSOCEO *pce, int tbbsx, MSOCBVCR msocbvcr);

/* Get an HBRUSH from an msocbvcr* enum.  The brush is cached and should not
   be deleted. */
MSOAPI_(HBRUSH) MsoHbrCbvGet(MSOCBVCR msocbvcr);

/* Get the dimensions specified by an msocbvcpx* enum. */
MSOAPI_(int) MsoCpxCbvGet(MSOCBVCPX msocbvcpx);
MSOAPIX_(int) MsoCpxCbvGetAccurate(MSOCEO *pceo, MSOCBVCPX msocbvcpx);

/* Returns TRUE if we should be using the new visuals for commandbars, given
   the pceo and tbbsx. */
MSOAPIX_(BOOL) MsoFUseCbv(MSOCEO *pceo, int tbbsx);

/* Returns TRUE if the current screen color depth is 256 colors, or lower. */
MSOAPIX_(BOOL) MsoFCbvLowColor();

/* Returns TRUE if the system has the high contrast option turned on.*/
MSOAPI_(BOOL) MsoFCbvHighContrast();

/* Returns TRUE if the current screen color depth is at least thousand of color,
	and High Contrast is NOT turned on. */
MSOAPI_(BOOL) MsoFCbvHighColor();

/* Here are the possible states of the above three function calls:

  Low Color		High Contrast		High Color

  T				T					F
  T				F					F
  F				T					F
  F				F					T

*/


/* Draws from a masked bitmap into a DC, applying "new look" visuals for disabled mode. */
MSOAPI_(void) MsoCbvDrawCustomBitmapDisabled(HDC hdc, RECT *prc, BITMAPINFO *pbmiImage,
									BITMAPINFO *pbmiMask, COLORREF crBkgd,
									COLORREF crDisabled);

/****************************************************************************
	The MsoRenderColor collection

	Handful of utility functions to draw color swatches, SDM dropdowns, and
	icons the "Office way". All solid colors passed in are drawn using GEL.

	On palette devices, app is responsible for ensuring that the proper
	palette is selected before calling those functions.
****************************************************************************/

/*	Draws a drawing swatch the Office way. csType can be any of msocsxxx:
	- msocsColor: a normal little color swatch (like MsoRenderColorSwatch)
	- msocsAutomatic: the text Automatic, and a rectangle of color to the left
		(if cr is 0xFFFFFFFF, no rectangle is drawn).
	- msocsNoFill, msocsNoColor, msocsNone, msocsNoLine, msocsNoShadow, msocsNo3D:
	  the text No Fill, No Color, etc., centered on the background cr. If
	  cr is 0xFFFFFFFF, it's transparent (so uses the toolbar background).
	Strings are localized by Office.
	csColor dimension assumed 16*16 with dxBetween = dyBetween = 3 */
MSOAPI_(void) MsoRenderColorSwatch(HDC hdc, RECT *prc, int csType,
		COLORREF cr, BOOL fSelected, BOOL fCurrent, int tbbsx);

/*	Draws the owner-drawn part of a SDM-dropdown lookalike with the given
	color. cs is one of msocsxxx. Color ignored for Automatic. */
MSOAPI_(void) MsoRenderColorSDMDropdown(HDC hdc, RECT *prc, int cs,
		COLORREF cr, int tbbsx);

/* Fills prc with the rectangle that should be filled with the current color/pattern/
	gradient fill/whatever for the msotcidPaint and msotcidBrush controls. prc is
	input (the button rectangle), prcPaint output (where to paint). Handles small/big
	buttons sizes correctly. */
MSOAPI_(void) MsoGetPaintRectangle(RECT *prc, RECT *prcPaint);

/*	Paints a rectangle of solid color, or "none". cs is one of msocsxxx (no
	label is ever displayed). Uses the Office conventions as to whether to
	draw a border or not, etc. For use when drawing icons. */
MSOAPI_(void) MsoRenderSolidPaintRectangle(HDC hdc, RECT *prc, int cs, COLORREF cr);

/*	Remnant from when we were coloring pixels in icons to match the MRU color.
	All it does today is draw the icon. */
// FUTURE: remove after API thaw, unfortunately still in use by Word
MSOAPI_(void) MsoPaintColorIcon(HDC hdc, RECT *prc, int tcid, int tbbsx, COLORREF cr);
MSOAPI_(void) MsoCbvPaintColorIcon(HDC hdc, RECT *prc, int tcid, int tbbsx, MSOCEO *pceo);

/* Wrapper to do all of the commandbar drawing code */
MSOAPI_(void) MsoCbvDrawButton(MSOCTLENV *pce, int tcid, IMsoButtonUser *pibu, 
						void **ppvPibu, HANDLE hdibCustom, HANDLE hmaskCustom, 
						int tbbsx, WCHAR *wtz, int ftReq, int tbbsx2);

/* Wrapper to draw a custom or tcid-based icon into a rectangle, including
   saturation/shadow/etc effects. */
MSOAPI_(void) MsoCbvDrawIcon(HDC hdc, MSOCEO *pceo, int tcid, HANDLE hdibCustom,
			HANDLE hmaskCustom, RECT *prc, COLORREF crBkgd, int tbbsx, UINT fuFlags);


/*	Does the full drawing work for the button part of owner-drawn controls
	for the color controls (Fill Color, Line Color, Font Color, etc). You can
	call this directly from your TbbodDraw user methods. */
MSOAPI_(int)  MsoTbbodRenderPaintColorIcon(HDC hdc, RECT *prc, int tcid,
		int tbbsx, int odm, int cs, COLORREF cr);

/* Draws a 1-pixel thick rectangle, using crUpper for left and up, and crLower
	for right and bottom. Also shrinks prc by 1. */
MSOAPI_(void) MsoDrawOneBorder(HDC hdc, RECT *prc, COLORREF crUpper, COLORREF crLower);

/* Spelunks through the pconpic for the gccr belonging to the gcc known as
   tmc to sdm. */
MSOAPIX_(BOOL) MsoFGccrFromTmc(HMSOINST pinst, INT_PTR tmc, MSOGCCR **pgccr);

/* Returns the IMsoToolbar of the current tracking menu */
MSOAPIX_(IMsoToolbar *) MsoPitbTracking();

/* Select and realize the office palette into hdc. */
MSOAPI_(HPALETTE) MsoHpalSelectAndRealizeIfNecessary(IMsoToolbar *pitb, HDC hdc, BOOL fForceBackground);

/* Given a pic, return its control site interface, TB, and TBS.  Pass NULL
	for values that are not desired.  Returned pointers will be NULL if
	that part doesn't exist for the control. */
MSOAPI_(void) MsoGetMoreFromPic(IMsoControl *pic, IMsoControlSite **ppics,
						  IMsoToolbar **ppitb, IMsoToolbarSet **ppitbs);

/* Touch a control's PIP record as if the control had just been executed by the
   user.  NOTE:  This should NOT be used in most situations.  This has been
   added for a unique situation in Project. */
MSOAPI_(void) MsoTouchCtlPIP(IMsoControl *pic, BOOL fInMenu);

/* Determines whether or not the toolbarset should be deactivated based on who is
		gaining activation. */
MSOAPI_(BOOL) MsoFShouldDeactivateToolbars(HWND hwnd, IMsoToolbarSet *pitbs);
// Call this function if you call MsoFShouldDeactivateToolbars so that a toolbarset that
//		didn't get deactivated can be at the appropriate time.
MSOAPI_(void) MsoFActivatingToolbars(IMsoToolbarSet *pitbs);

/****************************************************************************
	Message filters

	Toolbars require four filters (in addition to full Component Manager
	compliance):

	1. TBS::FHandledMessage
	2. MsoFWndProc
	3. MsoNCActivate
	4. MsoPeekMessage
****************************************************************************/

/*---------------------------------------------------------------------------
	1. TBS::FHandledMessage

	Must be in the message pump (before dispatching messages). Sample code:

	if (MsoFHandledMessageNeeded(msg))
		{
		IMsoToolbarSet *pitbs;
		LRESULT lr;
		AssertDo(MsoFPitbsFromHwndAndMsg(hwnd, msg, &pitbs));
		if (pitbs && pitbs->FHandledMessage(hwnd, msg, wParam, lParam, pitbs, &lr))
			goto EndLoop;	// discard the message and call PeekMessage or GetMessage again
		}
	// else continue on to TranslateMessage and DispatchMessage
---------------------------------------------------------------------------*/

/*	Quick function that returns TRUE if TBS::FHandledMessage needs that
	message. */
MSOAPI_(BOOL) MsoFHandledMessageNeeded(UINT msg);

/*---------------------------------------------------------------------------
	2. MsoFWndProc.
	
	Must be at the top of each top-level WndProc that owns a toolbar set.
	Sample code:

	if (MsoFWndProcNeeded(msg))
		{
		IMsoToolbarSet *pitbs;
		LRESULT lr;
		AssertDo(MsoFPitbsFromHwndAndMsg(hwnd, msg, &pitbs));
		if (MsoFWndProc(hwnd, msg, wParam, lParam, pitbs, &lr))
			return lr;		// discard message and return
		}
	// else continue on to your normal MainWndProc code
---------------------------------------------------------------------------*/

/*	Quick function that returns TRUE if MsoFWndProc needs that message. */
MSOAPI_(BOOL) MsoFWndProcNeeded(UINT msg);

/* This must be inserted at the top of each top-level WndProc that owns a
	toolbar set. If Office returns TRUE, the app should return from its
	WndProc immediately with the value stored in plr. Otherwise the app should 
	process it as it normally does. */
MSOAPI_(BOOL) MsoFWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam,
		IMsoToolbarSet *pitbs, LRESULT *plr);

/*---------------------------------------------------------------------------
	3. MsoNCActivate
	
	Must be called for each top-level WndProc in their WM_NCACTIVATE case
	before any other local processing.  This call allows office to modify
	the wParam before you call the DefProc.  If you don't add this call,
	your office title bar may go inactive when it shouldn't.

	Sample code:

	switch(msg)
		{
	case WM_NCACTIVATE:
		MsoNCActivate(hwnd, &wParam);
		// other processing
		return DefFrameProc(...);
		}
---------------------------------------------------------------------------*/

// Allows Office to modify the activation state when necessary for all
// activation changes.
MSOAPI_(VOID) MsoNCActivate(HWND hwnd, WPARAM *pwParam);

/*	Fills ppitbs with the toolbar set Office thinks the given message should
	be sent to (i.e., passed to MsoFWndProc). Returns TRUE if Office is
	certain of its result (all ambiguities resolved), and FALSE otherwise.
	Office will resolve ambiguities in all cases it can handle by itself.
	If this function fails, it is your responsibility to give MsoFWndProc the
	correct toolbar set. The debug version asserts when returning FALSE.
	hwnd = NULL is supported for the Mac. */
MSOAPI_(BOOL) MsoFPitbsFromHwndAndMsg(HWND hwnd, UINT msg, interface IMsoToolbarSet **ppitbs);

/*	Fills ppitbs with the toolbar set Office thinks is associated with this
	window, and returns TRUE if Office is certain of its result (which may be
	ppitbs NULL, no toolbar set attached to this hwnd), and FALSE otherwise. */
MSOAPI_(BOOL) MsoFPitbsFromHwnd(HWND hwnd, interface IMsoToolbarSet **ppitbs);

/*---------------------------------------------------------------------------
	4. MsoPeekMessage

	Must be called from the message pump(s), *before* GetMessage is called.
	Simplified code would be:

	MSG msg;
	if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
		MsoPeekMessage(Office instance, &msg);
		if (fCMLoopPushed && !picm->FContinueMsgLoop(&msg))
			break out of message pump;
		GetMessage(&msg, NULL, 0, 0);
		// rest of message pump
		}

	If you already have a PeekMessage stage in your pump (most apps do), just
	insert the call to MsoPeekMessage in this stage. If you don't, you need
	to add one. FYI, PeekMessage is much faster without a filter
	(range = 0, 0) instead of with.

	It is essential that this function be called before messages are
	retrieved from the queue. An easy way to test if it works right is to
	drop a command bar menu, and double-click on your app system box. If your
	app doesn't try to quit, then you're calling MsoPeekMessage wrong.

	Although it doesn't hurt to call this from Mac, it doesn't seem to be
	needed at this point. WLM retrieves messages from the queues a little
	differently than Windows (they do some stuff after GetMessage that
	Windows does before), so MsoPeekMessage doesn't help any. If you have
	separate pumps for Win and Mac, don't bother about the Mac (yet!).

	MsoPeekMessage is of course guaranteed as fast as we can make it (it
	returns instantly in most cases).
---------------------------------------------------------------------------*/

MSOAPI_(void) MsoPeekMessage(HMSOINST hinst, MSG *pmsg);


/* When fDontChange is TRUE, toolbars will NOT set the cursor in response
   to WM_SETCURSOR messages sent to ToolbarWndProcs.  Toolbars will always
   return TRUE to the message when this is set. This is useful for
   apps in modal loops that need to poll the event queue for other events.
   Note that other routines may still change the cursor. */
MSOAPI_(void) MsoSetToolbarCursorMode(BOOL fDontChange);

/****************************************************************************
	Toolbar animations
****************************************************************************/

/* Sets the toolbar dropdown animation style */
enum
	{
	msotbasNone = 0,		// doubles as System Default
	msotbasRandom,
	msotbasUnfold,
	msotbasSlide,			// like Encarta
	msotbasFade,

	msotbasMaxDropdown,
	// None of these items should appear on the customize dropdown
	msotbasStoL = msotbasMaxDropdown,			// Short to Long - don't use for normal showing...
	msotbasStoLFade,		// Short to Long - don't use for normal showing...
	msotbasMax,				// sentinel
	};

MSOAPI_(int)  MsoTbasGetTbAnimationStyle();
MSOAPI_(void) MsoSetTbAnimationStyle(int tbas);

// gets/sets whether keyboard shortcuts should be displayed appended to tooltips
// this setting is Office wide and saved in the registry
MSOAPI_(BOOL) MsoFGetTbShowKbdShortcuts();
MSOAPI_(void) MsoSetTbShowKbdShortcuts(BOOL fShowKbdShortcuts);

// gets/sets whether to show the Font Dropdown using wysiwyg fonts
// this setting is Office wide and saved in the registry
MSOAPI_(BOOL) MsoFGetTbFontView();
MSOAPIX_(void) MsoSetTbFontView(BOOL fShowKbdShortcuts);

#ifdef CLEARTYPE
// gets/sets whether to use ClearType when rendering text
// this setting is Office wide and saved in the registry
MSOAPI_(BOOL) MsoFGetTbClearType();
MSOAPIX_(void) MsoSetTbClearType(BOOL fUseClearType);
#endif // CLEARTYPE

MSOAPI_(void) MsoPrepareWebToolbarsForMerge(LPOLEINPLACEFRAME pIPFrame, IMsoToolbarSet *pitbs);

#define FIsWebTbid(tbid) 	 (	msotbidHistoryMenu == (tbid) || msotbidFavoritesMenu == (tbid) || \
								msotbidWeb == (tbid) || msotbidWebOptionsMenu == (tbid))
	
// These functions allow for standard handling of SDM workpanes.
//		If there is no need for overrides, use the first function to get a pfn
//			to pass into TBS::FShowWorkPane
//		If there is need for overrides, create your own pfn and at the end of
//			all un-handled messages, call the second function (think: DefWindowProc)
MSOAPI_(MSOPFNWPCALLBACK) MsoPfnGetSDMWorkPaneCallback(void);
MSOAPI_(BOOL) MsoFCallSDMWorkPaneCallback(int idWP, int tbwpc, void * pwpInfo, 
				void * param1, void * param2);
MSOAPI_(void **) HdlgFromWpSDM(MSOWPSDM *pwpSDM);
MSOAPIX_(void *) HCabFromWpSDM(MSOWPSDM *pwpSDM);

MSOAPI_(void) MsoIdealAutoLayoutCurDlgWP(POINT * pPt);

/* Returns true if a pane has grabbed focus and F6 was consumed by Office,
   and false if no pane is currently active (and so the app should do the
   normal thing for F6). */
MSOAPI_(BOOL) MsoFProcessF6Loop(IMsoToolbarSet *pitbs, BOOL fReverse);
MSOAPI_(BOOL) MsoFPassMsgToComponent(MSG *pmsg);
MSOAPI_(void) MsoSetUnicodeMessageLoop(BOOL fUnicode);

MSOAPI_(HFONT) MsoGetOrientedFont(const BOOL fVertical, int msotbftReq);
MSOAPI_(BOOL) MsoFAnimateWindow(HWND hwnd, DWORD time, DWORD aw);

MSOAPI_(void) MsoSetIgnoreDeactivation(BOOL fSet);


// Arrow types (used for the MsoGetOrientedArrowWidth call)
enum
	{
	msotbatDefault =     0x0001,
	msotbatSizeByFont =  0x0001,
	msotbatSizeByBtn =   0x0002,
	msotbatNoRotate =    0x0004,
	msotbatForceRotate = 0x0008,
	};

MSOAPI_(int) MsoGetOrientedArrowWidth(const MSOCEO *pceo, const int at);

#endif // MSO_NO_INTERFACES


/****************************************************************************
	 Prototypes used to support the button editor (was COMMTB32.DLL)
****************************************************************************/
#ifndef MSO_NO_INTERFACES

MSOAPI_(BOOL) TB_FInit(void);
MSOAPIX_(void) TB_Uninit(void);
MSOAPI_(BOOL) FLoadComctl32Lib();
MSOAPI_(HANDLE) TB_CreateMask(DWORD  RGBBkgd, BITMAPINFO *pbmiColor);
MSOAPI_(HANDLE) TB_CreateDisable(BITMAPINFO *pbmiColor, BITMAPINFO *pbmiMask);
MSOAPI_(int) TB_GetSize(BITMAPINFO *pbmi);
MSOAPI_(BOOL) WIN_DIBPtrToBitMap(BITMAPINFO *pbmi, HBITMAP *phBitMap);
MSOAPI_(void) WIN_SysColorChange(void);
MSOAPI_(BOOL) TB_DrawButton(HDC hdc, HDC hMemDC, RECT *pr, HBITMAP hBmp, HBITMAP hMaskBmp,
							int iX, int iY,int iWidth, int iHeight, WORD wState, BOOL fIsDIB);

#endif // MSO_NO_INTERFACES


// Mso Toolbar Fill Id
enum
	{
	msotbfidInitTb = 0,
	msotbfidResetTb,
	msotbfidDropMenu,
	msotbfidOriginalTb, 
	};

#if VSMSODEBUG
	MSOAPI_(void) MsoDebugToolbarScafolding();
#endif

#if DEBUGHDC
// Don't remove without asking TCoon
// Helpful in tracking down runaway DC's
HDC msoDebugGetDC(HWND hwnd, char *szfile, int iline);
int msoDebugReleaseDC(HWND hwnd, HDC hdc, char *szfile, int iline);
#define GetDC(x) msoDebugGetDC(x, __FILE__, __LINE__)
#define ReleaseDC(x, y) msoDebugReleaseDC(x, y, __FILE__, __LINE__)
#endif
#endif // MSOTB_H
