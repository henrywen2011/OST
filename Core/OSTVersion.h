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
#ifndef OST_CORE_OSTVERSION_H
#define OST_CORE_OSTVERSION_H

#include "OSTPlatform.h"

#define OST_VERSION_MAJOR			1
#define OST_VERSION_MINOR			0
#define OST_VERSION_MAINTENANCE		0
#define OST_VERSION_BUILD			1

/** OpenST version (in brief string format): "Major.Minor.Maintenance (Build)" */ 
#define OST_BRIEF_VERSION_STRING					\
	OST_STRINGIFY(OST_VERSION_MAJOR) "."			\
	OST_STRINGIFY(OST_VERSION_MINOR) "."			\
	OST_STRINGIFY(OST_VERSION_MAINTENANCE)			\
	" (Build " OST_STRINGIFY(OST_VERSION_BUILD) ")"

/** OpenST version (in numeric format): (OpenST major version * 100000000 + OpenNI minor version * 1000000 + OpenST maintenance version * 10000 + OpenST build version). */
#define OST_VERSION (OST_VERSION_MAJOR * 100000000 + OST_VERSION_MINOR * 1000000 + OST_VERSION_MAINTENANCE * 10000 + OST_VERSION_BUILD)
#define OST_CREATE_API_VERSION(major, minor) ((major)*1000 + (minor))
#define OST_API_VERSION OST_CREATE_API_VERSION(OST_VERSION_MAJOR, OST_VERSION_MINOR)

/** OpenST version (in string format): "Major.Minor.Maintenance.Build-Platform (MMM DD YYYY HH:MM:SS)". */ 
#define OST_VERSION_STRING						\
	OST_BRIEF_VERSION_STRING  "-"				\
	OST_PLATFORM_STRING " (" OST_TIMESTAMP ")"

typedef struct _OSTVersion
{
	/** Major version number */
	int major;
	/** Minor version number */
	int minor;
	/** Maintenance build number */
	int maintenance;
	/** Build number */
	int build;
}OSTVersion;

#endif//OST_CORE_OSTVERSION_H