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
#ifndef OST_CORE_OSTBASICABLE_H
#define OST_CORE_OSTBASICABLE_H

#include "OSTTypes.h"

/** 
* @class Runnable
* @brief Encapsulates a Runnable task
*/
class Runnable
{
public:
	//! Destroy a Runnable object
	virtual ~Runnable() {}

	/**
	* @brief Task to be performed in another thread of execution
	*/
	virtual void Run() = 0;
};

/** 
* @class NonCopyable
* @brief Some objects kind of objects should not be copied. This is particularly true
* of objects involved in providing mutually exclusive access to something
* (e.g. Mutexes, Queues, Semaphores, etc.)
*
* Based on Dave Abrahams contribution to the Boost library.
*/
class NonCopyable
{
	/**
	* @brief Restrict the copy constructor
	*/
	NonCopyable(const NonCopyable&);

	/**
	* @brief Restrict the assignment operator
	*/
	const NonCopyable& operator=(const NonCopyable&);

protected:
	//! Create a NonCopyable object
	NonCopyable() { }
	//! Destroy a NonCopyable object
	~NonCopyable() { }
};

/**
* @class Lockable
* @brief The Lockable interface defines a common method of adding general <i>acquire-release</i> 
* semantics to an object. An <i>acquire-release</i> protocol does not necessarily imply 
* exclusive access. 
*/
class Lockable
{
public:  
	/**
	* @brief Destroy a Lockable object
	*/
    virtual ~Lockable() {}

	/**
	* @brief Acquire the Lockable object
	*/
    virtual void Acquire() = 0;

	/**
	* @brief Attempt to acquire the Lockable object
	* This method may or may not block the caller for a definite amount
	* of time. Those details are defined by specializations of this class;
	* however, this method includes a timeout value that can be used to 
	* limit the maximum amount of time that a specialization <i>could</i> block.
	*
	* @param timeout - maximum amount of time (milliseconds) this method could block
	*
	* @return 
	*   - <em>OST_TRUE</em>  if the operation completes and the Lockable is acquired before 
	*     the timeout expires. 
	*   - <em>OST_FALSE</em> if the operation times out before the Lockable can be acquired.
	*/
    virtual OSTBool TryAcquire(unsigned long timeout) = 0;

	/**
	* @brief Release the Lockable object
	*/
    virtual void Release() = 0;
};

/**
* @class Waitable
* @brief The Waitable interface defines a common method of adding generic
* <i>wait</i> semantics to a class. 
*/
class Waitable
{
public:
	//! Destroy a Waitable object.  
    virtual ~Waitable() {}

    /**
     * @brief Waiting on an object will generally cause the calling thread to be blocked
     * for some indefinite period of time. The thread executing will not proceed
     * any further until the Waitable object releases it unless or an exception
     * is thrown.
     */
    virtual void wait() = 0;

    /**
     * @brief Waiting on an object will generally cause the calling thread to be blocked
     * for some indefinite period of time. The thread executing will not proceed
     * any further until the Waitable object releases it unless or an exception
     * is thrown.
     *
     * @param  timeout  maximum amount of time, in milliseconds, to spend waiting.
     *
     * @return 
     *   - <em>OST_TRUE</em> if the set of tasks being wait for complete before 
     *                   <i>timeout</i> milliseconds elapse.
     *   - <em>OST_FALSE</em> othewise.
     */
    virtual OSTBool wait(unsigned long timeout) = 0;
};

#endif//OST_CORE_OSTBASICABLE_H