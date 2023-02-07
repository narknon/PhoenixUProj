/*******************************************************************************
The content of this file includes portions of the AUDIOKINETIC Wwise Technology
released in source code form as part of the SDK installer package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use this file in accordance with the end user license agreement provided 
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Apache License Usage

Alternatively, this file may be used under the Apache License, Version 2.0 (the 
"Apache License"); you may not use this file except in compliance with the 
Apache License. You may obtain a copy of the Apache License at 
http://www.apache.org/licenses/LICENSE-2.0.

Unless required by applicable law or agreed to in writing, software distributed
under the Apache License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
OR CONDITIONS OF ANY KIND, either express or implied. See the Apache License for
the specific language governing permissions and limitations under the License.

  Version: v2021.1.9  Build: 7847
  Copyright (c) 2006-2022 Audiokinetic Inc.
*******************************************************************************/

/**
 * \brief Wwise Authoring Plug-ins - Helper tools, potentially defined elsewhere.
 * \file AK/Wwise/Plugin/PluginHelpers.h
 */

#pragma once

#include "../../AkPlatforms.h"
#include "../../AkWwiseSDKVersion.h"

#include <memory.h>
#include <stdbool.h>		// for bool type
#include <stdint.h>			// for integer types (uint32_t, ...)

// These definitions are used throughout the Wwise plug-in system
#ifndef GUID_DEFINED		// Adapted from Windows API, to have exactly the same definition. C-compatible.
#define GUID_DEFINED
#pragma pack(push,8)
typedef struct _GUID {
	uint32_t Data1;
	uint16_t Data2;
	uint16_t Data3;
	uint8_t  Data4[8];
} GUID;
#pragma pack(pop)
#endif

#ifndef AK_WIN
#ifndef GUID_HELPERS_DEFINED
#define GUID_HELPERS_DEFINED
extern const __attribute__((weak)) GUID GUID_NULL = { 0 };

inline bool operator==(const GUID& lhs, const GUID& rhs)
{
	return memcmp(&lhs, &rhs, sizeof(GUID)) == 0;
}

inline bool operator!=(const GUID& lhs, const GUID& rhs)
{
	return !(lhs == rhs);
}
#endif
#else
#define AK_DEFINE_GUID_NULL
#endif

#ifndef MKBOOL
#define MKBOOL(cond) ((cond) ? true : false)
#endif
