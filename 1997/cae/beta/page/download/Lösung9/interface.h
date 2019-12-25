/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 3.01.75 */
/* at Tue Sep 30 04:52:59 1997
 */
/* Compiler settings for interface.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: none
*/
//@@MIDL_FILE_HEADING(  )
#include "rpc.h"
#include "rpcndr.h"
#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __interface_h__
#define __interface_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IProcessor_FWD_DEFINED__
#define __IProcessor_FWD_DEFINED__
typedef interface IProcessor IProcessor;
#endif 	/* __IProcessor_FWD_DEFINED__ */


#ifndef __Processor_FWD_DEFINED__
#define __Processor_FWD_DEFINED__

#ifdef __cplusplus
typedef class Processor Processor;
#else
typedef struct Processor Processor;
#endif /* __cplusplus */

#endif 	/* __Processor_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IProcessor_INTERFACE_DEFINED__
#define __IProcessor_INTERFACE_DEFINED__

/****************************************
 * Generated header for interface: IProcessor
 * at Tue Sep 30 04:52:59 1997
 * using MIDL 3.01.75
 ****************************************/
/* [uuid][unique][dual][object] */ 



EXTERN_C const IID IID_IProcessor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    interface DECLSPEC_UUID("9CEDE610-0116-11D1-86CA-E9A742759030")
    IProcessor : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddNode( 
            /* [in] */ double X,
            /* [in] */ double Y) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResult( 
            /* [in] */ long Name,
            /* [retval][out] */ double __RPC_FAR *Result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProcessorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IProcessor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IProcessor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IProcessor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IProcessor __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IProcessor __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IProcessor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IProcessor __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddNode )( 
            IProcessor __RPC_FAR * This,
            /* [in] */ double X,
            /* [in] */ double Y);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResult )( 
            IProcessor __RPC_FAR * This,
            /* [in] */ long Name,
            /* [retval][out] */ double __RPC_FAR *Result);
        
        END_INTERFACE
    } IProcessorVtbl;

    interface IProcessor
    {
        CONST_VTBL struct IProcessorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProcessor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IProcessor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IProcessor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IProcessor_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IProcessor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IProcessor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IProcessor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IProcessor_AddNode(This,X,Y)	\
    (This)->lpVtbl -> AddNode(This,X,Y)

#define IProcessor_GetResult(This,Name,Result)	\
    (This)->lpVtbl -> GetResult(This,Name,Result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IProcessor_AddNode_Proxy( 
    IProcessor __RPC_FAR * This,
    /* [in] */ double X,
    /* [in] */ double Y);


void __RPC_STUB IProcessor_AddNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IProcessor_GetResult_Proxy( 
    IProcessor __RPC_FAR * This,
    /* [in] */ long Name,
    /* [retval][out] */ double __RPC_FAR *Result);


void __RPC_STUB IProcessor_GetResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IProcessor_INTERFACE_DEFINED__ */



#ifndef __Processor_LIBRARY_DEFINED__
#define __Processor_LIBRARY_DEFINED__

/****************************************
 * Generated header for library: Processor
 * at Tue Sep 30 04:52:59 1997
 * using MIDL 3.01.75
 ****************************************/
/* [version][uuid] */ 



EXTERN_C const IID LIBID_Processor;

#ifdef __cplusplus
EXTERN_C const CLSID CLSID_Processor;

class DECLSPEC_UUID("9CEDE610-0116-11D1-86CA-E9A742759032")
Processor;
#endif
#endif /* __Processor_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
