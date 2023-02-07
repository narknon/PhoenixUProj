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
 
#ifndef _AK_MIXERINPUTMAP_H_
#define _AK_MIXERINPUTMAP_H_

#include <AK/SoundEngine/Common/AkTypes.h>

#include <AK/SoundEngine/Common/IAkPluginMemAlloc.h>
#include <AK/Tools/Common/AkArray.h>
#include <AK/SoundEngine/Common/IAkPlugin.h>

/// Collection class to manage inputs in mixer plugins.
/// The inputs are identified by their context. The type of data attached to it is the template argument USER_DATA.
/// The collection performs allocation/deallocation of user data via AK_PLUGIN_NEW/DELETE().
/// Usage
/// 
/// // Init 
/// AkMixerInputMap<void*, MyStruct> m_mapInputs;
/// m_mapInputs.Init( in_pAllocator );	// in_pAllocator passed at plugin init.
///
/// // Add an input.
/// m_mapInputs.AddInput( in_pInput );	// void * in_pInput 
/// 
/// // Find an input
/// MyStruct * pInput = m_mapInputs.Exists( in_pInputContext );	// void * in_pInputContext passed to ConsumeInput()
///
/// // Iterate through inputs.
///	AkMixerInputMap<MyStruct>::Iterator it = m_mapInputs.End();
///	while ( it != m_mapInputs.End() )
///	{
///		MyStruct * pInput = (*it).pUserData;
///		...
///		++it;
///	}

/// Structure of an entry in the AkMixerInputMap map.
template <class KEY, class USER_DATA>
struct AkInputMapSlot
{
	KEY				key;		/// Key.
	USER_DATA *		pUserData;	/// User data. Here we have a buffer. Other relevant info would be the game object position and input parameters of the previous frame.

	AkInputMapSlot() : key( NULL ), pUserData( NULL ) {}
	bool operator ==(const AkInputMapSlot& in_Op) const { return (key == in_Op.key); }
};

/// AkMixerInputMap: Map of inputs (identified with AK::IAkMixerInputContext *) to user-defined blocks of data.
template <class KEY, class USER_DATA>
class AkMixerInputMap : public AkArray<AkInputMapSlot<KEY, USER_DATA>, const AkInputMapSlot<KEY, USER_DATA>&, AkPluginArrayAllocator>
{
public:
	typedef AkArray<AkInputMapSlot<KEY, USER_DATA>, const AkInputMapSlot<KEY, USER_DATA>&, AkPluginArrayAllocator> BaseClass;

	/// Returns the user data associated with given input context. Returns NULL if none found.
	USER_DATA * Exists( KEY in_key )
	{
		typename AkArray<AkInputMapSlot<KEY, USER_DATA>, const AkInputMapSlot<KEY, USER_DATA>&, AkPluginArrayAllocator>::Iterator it = FindEx(in_key);
		return ( it != BaseClass::End() ) ? (*it).pUserData : NULL;
	}

	/// Adds an input with new user data.
	USER_DATA * AddInput(KEY in_key)
	{
		typename AkArray<AkInputMapSlot<KEY, USER_DATA>, const AkInputMapSlot<KEY, USER_DATA>&, AkPluginArrayAllocator>::Iterator it = FindEx(in_key);
		if ( it != BaseClass::End() )
			return (*it).pUserData;
		else
		{
			AkInputMapSlot<KEY, USER_DATA> * pSlot = AkArray<AkInputMapSlot<KEY, USER_DATA>, const AkInputMapSlot<KEY, USER_DATA>&, AkPluginArrayAllocator>::AddLast();
			if ( pSlot )
			{
				pSlot->pUserData = AK_PLUGIN_NEW( AkPluginArrayAllocator::GetAllocator(), USER_DATA );
				if ( pSlot->pUserData )
				{
					pSlot->key = in_key;
					return pSlot->pUserData;
				}
				BaseClass::RemoveLast();
			}
		}
		return NULL;
	}

	/// Removes an input and destroys its associated user data.
	bool RemoveInput(KEY in_key)
	{
		typename AkArray<AkInputMapSlot<KEY, USER_DATA>, const AkInputMapSlot<KEY, USER_DATA>&, AkPluginArrayAllocator>::Iterator it = FindEx( in_key );
		if ( it != BaseClass::End() )
		{
			AKASSERT( (*it).pUserData );
			AK_PLUGIN_DELETE( AkPluginArrayAllocator::GetAllocator(), (*it).pUserData );
			BaseClass::EraseSwap( it );
			return true;
		}
		return false;
	}

	/// Erase the specified iterator in the array. but it does not guarantee the ordering in the array.
	typename AkArray<AkInputMapSlot<KEY, USER_DATA>, const AkInputMapSlot<KEY, USER_DATA>&, AkPluginArrayAllocator>::Iterator EraseSwap(typename AkArray<AkInputMapSlot<KEY, USER_DATA>, const AkInputMapSlot<KEY, USER_DATA>&, AkPluginArrayAllocator>::Iterator& in_rIter)
	{
		if ((*in_rIter).pUserData)
		{
			AK_PLUGIN_DELETE(AkPluginArrayAllocator::GetAllocator(), (*in_rIter).pUserData);
		}
		return BaseClass::EraseSwap(in_rIter);
	}

	/// Terminate array.
	void Term()
	{
		if ( BaseClass::m_pItems )
		{
			RemoveAll();
			AkPluginArrayAllocator::Free( BaseClass::m_pItems );
			BaseClass::m_pItems = 0;
			BaseClass::m_ulReserved = 0;
		}
	}

	/// Finds an item in the array.
	typename AkArray<AkInputMapSlot<KEY, USER_DATA>, const AkInputMapSlot<KEY, USER_DATA>&, AkPluginArrayAllocator>::Iterator FindEx( KEY in_key ) const
	{
		AkInputMapSlot<KEY, USER_DATA> mapSlot;
		mapSlot.key = in_key;
		return BaseClass::FindEx( mapSlot );
	}

	/// Removes and destroys all items in the array.
	void RemoveAll()
	{
		for ( typename AkArray<AkInputMapSlot<KEY, USER_DATA>, const AkInputMapSlot<KEY, USER_DATA>&, AkPluginArrayAllocator>::Iterator it = BaseClass::Begin(), itEnd = BaseClass::End(); it != itEnd; ++it )
		{
			AKASSERT( (*it).pUserData );
			AK_PLUGIN_DELETE( AkPluginArrayAllocator::GetAllocator(), (*it).pUserData );
			(*it).~AkInputMapSlot();
		}
		BaseClass::m_uLength = 0;
	}
};

#endif // _AK_MIXERINPUTMAP_H_
