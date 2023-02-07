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
 * \brief Wwise Authoring Plug-ins - Plug-in that lists supported output devices. 
 * \file AK/Wwise/Plugin/SinkDevices.h
 * 
 * Provides a list of up-to-date device IDs that can be used to instantiate a new Sound Engine sink.
 * 
 * \sa C interfaces
 * - \ref ak_wwise_plugin_sink_devices_v1
 * 
 * \sa C++ interfaces
 * - \ref AK::Wwise::Plugin::SinkDevices
 */

#pragma once

#include "PluginInfoGenerator.h"

/**
 * \brief Device enumerator for sink plug-ins.
 * 
 * Allows your plug-in to provide a list of up-to-date device IDs that can be used to instantiate a new
 * Sound Engine sink.
 * 
 * This plug-in interface cannot be linked to a backend or a frontend plug-in, it must be standalone.
 * 
 * \sa
 * - \ref ak_wwise_plugin_sink_devices_instance_v1 instance type
 * - \ref AK::Wwise::Plugin::SinkDevices C++ Interface
 * - \ref AK_WWISE_PLUGIN_SINK_DEVICES_V1_ID Current ID for interface
 * - \ref AK_WWISE_PLUGIN_INTERFACE_TYPE_SINK_DEVICES
 */
struct ak_wwise_plugin_sink_devices_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	using Instance = ak_wwise_plugin_sink_devices_instance_v1;		///< \copydoc ak_wwise_plugin_sink_devices_instance_v1

	ak_wwise_plugin_sink_devices_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_SINK_DEVICES, 1)
	{}
