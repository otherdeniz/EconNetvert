#pragma once

/****************************************************************************
	msointl.h

	Owner: NobuyaH
 	Copyright (c) 1994-95 Microsoft Corporation

	This file contains the exported interfaces and declarations for
	internationalization.
****************************************************************************/
#ifndef MSOINTL_H
#define MSOINTL_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


/*************************************************************************
	Data Types
*************************************************************************/
typedef UINT CPG;		// code page
typedef WORD LID;		// language id
typedef WORD CHS;		// Char set


/*************************************************************************
	Language ID's (lid)
*************************************************************************/
#define lidUnknown				0xffff
#define lidNone					0x0000
#define lidNoProof				0x0400
// listed in order of PRIMARYLANGID, then SUBLANGID
#define lidArabic				0x0401
#define lidIraq					0x0801
#define lidEgyptian				0x0c01
#define lidLibya				0x1001
#define lidAlgerian				0x1401
#define lidMorocco				0x1801
#define lidTunisia				0x1c01
#define lidOman					0x2001
#define lidYemen				0x2401
#define lidSyria				0x2801
#define lidJordan				0x2c01
#define lidLebanon				0x3001
#define lidKuwait				0x3401
#define lidUAE					0x3801
#define lidBahrain				0x3c01
#define lidQatar				0x4001
#define lidBulgarian			0x0402
#define lidCatalan				0x0403
#define lidTaiwan				0x0404	// Traditional Chinese
#define lidChina				0x0804	// Simplified Chinese
#define lidHongkong				0x0c04	// Mixed Chinese
#define lidSingapore			0x1004
#define lidMacau				0x1404
#define lidCzech				0x0405
#define lidDanish				0x0406
#define lidGerman				0x0407
#define lidSwissGerman			0x0807
#define lidAustrianGerman		0x0c07
#define lidGermanLuxembourg		0x1007
#define lidGermanLiechtenstein	0x1407
#define lidGreek				0x0408
#define lidAmerican 			0x0409	// English (U.S.)
#define lidBritish				0x0809	// English (U.K.)
#define lidAustralian			0x0c09	// English (Australian)
#define lidCanadianEnglish		0x1009	// English (Canadian)
#define lidEnglishNewZealand	0x1409
#define lidEnglishIreland		0x1809
#define lidEnglishSouthAfrica	0x1c09
#define lidEnglishJamaica		0x2009
#define lidEnglishCaribbean		0x2409
#define lidEnglishBelize		0x2809
#define lidEnglishTrinidad		0x2c09
#define lidEnglishZimbabwe		0x3009
#define lidEnglishPhilippines	0x3409
#define lidEnglishIndonesia		0x3809
#define lidEnglishHongKong		0x3c09
#define lidEnglishIndia			0x4009
#define lidEnglishMalaysia		0x4409
#define lidEnglishSingapore		0x4809
#define lidSpanish				0x040a	// Traditional Spanish
#define lidSpanishCA			0x080a	// Central American Spanish
#define lidMexican				0x080a
#define lidSpanishModern		0x0c0a	// Modern Spanish
#define lidGuatemala			0x100a
#define lidCostaRica			0x140a
#define lidPanama				0x180a
#define lidDominicanRepublic	0x1c0a
#define lidSpanishSA			0x200a	// South American Spanish
#define lidVenezuela			0x200a
#define lidColombia				0x240a
#define lidPeru					0x280a
#define lidArgentina			0x2c0a
#define lidEcuador				0x300a
#define lidChile				0x340a
#define lidUruguay				0x380a
#define lidParguay				0x3c0a
#define lidBolivia				0x400a
#define lidElSalvador			0x440a
#define lidHonduras				0x480a
#define lidNicaragua			0x4c0a
#define lidPuertoRico			0x500a
#define lidFinnish				0x040b
#define lidFrench				0x040c
#define lidFrenchBelgian		0x080c
#define lidFrenchCanadian		0x0c0c
#define lidFrenchSwiss			0x100c
#define lidFrenchLuxembourg		0x140c
#define lidFrenchMonaco			0x180c
#define lidFrenchWestIndies		0x1c0c
#define lidFrenchReunion		0x200c
#define lidFrenchZaire			0x240c
#define lidFrenchSenegal		0x280c
#define lidFrenchCameroon		0x2c0c
#define lidFrenchCotedIvoire	0x300c
#define lidFrenchMali			0x340c
#define lidHebrew				0x040d
#define lidHungarian			0x040e
#define lidIcelandic			0x040f
#define lidItalian				0x0410
#define lidItalianSwiss			0x0810
#define lidJapanese				0x0411
#define lidKorean				0x0412
//	*** the only one with SUBLANGID == 0!! ***
#define lidDutchPreferred		0x0013
#define lidDutch				0x0413
#define lidDutchBelgian			0x0813
#define lidNorskBokmal			0x0414
#define lidNorskNynorsk			0x0814
#define lidPolish				0x0415
#define lidPortBrazil			0x0416
#define lidPortIberian			0x0816
#define lidRhaetoRomanic		0x0417
#define lidRomanian				0x0418
#define lidRomanianMoldavia		0x0818
#define lidRussian				0x0419
#define lidRussianMoldavia		0x0819
#define lidCroatian				0x041a
#define lidSerbianLatin			0x081a
#define lidSerbianCyrillic		0x0c1a
#define lidBosniaHerzegovina	0x101a
#define lidSlovak				0x041b
#define lidAlbanian				0x041c
#define lidSwedish				0x041d
#define lidSwedishFinland		0x081d
#define lidThai					0x041e	// Thailand, complex script
#define lidTurkish				0x041f
#define lidUrdu					0x0420	// Indic Language; Arabic script
#define lidUrduIndia			0x0820
#define lidIndonesian			0x0421
#define lidUkrainian			0x0422	// xUSSR
#define lidByelorussian			0x0423	// xUSSR
#define lidSlovenian			0x0424
#define lidEstonian				0x0425	// xUSSR
#define lidLatvian				0x0426	// xUSSR
#define lidLithuanian			0x0427	// xUSSR
#define lidLithuanianTrad		0x0827
#define lidTajik				0x0428
#define lidFarsi				0x0429	// Arabic script
#define lidVietnamese			0x042a
#define lidArmenian				0x042b	// xUSSR
#define lidAzeriLatin			0x042c	// xUSSR
#define lidAzeriCyrillic		0x082c	// xUSSR
#define lidBasque				0x042d
#define lidSorbian				0x042e
#define lidMacedonian			0x042f
#define lidSutu					0x0430
#define lidTsonga				0x0431
#define lidTswana				0x0432
#define lidVenda				0x0433
#define lidXhosa				0x0434
#define lidZulu					0x0435
#define lidAfrikaans			0x0436
#define lidGeorgian				0x0437	// xUSSR
#define lidFaeroese				0x0438
#define lidHindi				0x0439	// Indic Language
#define lidMaltese				0x043a
#define lidSamiLappish			0x043b
#define lidGaelicScots			0x043c
#define lidGaelicIrish			0x083c
#define lidYiddish				0x043d
#define lidMalaysian			0x043e
#define lidMalayBrunei			0x083e
#define lidKazakh				0x043f	// xUSSR
#define lidKyrgyz				0x0440
#define lidSwahili				0x0441
#define lidTurkmen				0x0442
#define lidUzbekLatin			0x0443	// xUSSR
#define lidUzbekCyrillic		0x0843	// xUSSR
#define lidTatar				0x0444	// xUSSR
#define lidBengali				0x0445	// Indic Language
#define lidBengaliBangladesh	0x0845
#define lidPunjabi				0x0446	// Indic Language
#define lidPunjabiPakistan		0x0846
#define lidGujarati				0x0447	// Indic Language
#define lidOriya				0x0448	// Indic Language
#define lidTamil				0x0449	// Indic Language
#define lidTelugu				0x044a	// Indic Language
#define lidKannada				0x044b	// Indic Language ?not in FLidIndianNative()
#define lidMalayalam			0x044c	// Indic Language
#define lidAssamese				0x044d	// Indic Language
#define lidMarathi				0x044e	// Indic Language
#define lidSanskrit				0x044f	// Indic Language
#define lidMongolian			0x0450   // Mongolian Cylliric
#define lidMongolianMongo		0x0850	// Mongolian Mongolian
#define lidTibetan				0x0451
#define lidWelsh				0x0452
#define lidKhmer				0x0453
#define lidLao					0x0454
#define lidBurmese				0x0455
#define lidGalician				0x0456
#define lidKonkani				0x0457	// Indic Language
#define lidManipuri				0x0458	// Indic Language
#define lidSindhi				0x0459	// Indic Language
#define lidSindhiPakistan		0x0859
#define lidSyriac				0x045a
#define lidSinhalese			0x045b
#define lidCherokee				0x045c
#define lidInuktitut			0x045d
#define lidAmharic				0x045e
#define lidTamazight            0x045f  // Berber - Arabic script
#define lidTamazightLatin       0x085f  // Berber - Latin script
#define lidKashmiri				0x0460	// Indic Language
#define lidKashmiriIndia		0x0860
#define lidNepali				0x0461	// Indic Language
#define lidNepaliIndia			0x0861
#define lidFrisian				0x0462
#define lidPashto				0x0463
#define lidFilipino             0x0464  // Philippines
#define lidMaldivian            0x0465  // Thaana script
#define lidEdo					0x0466
#define lidFulfulde				0x0467
#define lidHausa				0x0468
#define lidIbibio				0x0469
#define lidYoruba				0x046a
// slight gap here...
#define lidIgbo					0x0470
#define lidKanuri				0x0471
#define lidOromo				0x0472
#define lidTigrignaEthiopic		0x0473
#define lidTigrignaEritrea		0x0873
#define lidGuarani				0x0474
#define lidHawaiian				0x0475
#define lidLatin				0x0476
#define lidSomali				0x0477
#define lidYi					0x0478
#define lidDzongkha				0x0851
#define lidFrenchHaiti			0x3c0c
#define lidFrenchMorocco		0x380c
// insert new languages here
//!!! update lidBaseHi and sublangs[] if you add a new language
//!!! update sublangs[] if you add any sublanguages

