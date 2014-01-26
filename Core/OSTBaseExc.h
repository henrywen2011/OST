/*****************************************************************************
*  OpenST Basic tool library                                                 *
*  Copyright (C) 2014 Henry.Wen  renhuabest@sina.com   .                     *
*                                                                            *
*  This file is part of OST.                                                 *
*                                                                            *
*  This program is free software; you can redistribute it and/or modify      *
*  it under the terms of the GNU General Public License version 3 as         *
*  published by the Free Software Foundation.                                *
*                                                                            *
*  You should have received a copy of the GNU General Public License         *
*  along with OST. If not, see <http://www.gnu.org/licenses/>.               *
*                                                                            *
*  Unless required by applicable law or agreed to in writing, software       *
*  distributed under the License is distributed on an "AS IS" BASIS,         *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  *
*  See the License for the specific language governing permissions and       *
*  limitations under the License.                                            *
*                                                                            *
*  Author  : Henry.Wen                                                       *
*  E-Mail  : renhuabest@sina.com                                             *
*  License : GNU General Public License (GPL)                                *
*  source code availability:https://github.com/henrywen2011/OST              *
*                                                                            *
*----------------------------------------------------------------------------*
*  Remark         : Description												 *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  Date       | Version | Author        | Description                        *
*----------------------------------------------------------------------------*
*  2014/01/24 | 1.0.0.1 | Henry.Wen     | Create file                        *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/
#ifndef OST_CORE_OSTBBASEEXC_H
#define OST_CORE_OSTBBASEEXC_H

#include <string>
#include <sstream>
#include <exception>

#include "OSTCommon.h"

OST_NAMESPACE_BEGIN

/** 
* @class OSTBaseExc
* @brief Base exception class
*/
class OSTBaseExc : public std::string, public std::exception
{
public:
	OSTBaseExc(const std::string& msg);
	OSTBaseExc(const char* msg = 0);
	OSTBaseExc(std::stringstream &msg);
	virtual ~OSTBaseExc() throw();

	/**
	* @brief Convenient methods to change the exception's text
	*/
	OSTBaseExc& assign (std::stringstream &msg);	//! assign (s.str())
	OSTBaseExc& operator = (std::stringstream &msg);

	OSTBaseExc& append (std::stringstream &msg);	//! append (s.str())
	OSTBaseExc& operator += (std::stringstream &msg);

	OSTBaseExc& assign(const char* msg);
	OSTBaseExc& operator = (const char *msg);
	OSTBaseExc& operator = (const OSTBaseExc& exc);
	
	OSTBaseExc& append(const char* msg);
	OSTBaseExc& operator += (const char *msg);

	/**
	* @brief what() method -- e.what() returns e.c_str()
	*/
	virtual const char* what() const throw();

	/**
	* @brief Stack trace for the point at which the exception was 
	* thrown.The stack trace will be an empty string unless a working
	* stack-tracing routine has been installed (@see below, setStackTracer()).
	*/
	const std::string&  StackTrace() const;

private:
	std::string m_stackTrace;
};

//---------------------------------------------------------------------------
// A macro to save typing when declararing an exception
// class derived directly or indirectly from BaseExc:
//---------------------------------------------------------------------------
#define OST_DEFINE_EXC(name, base)						    \
class name: public base                                     \
{                                                           \
public:														\
	name()                         throw(): base (0)    {}  \
	name (const char* text)        throw(): base (text) {}  \
	name (const std::string &text) throw(): base (text) {}  \
	name (std::stringstream &text) throw(): base (text) {}  \
	~name() throw() { }                                     \
};

//--------------------------------------------------------
// Some exceptions which should be useful in most programs
//--------------------------------------------------------
OST_DEFINE_EXC (ArgExc, OSTBaseExc)    // Invalid arguments to a function call

OST_DEFINE_EXC (LogicExc, OSTBaseExc)  // General error in a program's logic,
// for example, a function was called
// in a context where the call does
// not make sense.

//---------------------------------------------------------------------------
// Invalid input data, e.g. from a file
//---------------------------------------------------------------------------
OST_DEFINE_EXC (InputExc, OSTBaseExc)

//---------------------------------------------------------------------------
// Input or output operation failed
//---------------------------------------------------------------------------
OST_DEFINE_EXC (IoExc, OSTBaseExc)

//---------------------------------------------------------------------------
// Arithmetic exception; more specific exceptions derived from this class
//---------------------------------------------------------------------------
OST_DEFINE_EXC (MathExc, OSTBaseExc)

//---------------------------------------------------------------------------
// Base class for exceptions corresponding.to errno values (see errno.h); more
// specific exceptions derived from this
//---------------------------------------------------------------------------
OST_DEFINE_EXC (ErrnoExc, OSTBaseExc)

//---------------------------------------------------------------------------
// Missing method exception e.g. from a call to a method that is only partially
// or not at all implemented. A reminder to lazy software people to get back
// to work.
//---------------------------------------------------------------------------
OST_DEFINE_EXC (NoImplExc, OSTBaseExc)

//---------------------------------------------------------------------------
// A pointer is inappropriately null.
//---------------------------------------------------------------------------
OST_DEFINE_EXC (NullExc, OSTBaseExc)

//---------------------------------------------------------------------------
// An object is an inappropriate type,i.e. a dynamnic_cast failed.
//---------------------------------------------------------------------------
OST_DEFINE_EXC (TypeExc, OSTBaseExc)

//----------------------------------------------------------------------
// Stack-tracing support:
// 
// SetStackTracer(st)
//
//	installs a stack-tracing routine, st, which will be called from
//	class BaseExc's constructor every time an exception derived from
//	BaseExc is thrown.  The stack-tracing routine should return a
//	string that contains a printable representation of the program's
//	current call stack.  This string will be stored in the BaseExc
//	object; the string is accesible via the BaseExc::stackTrace()
//	method.
//
// SetStackTracer(0)
//
//	removes the current stack tracing routine.  When an exception
//	derived from BaseExc is thrown, the stack trace string stored
//	in the BaseExc object will be empty.
//
// GetStackTracer()
//
//	returns a pointer to the current stack-tracing routine, or 0
//	if there is no current stack stack-tracing routine.
// 
//----------------------------------------------------------------------
typedef std::string (* StackTracer) ();

void SetStackTracer (StackTracer st);
StackTracer GetStackTracer ();

OST_NAMESPACE_EDN

#endif//OST_CORE_OSTBBASEEXC_H