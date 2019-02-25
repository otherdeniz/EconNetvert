#pragma once

/****************************************************************************
    msores.h

    Owner: jimmur
    Copyright (c) 1994 Microsoft Corporation

    Reading various and sundry  Office resoruce types
****************************************************************************/
#if !defined(MSORES_H)
#define MSORES_H

#if !defined(MSOSTD_H)
#include <msostd.h>
#endif

/****************************************************************************
   This enum specifies the flags associated with a office Bitmap.  They are
   used when loading the bitmap.
 ****************************************************************************/
typedef enum
{
	msoolbSlow = 0, msoolbSmall = 0, msoolbHorizontal = 0,
	msoolbMedium = 1,
	msoolbFast = 2, msoolbFat = 2,
	msoolbSpeedMask = 0x03, msoolbSizeMask = 0x03,

	msoolbShared = 0x100,
	msoolbVertical = 0x200,
	msoolbHasMask = 0x400,
	msoolbNoDither = 0x8000,
};

/****************************************************************************
	HBSTRIP is an opaque reference to an Office Bitmap record.
 ****************************************************************************/
typedef struct BSTRIP* HBSTRIP;
#define hbstripNil ((HBSTRIP)NULL)

/****************************************************************************
	The MSOCCI Structure is used to define chromakey changes when drawing a
   bitmap
 ****************************************************************************/
typedef struct
{
   int      ipcchange;     // index into the color pallette of color to change
   COLORREF crNew;         // New color to put inot the Pallette
}MSOCCI;

/****************************************************************************
	The MSOCCIH Structure is used to specify multiple MSOCCI structures when
   drawing a bitmap
 ****************************************************************************/
typedef struct
{
   int    ccci;            // count of change color records
   MSOCCI rgcci[1];        // Color Change Records
}MSOCCIH;

/****************************************************************************
	Office Bitmap manipulation functions
 ****************************************************************************/

 /* Given an instance handle (hinst), and the resource id to load (idb),
  * returns a pointer to the bitmap, starting with a BITMAPINFO structure.
  * Automatically uncompresses the bitmap if stored as an LZBITMAP resource.
  * Returns NULL on error
  *
  * If pbi is NULL, space for the bitmap is allocated on the heap.  Free
  * this memory by calling MsoFreeBitmap on this pointer when you are
  * finished with it.
  *
  * If pbi is not NULL, it points to a buffer (cbbi bytes long) that will
  * receive the bitmap.  If the buffer is not large enough to hold the bitmap
  * then NULL is returned and the BITMAPINFOHEADER will be stored into the 
  * buffer on failure
  *
  * Note that if you don't have any specific place you want to store the
  * bitmap, it is more efficient to let MsoLoadBitmap load the bitmap, rather
  * than providing your own pointer.  The pointer is provided for loading
  * the bitmap directly into shared memory (for example).
  */
#define MsoLoadBitmapResource(hinst, idb) MsoLoadBitmapResourceEx((hinst),(idb),NULL,0)

MSOAPI_(BITMAPINFO *) MsoLoadBitmapResourceEx(HINSTANCE hinst, int idb, BITMAPINFO *pbi, DWORD cbbi);

 /* Frees a Bitmap allocated by MsoLoadBitmapResource. */
MSOAPI_(VOID) MsoFreeBitmapResource(BITMAPINFO *pbi);

 /* Loads a bitmap resource and creates an HBITMAP from it, uncompressing
  * the source image first if necessary.  This object is a real GDI object
  * and should be freed using DeleteObject().
  *
  * Returns NULL on error.
  */
MSOAPI_(HBITMAP) MsoLoadBitmap(HINSTANCE hinst, int idb);

 /*  Given an instance handle (hinst), the resource id to load (idb), the
    number of sub bitmaps in the bitmap (one based), and a set of flags
    (msoolb), this funciton will load in a bitmap and return a handle to
    an Office bitmap object in the phbstrip out parameter.  Returns Success. */