#define lidBaseHi				0x0078	// highest base value currently defined
#define lidSubHi				20		// highest sublang value (high 6 bits)
#define lidHi					200					

// inline LangBase macro (like WLangBase, which looks at the bottom 10 bits,
// but more efficient since we know we're nowhere near overflowing 8 bits
#define ilLangBase(lid)		((BYTE)lid)


__inline int FLidIndianNative(int lid)
{
	int ret;  ret = 0;
	switch (ilLangBase(lid)) 
	{
		case ilLangBase(lidAssamese):
		case ilLangBase(lidBengali):
		case ilLangBase(lidGujarati):
		case ilLangBase(lidHindi):
		case ilLangBase(lidKonkani):
		case ilLangBase(lidMalayalam):
		case ilLangBase(lidManipuri):
		case ilLangBase(lidMarathi):
		case ilLangBase(lidOriya):
		case ilLangBase(lidNepali):
		case ilLangBase(lidSanskrit):
		case ilLangBase(lidTamil):
		case ilLangBase(lidTelugu):
		case ilLangBase(lidKannada):
		case ilLangBase(lidBurmese):
		case ilLangBase(lidSinhalese):
			{
			ret++;
			break;
			}
		case ilLangBase(lidPunjabi) :
			{
			if (lidPunjabiPakistan != lid)
				ret++;
			break;
			}
		case ilLangBase(lidSindhi) :
			{
			if (lidSindhiPakistan != lid)
				ret++;
			break;
			}
		case ilLangBase(lidKashmiri) :
			{
			if (lidKashmiriIndia == lid)
				ret++;
			break;
			}
		default:
			break;
	}
	return ret;
}/*FLidIndianNative*/