#endif

	/**
	 * \brief Get a count of the number of interfaces currently available.
	 * 
	 * Provided by your plug-in, this should return a count.
	 * 
	 * \aknote
	 * Due to the unpredictable nature of hardware configuration changes, an unpadded, basic system would return
	 * a configuration that can change between a GetCount and subsequent objects retrieval.
	 * 
	 * As a plug-in designer, you are responsible to address this by returning adequate values that make sense as a whole.
	 * 
	 * To guide you, Sink Devices interface is used for retrieval and data copy in a tight loop over a single thread
	 * at once. Host will retrieve the count, followed by the Name (GetName) and DeviceID (GetDeviceID), in the
	 * order the compiler sees fit. Data is expected to survive for the amount of time this tight loop exists.
	 * 
	 * \code
	 *     	int count = m_interface->GetCount(m_instance);
	 *	    for (int i = 0; i < count; ++i)
	 *	    {
	 *		    result.emplace_back(
	 *			    m_interface->GetName(m_instance, i),
	 *			    m_interface->GetDeviceID(m_instance, i)
	 *		    );
	 *	    }
	 * \endcode
	 * 
	 * A proposal is to use GetCount to internally retrieve the device names and IDs, make a static internal
	 * cache, and then return name and device ID based on this cache.
	 * 
	 * You can also spawn an event listener or an update thread, and ensure the data is up to date when the calls
	 * come in, and block updates until all calls are accounted for.
	 * \endaknote
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return int Count of the number of interfaces available.
	 */
	int(*GetCount)(const struct ak_wwise_plugin_sink_devices_instance_v1* in_this);

	/**
	 * \brief Get a user-presentable name for the device number in_num.
	 * 
	 * Provided by your plug-in, this should return a const char* in UTF-8, valid at least until the next
	 * function call, and must not return duplicates or nullptr.
	 * 
	 * It should return names that can be understood by an end user in the context of your plug-in.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_num Device number, from zero to the value, as retrieved by GetCount.
	 * \return const char* UTF-8 Name of the interface in_num.
	 * 
	 * \sa \ref GetCount for a discussion on providing data in a multithread-aware environment.
	 */
	const char*(*GetName)(const struct ak_wwise_plugin_sink_devices_instance_v1* in_this, int in_num);

	/**
	 * \brief Get a device ID for the device number in_num.
	 * 
	 * Provided by your plug-in, this should return a uint32_t that can be understood by the Sound Engine part of
	 * your sink plug-in. It must not return duplicates or pointers, and the value should be applicable to the
	 * GetName call based on the same in_num.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_num Device number, from zero to the value, as retrieved by GetCount.
	 * \return uint32_t Device ID for the interface in_num.
	 * 
	 * \sa \ref GetCount for a discussion on providing data in a multithread-aware environment.
	 */
	uint32_t(*GetDeviceID)(const struct ak_wwise_plugin_sink_devices_instance_v1* in_this, int in_num);
};
#define AK_WWISE_PLUGIN_SINK_DEVICES_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_SINK_DEVICES, 1)
#define AK_WWISE_PLUGIN_SINK_DEVICES_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_SINK_DEVICES_V1_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CSinkDevices = ak_wwise_plugin_sink_devices_v1;		///< \copydoc ak_wwise_plugin_sink_devices_v1

		/**
		 * \brief C++ API to provide device enumeration for sink plug-ins.
		 * 
		 * Allows your plug-in to provide a list of up-to-date device IDs that can be used to instantiate a new Sound
		 * Engine sink.
		 * 
		 * This plug-in interface cannot be linked to a backend or a frontend plug-in, it must be standalone.
		 * 
		 * \sa
		 * - \ref ak_wwise_plugin_sink_devices_v1 C interface
		 * - \ref AK_WWISE_PLUGIN_INTERFACE_TYPE_SINK_DEVICES
		 */
		class SinkDevices : public CSinkDevices::Instance
		{
		public:
			/**
			 * \copydoc CSinkDevices::Instance
			 */
			using Instance = CSinkDevices::Instance;

			/**
			 * \brief The interface type, as provided by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as provided by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_SINK_DEVICES
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
			struct Interface : public CSinkDevices
			{
				using Instance = SinkDevices;																			///< \copydoc SinkDevices
				Interface()
				{
					CSinkDevices::GetCount = [](const struct ak_wwise_plugin_sink_devices_instance_v1* in_this) { return static_cast<const Instance*>(in_this)->GetCount(); };
					CSinkDevices::GetName = [](const struct ak_wwise_plugin_sink_devices_instance_v1* in_this, int in_num) { return static_cast<const Instance*>(in_this)->GetName(in_num); };
					CSinkDevices::GetDeviceID = [](const struct ak_wwise_plugin_sink_devices_instance_v1* in_this, int in_num) { return static_cast<const Instance*>(in_this)->GetDeviceID(in_num); };
				}
			};

			/**
			 * \internal
			 * \brief Get the static Interface object, as used internally in AK::Wwise::Plugin::PluginInfoGenerator.
			 */
			InterfacePtr GetInterfacePointer() {
				static Interface g_interface;
				return &g_interface;
			}

			/**
			 * \internal
			 * \brief Get the static Instance object, as used internally in AK::Wwise::Plugin::PluginInfoGenerator.
			 */
			CSinkDevices::Instance* GetInstancePointer() {
				return this;
			}

			/**
			 * \internal
			 * \brief Get the static Instance object, as used internally in AK::Wwise::Plugin::PluginInfoGenerator.
			 */
			const CSinkDevices::Instance* GetInstancePointer() const {
				return this;
			}

			SinkDevices() :
				CSinkDevices::Instance()
			{
			}

			virtual ~SinkDevices() {}

			/**
			 * \brief Get a count of the number of interfaces currently available.
			 * 
			 * Provided by your plug-in, this should return a count.
			 * 
			 * \aknote
			 * Due to the unpredictable nature of hardware configuration changes, an unpadded, basic system would return
			 * a configuration that can change between a GetCount and subsequent objects retrieval.
			 * 
			 * As a plug-in designer, you are responsible to address this by returning adequate values that make sense as a whole.
			 * 
			 * To guide you, Sink Devices interface is used for retrieval and data copy in a tight loop over a single thread
			 * at once. Host will retrieve the count, followed by the Name (GetName) and DeviceID (GetDeviceID), in the
			 * order the compiler sees fit. Data is expected to survive for the amount of time this tight loop exists.
			 * 
			 * \code
			 *     	int count = m_interface->GetCount(m_instance);
			 *	    for (int i = 0; i < count; ++i)
			 *	    {
			 *		    result.emplace_back(
			 *			    m_interface->GetName(m_instance, i),
			 *			    m_interface->GetDeviceID(m_instance, i)
			 *		    );
			 *	    }
			 * \endcode
			 * 
			 * A proposal is to use GetCount to internally retrieve the device names and IDs, make a static internal
			 * cache, and then return name and device ID based on this cache.
			 * 
			 * You can also spawn an event listener or an update thread, and ensure the data is up to date when the calls
			 * come in, and block updates until all calls are accounted for.
			 * \endaknote
			 * 
			 * \return int Count of the number of interfaces available.
			 */
			virtual int GetCount() const = 0;

			/**
			 * \brief Get a user-presentable name for the device number in_num.
			 * 
			 * Provided by your plug-in, this should return a const char* in UTF-8, valid at least until the next
			 * function call, and must not return duplicates or nullptr.
			 * 
			 * It should return names that can be understood by an end user in the context of your plug-in.
			 * 
			 * \param[in] in_num Device number, from zero to the value, as retrieved by GetCount.
			 * \return const char* UTF-8 Name of the interface in_num.
			 * 
			 * \sa \ref GetCount for a discussion on providing data in a multithread-aware environment.
			 */
			virtual const char* GetName(int in_num) const = 0;

			/**
			 * \brief Get a device ID for the device number in_num.
			 * 
			 * Provided by your plug-in, this should return a uint32_t that can be understood by the Sound Engine part of
			 * your sink plug-in. It must not return duplicates or pointers, and the value should be applicable to the
			 * GetName call based on the same in_num.
			 * 
			 * \param[in] in_num Device number, from zero to the value, as retrieved by GetCount.
			 * \return uint32_t Device ID for the interface in_num.
			 * 
			 * \sa \ref GetCount for a discussion on providing data in a multithread-aware environment.
			 */
			virtual uint32_t GetDeviceID(int in_num) const = 0;
		};
	} // of namespace V1

	/// Latest version of the C SinkDevices interface.
	using CSinkDevices = V1::CSinkDevices;
	/// Latest version of the C++ SinkDevices interface.
	using SinkDevices = V1::SinkDevices;

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(SinkDevices);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(SinkDevices);
} // of namespace AK::Wwise::Plugin

#endif // of __cplusplus