MSOAPI_(BOOL) MsoFLoadBStrip(HINSTANCE hinst, int idb, int cbmp, int olb,
                             HBSTRIP * phbstrip);

 /*  Given an instance handle (hinst), the resource id to load (idb), the
    number of sub bitmaps in the bitmap (one based), the width (idx) and the
    height (idy) of the subbitmaps ( or 0 if square subbitmaps or a single
    bitmap) and a set of flags (msoolb), this funciton will load in a 
    bitmap and return a handle toan Office bitmap object in the phbstrip 
    out parameter.  Returns Success. */
MSOMACAPI_(BOOL) MsoFLoadBStripEx(HINSTANCE hinst, int idb, int cbmp, int olb,
									  int idx, int idy, HBSTRIP * phbstrip);

/*	Given a BITMAPINFO * (DIB)  the number of sub bitmaps in the 
	DIB (one based), and a setof flags(olb), this function will wrap a 
	DIB and return a handle to an Office bitmap object in the phbstrip 
	out parameter.  Returns Success.	*/
MSOAPI_(BOOL) MsoFWrapDIB(BITMAPINFO * pbi, int cbmp, int olb, 
										HBSTRIP * phbstrip);

/* Deletes the Office Bitmap object specified by the hbstrip parameter. */
MSOAPI_(void) MsoFreeBStrip(HBSTRIP hbstrip);

/* Given a handle to an Office Bitmap object, this function will place in the
   psize out parameter the size of the bitmap. If fSingle is true, psize
	will get the size of a single bitmap within the bstrip. */
MSOAPI_(BOOL) MsoFGetInfoBStrip(HBSTRIP hbstrip, BOOL fSingle, SIZE * psize);

/* Draws the subbitmap ibmp, from the  hbstrip Office Bitmap object in the
   hdc at location x,y using the rop rastorOp.  If the pmsoccih parameter
   is not NULL, then it will change the colors specified in the MSOCCIH
   structure before drawing the bitmap. Returns success. */
MSOAPI_(BOOL) MsoFDrawBStrip(HDC hdc, int x, int y, HBSTRIP hbstrip, int idb,
                             DWORD rop, MSOCCIH * ccih);

/* Draws the subbitmap ibmp, from the  hbstrip Office Bitmap object in the
   hdc at location x,y and stretched to fill the rectangle specified by
   dx and dy using the rop rastorOp.  If the pmsoccih parameter is not
   NULL, then it will change the colors specified in the MSOCCIH structure
   befored rawing the bitmap. Returns success. */
MSOAPI_(BOOL) MsoFStretchBStrip(HDC hdc, int x, int y, int dx, int dy,
                                HBSTRIP hbstrip, int idb, DWORD rop,
                                MSOCCIH *  ccih);

/* Extract a HBITMAP indexed idb from hbstrip in the phb out parameter.
   Returns Success. */
/* FUTURE: phb is NOT an HBITMAP pointer -- it's a BITMAPINFO pointer with
	bits hanging off of it, like a DIB resource.  Should fix the declaration
	some day */
MSOAPI_(BOOL) MsoFGetSubBitmap(HBSTRIP hbstrip, int idb, HBITMAP * phb);

/* Check the internal consistency of the hbstrip office bitmap and returns
   whether or not this office bitmap is valid */
#if VSMSODEBUG
	MSOAPIXX_(BOOL) MsoFValidBStrip(HBSTRIP hbstrip);
#else
	#define MsoFValidBStrip(hbstrip) (TRUE)
#endif

/* Write out the BE record for a HBSTRIP.  This is used for memory leak
   detection */

#if VSMSODEBUG
   MSOAPI_(BOOL) MsoFWriteBStripBe(HBSTRIP hbstrip, LPARAM lParam);
#endif

// rendering codes for MsoFBDrawStripAsButton.
#define msodbsabNormal		0
#define msodbsabDither		(1<<0)
#define msodbsabDisable		(1<<1)	// simultaneously dithered and disabled not supported
#define msodbsabDrawText	(1<<2)	// maps black to the button text color
#define msodbsabCbvCtlBkgd (1<<3)	// Uses the new CBV values for Control background
#define msodbsabCbvMouseOver (1<<4)	// Uses the new CBV values for Mouse Over
#define msodbsabCbvMouseDown (1<<5)	// Uses the new CBV values for Mouse Down
#define msodbsabCbvDisabled  (1<<6)	// Uses the new CBV values for Disabled
#define msodbsabCbvInMenu    (1<<7) // On a menu, use the right CBV background
#define msodbsabCbvSelected  (1<<8) // Uses the new CBV values for Selected
#define msodbsabCbvSelectedMouseOver  (1<<9) // Uses the new CBV values for Selected Mouse Over

