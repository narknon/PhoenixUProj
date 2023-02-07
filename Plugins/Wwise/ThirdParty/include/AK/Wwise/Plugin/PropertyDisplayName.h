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
 * \brief Wwise Authoring Plug-ins - Plug-in API for property display name.
 * \file AK/Wwise/Plugin/PropertyDisplayName.h
 */

#pragma once

#include "PluginInfoGenerator.h"

/**
 * \brief Backend API to specify display names for properties
 * 
 * \aknote It is preferrable to specify names directly in the XML. This interface can be useful when implementing
 *         properties that have different meanings dependending on the state of other properties. \endaknote
 */
struct ak_wwise_plugin_property_display_name_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for providing display names to properties.
	using Instance = ak_wwise_plugin_property_display_name_instance_v1;

	ak_wwise_plugin_property_display_name_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_PROPERTY_DISPLAY_NAME, 1)
	{}
#endif

	/**
	 * \brief Gets the user-friendly name of the specified property.
	 * 
	 * This function should write the user-friendly name of the specified property to the char buffer
	 * out_pszDisplayName, which is of maximum length in_unCharCount.
	 * 
	 * \aknote This function used to be deprecated, but is actually useful in case of dynamic naming.
	 *         As such, it has been reinstated. However, its usage is still not preferred. By default,
	 *         you should provide your naming inside the XML, and use this function only in cases
	 *         where you cannot reliably name the property in your XML. For example, you might have
	 *         a switch between two modes, and the same property might have two different names. This
	 *         function can then be used for this particular case. \endaknote
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pszPropertyName The internal name of the property.
	 * \param[out] out_pszDisplayName The returned user-friendly name, as a null-terminated string.
	 * \param[in] in_unCharCount The maximum number of char in the buffer, including the terminating null.
	 * \return true if the property has a user-friendly name.
	 */
	bool(*DisplayNameForProp)(
		const struct ak_wwise_plugin_property_display_name_instance_v1* in_this,
		const char * in_pszPropertyName,
		char * out_pszDisplayName,
		uint32_t in_unCharCount
	);

	/**
	 * \brief Get the user-friendly names of possible values for the specified property.
	 * 
	 * This function should write pairs of value and text for the specified property to
	 * the WCHAR buffer out_pszDisplayName, which is of length in_unCharCount.
	 * 
	 * Pairs are separated by commas, and each pair contains the value and the
	 * text, separated by a colon.
	 * 
	 * Here are a few examples:
	 * - Numeric property: "-100:Left,0:Center,100:Right"
	 * - Boolean property: "0:Off,1:On"
	 * - Numeric property seen as an enumeration:
	 *      "0:Low Pass,1:High Pass,2:Band Pass,3:Notch,4:Low Shelf,5:High Shelf,6:Peaking"
	 * 
	 * \aknote This function used to be deprecated, but is actually useful in case of dynamic naming.
	 *         As such, it has been reinstated. However, its usage is still not preferred. By default,
	 *         you should provide your naming inside the XML, and use this function only in cases
	 *         where you cannot reliably name the property in your XML. For example, you might have
	 *         a switch between two modes, and the same property might have two different names. This
	 *         function can then be used for this particular case. \endaknote
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pszPropertyName The internal name of the property.
	 * \param[out] out_pszValuesName The returned property value names, as a null-terminated string.
	 * \param[in] in_unCharCount The maximum number of char in the buffer, including the terminating null.
	 * \return true if the property has a user-friendly value name.
	 * 
	 * \sa
	 * - \ref wwiseplugin_displaynames
	 */
	bool(*DisplayNamesForPropValues)(
		const struct ak_wwise_plugin_property_display_name_instance_v1* in_this,
		const char * in_pszPropertyName,
		char * out_pszValuesName,
		uint32_t in_unCharCount
	);
};
#define AK_WWISE_PLUGIN_PROPERTY_DISPLAY_NAME_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_PROPERTY_DISPLAY_NAME, 1)
#define AK_WWISE_PLUGIN_PROPERTY_DISPLAY_NAME_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_PROPERTY_DISPLAY_NAME_V1_ID(), in_pluginInfo, in_data) \
}

