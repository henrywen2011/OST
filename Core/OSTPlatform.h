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
#ifndef OST_CORE_OSTPLATFORM_H
#define OST_CORE_OSTPLATFORM_H


//---------------------------------------------------------------------------
// Platform Defines
//---------------------------------------------------------------------------
enum
{
	OST_PLATFORM_WIN32         = 1,
	OST_PLATFORM_LINUX_X86     = 2,
	OST_PLATFORM_LINUX_ARM     = 3,
	OST_PLATFORM_ANDROID       = 4,
	OST_PLATFORM_MACOSX        = 5,
};

#if (defined _WIN32)
#	ifndef RC_INVOKED
#		if _MSC_VER < 1400
#			error OpenST Platform Abstraction Layer - Win32 - Microsoft Visual Studio version below 2005 are not supported!
#		endif
#	endif
#	include "OSTPlatformWin32.h"
#	define OST_PLAFORM           OST_PLATFORM_WIN32
#	define OST_PLATFORM_STRING   "win32"
#elif (__linux__ && (i386 || __x86_64__))
#	include "OSTPlatformLinux-x86.h"
#	define OST_PLAFORM           OST_PLATFORM_LINUX_X86
#	define OST_PLATFORM_STRING   "linux-x86"
#elif (__linux__ && __arm__)
#	include "OSTPlatformLinux-Arm.h"
#	define OST_PLAFORM           OST_PLATFORM_LINUX_ARM
#	define OST_PLATFORM_STRING   "linux-arm"
#elif defined (ANDROID)
#	include "OSTPlatformAndroid.h"
#	define OST_PLAFORM           OST_PLATFORM_ANDROID
#	define OST_PLATFORM_STRING   "android"
#elif (__APPLE__)
#	include "OSTPlatformMacOSX.h"
#	define OST_PLAFORM           OST_PLATFORM_MACOSX
#	define OST_PLATFORM_STRING   "macosx"
#else
#	error OpenST Platform Abstraction Layer - Unsupported Platform!
#endif

//---------------------------------------------------------------------------
// API Export/Import Macros
//---------------------------------------------------------------------------
#ifdef __cplusplus
#	define OST_C extern "C"
#	define OST_C_API_EXPORT  OST_C  OST_API_EXPORT
#	define OST_C_API_IMPORT  OST_C  OST_API_IMPORT
#	define OST_CPP_API_EXPORT       OST_API_EXPORT
#	define OST_CPP_API_IMPORT       OST_API_IMPORT
#else // __cplusplus
#	define OST_C_API_EXPORT         OST_API_EXPORT
#	define OST_C_API_IMPORT         OST_API_IMPORT
#endif  // __cplusplus


#ifdef OPENST_EXPORT
#	define OST_C_API    OST_C_API_EXPORT
#	define OST_CPP_API  OST_CPP_API_EXPORT
#else // OPENNI2_EXPORT
#	define OST_C_API    OST_C_API_IMPORT
#	define OST_CPP_API  OST_CPP_API_IMPORT
#endif//OPENST_EXPORT

//---------------------------------------------------------------------------
// Base Macros
//---------------------------------------------------------------------------
#define OST_DISABLE_COPY(Class)			\
	Class (const Class&);				\
	Class &operator=(const Class&);


#define OST_ABS(a)					( (a) < 0   ? (-(a)) : (a) )
#define OST_SUB_ABS(a, b)			( (a) > (b) ? ((a) - (b)) : ((b) - (a)) )
#define OST_MIN(a, b)				( (a) < (b) ? (a) : (b) )
#define OST_MAX(a, b)				( (a) > (b) ? (a) : (b) )
#define OST_SWAP(a, b, t)			( (t) = (a); (a) = (b); (b) = (t); )


#define OST_SAFE_DELETE(x)			{ if(x) delete x; x = 0; }
#define OST_SAFE_DELETE_ARRAY(x)	{ if(x) delete[] x; x = 0; }


/** Converts n into a pre-processor string.  */ 
#define OST_STRINGIFY_HELPER(n)		#n
#define OST_STRINGIFY(n)			OST_STRINGIFY_HELPER(n)
#define OST_CONNECTION(a, b)		(a##b)


#define OST_GETLENGTH_ARRAY(a)			sizeof(a) / sizeof(a[0])
#define OST_STRCPY_ARRAY_SIZE(a, b, l)	{ if(a && b) strncpy(a, b, l); }
#define OST_STRCPY_ARRAY(a, b)			{													\
											if(a && b)										\
											{												\
												size_t len1 = strlen(a);					\
												size_t len2 = strlen(b);					\
												strncpy(a, b, len1 < len2 ? len1 : len2);	\
											}												\
										}


//---------------------------------------------------------------------------
// Digital Image Macros
//---------------------------------------------------------------------------
#define OST_PI						3.141592653589793f
#define OST_RGB2GRAY(r, g, b)		( ((b) * 117 + (g) * 601 + (r) * 306) >> 10 )


//---------------------------------------------------------------------------
// date and time at compile time
//---------------------------------------------------------------------------
#define OST_TIMESTAMP				__DATE__ " " __TIME__


//---------------------------------------------------------------------------
// The default memory alignment
//---------------------------------------------------------------------------
#define OST_DEFAULT_MEM_ALIGN		16

#endif//OST_CORE_OSTPLATFORM_H