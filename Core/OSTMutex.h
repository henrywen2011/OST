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
#ifndef OST_CORE_OSTMUTEX_H
#define OST_CORE_OSTMUTEX_H

#include "OSTTypes.h"
#include "OSTPlatform.h"
#include "OSTBasicable.h"

#if (OST_PLAFORM == OST_PLATFORM_WIN32)
typedef CRITICAL_SECTION OST_MUTEX_SECTION;
#else
#include <pthread>
typedef pthread_mutex_t  OST_MUTEX_SECTION;
#endif

OST_NAMESPACE_BEGIN
/** 
* @class OSTMutex
* @brief A Mutex (mutual exclusion) is a synchronization mechanism used to control
* access to a shared resourcein a concurrent (multithreaded) scenario.
*/
class OSTMutex : public NonCopyable
{
public:
	OSTMutex(void);
	~OSTMutex(void);

	/**
	* @brief Locks the OSTMutex. Blocks if the OSTMutex is held by another thread.
	*/
	void Lock() const;

	/**
	* @brief Unlocks the mutex so that it can be acquired by other threads.
	*/
	void Unlock() const;

	/**
	* @brief Tries to lock the mutex. 
	* @return 
	*	-<em>OST_FALSE</em> if the mutex is already held by another thread
	*	-<em>OST_TRUE</em> otherwise.
	*/
	OSTBool TryLock();

	/**
	* @brief Locks the mutex. Blocks up to the given number of milliseconds
	* if the mutex is held by another thread.
	* Performance Note: On most platforms (including Windows), this member function is 
	* implemented using a loop calling (the equivalent of) tryLock() and Thread::sleep().
	* On POSIX platforms that support pthread_mutex_timedlock(), this is used.
	*
	* @return
	*	- <em>OST_TRUE</em> if the mutex was successfully locked.
	*	- <em>OST_FALSE</em> otherwise.
	*/
	OSTBool TryLock(long millisecondes);
	
private:
	mutable OST_MUTEX_SECTION m_mutex;
};

/** 
* @class AutoLock
* @brief Using the AutoLock class is the preferred way to automatically
* lock and unlock a mutex.
*/
class AutoLock
{
public:
	AutoLock(const OSTMutex& mutex, OSTBool autolocked = OST_TRUE) : m_mutex(mutex), m_locked(autolocked)
	{
		if(autolocked)
		{
			m_mutex.Lock();
			m_locked = autolocked;
		}		
	};

	~AutoLock()
	{
		if(m_locked)
		{
			m_mutex.Unlock();
		}
	};

private:
	AutoLock(const AutoLock&);
	AutoLock& operator = (const AutoLock&);

private:
	const OSTMutex& m_mutex;
	OSTBool			m_locked;
};

/** 
* @class AutoUnLock
* @brief Using the AutoUnLock class is the preferred way to automatically
* lock and unlock a mutex.
*/
class AutoUnLock
{
public:
	AutoUnLock(const OSTMutex& mutex, OSTBool unlocked = OST_TRUE) : m_mutex(mutex), m_unlocked(unlocked)
	{
		if(m_unlocked)
		{
			m_mutex.Unlock();
		}
	}
	
	~AutoUnLock()
	{
		m_mutex.Lock();
	}

private:
	AutoUnLock(const AutoUnLock&);
	AutoUnLock& operator = (const AutoUnLock&);

private:
	const OSTMutex&		m_mutex;
	OSTBool				m_unlocked;
};

#define LOCK(mutex)		AutoLock	locker(mutex)
#define UNLOCK(mutex)	AutoUnLock	locker(mutex)

OST_NAMESPACE_END

#endif//OST_CORE_OSTMUTEX_H