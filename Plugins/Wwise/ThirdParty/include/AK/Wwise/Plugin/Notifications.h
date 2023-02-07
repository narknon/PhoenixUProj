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
 * \brief Wwise Authoring Plug-ins - APIs for different host notifications.
 * \file AK/Wwise/Plugin/Notifications.h
 * 
 * These are notifications not fitting in the other host services. For every host service, there is usually
 * a notification to tell your plug-in something changed and to update data.
 * 
 * These are independent notifications, not linked on other services.
 */

#pragma once

#include "PluginInfoGenerator.h"

/**
 * \brief API for Sound Engine's Monitor Data notification.
 */
struct ak_wwise_plugin_notifications_monitor_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for receiving Sound Engine's monitoring data.
	using Instance = ak_wwise_plugin_notifications_monitor_instance_v1;

	ak_wwise_plugin_notifications_monitor_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_MONITOR, 1)
	{}
#endif

	/**
	 * \brief Received a new Monitor Data blob.
	 * 
	 * Called when an instance of the run-time component of the plug-in sends data using
	 * \c AK::IAkEffectPluginContext::PostMonitorData(), and this plug-in's settings are being displayed
	 * in a window. Because multiple run-time instances may exist for a single authoring tool plug-in,
	 * the data is batched together and passed at the end of the frame.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_iTimeStamp Timestamp of the data (in milliseconds).
	 * \param[in] in_pMonitorDataArray Array of blobs of data.
	 * \param[in] in_uMonitorDataArraySize Number of elements in array 'in_pMonitorDataArray'.
	 * \param[in] in_bIsRealtime true if monitoring in real time, false if scrubbing through profiler history.
	 */
	void(*NotifyMonitorData)(
		struct ak_wwise_plugin_notifications_monitor_instance_v1* in_this,
		AkTimeMs in_iTimeStamp,
		const AK::Wwise::Plugin::MonitorData * in_pMonitorDataArray,
		unsigned int in_uMonitorDataArraySize,
		bool in_bIsRealtime
	);
};

#define AK_WWISE_PLUGIN_NOTIFICATIONS_MONITOR_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_MONITOR, 1)
#define AK_WWISE_PLUGIN_NOTIFICATIONS_MONITOR_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_NOTIFICATIONS_MONITOR_V1_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		/// Notifications namespace
		namespace Notifications
		{
			using CMonitor = ak_wwise_plugin_notifications_monitor_v1;

			/// \copydoc ak_wwise_plugin_notifications_monitor_v1
			class Monitor : public CMonitor::Instance
			{
			public:
				/**
				 * \copydoc CMonitor::Instance
				 */
				using Instance = CMonitor::Instance;

				/**
				 * \brief The interface type, as provided by this plug-in.
				 */
				enum : InterfaceTypeValue
				{
					/**
					 * \brief The interface type, as provided by this plug-in.
					 */
					k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_MONITOR
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
				struct Interface : public CMonitor
				{
					using Instance = Monitor;
					Interface()
					{
						CMonitor::NotifyMonitorData = [](
							struct ak_wwise_plugin_notifications_monitor_instance_v1* in_this,
							AkTimeMs in_iTimeStamp,
							const MonitorData * in_pMonitorDataArray,
							unsigned int in_uMonitorDataArraySize,
							bool in_bIsRealtime)
						{
							static_cast<Instance*>(in_this)->NotifyMonitorData(
								in_iTimeStamp,
								in_pMonitorDataArray,
								in_uMonitorDataArraySize,
								in_bIsRealtime);
						};
					}
				};

				InterfacePtr GetInterfacePointer() {
					static Interface g_interface;
					return &g_interface;
				}
				CMonitor::Instance* GetInstancePointer() {
					return this;
				}
				const CMonitor::Instance* GetInstancePointer() const {
					return this;
				}

				Monitor() :
					CMonitor::Instance()
				{
				}

				virtual ~Monitor() {}

				/**
				 * \brief Received a new Monitor Data blob.
				 * 
				 * Called when an instance of the run-time component of the plug-in sends data using
				 * \c AK::IAkEffectPluginContext::PostMonitorData(), and this plug-in's settings are being displayed
				 * in a window. Because multiple run-time instances may exist for a single authoring tool plug-in,
				 * the data is batched together and passed at the end of the frame.
				 * 
				 * \param[in] in_iTimeStamp Timestamp of the data (in milliseconds).
				 * \param[in] in_pMonitorDataArray Array of blobs of data.
				 * \param[in] in_uMonitorDataArraySize Number of elements in array 'in_pMonitorDataArray'.
				 * \param[in] in_bIsRealtime true if monitoring in real time, false if scrubbing through profiler history.
				 */
				virtual void NotifyMonitorData(
					AkTimeMs in_iTimeStamp,
					const MonitorData* in_pMonitorDataArray,
					unsigned int in_uMonitorDataArraySize,
					bool in_bIsRealtime
				) = 0;
			};
		} // of namespace Notifications
	} // of namespace V1

	namespace Notifications
	{
		/// Latest version of the C Monitor notification interface.
		using CMonitor = V1::Notifications::CMonitor;
		/// Latest version of the C++ Monitor notification interface.
		using Monitor = V1::Notifications::Monitor;
	}

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(Notifications::Monitor);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(Notifications::Monitor);
} // of namespace AK::Wwise::Plugin

#endif
