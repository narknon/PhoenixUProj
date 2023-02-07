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
 * \brief Wwise Authoring Plug-ins - Standardized header for all the plug-in interfaces.
 * \file AK/Wwise/Plugin/PluginBaseInterface.h
 */

#pragma once

#include "PluginDef.h"

#ifdef __cplusplus
#include <type_traits> // std::underlying_type
#endif

/** \addtogroup global
 * @{
 */

/**
 * \brief List of every single interface known to the plug-in system
 *
 * Once the version of a plug-in interface is official, it should always keep the same ID. No ID should be reused,
 * and the order should stay exactly the same all the time.
 */
typedef enum
{
	AK_WWISE_PLUGIN_INTERFACE_TYPE_UNKNOWN,										///< <b>2021.1</b> Unknown plug-in ID (0 - error, invalid, uninitialized)
	AK_WWISE_PLUGIN_INTERFACE_TYPE_PLUGIN_CONTAINER, 							///< <b>2021.1</b> Plug-in container plug-in. Contains all the other plug-ins. ak_wwise_plugin_container

	AK_WWISE_PLUGIN_INTERFACE_TYPE_ANALYSIS_TASK,								///< <b>2021.1</b> Analysis task plug-in. ak_wwise_plugin_analysis_task_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_AUDIO_PLUGIN,								///< <b>2021.1</b> Audio backend plug-in. ak_wwise_plugin_audio_plugin_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_CONVERSION,									///< <b>2021.1</b> Conversion plug-in. ak_wwise_plugin_conversion_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_CUSTOM_DATA,									///< <b>2021.1</b> Custom Data reader backend part. ak_wwise_plugin_custom_data_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_FEEDBACK_AWARE,								///< <b>2021.1</b> Feedback-aware frontend part. ak_wwise_plugin_feedback_aware_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_FIRST_TIME_CREATION_MESSAGE, 				///< <b>2021.1</b> First Time Creation Message plug-in. ak_wwise_plugin_first_time_creation_message_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_LICENSE,										///< <b>2021.1</b> Licensing. ak_wwise_plugin_license_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_MEDIA_CONVERTER,								///< <b>2021.1</b> Media Converter backend part. ak_wwise_plugin_media_converter_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_HOST,							///< <b>2021.1</b> Host modification notification. ak_wwise_plugin_notifications_host_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_MONITOR,						///< <b>2021.1</b> Monitor data notification. ak_wwise_plugin_notifications_monitor_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_OBJECT_MEDIA,					///< <b>2021.1</b> Object Media modification notification. ak_wwise_plugin_notifications_object_media_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_OBJECT_STORE,					///< <b>2021.1</b> Object Store modification notification. ak_wwise_plugin_notifications_object_store_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_PROPERTY_SET,					///< <b>2021.1</b> Property Set modification notification. ak_wwise_plugin_notifications_property_set_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_PROPERTY_DISPLAY_NAME,						///< <b>2021.1</b> Property display name overrides. ak_wwise_plugin_property_display_name_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_SINK_DEVICES,								///< <b>2021.1</b> Sink Devices enumeration plug-in. ak_wwise_plugin_sink_devices_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_SOURCE,										///< <b>2021.1</b> Source-specific backend part. ak_wwise_plugin_source_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_UNDO_EVENT,									///< <b>2021.1</b> Undo Event. ak_wwise_plugin_undo_event_v1

	AK_WWISE_PLUGIN_INTERFACE_TYPE_GUI_CONVERSION_WINDOWS,						///< <b>2021.1</b> Conversion frontend plug-in for Windows. ak_wwise_plugin_gui_conversion_windows_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_GUI_WINDOWS,			  						///< <b>2021.1</b> Audio frontend plug-in for Windows. ak_wwise_plugin_gui_windows_v1

	AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST,										///< <b>2021.1</b> Host services. ak_wwise_plugin_host_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_CONVERSION_HELPERS,						///< <b>2021.1</b> Conversion helpers host services. ak_wwise_plugin_host_conversion_helpers_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_OBJECT_MEDIA,							///< <b>2021.1</b> Object Media host service. ak_wwise_plugin_host_object_media_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_OBJECT_STORE,							///< <b>2021.1</b> Object Store host service. ak_wwise_plugin_host_object_store_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_PROPERTY_SET,							///< <b>2021.1</b> Property Set host service. ak_wwise_plugin_host_property_set_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_UNDO_MANAGER,							///< <b>2021.1</b> Undo Manager host service. ak_wwise_plugin_host_undo_manager_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_DATA_WRITER,							///< <b>2021.1</b> Data Writer host service. ak_wwise_plugin_host_data_writer_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_XML,									///< <b>2021.1</b> XML reading and writing host services. ak_wwise_plugin_host_xml_v1

	AK_WWISE_PLUGIN_INTERFACE_TYPE_LINK_BACKEND,			  				 	///< <b>2021.1</b> Link to the backend plug-in. ak_wwise_plugin_link_backend_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_LINK_FRONTEND,			  					///< <b>2021.1</b> Link to the frontend plug-ins. ak_wwise_plugin_link_frontend_v1
	AK_WWISE_PLUGIN_INTERFACE_TYPE_NATIVE_ISERVICEPROVIDER,	   					///< \internal <b>2021.1</b>
	AK_WWISE_PLUGIN_INTERFACE_TYPE_NATIVE_IWAUDIODEVICEPLUGIN,					///< \internal <b>2021.1</b>
	AK_WWISE_PLUGIN_INTERFACE_TYPE_NATIVE_IWCONVERSIONPLUGIN,  					///< \internal <b>2021.1</b>
	AK_WWISE_PLUGIN_INTERFACE_TYPE_NATIVE_IWEFFECTPLUGIN,	  					///< \internal <b>2021.1</b>
	AK_WWISE_PLUGIN_INTERFACE_TYPE_NATIVE_IWSOURCEPLUGIN,	   					///< \internal <b>2021.1</b>

	AK_WWISE_PLUGIN_INTERFACE_TYPE_TESTSERVICE,									///< \internal <b>Reserved</b>
	/** Number of plug-in interfaces. Last value. */
	AK_WWISE_PLUGIN_INTERFACE_TYPE_NUM
} ak_wwise_plugin_interface_type;

