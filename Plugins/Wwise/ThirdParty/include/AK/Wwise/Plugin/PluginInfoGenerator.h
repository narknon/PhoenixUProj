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
 * \brief Wwise Authoring Plug-ins - C++ class helper to automatically determine the plug-in interfaces used in a class.
 * \file AK/Wwise/Plugin/PluginInfoGenerator.h
 */

#pragma once

#include "PluginContainer.h"

#ifdef __cplusplus
#include <array>
#include <memory>

/**
 * \brief The specific version for native plug-in interfaces. Must be identical down to the build number.
 * \warning Private API. Using this makes the plug-in compatible with this Authoring's build version only.
 */
#define AK_WWISESDK_VERSION_NATIVE_COMBINED ((AK_WWISESDK_VERSION_MAJOR << 19) | (AK_WWISESDK_VERSION_MINOR << 16) | AK_WWISESDK_VERSION_SUBMINOR)

namespace AK::Wwise::Plugin
{
	using InterfaceType = decltype(BaseInterface::m_interface);					///< PluginInfoGenerator: Type for the m_interface value in BaseInterface
	using InterfaceTypeValue = std::underlying_type<InterfaceType>::type;		///< PluginInfoGenerator: Underlying storage type for the m_interface value in BaseInterface
	using InterfaceVersion = decltype(BaseInterface::m_version);				///< PluginInfoGenerator: Type for the m_version value in BaseInterface

	/**
	 * \brief The interface information of the plug-in currently being instantiated.
	 * 
	 * When the host calls the Instantiate of the plug-in, PluginInfoGenerator will automatically set this thread
	 * variable to the provided \c in_pluginInfo. This allows the interfaces to bind themselves without having
	 * to pass this parameter throughout the constructor.
	 * 
	 * \akwarning This variable is only set up during instantiation. \endakwarning
	 */
	template <bool = false>
	struct PluginInfoTLS
	{
#ifndef _MANAGED
		thread_local
#endif
		static PluginInfo* tls_pluginInfo;
	};

	/**
	 * \brief PluginInfoGenerator: For each plug-in interface type, provides a single static instance used throughout this plug-in container.
	 * 
	 * This uses a C++ template principle where you can define a static variable inside a templated class, and you
	 * can have the compiler generate one unique static instance for each individual templated class.
	 * 
	 * Also, having a class outer shell means the static member can reside in a header and be instantiated in that same
	 * header without the linker refusing multiple definitions.
	 * 
	 * \tparam CInterface Which interface (In C)
	 * 
	 * \sa
	 * - \ref AK::Wwise::Plugin::PluginInfoGenerator
	 */
	template <typename CInterface>
	class CBaseInterfaceGlue
	{
	public:
		using GluedInterface = CInterface;
		static GluedInterface* g_cinterface;									///< The unique instance of the CInterface interface. Defined at nullptr first, overridden by the Host once loaded.
	};
	template<typename CInterface> CInterface* CBaseInterfaceGlue<CInterface>::g_cinterface = nullptr;

	/**
	 * \brief PluginInfoGenerator: Associates an existing C Interface with a variable that can be used. Derives from the instance that uses it.
	 * 
	 * \tparam CInterface The C Interface that needs to be instantiated into a CInstance.
	 * \tparam CInstance The C Instance that will be instantiated. Automatically derived from the CInterface::Instance typedef.
	 * 
	 * \sa
	 * - \ref AK::Wwise::Plugin::PluginInfoGenerator
	 */
	template <typename CInterface, typename CInstance = typename CInterface::Instance>
	class CBaseInstanceGlue : public CInstance, public CBaseInterfaceGlue<CInterface>
	{
	public:
		using Instance = CInstance;
	};

	/**
	 * \brief PluginInfoGenerator: Base class for every C++ instance that retrieves a service from the Wwise Authoring host.
	 * 
	 * Compared to C, where the interface contains all the functions and the instance is an opaque block, the C++
	 * version is the opposite; the instance is a class containing all the methods, and the interface is hidden as
	 * implementation details.
	 * 
	 * The HostInterfaceGlue helper class provides that distinction. Depending on the in_baseInstance parameter,
	 * it will either have only a C interface (true) or also have its default instantiation (false).
	 * 
	 * \tparam CPPInstance The C++ instance to instantiate.
	 * \tparam in_baseInstance Only provide a bridge (true) or also a default instance (false).
	 * 
	 * \sa
	 * - \ref AK::Wwise::Plugin::PluginInfoGenerator
	 */
	template <typename CPPInstance, bool in_baseInstance>
	class HostInterfaceGlue : private ak_wwise_plugin_cpp_base_instance
	{
	public:
		enum : InterfaceTypeValue { k_interfaceType = CPPInstance::k_interfaceType };
		enum : InterfaceVersion { k_interfaceVersion = CPPInstance::k_interfaceVersion };
		using GluedInterface = typename CPPInstance::GluedInterface;
		using Instance = CPPInstance;
		using CInstance = typename CPPInstance::Instance;

