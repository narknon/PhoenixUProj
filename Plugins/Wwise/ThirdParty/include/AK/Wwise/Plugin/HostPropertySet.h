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
 * \brief Wwise Authoring Plug-ins - Plug-in API for property sets.
 * \file AK/Wwise/Plugin/HostPropertySet.h
 */

#pragma once

#include "PluginInfoGenerator.h"


/**
 * \brief Interface used to interact with property sets.
 * 
 * A property set is a dictionary of properties, as stored inside a user's Authoring project. Whenever a
 * property name is specified, it corresponds to the property name as set in the plug-in's XML
 * definition file.
 * 
 * By default, Authoring will provide a property set, as defined in the XML definition file. It is
 * possible to have more than one property set by requesting ak_wwise_plugin_host_object_store_v1, and
 * adding \c InnerTypes in the XML definition file.
 * 
 * This interface supports both the unique default property set, as well as Object Store's inner
 * property sets.
 * 
 * You can also subscribe to notifications through ak_wwise_plugin_notifications_property_set_v1 in order to
 * be informed when some property set values changed.
 * 
 * \aknote
 * 		Most methods assume you acquired access to a platform as a GUID; either provided by the caller function,
 *		or retrieved through the Host interface.
 * 
 * 		The usual providers of this GUID are \ref ak_wwise_plugin_audio_plugin_v1::GetBankParameters
 * 		and \ref ak_wwise_plugin_audio_plugin_v1::GetPluginData method parameters.
 * 
 * 		You can also poll up-to-date GUIDs from \ref ak_wwise_plugin_host_v1 methods, such as
 * 		\ref ak_wwise_plugin_host_v1::GetCurrentPlatform.
 * 
 * 		Finally, you can also provide GUID_NULL as a parameter, which will access data for all platforms at
 * 		once (linked value). This is adequate only in certain cases where no platform-specific data is
 * 		possible for a value. Using the current platform is always the preferred method of access. 
 * \endaknote
 * 
 * \sa
 * - \ref wwiseplugin_xml_properties_tag
 * - \ref wwiseplugin_propertyset
 * - \ref ak_wwise_plugin_notifications_property_set_v1
 * - \ref ak_wwise_plugin_host_object_store_v1
 */
struct ak_wwise_plugin_host_property_set_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base host-provided instance type for ak_wwise_plugin_host_property_set_v1.
	using Instance = ak_wwise_plugin_host_property_set_instance_v1;
	ak_wwise_plugin_host_property_set_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_PROPERTY_SET, 1)
	{}
