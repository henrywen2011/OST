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
#include "OSTRWMutex.h"

OST_NAMESPACE_BEGIN

OSTRWLock::OSTRWLock()
{
	pthread_mutexattr_t attr;

	if( 0 != pthread_mutexattr_init(&attr) )
		return;

	if (0 != pthread_mutex_init(&m_mutex, &attr))
	{
		pthread_mutexattr_destroy(&attr);
		throw SystemExc("cannot create mutex");
	}
	pthread_mutexattr_destroy(&attr);
}

OSTRWLock::~OSTRWLock()
{
	Unlock();
}

void OSTRWLock::ReadLock()
{
	try
	{
		pthread_mutex_lock(&m_mutex);
	}
	catch (...)
	{
		throw SystemExc("Cannot lock mutex");
	}
}

OSTBool OSTRWLock::TryReadLock()
{
	OSTInt32 rc = pthread_mutex_trylock(&m_mutex);
	if (0 == rc)
	{
		return OST_TRUE;
	}
	else if (rc == EBUSY)
	{
		return OST_FALSE;
	}
	else
	{
		throw SystemExc("Cannot lock mutex");
	}
}

void OSTRWLock::WriteLock()
{
	try
	{
		pthread_mutex_lock(&m_mutex);
	}
	catch (...)
	{
		throw SystemExc("Cannot lock mutex");
	}
}

OSTBool OSTRWLock::TryWriteLock()
{
	OSTInt32 rc = pthread_mutex_trylock(&m_mutex);
	if (0 == rc)
	{
		return OST_TRUE;
	}
	else if (rc == EBUSY)
	{
		return OST_FALSE;
	}
	else
	{
		throw SystemExc("Cannot lock mutex");
	}
}

void OSTRWLock::Unlock()
{
	pthread_mutex_unlock(&m_mutex);
}

OST_NAMESPACE_END