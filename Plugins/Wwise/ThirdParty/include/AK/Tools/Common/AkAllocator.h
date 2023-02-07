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

// AkAllocator.h

#ifndef _AK_TOOLS_COMMON_AKALLOCATOR_H
#define _AK_TOOLS_COMMON_AKALLOCATOR_H

#include <AK/SoundEngine/Common/IAkPluginMemAlloc.h>
#include <AK/Tools/Common/AkAssert.h>
#include <AK/AkPlatforms.h>

#ifdef AK_WIN
#include <cstdlib>
#endif

namespace AK
{
	// Audiokinetic Wwise namespace
	namespace Wwise
	{
		class Mallocator
			: public AK::IAkPluginMemAlloc
		{
		public:
			virtual void* Malloc(
				size_t in_uSize,
				const char*,
				AkUInt32
			) override
			{
				return malloc(in_uSize);
			}

			virtual void Free(void* in_pMemAddress) override
			{
				free(in_pMemAddress);
			}

			virtual void* Malign(
				size_t in_uSize,
				size_t in_uAlignment,
				const char*,
				AkUInt32
			) override
			{
			#ifdef AK_WIN
				return _aligned_malloc(in_uSize, in_uAlignment);
			#else
				return aligned_alloc(in_uAlignment, in_uSize);
			#endif
			}

			virtual void* Realloc(
				void* in_pMemAddress,
				size_t in_uSize,
				const char*,
				AkUInt32
			) override
			{
				return realloc(in_pMemAddress, in_uSize);
			}

			virtual void* ReallocAligned(
				void* in_pMemAddress,
				size_t in_uSize,
				size_t in_uAlignment,
				const char*,
				AkUInt32
			) override
			{
			#ifdef AK_WIN
				return _aligned_realloc(in_pMemAddress, in_uSize, in_uAlignment);
			#else
				AKASSERT(!"ReallocAligned is not supported: using realloc");
				return realloc(in_pMemAddress, in_uSize);
			#endif
			}
		};

		template<typename T>
		class SafeAllocator
		{
		public:
			SafeAllocator(AK::IAkPluginMemAlloc* in_pAlloc)
				: m_pAlloc(in_pAlloc),
				  m_pPtr(nullptr)
			{
			}

			~SafeAllocator()
			{
				if (m_pPtr)
				{
					m_pAlloc->Free(m_pPtr);
				}
			}

			T* operator->() { return m_pPtr; }
			T& operator*() { return *m_pPtr; }

			explicit operator bool() const { return m_pPtr != nullptr; }
			operator T*&() { return m_pPtr; }

		private:
			AK::IAkPluginMemAlloc* m_pAlloc;
			T* m_pPtr;
		};
	}
}

#endif // _AK_TOOLS_COMMON_AKALLOCATOR_H