		static GluedInterface g_cppinterface;									///< The unique interface for this plug-in interface.
	};
	template<typename CPPInstance, bool in_baseInstance> typename CPPInstance::GluedInterface HostInterfaceGlue<CPPInstance, in_baseInstance>::g_cppinterface;

	template <typename CPPInstance>
	class HostInterfaceGlue<CPPInstance, true> : public HostInterfaceGlue<CPPInstance, false>
	{
	public:
		using Super = HostInterfaceGlue<CPPInstance, false>;
		using CInstance = typename Super::CInstance;
		using Instance = typename Super::Instance;
		using GluedInterface = typename Super::GluedInterface;

		CPPInstance* m_instance;												///< The default instance for this plug-in interface.

		HostInterfaceGlue(CInstance* in_instance) : m_instance(static_cast<CPPInstance*>(in_instance)) {}
		HostInterfaceGlue() : HostInterfaceGlue(GetCInterfaceInstance()) {}

	private:
		/**
		 * \brief Locate the C interface of our CPPInstance in our current plug-in.
		 * 
		 * \ref PluginInfoTLS<>::tls_pluginInfo is used to retrieve the plug-in we are trying to instantiate.
		 * \return CInstance* The C interface related to our CPPInstance.
		 */
		static CInstance* GetCInterfaceInstance()
		{
			auto pluginInfo = PluginInfoTLS<>::tls_pluginInfo;
			for (int i = 0; i < pluginInfo->m_arraySize; ++i)
			{
				InterfaceArrayItem& intf = pluginInfo->m_interfaces[i];
				if (intf.m_interface->m_interface == static_cast<InterfaceType>(HostInterfaceGlue::k_interfaceType) &&
					intf.m_interface->m_version == HostInterfaceGlue::k_interfaceVersion)
				{
					return static_cast<CInstance*>(intf.m_instance);
				}
			}
			return nullptr;
		}
	};


	/**
	 * \brief PluginInfoGenerator: Compile-time dictionary of known interface-version.
	 * 
	 * Used so we can ask a KnownInterfaceClass<in_interface, in_version> and receive which class and interface it points to.
	 * 
	 * \tparam in_interfaceType 
	 * \tparam in_interfaceVersion
	 * 
	 * \sa
	 * - \ref AK::Wwise::Plugin::PluginInfoGenerator
	 */
	template <InterfaceType in_interfaceType, InterfaceVersion in_interfaceVersion>
	struct KnownInterfaceClass
	{
		using Type = void;
		using Interface = void;
	};

/**
 * \brief PluginInfoGenerator: Defines a C++ known interface-version to Type dictionary entry.
 * 
 * \aknote Macro assumes a AK::Wwise::Plugin namespace root. \endaknote
 * 
 * \param in_name Class name.
 * 
 * \sa
 * - \ref AK::Wwise::Plugin::PluginInfoGenerator
 */
#define AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(in_name) \
	template<> struct KnownInterfaceClass<(AK::Wwise::Plugin::InterfaceType)in_name::k_interfaceType, in_name::k_interfaceVersion> \
	{ \
		using Type = in_name; \
		using Interface = typename Type::Interface; \
	}


	/**
	 * \brief PluginInfoGenerator: Requests a host-provided service, and optionally receives a variable containing the default instance.
	 * 
	 * \tparam T The C++ class to request.
	 * 
	 * \sa
	 * - \ref AK::Wwise::Plugin::PluginInfoGenerator
	 */
	template <typename T>
	class RequestedHostInterface {};

/**
 * \brief PluginInfoGenerator: Creates a C++ host specialization for interface class specified in in_name, and creates a variable instance named m_ followed by in_varname.
 * 
 * \aknote Macro assumes a AK::Wwise::Plugin namespace root. \endaknote
 * 
 * \param in_name Name of the C++ class
 * \param in_varname Name of the variable to instantiate. Will be prefixed by m_. A second static variable is created with g_ prefix, containing the C++ interface.
 * \param ... Supplemental class derivations can be added as additional parameters
 * 
 * \sa
 * - \ref AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE_NO_BASE_INSTANCE
 * - \ref AK::Wwise::Plugin::PluginInfoGenerator
 */
#define AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE(in_name, in_varname, ...) \
	template <> \
	class RequestedHostInterface<in_name> : public HostInterfaceGlue<in_name, true> __VA_ARGS__ \
	{ \
	public: \
		using HostInterfaceDefinition = HostInterfaceGlue<in_name, true>; \
		in_name::Interface& g_ ## in_varname ## Interface = HostInterfaceDefinition::g_cppinterface; \
		HostInterfaceDefinition::Instance& m_ ## in_varname = *HostInterfaceDefinition::m_instance; \
		\
		RequestedHostInterface() {} \
	}

/**
 * \brief PluginInfoGenerator: Creates a C++ host specialization for interface class specified in in_name.
 * 
 * \aknote Macro assumes a AK::Wwise::Plugin namespace root. \endaknote
 * 
 * \param in_name Name of the C++ class
 * \param in_varname Name of the static variable to be created with g_ prefix, containing the C++ interface.
 * \param ... Supplemental class derivations can be added as additional parameters
 * 
 * \sa
 * - \ref AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE
 * - \ref AK::Wwise::Plugin::PluginInfoGenerator
 */
#define AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE_NO_BASE_INSTANCE(in_name, in_varname) \
	template <> \
	class RequestedHostInterface<in_name> : public HostInterfaceGlue<in_name, false> \
	{ \
	public: \
		using HostInterfaceDefinition = HostInterfaceGlue<in_name, false>; \
		in_name::Interface& g_ ## in_varname ## Interface = HostInterfaceDefinition::g_cppinterface; \
		\
		RequestedHostInterface() {} \
	}

