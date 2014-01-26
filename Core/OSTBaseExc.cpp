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

#include <stdlib.h>

OST_NAMESPACE_BEGIN

namespace 
{
	StackTracer g_currentStackTracer = 0;
} // namespace

void SetStackTracer (StackTracer stackTracer)
{
	g_currentStackTracer = stackTracer;
}

StackTracer GetStackTracer ()
{
	return g_currentStackTracer;
}

OSTBaseExc::OSTBaseExc( const std::string& msg ) : std::string (msg)
	, m_stackTrace (g_currentStackTracer ? g_currentStackTracer() : "")
{
}

OSTBaseExc::OSTBaseExc( const char* msg ) : std::string (msg ? msg : "")
	, m_stackTrace (g_currentStackTracer ? g_currentStackTracer() : "")
{
}

OSTBaseExc::OSTBaseExc( std::stringstream &msg ) : std::string (msg.str())
	, m_stackTrace (g_currentStackTracer ? g_currentStackTracer() : "")
{
}

OSTBaseExc::~OSTBaseExc() throw()
{
	//empty
}

OSTBaseExc& OSTBaseExc::assign( std::stringstream &msg )
{
	std::string::assign (msg.str());
	return *this;
}

OSTBaseExc& OSTBaseExc::assign( const char* msg )
{
	std::string::assign(msg);
	return *this;
}

OSTBaseExc& OSTBaseExc::operator=( std::stringstream &msg )
{
	return assign(msg);
}

OSTBaseExc& OSTBaseExc::operator=( const char *msg )
{
	return assign(msg);
}

OSTBaseExc& OSTBaseExc::operator=( const OSTBaseExc& exc )
{
	if(this != &exc)
	{
		this->m_stackTrace = exc.m_stackTrace;
	}
	return *this;
}

OSTBaseExc& OSTBaseExc::append( std::stringstream &msg )
{
	std::string::append (msg.str());
	return *this;
}

OSTBaseExc& OSTBaseExc::append( const char* msg )
{
	std::string::append(msg);
	return *this;
}

OSTBaseExc& OSTBaseExc::operator+=( std::stringstream &msg )
{
	return append (msg);
}

OSTBaseExc& OSTBaseExc::operator+=( const char *msg )
{
	return append(msg);
}

const char* OSTBaseExc::what() const throw()
{
	return c_str();
}

const std::string& OSTBaseExc::StackTrace() const
{
	return m_stackTrace;
}

OST_NAMESPACE_EDN