/* Wrapper for MsoFDrawBStrip that maps VGA colors 10 and 13 as appropriate
	for drawing bits on Command Bars. dbsab is one of msodbsabxxx above.

	msodbsabNormal: 
		maps both of these colors to the Button Face color.

	msotbsabDither:
		maps 10 to Button Face and 13 to another color. This can be used to draw
		the "latched" version of a command bar item.
		
	msotbsabDisable:
		draws the item disabled. Note that both dithered & disabled not supported. 

	msotbsabDrawText:
		maps black to the button text color. */
MSOAPI_(BOOL) MsoFDrawBStripAsButton(HDC hdc, int x, int y, HBSTRIP hbstrip,
	int idb, int dbsab);
MSOAPI_(BOOL) MsoFDrawBStripAsButtonChroma(HDC hdc, int x, int y,
	HBSTRIP hbstrip, int ibmp, int dbsab, BOOL fChroma);

/* Compression/Decompression routines for bitmaps */
MSOAPI_(void) MsoUncompressLZW(const BYTE *pIn, BYTE *pOut, int cbOut);
MSOAPI_(int) MsoCompressLZW(const BYTE *pIn, BYTE *pOut, int cbIn);

/*************************************************************************
	Resource IDs
*************************************************************************/

/* New Office resource types */

#define MsoSttHuff 216
#define rtOffString 217
#define MsoHuffTable 218
#define rtMsoIconLookup 219
#define rtBootIds 230

/* The following are resource types which are not in the Win32 reserved
	name space and are not intended for app use - they should only appear
	inside the MSO resource file and they probably clash with App defined
	types. */
#define MsoResJFIFData 0x0101   // Data is in JFIF file format
#define MsoResWMFData  0x0102   // Raw WMF (PICT on Mac) data
#define MsoResBitData  0x103    // Raw bitmap bit data
#define MsoResCharsetData 0x104 // Charset table data
#define MsoResZlibFlag 0x1000   // Flag: data has been compressed with Zlib


/*************************************************************************
	Data to resource definitions
*************************************************************************/

/*	These 2 macros should be wrapped around any localizable data
	that should be converted into a resource. */

#define MsoBeginResDef(resType, resId) \
		data_seg("mso96_"#resType"_"#resId)

#define MsoEndResDef() data_seg()




/*************************************************************************
	Resource types and ids of data converted to resources
*************************************************************************/

/* intl structure in intl.cpp */
#define msorestypeIntl 220
#define msoresidIntl1 1

/* dlg structure in dlgres.cpp*/
#define msorestypeDlg 221

/* Loc id structure output by new DC.EXE. */
#define msorestypeLocIds 222

/* FE MsoCompareStringW ideographic exception tables */
#define MSORTCompStr 223	// type
// ids
#define MSORIBIG5			1
#define MSORIPRCP			2
#define MSORIPRC			3
#define MSORIXJIS			4
#define MSORIKSC			5
#define MSORIKSCSCRIPT	6
#define MSORIKSCALPHA	7
#define MSORIKSCUNIPT	8
#define MSORIKSCUNIPTSCRIPT	9
#define MSORIKSCCANTCOMPRESS	10
//SUKHABUT
#define MSORIBOPOMOFO				11
//SUKHABUT

/* FarEast Leading and Following Punctuation Tables */
#define msorestypeFEPunc 224 

#ifdef DECAL
#define msorestypeDecal	225
#endif

#define msoidtLeadingJapan     1
#define msoidtLeadingKorea     2
#define msoidtLeadingChina     3
#define msoidtLeadingTaiwan    4

#define msoidtFollowingJapan  11
#define msoidtFollowingKorea  12
#define msoidtFollowingChina  13
#define msoidtFollowingTaiwan 14

#endif /* MSORES_H */

