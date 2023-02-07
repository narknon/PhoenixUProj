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
 * \brief Wwise Authoring Plug-ins - API for storing objects not in the plug-in XML.
 * \file AK/Wwise/Plugin/HostObjectStore.h
 */

#pragma once

#include "HostPropertySet.h"


/**
 * \brief Custom inner property set interface.
 * 
 * The Object Store contains named lists, and those named lists each contains a vector of inner property sets.
 * 
 * For example, you can create a list named "Property curve points" and have 12 inner property sets with coordinates,
 * configuration and information for the 12 user-created curve points.
 * 
 * Inner property sets can be created from any inner types, as defined in the plug-in's XML definition file
 * <code>InnerTypes</code> section. Your lists should contain recognizable types, as there is no way to poll the
 * type of the created object. This system was created with a one-list-one-type design pattern; however, there is
 * no actual restriction in using different types in a same list.
 * 
 * You can define as many named lists as required. You should consider creating different inner property sets or
 * lists for each platform if the property set indexes aren't linked.
 * 
 * You can create new inner property set with \ref CreatePropertySet, and insert it in a list's index with
 * \ref InsertPropertySet.
 * 
 * You can also subscribe to notifications through ak_wwise_plugin_notifications_object_store_v1 in order to be
 * informed when some inner property set changed.
 * 
 * \aknote
 * 		In order to manage property sets, you must make sure to use \ref AK::Wwise::Plugin::RequestPropertySet in
 * 		your plug-in.
 * \endaknote
 * 
 * \aknote
 * 		Historical naming convention described it as "inner object" and "inner type". For simplicity,
 * 		since we are talking about property sets, the naming has been standardized to "inner property set".
 * 		However, the names are interchangeable and are still being used.
 * \endaknote
 * 
 * \sa
 * - \ref wwiseplugin_objectstore
 * - \ref wwiseplugin_xml_properties_tag
 * - \ref ak_wwise_plugin_notifications_object_store_v1
 */
struct ak_wwise_plugin_host_object_store_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base host-provided instance type for ak_wwise_plugin_host_object_store_v1.
	using Instance = ak_wwise_plugin_host_object_store_instance_v1;

	ak_wwise_plugin_host_object_store_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_OBJECT_STORE, 1)
	{}
