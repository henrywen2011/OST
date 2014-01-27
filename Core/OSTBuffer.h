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
#ifndef OST_CORE_OSTBUFFER_H
#define OST_CORE_OSTBUFFER_H

OST_NAMESPACE_BEGIN
/** 
* @class OSTBuffer
* @brief allocates a buffer of a given type and size in the constructor and
* deallocates the buffer in the destructor.
*/
template <class T>
class OSTBuffer
{
public:
	OSTBuffer(OSTSize_t size) : m_size(size), m_buffer(0)
	{
		if(size > 0)
		{
			m_buffer = new T[m_size];
		}
	}

	~OSTBuffer()
	{
		if(m_buffer)
		{
			delete[] m_buffer;
			m_buffer = 0;
		}
	}

	/**
	* @brief Resizes the buffer. 
	*
	* @param	newSize buffer size must not be 0
	* @param	preserveContent 
	*	-<em>OST_TRUE</em>old buffer is copied over to the new buffer
	*	-<em>OST_FALSE</em>not cover
	*/
	void resize(OSTSize_t newSize, OSTBool preserveContent = OST_TRUE)
	{
		if(newSize > m_size)
		{
			T* ptr = new T[newSize];
			if (preserveContent)
			{
				std::memcpy(ptr, m_buffer, m_size);
			}
			delete [] m_buffer;
			m_buffer  = ptr;
		}
		m_size = newSize;
	}

	/**
	* @brief Get the buffer size
	*
	* @return buffer size
	*/
	OSTSize_t Size() const
	{
		return m_size;
	}

	T* Begin() { return m_buffer; }
	T* End() { return m_buffer + m_size; } 

	const T* Begin() const { return m_buffer; }
	const T* End() const { return m_buffer + m_size; }

	T& operator [] (OSTSize_t index)
	{	
		if(index >= m_size)
			return 0;

		return m_buffer[index]; 
	}

	const T& operator [] (OSTSize_t index) const
	{ 
		if(index >= m_size)
			return 0;

		return m_buffer[index];
	}

private:
	OSTBuffer();
	OSTBuffer(const OSTBuffer&);
	OSTBuffer& operator = (const OSTBuffer&);

private:
	OSTSize_t m_size;
	T* m_buffer;
};

OST_NAMESPACE_END
#endif//OST_CORE_OSTBUFFER_H