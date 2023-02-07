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
 * \brief Wwise Authoring Plug-ins - API to request host's current state and services.
 * \file AK/Wwise/Plugin/Host.h
 */

#pragma once

#include "../PlatformID.h"
#include "PluginInfoGenerator.h"


/**
 * \brief API to request host's current state and services.
 * 
 * If requested, this contains information on the current state of the host as well as generic operations.
 * 
 * For example, the currently selected platform, tools to post
 * when internal plug-in data changed, or a way to make Waapi calls.
 * 
 * In order to be reactive to host's state, you should consider implementing ak_wwise_plugin_notifications_host_v1
 * notifications.
 */
struct ak_wwise_plugin_host_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base host-provided instance type.
	using Instance = ak_wwise_plugin_host_instance_v1;
	ak_wwise_plugin_host_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST, 1)
	{}
#endif

	/**
	 * \brief Retrieves the current platform identifier.
	 * 
	 * This can be passed to any function that has a parameter for a platform ID, such as GetValue() or
	 * SetValue(), when you want to make the call for the currently active platform.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return The unique ID of the current platform.
	 */
	GUID(*GetCurrentPlatform)(const struct ak_wwise_plugin_host_v1* in_this);

	/**
	 * \brief Retrieves the current base platform identifier.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return The unique ID of the current base platform.
	 */
	BasePlatformID(*GetCurrentBasePlatform)(const struct ak_wwise_plugin_host_v1* in_this);

	/**
	 * \brief Retrieves the requested playback base platform of the Authoring tool.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return The unique base ID of the requested playback's platform.
	 */
	BasePlatformID(*GetDefaultNativeAuthoringPlaybackPlatform)(const struct ak_wwise_plugin_host_v1* in_this);

	/**
	 * \brief Retrieves the requested playback platform of the Authoring tool.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return The unique ID of the requested playback's platform.
	 */
	GUID(*GetAuthoringPlaybackPlatform)(const struct ak_wwise_plugin_host_v1* in_this);

	/**
	 * \brief Use this function to tell Wwise that something other than properties has changed within the plug-in.
	 * 
	 * This will set the plugin dirty (indicating there are unsaved changes) and GetPluginData will be called when
	 * the plug-in is about to play in Wwise. This will transfer the internal data to the Sound Engine part of
	 * the plug-in.
	 * 
	 * Use ALL_PLUGIN_DATA_ID to indicate that all the data has to be refreshed.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_idData Data needed to be updated.
	 * \param[in] in_bMakeProjectDirty Whether project needs saving.
	 */
	void(*NotifyInternalDataChanged)(
		struct ak_wwise_plugin_host_instance_v1* in_this,
		AkPluginParamID in_idData,
		bool in_bMakeProjectDirty
	);

	/**
	 * \brief Obtain licensing status for the plug-in.
	 * 
	 * Refer to \ref wwiseplugin_dll_license for more information.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform GUID of the platform.
	 * \param[out] out_eType License Type.
	 * \param[out] out_eStatus License Status.
	 * \param[out] out_uDaysToExpiry Days until license expiry.
	 */
	void(*GetLicenseStatus)(
		const struct ak_wwise_plugin_host_instance_v1* in_this,
		const GUID* in_guidPlatform,
		AK::Wwise::Plugin::LicenseType* out_eType,
		AK::Wwise::Plugin::LicenseStatus* out_eStatus,
		uint32_t* out_uDaysToExpiry
	);

	/**
	 * \brief Obtain licensing status for a plug-in-specific asset ID.
	 * 
	 * Refer to \ref wwiseplugin_dll_license for more information.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform GUID of the platform.
	 * \param[in] in_uAssetID ID of the asset.
	 * \param[out] out_eType License Type.
	 * \param[out] out_eStatus License Status.
	 * \param[out] out_uDaysToExpiry Days until license expiry.
	 */
	void(*GetAssetLicenseStatus)(
		const struct ak_wwise_plugin_host_instance_v1* in_this,
		const GUID* in_guidPlatform,
		AkUInt32 in_uAssetID,
		AK::Wwise::Plugin::LicenseType* out_eType,
		AK::Wwise::Plugin::LicenseStatus* out_eStatus,
		uint32_t* out_uDaysToExpiry
	);

	/**
	 * \brief Find and call the specified procedure.
	 * 
	 * Calls made using this function are always blocking.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_szUri URI of the procedure to call.
	 * \param[in] in_szArgs JSON string of arguments to pass to the procedure, or nullptr for no arguments.
	 * \param[in] in_szOptions JSON string of options to pass to the procedure, or nullptr for no options.
	 * \param[in] in_pAlloc Allocator used to allocate memory for the results or the error.
	 * \param[out] out_szResults JSON string (utf-8) containing the results, if any.
	 * \param[out] out_szError JSON string (utf-8) containing the error, if any.
	 */
	void(*WaapiCall)(
		const struct ak_wwise_plugin_host_v1* in_this,
		const char* in_szUri,
		const char* in_szArgs,
		const char* in_szOptions,
		AK::IAkPluginMemAlloc* in_pAlloc,
		char** out_szResults,
		char** out_szError
	);
};


