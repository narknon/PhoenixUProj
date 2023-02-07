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

/// \file
/// Memory allocation macros for Wwise sound engine plug-ins.

#ifndef _IAKPLUGINMEMALLOC_H_
#define _IAKPLUGINMEMALLOC_H_

#include <AK/SoundEngine/Common/AkTypes.h>
#include <AK/SoundEngine/Common/AkMemoryMgr.h>

namespace AK
{
	/// Interface to memory allocation
	/// \akcaution SDK users should never call these function directly, but use memory allocation macros instead. \endakcaution
	/// \sa
	/// - \ref fx_memory_alloc
	class IAkPluginMemAlloc
	{
	protected:
		/// Virtual destructor on interface to avoid warnings.
		virtual ~IAkPluginMemAlloc(){}

	public:

		/// Allocate memory.
		/// \return A pointer to the newly-allocated memory.
		/// \sa
		/// - \ref fx_memory_alloc
		virtual void * Malloc(
			size_t	in_uSize,				///< Allocation size in bytes
			const char* in_pszFile,			///< Allocation file name (for tracking purposes, unused in Release)
			AkUInt32 		in_uLine		///< Allocation line number (for tracking purposes, unused in Release)
			) = 0;

		/// Free allocated memory.
		/// \sa
		/// - \ref fx_memory_alloc
		virtual void Free(
			void *	in_pMemAddress			///< Allocated memory start address			
			) = 0;

		/// Allocate memory.
		/// \return A pointer to the newly-allocated memory.
		/// \sa
		/// - \ref fx_memory_alloc
		virtual void * Malign(
			size_t	in_uSize,				///< Allocation size in bytes
			size_t	in_uAlignment,			///< Required alignment in bytes
			const char* in_pszFile,			///< Allocation file name (for tracking purposes, unused in Release)
			AkUInt32 		in_uLine		///< Allocation line number (for tracking purposes, unused in Release)
			) = 0;

		/// Reallocated memory.
		/// \return A pointer to the reallocated memory.
		/// \sa
		/// - \ref fx_memory_alloc
		virtual void * Realloc(
			void *	in_pMemAddress,			///< Allocated memory start address
			size_t	in_uSize,				///< Allocation size in bytes
			const char* in_pszFile,			///< Allocation file name (for tracking purposes, unused in Release)
			AkUInt32 		in_uLine		///< Allocation line number (for tracking purposes, unused in Release)
			) = 0;

		/// Reallocated memory.
		/// \return A pointer to the reallocated memory.
		/// \sa
		/// - \ref fx_memory_alloc
		virtual void * ReallocAligned(
			void *	in_pMemAddress,			///< Allocated memory start address
			size_t	in_uSize,				///< Allocation size in bytes
			size_t	in_uAlignment,			///< Required alignment in bytes
			const char* in_pszFile,			///< Allocation file name (for tracking purposes, unused in Release)
			AkUInt32 		in_uLine		///< Allocation line number (for tracking purposes, unused in Release)
			) = 0;
	};
}

	AkForceInline void * operator new( size_t size, AK::IAkPluginMemAlloc * in_pAllocator, const char * szFile, AkUInt32 ulLine) throw()
	{
		return in_pAllocator->Malloc( size, szFile, ulLine );
	}

	AkForceInline void* operator new(size_t size, AK::IAkPluginMemAlloc* in_pAllocator) throw()
	{
		return in_pAllocator->Malloc(size, NULL, 0);
	}

	AkForceInline void operator delete( void *, AK::IAkPluginMemAlloc *, const char *, AkUInt32 ) throw() {}
	AkForceInline void operator delete( void *, AK::IAkPluginMemAlloc * ) throw() {}

	/// Macro used to allocate objects.
	/// \param _allocator Memory allocator interface.
	/// \param _what Desired object type.
	/// \return A pointer to the newly-allocated object.
	/// \aknote Use AK_PLUGIN_DELETE() for memory allocated with this macro. \endaknote
	/// \sa
	/// - \ref fx_memory_alloc
	/// - AK_PLUGIN_DELETE()
	#define AK_PLUGIN_NEW( _allocator, _what )							new( ( _allocator ), __FILE__, __LINE__ ) _what
	

	/// Macro used to allocate memory
	/// \param _allocator Memory allocator interface.
	/// \param _size Requested size in bytes.
	/// \return A void pointer to the the allocated memory.
	/// \aknote Use AK_PLUGIN_FREE() for memory allocated with this macro. \endaknote
	/// \sa
	/// - \ref fx_memory_alloc
	/// - AK_PLUGIN_FREE()	
	#define AK_PLUGIN_ALLOC( _allocator, _size )						( _allocator )->Malloc( ( _size ), __FILE__, __LINE__ )

	/// Macro used to allocate memory with an alignment
	/// \param _allocator Memory allocator interface.
	/// \param _size Requested size in bytes.
	/// \param _align Requested alignment of allocation
	/// \return A void pointer to the the allocated memory.
	/// \aknote Use AK_PLUGIN_FREE() for memory allocated with this macro. \endaknote
	/// \sa
	/// - \ref fx_memory_alloc
	/// - AK_PLUGIN_FREE()	
	#define AK_PLUGIN_ALLOC_ALIGN( _allocator, _size, _align )			( _allocator )->Malign( ( _size ), ( _align ), __FILE__, __LINE__ )

	/// Macro used to reallocate memory
	/// \param _allocator Memory allocator interface.
	/// \param _pmem Start of allocated memory.
	/// \param _size Requested size in bytes.
	/// \return A void pointer to the the reallocated memory.
	/// \aknote Use AK_PLUGIN_FREE() for memory allocated with this macro. \endaknote
	/// \sa
	/// - \ref fx_memory_alloc
	/// - AK_PLUGIN_FREE()
	#define AK_PLUGIN_REALLOC( _allocator, _pmem, _size )	( _allocator )->Realloc( ( _pmem ), ( _size ), __FILE__, __LINE__ )

	/// Macro used to reallocate memory with an alignment
	/// \param _allocator Memory allocator interface.
	/// \param _pmem Start of allocated memory.
	/// \param _size Requested size in bytes.
	/// \param _align Requested alignment of allocation
	/// \return A void pointer to the the reallocated memory.
	/// \aknote Use AK_PLUGIN_FREE() for memory allocated with this macro. \endaknote
	/// \sa
	/// - \ref fx_memory_alloc
	/// - AK_PLUGIN_FREE()
	#define AK_PLUGIN_REALLOC_ALIGN( _allocator, _pmem, _size, _align )	( _allocator )->ReallocAligned( ( _pmem ), ( _size ), ( _align ), __FILE__, __LINE__ )