#endif

	/**
	 * \brief Inserts an inner property set into the specified list at the specified position.
	 * 
	 * To create a new inner property set, use \ref CreatePropertySet . You can then insert
	 * that particular inner property set in the named list <code>in_pszListName</code>, at the
	 * <code>in_uiIndex</code> position, so it will be stored in the project data. Existing object positions
	 * equal to or higher than <code>in_uiIndex</code> will be incremented as required.
	 * 
	 * Named lists are created automatically, there is no limitation for naming. However, you should use the
	 * standardized naming convention for better memory usage in Wwise Authoring. List ordering is
	 * arbitrary.
	 * 
	 * \aknote
	 * 		You must add up indexes sequentially. If you have 0-14 indexes, adding a new one at 40 will
	 * 		create it at 15. Pass <code>(unsigned int)-1</code> as the in_uiIndex to insert at the end of
	 * 		the list.
	 * \endaknote
	 * 
	 * \akwarning
	 * 		Never reuse the same inner property set under two different indexes or lists. If you are
	 * 		uncertain, or if you want to move it elsewhere, use \ref RemovePropertySet before
	 * 		inserting it elsewhere.
	 * \endakwarning
	 * 
	 * \sa
	 * - \ref ak_wwise_plugin_notifications_object_store_v1::NotifyInnerObjectAddedRemoved
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pszListName Name of the affected list. That list will be created or appended depending
	 *            on the situation.
	 * \param[in] in_uiIndex Inner property set index in the list. If higher than or equal to the current
	 *            object count in that list, will add a new index. Otherwise, increments previous object's
	 * 			  indexes to make room for this new inner property set.
	 * \param[in] in_pPropertySet The inner property set to include in the list's index. This property set
	 * 			  must be created with \ref CreatePropertySet and not used elsewhere.
	 */
	void(*InsertPropertySet)(
		struct ak_wwise_plugin_host_object_store_instance_v1* in_this,
		const char * in_pszListName,
		unsigned int in_uiIndex,
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_pPropertySet
	);

	/**
	 * \brief Removes an inner property set from any list, without deleting the object itself.
	 * 
	 * This is useful if you still need the object internally, or if you want to move that object to another
	 * list or index.
	 * 
	 * If a list doesn't contain any items anymore, the list will automatically be deleted.
	 * 
	 * The function \ref DeletePropertySet must be used if you still keep that reference without being
	 * reinserted through \ref InsertPropertySet. For normal deletion, you should execute
	 * \ref DeletePropertySet function directly, and it will remove any usage automatically.
	 * 
	 * \sa
	 * - \ref ak_wwise_plugin_notifications_object_store_v1::NotifyInnerObjectAddedRemoved
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pPropertySet The inner property set to remove from any list's index. The object is not
	 *            deleted.
	 * \return true if successful
	 */
	bool(*RemovePropertySet)(
		struct ak_wwise_plugin_host_object_store_instance_v1* in_this,
		const struct ak_wwise_plugin_host_property_set_instance_v1* in_pPropertySet
	);

	/**
	 * \brief Gets an inner property set inside the specified list at the specified position.
	 * 
	 * Wwise Authoring handles the object's lifetime as long as it's inserted. You should not call
	 * \ref DeletePropertySet unless you want to remove it from your plug-in instance's objects.
	 * 
	 * \aknote
	 * 		In order to manage property sets, you must make sure to use
	 * 		\ref AK::Wwise::Plugin::RequestPropertySet.
	 * \endaknote
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pszListName Name of the polled list. If the list doesn't exist, the function will
	 * 			  return nullptr.
	 * \param[in] in_uiIndex Inner property set index in the list. If higher than or equal to the current
	 *            object count in that list, the function will return nullptr.
	 * \return The requested inner property set, or nullptr if not existing.
	 */
	struct ak_wwise_plugin_host_property_set_instance_v1*(*GetPropertySet)(
		const struct ak_wwise_plugin_host_object_store_instance_v1* in_this,
		const char * in_pszListName,
		unsigned int in_uiIndex
	);

	/**
	 * \brief Gets the number of inserted indexes inside the specified list.
	 * 
	 * If the list doesn't exist, 0 will be returned.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pszListName Name of the polled list. If the list doesn't exist, the function will
	 * 			  return 0.
	 * \return The number of inner property sets inside the list in_pszListName.
	 */
	unsigned int(*GetPropertySetCount)(
		const struct ak_wwise_plugin_host_object_store_instance_v1* in_this,
		const char * in_pszListName
	);

	/**
	 * \brief Creates a new inner property set.
	 * 
	 * An inner property set must be defined as a particular <code>InnerType</code> in the plug-in's XML
	 * definition file.
	 * 
	 * When this object is created, it is not bound to any list. As such, this is the only moment
	 * where it is under the plug-in's responsibility. You should either call
	 * \ref InsertPropertySet or \ref DeletePropertySet on it to make sure the plug-in doesn't cause
	 * a memory leak.
	 * 
	 * \sa
	 * - \ref wwiseplugin_objectstore
	 * - \ref wwiseplugin_xml_properties_tag
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pszType The requested InnerType, as defined in the plug-in's XML definition file.
	 * \return A new inner property set instance.
	 */
	struct ak_wwise_plugin_host_property_set_instance_v1*(*CreatePropertySet)(
		struct ak_wwise_plugin_host_object_store_instance_v1* in_this,
		const char * in_pszType
	);

	/**
	 * \brief Frees the inner property set.
	 * 
	 * It will also remove the object from its list if the object has been inserted. As such, you are not
	 * required to call \ref RemovePropertySet beforehand.
	 * 
	 * \akwarning
	 * 		Do not use the in_pPropertySet after calling this function.
	 * \endakwarning
	 * 
	 * \sa
	 * - \ref ak_wwise_plugin_notifications_object_store_v1::NotifyInnerObjectAddedRemoved
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pPropertySet The inner property set to permanently delete.
	 */
	void(*DeletePropertySet)(
		struct ak_wwise_plugin_host_object_store_instance_v1* in_this,
		struct ak_wwise_plugin_host_property_set_instance_v1* in_pPropertySet
	);

	/**
	 * \brief Returns the number of inner property set lists to be used with GetListName.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return Number of property set lists, or 0 if there are none.
	 */
	unsigned int(*GetListCount)(
		const struct ak_wwise_plugin_host_object_store_instance_v1* in_this
	);

	/**
	 * \brief Gets the name of the list at the specified position.
	 * 
	 * List ordering is arbitrary and can vary between Wwise Authoring versions or project loads.
	 * 
	 * \akwarning
	 * 		If you do not provide a buffer big enough to write the full string, the function will fail and
	 * 		return 0. Make sure to use a buffer big enough to write the entire string, depending
	 * 		on your own naming convention.
	 * \endakwarning
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_uiListIndex Index of the list name to retrieve.
	 * \param[out] out_pszListName Pointer to a buffer that will contain the list name.
	 * \param[in] in_uiBufferSize Size of the provided buffer. If the buffer is not big enough for the
	 * 			  entire name alongside a string ending suffix, the function will return 0 and no string
	 *            will be copied.
	 * \return Number of characters written to the buffer, zero if failed.
	 */
	unsigned int(*GetListName)(
		const struct ak_wwise_plugin_host_object_store_instance_v1* in_this,
		unsigned int in_uiListIndex,
		char * out_pszListName,
		unsigned int in_uiBufferSize
	);
};