__inline int FLidFarEast(unsigned lid)
{
	int ret;  ret = 0;
	switch (PRIMARYLANGID(lid)) {
		case PRIMARYLANGID(lidJapanese):
		case PRIMARYLANGID(lidKorean):
		case PRIMARYLANGID(lidChina):
			ret++;
	}
	return ret;
}

__inline int FLidBiDi(unsigned lid)
{
	int ret = 0;
	switch (ilLangBase(lid)) 
	{
		case PRIMARYLANGID(lidArabic):
		case PRIMARYLANGID(lidHebrew):
		case PRIMARYLANGID(lidFarsi):
		case PRIMARYLANGID(lidUrdu):
		case PRIMARYLANGID(lidYiddish):
		case PRIMARYLANGID(lidSyriac):
		case PRIMARYLANGID(lidPashto):
		case PRIMARYLANGID(lidMaldivian):
		case PRIMARYLANGID(lidTamazight):
			ret++;
			break;
		case ilLangBase(lidSindhi) :
			{
			if (lidSindhiPakistan == lid)
				ret++;
			break;
			}
		case ilLangBase(lidPunjabi) :
			{
			if (lidPunjabiPakistan == lid)
				ret++;
			break;
			}
		case ilLangBase(lidKashmiri) :
			{
			if (lidKashmiriIndia != lid)
				ret++;
			break;
			}
		default:
			break;
	}
	return ret;
}


