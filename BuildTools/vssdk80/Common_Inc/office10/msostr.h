#pragma once

/*************************************************************************
 	msostr.h

	Owner: rickp
 	Copyright (c) 1994 Microsoft Corporation

	Standard string utilities for Office.  We have fairly a complete
	set of operations on the SZ (null-terminated single-byte string),
	WZ (null-terminated unicode string), and WTZ (null-terminated
	unicode string with length word) types, and a few random other
	string representations thrown in.
*************************************************************************/

#if !defined(MSOSTR_H)
#define MSOSTR_H

#if !defined(MSOSTD_H)
#include <msostd.h>
#endif
#include <msointl.h>

#if !defined(MSODEBUG_H)
#include <msodebug.h>
#endif

#if !defined(_INC_MINMAX)
#include <minmax.h>
#endif

#if defined(__cplusplus)
extern "C" {
#endif


/*************************************************************************
	Unicode character utilities
*************************************************************************/

/*
Special Turkish sort order defined by Office - different from system's
default Turkish sort order in that undotted i's sort before dotted i's -
in the system, they both sort equal. To use, or in the mask with the
LCID passed to the MsoCompareString* routines.
*/

#define MSO_TURKISH_SORT 0xf
#define MSO_TURKISH_SORT_MASK 0x000f0000

MSOAPI_(BOOL) MsoFPuncWch(WCHAR wch);

MSOAPI_(BOOL) MsoFAlphaWch(WCHAR wch);

MSOAPI_(BOOL) MsoFSpecChWch(WCHAR wch);

MSOAPI_(BOOL) MsoFComplexMarkWch(WCHAR wch);

MSOAPI_(BOOL) MsoFSpaceWch(WCHAR wch);

MSOAPIXX_(BOOL) MsoFSpaceCh(CHAR ch);

MSOAPI_(int) MsoCompareStringA(LCID Locale, DWORD dwCmpFlags,
		LPCSTR lpString1, int cchCount1, LPCSTR lpString2, int cchCount2);

MSOAPI_(int) MsoCompareStringW(LCID Locale, DWORD dwCmpFlags,
		LPCWSTR lpString1, int cchCount1, LPCWSTR lpString2, int cchCount2);

/*	Returns fTrue if and only if wch is a digit. */
MSOAPI_(BOOL) MsoFDigitWch(WCHAR wch);

/*	Returns TRUE if and only if ch is a digit. */
MSOAPI_(BOOL) MsoFDigitCh(int ch);

/* Returns TRUE if and only if wch is a hex digit. */
MSOAPIX_(BOOL) MsoFHexDigitWch(WCHAR wch);

/*	Returns fTrue if and only if wch is an alphanumeric character. */
MSOAPIX_(BOOL) MsoFAlphaNumWch(WCHAR wch);

/*	Returns TRUE if and only if wch is a digit or an alpha with upper/lowercase. */
MSOAPIX_(BOOL) MsoFUpperLowerDigitWch(WCHAR wch);

/*	Returns TRUE if and only if wch is a valid character in the code page. */
MSOAPIX_(BOOL) MsoFWchInCpg(WCHAR wch, int cpg);

/* Converts wch to lower case and returns the result. */
MSOAPIMX_(WCHAR) MsoWchLower(WCHAR wch);

/*  Returns FS_* font signature flags indicating code pages which support
    the supplied Unicode character. */
MSOAPI_(int) MsoFsFromWch(WCHAR wch);

/*	Returns fTrue if and only if wch is a FE char. */
MSOAPI_(BOOL) MsoFFEWch(WCHAR wch);

/* Returns an FS_* font signature flag corresponding to a particular code
	page, these two routines can be used to work out spans of characters
	which fit in to a give code page, hence can be represented by a single
	Win95 Charset. */
MSOAPI_(int) MsoFsCpgFromCpg(int cpg);

MSOAPI_(int) MsoFsCpgFromCpgChkFamily(int cpg);

/* Return the charset that corresponds to a given code page (i.e. that
	contains the glyphs for the characters in that code page). */
MSOAPI_(BYTE) MsoChsFromCpg(int cpg);

/* Return the code page from a font signature bit array.  Based on the Word
	code but this handles a full array (but the code page returned is fairly
	random) - i.e. multiple bits may be set in fsCpg. */
MSOAPI_(CPG) MsoCpgFromFsCpg(int fsCpg);

MSOAPI_(int) MsoFToggleCharCode(LPWSTR pwtSrc, LPWSTR pwtDest, int fExact);


//SOUTHASIA

BOOL MsoIsWchVietToneMark(WCHAR wch);
BOOL MsoIsWchIndicVowel(WCHAR wch);

BOOL MsoFIsThaiText(LPCWSTR lpwch, LPCWSTR lpwchEnd);
BOOL MsoFIsThaiChar(WCHAR wch);

MSOAPIX_(BOOL) MsoIsIndicFont(HDC hdc, LOGFONT lf);
//SOUTHASIA


/*************************************************************************
	Unicode Japanese character normalization routines from Word.
    (Fuzzy Normalization)
*************************************************************************/

/* Fuzzy Option Flags Structure - for Fuzzy Normalization.*/
typedef struct _MSOGRPFFUZ
	{
	union
		{
		unsigned int grpfFuzExp;
		struct
			{
			ULONG		fEqCase : 1;				// ( 0) upper/lower case
			ULONG		fEqByte : 1;				// ( 1) single/double byte
			ULONG		fEqMinus : 1;				// ( 2) minus/long vowel
			ULONG		fEqHira_Kata : 1;			// ( 3) hiragana/katakana
			ULONG		fEqSmallKana : 1;			// ( 4) small kana
			ULONG		fEqRepSymbol : 1;			// ( 5) repeated symbols
			ULONG		fEqOldKana : 1;				// ( 6) old kana
			ULONG		fEqLongVowel : 1;			// ( 7) several exp with long vowel
			ULONG		fEqD_Z : 1;					// ( 8) DI/JI DU/ZU
			ULONG		fEqB_V : 1;					// ( 9) BA/VA
			ULONG		fEqT_C : 1;					// (10) TSI/THI/CHI
			ULONG		fEqDhi_Zi : 1;				// (11) DHI/ZI
			ULONG		fEqY_A : 1;					// (12) YA/A
			ULONG		fEqS_SH : 1;				// (13) SHE/SE JE/ZE
			ULONG		fEqKI_KU : 1;				// (14) KI/KU
			ULONG		fEqF_H : 1;					// (15) FU/HU
			ULONG		fEqKanji : 1;				// (16) kanji ("itaiji")
			ULONG		fEqSoundsLike : 1;			// (17) sounds like

			ULONG		fIgnorePunct : 1;			// (18) ignore punctuation char
			ULONG		fIgnoreSpace : 1;			// (19) ignore space char

			ULONG		fDontIgnore : 1;			// (20) ignore nothing
			ULONG		fDontIgnoreLast : 1;		// (21) ignore nothing at the end of str

			ULONG		: 10;
			};
		};
	} MSOGRPFFUZ;

/* 	%%Function: MsoCwchGetAltChar
	%%Contact: katsun,kander

	Get alternate characters of wchOrig.
	Result characters are put in pwchResult which includes the original
	character.
	If return value is zero, there is no alternate characters. */
MSOAPI_(int) MsoCwchGetAltChar(WCHAR wchOrig, WCHAR *pwchResult, int cwchResultMax);

/*	%%Function: MsoCwchNormFuzzy
	%%Contact: katsun,kander

	Normalize fuzzy expression in rgwchSrc into rgwchDest.
	rgwchDest must be big enough to hold the result string.
	It does not ignore anything if fDontIgnore is fTrue.
	Return cwchDest if succeed. */
MSOAPI_(int) MsoCwchNormFuzzy(WCHAR *rgwchSrc, int cwchSrc, WCHAR *rgwchDest, MSOGRPFFUZ *pgrpffuz);



/*************************************************************************
	Simple string utilities
*************************************************************************/

/*	A simple string copy, copying szFrom to szTo.  Returns a pointer to
	the end of the destination string. */
MSOAPI_(CHAR*) MsoSzCopy(const CHAR* szFrom, CHAR* szTo);

/*	A simple string copy, copying wzFrom to wzTo.  Returns a pointer to
	the end of the destination string. */
MSOAPI_(WCHAR*) MsoWzCopy(const WCHAR* wzFrom, WCHAR* wzTo);

/* Copies the lesser of len(wzFrom) or n characters (n includes the
	null terminator) from wzFrom to wzTo. */
MSOAPI_(void) MsoWzCchCopy(const WCHAR* wzFrom, WCHAR* wzTo, int cch );

/*	Copies the lesser of len(szFrom) or n characters (n includes the
	null terminator) from szFrom to szTo. */
MSOAPI_(void) MsoSzCchCopy(const CHAR* szFrom, CHAR* szTo, int cch);

/*  Copies cch characters from rgwchFrom to wzTo and null terminates wzTo */
MSOAPI_(WCHAR*) MsoWzRgwchCchCopy(const WCHAR* rgwchFrom, WCHAR* wzTo, int cch);

/*	A simple string copy, copying wtzFrom to wtzTo. */
MSOAPI_(void) MsoWtzCopy(const WCHAR* wtzFrom, WCHAR* wtzTo);

/*	A simple string copy, copying wtFrom to wtTo. */
MSOAPI_(void) MsoWtCopy(const WCHAR* wtFrom, WCHAR* wtTo);

/*	Returns pointer to first occurrence of ch in rgch, NULL if not found. */
MSOAPI_(CHAR*) MsoRgchIndex(const CHAR *rgch, int cch, int ch);

/*	Returns pointer to first occurrence of wch in rgwch, NULL if not found. */
MSOAPI_(WCHAR*) MsoRgwchIndex(const WCHAR *rgwch, int cch, int wch);

/*	Returns pointer to last occurrence of wch in rgwch, NULL if not found. */
MSOAPIX_(WCHAR*) MsoRgwchIndexRight(const WCHAR *rgwch, int cch, WCHAR wch);

/*	Returns the length, in bytes, of the sz derived from wz.  -1 on error */
MSOAPI_(int) MsoCpCchSzLenFromWz(UINT CodePage, const WCHAR *wz);

/*	Returns the length, in bytes, of the SBCS/DBCS string sz. */
MSOAPI_(int) MsoCchSzLen(const CHAR* sz);

/*	Returns the length of the Unicode string wz. */
MSOAPI_(int) MsoCchWzLen(const WCHAR* wz);

/*	Returns the length of the Unicode string wtz. */
__inline WORD MsoCchWtzLen(const WCHAR* wtz) { return (WORD)wtz[0]; }

/*	Returns the length of the Unicode string wt. */
__inline WORD MsoCchWtLen(const WCHAR* wt) { return (WORD)wt[0]; }

/*	Append null-terminated string szFrom onto the end of szTo, and
	returns a pointer to the end of the destination string. */
MSOAPI_(CHAR*) MsoSzAppend(const CHAR* szFrom, CHAR* szTo);

/*	Append null-terminated string wzFrom onto the end of wzTo, and
	returns a pointer to the end of the destination string. */
MSOAPI_(WCHAR*) MsoWzAppend(const WCHAR* wzFrom, WCHAR* wzTo);

/*	Append the WTZ string wtzFrom onto the end of wtzTo. */
MSOAPI_(void) MsoWtzAppend(const WCHAR* wtzFrom, WCHAR* wtzTo);

/* Appecnds cch-strlen(wzTo) chars from wzFrom onto the end of wzTo, and
	returns a pointer to the end of the destination string. */
MSOAPI_(WCHAR*) MsoWzCchAppend(const WCHAR* wzFrom, WCHAR* wzTo, int cch);

/* get text part of length-preceeded strings */

/* Returns a pointer to the text part of the string wtz */
__inline WCHAR* MsoWzFromWtz(const WCHAR* wtz) { return (WCHAR*)(wtz+1); }

/* Returns a pointer to the text part of the string wt */
__inline WCHAR* MsoRgwchFromWt(const WCHAR* wt) { return (WCHAR*)(wt+1); }

/* Checks if wtz is a valid string */
#if VSMSODEBUG
	MSOAPIXX_(BOOL) MsoFValidWtz(const WCHAR* wtz);
#else
	#define MsoFValidWtz(wtz) (1)
#endif


/*************************************************************************
	String comparisons
*************************************************************************/

enum
{
	msocsExact = 0x4,	/* exact string matches required */

	msocsCase = 0x4,	/* case-sensitive comparisons */
	msocsIgnoreCase = 0x1,	/* case-insensitive comparisons */

	msocsDiacriticals = 0x4,	/* diacritical differences compare different */
	msocsIgnoreDiacriticals = 0x2,	/* diacriticals ignored */
	msocsIgnoreKana = 0x8,
	msocsIgnoreWidth = 0x10,
	msocsIgnoreNonSpace = 0x20
};

/* Test if the null-terminated strings sz1 and sz2 are the same. */
MSOAPI_(BOOL) MsoFSzEqual(const CHAR* sz1, const CHAR* sz2, int cs);

MSOAPI_(BOOL) MsoFWzEqual(const WCHAR* wz1, const WCHAR* wz2, int cs);

MSOAPI_(BOOL) MsoFWtzEqual(const WCHAR* wtz1, const WCHAR* wtz2, int cs);

/* Test if the two strings rgch1 (length cch1) and rgch2 (length cch2) are
	the same. */
MSOAPI_(BOOL) MsoFRgchEqual(const CHAR* rgch1, int cch1, const CHAR* rgch2, int cch2, int cs);

/*	Test if the two Unicode strings rgwch1 (length cch1) and rgwch2
	(length cch2) are the same. */
MSOAPI_(BOOL) MsoFRgwchEqual(const WCHAR* rgch1, int cch1, const WCHAR* rgch2, int cch2, int cs);

/* Compares the sort order of the two strings sz1 and sz2.  Returns
	-1 if sz1 < sz2, 0 if they sort equally, and +1 if sz1 > sz2. */
MSOAPI_(int) MsoSgnSzCompare(const CHAR* sz1, const CHAR* sz2, int cs);

MSOAPI_(int) MsoSgnWzCompare(const WCHAR* wz1, const WCHAR* wz2, int cs);

MSOAPI_(int) MsoSgnWtzCompare(const WCHAR* wtz1, const WCHAR* wtz2, int cs);

/* Compares the sort order of the two strings rgch1 (length cch1)
   and rgch2 (length cch2).  Returns -1 if rgch1 < rgch2, 0 if they
   sort equally, and +1 if rgch1 > rgch2. */
MSOAPI_(int) MsoSgnRgchCompare(const CHAR* rgch1, int cch1, const CHAR* rgch2, int cch2, int cs);

MSOAPI_(int) MsoSgnRgwchCompare(const WCHAR* rgch1, int cch1, const WCHAR* rgch2, int cch2, int cs);

/*	Compares the sort order of the two unicode strings rgwch1
	(# of chars cch1) and rgwch2 (# of chars cch2).  Returns -1 if
	rgwch1 < rgwch2, 0 if they sort equally, and +1 if rgwch1 > rgwch2.
	The string compare is based on locale - identified by the sort
	and language IDs. */
MSOAPIMX_(int) MsoSgnRgwchCompareLoc(const WCHAR* rgch1, int cch1, const WCHAR* rgch2, int cch2, int cs, WORD wLangId, WORD wSortId);


/*************************************************************************
	Substrings and searches
*************************************************************************/

/*	Finds the first occurance of the character ch in the null-terminated
	string sz, and returns a pointer to it.  Returns NULL if the character
	was not in the string. */
MSOAPI_(CHAR*) MsoSzIndex(const CHAR* sz, int ch);

/*	Finds the last (rightmost) occurance of the character ch in the null-terminated
	string sz, and returns a pointer to it.  Returns NULL if the character
	was not in the string. */
MSOAPI_(CHAR*) MsoSzIndexRight(const CHAR* sz, int ch);

/*  Finds the first occurance of one of szCharSet in the null-terminated
	string sz, and returns a pointer to it.  Returns NULL if none of the characters
	was not in the string.

	Does not work on DBCS */
MSOAPIX_(CHAR*) MsoSzIndexOneOf(const CHAR* sz, const CHAR *szCharSet);

MSOAPI_(WCHAR*) MsoWzIndexOneOf(const WCHAR* sz, const WCHAR *szCharSet);

/*	Finds the last (rightmost) occurance of the character wch in the null-terminated
	UNINCODE  string cwz, and returns a pointer to it.  Returns NULL if the character
	was not in the string. */
MSOAPI_(WCHAR*) MsoWzIndexRight(const WCHAR* cwz, int wch);

/*	Finds the last (rightmost) occurance of the character wch in the null-terminated
	UNINCODE  string cwz starting from char position cch, and returns a pointer to it.
	Returns NULL if the character was not in the string. */
MSOAPI_(WCHAR*) MsoCchWzIndexRight(const WCHAR* cwz, INT_PTR cch, int wch);

/* Replaces all occurances of wchOut with wchIn. */
MSOAPI_(void) MsoReplaceAllOfWchWithWch (WCHAR *wz, WCHAR wchOut, WCHAR wchIn);

/*	Just like MsoSzIndex, except the string is guaranteed to be full of
	single-byte ANSI characters (i.e., no DBCS characters) */
MSOAPIMX_(CHAR*) MsoSzIndex1(const CHAR* sz, int ch);

/*	Finds the first occurance of the character ch in the null-terminated
	string wz, and returns a pointer to it.  Returns NULL if the character
	was not in the string. */
MSOAPI_(WCHAR*) MsoWzIndex(const WCHAR* sz, int ch);

/* Finds the occurance of the substring szFind inside the string sz, and
	returns a pointer to the beginning of it. Returns NULL if the substring
	is not found */
MSOAPI_(CHAR*) MsoSzStrStr(const CHAR* sz, const CHAR* szFind);


/*	Finds the occurance of the substring szFind inside the string sz, and
	returns a pointer to the beginning of it. Returns NULL if the substring
	is not found

	This version pays attention to cs and does not require NULL termination. */
MSOAPI_(CHAR*) MsoPchStrStr(const CHAR* pch, int cch, const CHAR* szFind, int cs);

/*	Finds the occurance of the substring pwchFind inside the string pwch, and
	returns a pointer to the beginning of it. Returns NULL if the substring
	is not found. This version pays attention to cs and does not require NULL 
	termination. */
MSOAPIX_(WCHAR *) MsoPwchStrStr(const WCHAR *pwch, int cch, const WCHAR *pwchFind, int cchFind, int cs);
/*	Finds the occurance of the substring pwchFind inside the string pwch, and
	returns a pointer to the beginning of it. Returns NULL if the substring
	is not found */
MSOAPI_(WCHAR*) MsoPwchStrStrFast(const WCHAR *pwch, int cch, const WCHAR *pwchFind, int cchFind);
/*	Finds the last (rightmost) occurance of the substring pwchFind inside the 
	string pwch, and returns a pointer to the beginning of it. 
	Returns NULL if the substring is not found */
MSOAPI_(WCHAR*) MsoPwchStrStrRightFast(const WCHAR *pwch, int cch, const WCHAR *pwchFind, int cchFind);

/*	Finds the occurance of the substring wzFind inside the string wz, and
	returns a pointer to the beginning of it. Returns NULL if the substring
	is not found  */
MSOAPI_(WCHAR*) MsoWzStrStr(const WCHAR* wz, const WCHAR* wzFind);
/* Ex version lets you specify case sensitive vs. insensitive etc */
MSOAPI_(WCHAR*) MsoWzStrStrEx(const WCHAR* wz, const WCHAR* wzFind, int cs);
/* Ex version lets you specify cch in wzFind to match against, and case sensitive vs. insensitive etc */
MSOAPIX_(WCHAR*) MsoWzStrStrEx2(const WCHAR* wz, const WCHAR* wzFind, int cchFind, int cs);

/*	Given a pattern string with special token symbols in it, inserts
	other strings in place of the token, based on a variable argument
	list.  The token "|0" is replaced by the 0th variable arg, "|1" is
	replaced by the 1st variable arg, "|2" by the 2nd variable arg, etc.
	Especially useful for international error messages, where the order
	of inserted strings may change depending on the language.

	If the "|" character is not followed by a number, inserts the 0th
	variable arg.

	The pattern string is passed in in szPat, the result is stored in
	the buffer szOut, which is of length cchOut. */

#define __stdcall __cdecl
// MSOAPI_(int) MsoInsertSz(CHAR* szOut, int cchOut, const CHAR* szPat, const CHAR* sz0, ...);
// MSOMACPUB int __cdecl MsoInsertWtz(WCHAR* wtzOut, int cchOut, const WCHAR* wtzPat, const WCHAR* wtz0, ...);
// MSOAPI_(int) MsoInsertWz(WCHAR* wzOut, int cchOut, const WCHAR* wzPat, const WCHAR* wz0, ...);
// MSOAPIX_(int) MsoInsertIdsWtz(WCHAR* wtzOut, int cchOut, HINSTANCE hinst, int idsPat, const WCHAR* wtz0, ...);

#if defined(FRONTPAGE_BUILD) || defined(OFFICE_BUILD) || defined(LIME_BUILD)
MSOAPI_(int) MsoCchInsertSz    ( CHAR* szOut , int cchOut, const  CHAR* szPat , int iCount, ...);
#endif
MSOAPIX_(int) MsoCchInsertWtz   (WCHAR* wtzOut, int cchOut, const WCHAR* wtzPat, int iCount, ...);
MSOAPI_(int) MsoCchInsertWz    (WCHAR* wzOut , int cchOut, const WCHAR* wzPat , int iCount, ...);
MSOAPIX_(int) MsoCchInsertIdsWtz(WCHAR* wtzOut, int cchOut, HINSTANCE hinst, int idsPat, int iCount, ...);
MSOAPIX_(int) MsoCchInsertIdsWz (WCHAR* wtzOut, int cchOut, HINSTANCE hinst, int idsPat, int iCount, ...);

#undef __stdcall


/*************************************************************************
	Unicode and character set string conversions
*************************************************************************/

/* converts a wide unicode string szFrom into the system's native
	default character set in szTo */
MSOAPI_(int) MsoWzToSz(const WCHAR* wzFrom, CHAR* szTo);
MSOAPIX_(void) MsoWzToSzSimple(const WCHAR* wzFrom, CHAR* szTo);

MSOAPI_(int) MsoWtzToSz(const WCHAR* wtzFrom, CHAR* szTo);

/* Any particular reason we're missing MsoWtzToStz? */

/* converts a system's native character set string szFrom into a
	wide unicode string in szTo */
MSOAPIX_(int) MsoSzToWzCch(const char *szFrom, WCHAR *wzTo, int cchTo);
MSOAPI_(int) MsoSzToWz(const CHAR* szFrom, WCHAR* wzTo);
MSOAPIX_(void) MsoSzToWzSimple(const CHAR* szFrom, WCHAR* wzTo);
MSOAPI_(int) MsoCpSzToWz(UINT CodePage, const CHAR* szFrom, WCHAR* wzTo);
MSOAPIX_(WCHAR) MsoWchFromCpCh(UINT cp, const CHAR ch);

/*	Converts the unicode string wtz into the Ansi, allocated from the
	mark memory manager.  The string should be freed using MsoReleaseSz. */
//  REVIEW:  PETERO:  This comment is wrong, these APIs don't alloc from mark mem buffer...
MSOAPI_(int) MsoSzToWtz(const CHAR* szFrom, WCHAR* wtzTo);

MSOAPI_(int) MsoWtzToWz(const WCHAR* wtz, WCHAR* wz);

MSOAPI_(int) MsoWzToWtz(const WCHAR* wz, WCHAR* wtz);

/*	Converts the Unicode string in rgwchFrom into an Ansi string at
	rgchTo.  This API will work in-place.
	Returns FALSE if the target buffer is not large enough for the
	conversion.  Returns TRUE on success. */
MSOAPI_(BOOL) MsoFRgwchToRgch(const WCHAR* rgwchFrom, CHAR* rgchTo, int cbTo);

/* converts a wide unicode string in rgchFrom (length cchFrom) into the
	system's native default character set in rgchTo */
MSOAPI_(int) MsoRgwchToRgch(const WCHAR* rgchFrom, int cchFrom, CHAR* rgchTo, int cchTo);

/*	Converts a unicode string rgchFrom (with length cchFrom) into the
	equivalent string in the specified character set. If rgchTo
	is non-NULL, the converted string is stored there.  The length in
	bytes of the converted string is returned, even if rgchTo is NULL. */
MSOAPI_(int) MsoRgwchToCpRgch(UINT CodePage, const WCHAR* rgchFrom, int cchFrom, CHAR* rgchTo, int cchTo);
MSOAPIX_(int) MsoRgwchToCpRgchEx(UINT CodePage, const WCHAR* rgchFrom, int cchFrom, CHAR* rgchTo, int cchTo, BOOL *fDefault);

/*	Converts the Ansi string in rgchFrom with length cchFrom into a
	Unicode string at rgchTo.  The rgchTo buffer is assumed to be cchTo
	character slong.  Returns the length of the converted string.  This
	API will work in-place. */
MSOAPI_(int) MsoRgchToRgwch(const CHAR* rgchFrom, int cchFrom, WCHAR* rgchTo, int cchTo);

/*	Converts the MultiByte string of code page CodePage in rgchFrom with
	length cchFrom into a Unicode string at rgwchTo.  The rgwchTo buffer
	is assumed to be cchTo characters long.  Returns the length of the
	converted string.  This API will work in-place. */
MSOAPI_(int) MsoCpRgchToRgwch(UINT CodePage, const CHAR* rgchFrom, int cchFrom, WCHAR* rgwchTo, int cchTo);

/*	Converts the Ansi string in rgchFrom with length cchFrom into a
	Unicode string at rgwchTo.  This API will work in-place.
	Returns FALSE if the target buffer is not large enough for the
	conversion.  Returns TRUE on success. */
MSOAPI_(BOOL) MsoFRgchToRgwch(const CHAR* rgchFrom, WCHAR* rgwchTo, int cchTo);

/* converts a system's native character set string rgchFrom (with
	length cchFrom) into a wide unicode string in rgchTo */
#ifdef VSMSODEBUG
#define MsoSzMarkWtz(wtz) MsoSzMarkWtzCore(wtz, __FILE__, __LINE__)
MSOAPIX_(CHAR*) MsoSzMarkWtzCore(const WCHAR* wtz, const CHAR* szFile, int line);
#else
#define MsoSzMarkWtz(wtz) MsoSzMarkWtzCore(wtz)
MSOAPIX_(CHAR*) MsoSzMarkWtzCore(const WCHAR* wtz);
#endif

/*	Converts the unicode string wz into the Ansi, allocated from the
	mark memory manager.  The string should be freed using MsoReleaseSz. */
#ifdef VSMSODEBUG
#define MsoSzMarkWz(wz) MsoSzMarkWzCore(wz, __FILE__, __LINE__)
MSOAPI_(CHAR*) MsoSzMarkWzCore(const WCHAR* wz, const CHAR* szFile, int line);
#else
#define MsoSzMarkWz(wz) MsoSzMarkWzCore(wz)
MSOAPI_(CHAR*) MsoSzMarkWzCore(const WCHAR* wz);
#endif

/*	Converts the unicode string rgwch of length cch into the Ansi,
	allocated from the mark memory manager.  The actual length of
	the Ansi text is returned at *pcch. */
#ifdef VSMSODEBUG
#define MsoRgchMarkRgwch(pcch, rgwch, cch) MsoRgchMarkRgwchCore(pcch, rgwch, cch, __FILE__, __LINE__)
MSOAPIX_(CHAR*) MsoRgchMarkRgwchCore(int* pcch, const WCHAR* rgwch, int cch, const CHAR* szFile, int line);
#else
#define MsoRgchMarkRgwch(pcch, rgwch, cch) MsoRgchMarkRgwchCore(pcch, rgwch, cch)
MSOAPIX_(CHAR*) MsoRgchMarkRgwchCore(int* pcch, const WCHAR* rgwch, int cch);
#endif

/*	Releases the string sz allocated by MsoSzMarkWtz, MsoSzMarkWz, et.al. */
#define MsoReleaseSz(sz) MsoReleaseMem(sz)

/*	Translates an ANSI (single/double byte character set) character string
	sz in the system default codepage into a Unicode string.  The unicode
	string is allocated out of the mark/release memory heap. */
#ifdef VSMSODEBUG
#define MsoWzMarkSz(sz) MsoWzMarkSzCore(sz, __FILE__, __LINE__)
MSOAPI_(WCHAR*) MsoWzMarkSzCore(const CHAR* sz, const CHAR* szFile, int line);
#else
#define MsoWzMarkSz(sz) MsoWzMarkSzCore(sz)
MSOAPI_(WCHAR*) MsoWzMarkSzCore(const CHAR* sz);
#endif

/*	Translates an ANSI (single byte character set, all chars < 128) character
	string sz in the system default codepage into a Unicode string.  The
	unicode string is allocated out of the mark/release memory heap.
					THIS IS NOT FOR DBCS!!!!     */
#ifdef VSMSODEBUG
#define MsoWzMarkSzSimple(sz) MsoWzMarkSzSimpleCore(sz, __FILE__, __LINE__)
MSOAPIX_(WCHAR*) MsoWzMarkSzSimpleCore(const CHAR* sz, const CHAR* szFile, int line);
#else
#define MsoWzMarkSzSimple(sz) MsoWzMarkSzSimpleCore(sz)
MSOAPIX_(WCHAR*) MsoWzMarkSzSimpleCore(const CHAR* sz);
#endif


/*	Translates an ANSI (single/double byte character set) character string
	sz in the system default codepage into a length-word preceeded Unicode
	string.  The Unicode string is allocated out of the mark/release memory
	heap. */
#ifdef VSMSODEBUG
#define MsoWtzMarkSz(sz) MsoWtzMarkSzCore(sz, __FILE__, __LINE__)
MSOAPIX_(WCHAR*) MsoWtzMarkSzCore(const CHAR* sz, const CHAR* szFile, int line);
#else
#define MsoWtzMarkSz(sz) MsoWtzMarkSzCore(sz)
MSOAPIX_(WCHAR*) MsoWtzMarkSzCore(const CHAR* sz);
#endif

/*	Releases a Unicode string allocated by MsoWzMarkSz or MsoWtzMarkSz. */
#define MsoReleaseWz(wz) MsoReleaseMem(wz)

/*	conversion routines for OLECHAR to WCHAR - note that if an OLECHAR and
	a WCHAR are the same thing, these routines to nothing */
	#define MsoOzMarkWz(wz) ((OLECHAR*)(wz))
	#define MsoReleaseOzWz(oz)
	#define MsoWzMarkOz(oz) ((WCHAR*)(oz))
	#define MsoReleaseWzOz(wz)

/*	Converts a group of ANSI strings into a group of Unicode strings.
    Each string in the group is terminated by a null.  Returns
	resulting length of the Unicode string stored in wzTo as a cch */
MSOAPIMX_(int) MsoGrszToGrwz(const CHAR* szFrom, WCHAR* wzTo, int cchTo);

/*	Converts a group of Unicode strings into a group of ANSI strings.
    Each string in the group is terminated by a null.  Returns
	resulting length of the ANSI string stored in szTo as a cch */
MSOAPIX_(int) MsoGrwzToGrsz(const WCHAR* wzFrom, CHAR* szTo);


/*************************************************************************
	Miscellaneous string utilities
*************************************************************************/

/*	Decodes the unsigned integer u into ASCII text in base wBase.  The
	string is stored in the rgch buffer, which is assumed to be large
	enough to hold the number's text and a null terminator.  Returns
	the length of the text decoded. */
MSOAPI_(int) MsoSzDecodeUint(CHAR* rgch, unsigned u, int wBase);

/*	Decodes the unsigned u into Unicode text in base wBase.  The string is
	stored in the rgwch buffer, which is assumed to be large enough to
	hold the number's text and a null terminator.  Returns the length
	of the text decoded. */
MSOAPI_(int) MsoWzDecodeUint(WCHAR* rgwch, unsigned u, int wBase);

/*	Decodes the integer w into Unicode text in base wBase.  The string is
	stored in the rgwch buffer, which is assumed to be large enough to
	hold the number's text and a null terminator.  Returns the length
	of the text decoded. */
MSOAPI_(int) MsoWzDecodeInt(WCHAR* rgwch, int w, int wBase);

/*	Decodes the signed integer w into ASCII text in base wBase.  The
	string is stored in the rgch buffer, which is assumed to be large
	enough to hold the number's text and a null terminator.  Returns
	the length of the text decoded. */
MSOAPI_(int) MsoSzDecodeInt(CHAR* rgch, int w, int wBase);

/*	Decodes the double number w into ASCII text*/
MSOAPI_(CHAR *) MsoSzDecodeDouble(double w,int count,int *dec,int *sign);

/*  Decodes the double d into Unicode text.  The string is stored in
	the rgwch buffer, which is assumed to be large enough to hold
	the number's text and a null terminator.  Returns the length of
	the text decoded. */
MSOAPI_(int) MsoWzDecodeDouble(WCHAR* rgwch, double d);

/*  Decodes the SystemTime st into Unicode text, in ISO8061 format.
	The string is stored in the rgwch buffer, which is assumed to
	be large enough to hold the time's text and a null terminator.
	Returns the length of the text decoded. */
MSOAPI_(int) MsoWzDecodeTime(WCHAR* rgwch, const SYSTEMTIME *pst);

/* Parses the Unicode text at rgwch into *pw. Returns the count of
   characters considered part of the number. Continues reading characters
   and encoding them into *pw until it encounters a non-digit.   
   Handles overflow by returning zero.*/
#if !STATIC_LIB_DEF
MSOAPI_(int) MsoParseInt64Wz(const WCHAR* rgwch, __int64 *pw);
#endif

/* Parses the Unicode text at rgwch into *pw. Returns the count of
   characters considered part of the number.
   Returns 0 on overflow */
MSOAPI_(int) MsoParseIntWz(const WCHAR* rgwch, int *pw);
// Temporary name mapping -- we'll remove this API soon
#define MsoIntEncodeWz MsoParseIntWz

/* Parses the Unicode text at rgwch into *pw. Returns the count of
   characters considered part of the number.
   Returns 0 on overflow */
MSOAPI_(int) MsoParseUIntWz(const WCHAR* rgwch, unsigned *pw);

/*	Parses the Ansi text at rgch into *pw. Returns the count of
   characters considered part of the number. Continues reading
   characters and encoding them into *pw until it encounters a
   non-digit.  Returns 0 on overflow */
MSOAPI_(int) MsoParseIntSz(const CHAR* rgch, int *pw);

/*	Parses the Ansi text at rgch into *pw. Returns the count of
   characters considered part of the number. Continues reading
   characters and encoding them into *pw until it encounters a
   non-digit.  Returns 0 on overflow */
MSOAPI_(int) MsoParseUIntSz(const CHAR* rgch, unsigned *pw);

// Temporary name mapping -- we'll remove this API soon
#define MsoIntEncodeSz MsoParseIntSz

MSOAPI_(int) MsoParseHexIntWz(const WCHAR *wz, int *pw);
MSOAPIX_(int) MsoParseHexIntSz(const CHAR  *sz, int *pw);

/* Parses the Unicode text at rgwch into *pw. Returns the count of
   characters considered part of the number.
   Returns 0 on overflow */
MSOAPI_(int) MsoParseHexUIntWz(const WCHAR *wz, unsigned *pw);

/*  Parses the Unicode text at rgwch into *pd.  Returns the count of
	characters considered part of the number. */
MSOAPI_(int) MsoParseDoubleWz(const WCHAR* rgwch, double *pd);

/*  Parses the Unicode text at rgwch into *pst.  Expects time in
	ISO8061 format.  Returns time in Z-time, not local time.
	Returns 0 if time fails to conform to format required.  */
MSOAPI_(int) MsoParseTimeWz(const WCHAR* rgwch, SYSTEMTIME *pst);

/*	Converts the pascal-type string st into a null-terminated string sz.
	Returns length of the string, excluding the trailing null.  This API
	will work if sz == st */
MSOAPI_(int) MsoStToSz(const BYTE* st, CHAR* sz);

/*	Converts a C-style null-terminated string sz into a pascal-type
	string st.  Returns the length of the string.  This routine will
	work if sz == st. */
MSOAPI_(int) MsoSzToSt(const CHAR* sz, BYTE* st);

/*	Expands MSO-environment strings and replaces them with their defined
	values.  Subsequently calls the system API to expand and replace any
	remaining environment-variable strings. */
MSOAPI_(DWORD) MsoExpandEnvironmentStrings(LPCWSTR lpSrc, LPWSTR lpDest, DWORD cchDest);

/*	Converts a string representation of a GUID to an actual GUID. */
MSOAPI_(BOOL) MsoFGuidFromWz(WCHAR *wz, GUID *pguid);


/*************************************************************************
	String table resources
*************************************************************************/

/* String identifiers and their associated pieces */

#define MsoIdsFromSttIdsl(stt,idsl) ((long)MAKELONG(idsl,stt))
#define MsoIdslFromIds(ids) LOWORD(ids)
#define MsoSttFromIds(ids) HIWORD(ids)

#define msoidslNil 0xFFFFU
#define msosttNil  0xFFFFU
#define msoidsNil MsoIdsFromSttIdsl(msosttNil,msoidslNil)


/* The string table resource format */

enum
{
	msotstNil = 0,	/* invalid string table type */
	msotstAllocated = 0,	/* allocated index table type */
	msotstFixed = 1,	/* fixed index table type */
	msotstNoCompress = 2,	/* no compression */
	msotstSlow = 4,	/* slow reverse lookups */
	msotstFast = 8,	/* fast O(ln n) reverse lookups */
	msotstCaseSensitive = 16,	/* case sensitive reverse lookups */
	msotstSimple = 32,	/* simple (no index) tables */
	msotstCompress = 64, /* simple compress if SBCS charset, no 2nd byte */
	msotstHuffCompress = 128 /* huffman and substring compression */
};

typedef struct MSOFLOM
{
	WORD idsl;	/* string index */
	WORD bwt;	/* offset to beginning of string */
} MSOFLOM;

typedef struct MSOSTT
{
	WORD tst;	/* type of string table */
	WORD lang;	/* NLS language ID */
	WORD sort;	/* NLS sorting ID */
	union
		{
		struct	/* tstAllocated */
			{
			WORD idslMac;	/* number of strings */
			WORD mpidslbwt[1];	/* idslMac entries */
			};
		struct	/* tstFixed */
			{
			WORD cflom;	/* number of strings */
			MSOFLOM rgflom[1];	/* cflom entries */
			};
		};
	/* for tstFast, there is a rgflomSorted array here */
	/* the actual grwt data follows */
} MSOSTT;


// Huffman Table Resource format
typedef struct MSODSTE
{   // Decode State Table Entry
	WORD mpbidste[2];
	WCHAR rgwchKey[4];
} MSODSTE;

#define msobwtNil 0xFFFFU

#define __stdcall __cdecl

/* Loads a non-OSTRMAN string with id ids from the resource file 
	specified by hinst.  result is left in wz, which is a buffer big 
	enough to hold of cch Unicode characters.  Returns # of chars 
	if successful. */
MSOAPIX_(int) MsoCchStdLoadWz(HINSTANCE hinst, int ids, WCHAR* wz, int cch);

#undef __stdcall

/*	Loads a string with id ids from the resource file specified by hinst.
	result is left in wtz, which is a buffer big enough to hold of cch
	Unicode characters.  Returns TRUE if successful */
MSOAPI_(BOOL) MsoFLoadWtz(HINSTANCE hinst, int ids, WCHAR* wtz, int cch);

/*	Loads a string with id ids from the resource file specified by hinst.
	result is left in wz, which is a buffer big enough to hold of cch
	Unicode characters.  Returns TRUE if successful */
MSOAPI_(BOOL) MsoFLoadWz(HINSTANCE hinst, int ids, WCHAR* wz, int cch);
MSOAPI_(BOOL) MsoFLoadOsaWz(int idsl, WCHAR* wz, int cch);
MSOAPI_(BOOL) MsoFLoadVseWz(int idsl, WCHAR* wz, int cch);

/*	Loads a string with id ids from the resource file specified by hinst.
	result is left in wz, which is a buffer big enough to hold of cch
	Unicode characters.  Returns TRUE if successful */
MSOAPI_(BOOL) MsoFLoadWzFromPstt(HINSTANCE hinst, MSOSTT *pstt, int ids, WCHAR* wz, int cch);

/*	Loads a string with id ids from the resource file specified by hinst.
	result is left in wz, which is a buffer big enough to hold of cch
	Unicode characters.  Returns # of chars if successful */
MSOAPIXX_(int) MsoCchLoadWzFromPstt(HINSTANCE hinst, MSOSTT *pstt, int ids, WCHAR* wz, int cch);

/*	Loads a string with id ids from the resource file specified by hinst.
	result is left in wz, which is a buffer big enough to hold of cch
	Unicode characters.  Returns # of chars if successful */
MSOAPI_(int) MsoCchLoadWz(HINSTANCE hinst, int ids, WCHAR* wz, int cch);

/*	Loads a string with id ids from the resource file specified by hinst.
	result is left in rgch, which is a buffer of length cch.  Returns length
	of the string if found, FALSE if not.  The returned string is
	guaranteed to be null-terminated */
MSOAPI_(int) MsoCchLoadSz(HINSTANCE hinst, int ids, CHAR* rgch, int cch);

/*	Loads a string with id ids from the resource file specified by hinst.
	result is left in rgch, which is a buffer of length cch.  Returns the
	actual length of the string.  The returned string is guaranteed to be
	null-terminated */
MSOAPI_(BOOL) MsoFLoadSz(HINSTANCE hinst, int ids, CHAR* sz, int cch);
MSOAPI_(BOOL) MsoFLoadOsaSz(int idsl, CHAR* rgch, int cch);

/*	Loads a string with id ids from the resource file specified by hinst.
	result is left in rgch, which is a buffer of length cch.  Returns TRUE
	if the string was found.  The returned string is guaranteed to be
	null-terminated. Takes required output code page as a param. */
MSOAPI_(BOOL) MsoFLoadCpSz(HINSTANCE hinst, int ids, CHAR* rgch, int cch, UINT CodePage);

#ifdef WORD_BUILD
/*	Loads a string with id ids from the resource file specified by hinst.
	result is left in stz, which should be a buffer big enough to hold the
	biggest possible string, usually 258 bytes.  Returns TRUE if successful.
	The returned string is guaranteed to be null-terminated.
	Takes required output code page as a param. */
MSOAPI_(BOOL) MsoFLoadCpStz(HINSTANCE hinst, int ids, BYTE* stz, UINT CodePage);
#endif

/*	Loads a string with id ids from the resource file specified by hinst.
	Converts the string to an integer and stores the integer in *pint.
	Returns fSuccess. */
MSOAPIX_(BOOL) MsoFLoadInt(HINSTANCE hinst, int ids, int *pi);

/*	Searches for a string sz in the given string table stt, loaded from
	the resource file hinst.  Returns the idsl of the string if found,
	or msoidslNil if not found */
MSOAPI_(int) MsoLookupSz(HINSTANCE hinst, WORD stt, const CHAR* sz);

#ifdef WORD_BUILD
/*	Searches for a string st in the given string table stt, loaded from
	the resource file hinst.  Returns the idsl of the string if found,
	or msoidslNil if not found */
MSOAPI_(int) MsoLookupSt(HINSTANCE hinst, WORD stt, const BYTE* st);
#endif

/*	Searches for a string wz in the given string table stt, loaded from
	the resource file hinst.  Returns the idsl of the string if found,
	or msoidslNil if not found  */
MSOAPI_(int) MsoLookupWz(HINSTANCE hinst, WORD stt, const WCHAR* wz);

/*	Searches for a string wtz in the given string table stt, loaded from
	the resource file hinst.  Returns the idsl of the string if found,
	or msoidslNil if not found  */
MSOAPI_(int) MsoLookupWtz(HINSTANCE hinst, WORD stt, const WCHAR* wtz);

/*	Finds the number of strings in the string table hinst/stt. */
MSOAPI_(int) MsoIdslMacFromStt(HINSTANCE hinst, WORD stt);

/*	Loads a string table stt in the dll instance hinst and returns a
	pointer to the stt (NULL on error). This API should be used in
	conjunction with the MsoGetWtzFromPstt API to load a large number
	of strings from the same stt. */
MSOAPI_(MSOSTT*) MsoLoadPstt(HINSTANCE hinst, WORD stt);

/*	Loads a string with id ids from a string table whose ptr is passed in.
	The ptr is obtained from an earlier call to MsoLoadPstt. Returns
	TRUE on success or FALSE on error. */
MSOAPI_(BOOL) MsoFLoadWtzFromPstt(HINSTANCE hinst, MSOSTT *pstt, int ids, WCHAR* wtz, int cch);

/*	Loads a string with id ids from a string table whose ptr is passed in.
	The ptr is obtained from an earlier call to MsoLoadPstt. Returns
	length of string on success or FALSE on error. */
MSOAPIX_(int) MsoCchLoadSzFromPstt(HINSTANCE hinst, MSOSTT *pstt, int ids, CHAR* rgch, int cch);

/*	Loads a string with id ids from a string table whose ptr is passed in.
	The ptr is obtained from an earlier call to MsoLoadPstt. Returns
	TRUE on success or FALSE on error. */
MSOAPIX_(BOOL) MsoFLoadSzFromPstt(HINSTANCE hinst, MSOSTT *pstt, int ids, CHAR* rgch, int cch);

/*	Loads a string with id ids from a string table whose ptr is passed in.
	The ptr is obtained from an earlier call to MsoLoadPstt. Returns
	TRUE on success or FALSE on error. Takes code page as param. */
MSOAPIXX_(int) MsoCchCpLoadSzFromPstt(HINSTANCE hinst, MSOSTT *pstt, int ids, CHAR* rgch, int cch, UINT CodePage);

/*	Loads a string with id ids from a string table whose ptr is passed in.
	Result is left in stz, which should be a buffer big enough to hold the
	biggest possible string, usually 258 bytes.  Returns TRUE if successful.
	The returned string is guaranteed to be null-terminated */
MSOAPIMX_(BOOL) MsoFLoadStzFromPstt(HINSTANCE hinst, MSOSTT *pstt, int ids, BYTE *stz);

/*	Searches for a string wtz in the given string table pstt, loaded from
	the resource file hinst.  Returns the idsl of the string if found,
	or msoidslNil if not found */
MSOAPIXX_(int) MsoLookupWtzFromPstt(HINSTANCE hinst, MSOSTT *pstt, const WCHAR* wtz);

/*	Searches for a string wz in the given string table pstt, loaded from
	the resource file hinst.  Returns the idsl of the string if found,
	or msoidslNil if not found */
MSOAPIXX_(int) MsoLookupWzFromPstt(HINSTANCE hinst, MSOSTT *pstt, const WCHAR* wz);

/*	Searches for the string rgwch of length cch in the in-memory resource
	pstt.  Returns the index of the string within the string table, if
	found, or msoidslNil if not found. */
MSOAPIXX_(int) MsoLookupPsttRgwch(HINSTANCE hinst, const MSOSTT* pstt, int cch, const WCHAR* rgwch);

/*	Finds the number of strings in the string table hinst/pstt. */
MSOAPIX_(int) MsoIdslMacFromPstt(HINSTANCE hinst, MSOSTT *pstt);

/*	Unloads a string table pointed to by pstt - ptr obtained by earlier
	call to MsoLoadPstt. Returns TRUE if resource freed ok, else returns
	FALSE - either because invalid ptr, resource couldn't be unlocked, or
	resource couldn't be freed. */
MSOAPIX_(BOOL) MsoFUnloadPstt(MSOSTT *pstt);

MSOAPIX_(CHAR*) MsoMarkLoadStz(HINSTANCE hinst, int ids);
MSOAPIX_(WCHAR*) MsoMarkLoadWtz(HINSTANCE hinst, int ids);

#define msoStrip	0x0001
#define msoCaps	0x0002
/*	This function performs upper case conversion for a given
	Unicode character given its language id.
	Returns the input Unicode character if no conversion is found.
	Currently works only for the 5 Win and 5 Mac code pages needed for the
	Pan European version of the apps.
	wflags has the following bits that are currently used -
	msoStrip if you want to strip all the accents */
MSOAPI_(WCHAR) MsoWchToUpperLid(WCHAR wch, LID lid, WORD wflags);

/*	This function performs upper case conversion for a given
	Unicode character. It is invariant with respect to lcids and
	must be kept this way because word needs an invariant upper casing. */
MSOAPI_(WCHAR) MsoWchToUpperInvariant(WCHAR wch);

/* This function performs upper case conversion for a given
	Unicode character. Returns the input Unicode character if no
	conversion is found. Currently works only for the 10 code pages
	needed for Pan European version of the apps. */
MSOAPI_(WCHAR) MsoWchToUpper(WCHAR wch);

/*	This function strips the accent of WinLatin1 and Greek characters.
	Please note that European Latin, Extended Latin, and Cyrillic
	characters are unaffected. */
MSOAPI_(WCHAR) MsoWchStripAccent(WCHAR wch);

/*	This function performs lower case conversion for a given
	Unicode character given its language id.
	Currently works only for the 5 Win and 5 Mac code pages needed for the
	Pan European version of the apps.
	The wflags param is unused currently. */
MSOAPI_(WCHAR) MsoWchToLowerLid(WCHAR wch, LID lid, WORD wflags);

/* This function performs lower case conversion for a given
	Unicode character. Returns the input Unicode character if no
	conversion is found. Currently works only for the 10 code pages
	needed for Pan European version of the apps. */
MSOAPI_(WCHAR) MsoWchToLower(WCHAR wch);

/*	This function performs upper case conversion for a given wz.
	Note:  If the input string size exceeds cchMaxSz then it is truncated*/
MSOAPI_(void) MsoWzUpper(WCHAR * wz);


/*	This function performs lower case conversion for a given wz.
	Note:  If the input string size exceeds cchMaxSz then it is truncated*/
MSOAPI_(void) MsoWzLower(WCHAR *wz);

#ifdef OFFICE_BUILD
/*	This function performs upper case conversion for a given sz.
	Note:  If the input string size exceeds cchMaxSz then it is truncated */
MSOAPIX_(void) MsoSzUpper(CHAR *sz);

/* This function performs lower case conversion for a given sz.
	Note:  If the input string size exceeds cchMaxSz then it is truncated */
MSOAPIX_(void) MsoSzLower(CHAR *sz);
#endif

MSOAPIX_(int) UTF8ToUnicode(LPCSTR lpSrcStr, int *cchSrc, LPWSTR lpDestStr,
	int cchDest);
MSOAPI_(int) UnicodeToUTF8(LPCWSTR lpSrcStr, int cchSrc, LPSTR lpDestStr,
	int cchDest);

/*	This function provides our own layer to MultiByteToWideChar() call.  We
	provide our own lookup table if it's not available from NLS subsystem.
	Currently works for 20 SBCS Win and 5 Mac code pages. */
MSOAPI_(int) MsoMultiByteToWideChar(UINT CodePage, DWORD dwFlags,
		LPCSTR lpMultiByteStr, INT_PTR cchMultiByte, LPWSTR lpWideCharStr,
		int cchWideChar);

/*	This function provides our own layer to MultiByteToWideChar() call.  We
	provide our own lookup table if it's not available from NLS subsystem.
	Currently works for 20 SBCS Win and 5 Mac code pages. */
MSOAPI_(int) MsoWideCharToMultiByte(UINT CodePage,
		DWORD dwFlags, LPCWSTR lpWideCharStr, int cchWideChar,
		LPSTR lpMultiByteStr, INT_PTR cchMultiByte, LPCSTR lpDefaultChar,
		LPBOOL lpUsedDefaultChar);

/*	This function provides our own layer to GetStringTypeExW() call. */
MSOAPI_(BOOL) MsoGetStringTypeExW(LCID Locale,
								  DWORD dwInfoType,
								  LPCWSTR lpSrcStr,
								  int cchSrc,
								  LPWORD lpCharType);

#ifdef OFFICE_BUILD
// Returns whether a given Unicode string can be losslessly converted into the given codepage.
MSOAPIX_(BOOL) MsoFExpressibleWzInCodePage (const WCHAR *wz, int cpg);
#endif

/* The next 2 apis are from Office 95.  The latter is only used by Word. */
/* Checks if ch is a DBCS lead byte. */

MSOAPIX_(BOOL) FDbcsFirstByte(unsigned char ch);

// All ctypes of all acceptable languages should
// be defined here.
#define ctypeNone 0

// This must be the same as in langspec.h !!!
#define ctypeSpace 1
#define ctypeAlnum 2
#define ctypeSBKatakana 3
#define ctypeSymbol 4
#define ctypeDBSpace 5
#define ctypeDBHiragana 6
#define ctypeDBKatakana 7
#define ctypeDBEKana 8
#define ctypeDBAlnum 9
#define ctypeDBKanji 10
#define ctypeDBSymbol 11
#define ctypeDBHangeul 12
#define ctypeDBHangeulJamo 13
#define ctypeDBHanja 14
#define ctypeDBEUDC 15
#define ctypeDBGreek 16
#define ctypeDBJapanese 17
#define ctypeDBRussian 18
#define ctypeDBHebrew 19
#define ctypeDBArabic 20
#define ctypeDBDevanagari 21
#define ctypeDBOriya 22
#define ctypeDBTamil 23
#define ctypeDBThai 24

// Classes of characters
#define classNone 0
#define classSpace 1
#define classTerminal 2
#define classNT 3
#define classTNT 4

// Possible trigger values
#define itrigger0 0
#define itrigger1 1
#define itrigger2 2
#define itrigger3 3
#define itrigger4 4
#define itrigger5 5
#define itrigger6 6
#define itrigger7 7

MSOAPI_(int) MsoIOFCTriggerFromXchXch(int xch1, int xch2);

#define wchUnicodeBig    0xFFFE
#define wchUnicodeLittle 0xFEFF
#define lUTF8BOM         0xBFBBEFL
#define lUTF8BOMMask     0xFFFFFFL

/* Office's (actually Word's and maintained by them) implementation of DrawTextW */
MSOAPI_(int) MsoDrawTextW(HDC hdc, LPCWSTR lpwchText, int cchText, RECT FAR *lprc, UINT format);
MSOAPI_(int) MsoDrawTextExW(HDC hdc, LPCWSTR lpwchText, int cchText,
							LPRECT lprc, DWORD dwDTformat,
							LPDRAWTEXTPARAMS lpDTparams);

/*	Compares the sort order of the two unicode strings rgwch1
	(# of chars cch1) and rgwch2 (# of chars cch2).  Returns negative if
	rgwch1 < rgwch2, 0 if they sort equally, and positive if rgwch1 > rgwch2.
	The string compare is based on Unicode order.  MsoWchToUpper is used
	as an invariant ToUpper.  It must behave the same no matter which language
	we run on. */
MSOAPI_(int) MsoSgnRgwchCompareInvariant(const WCHAR *rgwch1, int cch1, const WCHAR *rgwch2, int cch2, int cs);

/* Compares two 7-bit ASCII only strings case insensitively.  Does so
   without doing a unicode conversion and without requiring the language
   Dll.
 */
MSOAPIX_(BOOL) MsoFRgchIEqualFast(const char *rgch1, const char *rgch2, int cch);
/*-----------------------------------------------------------------------------
	MsoFRgwchIEqualFast

	cheap rgch compare, wz1 must be a unicode string of lower case 
	7-bit chars (0-127)
-------------------------------------------------------------------- HAILIU -*/
MSOAPIX_(BOOL) MsoFRgwchIEqualFast(LPCWSTR rgwch1, LPCWSTR rgwch2, int cch);
MSOAPI_(BOOL) MsoFSzIEqualFast(const char *rgch1, const char *rgch2);
MSOAPI_(BOOL) MsoFLowAsciiRgch(LPSTR sz, int cch);
MSOAPI_(BOOL) MsoFLowAsciiRgwch(LPWSTR wz, int cch);
MSOAPI_(INT) MsoCchRgchToRgwchLowAscii(LPSTR pch, LPWSTR pwch, INT cch);
MSOAPI_(INT) MsoCchRgwchToRgchLowAscii(LPWSTR pwch, LPSTR pch, INT cch);


#if defined(__cplusplus)
}
#endif