#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CPropertyDisplayName = ak_wwise_plugin_property_display_name_v1;
		class PropertyDisplayName : public CPropertyDisplayName::Instance
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
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_PROPERTY_DISPLAY_NAME
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
			struct Interface : public CPropertyDisplayName
			{
				using Instance = PropertyDisplayName;
				Interface()
				{
					CPropertyDisplayName::DisplayNameForProp =
						[](
							const struct ak_wwise_plugin_property_display_name_instance_v1* in_this,
							const char * in_pszPropertyName,
							char * out_pszDisplayName,
							uint32_t in_unCharCount)
					{
						return (bool)static_cast<const Instance*>(in_this)->DisplayNameForProp(
							in_pszPropertyName,
							out_pszDisplayName,
							in_unCharCount);
					};
					CPropertyDisplayName::DisplayNamesForPropValues = [](
						const struct ak_wwise_plugin_property_display_name_instance_v1* in_this,
						const char * in_pszPropertyName,
						char * out_pszValuesName,
						uint32_t in_unCharCount)
					{
						return (bool)static_cast<const Instance*>(in_this)->DisplayNamesForPropValues(
							in_pszPropertyName,
							out_pszValuesName,
							in_unCharCount);
					};
				}
			};

			InterfacePtr GetInterfacePointer() {
				static Interface g_interface;
				return &g_interface;
			}
			CPropertyDisplayName::Instance* GetInstancePointer() {
				return this;
			}
			const CPropertyDisplayName::Instance* GetInstancePointer() const {
				return this;
			}

			PropertyDisplayName() :
				CPropertyDisplayName::Instance()
			{
			}

			virtual ~PropertyDisplayName() {}

			/**
			 * \brief Gets the user-friendly name of the specified property.
			 * 
			 * This function should write the user-friendly name of the specified property to the char buffer
			 * out_pszDisplayName, which is of maximum length in_unCharCount.
			 * 
			 * \aknote This function used to be deprecated, but is actually useful in case of dynamic naming.
			 *         As such, it has been reinstated. However, its usage is still not preferred. By default,
			 *         you should provide your naming inside the XML, and use this function only in cases
			 *         where you cannot reliably name the property in your XML. For example, you might have
			 *         a switch between two modes, and the same property might have two different names. This
			 *         function can then be used for this particular case. \endaknote
			 * 
			 * \param[in] in_pszPropertyName The internal name of the property.
			 * \param[out] out_pszDisplayName The returned user-friendly name, as a null-terminated string.
			 * \param[in] in_unCharCount The maximum number of char in the buffer, including the terminating null.
			 * \return true if the property has a user-friendly name.
			 */
			virtual bool DisplayNameForProp(
				const char * in_pszPropertyName,
				char * out_pszDisplayName,
				uint32_t in_unCharCount
			) const { return false; }

			/**
			 * \brief Get the user-friendly names of possible values for the specified property.
			 * 
			 * This function should write pairs of value and text for the specified property to
			 * the WCHAR buffer out_pszDisplayName, which is of length in_unCharCount.
			 * 
			 * Pairs are separated by commas, and each pair contains the value and the
			 * text, separated by a colon.
			 * 
			 * Here are a few examples:
			 * - Numeric property: "-100:Left,0:Center,100:Right"
			 * - Boolean property: "0:Off,1:On"
			 * - Numeric property seen as an enumeration:
			 *      "0:Low Pass,1:High Pass,2:Band Pass,3:Notch,4:Low Shelf,5:High Shelf,6:Peaking"
			 * 
			 * \aknote This function used to be deprecated, but is actually useful in case of dynamic naming.
			 *         As such, it has been reinstated. However, its usage is still not preferred. By default,
			 *         you should provide your naming inside the XML, and use this function only in cases
			 *         where you cannot reliably name the property in your XML. For example, you might have
			 *         a switch between two modes, and the same property might have two different names. This
			 *         function can then be used for this particular case. \endaknote
			 * 
			 * \param[in] in_pszPropertyName The internal name of the property.
			 * \param[out] out_pszValuesName The returned property value names, as a null-terminated string.
			 * \param[in] in_unCharCount The maximum number of char in the buffer, including the terminating null.
			 * \return true if the property has a user-friendly value name.
			 * 
			 * \sa
			 * - \ref wwiseplugin_displaynames
			 */
			virtual bool DisplayNamesForPropValues(
				const char * in_pszPropertyName,
				char * out_pszValuesName,
				uint32_t in_unCharCount
			) const { return false; }
		};
	} // of namespace V1

	/// Latest version of the C PropertyDisplayName interface.
	using CPropertyDisplayName = V1::CPropertyDisplayName;
	/// Latest version of the C++ PropertyDisplayName interface.
	using PropertyDisplayName = V1::PropertyDisplayName;

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(PropertyDisplayName);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(PropertyDisplayName);
} // of namespace AK::Wwise::Plugin

#endif