	/**
	 * \brief PluginInfoGenerator: Defines a compile-time dictionary with the latest version known to the SDK for each interface.
	 * 
	 * \tparam in_interfaceType The interface ID to define.
	 * 
	 * \sa
	 * - \ref AK::Wwise::Plugin::PluginInfoGenerator
	 */
	template <InterfaceType in_interfaceType>
	struct LatestInterfaceVersion
	{
		enum { k_interfaceVersion = 1 };
	};

/**
 * \brief PluginInfoGenerator: Creates a C++ link to the latest version known to the SDK for each interface.
 * 
 * \param in_interface C++ interface to retrieve the interface type and version.
 * 
 * \sa
 * - \ref AK::Wwise::Plugin::PluginInfoGenerator
 */
#define AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(in_interface) \
	template <> \
	struct LatestInterfaceVersion<(InterfaceType)in_interface::k_interfaceType> \
	{ \
		enum { k_interfaceVersion = (InterfaceVersion)in_interface::k_interfaceVersion }; \
	}


	// These are the default structural known interface classes / Current Interface version
	template<> struct KnownInterfaceClass<AK_WWISE_PLUGIN_INTERFACE_TYPE_PLUGIN_CONTAINER, 1>
	{
		using Type = void;
		using Interface = PluginContainer;
	};
	template<> struct LatestInterfaceVersion<AK_WWISE_PLUGIN_INTERFACE_TYPE_PLUGIN_CONTAINER>
	{
		enum { k_interfaceVersion = 1 };
	};

	/**
	 * \brief C++ PluginInfo Generator.
	 * 
	 * Retrieves the list of plug-in interfaces required by a plug-in through derivation, and automatically creates a
	 * related ak_wwise_plugin_info structure.
	 * 
	 * Compared to a manually generated C version, the generated structure is done through a function that fills all
	 * the required data. Since it's a static global function called only once, and contains only value stores, the cost
	 * is, so far, quite minimal.
	 * 
	 * \tparam PluginT The plug-in class that needs to be instantiated in order to use that plug-in.
	 */
	template <typename PluginT>
	struct PluginInfoGenerator
	{
		/**
		 * \brief Compile-time dictionary about a particular interface type.
		 * 
		 * \tparam in_interfaceType The interface ID with the information to request.
		 */
		template <InterfaceType in_interfaceType>
		struct InterfaceInfo
		{
			enum
			{
				/**
				 * \brief Most up-to-date version of the interface in the current SDK.
				 */
				k_latestInterfaceVersion = LatestInterfaceVersion<in_interfaceType>::k_interfaceVersion
			};

			/**
			 * \brief Compile-time container of version numbers.
			 * 
			 * \tparam in_versions,... Version numbers to store in the container in ascending order.
			 */
			template <uint32_t... in_versions>
			struct VersionPack : public std::integer_sequence<uint32_t, in_versions...>
			{
				/**
				 * \brief Get the latest version stored in the container. Assumes the container is sorted in ascending order.
				 * 
				 * \return uint32_t The latest version of the pack.
				 */
				static constexpr uint32_t GetLatest()
				{
					return (in_versions, ...); // Fold-expression with comma operator
				}
			};