/// Macro used to delete objects.
/// \param in_pAllocator Memory allocator interface.
/// \param in_pObject A pointer to the allocated object.
/// \sa
/// - \ref fx_memory_alloc
/// - AK_PLUGIN_NEW()
template <class T>
AkForceInline void AK_PLUGIN_DELETE( AK::IAkPluginMemAlloc * in_pAllocator, T * in_pObject )
{
	if ( in_pObject )
	{
		in_pObject->~T();
		in_pAllocator->Free( in_pObject );
	}
}

/// Macro used to free memory.
/// \param _allocator Memory allocator interface.
/// \param _pvmem A void pointer to the allocated memory.
/// \sa
/// - \ref fx_memory_alloc
/// - AK_PLUGIN_ALLOC()
#define AK_PLUGIN_FREE( _allocator, _pvmem )	( _allocator )->Free( ( _pvmem ) )

/// Allocator for plugin-friendly arrays (see AkArray).
/// Usage: Initialize the array with Init(AK::IAkPluginMemAlloc* in_pAllocator), passing it the memory allocator received from the host. Then use normally.
class AkPluginArrayAllocator
{
public:
	AkForceInline AkPluginArrayAllocator() : m_pAllocator(NULL) {}
	AkForceInline void Init(AK::IAkPluginMemAlloc* in_pAllocator) { m_pAllocator = in_pAllocator; }
protected:
	AkForceInline void* Alloc(size_t in_uSize) { return AK_PLUGIN_ALLOC(m_pAllocator, in_uSize); }
	AkForceInline void* ReAlloc(void* in_pCurrent, size_t in_uOldSize, size_t in_uNewSize) { return AK_PLUGIN_REALLOC(m_pAllocator, in_pCurrent, in_uNewSize); }
	AkForceInline void Free(void* in_pAddress) { AK_PLUGIN_FREE(m_pAllocator, in_pAddress); }
	AkForceInline void TransferMem(void*& io_pDest, AkPluginArrayAllocator& in_src, void* in_pSrc)
	{
#ifdef AKASSERT
		AKASSERT(io_pDest == NULL);
#endif
		io_pDest = in_pSrc;
		m_pAllocator = in_src.GetAllocator();
	}
	AkForceInline AK::IAkPluginMemAlloc* GetAllocator() { return m_pAllocator; }
private:
	AK::IAkPluginMemAlloc* m_pAllocator;
};

#endif // _IAKPLUGINMEMALLOC_H_
