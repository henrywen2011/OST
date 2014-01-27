#include "OSTCommon.h"
#include "OSTMemory.h"

OST_NAMESPACE_BEGIN

void* OSTMemory::OSTMalloc( const OSTSize_t nAllocSize )
{

}

void* OSTMemory::OSTMallocAligned(const OSTSize_t nAllocSize, const OSTSize_t nAlignment)
{

}

void* OSTMemory::OSTCalloc(const OSTSize_t nAllocNum, const OSTSize_t nAllocSize)
{
}

void* OSTMemory::OSTCallocAligned(const OSTSize_t nAllocNum, const OSTSize_t nAllocSize, const OSTSize_t nAlignment)
{

}

void* OSTMemory::OSTRealloc(void* pMemory, const OSTSize_t nAllocSize)
{

}

void* OSTMemory::OSTReallocAligned(void* pMemory, const OSTSize_t nAllocSize, const OSTSize_t nAlignment)
{

}

void* OSTMemory::OSTRecalloc(void* pMemory, const OSTSize_t nAllocNum, const OSTSize_t nAllocSize)
{

}

void OSTMemory::OSTFree(const void* pMemBlock)
{

}

void OSTMemory::OSTFreeAligned(const void* pMemBlock)
{

}

void OSTMemory::OSTMemCopy(void* pDest, const void* pSource, OSTSize_t nCount)
{

}

OSTInt32 OSTMemory::OSTMemCmp(const void *pBuf1, const void *pBuf2, OSTSize_t nCount)
{

}

void OSTMemory::OSTMemSet(void* pDest, OSTUInt8 nValue, OSTSize_t nCount)
{

}

void OSTMemory::OSTMemMove(void* pDest, const void* pSource, OSTSize_t nCount)
{

}

OSTUInt64 OSTMemory::OSTEndianSwapUINT64(OSTUInt64 nValue)
{

}

OSTUInt32 OSTMemory::OSTEndianSwapUINT32(OSTUInt32 nValue)
{

}

OSTUInt16 OSTMemory::OSTEndianSwapUINT16(OSTUInt16 nValue)
{

}

OSTFloat OSTMemory::OSTEndianSwapFLOAT(OSTFloat fValue)
{

}

OST_NAMESPACE_END