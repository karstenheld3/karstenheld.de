/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Sep 30 04:52:59 1997
 */
/* Compiler settings for interface.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IProcessor = {0x9CEDE610,0x0116,0x11D1,{0x86,0xCA,0xE9,0xA7,0x42,0x75,0x90,0x30}};


const IID LIBID_Processor = {0x9CEDE610,0x0116,0x11D1,{0x86,0xCA,0xE9,0xA7,0x42,0x75,0x90,0x31}};


const CLSID CLSID_Processor = {0x9CEDE610,0x0116,0x11D1,{0x86,0xCA,0xE9,0xA7,0x42,0x75,0x90,0x32}};


#ifdef __cplusplus
}
#endif