/**
 * \brief Interface description and base class for every Wwise Authoring plug-in interface.
 * 
 * The interface description is expected to never change, and to contain two basic values: the interface type, which is
 * an incrementing value for every single possibility of known interfaces, as well as the version of this interface,
 * starting from 1 at the interface's public release.
 * 
 * An interface can either be provided by the plug-in (for example, AK_WWISE_PLUGIN_INTERFACE_TYPE_AUDIO_PLUGIN), where
 * the plug-in provides the functionality of the callback; or it can be requested to the Wwise Authoring host
 * (for example, AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_PROPERTY_SET), where the data will be filled by the host for
 * the plug-in to call.
 * 
 * All requested or provided interfaces are deemed mandatory in order to instantiate a plug-in. An unknown or an invalid
 * interface in a context (AK_WWISE_PLUGIN_INTERFACE_TYPE_GUI_WINDOWS in WwiseConsole.exe or on Linux) causes the host
 * to skip the plug-in.
 */
#pragma pack(push, 1)
struct ak_wwise_plugin_base_interface
{
	ak_wwise_plugin_interface_type m_interface : 32; ///< Interface type (see \ref ak_wwise_plugin_interface_type)
	uint32_t m_version : 32;						 ///< Version of the interface

#ifdef __cplusplus
	constexpr ak_wwise_plugin_base_interface(decltype(m_interface) in_interface, decltype(m_version) in_version) : m_interface(in_interface), m_version(in_version)
	{
	}
	constexpr ak_wwise_plugin_base_interface() : ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_UNKNOWN, 0) {}
	constexpr ak_wwise_plugin_base_interface(std::underlying_type<decltype(m_interface)>::type in_interface, decltype(m_version) in_version) : ak_wwise_plugin_base_interface(static_cast<ak_wwise_plugin_interface_type>(in_interface), in_version) {}
#endif
};
#pragma pack(pop)

#define AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(/* ak_wwise_plugin_interface_type */ in_interface, /* uint32_t */ in_version) \
	{                                                                                                                        \
		.m_interface = in_interface,                                                                                         \
		.m_version = in_version                                                                                              \
	}

/**
 * @}
 */