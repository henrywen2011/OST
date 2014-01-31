
#include <stdlib.h>
#include <string.h>

#include "OSTCommon.h"
#include "OSTMemory.h"

OST_NAMESPACE_BEGIN

void* OSTMemory::OSTMalloc( const OSTSize_t nAllocSize )
{
	return (malloc(nAllocSize));
}

void* OSTMemory::OSTMallocAligned(const OSTSize_t nAllocSize, const OSTSize_t nAlignment)
{
	return (_aligned_malloc(nAllocSize, nAlignment));
}

void* OSTMemory::OSTCalloc(const OSTSize_t nAllocNum, const OSTSize_t nAllocSize)
{
	return (calloc(nAllocNum, nAllocSize));
}

void* OSTMemory::OSTCallocAligned(const OSTSize_t nAllocNum, const OSTSize_t nAllocSize, const OSTSize_t nAlignment)
{
	void* pMemBlock = NULL;
	OSTSize_t nBlockSize = nAllocNum * nAllocSize;

	// Allocate the aligned memory block
	pMemBlock = OSTMallocAligned(nBlockSize, nAlignment);

	// If it succeeded (the returned block wasn't NULL, let's zero it)
	if (pMemBlock != NULL)
	{
		OSTMemSet(pMemBlock, 0, nBlockSize);
	}

	return (pMemBlock);
}

void* OSTMemory::OSTRealloc(void* pMemory, const OSTSize_t nAllocSize)
{
	return (realloc(pMemory, nAllocSize));
}

void* OSTMemory::OSTReallocAligned(void* pMemory, const OSTSize_t nAllocSize, const OSTSize_t nAlignment)
{
	return (_aligned_realloc(pMemory, nAllocSize, nAlignment));
}

void* OSTMemory::OSTRecalloc(void* pMemory, const OSTSize_t nAllocNum, const OSTSize_t nAllocSize)
{
	return (_recalloc(pMemory, nAllocNum, nAllocSize));
}

void OSTMemory::OSTFree(const void* pMemBlock)
{
	free ((void*)pMemBlock);
}

void OSTMemory::OSTFreeAligned(const void* pMemBlock)
{
	_aligned_free((void*)pMemBlock);
}

void OSTMemory::OSTMemCopy(void* pDest, const void* pSource, OSTSize_t nCount)
{
	memcpy(pDest, pSource, nCount);
}

OSTInt32 OSTMemory::OSTMemCmp(const void *pBuf1, const void *pBuf2, OSTSize_t nCount)
{
	return memcmp(pBuf1, pBuf2, nCount);
}

void OSTMemory::OSTMemSet(void* pDest, OSTUInt8 nValue, OSTSize_t nCount)
{
	memset(pDest, nValue, nCount);
}

void OSTMemory::OSTMemMove(void* pDest, const void* pSource, OSTSize_t nCount)
{
	memmove(pDest, pSource, nCount);
}

OST_NAMESPACE_END