MSOAPI_(BOOL) MsoFMarkWzToWtz(WCHAR *wz, WCHAR **pwtz);

//  Wrappers for standard libc routines
#ifndef NO_LIBC_INLINE
#if defined(OFFICE_BUILD) || defined(WORD_BUILD) || defined(EXCEL_BUILD) || defined(ACCESS_BUILD) || defined(PPT_BUILD)
__inline wchar_t * __cdecl wcscat(wchar_t *wzTo, const wchar_t *wzFrom)
{
	MsoWzAppend(wzFrom, wzTo);
	return wzTo;
}

__inline wchar_t * __cdecl wcschr(const wchar_t *string, wint_t c)
{
	return MsoWzIndex(string,c);
}

#ifndef GDIPSTAT
__inline int __cdecl wcscmp(const wchar_t *wz1, const wchar_t *wz2)
{
	return MsoSgnWzCompare(wz1, wz2, msocsCase);
}
#endif // GDIPSTAT

__inline wchar_t * __cdecl wcscpy(wchar_t *wzTo, const wchar_t *wzFrom)
{
	MsoWzCopy(wzFrom, wzTo);
	return wzTo;
}

__inline size_t __cdecl wcscspn(const wchar_t *string,const wchar_t *charset)
{
	WCHAR *wz = MsoWzIndexOneOf(string,charset);

	if (wz)
		return (wz-string);
	else
		return MsoCchWzLen(string);
}

