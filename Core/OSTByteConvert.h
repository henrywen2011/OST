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
#ifndef OST_CORE_OSTBYTECONVERT_H
#define OST_CORE_OSTBYTECONVERT_H

#include "OSTTypes.h"
#include "OSTCommon.h"

OST_NAMESPACE_BEGIN

/** 
* @class OSTByteConvert
* @brief Byte Convert 
*/
class OSTByteConvert
{
public:
	static OSTInt16 FlipBytes(OSTInt16 bytes);

	static OSTUInt16 FlipBytes(OSTUInt16 bytes);

	static OSTInt32 FlipBytes(OSTInt32 bytes);

	static OSTUInt32 FlipBytes(OSTUInt32 bytes);

	static OSTInt64 FlipBytes(OSTInt64 bytes);

	static OSTUInt64 FlipBytes(OSTUInt64 bytes);
};

OST_NAMESPACE_END
#endif//OST_CORE_OSTBYTECONVERT_H