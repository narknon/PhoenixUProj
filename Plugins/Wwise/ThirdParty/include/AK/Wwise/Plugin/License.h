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
 * \brief Wwise Authoring Plug-ins - Plug-in API for licensing.
 * \file AK/Wwise/Plugin/License.h
 */

#pragma once

#include "PluginInfoGenerator.h"

/**
 * \brief Backend API to specify licensing requirements
 */
struct ak_wwise_plugin_license_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for providing licensing information.
	using Instance = ak_wwise_plugin_license_instance_v1;

	ak_wwise_plugin_license_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_LICENSE, 1)
	{}
#endif

	/**
	 * \brief Retrieve the licensing status of the plug-in for the given platform.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform GUID of the platform.
	 * \param[out] out_eSeverity (Optional) If set, the string placed in out_pszMessage will be shown
	 *             in the log with the corresponding severity. 
	 * \param[out] out_pszMessage Pointer to the buffer of size in_uiBufferSize that will hold the
	 *             message string.
	 * \param[in] in_uiBufferSize Null-terminated size of the buffer pointed by out_pszMessage.

	 * \return Licensing status of the plug-in; LicenseStatus_Unlicensed or LicenseStatus_Expired
	 *         will prevent the plug-in from being included in a SoundBank.
	 * 
	 * \sa
	 * - \ref AK::Wwise::Plugin::Host::GetLicenseStatus
	 * - \ref AK::Wwise::Plugin::Host::GetAssetLicenseStatus
	 * - \ref wwiseplugin_dll_license
	 */
	AK::Wwise::Plugin::LicenseStatus(*GetLicenseStatus)(
		const struct ak_wwise_plugin_license_instance_v1* in_this,
		const GUID* in_guidPlatform,		///< GUID of the platform
		AK::Wwise::Plugin::Severity* out_eSeverity,	///< (Optional) If set, the string placed in out_pszMessage will be shown in the log with the corresponding severity.
		char * out_pszMessage,				///< Pointer to the buffer that will hold the message string
		unsigned int in_uiBufferSize		///< Size of the buffer pointed by out_pszMessage (in number of WCHAR, including null terminator)
	);

};
#define AK_WWISE_PLUGIN_LICENSE_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_LICENSE, 1)
#define AK_WWISE_PLUGIN_LICENSE_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_LICENSE_V1_ID(), in_pluginInfo, in_data) \
}

#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CLicense = ak_wwise_plugin_license_v1;
		class License : public CLicense::Instance
		{
		public:
			/**
			 * \brief The interface type, as provided by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as provided by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_LICENSE
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
			struct Interface : public CLicense
			{
				using Instance = License;
				Interface()
				{
					CLicense::GetLicenseStatus = [](
						const struct ak_wwise_plugin_license_instance_v1* in_this,
						const GUID* in_guidPlatform,
						Severity* out_eSeverity,
						char * out_pszMessage,
						unsigned int in_uiBufferSize)
					{
						return (LicenseStatus)static_cast<const Instance*>(in_this)->GetLicenseStatus(
							*in_guidPlatform,
							*out_eSeverity,
							out_pszMessage,
							in_uiBufferSize);
					};
				}
			};

			InterfacePtr GetInterfacePointer() {
				static Interface g_interface;
				return &g_interface;
			}
			CLicense::Instance* GetInstancePointer() {
				return this;
			}
			const CLicense::Instance* GetInstancePointer() const {
				return this;
			}

			License() :
				CLicense::Instance()
			{
			}

			virtual ~License() {}

			/**
			 * \brief Retrieve the licensing status of the plug-in for the given platform.
			 * 
			 * \param[in] in_guidPlatform GUID of the platform.
			 * \param[out] out_eSeverity (Optional) If set, the string placed in out_pszMessage will be shown
			 *             in the log with the corresponding severity.
			 * \param[out] out_pszMessage Pointer to the buffer of size in_uiBufferSize that will hold the
			 *             message string.
			 * \param[in] in_uiBufferSize Null-terminated size of the buffer pointed by out_pszMessage.

			* \return Licensing status of the plug-in; LicenseStatus_Unlicensed or LicenseStatus_Expired
			*         will prevent the plug-in from being included in a SoundBank.
			* 
			* \sa
			* - \ref AK::Wwise::Plugin::Host::GetLicenseStatus
			* - \ref AK::Wwise::Plugin::Host::GetAssetLicenseStatus
			* - \ref wwiseplugin_dll_license
			*/
			virtual LicenseStatus GetLicenseStatus(
				const GUID & in_guidPlatform,
				Severity & out_eSeverity,
				char * out_pszMessage,
				unsigned int in_uiBufferSize
			) const { return LicenseStatus::LicenseStatus_Valid; }
		};
	} // of namespace V1

	/// Latest version of the C License interface.
	using CLicense = V1::CLicense;
	/// Latest version of the C++ License interface.
	using License = V1::License;

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(License);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(License);
} // of namespace AK::Wwise::Plugin

#endif