#ifdef NOTYET
__inline size_t __cdecl wcslen(const wchar_t *string)
{
	return MsoCchWzLen(string);
}
#endif

__inline wchar_t * __cdecl wcsncat(wchar_t *wzTo, const wchar_t *wzFrom, size_t count)
{
    MsoWzCchCopy(wzFrom, wzTo + MsoCchWzLen(wzTo), (int)(count+1));
    return wzTo;
}

__inline int __cdecl wcsncmp(const wchar_t *string1, const wchar_t *string2, size_t size)
{
	return MsoSgnRgwchCompare(string1, min(MsoCchWzLen(string1) + 1, size), 
							  string2, min(MsoCchWzLen(string2) + 1, size), 
							  msocsCase);
}

#ifndef STATIC_LIB_DEF
__inline wchar_t * __cdecl wcsncpy(wchar_t *destination,const wchar_t *source,size_t count)
{
	MsoWzCchCopy(source,destination,(int)count);
//  NOTE:  Adds terminating 0 on truncation and does not 0 fill.  This is different than CRT spec.
    return destination;
}
#endif

__inline wchar_t * __cdecl wcsrchr(const wchar_t *string,wint_t c)
{
	return MsoWzIndexRight(string,c);
}

__inline wchar_t * __cdecl wcsstr(const wchar_t *string,const wchar_t *charset)
{
	return MsoWzStrStr(string,charset);
}