			/**
			 * \brief Recursively accumulate each version of the interface requested or provided by the plug-in (there should be one or none).
			 * 
			 * \aknote Assumes the interface versions range from 1 to k_latestInterfaceVersion, except for native interfaces. \endaknote
			 * 
			 * \return A pair containing a VersionPack of the requested versions and a VersionPack of the provided versions of the interface.
			 * 
			 * \sa
			 * - \ref k_latestInterfaceVersion
			 * - \ref VersionPack
			 */
			template <uint32_t in_interfaceVersion = k_latestInterfaceVersion, uint32_t... in_requestedVersions, uint32_t... in_providedVersions>
			static constexpr auto GetUsedInterfaceVersions(VersionPack<in_requestedVersions...> = {}, VersionPack<in_providedVersions...> = {})
			{
				if constexpr (in_interfaceVersion >= 1)
				{
					using InterfaceClass = typename KnownInterfaceClass<in_interfaceType, in_interfaceVersion>::Type;
					using RequestedInterfaceVersions = std::conditional_t<
						std::is_base_of_v<RequestedHostInterface<InterfaceClass>, PluginT>,
						VersionPack<in_interfaceVersion, in_requestedVersions...>,
						VersionPack<in_requestedVersions...>>;
					using ProvidedInterfaceVersions = std::conditional_t<
						std::is_base_of_v<InterfaceClass, PluginT>,
						VersionPack<in_interfaceVersion, in_providedVersions...>,
						VersionPack<in_providedVersions...>>;
					return GetUsedInterfaceVersions<
						// If the interface is native, there can only be a single version of it
						k_latestInterfaceVersion == AK_WWISESDK_VERSION_NATIVE_COMBINED ? 0 : in_interfaceVersion - 1>
						(RequestedInterfaceVersions(), ProvidedInterfaceVersions());
				}
				else
				{
					return std::pair<VersionPack<in_requestedVersions...>, VersionPack<in_providedVersions...>>();
				}
			}

			/**
			 * \brief Pair type containing a VersionPack of the requested versions and a VersionPack of the provided versions of the interface.
			 * 
			 * \sa
			 * - \ref GetUsedInterfaceVersions
			 * - \ref VersionPack
			 */
			using UsedInterfaceVersions = decltype(GetUsedInterfaceVersions());

			/**
			 * \brief VersionPack containing the requested versions of the interface by the plug-in.
			 * 
			 * \sa
			 * - \ref UsedInterfaceVersions
			 * - \ref VersionPack
			 */
			using RequestedInterfaceVersions = typename UsedInterfaceVersions::first_type;

			/**
			 * \brief VersionPack containing the provided versions of the interface by the plug-in.
			 * 
			 * \sa
			 * - \ref UsedInterfaceVersions
			 * - \ref VersionPack
			 */
			using ProvidedInterfaceVersions = typename UsedInterfaceVersions::second_type;

			enum : bool
			{
				/**
				 * \brief Is the interface requested (interface provided by host) by the generated plug-in class.
				 * 
				 * \sa
				 * - \ref RequestedInterfaceVersions
				 */
				k_requested = RequestedInterfaceVersions::size() >= 1,

				/**
				 * \brief Is the interface provided (interface used by host) by the generated plug-in class.
				 * 
				 * \sa
				 * - \ref ProvidedInterfaceVersions
				 */
				k_provides = ProvidedInterfaceVersions::size() >= 1,

				/**
				 * \brief Are we using this interface in our plug-in.
				 */
				k_has = k_requested || k_provides
			};

			static_assert(RequestedInterfaceVersions::size() <= 1, "Plugin can't request more than one version of the same interface");
			static_assert(ProvidedInterfaceVersions::size() <= 1, "Plugin can't provide more than one version of the same interface");
			static_assert(!(k_requested && k_provides), "Requested interfaces can't be provided and provided interfaces can't be requested");

			/**
			 * \brief Extract the version of the interface used by the plug-in.
			 * 
			 * \aknote If this interface hasn't been requested or provided at all by the plug-in, k_latestInterfaceVersion is returned. \endaknote
			 * 
			 * \return uint32_t The version of the interface.
			 * 
			 * \sa
			 * - \ref RequestedInterfaceVersions
			 * - \ref ProvidedInterfaceVersions
			 * - \ref k_latestInterfaceVersion
			 */
			static constexpr uint32_t GetInterfaceVersion()
			{
				if constexpr (k_requested)
				{
					return RequestedInterfaceVersions::GetLatest();
				}
				else if constexpr (k_provides)
				{
					return ProvidedInterfaceVersions::GetLatest();
				}
				else
				{
					return k_latestInterfaceVersion;
				}
			}

			enum
			{
				/**
				 * \brief Version of the interface used by the plug-in or k_latestInterfaceVersion if unused.
				 * 
				 * \sa
				 * - \ref GetInterfaceVersion
				 * - \ref k_latestInterfaceVersion
				 */
				k_interfaceVersion = GetInterfaceVersion()
			};

			/**
			 * \brief Interface class of the versioned interface type.
			 * 
			 * \sa
			 * - \ref AK::Wwise::Plugin::KnownInterfaceClass
			 * - \ref k_interfaceVersion
			 */
			using InterfaceClass = typename KnownInterfaceClass<in_interfaceType, k_interfaceVersion>::Type;

			/**
			 * \brief Casts the plug-in class to the requested interface class.
			 * 
			 * \aknote This needs to be in a template, as the interface might not be castable. \endaknote
			 */
			template <bool>
			struct ToInterfaceClassImpl
			{
				constexpr static inline InterfaceClass* Cast(PluginT* in_plugin)
				{
					return static_cast<InterfaceClass*>(in_plugin);
				}
			};