/**
 * \brief API to receive host's update notifications.
 */
struct ak_wwise_plugin_notifications_host_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for receiving notifications on host changes events.
	using Instance = ak_wwise_plugin_notifications_host_instance_v1;

	ak_wwise_plugin_notifications_host_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_HOST, 1)
	{}
#endif

	/**
	 * \brief Received when the current platform changes.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidCurrentPlatform The unique ID of the new platform.
	 * 
	 * \sa
	 * - \ref wwiseplugin_platformchange
	 */
	void(*NotifyCurrentPlatformChanged)(
		struct ak_wwise_plugin_notifications_host_instance_v1* in_this,
		const GUID * in_guidCurrentPlatform		///< The unique ID of the new platform
	);
};


#define AK_WWISE_PLUGIN_HOST_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST, 1)
#define AK_WWISE_PLUGIN_HOST_V1_CTOR() \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_HOST_V1_ID() \
}

#define AK_WWISE_PLUGIN_NOTIFICATIONS_HOST_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_HOST, 1)
#define AK_WWISE_PLUGIN_NOTIFICATIONS_HOST_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_NOTIFICATIONS_HOST_V1_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CHost = ak_wwise_plugin_host_v1;

		/// \copydoc ak_wwise_plugin_host_v1
		class Host : public CBaseInstanceGlue<CHost>
		{
		public:
			using Interface = CHost;
			using Instance = CHost::Instance;

			/**
			 * \brief The interface type, as requested by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as requested by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST
			};
			/**
			 * \brief The interface version, as requested by this plug-in.
			 */
			enum : InterfaceVersion
			{
				/**
				 * \brief The interface version, as requested by this plug-in.
				 */
				k_interfaceVersion = 1
			};

			/**
			 * \brief Retrieves the current platform identifier.
			 * 
			 * This can be passed to any function that has a parameter for a platform ID, such as GetValue() or
			 * SetValue(), when you want to make the call for the currently active platform.
			 * 
			 * \return The unique ID of the current platform.
			 */
			inline GUID GetCurrentPlatform() const { return g_cinterface->GetCurrentPlatform(g_cinterface); }

			/**
			 * \brief Retrieves the current base platform identifier.
			 * 
			 * \return The unique ID of the current base platform.
			 */
			inline BasePlatformID GetCurrentBasePlatform() const { return g_cinterface->GetCurrentBasePlatform(g_cinterface); }

			/**
			 * \brief Retrieves the requested playback base platform of the Authoring tool.
			 * 
			 * \return The unique base ID of the requested playback's platform.
			 */
			inline BasePlatformID GetDefaultNativeAuthoringPlaybackPlatform() const { return g_cinterface->GetDefaultNativeAuthoringPlaybackPlatform(g_cinterface); }

			/**
			 * \brief Retrieves the requested playback platform of the Authoring tool.
			 * 
			 * \return The unique ID of the requested playback's platform.
			 */
			inline GUID GetAuthoringPlaybackPlatform() const { return g_cinterface->GetAuthoringPlaybackPlatform(g_cinterface); }

			/**
			 * \brief Use this function to tell Wwise that something other than properties has changed within the plug-in.
			 * 
			 * This will set the plugin dirty (indicating there are unsaved changes) and GetPluginData will be called when
			 * the plug-in is about to play in Wwise. This will transfer the internal data to the Sound Engine part of
			 * the plug-in.
			 * 
			 * Use ALL_PLUGIN_DATA_ID to indicate that all the data has to be refreshed.
			 * 
			 * \param[in] in_idData Data needed to be updated.
			 * \param[in] in_bMakeProjectDirty Whether project needs saving.
			 */
			inline void NotifyInternalDataChanged(AkPluginParamID in_idData, bool in_bMakeProjectDirty) { g_cinterface->NotifyInternalDataChanged(this, in_idData, in_bMakeProjectDirty); }

			/**
			 * \brief Obtain licensing status for the plug-in.
			 * 
			 * Refer to \ref wwiseplugin_dll_license for more information.
			 * 
			 * \param[in] in_guidPlatform GUID of the platform.
			 * \param[out] out_eType License Type.
			 * \param[out] out_eStatus License Status.
			 * \param[out] out_uDaysToExpiry Days until license expiry.
			 */
			inline void GetLicenseStatus(
				const GUID& in_guidPlatform,
				LicenseType& out_eType,
				LicenseStatus& out_eStatus,
				uint32_t& out_uDaysToExpiry
			) const
			{
				g_cinterface->GetLicenseStatus(this, &in_guidPlatform, &out_eType, &out_eStatus, &out_uDaysToExpiry);
			}

			/**
			 * \brief Obtain licensing status for a plug-in-specific asset ID.
			 * 
			 * Refer to \ref wwiseplugin_dll_license for more information.
			 * 
			 * \param[in] in_guidPlatform GUID of the platform.
			 * \param[in] in_uAssetID ID of the asset.
			 * \param[out] out_eType License Type.
			 * \param[out] out_eStatus License Status.
			 * \param[out] out_uDaysToExpiry Days until license expiry.
			 */
			inline void GetAssetLicenseStatus(
				const GUID& in_guidPlatform,
				AkUInt32 in_uAssetID,
				LicenseType& out_eType,
				LicenseStatus& out_eStatus,
				uint32_t& out_uDaysToExpiry
			) const
			{
				g_cinterface->GetAssetLicenseStatus(this, &in_guidPlatform, in_uAssetID, &out_eType, &out_eStatus, &out_uDaysToExpiry);
			}

			/**
			 * \brief Find and call the specified procedure.
			 * 
			 * Calls made using this function are always blocking.
			 * 
			 * \param[in] in_szUri URI of the procedure to call.
			 * \param[in] in_szArgs JSON string of arguments to pass to the procedure, or nullptr for no arguments.
			 * \param[in] in_szOptions JSON string of options to pass to the procedure, or nullptr for no options.
			 * \param[in] in_alloc Allocator used to allocate memory for the results or the error.
			 * \param[out] out_szResults JSON string (utf-8) containing the results, if any.
			 * \param[out] out_szError JSON string (utf-8) containing the error, if any.
			 */
			inline void WaapiCall(
				const char* in_szUri,
				const char* in_szArgs,
				const char* in_szOptions,
				AK::IAkPluginMemAlloc& in_alloc,
				char*& out_szResults,
				char*& out_szError
			) const
			{
				g_cinterface->WaapiCall(g_cinterface, in_szUri, in_szArgs, in_szOptions, &in_alloc, &out_szResults, &out_szError);
			}
		};

		/// Notifications namespace
		namespace Notifications
		{
			using CHost_ = ak_wwise_plugin_notifications_host_v1;

			/// \copydoc ak_wwise_plugin_notifications_host_v1
			class Host_ : public CHost_::Instance
			{
			public:
				/**
				 * \copydoc CHost_::Instance
				 */
				using Instance = CHost_::Instance;

				/**
				 * \brief The interface type, as provided by this plug-in.
				 */
				enum : InterfaceTypeValue
				{
					/**
					 * \brief The interface type, as provided by this plug-in.
					 */
					k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_HOST
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
				struct Interface : public CHost_
				{
					using Instance = Host_;
					Interface()
					{
						CHost_::NotifyCurrentPlatformChanged = [](
							struct ak_wwise_plugin_notifications_host_instance_v1* in_this,
							const GUID * in_guidCurrentPlatform)
						{
							static_cast<Instance*>(in_this)->NotifyCurrentPlatformChanged(
								*in_guidCurrentPlatform);
						};
					}
				};

				InterfacePtr GetInterfacePointer() {
					static Interface g_interface;
					return &g_interface;
				}
				CHost_::Instance* GetInstancePointer() {
					return this;
				}
				const CHost_::Instance* GetInstancePointer() const {
					return this;
				}

				Host_() :
					CHost_::Instance()
				{
				}

				virtual ~Host_() {}

				/// This function is called by Wwise when the current platform changes.
				/// \warning This function is guaranteed to be called by a single thread at a time.
				/// \sa
				/// - \ref wwiseplugin_platformchange
				virtual void NotifyCurrentPlatformChanged(
					const GUID & in_guidCurrentPlatform		///< The unique ID of the new platform
				) {}
			};
		} // of namespace Notifications

		/**
		 * \brief Requests a Host interface, provided as m_host variable.
		 * 
		 * Deriving your plug-in class from RequestHost will automatically request both Host and
		 * Notifications::Host_ interfaces. From this point, you will be able to derive from the virtual
		 * functions as defined in Notifications::Host_, and access the host-provided functions in the
		 * \c m_host variable.
		 */
		using RequestHost = RequestedHostInterface<Host>;

	} // of namespace V1

	/// Latest version of the C Host interface.
	using CHost = V1::CHost;
	/// Latest version of the C++ Host interface.
	using Host = V1::Host;
	/// Latest version of the requested C++ Host interface.
	using RequestHost = V1::RequestHost;

	namespace Notifications
	{
		/// Latest version of the C Host notification interface.
		using CCHost = V1::Notifications::Host_;
		/// Latest version of the C++ Host notification interface.
		using Host = V1::Notifications::Host_;
	}

	AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE(Host, host,, public Notifications::Host);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(Host);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(Host);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(Notifications::Host);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(Notifications::Host);
} // of namespace AK::Wwise::Plugin

#endif