__inline int __cdecl _wcsicmp(const wchar_t *string1,const wchar_t *string2)
{
	return MsoSgnWzCompare(string1,string2,msocsIgnoreCase);
}

__inline int __cdecl _wcsnicmp(const wchar_t *string1,const wchar_t *string2,size_t size)
{
	return MsoSgnRgwchCompare(string1, min(MsoCchWzLen(string1) + 1, size), 
							  string2, min(MsoCchWzLen(string2) + 1, size),
							  msocsIgnoreCase);
}

#ifndef OFFICE_BUILD
__inline char * __cdecl _ecvt(double value,int count,int *dec,int *sign)
{
    return MsoSzDecodeDouble(value,count,dec,sign);
}
#endif

__inline char * __cdecl _fcvt(double value,int count,int *dec,int *sign)
{
    return MsoSzDecodeDouble(value,count,dec,sign);
}

#ifndef ZENSTAT_LIB_DEF
__inline char * __cdecl _gcvt(double value, int digits, char *buffer)
{
    int nDumb;
    MsoSzCopy(MsoSzDecodeDouble(value, digits,&nDumb,&nDumb),buffer);
    return buffer;
}
#endif //ZENSTAT_LIB_DEF

__inline char * __cdecl strchr(const char *string,int c)
{
	return MsoSzIndex(string,c);
}

