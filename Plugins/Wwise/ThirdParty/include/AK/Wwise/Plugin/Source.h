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
 * \brief Wwise Authoring Plug-ins - API specific for source plug-in.
 * \file AK/Wwise/Plugin/Source.h
 */

#pragma once

#include "PluginInfoGenerator.h"

/**
 * \brief API specific for source plug-in.
 * 
 * This must be implemented for each source plug-in that is exposed in Wwise.
 * 
 */
struct ak_wwise_plugin_source_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for providing source-specific information.
	using Instance = ak_wwise_plugin_source_instance_v1;

	ak_wwise_plugin_source_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_SOURCE, 1)
	{}
#endif

	/**
	 * \brief Return the minimum and maximum duration, in seconds.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[out] out_dblMinDuration Minimum duration, in seconds
	 * \param[out] out_dblMaxDuration Maximum duration, in seconds
	 */
	bool(*GetSourceDuration)(
		const struct ak_wwise_plugin_source_instance_v1* in_this,
		double* out_dblMinDuration,
		double* out_dblMaxDuration
	);
};

#define AK_WWISE_PLUGIN_SOURCE_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_SOURCE, 1)
#define AK_WWISE_PLUGIN_SOURCE_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_SOURCE_V1_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CSource = ak_wwise_plugin_source_v1;
		
		/// \copydoc ak_wwise_plugin_audio_plugin_v1
		class Source : public CSource::Instance
		{
		public:
			/**
			 * \copydoc CSource::Instance
			 */
			using Instance = CSource::Instance;

			/**
			 * \brief The interface type, as provided by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as provided by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_SOURCE
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
			struct Interface : public CSource
			{
				using Instance = Source;
				Interface()
				{
					CSource::GetSourceDuration = [](
						const struct ak_wwise_plugin_source_instance_v1* in_this,
						double* out_dblMinDuration,
						double* out_dblMaxDuration)
					{
						return (bool)static_cast<const Instance*>(in_this)->GetSourceDuration(
							*out_dblMinDuration,
							*out_dblMaxDuration);
					};
				}
			};

			InterfacePtr GetInterfacePointer() {
				static Interface g_interface;
				return &g_interface;
			}
			CSource::Instance* GetInstancePointer() {
				return this;
			}
			const CSource::Instance* GetInstancePointer() const {
				return this;
			}

			Source() :
				CSource::Instance()
			{
			}

			virtual ~Source() {}

			/**
			 * \brief Return the minimum and maximum duration, in seconds.
			 * 
			 * \param[out] out_dblMinDuration Minimum duration, in seconds
			 * \param[out] out_dblMaxDuration Maximum duration, in seconds
			 */
			virtual bool GetSourceDuration(
				double & out_dblMinDuration,
				double & out_dblMaxDuration
			) const = 0;
		};
	} // of namespace V1

	/// Latest version of the C Source interface.
	using CSource = V1::CSource;
	/// Latest version of the C++ Source interface.
	using Source = V1::Source;

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(Source);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(Source);
} // of namespace AK::Wwise::Plugin

#endif