__inline int FValidLid(unsigned lid)
{
	//omit 0th element, dec lid so 0 will be invalid
	static const BYTE sublangs[] = {
		  16, 1, 1, 5, 1, 1, 5, 1,18,20, 1,15, 1, 1, 1,	//0x01..0x0F
		2, 1, 1,2+1,2, 1, 2, 1, 2, 2, 4, 1, 1, 2, 1, 1,	//0x10..0x1F
		2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1,	//0x20..0x2F
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1,	//0x30..0x3F
		1, 1, 1, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1,	//0x40..0x4F
		2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2,	//0x50..0x5F
		2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,	//0x60..0x6F
		1, 1, 1, 2, 1, 1, 1, 1, 1};						//0x70..lidBaseHi
	int sublang;
	int ret; ret = 0;	//doing this with "if(cond)ret++; return ret;"
						//	instead of simply "return(cond)" actually
						//	compiles smaller and avoids a jmp
	sublang = lid >> 10;		// get SUBLANGID
	lid &= 0x03FF;				// get PRIMARYLANGID
	if (lid != PRIMARYLANGID(lidDutch))
		sublang--;
	if (--lid < lidBaseHi && (BYTE)sublang < sublangs[lid])
		ret++;
	return ret;
}


#define FLidSouthAsia(lid) \
				(ilLangBase(lid) == ilLangBase(lidThai) || ilLangBase(lid) == ilLangBase(lidTibetan) || \
				ilLangBase(lid) == ilLangBase(lidKhmer) || ilLangBase(lid) == ilLangBase(lidLao) || \
				FLidIndianNative(lid))

#define FLidComplexScript(lid) \
				(FLidBiDi(lid) || FLidSouthAsia(lid))

#define FLidChinese(lid) \
				(PRIMARYLANGID(lid) == PRIMARYLANGID(lidChina))

/*#define FValidLid(lid) \
				(FLidEuro(lid) || FLidFarEast(lid) || FLidComplexScript(lid))/**/

#define FIsLangBaseTaiwan(lid) \
				(lid == lidTaiwan || lid == lidHongkong || lid == lidMacau)

#define FIsLangBaseChina(lid) \
				(lid == lidChina || lid == lidSingapore)

#define LidChineseBaseLang(lid) \
				((LID)(FIsLangBaseChina(lid) ? lidChina : lidTaiwan))

/*************************************************************************
	Code Pages
*************************************************************************/
#define CP_OEM_437       437
#define CP_ARABICDOS     708
#define CP_DOS720        720
#define CP_IBM850        850
#define CP_IBM852        852
#define CP_DOS862        862
#define CP_OEM_864       864
#define CP_IBM866        866
#define CP_THAI          874
#define CP_JAPAN         932
#define CP_CHINA         936
#define CP_KOREA         949
#define CP_TAIWAN        950
#define CP_EASTEUROPE    1250
#define CP_RUSSIAN       1251
#define CP_WESTEUROPE    1252
#define CP_GREEK         1253
#define CP_TURKISH       1254
#define CP_HEBREW        1255
#define CP_ARABIC        1256
#define CP_BALTIC        1257
#define CP_VIETNAMESE    1258
#define CP_ASCII         20127
#define CP_RUSSIANKOI8R  20866
#define CP_RUSSIANKOI8U  21866
#define CP_ISOLATIN1     28591
#define CP_ISOEASTEUROPE 28592
#define CP_ISOTURKISH    28593
#define CP_ISOBALTIC     28594
#define CP_ISORUSSIAN    28595
#define CP_ISOARABIC     28596
#define CP_ISOGREEK      28597
#define CP_ISOHEBREW     28598
#define CP_ISOTURKISH2   28599
#define CP_ISOLATIN9     28605
#define CP_HEBREWLOG     38598
#define CP_USER          50000
#define CP_AUTOALL       50001
#define CP_JAPANNHK      50220
#define CP_JAPANESC      50221
#define CP_JAPANSIO      50222
#define CP_KOREAISO      50225
#define CP_TAIWANISO     50227
#define CP_CHINAISO      50229
#define CP_AUTOJAPAN     50932
#define CP_AUTOCHINA     50936
#define CP_AUTOKOREA     50949
#define CP_AUTOTAIWAN    50950
#define CP_AUTORUSSIAN   51251
#define CP_AUTOGREEK     51253
#define CP_AUTOARABIC    51256
#define CP_JAPANEUC      51932
#define CP_CHINAEUC      51936
#define CP_KOREAEUC      51949
#define CP_TAIWANEUC     51950
#define CP_CHINAHZ       52936

// ISCII codepages
#define CP_ISCII_DEVANAGARI 57002
#define CP_ISCII_BENGALI    57003
#define CP_ISCII_TAMIL      57004
#define CP_ISCII_TELUGU     57005
#define CP_ISCII_ASSAMESE   57006
#define CP_ISCII_ORIYA      57007
#define CP_ISCII_KANNADA    57008
#define CP_ISCII_MALAYALAM  57009
#define CP_ISCII_GUJARATI   57010
#define CP_ISCII_PUNJABI    57011