/**
 * \brief Interface able to receive notifications for custom inner property sets.
 * 
 * \aknote
 * 		In order to manage property sets, you must make sure to use \ref AK::Wwise::Plugin::RequestPropertySet in
 * 		your plug-in.
 * \endaknote
 *
 * \sa
 * - \ref wwiseplugin_objectstore
 * - \ref ak_wwise_plugin_host_object_store_v1
 */
struct ak_wwise_plugin_notifications_object_store_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for receiving notifications on related Object Store's changes.
	using Instance = ak_wwise_plugin_notifications_object_store_instance_v1;

	ak_wwise_plugin_notifications_object_store_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_OBJECT_STORE, 1)
	{}
#endif

	/**
	 * \brief Called when an inner property set's data has changed.
	 * 
	 * For example, data can change through interaction with a UI control bound to a property,
	 * or through undo/redo operations.
	 * 
	 * \sa
	 * - \ref wwiseplugin_objectstore_notifications
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pPSet The inner property set that changed.
	 * \param[in] in_guidPlatform The unique ID of the queried platform.
	 * \param[in] in_pszPropertyName The name of the property that changed.
	 */
	void(*NotifyInnerObjectPropertyChanged)(
		struct ak_wwise_plugin_notifications_object_store_instance_v1* in_this,
		struct ak_wwise_plugin_host_property_set_instance_v1* in_pPSet,
		const GUID * in_guidPlatform,
		const char * in_pszPropertyName
	);

	/**
	 * \brief Called when an inner property set has changed.
	 * 
	 * For example, at a backend data refresh, a UI control bound to a property, or through
	 * undo/redo operations.
	 * 
	 * \sa
	 * - \ref wwiseplugin_objectstore_notifications
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pPSet The inner property set that was added or removed.
	 * \param[in] in_uiIndex The insertion/removal index inside a named list.
	 * \param[in] in_eOperation InnerObjectAdded or InnerObjectRemoved.
	 */
	void(*NotifyInnerObjectAddedRemoved)(
		struct ak_wwise_plugin_notifications_object_store_instance_v1* in_this,
		struct ak_wwise_plugin_host_property_set_instance_v1* in_pPSet,
		unsigned int in_uiIndex,
		AK::Wwise::Plugin::NotifyInnerObjectOperation in_eOperation
	);
};


#define AK_WWISE_PLUGIN_HOST_OBJECT_STORE_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_OBJECT_STORE, 1)
#define AK_WWISE_PLUGIN_HOST_OBJECT_STORE_V1_CTOR() \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_HOST_OBJECT_STORE_V1_ID() \
}

