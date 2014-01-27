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
#include "OSTBaseExc.h"
#include "OSTMutex.h"

OST_NAMESPACE_BEGIN

OSTMutex::OSTMutex(void)
{
	InitializeCriticalSectionAndSpinCount(&m_mutex, 4000);
}

OSTMutex::~OSTMutex(void)
{
	DeleteCriticalSection(&m_mutex);
}

void OSTMutex::Lock() const
{
	try
	{
		EnterCriticalSection(&m_mutex);
	}
	catch (...)
	{
		throw SystemExc("Cannot lock mutex");
	}
}

void OSTMutex::Unlock() const
{
	LeaveCriticalSection(&m_mutex);
}

OSTBool OSTMutex::TryLock()
{
	try
	{
		return (TryEnterCriticalSection(&m_mutex) != 0 ? OST_TRUE : OST_FALSE);
	}
	catch(...)
	{
	}
	throw SystemExc("Cannot lock mutex");
}

OSTBool OSTMutex::TryLock(long millisecondes)
{
	return OST_TRUE;
}

OST_NAMESPACE_END