#define CP_MAC_ROMAN     10000
#define CP_MAC_JAPAN     10001
#define CP_MAC_ARABIC    10004
#define CP_MAC_HEBREW    10005
#define CP_MAC_GREEK     10006
#define CP_MAC_CYRILLIC  10007
#define CP_MAC_LATIN2    10029
#define CP_MAC_TURKISH   10081
#define CP_DEFAULT       CP_ACP
#define CP_GETDEFAULT    GetACP()
#define CP_JOHAB         1361
#define CP_SYMBOL        42
#define CP_UTF8          65001
#define CP_UTF7          65000
#define CP_UNICODELITTLE 1200
#define CP_UNICODEBIG    1201
#define CP_UNICODEDEF    CP_UNICODELITTLE
#define CP_UNKNOWN		 -1

/*************************************************************************
	Charsets
*************************************************************************/
#define MACINTOSH_CHARSET   256     // Value used in chp.chs and fcb.chs in Word
#define chsUnknown    (0xffff)
#define chsAnsi       ANSI_CHARSET
#define chsSysDflt    DEFAULT_CHARSET
#define chsSymbol     SYMBOL_CHARSET
#define chsShiftJIS   SHIFTJIS_CHARSET
#define chsHangeul    HANGEUL_CHARSET
#define chsChinese5   CHINESEBIG5_CHARSET
#define chsGB2312	  GB2312_CHARSET
#define chsOEM        OEM_CHARSET
#define chsGreek      GREEK_CHARSET
#define chsTurkish    TURKISH_CHARSET
#define chsEastEurope EASTEUROPE_CHARSET
#define chsRussian    RUSSIAN_CHARSET
#define chsMac        MACINTOSH_CHARSET   // <-Mac charset used by Word in files(NOTE: this won't fit in a byte)
#define chsMacFfn     MAC_CHARSET         // for use FFN (can't allow file format change)
#define chsBaltic     BALTIC_CHARSET
#define chsPC437	  254
#ifndef ARABIC_TRAD_CHARSET
#define ARABIC_TRAD_CHARSET     179   // Traditional Arabic Font layout
#endif


#ifndef STANDALONE

/*************************************************************************
	Inline Functions
*************************************************************************/
__inline int MsoFChsArabic(int chs)	
	{
	return (chs == ARABIC_CHARSET || chs == ARABIC_TRAD_CHARSET);
	}
						 
__inline int MsoFChsHebrew(int chs)
	{
	return (chs == HEBREW_CHARSET);
	}

__inline int MsoFChsBiDi(int chs)
	{
	return (chs == ARABIC_CHARSET ||
			chs == HEBREW_CHARSET ||
			chs == ARABIC_TRAD_CHARSET);
	}

__inline int MsoFChsComplex(int chs)
	{
	return (chs == ARABIC_CHARSET ||
			chs == HEBREW_CHARSET ||
			chs == ARABIC_TRAD_CHARSET ||
			chs == THAI_CHARSET   ||
			chs == VIETNAMESE_CHARSET);
	}

__inline int MsoFChsDbcs(int chs)
	{
	return (chs == chsShiftJIS ||
			chs == chsHangeul ||
			chs == chsGB2312 ||
			chs == chsChinese5);
	}

__inline int MsoFCpgChinese(int cpg)
	{
	if (cpg == CP_ACP)
		cpg = GetACP();
	return (cpg == CP_TAIWAN || cpg == CP_CHINA);
	}

__inline int MsoFCpgTaiwan(int cpg)
	{
	if (cpg == CP_ACP)
		cpg = GetACP();
	return (cpg == CP_TAIWAN);
	}

__inline int MsoFCpgPRC(int cpg)
	{
	if (cpg == CP_ACP)
		cpg = GetACP();
	return (cpg == CP_CHINA);
	}
	
__inline int MsoFCpgJapanese(int cpg)
	{
	if (cpg == CP_ACP)
		cpg = GetACP();
	return (cpg == CP_JAPAN);
	}
	
__inline int MsoFCpgFarEast(int cpg)
	{
	if (cpg == CP_ACP)
		cpg = GetACP();
	return (cpg == CP_JAPAN || cpg == CP_TAIWAN || cpg == CP_CHINA ||
			cpg == CP_KOREA || cpg == CP_MAC_JAPAN);
	}

__inline int MsoFCpgDbcs(int cpg)
	{
	return (cpg == CP_JAPAN ||
			cpg == CP_KOREA ||
			cpg == CP_TAIWAN ||
			cpg == CP_CHINA);
	}
	