#define AK_WWISE_PLUGIN_NOTIFICATIONS_OBJECT_STORE_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_OBJECT_STORE, 1)
#define AK_WWISE_PLUGIN_NOTIFICATIONS_OBJECT_STORE_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_NOTIFICATIONS_OBJECT_STORE_V1_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CHostObjectStore = ak_wwise_plugin_host_object_store_v1;

		/// \copydoc ak_wwise_plugin_host_object_store_v1 
		class ObjectStore : public CBaseInstanceGlue<CHostObjectStore>
		{
		public:
			using Interface = CHostObjectStore;

			/**
			 * \brief The interface type, as requested by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as requested by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_OBJECT_STORE
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
			 * \brief Inserts an inner property set into the specified list at the specified position.
			 * 
			 * To create a new inner property set, use \ref CreatePropertySet . You can then insert
			 * that particular inner property set in the named list <code>in_pszListName</code>, at the
			 * <code>in_uiIndex</code> position, so it will be stored in the project data. Existing object positions
			 * equal to or higher than <code>in_uiIndex</code> will be incremented as required.
			 * 
			 * Named lists are created automatically, there is no limitation for naming. However, you should use the
			 * standardized naming convention for better memory usage in Wwise Authoring. List ordering is
			 * arbitrary.
			 * 
			 * \aknote
			 * 		You must add up indexes sequentially. If you have 0-14 indexes, adding a new one at 40 will
			 * 		create it at 15. Pass <code>(unsigned int)-1</code> as the in_uiIndex to insert at the end of
			 * 		the list.
			 * \endaknote
			 * 
			 * \akwarning
			 * 		Never reuse the same inner property set under two different indexes or lists. If you are
			 * 		uncertain, or if you want to move it elsewhere, use \ref RemovePropertySet before
			 * 		inserting it elsewhere.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref ak_wwise_plugin_notifications_object_store_v1::NotifyInnerObjectAddedRemoved
			 * 
			 * \param[in] in_pszListName Name of the affected list. That list will be created or appended depending
			 *            on the situation.
			 * \param[in] in_uiIndex Inner property set index in the list. If higher than or equal to the current
			 *            object count in that list, will add a new index. Otherwise, increments previous object's
			 * 			  indexes to make room for this new inner property set.
			 * \param[in] in_propertySet The inner property set to include in the list's index. This property set
			 * 			  must be created with \ref CreatePropertySet and not used elsewhere.
			 */
			inline void InsertPropertySet(
				const char * in_pszListName,
				unsigned int in_uiIndex,
				const PropertySet& in_propertySet
			)
			{
				g_cinterface->InsertPropertySet(this, in_pszListName, in_uiIndex, &in_propertySet);
			}

			/**
			 * \brief Removes an inner property set from any list, without deleting the object itself.
			 * 
			 * This is useful if you still need the object internally, or if you want to move that object to another
			 * list or index.
			 * 
			 * If a list doesn't contain any items anymore, the list will automatically be deleted.
			 * 
			 * The function \ref DeletePropertySet must be used if you still keep that reference without being
			 * reinserted through \ref InsertPropertySet. For normal deletion, you should execute
			 * \ref DeletePropertySet function directly, and it will remove any usage automatically.
			 * 
			 * \sa
			 * - \ref ak_wwise_plugin_notifications_object_store_v1::NotifyInnerObjectAddedRemoved
			 * 
			 * \param[in] in_propertySet The inner property set to remove from any list's index. The object is not
			 *            deleted.
			 * \return true if successful
			 */
			inline bool RemovePropertySet(
				const PropertySet& in_propertySet
			)
			{
				return MKBOOL(g_cinterface->RemovePropertySet(this, &in_propertySet));
			}

			/**
			 * \brief Gets an inner property set inside the specified list at the specified position.
			 * 
			 * Wwise Authoring handles the object's lifetime as long as it's inserted. You should not call
			 * \ref DeletePropertySet unless you want to remove it from your plug-in instance's objects.
			 * 
			 * \aknote
			 * 		In order to manage property sets, you must make sure to use
			 * 		\ref AK::Wwise::Plugin::RequestPropertySet.
			 * \endaknote
			 * 
			 * \param[in] in_pszListName Name of the polled list. If the list doesn't exist, the function will
			 * 			  return nullptr.
			 * \param[in] in_uiIndex Inner property set index in the list. If higher than or equal to the current
			 *            object count in that list, the function will return nullptr.
			 * \return The requested inner property set, or nullptr if not existing.
			 */
			inline PropertySet* GetPropertySet(
				const char * in_pszListName,
				unsigned int in_uiIndex
			) const
			{
				return static_cast<PropertySet*>(g_cinterface->GetPropertySet(this, in_pszListName, in_uiIndex));
			}

			/**
			 * \brief Gets the number of inserted indexes inside the specified list.
			 * 
			 * If the list doesn't exist, 0 will be returned.
			 * 
			 * \param[in] in_pszListName Name of the polled list. If the list doesn't exist, the function will
			 * 			  return 0.
			 * \return The number of inner property sets inside the list in_pszListName.
			 */
			inline unsigned int GetPropertySetCount(
				const char * in_pszListName
			) const
			{
				return g_cinterface->GetPropertySetCount(this, in_pszListName);
			}

			/**
			 * \brief Creates a new inner property set.
			 * 
			 * An inner property set must be defined as a particular <code>InnerType</code> in the plug-in's XML
			 * definition file.
			 * 
			 * When this object is created, it is not bound to any list. As such, this is the only moment
			 * where it is under the plug-in's responsibility. You should either call
			 * \ref InsertPropertySet or \ref DeletePropertySet on it to make sure the plug-in doesn't cause
			 * a memory leak.
			 * 
			 * \sa
			 * - \ref wwiseplugin_objectstore
			 * - \ref wwiseplugin_xml_properties_tag
			 * 
			 * \param[in] in_pszType The requested InnerType, as defined in the plug-in's XML definition file.
			 * \return A new inner property set instance.
			 */
			inline PropertySet* CreatePropertySet(
				const char * in_pszType
			)
			{
				return static_cast<PropertySet*>(g_cinterface->CreatePropertySet(this, in_pszType));
			}

			/**
			 * \brief Frees the inner property set.
			 * 
			 * It will also remove the object from its list if the object has been inserted. As such, you are not
			 * required to call \ref RemovePropertySet beforehand.
			 * 
			 * \akwarning
			 * 		Do not use the in_pPropertySet after calling this function.
			 * \endakwarning
			 * 
			 * \sa
			 * - \ref ak_wwise_plugin_notifications_object_store_v1::NotifyInnerObjectAddedRemoved
			 * 
			 * \param[in] in_pPropertySet The inner property set to permanently delete.
			 */
			inline void DeletePropertySet(
				PropertySet* in_pPropertySet
			)
			{
				g_cinterface->DeletePropertySet(this, in_pPropertySet);
			}

			/**
			 * \brief Returns the number of inner property set lists to be used with GetListName.
			 * 
			 * \return Number of property set lists, or 0 if there are none.
			 */
			inline unsigned int GetListCount(
			) const
			{
				return g_cinterface->GetListCount(this);
			}

			/**
			 * \brief Gets the name of the list at the specified position.
			 * 
			 * List ordering is arbitrary and can vary between Wwise Authoring versions or project loads.
			 * 
			 * \akwarning
			 * 		If you do not provide a buffer big enough to write the full string, the function will fail and
			 * 		return 0. Make sure to use a buffer big enough to write the entire string, depending
			 * 		on your own naming convention.
			 * \endakwarning
			 * 
			 * \param[in] in_uiListIndex Index of the list name to retrieve.
			 * \param[out] out_pszListName Pointer to a buffer that will contain the list name.
			 * \param[in] in_uiBufferSize Size of the provided buffer. If the buffer is not big enough for the
			 * 			  entire name alongside a string ending suffix, the function will return 0 and no string
			 *            will be copied.
			 * \return Number of characters written to the buffer, zero if failed.
			 */
			inline unsigned int GetListName(
				unsigned int in_uiListIndex,
				char * out_pszListName,
				unsigned int in_uiBufferSize
			) const
			{
				return g_cinterface->GetListName(this, in_uiListIndex, out_pszListName, in_uiBufferSize);
			}
		};

		namespace Notifications
		{
			using CObjectStore_ = ak_wwise_plugin_notifications_object_store_v1;

			/// \copydoc ak_wwise_plugin_notifications_object_store_v1
			class ObjectStore_ : public CObjectStore_::Instance
			{
			public:
				/**
				 * \copydoc CObjectStore_::Instance
				 */
				using Instance = CObjectStore_::Instance;

				/**
				 * \brief The interface type, as provided by this plug-in.
				 */
				enum : InterfaceTypeValue
				{
					/**
					 * \brief The interface type, as provided by this plug-in.
					 */
					k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_OBJECT_STORE
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
				struct Interface : public CObjectStore_
				{
					using Instance = ObjectStore_;
					Interface()
					{
						CObjectStore_::NotifyInnerObjectPropertyChanged = [](
							struct ak_wwise_plugin_notifications_object_store_instance_v1* in_this,
							struct ak_wwise_plugin_host_property_set_instance_v1* in_pPSet,
							const GUID * in_guidPlatform,
							const char * in_pszPropertyName)
						{
							static_cast<Instance*>(in_this)->NotifyInnerObjectPropertyChanged(
								*static_cast<PropertySet*>(in_pPSet),
								*in_guidPlatform,
								in_pszPropertyName);
						};
						CObjectStore_::NotifyInnerObjectAddedRemoved = [](
							struct ak_wwise_plugin_notifications_object_store_instance_v1* in_this,
							struct ak_wwise_plugin_host_property_set_instance_v1* in_pPSet,
							unsigned int in_uiIndex,
							NotifyInnerObjectOperation in_eOperation)
						{
							static_cast<Instance*>(in_this)->NotifyInnerObjectAddedRemoved(
								*static_cast<PropertySet*>(in_pPSet),
								in_uiIndex,
								in_eOperation);
						};
					}
				};

				InterfacePtr GetInterfacePointer() {
					static Interface g_interface;
					return &g_interface;
				}
				CObjectStore_::Instance* GetInstancePointer() {
					return this;
				}
				const CObjectStore_::Instance* GetInstancePointer() const {
					return this;
				}

				ObjectStore_() :
					CObjectStore_::Instance()
				{
				}

				virtual ~ObjectStore_() {}

				/**
				 * \brief Called when an inner property set's data has changed.
				 * 
				 * For example, data can change through interaction with a UI control bound to a property,
				 * or through undo/redo operations.
				 * 
				 * \sa
				 * - \ref wwiseplugin_objectstore_notifications
				 * 
				 * \param[in] in_PSet The inner property set that changed.
				 * \param[in] in_guidPlatform The unique ID of the queried platform.
				 * \param[in] in_pszPropertyName The name of the property that changed.
				 */
				virtual void NotifyInnerObjectPropertyChanged(
					PropertySet& in_PSet,
					const GUID& in_guidPlatform,
					const char* in_pszPropertyName
				) {}

				/**
				 * \brief Called when an inner property set has changed.
				 * 
				 * For example, at a backend data refresh, a UI control bound to a property, or through
				 * undo/redo operations.
				 * 
				 * \sa
				 * - \ref wwiseplugin_objectstore_notifications
				 * 
				 * \param[in] in_PSet The inner property set that was added or removed.
				 * \param[in] in_uiIndex The insertion/removal index inside a named list.
				 * \param[in] in_eOperation InnerObjectAdded or InnerObjectRemoved.
				 */
				virtual void NotifyInnerObjectAddedRemoved(
					PropertySet& in_PSet,
					unsigned int in_uiIndex,
					NotifyInnerObjectOperation in_eOperation
				) {}
			};
		} // of namespace Notifications

		/**
		 * \brief Requests an ObjectStore interface, provided as m_objectStore variable.
		 * 
		 * Deriving your plug-in class from RequestObjectStore will automatically request both ObjectStore and
		 * Notifications::ObjectStore_ interfaces. From this point, you will be able to derive from the virtual
		 * functions, as defined in Notifications::ObjectStore_, and access the host-provided functions in the
		 * \c m_objectStore variable.
		 */
		using RequestObjectStore = RequestedHostInterface<ObjectStore>;

	} // of namespace V1

	/// Latest version of the C ObjectStore interface.
	using CHostObjectStore = V1::CHostObjectStore;
	/// Latest version of the C++ ObjectStore interface.
	using ObjectStore = V1::ObjectStore;
	/// Latest version of the requested C++ ObjectStore interface.
	using RequestObjectStore = V1::RequestObjectStore;

	namespace Notifications
	{
		/// Latest version of the C ObjectStore notification interface.
		using CObjectStore = V1::Notifications::CObjectStore_;
		/// Latest version of the C++ ObjectStore notification interface.
		using ObjectStore = V1::Notifications::ObjectStore_;
	}

	AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE(ObjectStore, objectStore,, public Notifications::ObjectStore);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(ObjectStore);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(ObjectStore);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(Notifications::ObjectStore);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(Notifications::ObjectStore);

} // of namespace AK::Wwise::Plugin

#endif
