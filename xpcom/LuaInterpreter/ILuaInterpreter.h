/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ILuaInterpreter.idl
 */

#ifndef __gen_ILuaInterpreter_h__
#define __gen_ILuaInterpreter_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    ILuaInterpreter */
#define ILUAINTERPRETER_IID_STR "85ef5c25-ad75-4aa0-ad92-4a4e27b30a45"

#define ILUAINTERPRETER_IID \
  {0x85ef5c25, 0xad75, 0x4aa0, \
    { 0xad, 0x92, 0x4a, 0x4e, 0x27, 0xb3, 0x0a, 0x45 }}

class NS_NO_VTABLE NS_SCRIPTABLE ILuaInterpreter : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(ILUAINTERPRETER_IID)

  /* double ReturnVersion (); */
  NS_SCRIPTABLE NS_IMETHOD ReturnVersion(double *_retval) = 0;

  /* ACString ReturnLuaVersion (); */
  NS_SCRIPTABLE NS_IMETHOD ReturnLuaVersion(nsACString & _retval) = 0;

  /* ACString ExecuteCommand (in string command); */
  NS_SCRIPTABLE NS_IMETHOD ExecuteCommand(const char *command, nsACString & _retval) = 0;

  /* ACString ExecuteScript (in string script); */
  NS_SCRIPTABLE NS_IMETHOD ExecuteScript(const char *script, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(ILuaInterpreter, ILUAINTERPRETER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_ILUAINTERPRETER \
  NS_SCRIPTABLE NS_IMETHOD ReturnVersion(double *_retval); \
  NS_SCRIPTABLE NS_IMETHOD ReturnLuaVersion(nsACString & _retval); \
  NS_SCRIPTABLE NS_IMETHOD ExecuteCommand(const char *command, nsACString & _retval); \
  NS_SCRIPTABLE NS_IMETHOD ExecuteScript(const char *script, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_ILUAINTERPRETER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReturnVersion(double *_retval) { return _to ReturnVersion(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReturnLuaVersion(nsACString & _retval) { return _to ReturnLuaVersion(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteCommand(const char *command, nsACString & _retval) { return _to ExecuteCommand(command, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteScript(const char *script, nsACString & _retval) { return _to ExecuteScript(script, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_ILUAINTERPRETER(_to) \
  NS_SCRIPTABLE NS_IMETHOD ReturnVersion(double *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReturnVersion(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ReturnLuaVersion(nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ReturnLuaVersion(_retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteCommand(const char *command, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteCommand(command, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ExecuteScript(const char *script, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteScript(script, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public ILuaInterpreter
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_ILUAINTERPRETER

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, ILuaInterpreter)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* double ReturnVersion (); */
NS_IMETHODIMP _MYCLASS_::ReturnVersion(double *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString ReturnLuaVersion (); */
NS_IMETHODIMP _MYCLASS_::ReturnLuaVersion(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString ExecuteCommand (in string command); */
NS_IMETHODIMP _MYCLASS_::ExecuteCommand(const char *command, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString ExecuteScript (in string script); */
NS_IMETHODIMP _MYCLASS_::ExecuteScript(const char *script, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_ILuaInterpreter_h__ */
