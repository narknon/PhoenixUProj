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
 * \brief Wwise Authoring Plug-ins - A single instantiatable plug-in interface.
 * \file AK/Wwise/Plugin/PluginInterfaceArrayItem.h
 */

#pragma once

#include "PluginBaseInterface.h"

/**
 * \brief A single instantiatable plug-in interface.
 * 
 * The goal of the ak_wwise_plugin_interface_array_item is to provide both the static m_interface, as well as the
 * dynamic m_instance
 * 
 */
struct ak_wwise_plugin_interface_array_item
{
	/**
	 * \brief The interface. Should be identical for every instance of this DLL.
	 * 
	 * Filled in the static array by plug-in. Requests statically filled or nulled before Instantiate by host.
	 */
	ak_wwise_plugin_interface_ptr m_interface;

	/**
	 * \brief That particular instance.
	 * 
	 * Filled before Instantiate by host, or by Instantiate by plug-in.
	 */
	ak_wwise_plugin_instance_ptr m_instance;

#ifdef __cplusplus
	constexpr inline ak_wwise_plugin_interface_array_item(ak_wwise_plugin_interface_ptr in_interface = nullptr, ak_wwise_plugin_instance_ptr in_instance = nullptr) :
		m_interface(in_interface),
		m_instance(in_instance)
	{
	}
#endif
};

#define AK_WWISE_PLUGIN_INTERFACE_ARRAY_ITEM_CTOR() \
{ \
	.m_interface = 0, \
	.m_instance = 0 \
}
#define AK_WWISE_PLUGIN_INTERFACE_ARRAY_ITEM_CTOR_INTERFACE(/* ak_wwise_plugin_interface_ptr */ in_interface) \
{ \
	.m_interface = in_interface, \
	.m_instance = 0 \
}
#define AK_WWISE_PLUGIN_INTERFACE_ARRAY_ITEM_CTOR_INSTANCE(/* ak_wwise_plugin_interface_ptr */ in_interface, /* ak_wwise_plugin_instance_ptr */ in_instance) \
{ \
	.m_interface = in_interface, \
	.m_instance = (void*)in_instance \
}