			/**
			 * \brief Casts the plug-in class to the requested interface class.
			 */
			using ToInterfaceClass = ToInterfaceClassImpl<k_has>;

			/**
			 * \brief Get a Placeholder Pointer object.
			 * 
			 * \return BaseInterface* An empty Base Interface pointing to the proper type and version. This is used
			 *         when requesting an interface with the host, and the placeholder object pointer will get replaced.
			 */
			static BaseInterface* GetPlaceholderPointer()
			{
				static BaseInterface s_placeholder(in_interfaceType, k_interfaceVersion);
				return &s_placeholder;
			}
		};

		/**
		 * \brief Count the number of interfaces we are currently using.
		 * 
		 * \sa
		 * - \ref k_interfaceCount
		 */
		template <InterfaceType in_interface = (InterfaceType)(AK_WWISE_PLUGIN_INTERFACE_TYPE_NUM - 1)>
		static constexpr size_t CountInterfaces()
		{
			if constexpr (in_interface != AK_WWISE_PLUGIN_INTERFACE_TYPE_UNKNOWN)
			{
				if constexpr (InterfaceInfo<in_interface>::k_has)
				{
					return CountInterfaces<(InterfaceType)(in_interface - 1)>() + 1;
				}
				else
				{
					return CountInterfaces<(InterfaceType)(in_interface - 1)>();
				}
			}
			else
			{
				return 0;
			}
		}

		enum : size_t
		{
			/**
			 * \brief Number of interfaces we are currently using.
			 * 
			 * \sa
			 * - \ref CountInterfaces
			 */
			k_interfaceCount = CountInterfaces()
		};

		/**
		 * \brief Generates the InterfaceArrayItem for our particular type.
		 * 
		 * \tparam in_interfaceType Interface ID
		 */
		template <InterfaceType in_interfaceType>
		static constexpr InterfaceArrayItem GenerateInterface()
		{
			if constexpr (InterfaceInfo<in_interfaceType>::k_requested)
			{
				return InterfaceArrayItem(InterfaceInfo<in_interfaceType>::GetPlaceholderPointer());
			}
			else if constexpr (InterfaceInfo<in_interfaceType>::k_provides)
			{
				return InterfaceArrayItem(InterfaceInfo<in_interfaceType>::ToInterfaceClass::Cast(nullptr)->GetInterfacePointer());
			}
			else
			{
				return InterfaceArrayItem();
			}
		}

		/**
		 * \brief Recursively generates an interface array of all the Interfaces pointers.
		 * 
		 * \tparam in_interfaceType The current interface being processed. They are processed recursively from max to 0
		 */
		template <InterfaceType in_interfaceType>
		static constexpr void GenerateInterfaceArray(InterfaceArrayItem out_interfaces[k_interfaceCount], int in_count, InterfaceArrayItem)
		{
			if constexpr (in_interfaceType != AK_WWISE_PLUGIN_INTERFACE_TYPE_UNKNOWN && in_interfaceType != AK_WWISE_PLUGIN_INTERFACE_TYPE_NUM)
			{
				GenerateInterfaceArray<(InterfaceType)(in_interfaceType + 1)>(
					out_interfaces,
					in_count + (InterfaceInfo<in_interfaceType>::k_has ? 1 : 0),
					InterfaceInfo<in_interfaceType>::k_has ? out_interfaces[in_count] = GenerateInterface<in_interfaceType>() : InterfaceArrayItem());
			}
		}

		static constexpr InterfaceArrayItem* GenerateInterfaceArray(InterfaceArrayItem out_interfaces[k_interfaceCount])
		{
			GenerateInterfaceArray<(InterfaceType)1>(out_interfaces, 0, InterfaceArrayItem());
			return out_interfaces;
		}

		/**
		 * \brief Generates the constructor for our particular type
		 * 
		 * \tparam in_interfaceType Interface ID
		 */
		template <InterfaceType in_interfaceType>
		struct GenerateConstructor
		{
			static inline void UpdateCInterface(const InterfaceArrayItem& in_original)
			{
				if constexpr (InterfaceInfo<in_interfaceType>::k_requested)
				{
					// Update our global interface (that's used in calls) to the new value
					using InterfaceToUpdate = typename KnownInterfaceClass<in_interfaceType, InterfaceInfo<in_interfaceType>::k_interfaceVersion>::Interface;
					CBaseInterfaceGlue<InterfaceToUpdate>::g_cinterface = static_cast<InterfaceToUpdate*>(in_original.m_interface);
				}
			}

