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
 * \brief Wwise Authoring Plug-ins - API for general Audio Plug-in's backend (Source, Effect, Mixer).
 * \file AK/Wwise/Plugin/AudioPlugin.h
 */

#pragma once

#include "HostPropertySet.h"
#include "HostDataWriter.h"


/**
 * \brief Wwise API for general Audio Plug-in's backend.
 * 
 * \sa
 * - \ref ak_wwise_plugin_audio_plugin_instance_v1 instance type
 * - \ref AK::Wwise::Plugin::AudioPlugin C++ Interface
 * - \ref AK_WWISE_PLUGIN_AUDIO_PLUGIN_V1_ID Current ID for interface
 * - \ref AK_WWISE_PLUGIN_INTERFACE_TYPE_AUDIO_PLUGIN
 * - \ref wwiseplugin_backend
 */
struct ak_wwise_plugin_audio_plugin_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for providing audio plug-in backend services.
	using Instance = ak_wwise_plugin_audio_plugin_instance_v1;

	ak_wwise_plugin_audio_plugin_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_AUDIO_PLUGIN, 1)
	{}
#endif

	/**
	 * \brief Obtains parameters that will be written to a bank.
	 * 
	 * This is the usual function that gets overridden to provide data from the Authoring plug-in to the
	 * Sound Engine plug-in. Its goal is to retrieve data (usually from the PropertySet) and write it
	 * in the proper format and order, so the Sound Engine part can retrieve it and use it.
	 * 
	 * By design, this function is called to store data, as provided in the plug-in definition XML.
	 * 
	 * Because these can be changed at run-time, the parameter block should stay relatively small. For example, it
	 * should only provide basic members. Array sets, full sections, binary data or Object Stores might be
	 * better sent using the GetPluginData function, as the system can then ask to update only a portion
	 * of the parameters.
	 * 
	 * The design pattern, in that case, is to call GetPluginData at the end of GetBankParameters with some unique
	 * in_idParam (AK::IAkPluginParam::ALL_PLUGIN_DATA_ID) indicating that you want to send all the parameters 
	 * to the data writer.
	 * 
	 * \aknote In order to use the in_pDataWriter instance, your plugin must request the data writer
	 *         interface: ak_wwise_plugin_host_data_writer_v1. \endaknote
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform
	 * \param[in] in_pDataWriter A pointer to the data writer instance being used.
	 * \return true if successfully putting some parameters in the bank
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * - \ref wwiseplugin_propertyset
	 */
	bool(*GetBankParameters)(
		const struct ak_wwise_plugin_audio_plugin_instance_v1* in_this,
		const GUID * in_guidPlatform,
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_pDataWriter);
};

#define AK_WWISE_PLUGIN_AUDIO_PLUGIN_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_AUDIO_PLUGIN, 1)
#define AK_WWISE_PLUGIN_AUDIO_PLUGIN_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_AUDIO_PLUGIN_V1_ID(), in_pluginInfo, in_data) \
}

#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CAudioPlugin = ak_wwise_plugin_audio_plugin_v1;

		/**
		 * \brief Wwise API for general Audio Plug-in's backend.
		 * 
		 * \sa
		 * - \ref ak_wwise_plugin_audio_plugin_instance_v1 instance type
		 * - \ref ak_wwise_plugin_audio_plugin_v1 C Interface
		 * - \ref AK_WWISE_PLUGIN_AUDIO_PLUGIN_V1_ID Current ID for interface
		 * - \ref AK_WWISE_PLUGIN_INTERFACE_TYPE_AUDIO_PLUGIN
		 * - \ref wwiseplugin_backend
		 * 
		 * \aknote The \ref AK::Wwise::Plugin::RequestPropertySet and
		 * \ref AK::Wwise::Plugin::RequestWrite classes are automatically derived when
		 * providing \ref AK::Wwise::Plugin::AudioPlugin in C++. \endaknote
		 */
		class AudioPlugin : public CAudioPlugin::Instance,
			public AK::Wwise::Plugin::RequestPropertySet,
			public AK::Wwise::Plugin::RequestWrite
		{
		public:
			/**
			 * \copydoc CAudioPlugin::Instance
			 */
			using Instance = CAudioPlugin::Instance;

			/**
			 * \brief The interface type, as provided by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as provided by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_AUDIO_PLUGIN
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
			struct Interface : public CAudioPlugin
			{
				using Instance = AudioPlugin;
				Interface()
				{
					CAudioPlugin::GetBankParameters = [](
						const struct ak_wwise_plugin_audio_plugin_instance_v1* in_this,
						const GUID * in_guidPlatform,
						struct ak_wwise_plugin_host_data_writer_instance_v1* in_pDataWriter)
					{
						return (bool)static_cast<const Instance*>(in_this)->GetBankParameters(
							*in_guidPlatform,
							*static_cast<DataWriter*>(in_pDataWriter));
					};
				}
			};

			InterfacePtr GetInterfacePointer() {
				static Interface g_interface;
				return &g_interface;
			}
			CAudioPlugin::Instance* GetInstancePointer() {
				return this;
			}
			const CAudioPlugin::Instance* GetInstancePointer() const {
				return this;
			}

			AudioPlugin() :
				CAudioPlugin::Instance()
			{
			}

			virtual ~AudioPlugin() {}

			/**
			 * \brief Obtains parameters that will be written to a bank.
			 * 
			 * This is the usual function that gets overridden to provide data from the Authoring plug-in to the
			 * Sound Engine plug-in. Its goal is to retrieve data (usually from the PropertySet) and write it
			 * in the proper format and order, so the Sound Engine part can retrieve it and use it.
			 * 
			 * By design, this function is called to store data, as provided in the plug-in definition XML.
			 * 
			 * Because these can be changed at run-time, the parameter block should stay relatively small. For example, it
			 * should only provide basic members. Array sets, full sections, binary data or Object Stores might be
			 * better sent using the GetPluginData function, as the system can then ask to update only a portion
			 * of the parameters.
			 * 
			 * The design pattern, in that case, is to call GetPluginData at the end of GetBankParameters with some unique
			 * in_idParam (AK::IAkPluginParam::ALL_PLUGIN_DATA_ID) indicating that you want to send all the parameters
			 * to the data writer.
			 * 
			 * \aknote In order to use the in_pDataWriter instance, your plugin must request the data writer
			 *         interface: AK::Wwise::Plugin::RequestWrite. \endaknote
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform
			 * \param[in] in_dataWriter A reference to the data writer instance being used.
			 * \return true if successfully putting some parameters in the bank
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * - \ref wwiseplugin_propertyset
			 */
			virtual bool GetBankParameters(
				const GUID & in_guidPlatform,
				DataWriter & in_dataWriter
			) const { return false; }
		};
	} // of namespace V1

	/// Latest version of the C AudioPlugin interface.
	using CAudioPlugin = V1::CAudioPlugin;
	/// Latest version of the C++ AudioPlugin interface.
	using AudioPlugin = V1::AudioPlugin;

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(AudioPlugin);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(AudioPlugin);
} // of namespace AK::Wwise::Plugin

#endif