__inline int MsoFCpgArabic(int cpg)
	{
	if (cpg == CP_ACP)
		cpg = GetACP();
	return (cpg == CP_ARABIC);
	}
	
__inline int MsoFCpgHebrew(int cpg)
	{
	if (cpg == CP_ACP)
		cpg = GetACP();
	return (cpg == CP_HEBREW);
	}

__inline int MsoFCpgBiDi(int cpg)
	{
	if (cpg == CP_ACP)
		cpg = GetACP();
	return (cpg == CP_ARABIC ||
			cpg == CP_HEBREW);
	}

__inline int MsoFCpgUcs2(int cpg)
	{
	return (cpg == CP_UNICODELITTLE ||
			cpg == CP_UNICODEBIG);
	}

__inline int MsoFCpgAnyUnicode(int cpg)
	{
	return (cpg == CP_UTF7 ||
			cpg == CP_UTF8 ||
			cpg == CP_UNICODELITTLE ||
			cpg == CP_UNICODEBIG);
	}

//SOUTHASIA // schai. No CP support for Hindi
__inline int MsoFCpgSA(int cpg)
	{
	if (cpg == CP_ACP)
		cpg = GetACP();
	return (cpg == CP_THAI || 
			cpg == CP_VIETNAMESE);
	}
//SOUTHASIA


// Flags for MsoMungeDlgAndCheckFontForACP routine
#define MMD_MUNGETITLE            0x00000001	// Munge dialog title?
#define MMD_BLANKTITLE            0x00000002	// Need to specify MMD_MUNGETITLE
												// for this to be useful
#define MMD_ENSUREMINUIPOINTSIZE  0x00000004	// Change the point size to ensure
												// 8 (or 9) pt at 96 dpi.
#define MMD_ENSUREFONTNAME        0x00000008	// Change the font name so that
												// Far East fonts have localized
												// names on their own systems and
												// English names otherwise.
#define MMD_MUNGEITEMS            0x00000010	// Munge dialog template items?

#define MMD_FORWINNT	(MMD_ENSUREMINUIPOINTSIZE | MMD_ENSUREFONTNAME)
#define MMD_FORWIN9X	(MMD_FORWINNT | MMD_MUNGEITEMS)


/*************************************************************************
	Function Prototypes
*************************************************************************/
MSOAPI_(CPG) MsoCpgFromLid(LID lid);
MSOAPI_(BYTE) MsoChsFromLid(LID lid);
MSOAPI_(WCHAR) MsoWchTypedCh(const char ch);
MSOAPIX_(BOOL) MsoFIsImeLang(void);
MSOAPI_(DWORD) MsoGetTwoDigitYearMax(void);
MSOAPI_(DWORD) MsoGetTwoDigitCalYearMax(int iCal);
MSOMACAPI_(LCID) MsoGetLocale(void);
MSOAPI_(CPG) MsoCpgFromChs(int chs);
MSOAPI_(int) MsoWordBreakFE(LID, WCHAR *, int, int, void *, int);
MSOAPI_(int) MsoFoldWidth(WCHAR *, int, WCHAR *, int);
MSOAPI_(BOOL) MsoFSetModeBias(HWND, int);
MSOAPIX_(WORD*) MsoPwProcessWszOrOrd(WORD *pw, BOOL fBlank, BOOL fSkip);
/* Note that functions MsoMungeDlgForACP & MsoMungeDlgAndCheckFontForACP are
   now obselete. Use MsoMungeDlgEx instead. If not sure, please contact
   NitinG/RGiesen for more information. */
MSOAPI_(LPDLGTEMPLATE) MsoMungeDlgForACP(LPDLGTEMPLATE pdt, BOOL fBlankTitle, BOOL fSkipTitle);
MSOAPI_(LPDLGTEMPLATE *) MsoMungeDlgAndCheckFontForACP(LPDLGTEMPLATE *ppdt, 
									BOOL fBlankTitle, BOOL fIgnoreTitle, DWORD dwSize);
MSOAPI_(LPDLGTEMPLATE *) MsoMungeDlgEx(LPDLGTEMPLATE *ppdt, DWORD dwSize, UINT grfMmd);
MSOAPI_(LID) MsoLidDefaultForLid(LID lid);
MSOAPI_(LCID) MsoGetWebFormsLanguage(void);
/*-----------------------------------------------------------------------------
	MsoFGetAltFontNameCpg
--------------------------------------------------------------------- ZIYIW -*/
MSOAPI_(int) MsoFGetAltFontNameCpg(const WCHAR *xsz, WCHAR *xszAlt, CHS *pchs, CPG cpg, long fMode);

