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
#ifndef OST_CORE_OSTRWMUTEX_H
#define OST_CORE_OSTRWMUTEX_H

#include "OSTTypes.h"
#include "OSTCommon.h"
#include "OSTPlatform.h"
#include "OSTBasicable.h"

#if (OST_PLAFORM == OST_PLATFORM_WIN32)
#	include <Windows.h>
#else
#	include <pthread>
#endif

OST_NAMESPACE_BEGIN

/** 
* @class OSTRWLock
* @brief A reader writer lock allows multiple concurrent readers or one exclusive writer.
*/
class OSTRWLock
{
public:
	OSTRWLock();
	~OSTRWLock();

	/**
	* @brief Acquires a read lock. If another thread currently holds a write lock
	* waits until the write lock is released
	*/
	void ReadLock();

	/**
	* @brief Tries to acquire a read lock. Immediately returns true if successful, or
	* false if another thread currently holds a write lock.
	*
	* @return 
	*	-<em>OST_TURE</em>successful
	*	-<em>OST_FALSE</em>otherwise
	*/
	OSTBool TryReadLock();

	/**
	* @brief Acquires a read lock. If one or more other threads currently hold 
	* locks, waits until all locks are released. The results are undefined
	* if the same thread already holds a read or write lock
	*/
	void WriteLock();

	/**
	* @brief Tries to acquire a write lock. Immediately returns true if successful, or
	* false if another thread currently holds a write lock.
	*
	* @return 
	*	-<em>OST_TURE</em>successful
	*	-<em>OST_FALSE</em>otherwise
	*/
	OSTBool TryWriteLock();

	/**
	* @brief Releases the read or write lock.
	*/	
	void Unlock();

private:
	OSTRWLock(const OSTRWLock&);
	OSTRWLock& operator= (const OSTRWLock&);

private:

#if (OST_PLAFORM == OST_PLATFORM_WIN32)
	HANDLE   m_mutex;
	HANDLE   m_readEvent;
	HANDLE   m_writeEvent;
	unsigned m_readers;
	unsigned m_writersWaiting;
	unsigned m_writers;
#elif (OST_PLAFORM == OST_PLATFORM_ANDROID)
	pthread_mutex_t m_mutex;
#else
	pthread_rwlock_t m_rwl;
#endif
};

OST_NAMESPACE_END

#endif//OST_CORE_OSTRWMUTEX_H