#endif

	/**
	 * \deprecated
	 * \brief Retrieves the value of a specific property as a variant.
	 * 
	 * \akwarning
	 * 		This is a semi-private function. You should use the typed GetValue methods instead.
	 * 
	 * 		\ref GetValueString, \ref GetValueInt64, \ref GetValueInt32, \ref GetValueInt16,
	 *   	\ref GetValueInt8, \ref GetValueUInt64, \ref GetValueUInt32, \ref GetValueUInt16,
	 *  	\ref GetValueUInt8, \ref GetValueReal64 \ref GetValueReal32, \ref GetValueBool
	 * 
	 * 		The function can still be useful if you want to handle parameters as a black box, getting a
	 * 		value without knowing the type, and then setting that value elsewhere.
	 * \endakwarning
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_varProperty The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValue)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		AK::WwiseAuthoringAPI::AkVariantBase* out_varProperty
	);

	/**
	 * \deprecated
	 * \brief Modifies the value of a specific property as a variant.
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_varProperty under the
	 * \c in_guidPlatform platform.
	 * 
	 * The property type, as contained by \c in_varProperty, should be equal to the
	 * type as defined in the plug-in XML definition file.
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \akwarning
	 * 		This is a semi-private function. You should use the typed SetValue methods instead.
	 *
	 * 		\ref SetValueString, \ref SetValueInt64, \ref SetValueInt32, \ref SetValueInt16,
	 *   	\ref SetValueInt8, \ref SetValueUInt64, \ref SetValueUInt32, \ref SetValueUInt16,
	 *  	\ref SetValueUInt8, \ref SetValueReal64 \ref SetValueReal32, \ref SetValueBool
	 * 
	 * 		The function can still be useful if you want to handle parameters as a black box, getting a
	 * 		value without knowing the type, and then setting that value elsewhere.
	 * \endakwarning
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_varProperty The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValue)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		const AK::WwiseAuthoringAPI::AkVariantBase* in_varProperty
	);

	/**
	 * \brief Returns true if the specified property exists.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to check.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \return true if property exists.
	 */
	bool(*HasPropertyValue)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName
	);

	/**
	 * \brief Get the RTPC binding status for the specified property.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \return true if property is bound to an RTPC.
	 */
	bool(*PropertyHasRTPC)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const char * in_pszPropertyName
	);

	/**
	 * \brief Returns whether the specified property is bound to a state object.
	 * 
	 * \sa
	 * - \ref concept_state
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \return true if property is bound to a state.
	 */
	bool(*PropertyHasState)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const char * in_pszPropertyName
	);

	/**
	 * \brief Returns whether the specified property has at least some linked platforms.
	 * 
	 * By default, all platforms are linked.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \return true if that particular property has some linked platforms.
	 */
	bool(*PropertyHasLinked)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const char * in_pszPropertyName
	);

	/**
	 * \brief Returns whether the specified property has at least some platforms that are not linked.
	 * 
	 * By default, all platforms are linked.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \return true if that particular property has some unlinked platforms.
	 */
	bool(*PropertyHasUnlinked)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const char * in_pszPropertyName
	);

	/**
	 * \brief Returns whether the specified property's platform is linked.
	 * 
	 * By default, all platforms are linked.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \return true if the specified property specifically has the specified platform linked.
	 */
	bool(*PropertyPlatformIsLinked)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName
		);

	/**
	 * \brief Returns the internal unique identifier of the corresponding object.
	 * 
	 * For the plug-in property set, this is equivalent to the ID field in the project files.
	 * 
	 * For inner property sets, as defined in Object Stores, that value is dynamic and only valid for
	 * this session.
	 * 
	 * \aknote
	 * 		This value is provided mostly for information during the development process.
	 * 
	 * 		The ID might change on Undo or Redo operations.
	 * \endaknote
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return GUID of the corresponding object.
	 */
	const GUID*(*GetID)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this
	);

	/**
	 * \brief Retrieves the type of a specific property.
	 * 
	 * The return value can contain AK::WwiseAuthoringAPI::AkVariantTypeBase
	 * enumeration values.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \return A AK::WwiseAuthoringAPI::AkVariantTypeBase value.
	 */
	int (*GetType)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName
	);

	/**
	 * \brief Resets a property value to its default.
	 * 
	 * This is different than setting the value to the default value. Once saved,
	 * this property set value line will disappear from the project file.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \return true if successful.
	 */
	bool(*ClearValue)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName
	);

	/**
	 * \brief Modifies a property to a string value.
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * The plug-in XML definition file should define this property as a \c string in order to use
	 * this method.
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueString)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		const char* in_propertyValue
	);

	/**
	 * \brief Modifies a property to a 64-bit signed integer value.
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * The plug-in XML definition file should define this property as a \c int64 in order to use
	 * this method.
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueInt64)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		int64_t in_propertyValue
	);

	/**
	 * \brief Modifies a property to a 32-bit signed integer value.
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * The plug-in XML definition file should define this property as a \c int32 in order to use
	 * this method.
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueInt32)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		int32_t in_propertyValue
	);

	/**
	 * \brief Modifies a property to a 16-bit signed integer value.
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * The plug-in XML definition file should define this property as a \c int16 in order to use
	 * this method.
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueInt16)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		int16_t in_propertyValue
	);

	/**
	 * \brief Modifies a property to an 8-bit signed integer value. (Future use)
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * \akwarning
	 * 		The plug-in XML definition file doesn't currently provide a \c int8 value type.
	 * \endakwarning
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueInt8)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		int8_t in_propertyValue
	);

	/**
	 * \brief Modifies a property to a 64-bit unsigned integer value. (Future use)
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * \akwarning
	 * 		The plug-in XML definition file doesn't currently provide a \c uint64 value type.
	 * \endakwarning
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueUInt64)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		uint64_t in_propertyValue
	);

	/**
	 * \brief Modifies a property to a 32-bit unsigned integer value. (Future use)
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * \akwarning
	 * 		The plug-in XML definition file doesn't currently provide a \c uint32 value type.
	 * \endakwarning
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueUInt32)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		uint32_t in_propertyValue
	);

	/**
	 * \brief Modifies a property to a 16-bit unsigned integer value. (Future use)
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * \akwarning
	 * 		The plug-in XML definition file doesn't currently provide a \c uint16 value type.
	 * \endakwarning
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueUInt16)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		uint16_t in_propertyValue
	);

	/**
	 * \brief Modifies a property to an 8-bit unsigned integer value. (Future use)
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * \akwarning
	 * 		The plug-in XML definition file doesn't currently provide a \c uint8 value type.
	 * \endakwarning
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueUInt8)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		uint8_t in_propertyValue
	);

	/**
	 * \brief Modifies a property to a 64-bit floating point value.
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * The plug-in XML definition file should define this property as a \c Real64 in order to use
	 * this method.
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueReal64)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		double in_propertyValue
	);

	/**
	 * \brief Modifies a property to a 32-bit floating point value.
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * The plug-in XML definition file should define this property as a \c Real32 in order to use
	 * this method.
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueReal32)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		float in_propertyValue
	);

	/**
	 * \brief Modifies a property to a boolean value.
	 * 
	 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
	 * \c in_guidPlatform platform.
	 * 
	 * The plug-in XML definition file should define this property as a \c bool in order to use
	 * this method.
	 * 
	 * \aknote
	 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
	 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
	 * 
	 * 		More than one platform will be affected if the property is linked
	 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
	 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
	 * \param[out] in_propertyValue The new value of the property.
	 * \return true if successful.
	 */
	bool(*SetValueBool)(
		struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		bool in_propertyValue
	);

	/**
	 * \brief Retrieves the string value of a specific property.
	 * 
	 * The plug-in XML definition file should define this property as a \c string in order to use
	 * this method.
	 * 
	 * \aknote
	 * 		The returned pointer is provided by Authoring, and contains a TLS copy of the property
	 * 		value string. It is guaranteed to be valid until the next Host function call. If you
	 * 		wish to retain this string, you should make a copy at the earliest convenience.
	 * \endaknote
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 *   The buffer is owned by Authoring and is valid until the next API call.
	 * \return true if successful.
	 */
	bool(*GetValueString)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		const char** out_propertyValue
	);

	/**
	 * \brief Retrieves the 64-bit signed integer value of a specific property.
	 * 
	 * The plug-in XML definition file should define this property as a \c int64 in order to use
	 * this method.
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValueInt64)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		int64_t* out_propertyValue
	);

	/**
	 * \brief Retrieves the 32-bit signed integer value of a specific property.
	 * 
	 * The plug-in XML definition file should define this property as a \c int32 in order to use
	 * this method.
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValueInt32)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		int32_t* out_propertyValue
	);

	/**
	 * \brief Retrieves the 16-bit signed integer value of a specific property.
	 * 
	 * The plug-in XML definition file should define this property as a \c int16 in order to use
	 * this method.
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValueInt16)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		int16_t* out_propertyValue
	);

	/**
	 * \brief Retrieves the 8-bit signed integer value of a specific property. (Future use)
	 * 
	 * \akwarning
	 * 		The plug-in XML definition file doesn't currently provide a \c int8 value type.
	 * \endakwarning
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValueInt8)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		int8_t* out_propertyValue
	);

	/**
	 * \brief Retrieves the 64-bit unsigned integer value of a specific property. (Future use)
	 * 
	 * \akwarning
	 * 		The plug-in XML definition file doesn't currently provide a \c uint64 value type.
	 * \endakwarning
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValueUInt64)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		uint64_t* out_propertyValue
	);

	/**
	 * \brief Retrieves the 32-bit unsigned integer value of a specific property. (Future use)
	 * 
	 * \akwarning
	 * 		The plug-in XML definition file doesn't currently provide a \c uint32 value type.
	 * \endakwarning
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValueUInt32)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		uint32_t* out_propertyValue
	);

	/**
	 * \brief Retrieves the 16-bit unsigned integer value of a specific property. (Future use)
	 * 
	 * \akwarning
	 * 		The plug-in XML definition file doesn't currently provide a \c uint16 value type.
	 * \endakwarning
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValueUInt16)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		uint16_t* out_propertyValue
	);

	/**
	 * \brief Retrieves the 8-bit unsigned integer value of a specific property. (Future use)
	 * 
	 * \akwarning
	 * 		The plug-in XML definition file doesn't currently provide a \c uint8 value type.
	 * \endakwarning
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValueUInt8)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		uint8_t* out_propertyValue
	);

	/**
	 * \brief Retrieves the 64-bit floating point value of a specific property.
	 * 
	 * The plug-in XML definition file should define this property as a \c Real64 in order to use
	 * this method.
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValueReal64)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		double* out_propertyValue
	);

	/**
	 * \brief Retrieves the 32-bit floating point value of a specific property.
	 * 
	 * The plug-in XML definition file should define this property as a \c Real32 in order to use
	 * this method.
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValueReal32)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		float* out_propertyValue
	);

	/**
	 * \brief Retrieves the boolean value of a specific property.
	 * 
	 * The plug-in XML definition file should define this property as a \c bool in order to use
	 * this method.
	 * 
	 * \sa
	 * - \ref wwiseplugin_bank
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
	 * \param[out] out_propertyValue The returned value of the property.
	 * \return true if successful.
	 */
	bool(*GetValueBool)(
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName,
		bool* out_propertyValue
	);
};


