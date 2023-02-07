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
 * \brief Wwise Authoring Plug-ins - Backend API to load and save custom data in XML format.
 * \file AK/Wwise/Plugin/CustomData.h
 */

#pragma once

#include "HostXml.h"
#include "HostDataWriter.h"

/**
 * \brief Backend API to load and save custom data in XML format.
 * 
 * The initialization of custom-data-aware plug-ins is done using one of three mutually
 * exclusive possibilities:
 * - \b InitToDefault : Initializes a new instance using the default values
 * - \b InitFromInstance : Initializes a new instance using the values provided by the
 *		   original instance.
 * - \b InitFromWorkunit : Initializes a new instance using the values provided in the Save method.
 * 
 * \aknote In order to use the XML reader and writer instance, your plug-in must request the XML
 *         interface: ak_wwise_plugin_host_xml_v1. \endaknote
 */
struct ak_wwise_plugin_custom_data_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for providing custom data loading and saving.
	using Instance = ak_wwise_plugin_custom_data_instance_v1;

	ak_wwise_plugin_custom_data_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_CUSTOM_DATA, 1)
	{}
#endif

	/**
	 * \brief Initializes the plug-in's custom data to its default values.
	 * 
	 * This method is mutually exclusive with the other Init methods.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 */
	void(*InitToDefault)(
		struct ak_wwise_plugin_custom_data_instance_v1* in_this);

	/**
	 * \brief Copy the plug-in's custom data from another instance of the same plug-in.
	 * 
	 * This is used during copy/paste and delete for Undo purposes. The properties on
	 * the PropertySet do not need to be copied in this method.
	 * 
	 * This method is mutually exclusive with the other Init methods.
	 * 
	 * \param[in] in_this Current instance of this interface (Destination).
	 * \param[in] in_source The object that will provide the data used in initializing
	 *			  this instance.
	 * \return true if successful.
	 */
	bool(*InitFromInstance)(
		struct ak_wwise_plugin_custom_data_instance_v1* in_this,
		const struct ak_wwise_plugin_custom_data_instance_v1* in_source);

	/**
	 * \brief Load the custom data structure from the provided Work Unit's XML.
	 * 
	 * This method is mutually exclusive with the other Init methods.
	 * 
	 * \aknote In order to use the in_pReader instance, your plug-in must request the XML
	 *         interface: ak_wwise_plugin_host_xml_v1. \endaknote
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pReader XML Reader instance.
	 * \return true if load succeeded.
	 */
	bool(*InitFromWorkunit)(
		struct ak_wwise_plugin_custom_data_instance_v1* in_this,
		struct ak_wwise_plugin_host_xml_reader_instance_v1* in_pReader);

	/**
	 * \brief Save custom data structure in the provided Work Unit's XML.
	 * 
	 * \aknote In order to use the in_pWriter instance, your plug-in must request the XML
	 *         interface: ak_wwise_plugin_host_xml_v1. \endaknote
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pWriter XML Writer instance.
	 * \return true if save succeeded.
	 */
	bool(*Save)(
		struct ak_wwise_plugin_custom_data_instance_v1* in_this,
		struct ak_wwise_plugin_host_xml_writer_instance_v1* in_pWriter);

	/**
	 * \brief OnDelete function is called when the user presses the "delete" button on a plug-in.
	 * 
	 * This handler function should properly clean custom data and set undo/redo action properly
	 * to allow recreation on undo.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 */
	void(*OnDelete)(struct ak_wwise_plugin_custom_data_instance_v1* in_this);

	/**
	 * \brief Obtains parameters that will be sent to the sound engine when Wwise is connected.
	 * 
	 * This block should contain only data that is NOT a property defined in the plug-in xml file. The
	 * parameter ID should be different than the ones used in the plug-in xml.
	 * 
	 * This is used when there are Object Store, large binary data sections, or properties not usually
	 * residing in the XML. \sa \ref AK::Wwise::Plugin::AudioPlugin::GetBankParameters for a discussion
	 * on parameter passing to the Sound Engine.
	 * 
	 * \aknote In order to use the in_pDataWriter instance, your plug-in must request the data writer
	 *         interface: ak_wwise_plugin_host_data_writer_v1. \endaknote
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the queried platform
	 * \param[in] in_idParam The plug-in defined parameter ID
	 * \param[in] in_pDataWriter A pointer to the data writer instance being used.
	 * \return true if the plug-in has some plug-in defined data.
	 * 
	 * \sa
	 * - \ref AK::Wwise::Plugin::Host::NotifyInternalDataChanged
	 * - \ref AK::IAkPluginParam::ALL_PLUGIN_DATA_ID
	 * - \ref AK::IAkPluginParam::SetParam
	 */
	bool(*GetPluginData)(
		const struct ak_wwise_plugin_custom_data_instance_v1* in_this,
		const GUID* in_guidPlatform,
		AkPluginParamID in_idParam,
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_pDataWriter);

};
#define AK_WWISE_PLUGIN_CUSTOM_DATA_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_CUSTOM_DATA, 1)
#define AK_WWISE_PLUGIN_CUSTOM_DATA_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_CUSTOM_DATA_V1_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CCustomData = ak_wwise_plugin_custom_data_v1;

		/**
		 * \brief Backend API to load and save custom data in XML format.
		 * 
		 * The initialization of custom-data-aware plug-ins is done using one of three mutually
		 * exclusive possibilities:
		 * - \b InitToDefault : Initializes a new instance using the default values
		 * - \b InitFromInstance : Initializes a new instance using the values provided by the
		 *		   original instance.
		 * - \b InitFromWorkunit : Initializes a new instance using the values provided in the Save method.
		 * 
		 * \aknote AK::Wwise::Plugin::The RequestXml class is automatically derived when providing
		 * \ref CustomData in C++. \endaknote
		 */
		class CustomData : public CCustomData::Instance,
			public AK::Wwise::Plugin::RequestXml
		{
		public:
			/**
			 * \copydoc CCustomData::Instance
			 */
			using Instance = CCustomData::Instance;

			/**
			 * \brief The interface type, as provided by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as provided by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_CUSTOM_DATA
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

			struct Interface : public CCustomData
			{
				using Instance = CustomData;
				Interface()
				{
					CCustomData::InitToDefault = [](
						struct ak_wwise_plugin_custom_data_instance_v1* in_this)
					{
						static_cast<Instance*>(in_this)->InitToDefault();
					};
					CCustomData::InitFromInstance = [](
						struct ak_wwise_plugin_custom_data_instance_v1* in_this,
						const struct ak_wwise_plugin_custom_data_instance_v1* in_source)
					{
						return (bool)static_cast<Instance*>(in_this)->InitFromInstance(
							*static_cast<const CustomData*>(in_source));
					};
					CCustomData::InitFromWorkunit = [](
						struct ak_wwise_plugin_custom_data_instance_v1* in_this,
						struct ak_wwise_plugin_host_xml_reader_instance_v1* in_pReader)
					{
						return (bool)static_cast<Instance*>(in_this)->InitFromWorkunit(
							*static_cast<XmlReader*>(in_pReader));
					};
					CCustomData::Save = [](
						struct ak_wwise_plugin_custom_data_instance_v1* in_this,
						struct ak_wwise_plugin_host_xml_writer_instance_v1* in_pWriter)
					{
						return (bool)static_cast<Instance*>(in_this)->Save(
							*static_cast<XmlWriter*>(in_pWriter));
					};
					CCustomData::OnDelete = [](
						struct ak_wwise_plugin_custom_data_instance_v1* in_this)
					{
						static_cast<Instance*>(in_this)->OnDelete();
					};
					CCustomData::GetPluginData = [](
						const struct ak_wwise_plugin_custom_data_instance_v1* in_this,
						const GUID* in_guidPlatform,
						AkPluginParamID in_idParam,
						struct ak_wwise_plugin_host_data_writer_instance_v1* in_pDataWriter)
					{
						return (bool)static_cast<const Instance*>(in_this)->GetPluginData(
							*in_guidPlatform,
							in_idParam,
							*static_cast<DataWriter*>(in_pDataWriter));
					};
				}
			};

			/**
			 * \brief The C interface, fulfilled by your plug-in.
			 */
			InterfacePtr GetInterfacePointer() {
				static Interface g_interface;
				return &g_interface;
			}
			CCustomData::Instance* GetInstancePointer() {
				return this;
			}
			const CCustomData::Instance* GetInstancePointer() const {
				return this;
			}

			CustomData() :
				CCustomData::Instance()
			{
			}

			virtual ~CustomData() {}

			/**
			 * \brief Initializes the plug-in's custom data to its default values.
			 * 
			 * This method is mutually exclusive with the other Init methods.
			 */
			virtual void InitToDefault() { }

			/**
			 * \brief Copy the plug-in's custom data from another instance of the same plug-in.
			 * 
			 * This is used during copy/paste and delete for Undo purposes. The properties on
			 * the PropertySet do not need to be copied in this method.
			 * 
			 * This method is mutually exclusive with the other Init methods.
			 * 
			 * \param[in] in_source The object that will provide the data used in initializing
			 *			  this instance.
			 * \return true if successful.
			 */
			virtual bool InitFromInstance(const CustomData& in_source) { return true; }

			/**
			 * \brief Load the custom data structure from the provided Work Unit's XML.
			 * 
			 * This method is mutually exclusive with the other Init methods.
			 * 
			 * \aknote In order to use the in_pReader instance, your plug-in must request the XML
			 *         interface: ak_wwise_plugin_host_xml_v1. \endaknote
			 * 
			 * \param[in] in_reader XML Reader instance.
			 * \return true if load succeeded.
			 */
			virtual bool InitFromWorkunit(XmlReader& in_reader) { return true; }

			/**
			 * \brief Save custom data structure in the provided XML.
			 * 
			 * \aknote In order to use the in_pWriter instance, your plug-in must request the XML
			 *         interface: AK::Wwise::Plugin::RequestXml. \endaknote
			 * 
			 * \param[in] in_writer XML Writer instance.
			 * \return true if save succeeded.
			 */
			virtual bool Save(XmlWriter& in_writer) { return true; }

			/**
			 * \brief OnDelete function is called when the user presses the "delete" button on a plug-in.
			 * 
			 * This handler function should properly clean custom data and set undo/redo action properly
			 * to allow recreation on undo.
			 */
			virtual void OnDelete() { }

			/**
			 * \brief Obtains parameters that will be sent to the sound engine when Wwise is connected.
			 * 
			 * This block should contain only data that is NOT a property defined in the plug-in xml file. The
			 * parameter ID should be different than the ones used in the plug-in xml.
			 * 
			 * This is used when there are Object Store, large binary data sections, or properties not usually
			 * residing in the XML. \sa \ref AudioPlugin::GetBankParameters "GetBankParameters"
			 * for a discussion on parameter passing to the Sound Engine.
			 * 
			 * \aknote In order to use the in_pDataWriter instance, your plug-in must request the data writer
			 *         interface: AK::Wwise::Plugin::RequestWrite. \endaknote
			 * 
			 * \param[in] in_guidPlatform The unique ID of the queried platform
			 * \param[in] in_idParam The plug-in defined parameter ID
			 * \param[in] in_dataWriter A pointer to the data writer instance being used.
			 * \return true if the plug-in has some plug-in defined data.
			 * 
			 * \sa
			 * - \ref AK::Wwise::Plugin::Host::NotifyInternalDataChanged
			 * - \ref AK::IAkPluginParam::ALL_PLUGIN_DATA_ID
			 * - \ref AK::IAkPluginParam::SetParam
			 */
			virtual bool GetPluginData(
				const GUID& in_guidPlatform,
				AkPluginParamID in_idParam,
				DataWriter& in_dataWriter
			) const { return false; }
		};
	} // of namespace V1

	/// Latest version of the C CustomData interface.
	using CCustomData = V1::CCustomData;
	/// Latest version of the C++ CustomData interface.
	using CustomData = V1::CustomData;

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(CustomData);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(CustomData);
} // of namespace AK::Wwise::Plugin

#endif