__inline int __cdecl strcmpi(const char *string1,const char *string2)
{
	return MsoSgnSzCompare(string1,string2,msocsIgnoreCase);
}

__inline int __cdecl strncmp(const char *string1,const char *string2,size_t size)
{ 
	return MsoSgnRgchCompare(string1, min(MsoCchSzLen(string1) + 1, size), 
							 string2, min(MsoCchSzLen(string2) + 1, size), 
							 msocsCase);
}

#ifndef OFFICE_BUILD
__inline char * __cdecl strncpy(char *destination,const char *source,size_t count)
{
	MsoSzCchCopy(source,destination,(int)count);
    return destination;
}
#endif


/*memmovX86(pDst, pSrc, cnt)
	copy buffer making sure not to clobber overlap if any*/
#if defined(_M_IX86)
__inline void __cdecl memmovX86(void * pDst, const void * pSrc, size_t cb)
{
	__asm {
		mov		ecx,cb
		mov		edi,pDst
		mov		esi,pSrc
		mov		eax,edi
		sub		eax,esi
		 jz		_mmov_done		//return if src == dst
		push		ecx
		cmp		eax,ecx
		 jb		_mmov_bkwrds
		shr		ecx,2
		rep		movsd
		jmp		_mmov_crumbs

_mmov_bkwrds:
		lea		esi,[esi+ecx-4]
		lea		edi,[edi+ecx-4]
		std
		shr		ecx,2
		rep		movsd
		add		esi,3
		add		edi,3
_mmov_crumbs:
		pop		ecx
		and		ecx,3
		rep		movsb
		cld
_mmov_done:
	}
}
#endif //_M_IX86

