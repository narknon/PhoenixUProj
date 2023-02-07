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
 * \brief Wwise Authoring Plug-ins - Provides links to the related backend and frontend instances.
 * \file AK/Wwise/Plugin/PluginLinks.h
 */

#pragma once

#include "PluginInfoGenerator.h"

/**
 * \brief Host API to retrieve a link to the plug-in's backend instance.
 * 
 * Useful for the Frontend (GUI) when a special function must be called to get a value, or update elements.
 */
struct ak_wwise_plugin_link_backend_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base host-provided instance to retrieve the related backend instance, as shown in the frontend.
	using Instance = ak_wwise_plugin_link_backend_instance_v1;
	ak_wwise_plugin_link_backend_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_LINK_BACKEND, 1)
	{}
#endif

	/**
	 * \brief Retrieves a link to the plug-in's backend instance.
	 *
	 * \aknote The returned pointer might be modified in the frontend lifetime. For example, a plug-in that would undo
	 *         and redo a plug-in creation might return a different value. As such, you should not store the backend
	 *         pointer in a class member, but query it at every operation. \endaknote
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return Base pointer of the backend instance.
	 */
	ak_wwise_plugin_backend_instance* (*Get)(
		const ak_wwise_plugin_link_backend_instance_v1* in_this
	);
};

/**
 * \brief Host API to retrieve a link to the plug-in's frontend interfaces.
 * 
 * Useful for the Backend when there are special properties that don't use property sets.
 */
struct ak_wwise_plugin_link_frontend_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base host-provided instance to retrieve the related frontend instances related to the current backend.
	using Instance = ak_wwise_plugin_link_frontend_instance_v1;
	ak_wwise_plugin_link_frontend_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_LINK_FRONTEND, 1)
	{}
#endif

	/**
	 * \brief Retrieves an array of the plug-in's frontend instances.
	 * 
	 * \aknote The returned array is a temporary TLS pointer that is meant to be retrieved and processed immediately to
	 *         execute commands. You should not store this data. \endaknote
	 *
	 * \param[in] in_this Current instance of this interface.
	 * \param[out] out_count How many frontend instances are in the array.
	 * \return Temporary pointer to the array of frontend instances.
	 */
	ak_wwise_plugin_frontend_instance** (*GetArray)(
		const ak_wwise_plugin_link_frontend_instance_v1* in_this,
		int* out_count
	);
};

#define AK_WWISE_PLUGIN_LINK_BACKEND_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_LINK_BACKEND, 1)
#define AK_WWISE_PLUGIN_LINK_BACKEND_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_LINK_BACKEND_ID(), in_pluginInfo, in_data) \
}

