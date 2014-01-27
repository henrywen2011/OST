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
#ifndef OST_CORE_OSTMEMORY_H
#define OST_CORE_OSTMEMORY_H

#include "OSTTypes.h"

OST_NAMESPACE_BEGIN
/** 
* @class 
* @brief 
*/
class OSTMemory
{
public:
	static void*  OSTMalloc(const OSTSize_t nAllocSize);

	static void*  OSTMallocAligned(const OSTSize_t nAllocSize, const OSTSize_t nAlignment);

	static void*  OSTCalloc(const OSTSize_t nAllocNum, const OSTSize_t nAllocSize);

	static void*  OSTCallocAligned(const OSTSize_t nAllocNum, const OSTSize_t nAllocSize, const OSTSize_t nAlignment);

	static void*  OSTRealloc(void* pMemory, const OSTSize_t nAllocSize);

	static void*  OSTReallocAligned(void* pMemory, const OSTSize_t nAllocSize, const OSTSize_t nAlignment);

	static void*  OSTRecalloc(void* pMemory, const OSTSize_t nAllocNum, const OSTSize_t nAllocSize);

	static void  OSTFree(const void* pMemBlock);

	static void  OSTFreeAligned(const void* pMemBlock);

	static void  OSTMemCopy(void* pDest, const void* pSource, OSTSize_t nCount);

	static OSTInt32  OSTMemCmp(const void *pBuf1, const void *pBuf2, OSTSize_t nCount);

	static void  OSTMemSet(void* pDest, OSTUInt8 nValue, OSTSize_t nCount);

	static void  OSTMemMove(void* pDest, const void* pSource, OSTSize_t nCount);

	static OSTUInt64  OSTEndianSwapUINT64(OSTUInt64 nValue);

	static OSTUInt32  OSTEndianSwapUINT32(OSTUInt32 nValue);

	static OSTUInt16  OSTEndianSwapUINT16(OSTUInt16 nValue);

	static OSTFloat  OSTEndianSwapFLOAT(OSTFloat fValue);
};



OST_NAMESPACE_END
#endif//OST_CORE_OSTMEMORY_H