/*memcpyRev*(pDst, pSrc, cnt)
	copy buffer in reverse order to preserve buffer
	where src and dst overlap and src < dst*/
__inline void __cdecl memcpyRev(void * pDst, const void * pSrc, size_t cb)
{
#if defined(_M_IX86)
	__asm {
		mov		ecx,cb
		mov		esi,pSrc
		mov		edi,pDst
		lea		esi,[esi+ecx-4]
		lea		edi,[edi+ecx-4]
		push		ecx
		std
		shr		ecx,2
		rep		movsd
		pop		ecx
		and		ecx,3
		add		esi,3
		add		edi,3
		rep		movsb
		cld
	}
#else
	while ((int)--cb >= 0) ((BYTE*)pDst)[cb] = ((BYTE*)pSrc)[cb];
//	return pDst;
#endif
}

__inline void __cdecl memcpyRevWords(void * pDst, const void * pSrc, size_t cw)
{
#if defined(_M_IX86)
	__asm {
		mov		ecx,cw
		mov		esi,pSrc
		mov		edi,pDst
		lea		esi,[esi+ecx*2-2]
		lea		edi,[edi+ecx*2-2]
		std
		rep		movsw
		cld
//		lea		eax,[edi + 2]		// return ptr to dest str
	}
#else
	while ((int)--cw >= 0) ((WORD*)pDst)[cw] = ((WORD*)pSrc)[cw];
//	return pDst;
#endif
}

