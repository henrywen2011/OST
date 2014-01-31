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
#include "OSTByteConvert.h"

OST_NAMESPACE_BEGIN

OSTInt16 OSTByteConvert::FlipBytes( OSTInt16 bytes )
{
	return OSTInt16(FlipBytes(OSTUInt16(bytes)));
}

OSTUInt16 OSTByteConvert::FlipBytes( OSTUInt16 bytes )
{
	return ((bytes>>8) | (bytes<<8));
}

OSTInt32 OSTByteConvert::FlipBytes( OSTInt32 bytes )
{
	return OSTInt32(FlipBytes(OSTUInt32(bytes)));
}

OSTUInt32 OSTByteConvert::FlipBytes( OSTUInt32 bytes )
{
	return  (bytes>>24) | ((bytes<<8) & 0x00FF0000) 
		| ((bytes>>8) & 0x0000FF00) | (bytes<<24);
}

OSTInt64 OSTByteConvert::FlipBytes( OSTInt64 bytes )
{
	return OSTInt64(FlipBytes(OSTUInt64(bytes)));
}

OSTUInt64 OSTByteConvert::FlipBytes( OSTUInt64 bytes )
{
	/*OSTUInt32 hi = OSTUInt32(bytes >> 32);
	OSTUInt32 lo = OSTUInt32(bytes & 0xFFFFFFFF);

	return OSTUInt64(FlipBytes(hi)) | (OSTUInt64(FlipBytes(lo)) << 32);*/

	return ((bytes >> 56) ) | ((bytes >> 40) & 0x000000000000ff00ULL) |
		((bytes >> 24) & 0x0000000000ff0000ULL) | ((bytes >> 8 ) & 0x00000000ff000000ULL) |
		((bytes << 8 ) & 0x000000ff00000000ULL) | ((bytes << 24) & 0x0000ff0000000000ULL) |
		((bytes << 40) & 0x00ff000000000000ULL) | ((bytes << 56) );
}


OST_NAMESPACE_END