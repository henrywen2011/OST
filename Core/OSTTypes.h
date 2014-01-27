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
*  2014/01/26 | 1.0.0.1 | Henry.Wen     | Create file                        *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/
#ifndef OST_CORE_OSTTYPES_H
#define OST_CORE_OSTTYPES_H

#ifdef OST_TRUE
#	undef  OST_TRUE
#endif

#ifdef OST_FALSE
#	undef  OST_FALSE
#endif

#define OST_TRUE	1
#define OST_FALSE	0

//---------------------------------------------------------------------------
// Basic Types
//---------------------------------------------------------------------------
/** Boolean TRUE/FALSE type. */ 
typedef	int					OSTBool;
/** Signed character for strings. */ 
typedef	char				OSTChar;
/** Unsigned character for strings. */ 
typedef	unsigned char		OSTUChar;
/** Signed wide character for strings. */ 
typedef	wchar_t				OSTWChar;
/** 8-bit signed integer. */ 
typedef	signed char			OSTInt8;
/** 8-bit unsigned integer. */ 
typedef	unsigned char		OSTUInt8;
/** 16-bit signed integer. */ 
typedef	short				OSTInt16;
/** 16-bit unsigned integer. */ 
typedef	unsigned short		OSTUInt16;
/** 32-bit signed integer. */ 
typedef	int					OSTInt32;
/** 32-bit unsigned integer. */ 
typedef	unsigned int		OSTUInt32;
/** natural signed integer. */ 
typedef	int					OSTInt;
/** natural unsigned integer. */ 
typedef	unsigned int		OSTUInt;
/** natural signed integer. */ 
typedef	long				OSTLong;
/** natural unsigned integer. */ 
typedef	unsigned long		OSTULong;
/** Float (32bit) */ 
typedef	float				OSTFloat;
/** Double (64bit) */ 
typedef	double				OSTDouble;
/** Size type. */ 
typedef size_t				OSTSize_t;


#ifdef WIN32
/** 64-bit signed integer. */ 
typedef	__int64				OSTInt64;
/** 64-bit unsigned integer. */ 
typedef	unsigned __int64	OSTUInt64;
#else
/** 64-bit signed integer. */ 
typedef	long long			OSTInt64;
/** 64-bit unsigned integer. */ 
typedef	unsigned long long	OSTUInt64;
#endif


#endif//OST_CORE_OSTTYPES_H