__inline void __cdecl memcpyRevDwords(void * pDst, const void * pSrc, size_t cd)
{
#if defined(_M_IX86)
	__asm {
		mov		ecx,cd
		mov		esi,pSrc
		mov		edi,pDst
		lea		esi,[esi+ecx*4-4]
		lea		edi,[edi+ecx*4-4]
		std
		rep		movsd
		cld
//		lea		eax,[edi + 4]		// return ptr to dest str
	}
#else
	while ((int)--cd >= 0) ((DWORD*)pDst)[cd] = ((DWORD*)pSrc)[cd];
//	return pDst;
#endif
}

__inline void __cdecl memcpyRevMulOf2(void * pDst, const void * pSrc, size_t cb)
{
	AssertInline(!(cb & 0x1));	/* if this asserts, the calling routine incorrectly
										assumed that cb would always be a multiple of 2.
										Change the call to memcpyRev instead of memcpyRev2. */
	memcpyRevWords(pDst, pSrc, cb / 2);
}

__inline void __cdecl memcpyRevMulOf4(void * pDst, const void * pSrc, size_t cb)
{
	AssertInline(!(cb & 0x3));	/* if this asserts, the calling routine incorrectly
										assumed that cb would always be a multiple of 4.
										Change the call to memcpyRev instead of memcpyRev4. */
	memcpyRevDwords(pDst, pSrc, cb / 4);
}