			static inline void Constructor(InterfaceArrayItem& out_interface, const InterfaceArrayItem& in_original, PluginT* in_instance)
			{
				if constexpr (InterfaceInfo<in_interfaceType>::k_requested)
				{
					out_interface.m_interface = in_original.m_interface;
					out_interface.m_instance = in_original.m_instance;
				}
				else if constexpr (InterfaceInfo<in_interfaceType>::k_provides)
				{
					out_interface.m_interface = in_original.m_interface;
					out_interface.m_instance = InterfaceInfo<in_interfaceType>::ToInterfaceClass::Cast(in_instance)->GetInstancePointer();
				}
			}
		};

		/**
		 * \brief Recursively generates the constructors and interface pointer updater for all the Interfaces.
		 * 
		 * \tparam in_interfaceType The current interface being processed. They are processed recursively from max to 0
		 */
		template <InterfaceType in_interfaceType = (InterfaceType)(AK_WWISE_PLUGIN_INTERFACE_TYPE_UNKNOWN + 1)>
		struct GenerateConstructorArray
		{
			static inline void UpdateCInterface(const InterfaceArrayItem in_original[k_interfaceCount], int in_count = 0)
			{
				if constexpr (in_interfaceType != AK_WWISE_PLUGIN_INTERFACE_TYPE_NUM)
				{
					if constexpr (InterfaceInfo<in_interfaceType>::k_has)
					{
						GenerateConstructor<in_interfaceType>::UpdateCInterface(in_original[in_count]);
						GenerateConstructorArray<(InterfaceType)(in_interfaceType + 1)>::UpdateCInterface(in_original, in_count + 1);
					}
					else
					{
						GenerateConstructorArray<(InterfaceType)(in_interfaceType + 1)>::UpdateCInterface(in_original, in_count);
					}
				}
			}

			static inline void Constructor(InterfaceArrayItem out_interfaces[k_interfaceCount], const InterfaceArrayItem in_original[k_interfaceCount], PluginT* in_instance, int in_count = 0)
			{
				if constexpr (in_interfaceType != AK_WWISE_PLUGIN_INTERFACE_TYPE_NUM)
				{
					if constexpr (InterfaceInfo<in_interfaceType>::k_has)
					{
						GenerateConstructor<in_interfaceType>::Constructor(out_interfaces[in_count], in_original[in_count], in_instance);
						GenerateConstructorArray<(InterfaceType)(in_interfaceType + 1)>::Constructor(out_interfaces, in_original, in_instance, in_count + 1);
					}
					else
					{
						GenerateConstructorArray<(InterfaceType)(in_interfaceType + 1)>::Constructor(out_interfaces, in_original, in_instance, in_count);
					}
				}
			}
		};

		/**
		 * \brief The unique generator instance for this particular plug-in.
		 * 
		 * This is used to link the generator to the instantiate function, as defined statically.
		 * 
		 * It is known there is only one bridging interface between the C interface of the plug-in and the host, which
		 * means it's effectively limited to instantiating one instance at a time, where the host pre-fills its instance
		 * data, calls the Instantiate function, and then retrieves the new instance, as provided by the
		 * plug-in.
		 * 
		 * As such, this unique g_instance to do instantiation is not a new requirement, but merely an acknowledgement
		 * the Instantiate function is not reentrant.
		 */
		static PluginInfoGenerator* g_instance;

		/**
		 * \brief Current array of interfaces, used in the bridge between host and plug-in.
		 * 
		 * This array is writable and updated both by the host and the plug-in. Its data is then copied to the static
		 * instances of the plug-in (Interface) and copied to a new array, that is returned by the Instantiate method.
		 * 
		 * Contained in the m_pluginInfo member variable.
		 */
		InterfaceArrayItem m_interfaceArray[k_interfaceCount];

		/**
		 * \brief Plug-in instance constructor, as shared with the host.
		 * 
		 * It is currently assumed the in_pluginInfo parameter, as passed, is the same as the one provided in the
		 * ak_wwise_plugin_container structure. As such, in the current version of the SDK, this is not reentrant, as
		 * there is only one structure used to transfer data.
		 * 
		 * \warning This function is not reentrant. See \ref g_instance and \ref m_interfaceArray for more information.
		 * 
		 * \param in_pluginInfo Plug-in structure to instantiate.
		 * \return InterfaceArrayItem* The new instance: A copy of the structure, containing the instantiated pointers.
		 */
		static InterfaceArrayItem* Instantiate(PluginInfo* in_pluginInfo)
		{
			if (!g_instance)
			{
				return nullptr;
			}
			GenerateConstructorArray<>::UpdateCInterface(g_instance->m_interfaceArray);

			// Instantiate the user plug-in
			auto prevPluginInfo = PluginInfoTLS<>::tls_pluginInfo;
			PluginInfoTLS<>::tls_pluginInfo = in_pluginInfo;

			auto plugin = new PluginT;
				
			PluginInfoTLS<>::tls_pluginInfo = prevPluginInfo;

			// Create the resulting array and send it back to the host
			InterfaceArrayItem* result = new InterfaceArrayItem[k_interfaceCount];
			GenerateConstructorArray<>::Constructor(result, g_instance->m_interfaceArray, plugin);
			return result;
		}

