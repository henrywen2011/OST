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
#ifndef OST_CORE_OSTPLATFORMWIN32_H
#define OST_CORE_OSTPLATFORMWIN32_H

//---------------------------------------------------------------------------
// Prerequisites
//---------------------------------------------------------------------------
#ifndef WINVER						// Allow use of features specific to Windows XP or later
#	define WINVER			0x0501
#endif

#ifndef _WIN32_WINNT				// Allow use of features specific to Windows XP or later
#	define _WIN32_WINNT		0x0501
#endif	

#ifndef _WIN32_WINDOWS				// Allow use of features specific to Windows 98 or later
#	define _WIN32_WINDOWS	0x0410
#endif

#ifndef _WIN32_IE					// Allow use of features specific to IE 6.0 or later
#	define _WIN32_IE		0x0600
#endif

#define WIN32_LEAN_AND_MEAN			// Exclude rarely-used stuff from Windows headers


//---------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------
#include <windows.h>

#include <io.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>

//---------------------------------------------------------------------------
// Undeprecate CRT functions
//---------------------------------------------------------------------------
#ifndef _CRT_SECURE_NO_DEPRECATE 
#	define _CRT_SECURE_NO_DEPRECATE 1
#endif


//---------------------------------------------------------------------------
// Verify that we're built with the multithreaded 
// versions of the runtime libraries 
//---------------------------------------------------------------------------
#if defined(_MSC_VER) && !defined(_MT)
#	error Must compile with /MD, /MDd, /MT or /MTd
#endif


//---------------------------------------------------------------------------
// Check debug/release settings consistency 
//---------------------------------------------------------------------------
#if defined(NDEBUG) && defined(_DEBUG)
#	error Inconsistent build settings (check for /MD[d])
#endif


//---------------------------------------------------------------------------
// Call backs
//---------------------------------------------------------------------------
/** The std call type. */
#define OST_STDCALL			__stdcall

/** The call back calling convention. */
#define OST_CALLBACK_TYPE	OST_STDCALL

/** The C and C++ calling convension. */
#define OST_C_DECL			__cdecl


//---------------------------------------------------------------------------
// Indicates a deprecated function
// Before VS2005 there was no support for declspec deprecated...
//---------------------------------------------------------------------------
#if _MSC_VER < 1400
#	define OST_API_DEPRECATED(msg)
#else
#	define OST_API_DEPRECATED(msg)	__declspec(deprecated(msg))
#endif


//---------------------------------------------------------------------------
// API Export/Import Macros
//---------------------------------------------------------------------------
/** Indicates an exported and imported shared library function. */ 
#define OST_API_EXPORT		__declspec(dllexport)
#define OST_API_IMPORT		__declspec(dllimport)

#endif//OST_CORE_OSTPLATFORMWIN32_H