/*-----------------------------------------------------------------------------
	MsoFKnownAltFontNamePair
--------------------------------------------------------------------- ZIYIW -*/
MSOAPI_(int) MsoFKnownAltFontNamePair(const WCHAR *xsz1, const WCHAR *xsz2, CHS *pchs, long fMode);

// used for MsoWordBreakFE
typedef struct _THPARAM {
	int icmd;
	int icnt;
	void *pData;
	int iMax;
} THPARAM;

#define icmdOffsetArray 1
#define icmdWordBreakString 2
#define icmdNumOfChunks 3
#define icmdCurrentSelection 4

#endif /* !STANDALONE */

/*************************************************************************
	Numbering formats 
*************************************************************************/
typedef enum
	{
	msonfcNil = -1,
	msonfcArabic = 0,				//  1, 2, 3, 4, ...
	msonfcMin = msonfcArabic,
	msonfcUCRoman = 1,			//  I, II, III, IV, ...
	msonfcLCRoman = 2,			//  i, ii, iii, iv, ...
	msonfcUCLetter = 3,			//  A, B, C, D, ...
	msonfcLCLetter = 4,			//  a, b, c, d, ...
	msonfcOrdinal = 5,
	msonfcCardtext = 6,
	msonfcOrdtext = 7,
	msonfcHex = 8,
	msonfcChiManSty = 9,
	msonfcDbNum1 = 10,			//  FE numbering style
	msonfcDbNum2 = 11,			//  FE numbering style
	msonfcAiueo = 12,				//  Japan numbering style
	msonfcIroha = 13,				//  Japan numbering style
	msonfcDbChar = 14,
	msonfcSbChar = 15,
	msonfcDbNum3 = 16,			//  FE numbering style
	msonfcDbNum4 = 17,			//  FE numbering style
	msonfcCirclenum = 18,		//  Japan/FE numbering style
	msonfcDArabic = 19,			//  Combines DbChar w/ Arabic		//  REVIEW:  PETERO:  Same as DbChar?
	msonfcDAiueo = 20,			//  Japan - Combines DbChar w/ Aiueo
	msonfcDIroha = 21,			//  Japan - Combines DbChar w/ Iroha//  New defines for 97...
	msonfcArabicLZ = 22,			//  Leading zero:  01, 02, ..., 09, 10, 11, ...
	msonfcBullet = 23,			//  special nfc only used in numbering
	msonfcGanada = 24,			//  Korea
	msonfcChosung = 25,			//  Korea
	msonfcGB1 = 26,				//  China
	msonfcGB2 = 27,				//  China
	msonfcGB3 = 28,				//  China
	msonfcGB4 = 29,				//  China
	msonfcZodiac1 = 30,			//  Taiwan/China
	msonfcZodiac2 = 31,			//  Taiwan/China
	msonfcZodiac3 = 32,			//  Taiwan/China

//  REVIEW:  PETERO:  Complete full support of these
	msonfcTpeDbNum1 = 33,		//  Taiwan
	msonfcTpeDbNum2 = 34,		//  Taiwan
	msonfcTpeDbNum3 = 35,		//  Taiwan
	msonfcTpeDbNum4 = 36,		//  Taiwan
	msonfcChnDbNum1 = 37,		//  China
	msonfcChnDbNum2 = 38,		//  China
	msonfcChnDbNum3 = 39,		//  China
	msonfcChnDbNum4 = 40,		//  China
	msonfcKorDbNum1 = 41,		//  Korea
	msonfcKorDbNum2 = 42,		//  Korea
	msonfcKorDbNum3 = 43,		//  Korea
	msonfcKorDbNum4 = 44,		//  Korea
//  REVIEW:  PETERO:  End

	msonfcHebrew1 = 45,			//  BIDI Heb1 for Hebrew 
	msonfcArabic1 = 46,			//  BIDI AraAlpha for Arabic/Farsi/Urdu
	msonfcHebrew2 = 47,			//  BIDI Heb2 for Hebrew 
	msonfcArabic2 = 48,			//  BIDI AraAbjad for Arabic/Farsi/Urdu
	msonfcHindi1 = 49,			//  Hindi vowels
	msonfcHindi2 = 50,			//  Hindi consonants
	msonfcHindi3 = 51,			//  Hindi numbers
	msonfcHindi4 = 52,			//  Hindi descriptive (cardinals)
	msonfcThai1 = 53,				//  Thai letters
	msonfcThai2 = 54,				//  Thai numbers
	msonfcThai3 = 55,				//  Thai descriptive (cardinals)
	msonfcViet1 = 56,				//  Vietnamese descriptive (cardinals)
	msonfcNumInDash = 57,		//  Page Number format - # -
	msonfcLCRus = 58,				//  Lower case Russian alphabet
	msonfcUCRus = 59,				//  Upper case Russian alphabet
	msonfcLast = msonfcUCRus,
	msonfcNone = 0x00FF,		// special for lists (bullet or no number)
	} MSONFC;