struct ak_wwise_plugin_notifications_property_set_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for receiving notifications on property set's changes.
	using Instance = ak_wwise_plugin_notifications_property_set_instance_v1;

	ak_wwise_plugin_notifications_property_set_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_PROPERTY_SET, 1)
	{}
#endif

	/**
	 * \brief This function is called by Wwise when a plug-in property changes.
	 * 
	 * For example, data can change through interaction with a UI control bound to a property,
	 * or through undo/redo operations.
	 * 
	 * This function is not called on the Object Store or any inner property sets.
	 * 
	 * \sa
	 * - \ref wwiseplugin_propertyset_notification
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the affected property.
	 */
	void(*NotifyPropertyChanged)(
		struct ak_wwise_plugin_notifications_property_set_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const char * in_pszPropertyName
	);
};


#define AK_WWISE_PLUGIN_HOST_PROPERTY_SET_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_PROPERTY_SET, 1)
#define AK_WWISE_PLUGIN_HOST_PROPERTY_SET_V1_CTOR() \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_HOST_PROPERTY_SET_V1_ID() \
}

#define AK_WWISE_PLUGIN_NOTIFICATIONS_PROPERTY_SET_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_PROPERTY_SET, 1)
#define AK_WWISE_PLUGIN_NOTIFICATIONS_PROPERTY_SET_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_NOTIFICATIONS_PROPERTY_SET_V1_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CHostPropertySet = ak_wwise_plugin_host_property_set_v1;

		/// \copydoc ak_wwise_plugin_host_property_set_v1
		class PropertySet : public CBaseInstanceGlue<CHostPropertySet>
		{
		public:
			using Interface = CHostPropertySet;

			/**
			 * \brief The interface type, as requested by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as requested by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_PROPERTY_SET
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
			 * \deprecated
			 * \brief Retrieves the value of a specific property as a variant.
			 * 
			 * \akwarning
			 * 		This is a semi-private function. You should use the typed GetValue methods instead.
			 * 
			 * 		\ref GetValueString, \ref GetValueInt64, \ref GetValueInt32, \ref GetValueInt16,
			 *   	\ref GetValueInt8, \ref GetValueUInt64, \ref GetValueUInt32, \ref GetValueUInt16,
			 *  	\ref GetValueUInt8, \ref GetValueReal64 \ref GetValueReal32, \ref GetValueBool
			 * 
			 * 		The function can still be useful if you want to handle parameters as a black box, getting a
			 * 		value without knowing the type, and then setting that value elsewhere.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_varProperty The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValue(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				AK::WwiseAuthoringAPI::AkVariantBase& out_varProperty
			) const
			{
				return MKBOOL(g_cinterface->GetValue(this, &in_guidPlatform, in_pszPropertyName, &out_varProperty));
			}

			/**
			 * \deprecated
			 * \brief Modifies the value of a specific property as a variant.
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_varProperty under the
			 * \c in_guidPlatform platform.
			 * 
			 * The property type, as contained by \c in_varProperty, should be equal to the
			 * type as defined in the plug-in XML definition file.
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \akwarning
			 * 		This is a semi-private function. You should use the typed SetValue methods instead.
			 *
			 * 		\ref SetValueString, \ref SetValueInt64, \ref SetValueInt32, \ref SetValueInt16,
			 *   	\ref SetValueInt8, \ref SetValueUInt64, \ref SetValueUInt32, \ref SetValueUInt16,
			 *  	\ref SetValueUInt8, \ref SetValueReal64 \ref SetValueReal32, \ref SetValueBool
			 * 
			 * 		The function can still be useful if you want to handle parameters as a black box, getting a
			 * 		value without knowing the type, and then setting that value elsewhere.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_varProperty The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValue(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				const AK::WwiseAuthoringAPI::AkVariantBase& in_varProperty
			)
			{
				return MKBOOL(g_cinterface->SetValue(this, &in_guidPlatform, in_pszPropertyName, &in_varProperty));
			}

			/**
			 * \brief Returns true if the specified property exists.
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to check.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return true if property exists.
			 */
			inline bool HasPropertyValue(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName
			) const
			{
				return MKBOOL(g_cinterface->HasPropertyValue(this, &in_guidPlatform, in_pszPropertyName));
			}

			/**
			 * \brief Get the RTPC binding status for the specified property.
			 * 
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return true if property is bound to an RTPC.
			 */
			inline bool PropertyHasRTPC(
				const char * in_pszPropertyName
			) const
			{
				return MKBOOL(g_cinterface->PropertyHasRTPC(this, in_pszPropertyName));
			}

			/**
			 * \brief Returns whether the specified property is bound to a state object.
			 * 
			 * \sa
			 * - \ref concept_state
			 * 
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return true if property is bound to a state.
			 */
			inline bool PropertyHasState(
				const char* in_pszPropertyName
			) const
			{
				return MKBOOL(g_cinterface->PropertyHasState(this, in_pszPropertyName));
			}

			/**
			 * \brief Returns whether the specified property has at least some linked platforms.
			 * 
			 * By default, all platforms are linked.
			 * 
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return true if that particular property has some linked platforms.
			 */
			inline bool PropertyHasLinked(
				const char* in_pszPropertyName
			) const
			{
				return MKBOOL(g_cinterface->PropertyHasLinked(this, in_pszPropertyName));
			}

			/**
			 * \brief Returns whether the specified property has at least some platforms that are not linked.
			 * 
			 * By default, all platforms are linked.
			 * 
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return true if that particular property has some unlinked platforms.
			 */
			inline bool PropertyHasUnlinked(
				const char* in_pszPropertyName
			) const
			{
				return MKBOOL(g_cinterface->PropertyHasUnlinked(this, in_pszPropertyName));
			}

			/**
			 * \brief Returns whether the specified property's platform is linked.
			 * 
			 * By default, all platforms are linked.
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return true if the specified property specifically has the specified platform linked.
			 */
			inline bool PropertyPlatformIsLinked(
				const GUID& in_guidPlatform,
				const char* in_pszPropertyName
			) const
			{
				return MKBOOL(g_cinterface->PropertyPlatformIsLinked(this, &in_guidPlatform, in_pszPropertyName));
			}

			/**
			 * \brief Returns the internal unique identifier of the corresponding object.
			 * 
			 * For the plug-in property set, this is equivalent to the ID field in the project files.
			 * 
			 * For inner property sets, as defined in Object Stores, that value is dynamic and only valid for
			 * this session.
			 * 
			 * \aknote
			 * 		This value is provided mostly for information during the development process.
			 * 
			 * 		The ID might change on Undo or Redo operations.
			 * \endaknote
			 * 
			 * \return GUID of the corresponding object.
			 */
			inline const GUID* GetID() const
			{
				return g_cinterface->GetID(this);
			}

			/**
			 * \brief Retrieves the type of a specific property.
			 * 
			 * The return value can contain AK::WwiseAuthoringAPI::AkVariantTypeBase
			 * enumeration values.
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return A AK::WwiseAuthoringAPI::AkVariantTypeBase value.
			 */
			inline int GetType(
				const GUID& in_guidPlatform,
				const char* in_pszPropertyName
			) const
			{
				return g_cinterface->GetType(this, &in_guidPlatform, in_pszPropertyName);
			}

			/**
			 * \brief Resets a property value to its default.
			 * 
			 * This is different than setting the value to the default value. Once saved,
			 * this property set value line will disappear from the project file.
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \return true if successful.
			 */
			inline bool ClearValue(
				const GUID& in_guidPlatform,
				const char* in_pszPropertyName
			)
			{
				return MKBOOL(g_cinterface->ClearValue(this, &in_guidPlatform, in_pszPropertyName));
			}

			/**
			 * \brief Modifies a property to a string value.
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * The plug-in XML definition file should define this property as a \c string in order to use
			 * this method.
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueString(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				const char * in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueString(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Modifies a property to a 64-bit signed integer value.
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * The plug-in XML definition file should define this property as a \c int64 in order to use
			 * this method.
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueInt64(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				int64_t in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueInt64(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Modifies a property to a 32-bit signed integer value.
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * The plug-in XML definition file should define this property as a \c int32 in order to use
			 * this method.
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueInt32(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				int32_t in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueInt32(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Modifies a property to a 16-bit signed integer value.
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * The plug-in XML definition file should define this property as a \c int16 in order to use
			 * this method.
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueInt16(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				int16_t in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueInt16(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Modifies a property to an 8-bit signed integer value. (Future use)
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c int8 value type.
			 * \endakwarning
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueInt8(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				int8_t in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueInt8(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Modifies a property to a 64-bit unsigned integer value. (Future use)
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint64 value type.
			 * \endakwarning
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueUInt64(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				uint64_t in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueUInt64(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Modifies a property to a 32-bit unsigned integer value. (Future use)
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint32 value type.
			 * \endakwarning
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueUInt32(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				uint32_t in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueUInt32(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Modifies a property to a 16-bit unsigned integer value. (Future use)
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint16 value type.
			 * \endakwarning
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueUInt16(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				uint16_t in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueUInt16(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Modifies a property to an 8-bit unsigned integer value. (Future use)
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint8 value type.
			 * \endakwarning
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueUInt8(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				uint8_t in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueUInt8(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Modifies a property to a 64-bit floating point value.
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * The plug-in XML definition file should define this property as a \c Real64 in order to use
			 * this method.
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueReal64(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				double in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueReal64(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Modifies a property to a 32-bit floating point value.
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * The plug-in XML definition file should define this property as a \c Real32 in order to use
			 * this method.
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueReal32(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				float in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueReal32(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Modifies a property to a boolean value.
			 * 
			 * Updates the property \c in_pszPropertyName to contain \c in_propertyValue under the
			 * \c in_guidPlatform platform.
			 * 
			 * The plug-in XML definition file should define this property as a \c bool in order to use
			 * this method.
			 * 
			 * \aknote
			 * 		Your changes might be substantially altered or replaced if your property is bound to an RTPC
			 * 		( \ref PropertyHasRTPC ) or a State ( \ref PropertyHasState ).
			 * 
			 * 		More than one platform will be affected if the property is linked
			 * 		( \ref PropertyPlatformIsLinked ); all platforms are linked by default.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the platform whose property you want to modify.
			 * \param[in] in_pszPropertyName The name of the property to update, based on the XML definition file.
			 * \param[out] in_propertyValue The new value of the property.
			 * \return true if successful.
			 */
			inline bool SetValueBool(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				bool in_propertyValue
			)
			{
				return MKBOOL(g_cinterface->SetValueBool(this, &in_guidPlatform, in_pszPropertyName, in_propertyValue));
			}

			/**
			 * \brief Retrieves the string value of a specific property.
			 * 
			 * The plug-in XML definition file should define this property as a \c string in order to use
			 * this method.
			 * 
			 * \aknote
			 * 		The returned pointer is provided by Authoring, and contains a TLS copy of the property
			 * 		value string. It is guaranteed to be valid until the next Host function call. If you
			 * 		wish to retain this string, you should make a copy at the earliest convenience.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 *   The buffer is owned by Authoring and is valid until the next API call.
			 * \return true if successful.
			 */
			inline bool GetValueString(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				const char*& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueString(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the 64-bit signed integer value of a specific property.
			 * 
			 * The plug-in XML definition file should define this property as a \c int64 in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValueInt64(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				int64_t& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueInt64(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the 32-bit signed integer value of a specific property.
			 * 
			 * The plug-in XML definition file should define this property as a \c int32 in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValueInt32(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				int32_t& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueInt32(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the 16-bit signed integer value of a specific property.
			 * 
			 * The plug-in XML definition file should define this property as a \c int16 in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValueInt16(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				int16_t& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueInt16(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the 8-bit signed integer value of a specific property. (Future use)
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c int8 value type.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValueInt8(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				int8_t& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueInt8(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the 64-bit unsigned integer value of a specific property. (Future use)
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint64 value type.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValueUInt64(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				uint64_t& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueUInt64(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the 32-bit unsigned integer value of a specific property. (Future use)
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint32 value type.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValueUInt32(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				uint32_t& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueUInt32(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the 16-bit unsigned integer value of a specific property. (Future use)
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint16 value type.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValueUInt16(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				uint16_t& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueUInt16(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the 8-bit unsigned integer value of a specific property. (Future use)
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint8 value type.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValueUInt8(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				uint8_t& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueUInt8(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the 64-bit floating point value of a specific property.
			 * 
			 * The plug-in XML definition file should define this property as a \c Real64 in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValueReal64(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				double& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueReal64(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the 32-bit floating point value of a specific property.
			 * 
			 * The plug-in XML definition file should define this property as a \c Real32 in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValueReal32(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				float& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueReal32(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the boolean value of a specific property.
			 * 
			 * The plug-in XML definition file should define this property as a \c bool in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform.
			 * \param[in] in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \param[out] out_propertyValue The returned value of the property.
			 * \return true if successful.
			 */
			inline bool GetValueBool(
				const GUID & in_guidPlatform,
				const char * in_pszPropertyName,
				bool& out_propertyValue
			) const
			{
				return MKBOOL(g_cinterface->GetValueBool(this, &in_guidPlatform, in_pszPropertyName, &out_propertyValue));
			}

			/**
			 * \brief Retrieves the string value of a specific property and returns the value as a temporary pointer.
			 * 
			 * This is a convenience for \ref GetValueString where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * The plug-in XML definition file should define this property as a \c string in order to use
			 * this method.
			 * 
			 * \aknote
			 * 		The returned pointer is provided by Authoring, and contains a TLS copy of the property
			 * 		value string. It is guaranteed to be valid until the next Host function call. If you
			 * 		wish to retain this string, you should make a copy at the earliest convenience.
			 * \endaknote
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline const char* GetString(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				const char* result;
				AKVERIFY(GetValueString(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}

			/**
			 * \brief Returns the 64-bit signed integer value of a specific property.
			 * 
			 * This is a convenience for \ref GetValueInt64 where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * The plug-in XML definition file should define this property as a \c int64 in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline int64_t GetInt64(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				int64_t result;
				AKVERIFY(GetValueInt64(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}

			/**
			 * \brief Returns the 32-bit signed integer value of a specific property.
			 * 
			 * This is a convenience for \ref GetValueInt32 where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * The plug-in XML definition file should define this property as a \c int32 in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline int32_t GetInt32(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				int32_t result;
				AKVERIFY(GetValueInt32(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}

			/**
			 * \brief Returns the 16-bit signed integer value of a specific property.
			 * 
			 * This is a convenience for \ref GetValueInt16 where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * The plug-in XML definition file should define this property as a \c int16 in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline int16_t GetInt16(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				int16_t result;
				AKVERIFY(GetValueInt16(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}

			/**
			 * \brief Returns the 8-bit signed integer value of a specific property.
			 * 
			 * This is a convenience for \ref GetValueInt8 where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c int8 value type.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline int8_t GetInt8(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				int8_t result;
				AKVERIFY(GetValueInt8(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}

			/**
			 * \brief Returns the 64-bit unsigned integer value of a specific property.
			 * 
			 * This is a convenience for \ref GetValueUInt64 where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint64 value type.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline uint64_t GetUInt64(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				uint64_t result;
				AKVERIFY(GetValueUInt64(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}

			/**
			 * \brief Returns the 32-bit unsigned integer value of a specific property.
			 * 
			 * This is a convenience for \ref GetValueUInt32 where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint32 value type.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline uint32_t GetUInt32(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				uint32_t result;
				AKVERIFY(GetValueUInt32(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}

			/**
			 * \brief Returns the 16-bit unsigned integer value of a specific property.
			 * 
			 * This is a convenience for \ref GetValueUInt16 where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint16 value type.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline uint16_t GetUInt16(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				uint16_t result;
				AKVERIFY(GetValueUInt16(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}

			/**
			 * \brief Returns the 8-bit unsigned integer value of a specific property.
			 * 
			 * This is a convenience for \ref GetValueUInt8 where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * \akwarning
			 * 		The plug-in XML definition file doesn't currently provide a \c uint8 value type.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline uint8_t GetUInt8(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				uint8_t result;
				AKVERIFY(GetValueUInt8(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}

			/**
			 * \brief Returns the 64-bit floating point value of a specific property.
			 * 
			 * This is a convenience for \ref GetValueReal64 where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * The plug-in XML definition file should define this property as a \c Real64 in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline double GetReal64(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				double result;
				AKVERIFY(GetValueReal64(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}

			/**
			 * \brief Returns the 32-bit floating point value of a specific property.
			 * 
			 * This is a convenience for \ref GetValueReal32 where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * The plug-in XML definition file should define this property as a \c Real32 in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline float GetReal32(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				float result;
				AKVERIFY(GetValueReal32(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}

			/**
			 * \brief Returns the boolean value of a specific property.
			 * 
			 * This is a convenience for \ref GetValueBool where the value is returned instead of
			 * being set in a provided variable.
			 * 
			 * The plug-in XML definition file should define this property as a \c bool in order to use
			 * this method.
			 * 
			 * \sa
			 * - \ref wwiseplugin_bank
			 * 
			 * \param in_guidPlatform The unique ID of the queried platform.
			 * \param in_pszPropertyName The name of the queried property, based on the XML definition file.
			 * \return The value of the property.
			 */
			inline bool GetBool(
				const GUID & in_guidPlatform,	///< The unique ID of the queried platform
				const char * in_pszPropertyName		///< The name of the property
			) const
			{
				bool result;
				AKVERIFY(GetValueBool(in_guidPlatform, in_pszPropertyName, result));
				return result;
			}
		};

		namespace Notifications
		{
			using CPropertySet_ = ak_wwise_plugin_notifications_property_set_v1;

			/// \copydoc ak_wwise_plugin_notifications_property_set_v1
			class PropertySet_ : public CPropertySet_::Instance
			{
			public:
				/**
				 * \copydoc CPropertySet_::Instance
				 */
				using Instance = CPropertySet_::Instance;

				/**
				 * \brief The interface type, as provided by this plug-in.
				 */
				enum : InterfaceTypeValue
				{
					/**
					 * \brief The interface type, as provided by this plug-in.
					 */
					k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_PROPERTY_SET
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
				struct Interface : public CPropertySet_
				{
					using Instance = PropertySet_;
					Interface()
					{
						CPropertySet_::NotifyPropertyChanged = [](
							struct ak_wwise_plugin_notifications_property_set_instance_v1* in_this,
							const GUID* in_guidPlatform,
							const char* in_pszPropertyName)
						{
							static_cast<Instance*>(in_this)->NotifyPropertyChanged(
								*in_guidPlatform,
								in_pszPropertyName);
						};
					}
				};

				InterfacePtr GetInterfacePointer() {
					static Interface g_interface;
					return &g_interface;
				}
				CPropertySet_::Instance* GetInstancePointer() {
					return this;
				}
				const CPropertySet_::Instance* GetInstancePointer() const {
					return this;
				}

				PropertySet_() :
					CPropertySet_::Instance()
				{
				}

				virtual ~PropertySet_() {}

				/**
				 * \brief This function is called by Wwise when a plug-in property changes.
				 *
				 * For example, data can change through interaction with a UI control bound to a property,
				 * or through undo/redo operations.
				 *
				 * This function is not called on the Object Store or any inner property sets.
				 *
				 * \sa
				 * - \ref wwiseplugin_propertyset_notification
				 *
				 * \param[in] in_guidPlatform The unique ID of the queried platform.
				 * \param[in] in_pszPropertyName The name of the affected property.
				 */
				virtual void NotifyPropertyChanged(
					const GUID& in_guidPlatform,		///< The unique ID of the queried platform
					const char* in_pszPropertyName		///< The name of the property
				) {}
			};
		} // of namespace Notifications

		/**
		 * \brief Requests a PropertySet interface, provided as m_propertySet variable.
		 * 
		 * Deriving your plug-in class from RequestPropertySet will automatically request both PropertySet and
		 * Notifications::PropertySet_ interfaces. From this point, you will be able to derive from the virtual
		 * functions as defined in Notifications::PropertySet_, and access the host-provided functions in the
		 * `m_propertySet` variable.
		 * 
		 * This is also useful when you want to access inner property sets from the ObjectStore interface.
		 * In that case, you can ignore the m_propertySet variable and the notifications interface.
		 * 
		 * \aknote The AK::Wwise::Plugin::RequestPropertySet and AK::Wwise::Plugin::RequestWrite classes are automatically
		 * derived when providing AudioPlugin in C++. \endaknote
		 */
		using RequestPropertySet = RequestedHostInterface<PropertySet>;

	} // of namespace V1

	/// Latest version of the C PropertySet interface.
	using CHostPropertySet = V1::CHostPropertySet;
	/// Latest version of the C++ PropertySet interface.
	using PropertySet = V1::PropertySet;
	/// Latest version of the requested C++ PropertySet interface.
	using RequestPropertySet = V1::RequestPropertySet;

	namespace Notifications
	{
		/// Latest version of the C PropertySet notification interface.
		using CPropertySet = V1::Notifications::CPropertySet_;
		/// Latest version of the C++ PropertySet notification interface.
		using PropertySet = V1::Notifications::PropertySet_;
	}

	AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE(PropertySet, propertySet,, public Notifications::PropertySet);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(PropertySet);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(PropertySet);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(Notifications::PropertySet);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(Notifications::PropertySet);
} // of namespace AK::Wwise::Plugin

#endif
