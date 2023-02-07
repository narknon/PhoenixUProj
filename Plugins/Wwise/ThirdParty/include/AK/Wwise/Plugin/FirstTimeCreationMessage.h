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
 * \brief Wwise Authoring Plug-ins - Plug-in that provides a special usage message when first instantiated.
 * \file AK/Wwise/Plugin/FirstTimeCreationMessage.h
 */

#pragma once

#include "PluginInfoGenerator.h"


/**
 * \brief Plug-in that provides a special usage message when first instantiated.
 */
struct ak_wwise_plugin_first_time_creation_message_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for providing a message shown the first time an instance is created.
	using Instance = ak_wwise_plugin_first_time_creation_message_instance_v1;

	ak_wwise_plugin_first_time_creation_message_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_FIRST_TIME_CREATION_MESSAGE, 1)
	{}
#endif

	/**
	 * \brief Returns a unique key used in the .wproj to indicate whether the licensing message was shown.
	 * 
	 * The key should be representative of the plug-in or plug-in family, as well as user readable. Even if a GUID
	 * would be unique, it would not be helpful to the user.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return Null-terminated string uniquely representing this plug-in or plug-in family.
	 */
	const char*(*GetKey)(const struct ak_wwise_plugin_first_time_creation_message_instance_v1* in_this);

	/**
	 * \brief Returns a unique creation message shown to the user.
	 * 
	 * Shown when the plug-in is first created and the key is not present in the .wproj yet.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return Null-terminated string containing the text to show to the end user.
	 */
	const char*(*GetCreationMessage)(const struct ak_wwise_plugin_first_time_creation_message_instance_v1* in_this);
};


#define AK_WWISE_PLUGIN_FIRST_TIME_CREATION_MESSAGE_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_FIRST_TIME_CREATION_MESSAGE, 1)
#define AK_WWISE_PLUGIN_FIRST_TIME_CREATION_MESSAGE_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_FIRST_TIME_CREATION_MESSAGE_V1_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CFirstTimeCreationMessage = ak_wwise_plugin_first_time_creation_message_v1;
		class FirstTimeCreationMessage : public CFirstTimeCreationMessage::Instance
		{
		public:
			/**
			 * \copydoc CFirstTimeCreationMessage::Instance
			 */
			using Instance = CFirstTimeCreationMessage::Instance;

			/**
			 * \brief The interface type, as provided by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as provided by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_FIRST_TIME_CREATION_MESSAGE
			};
			/**
			 * \brief The interface version, as provided by this plug-in.
			 */
			enum : InterfaceVersion
			{
				/**
				 * \brief The interface version, as provided by this plug-in.
				 */
				k_interfaceVersion = 1
			};

			/**
			 * \brief The C interface, fulfilled by your plug-in.
			 */
			struct Interface : public CFirstTimeCreationMessage
			{
				using Instance = FirstTimeCreationMessage;
				Interface()
				{
					CFirstTimeCreationMessage::GetKey = [](const struct ak_wwise_plugin_first_time_creation_message_instance_v1* in_this) { return static_cast<const Instance*>(in_this)->GetKey(); };
					CFirstTimeCreationMessage::GetCreationMessage = [](const struct ak_wwise_plugin_first_time_creation_message_instance_v1* in_this) { return static_cast<const Instance*>(in_this)->GetCreationMessage(); };
				}
			};

			InterfacePtr GetInterfacePointer() {
				static Interface g_interface;
				return &g_interface;
			}
			CFirstTimeCreationMessage::Instance* GetInstancePointer() {
				return this;
			}
			const CFirstTimeCreationMessage::Instance* GetInstancePointer() const {
				return this;
			}

			FirstTimeCreationMessage() :
				CFirstTimeCreationMessage::Instance()
			{
			}

			virtual ~FirstTimeCreationMessage() {}

			/**
			 * \brief Returns a unique key used in the .wproj to indicate whether the licensing message was shown.
			 * 
			 * The key should be representative of the plug-in or plug-in family, as well as user readable. Even if a GUID
			 * would be unique, it would not be helpful to the user.
			 * 
			 * \return Null-terminated string uniquely representing this plug-in or plug-in family.
			 */
			virtual const char* GetKey() const = 0;

			/**
			 * \brief Returns a unique creation message shown to the user.
			 * 
			 * Shown when the plug-in is first created and the key is not present in the .wproj yet.
			 * 
			 * \return Null-terminated string containing the text to show to the end user.
			 */
			virtual const char* GetCreationMessage() const = 0;
		};
	} // of namespace V1

	/// Latest version of the C FirstTimeCreationMessage interface.
	using CFirstTimeCreationMessage = V1::CFirstTimeCreationMessage;
	/// Latest version of the C++ FirstTimeCreationMessage interface.
	using FirstTimeCreationMessage = V1::FirstTimeCreationMessage;

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(FirstTimeCreationMessage);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(FirstTimeCreationMessage);
} // of namespace AK::Wwise::Plugin

#endif