//  NOTE:  msonfcNil and msonfcNone are not valid.
__inline BOOL MsoFValidNfc(MSONFC nfc)
{
	return (nfc >= msonfcMin && nfc <= msonfcLast);
}


_inline BOOL MsoFCanParseNfc(MSONFC nfc)
{
	//  NOTE:  List the numbering styles that we are able to parse.
	switch (nfc)
		{
	case msonfcArabic:
	case msonfcArabicLZ:
	case msonfcUCRoman:
	case msonfcLCRoman:
	case msonfcUCLetter:
	case msonfcLCLetter:
	case msonfcLCRus:
	case msonfcUCRus:
	case msonfcChiManSty:
	case msonfcHebrew1:
	case msonfcHebrew2:
	case msonfcArabic1:
	case msonfcArabic2:
	// _SOUTHASIA : Feb. 24, 1999 -- Code Porting
	case msonfcHindi1: 
	case msonfcHindi2: 
	case msonfcHindi3: 
	case msonfcHindi4: 
	case msonfcThai1: 
	case msonfcThai2: 
	case msonfcThai3:
	case msonfcViet1:
			return (TRUE);
		}
	return (FALSE);
}

#define msofnfcNil				0x00000000	// no flags
#define msofnfcKoreanCirc		0x00000001	// parse, format, and firstlast
#define msofnfcHebrewDQuote		0x00000002	// format only
#define msofnfcNoneBulletOK		0x00000004	// format only
#define msofnfcStripAccent		0x00000008	// format only
#define msofnfcRollOver			0x00000010	// format only
#define msofnfcFirstCap			0x00000020	// format only
#define msofnfcBackslashIsYen	0x00000040	// format only
#define msofnfcSkip4FW			0x00000080	// format only
#define msofnfcChinaCirc		0x00000100	// translate only (why not format too?)
#define msofnfcTaiwanCirc		0x00000200	// translate only (why not format too?)

typedef void (MSOAPICALLTYPE *PFNMSONFCRANGE)(int, int *, int *, ULONG); /* pointer to function filling nfc range */

// core, central use functions
MSOAPI_ (BOOL) MsoFParseWzNfc(WCHAR *wz, int *pnResult, MSONFC nfc, MSONFC nfcRangeOnly, PFNMSONFCRANGE pfnRange, int cchMax, LID lid, ULONG grfnfc);
MSOAPI_ (void) MsoNfcFirstLast(int nfc, int *pwFirst, int *pwLast, ULONG grfnfc);

// this API does not guarantee to NULL-terminate the pwch; use the returned cch!
MSOAPI_ (int)  MsoCchFormatLongNfc(long l, WCHAR *pwch, int nfc, int cchMax, LID lid, ULONG grfnfc);

MSOAPI_ (int) MsoTranslateRgwchNfc(MSONFC msonfc, WCHAR *rgwch, int cch, WCHAR *rgwchOut, int cchOut, LONG lVal, ULONG grfnfc);
MSOAPI_ (MSONFC) MsoNfcFEAmbigFromNfcPn(MSONFC nfc, int *pn);
MSOAPI_ (int) MsoWFromPwchCchDbNumber(WCHAR *lpwch, int cch, MSONFC *pnfc, ULONG grfnfc);

// access to subfunctions to avoid overhead
MSOAPI_ (int) MsoWRomanNumeralPwch(WCHAR *pwch, int cchLen);

MSOAPI_ (void) MsoAraToThaidigits(WCHAR *pwch);
MSOAPI_ (void) MsoAraToHindidigits(WCHAR *pwch);
MSOAPI_ (void) MsoHindiToAradigits(WCHAR *pwch);
MSOAPI_ (void) MsoThaiToAradigits(WCHAR *pwch);

// TTEmbedding.
typedef LONG (WINAPI *PFNTTEMBEDENABLE)(HDC, BOOL *);
MSOAPI_(LONG) MsoIsTTEmbeddingEnabledEx(HDC, BOOL *, WCHAR *, PFNTTEMBEDENABLE);

#ifdef __cplusplus
}; // extern "C"
#endif // __cplusplus

#endif  // !MSOINTL_H
