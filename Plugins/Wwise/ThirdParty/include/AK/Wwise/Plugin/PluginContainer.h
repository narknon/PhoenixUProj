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
 * \brief Wwise Authoring Plug-ins - Root interface allowing a logical unit (variable, library) to contain more than one interface.
 * \file AK/Wwise/Plugin/PluginContainer.h
 */

#pragma once

#include "PluginInfo.h"

/**
 * \brief Root interface allowing a logical unit (variable, library) to contain more than one interface.
 * 
 * The container is a required element to define the base of a logical unit. It contains basic information on the
 * build being used by the enclosed plug-ins. This allows the host to quickly determine if it should pursue
 * loading this container or not, and might need to apply patches to fix interface variations appearing
 * between SDK versions.
 * 
 * The container being versioned means this format could eventually change, but the goal was to make it generic
 * enough to keep it stable. It's easier to add up plug-ins to extend the format than to modify it.
 */
struct ak_wwise_plugin_container
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	struct ak_wwise_plugin_base_interface m_baseInterface;
#endif

	uint64_t m_wwiseSdkVersion;						///< Wwise Authoring version included with this SDK.

	struct ak_wwise_plugin_info* m_pluginInfos;		///< A chained list of all the plug-ins embedded in this container

#ifdef __cplusplus
	// Must not go higher than 18 44674 407 370 9551615 (ULLONG_MAX)
	//						      aaaaa iii sss bbbbbbb

	constexpr inline static uint64_t SdkVersionBuildMultiplier() { return 1; }
	constexpr inline static uint64_t SdkVersionBuildMax() { return 9999999; }
	constexpr inline static uint64_t SdkVersionSubminorMultiplier() { return SdkVersionBuildMultiplier() * (SdkVersionBuildMax() + 1); }
	constexpr inline static uint64_t SdkVersionSubminorMax() { return 999; }
	constexpr inline static uint64_t SdkVersionMinorMultiplier() { return SdkVersionSubminorMultiplier() * (SdkVersionSubminorMax() + 1); }
	constexpr inline static uint64_t SdkVersionMinorMax() { return 999; }
	constexpr inline static uint64_t SdkVersionMajorMultiplier() { return SdkVersionMinorMultiplier() * (SdkVersionMinorMax() + 1); }
	constexpr inline static uint64_t SdkVersionMajorMax() { return 99999; }

	/// \brief (C++) Major SDK version (ex. 2020)
	constexpr inline uint32_t MajorSdkVersion() const { return (uint32_t)(m_wwiseSdkVersion / SdkVersionMajorMultiplier()); }
	/// \brief (C++) Minor SDK version (ex. 1)
	constexpr inline uint32_t MinorSdkVersion() const { return (uint32_t)((m_wwiseSdkVersion % (SdkVersionMinorMultiplier() * (SdkVersionMinorMax() + 1))) / SdkVersionMinorMultiplier()); }
	/// \brief (C++) Patch / Subminor SDK version (ex. 0)
	constexpr inline uint32_t SubminorSdkVersion() const { return (uint32_t)((m_wwiseSdkVersion % (SdkVersionSubminorMultiplier() * (SdkVersionSubminorMax() + 1))) / SdkVersionSubminorMultiplier()); }
	/// \brief (C++) Build number (ex. 9404)
	constexpr inline uint32_t BuildSdkVersion() const { return (uint32_t)((m_wwiseSdkVersion % (SdkVersionBuildMultiplier() * (SdkVersionBuildMax() + 1)))); }

	ak_wwise_plugin_container() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_PLUGIN_CONTAINER, 1),
		m_wwiseSdkVersion((uint64_t)AK_WWISESDK_VERSION_MAJOR * SdkVersionMajorMultiplier() + (uint64_t)AK_WWISESDK_VERSION_MINOR * SdkVersionMinorMultiplier() + (uint64_t)AK_WWISESDK_VERSION_SUBMINOR * SdkVersionSubminorMultiplier() + (uint64_t)AK_WWISESDK_VERSION_BUILD * SdkVersionBuildMultiplier()),
		m_pluginInfos(nullptr)
	{}
	ak_wwise_plugin_container(ak_wwise_plugin_info* in_pluginInfos) :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_PLUGIN_CONTAINER, 1),
		m_wwiseSdkVersion((uint64_t)AK_WWISESDK_VERSION_MAJOR * SdkVersionMajorMultiplier() + (uint64_t)AK_WWISESDK_VERSION_MINOR * SdkVersionMinorMultiplier() + (uint64_t)AK_WWISESDK_VERSION_SUBMINOR * SdkVersionSubminorMultiplier() + (uint64_t)AK_WWISESDK_VERSION_BUILD * SdkVersionBuildMultiplier()),
		m_pluginInfos(in_pluginInfos)
	{}
#endif
};
#define AK_WWISE_PLUGIN_CONTAINER_CTOR_IDS() \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_PLUGIN_CONTAINER, 1), \
	.m_wwiseSdkVersion = (uint64_t)AK_WWISESDK_VERSION_MAJOR * 1000000000 + (uint64_t)AK_WWISESDK_VERSION_MINOR * 10000000 + (uint64_t)AK_WWISESDK_VERSION_SUBMINOR * 100000 + (uint64_t)AK_WWISESDK_VERSION_BUILD