		/**
		 * \brief Plug-in instance destructor, as shared to the host.
		 * 
		 * \param in_instance The copy of the structure (instance) to destroy.
		 */
		static void Disembody(InterfaceArrayItem* in_instance)
		{
			// In CPP, our Disembody operation actually takes the first plug-in interface's instance,
			// whatever that is, and casts it to our cpp base instance. They are all with a virtual dtor,
			// so they are equivalent.
			auto voidinstance = in_instance[0].m_instance;
			auto cinstance = reinterpret_cast<ak_wwise_plugin_base_instance*>(voidinstance);
			auto cppinstance = static_cast<ak_wwise_plugin_cpp_base_instance*>(cinstance);
			delete cppinstance;
			delete[] in_instance;
		}

		/**
		 * \brief The unique m_pluginInfo used in the ak_wwise_plugin_container for that particular plug-in.
		 * 
		 * Contains the m_interfaceArray member variable.
		 */
		PluginInfo m_pluginInfo;

		PluginInfoGenerator(PluginRegistration* in_pluginRegistration, uint32_t in_pluginFlags = 0) :
			m_pluginInfo(
				&in_pluginRegistration->m_ulCompanyID,
				&in_pluginRegistration->m_ulPluginID,
				&in_pluginRegistration->m_eType,
				in_pluginFlags,
				in_pluginRegistration,
				Instantiate,
				Disembody,
				k_interfaceCount,
				GenerateInterfaceArray(m_interfaceArray)
			)
		{
			g_instance = this;
		}
		PluginInfoGenerator(
			const AkUInt32* in_companyID,
			const AkUInt32* in_pluginID,
			const AkPluginType* in_pluginType,
			uint32_t in_pluginFlags = 0) :
			m_pluginInfo(
				in_companyID,
				in_pluginID,
				in_pluginType,
				in_pluginFlags,
				nullptr,
				Instantiate,
				Disembody,
				k_interfaceCount,
				GenerateInterfaceArray(m_interfaceArray)
			)
		{
			g_instance = this;
		}
		~PluginInfoGenerator()
		{
			g_instance = nullptr;
		}
	};

	template <bool _>
#ifndef _MANAGED
	thread_local
#endif
	PluginInfo* PluginInfoTLS<_>::tls_pluginInfo = nullptr;

	template <typename PluginT>
	PluginInfoGenerator<PluginT>* PluginInfoGenerator<PluginT>::g_instance = nullptr;
} // of namespace AK::Wwise::Plugin

/// \cond DOXYGEN_SKIP
#define AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME2(prefix,suffix) prefix##suffix
#define AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME1(prefix,suffix) AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME2(prefix, suffix)
/// \endcond

#if defined(DOXYGEN_INCLUDE)
/**
 * \brief Creates an unique PluginInfo instance for the plug-in registration
 */
#define AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME1(UserGeneratedPluginInfo, __COUNTER__)
#elif !defined(__COUNTER__)
#define AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME1(UserGeneratedPluginInfo, __LINE__)
#elif __COUNTER__ == __COUNTER__
#define AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME1(UserGeneratedPluginInfo, __LINE__)
#else
#define AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME1(UserGeneratedPluginInfo, __COUNTER__)
#endif



/**
 * \brief (C++) Declares the plug-in container.
 * 
 * The container name must be the plug-in file/xml name. For example, it should be AkCompressor for AkCompressor.dll/.xml.
 * 
 * \param ContainerName Container name.
 */
#define AK_DECLARE_PLUGIN_CONTAINER(ContainerName) extern AK::Wwise::Plugin::PluginContainer& GetPluginContainer ## ContainerName()

/**
 * \brief (C++) Defines the unique plug-in container.
 * 
 * The container name must be the plug-in file/xml name. For example, it should be AkCompressor for AkCompressor.dll/.xml.
 * 
 * \param ContainerName Container name. 
 */
#define AK_DEFINE_PLUGIN_CONTAINER(ContainerName) \
	AK::Wwise::Plugin::PluginContainer& GetPluginContainer ## ContainerName() \
	{ \
		static AK::Wwise::Plugin::PluginContainer singleton; \
		return singleton; \
	}

/**
 * \brief (C++) Exports the plug-in container for a shared library.
 * 
 * The export name is ak_wwise_plugin_container_export_ContainerName, where ContainerName must be the
 * plug-in file/xml name. For example, it should be AkCompressor for AkCompressor.dll/.xml.
 * 
 * For non-Windows platforms, the export name is ak_wwise_plugin_container_export_libContainerName.
 * 
 * \param ContainerName Container name. 
 */
#ifdef AK_WIN
#define AK_EXPORT_PLUGIN_CONTAINER(ContainerName) \
	extern "C" __declspec(dllexport) AK::Wwise::Plugin::PluginContainer * ak_wwise_plugin_container_export_ ## ContainerName; \
	AK::Wwise::Plugin::PluginContainer * ak_wwise_plugin_container_export_ ## ContainerName = &GetPluginContainer ## ContainerName()
