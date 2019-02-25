

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* Compiler settings for IVsQueryEditQuerySave80.idl:
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

#ifndef __IVsQueryEditQuerySave80_h__
#define __IVsQueryEditQuerySave80_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "IVsQueryEditQuerySave2.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_IVsQueryEditQuerySave80_0000 */
/* [local] */ 

#pragma once

enum __VSQueryEditFlags2
    {	QEF_AllowUnopenedProjects	= 0x80,
	QEF_CheckoutLocalVersion	= 0x100,
	QEF_CheckoutLatestVersion	= 0x200,
	QEF_DetectAnyChangedFile	= 0x400
    } ;
typedef DWORD VSQueryEditFlags2;


enum tagVSQueryEditResultFlags2
    {	QER_Reloaded	= 0x200,
	QER_Changed	= 0x400
    } ;
typedef DWORD VSQueryEditResultFlags2;



extern RPC_IF_HANDLE __MIDL_itf_IVsQueryEditQuerySave80_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IVsQueryEditQuerySave80_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