__inline void __cdecl memcpyWords(void * pDst, const void * pSrc, size_t cw)
{
#if defined(_M_IX86)
	__asm {
		mov		ecx,cw
		mov		esi,pSrc
		mov		edi,pDst
		shr		ecx,1			//comment out these 3 lines
		rep		movsd			// if size is more critical
		rcl		ecx,1			// than speed
		rep		movsw
	}
#else 
   memcpy (pDst, pSrc, cw * 2);

//	WORD *pwDst = (WORD *) pDst;
//	WORD *pwSrc = (WORD *) pSrc;
//	while ((int)--cw >= 0) *(pwDst++) = *(pwSrc++);

#endif
}

__inline void __cdecl memcpyDwords(void * pDst, const void * pSrc, size_t cd)
{
#if defined(_M_IX86)
	__asm {
		mov		ecx,cd
		mov		esi,pSrc
		mov		edi,pDst
		rep		movsd
	}
#else
   memcpy (pDst, pSrc, cd * 4);

//	DWORD *pdwDst = (DWORD *) pDst;
//	DWORD *pdwSrc = (DWORD *) pSrc;
//	while ((int)--cd >= 0) *(pdwDst++) = *(pdwSrc++)
 
#endif
}

__inline void __cdecl memcpyMulOf2(void * pDst, const void * pSrc, size_t cb)
{
	AssertInline(!(cb & 0x1));	/* if this asserts, the calling routine incorrectly
										assumed that cb would always be a multiple of 2.
										Change the call to memcpy instead of memcpy2. */
	memcpyWords(pDst, pSrc, cb / 2);
}

__inline void __cdecl memcpyMulOf4(void * pDst, const void * pSrc, size_t cb)
{
	AssertInline(!(cb & 0x3));	/* if this asserts, the calling routine incorrectly
										assumed that cb would always be a multiple of 4.
										Change the call to memcpy instead of memcpy4. */
	memcpyDwords(pDst, pSrc, cb / 4);
}



/*these scan an array IN REVERSE ORDER
	 - put the most common cases last in the array*/
#define countof(arr)		(sizeof(arr) / sizeof(arr[0]))
#define ArrHasB(arr, item)	arrScanB(arr, item, countof(arr))
#define ArrHasW(arr, item)	arrScanW(arr, item, countof(arr))
#define ArrHasD(arr, item)	arrScanD(arr, item, countof(arr))

__inline int __cdecl arrScanB(const char *arr, char item, int cnt)
{	//ret: 0 = item not in array, non-zero = found
	do ; while (--cnt >= 0 && arr[cnt] != item);
	return ++cnt;
}

__inline int __cdecl arrScanW(const WORD *arr, WORD item, int cnt)
{	//ret: 0 = item not in array, non-zero = found
	do ; while (--cnt >= 0 && arr[cnt] != item);
	return ++cnt;
}

__inline int __cdecl arrScanD(const DWORD *arr, DWORD item, int cnt)
{	//ret: 0 = item not in array, non-zero = found
	do ; while (--cnt >= 0 && arr[cnt] != item);
	return ++cnt;
}


__inline char * __cdecl strrchr(const char *string,int c)
{
	return MsoSzIndexRight(string,c);
}

__inline char * __cdecl strstr(const char *string,const char *charset)
{
	return MsoSzStrStr(string,charset);
}

#ifndef ACCESS_BUILD
__inline char * __cdecl _itoa(int value,char *string,int radix)
{
    MsoSzDecodeInt(string,value,radix);
    return string;
}
#endif

__inline wchar_t * __cdecl _itow(int value,wchar_t *string,int radix)
{
    MsoWzDecodeInt(string,value,radix);
    return string;
}

__inline char * __cdecl _ltoa(long value,char *string,int radix)
{
    MsoSzDecodeInt(string,value,radix);
    return string;
}

__inline wchar_t * __cdecl _ltow(long value,wchar_t *string,int radix)
{
    MsoWzDecodeInt(string,value,radix);
    return string;
}

__inline wchar_t * __cdecl _ultow(unsigned long value,wchar_t *string,int radix)
{
    MsoWzDecodeInt(string,value,radix);
    return string;
}

__inline int __cdecl _memicmp(const void *buf1,const void *buf2,size_t count)
{
	return MsoSgnRgchCompare((CHAR *)buf1,(int)count,(CHAR *)buf2,(int)count,msocsIgnoreCase);
}

__inline int __cdecl _strnicmp(const char *string1,const char *string2,size_t size)
{
	return MsoSgnRgchCompare(string1, min(MsoCchSzLen(string1) + 1, size),
							 string2, min(MsoCchSzLen(string2) + 1, size), 
							 msocsIgnoreCase);
}

__inline int __cdecl _wtoi(const wchar_t *string)
{
    int nTemp;
    MsoParseIntWz(string,&nTemp);
    return nTemp;
}

__inline long __cdecl _wtol(const wchar_t *string)
{
    int nTemp;
    MsoParseIntWz(string,&nTemp);
    return (long)nTemp;
}

#ifndef ACCESS_BUILD
__inline int __cdecl atoi(const char *string)
{
    int nTemp = 0;
    MsoParseIntSz(string, &nTemp);
    return nTemp;
}
#endif

#if defined(NOTYET) || defined(MASK_CRT_MEM_ROUTINES)
#ifndef VSMSODEBUG
__inline void * __cdecl malloc(size_t size)
{
    return MsoPvAlloc(size,msodgMisc);
}

__inline void * __cdecl calloc(size_t num,size_t size)
{
    return MsoPvAlloc(num*size,msodgMisc);
}

__inline void  __cdecl free(void *buf)
{
    MsoFreePv(buf);
}

__inline void * __cdecl realloc(void *buf,size_t size)
{
    return (buf!=NULL ? MsoPvRealloc(buf,size)
                      : MsoPvAlloc(size,msodgMisc));
}
#endif
#endif

#undef isspace
__inline int __cdecl isspace(int c)
{
    return MsoFSpaceCh((CHAR)c);
}

#ifndef ZENSTAT_LIB_DEF
#undef isdigit
__inline int __cdecl isdigit(int c)
{
    return MsoFDigitCh((CHAR)c);
}
#endif //ZENSTAT_LIB_DEF

#undef iswdigit
__inline int __cdecl iswdigit(wint_t c)
{
    return MsoFDigitWch((WCHAR)c);
}
#define _WCTYPE_INLINE_DEFINED		//  NOTE:  To keep the crt headers from giving us this again.

#if !defined(ACCESS_BUILD) && !defined(OFFICE_BUILD)
#undef alloca
#define alloca    Do not use
#endif
#endif		//  OFFICE_BUILD || WORD_BUILD || EXCEL_BUILD || ACCESS_BUILD || PPT_BUILD
#endif		//  !NO_LIBC_INLINE

#endif // MSOSTR_H
