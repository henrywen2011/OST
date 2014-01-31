#include "OSTCommon.h"
#include "OSTMemory.h"
#include "OSTPlatform.h"

OST_NAMESPACE_BEGIN

void* OSTMemory::OSTMalloc( const OSTSize_t nAllocSize )
{
	return (malloc(nAllocSize));
}

void* OSTMemory::OSTMallocAligned(const OSTSize_t nAllocSize, const OSTSize_t nAlignment)
{
	void* pResult = NULL;

#ifndef OST_PLATFORM_LINUX_NO_POSIX_MEMALIGN
	if (0 != posix_memalign(&pResult, nAlignment, nAllocSize))
		return NULL;
#else
	pResult = memalign(nAlignment, nAllocSize);//64 bit, 16
#endif

	return pResult;
}

void* OSTMemory::OSTCalloc(const OSTSize_t nAllocNum, const OSTSize_t nAllocSize)
{
	return (calloc(nAllocNum, nAllocSize));
}

void* OSTMemory::OSTCallocAligned(const OSTSize_t nAllocNum, const OSTSize_t nAllocSize, const OSTSize_t nAlignment)
{
	void* pMemBlock = NULL;
	OSTUInt32 nBlockSize = nAllocNum * nAllocSize;

	// Allocate the aligned memory block
	pMemBlock = OSTMallocAligned(nBlockSize, nAlignment);

	// If it succeeded (the returned block wasn't NULL, let's zero it)
	if (pMemBlock != NULL)
	{
		memset(pMemBlock, 0, nBlockSize);
	}

	return (pMemBlock);
}

void* OSTMemory::OSTRealloc(void* pMemory, const OSTSize_t nAllocSize)
{
	return (realloc(pMemory, nAllocSize));
}

void* OSTMemory::OSTReallocAligned(void* pMemory, const OSTSize_t nAllocSize, const OSTSize_t nAlignment)
{
	return NULL;
}

void* OSTMemory::OSTRecalloc(void* pMemory, const OSTSize_t nAllocNum, const OSTSize_t nAllocSize)
{
	return NULL;
}

void OSTMemory::OSTFree(const void* pMemBlock)
{
	free ((void*)pMemBlock);
}

void OSTMemory::OSTFreeAligned(const void* pMemBlock)
{
	OSTFree(pMemBlock);
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