#else
#define AK_EXPORT_PLUGIN_CONTAINER(ContainerName) \
	extern "C" __attribute__ ((visibility ("default"))) AK::Wwise::Plugin::PluginContainer * ak_wwise_plugin_container_export_lib ## ContainerName; \
	AK::Wwise::Plugin::PluginContainer * ak_wwise_plugin_container_export_lib ## ContainerName = &GetPluginContainer ## ContainerName()
#endif

/**
 * \brief (C++) Adds a Wwise Authoring plug-in and a Sound Engine plug-in to a plug-in container.
 * 
 * Creates a custom namespace with custom plug-in info, that contains the generated plug-in info structure. Then,
 * statically points it to the next pointer for the container.
 * 
 * This uses the Sound Engine part to retrieve the plug-in information (Company id, Plug-in ID and Plug-in Type). It
 * also adds up the Sound Engine's registration structure, so the host can initialize this part on first instantiation.
 * 
 * \param ContainerName Container name.
 * \param WwiseClassName Class name of the plug-in to add to the container.
 * \param AudioEngineRegisteredName Sound Engine's class name.
 * 
 * \sa
 * - \ref AK_ADD_PLUGIN_CLASSID_TO_CONTAINER For a version without the Sound Engine part.
 */
#define AK_ADD_PLUGIN_CLASS_TO_CONTAINER(ContainerName, WwiseClassName, AudioEngineRegisteredName) \
	extern AK::PluginRegistration AudioEngineRegisteredName ## Registration; \
	namespace { namespace AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME { \
		static struct UserGeneratedPluginInfo : private AK::Wwise::Plugin::PluginInfoGenerator<WwiseClassName> \
		{ \
			UserGeneratedPluginInfo() : \
				PluginInfoGenerator(&AudioEngineRegisteredName ## Registration) \
			{ \
				m_pluginInfo.m_next = GetPluginContainer ## ContainerName().m_pluginInfos; \
				GetPluginContainer ## ContainerName().m_pluginInfos = &m_pluginInfo; \
			} \
		} g_singleton; \
	} }

/**
 * \brief (C++) Adds a plug-in to a plug-in container.
 * 
 * Creates a custom namespace with custom plug-in info, that contains the generated plug-in info structure. Then,
 * statically points it to the next pointer for the container.
 * 
 * \param ContainerName Container name.
 * \param WwiseClassName Class name of the plug-in to add to the container.
 * \param CompanyID Plug-in vendor's Company ID, as provided by Audiokinetic.
 * \param PluginID Plug-in ID, as provided by Audiokinetic.
 * \param Type Plug-in type.
 * 
 * \sa
 * - \ref AK_ADD_PLUGIN_CLASS_TO_CONTAINER For a version with the Sound Engine part.
 */
#define AK_ADD_PLUGIN_CLASSID_TO_CONTAINER(ContainerName, WwiseClassName, CompanyID, PluginID, Type) \
	namespace { namespace AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME { \
		static struct UserGeneratedPluginInfo : private AK::Wwise::Plugin::PluginInfoGenerator<WwiseClassName> \
		{ \
			const AkUInt32 m_companyID = CompanyID; \
			const AkUInt32 m_pluginID = PluginID; \
			const AkPluginType m_type = Type; \
			UserGeneratedPluginInfo() : \
				PluginInfoGenerator(&m_companyID, &m_pluginID, &m_type) \
			{ \
				m_pluginInfo.m_next = GetPluginContainer ## ContainerName().m_pluginInfos; \
				GetPluginContainer ## ContainerName().m_pluginInfos = &m_pluginInfo; \
			} \
		} g_singleton; \
	} }

/// \deprecated
#define AK_AUDIOPLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME AK_PLUGIN_USERGENERATEDPLUGININFO_NAMESPACE_NAME

/// \deprecated
#define DECLARE_AUDIOPLUGIN_CONTAINER(x) AK_DECLARE_PLUGIN_CONTAINER(x)

/// \deprecated
#define DEFINE_AUDIOPLUGIN_CONTAINER(x) AK_DEFINE_PLUGIN_CONTAINER(x)

/// \deprecated
#define EXPORT_AUDIOPLUGIN_CONTAINER(x) AK_EXPORT_PLUGIN_CONTAINER(x)

/// \deprecated
#define ADD_AUDIOPLUGIN_CLASS_TO_CONTAINER(x, y, z) AK_ADD_PLUGIN_CLASS_TO_CONTAINER(x, y, z)

/// \deprecated
#define ADD_AUDIOPLUGIN_CLASSID_TO_CONTAINER(x, y, a, b, c) AK_ADD_PLUGIN_CLASSID_TO_CONTAINER(x, y, a, b, c)

#endif		// of __cplusplus