#define AK_WWISE_PLUGIN_LINK_FRONTEND_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_LINK_FRONTEND, 1)
#define AK_WWISE_PLUGIN_LINK_FRONTEND_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_LINK_FRONTEND_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CLinkBackend = ak_wwise_plugin_link_backend_v1;
		using CLinkFrontend = ak_wwise_plugin_link_frontend_v1;

		/// \copydoc ak_wwise_plugin_link_backend_v1
		class LinkBackend : public CBaseInstanceGlue<CLinkBackend>
		{
		public:
			using Interface = CLinkBackend;
			using Instance = CLinkBackend::Instance;

			/**
			 * \brief The interface type, as requested by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as requested by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_LINK_BACKEND
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
			 * \brief Retrieves a link to the plug-in's backend instance.
			 *
			 * \aknote The returned pointer might be modified in the frontend lifetime. For example, a plug-in that would undo
			 *         and redo a plug-in creation might return a different value. As such, you should not store the backend
			 *         pointer in a class member, but query it at every operation. \endaknote
			 * 
			 * \return Base pointer of the backend instance.
			 */
			inline ak_wwise_plugin_backend_instance* Get() const
			{
				return g_cinterface->Get(this);
			}

			/**
			 * \brief Retrieves a link to the plug-in's backend instance, casted as your C++ Backend class type.
			 *
			 * \aknote The returned pointer might be modified in the frontend lifetime. For example, a plug-in that would undo
			 *         and redo a plug-in creation might return a different value. As such, you should not store the backend
			 *         pointer in a class member, but query it at every operation. \endaknote
			 * 
			 * \tparam Backend Expected type of the backend instance. An unexpected type yields to an undefined result.
			 * \return Pointer of the backend class instance.
			 */
			template<typename Backend>
			inline Backend* As()
			{
				return static_cast<Backend*>(Get());
			}
		};

		/// \copydoc ak_wwise_plugin_link_frontend_v1
		class LinkFrontend : public CBaseInstanceGlue<CLinkFrontend>
		{
		public:
			using Interface = CLinkFrontend;
			using Instance = CLinkFrontend::Instance;

			/**
			 * \brief The interface type, as requested by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as requested by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_LINK_FRONTEND
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
			 * \brief Retrieves an array of the plug-in's frontend instances.
			 * 
			 * \aknote The returned array is a temporary TLS pointer that is meant to be retrieved and processed immediately to
			 *         execute commands. You should not store this data. \endaknote
			 *
			 * \param[out] out_count How many frontend instances are in the array.
			 * \return Temporary pointer to the array of frontend instances.
			 */
			inline ak_wwise_plugin_frontend_instance** GetArray(int* out_count) const
			{
				return g_cinterface->GetArray(this, out_count);
			}

			/**
			 * \brief Applies a function on each plug-in's frontend instances.
			 * 
			 * \aknote The frontend instances passed to the function are temporary TLS pointers that are meant to be retrieved
			 *         and processed immediately to execute commands. You should not store this data. \endaknote
			 *
			 * \tparam Frontend Expected type of the frontend instances (optional). If no explicit type is provided, the caller
			 *         needs to manually perform the cast to the expected frontend instance type. If an explicit type is
			 *         provided, the frontend instances will automatically be casted to the provided type and then forwarded
			 *         to in_operation if the cast was successful.
			 * \param[in] in_operation Function, functor or lambda taking a pointer of Frontend as parameter.
			 */
			template<typename Frontend = ak_wwise_plugin_frontend_instance, typename Functor>      
			inline void ForEach(Functor in_operation) const
			{
				int count = 0;
				auto frontends = GetArray(&count);
				for (int index = 0; index < count; ++index)
				{
					if constexpr (std::is_same_v<Frontend, ak_wwise_plugin_frontend_instance>)
					{
						in_operation(frontends[index]);
					}
					else if (auto* frontend = dynamic_cast<Frontend*>(frontends[index]))
					{
						in_operation(frontend);
					}
				}
			}
		};

		using RequestLinkBackend = RequestedHostInterface<LinkBackend>;
		using RequestLinkFrontend = RequestedHostInterface<LinkFrontend>;

	} // of namespace V1

	/// Latest version of the C LinkBackend interface.
	using CLinkBackend = V1::CLinkBackend;
	/// Latest version of the C++ LinkBackend interface.
	using LinkBackend = V1::LinkBackend;
	/// Latest version of the requested C++ LinkBackend interface.
	using RequestLinkBackend = V1::RequestLinkBackend;

	/// Latest version of the C LinkFrontend interface.
	using CLinkFrontend = V1::CLinkFrontend;
	/// Latest version of the C++ LinkFrontend interface.
	using LinkFrontend = V1::LinkFrontend;
	/// Latest version of the requested C++ LinkFrontend interface.
	using RequestLinkFrontend = V1::RequestLinkFrontend;

	AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE(LinkBackend, backend);
	AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE(LinkFrontend, frontend);

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(LinkBackend);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(LinkBackend);

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(LinkFrontend);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(LinkFrontend);
} // of namespace AK::Wwise::Plugin

#endif
