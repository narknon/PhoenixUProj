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
 * \brief Wwise Authoring Plug-ins - Definition of a plug-in, as stored in a container.
 * \file AK/Wwise/Plugin/PluginMFCWindows.h
 */

#pragma once

#include "PluginInterfaceArrayItem.h"

#pragma pack(push, 4)
struct ak_wwise_plugin_info
{
	struct ak_wwise_plugin_info* m_next;

	const AkUInt32* m_companyId;
	const AkUInt32* m_pluginId;
	const AkPluginType* m_pluginType;
	uint32_t m_pluginFlags;

	AK::PluginRegistration* m_pluginRegistration;

	// Member functions
	
	// Instantiation of a plug-in interface by host
	struct ak_wwise_plugin_interface_array_item*(*Instantiate)(struct ak_wwise_plugin_info* in_pluginInfo);

	// 
	void(*Disembody)(struct ak_wwise_plugin_interface_array_item* in_instance);

	size_t m_arraySize;
	struct ak_wwise_plugin_interface_array_item* m_interfaces;

#ifdef __cplusplus
	ak_wwise_plugin_info(
		const AkUInt32* in_companyId,
		const AkUInt32* in_pluginId,
		const AkPluginType* in_pluginType,
		uint32_t in_pluginFlags,
		AK::PluginRegistration* in_pluginRegistration,
		decltype(Instantiate) in_Instantiate,
		decltype(Disembody) in_Disembody,
		size_t in_arraySize,
		ak_wwise_plugin_interface_array_item* in_interfaces) :
		m_next(nullptr),
		m_companyId(in_companyId),
		m_pluginId(in_pluginId),
		m_pluginType(in_pluginType),
		m_pluginFlags(in_pluginFlags),
		m_pluginRegistration(in_pluginRegistration),
		Instantiate(in_Instantiate),
		Disembody(in_Disembody),
		m_arraySize(in_arraySize),
		m_interfaces(in_interfaces)
	{}
#endif
};
#pragma pack(pop)