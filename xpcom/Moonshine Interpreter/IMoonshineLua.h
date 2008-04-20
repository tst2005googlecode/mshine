/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM IMoonshineLua.idl
 */

#ifndef __gen_IMoonshineLua_h__
#define __gen_IMoonshineLua_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    IMoonshineLua */
#define IMOONSHINELUA_IID_STR "a1091011-3c4e-47b8-b35a-b8ee21d33c81"

#define IMOONSHINELUA_IID \
  {0xa1091011, 0x3c4e, 0x47b8, \
    { 0xb3, 0x5a, 0xb8, 0xee, 0x21, 0xd3, 0x3c, 0x81 }}

class NS_NO_VTABLE IMoonshineLua : public nsISupports {
 public: 

  NS_DEFINE_STATIC_IID_ACCESSOR(IMOONSHINELUA_IID)

  /* ACString GetVersion (); */
  NS_IMETHOD GetVersion(nsACString & _retval) = 0;

  /* ACString ExecuteStatement (in ACString statement); */
  NS_IMETHOD ExecuteStatement(const nsACString & statement, nsACString & _retval) = 0;

};

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_IMOONSHINELUA \
  NS_IMETHOD GetVersion(nsACString & _retval); \
  NS_IMETHOD ExecuteStatement(const nsACString & statement, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_IMOONSHINELUA(_to) \
  NS_IMETHOD GetVersion(nsACString & _retval) { return _to GetVersion(_retval); } \
  NS_IMETHOD ExecuteStatement(const nsACString & statement, nsACString & _retval) { return _to ExecuteStatement(statement, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_IMOONSHINELUA(_to) \
  NS_IMETHOD GetVersion(nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetVersion(_retval); } \
  NS_IMETHOD ExecuteStatement(const nsACString & statement, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExecuteStatement(statement, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public IMoonshineLua
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_IMOONSHINELUA

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, IMoonshineLua)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* ACString GetVersion (); */
NS_IMETHODIMP _MYCLASS_::GetVersion(nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString ExecuteStatement (in ACString statement); */
NS_IMETHODIMP _MYCLASS_::ExecuteStatement(const nsACString & statement, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_IMoonshineLua_h__ */
