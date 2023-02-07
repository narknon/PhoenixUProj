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
 * \brief Wwise Authoring Plug-ins - API to provide custom undo event and manage undo groups.
 * \file AK/Wwise/Plugin/HostUndoManager.h
 */

#pragma once

#include "HostPropertySet.h"

/**
 * \brief API to create a custom undo event in a plug-in.
 * 
 * This is useful when you handle custom properties, not handled by Property Sets.
 */
struct ak_wwise_plugin_undo_event_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for providing custom undo operations.
	using Instance = ak_wwise_plugin_undo_event_instance_v1;

	ak_wwise_plugin_undo_event_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_UNDO_EVENT, 1)
	{}
	ak_wwise_plugin_undo_event_v1(decltype(m_interface) in_interface, decltype(m_version) in_version) :
		ak_wwise_plugin_base_interface(in_interface, in_version)
	{}
	ak_wwise_plugin_undo_event_v1(std::underlying_type<decltype(m_interface)>::type in_interface, decltype(m_version) in_version) :
		ak_wwise_plugin_base_interface((decltype(m_interface))in_interface, in_version)
	{}
#endif

	/**
	 * \brief Called when the system needs to destroy your ak_wwise_plugin_undo_event_v1 instance.
	 * 
	 * Since your plug-in created the instance, you are responsible for destroying it.
	 * 
	 * \param[in] in_this Current instance of this Undo Event instance.
	 */
	void(*Destroy)(struct ak_wwise_plugin_undo_event_instance_v1* in_this);

	/**
	 * \brief Called when the user asks to undo an action.
	 * 
	 * \akwarning The backend instance is provided to you. You should never keep pointers to any plug-in instances
	 *            or services, as these might have been deleted and recreated in the meantime. \endakwarning
	 * 
	 * \param[in] in_this Current instance of this Undo Event.
	 * \param[in] in_backend The backend instance that created this event.
	 */
	bool(*Undo)(
		struct ak_wwise_plugin_undo_event_instance_v1* in_this,
		struct ak_wwise_plugin_backend_instance* in_backend);

	/**
	 * \brief Called when the user asks to redo an action.
	 * 
	 * \akwarning The backend instance is provided to you. You should never keep pointers to any plug-in instances
	 *            or services, as these might have been deleted and recreated in the meantime. \endakwarning
	 * 
	 * \param[in] in_this Current instance of this Undo Event instance.
	 * \param[in] in_backend The backend instance that created this event.
	 */
	bool(*Redo)(
		struct ak_wwise_plugin_undo_event_instance_v1* in_this,
		struct ak_wwise_plugin_backend_instance* in_backend);

	/**
	 * \brief Get the event name, to show after the "Undo " and "Redo " terms in the menu.
	 * 
	 * \param[in] in_this Current instance of this Undo Event.
	 * \param[out] out_csName Pointer to a static name for this event. The buffer is owned by Authoring and is 
	 *   valid until the next API call.
	 * \return true if successful.
	 */
	bool(*GetName)(
		const struct ak_wwise_plugin_undo_event_instance_v1* in_this,
		const char ** out_csName);
};
#define AK_WWISE_PLUGIN_UNDO_EVENT_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_UNDO_EVENT, 1)
#define AK_WWISE_PLUGIN_UNDO_EVENT_V1_CTOR() \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_UNDO_EVENT_V1_ID()) \
}


/**
 * \brief Host API to handle the plug-in's undo operations.
 */
struct ak_wwise_plugin_host_undo_manager_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base host-provided instance type for ak_wwise_plugin_host_undo_manager_v1.
	using Instance = ak_wwise_plugin_host_undo_manager_instance_v1;

	ak_wwise_plugin_host_undo_manager_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_UNDO_MANAGER, 1)
	{}
#endif

	/**
	 * \brief Open a group that will contain all subsequent undo events.
	 * 
	 * This must be done prior to performing any action on PropertySets, or adding custom events, as it is important to
	 * have one unique element on the undo stack. You can open multiple groups at once, like a stack, as long as you
	 * close them before exiting your function.
	 * 
	 * in_reopenGroupId should be set to 0 for a new group.
	 * 
	 * Example:
	 * <code>
	 * ak_wwise_plugin_undo_group_id m_dragAndDropGroupId = 0;
	 * m_dragAndDropGroupId = OpenGroup(this, m_dragAndDropGroupId);
	 * if (m_dragAndDropGroupId == 0) return;
	 * CloseGroup(this,
	 *            m_done ? AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY :
	 *                     AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_CLOSE,
	 *            "Drag and drop");
	 * if (m_done) m_dragAndDropGroupId = 0;
	 * </code>
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_reopenGroupId Previously opened undo group, or 0 for a new group.
	 * \return The new undo group that just got created, or 0 if the system cannot open a group at the moment.
	 */
	ak_wwise_plugin_undo_group_id (*OpenGroup)(
		struct ak_wwise_plugin_host_undo_manager_instance_v1* in_this,
		ak_wwise_plugin_undo_group_id in_reopenGroupId);

	/**
	 * \brief Closes the last opened group, in stack ordering.
	 * 
	 * Close the current group (_CLOSE) and add its content as a unique entry to the previous group,
	 * or to the Undo stack (_APPLY), or cancel its contents (_CANCEL).
	 * 
	 * in_szApplyEventName is only used for _APPLY. It is ignored elsewhere, and needs to be nullptr on
	 * _APPLY_FIRST_EVENT_NAME or _APPLY_LAST_EVENT_NAME.
	 * 
	 * in_groupId is only for validation, you can pass 0 if you do not wish to provide this validation.
	 * 
	 * \akwarning Cancelling contents doesn't undo all the grouped actions. You are responsible for doing all the proper
	 *            undoing before closing the group. \akwarning
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_action Action to perform when closing the group. Should usually
	 *            be AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY. 
	 * \param[in] in_groupId (Optional, pass 0) Validation to make sure the group being closed has the proper ID.
	 * \param[in] in_szApplyEventName Event name. Added after "Undo " and "Redo " in the menu.
	 * \return true if successful.
	 */
	bool(*CloseGroup)(
		struct ak_wwise_plugin_host_undo_manager_instance_v1* in_this,
		ak_wwise_plugin_undo_group_close_action in_action,
		ak_wwise_plugin_undo_group_id in_groupId,
		const char * in_szApplyEventName);

	/**
	 * \brief Adds a custom event to the currently opened group.
	 * 
	 * By default, you should be in a group while adding an event.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_event Event to add to the current group.
	 * \return true if successful.
	 */
	bool(*AddCustomEvent)(
		struct ak_wwise_plugin_host_undo_manager_instance_v1* in_this,
		struct ak_wwise_plugin_undo_event_pair_v1 in_event);

	/**
	 * \brief Check if we are currently in a state where we can add undo events.
	 * 
	 * This is different than not being in a group. You should always be in a group when you want to add an event.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return true if we can add an event.
	 */
	bool(*CanAddEvent)(const struct ak_wwise_plugin_host_undo_manager_instance_v1* in_this);

	/**
	 * \brief Check if we are busy (undoing or redoing).
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return true if we are currently performing an undo operation.
	 */
	bool(*IsBusy)(const struct ak_wwise_plugin_host_undo_manager_instance_v1* in_this);

	/**
	 * \brief Returns whether logging can occur or not.
	 * 
	 * Call this function when you are about to log an undo event to know if Wwise is in a state
	 * where undos are enabled. Undo logging can be disabled for a particular plug-in object if
	 * it already lives in the undo stack or in the clipboard.
	 * 
	 * This function is useful to determine whether a complex undo operation can be started without opening a
	 * new undo group (see \ref ak_wwise_plugin_host_undo_manager_v1::OpenGroup). Otherwise, the simple fact of
	 * opening an undo group will give a result of 0 if it's not possible to log undos at this time.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return true if the plug-in can log undo events at this time.
	 */
	bool(*CanLogUndos)(
		const struct ak_wwise_plugin_host_undo_manager_instance_v1* in_this);
};
#define AK_WWISE_PLUGIN_HOST_UNDO_MANAGER_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_UNDO_MANAGER, 1)
#define AK_WWISE_PLUGIN_HOST_UNDO_MANAGER_V1_CTOR() \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_HOST_UNDO_MANAGER_V1_ID() \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CUndoEvent = ak_wwise_plugin_undo_event_v1;
		using CUndoEventPair = ak_wwise_plugin_undo_event_pair_v1;

		/**
		 * \brief Base API to create a custom undo event in a plug-in.
		 * 
		 * This is useful when you handle custom properties, not handled by Property Sets.
		 * 
		 * UndoEvent should be handled by the \ref UndoEvent template.
		 */
		class BaseUndoEvent : public CUndoEvent::Instance
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
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_UNDO_EVENT
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

			using Interface = CUndoEvent;

			virtual Interface* GetInterfacePointer() = 0;

			CUndoEvent::Instance* GetInstancePointer() {
				return this;
			}

			const CUndoEvent::Instance* GetInstancePointer() const {
				return this;
			}

			BaseUndoEvent() :
				CUndoEvent::Instance()
			{
			}

			virtual ~BaseUndoEvent() {}
		};

		/**
		 * \brief Base API to create a custom undo event in a plug-in.
		 * 
		 * This is useful when you handle custom properties, not handled by Property Sets.
		 * 
		 * Undo events should be derived by your undo class, providing \ref UndoEvent::Undo,
		 * \ref UndoEvent::Redo and \ref UndoEvent::GetName methods.
		 * 
		 * No pointer to the backend class should be kept inside the undo event, as the object can be deleted
		 * and recreated when the plug-in gets removed through undo. The backend will be recreated at that point,
		 * making the pointer invalid.
		 * 
		 * \tparam Backend The plug-in backend type.
		 */
		template<typename Backend>
		class UndoEvent : public BaseUndoEvent
		{
		public:
			struct Interface : public BaseUndoEvent::Interface
			{
				using Instance = UndoEvent;

				/**
				 * \brief The C interface, fulfilled by your plug-in.
				 */
				Interface()
				{
					CUndoEvent::Destroy = [](
						struct ak_wwise_plugin_undo_event_instance_v1* in_this)
					{
						delete static_cast<Instance*>(in_this);
					};
					CUndoEvent::Undo = [](
						struct ak_wwise_plugin_undo_event_instance_v1* in_this,
						struct ak_wwise_plugin_backend_instance* in_backend)
					{
						return (bool)static_cast<Instance*>(in_this)->Undo(*static_cast<Backend*>(in_backend));
					};
					CUndoEvent::Redo = [](
						struct ak_wwise_plugin_undo_event_instance_v1* in_this,
						struct ak_wwise_plugin_backend_instance* in_backend)
					{
						return (bool)static_cast<Instance*>(in_this)->Redo(*static_cast<Backend*>(in_backend));
					};
					CUndoEvent::GetName = [](
						const struct ak_wwise_plugin_undo_event_instance_v1* in_this,
						const char ** out_csName)
					{
						return (bool)static_cast<const Instance*>(in_this)->GetName(
							out_csName);
					};
				}
			};

			virtual BaseUndoEvent::Interface* GetInterfacePointer() final {
				static Interface g_interface;
				return &g_interface;
			}

			/**
			 * \brief Called when the user asks to undo an action.
			 * 
			 * \akwarning The backend instance is provided to you. You should never keep pointers to any plug-in instances
			 *            or services, as these might have been deleted and recreated in the meantime. \endakwarning
			 * 
			 * \param[in] in_backend The backend instance that created this event.
			 */
			virtual bool Undo(Backend& in_backend) = 0;

			/**
			 * \brief Called when the user asks to redo an action.
			 * 
			 * \akwarning The backend instance is provided to you. You should never keep pointers to any plug-in instances
			 *            or services, as these might have been deleted and recreated in the meantime. \endakwarning
			 * 
			 * \param[in] in_backend The backend instance that created this event.
			 */
			virtual bool Redo(Backend& in_backend) = 0;

			/**
			 * \brief Get the event name, to show after the "Undo " and "Redo " terms in the menu.
			 * 
			 * \param[out] out_csName Pointer to a static name for this event. This pointer needs to be accessible as long
			 *             as the event is not destroyed.
			 * \return true if successful.
			 */
			virtual bool GetName(const char ** out_csName) const = 0;
		};

		template<typename BackendDerivedClass>
		class DynamicUndoEvent : public BaseUndoEvent
		{
		public:
			struct Interface : public BaseUndoEvent::Interface
			{
				using Instance = DynamicUndoEvent;

				/**
				 * \brief The C interface, fulfilled by your plug-in.
				 */
				Interface()
				{
					CUndoEvent::Destroy = [](
						struct ak_wwise_plugin_undo_event_instance_v1* in_this)
					{
						delete static_cast<Instance*>(in_this);
					};
					CUndoEvent::Undo = [](
						struct ak_wwise_plugin_undo_event_instance_v1* in_this,
						struct ak_wwise_plugin_backend_instance* in_backend)
					{
						BackendDerivedClass *backend = dynamic_cast<BackendDerivedClass*>(in_backend);
						if (backend)
							return (bool)static_cast<Instance*>(in_this)->Undo(*backend);
						else
							return false;
					};
					CUndoEvent::Redo = [](
						struct ak_wwise_plugin_undo_event_instance_v1* in_this,
						struct ak_wwise_plugin_backend_instance* in_backend)
					{
						BackendDerivedClass *backend = dynamic_cast<BackendDerivedClass*>(in_backend);
						if (backend)
							return (bool)static_cast<Instance*>(in_this)->Redo(*backend);
						else
							return false;
					};
					CUndoEvent::GetName = [](
						const struct ak_wwise_plugin_undo_event_instance_v1* in_this,
						const char ** out_csName)
					{
						return (bool)static_cast<const Instance*>(in_this)->GetName(
							out_csName);
					};
				}
			};

			virtual BaseUndoEvent::Interface* GetInterfacePointer() final {
				static Interface g_interface;
				return &g_interface;
			}

			/**
			 * \brief Called when the user asks to undo an action.
			 * 
			 * \akwarning The backend instance is provided to you. You should never keep pointers to any plug-in instances
			 *            or services, as these might have been deleted and recreated in the meantime. \endakwarning
			 * 
			 * \param[in] in_backend The backend instance that created this event.
			 */
			virtual bool Undo(BackendDerivedClass& in_backend) = 0;

			/**
			 * \brief Called when the user asks to redo an action.
			 * 
			 * \akwarning The backend instance is provided to you. You should never keep pointers to any plug-in instances
			 *            or services, as these might have been deleted and recreated in the meantime. \endakwarning
			 * 
			 * \param[in] in_backend The backend instance that created this event.
			 */
			virtual bool Redo(BackendDerivedClass& in_backend) = 0;

			/**
			 * \brief Get the event name, to show after the "Undo " and "Redo " terms in the menu.
			 * 
			 * \param[out] out_csName Pointer to a static name for this event. The buffer is owned by Authoring and is 
			 *   valid until the next API call.
			 * \return true if successful.
			 */
			virtual bool GetName(const char ** out_csName) const = 0;
		};

		using CHostUndoManager = ak_wwise_plugin_host_undo_manager_v1;

		/// \copydoc ak_wwise_plugin_host_undo_manager_v1
		class UndoManager : public CBaseInstanceGlue<CHostUndoManager>
		{
		public:
			using Interface = CHostUndoManager;

			/**
			 * \brief The interface type, as requested by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as requested by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_UNDO_MANAGER
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
			 * \brief Open a group that will contain all subsequent undo events.
			 * 
			 * This must be done prior to performing any action on PropertySets, or adding custom events, as it is important to
			 * have one unique element on the undo stack. You can open multiple groups at once, like a stack, as long as you
			 * close them before exiting your function.
			 * 
			 * in_reopenGroupId should be set to 0 for a new group.
			 * 
			 * Example:
			 * <code>
			 * ak_wwise_plugin_undo_group_id m_dragAndDropGroupId = 0;
			 * m_dragAndDropGroupId = OpenGroup(this, m_dragAndDropGroupId);
			 * if (m_dragAndDropGroupId == 0) return;
			 * CloseGroup(this,
			 *            m_done ? AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY :
			 *                     AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_CLOSE,
			 *            "Drag and drop");
			 * if (m_done) m_dragAndDropGroupId = 0;
			 * </code>
			 * 
			 * \param[in] in_reopenGroupId Previously opened undo group, or 0 for a new group.
			 * \return The new undo group that just got created, or 0 if the system cannot open a group at the moment.
			 */
			inline ak_wwise_plugin_undo_group_id OpenGroup(ak_wwise_plugin_undo_group_id in_reopenGroupId = 0)
			{
				return g_cinterface->OpenGroup(this, in_reopenGroupId);
			}

			/**
			 * \brief Closes the last opened group, in stack ordering.
			 * 
			 * Close the current group (_CLOSE) and add its content as a unique entry to the previous group,
			 * or to the Undo stack (_APPLY), or cancel its contents (_CANCEL).
			 * 
			 * in_szApplyEventName is only used for _APPLY. It is ignored elsewhere, and needs to be nullptr on
			 * _APPLY_FIRST_EVENT_NAME or _APPLY_LAST_EVENT_NAME.
			 * 
			 * in_groupId is only for validation, you can pass 0 if you do not wish to provide this validation.
			 * 
			 * \akwarning Cancelling contents doesn't undo all the grouped actions. You are responsible for doing all the proper
			 *            undoing before closing the group. \akwarning
			 * 
			 * \param[in] in_action Action to perform when closing the group. Should usually
			 *            be AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY. 
			 * \param[in] in_groupId (Optional, pass 0) Validation to make sure the group being closed has the proper ID.
			 * \param[in] in_szApplyEventName Event name. Added after "Undo " and "Redo " in the menu.
			 * \return true if successful and necessary (contains real changes).
			 */
			inline bool CloseGroup(
				ak_wwise_plugin_undo_group_close_action in_action = AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY,
				ak_wwise_plugin_undo_group_id in_groupId = 0,
				const char * in_szApplyEventName = nullptr)
			{
				return MKBOOL(g_cinterface->CloseGroup(this, in_action, in_groupId, in_szApplyEventName));
			}

			/**
			 * \brief Adds a custom event to the currently opened group.
			 * 
			 * By default, you should be in a group while adding an event.
			 * 
			 * \param[in] in_pEvent Event to add to the current group.
			 * \return true if successful.
			 */
			inline bool AddCustomEvent(BaseUndoEvent* in_pEvent)
			{
				return MKBOOL(g_cinterface->AddCustomEvent(
					this,
					{in_pEvent->GetInterfacePointer(), in_pEvent->GetInstancePointer() }));
			}

			/**
			 * \brief Check if we are currently in a state where we can add undo events.
			 * 
			 * This is different than not being in a group. You should always be in a group when you want to add an event.
			 * 
			 * \return true if we can add an event.
			 */
			inline bool CanAddEvent() const
			{
				return MKBOOL(g_cinterface->CanAddEvent(this));
			}

			/**
			 * \brief Check if we are busy (undoing or redoing).
			 * 
			 * \return true if we are currently performing an undo operation.
			 */
			inline bool IsBusy() const
			{
				return MKBOOL(g_cinterface->IsBusy(this));
			}

			/**
			 * \brief Returns whether logging can occur or not.
			 * 
			 * Call this function when you are about to log an undo event to know if Wwise is in a state
			 * where undos are enabled. Undo logging can be disabled for a particular plug-in object if
			 * it already lives in the undo stack or in the clipboard.
			 * 
			 * This function is useful to determine whether a complex undo operation can be started without opening a
			 * new undo group (see \ref ak_wwise_plugin_host_undo_manager_v1::OpenGroup). Otherwise, the simple fact of
			 * opening an undo group will give a result of 0 if it's not possible to log undos at this time.
			 * 
			 * \return true if the plug-in can log undo events at this time.
			 */
			inline bool CanLogUndos() const { return g_cinterface->CanLogUndos(this) ? true : false; }
		};

		/**
		 * \brief Requests an UndoManager interface, provided as m_undoManager variable.
		 * 
		 * Deriving your plug-in class from RequestUndoManager will automatically request the UndoManager
		 * interface. From this point, you will be able to access the host-provided functions in the
		 * \c m_undoManager variable.
		 */
		using RequestUndoManager = RequestedHostInterface<UndoManager>;

	} // of namespace V1

	/// Latest version of the C UndoEvent interface.
	using CUndoEvent = V1::CUndoEvent;
	/// Latest version of the C++ BaseUndoEvent interface.
	using BaseUndoEvent = V1::BaseUndoEvent;

	/// Latest version of the C++ UndoEvent template helper.
	template<typename Backend>
	using UndoEvent = V1::UndoEvent<Backend>;
	/// Latest version of the C++ DynamicUndoEvent template helper.
	template<typename BackendDerivedClass>
	using DynamicUndoEvent = V1::DynamicUndoEvent<BackendDerivedClass>;

	/// Latest version of the C UndoManager interface.
	using CHostUndoManager = V1::CHostUndoManager;
	/// Latest version of the C++ UndoManager interface.
	using UndoManager = V1::UndoManager;
	/// Latest version of the requested C++ UndoManager interface.
	using RequestUndoManager = V1::RequestUndoManager;

	AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE(UndoManager, undoManager);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(BaseUndoEvent);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(UndoManager);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(BaseUndoEvent);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(UndoManager);

	class AutoUndoGroup final
	{
	public:
		AutoUndoGroup(
			UndoManager& in_undoManager,
			const char* in_applyEventName = nullptr,
			ak_wwise_plugin_undo_group_id* in_reopenGroupId = nullptr,
			ak_wwise_plugin_undo_group_close_action in_closeAction = AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY)
			: m_undoManager(in_undoManager)
			, m_applyEventName(nullptr)
			, m_groupId(0)
			, m_reopenGroupId(in_reopenGroupId ? in_reopenGroupId : &m_groupId)
			, m_closeAction(in_closeAction)
		{
			if (in_applyEventName)
			{
				m_applyEventName = new char[strlen(in_applyEventName)+1];
				strcpy(m_applyEventName, in_applyEventName);
			}
			if (m_undoManager.CanAddEvent())
			{
				*m_reopenGroupId = m_undoManager.OpenGroup(*m_reopenGroupId);
				m_valid = m_reopenGroupId != 0;
				AKASSERT(m_valid);
			}
			else
			{
				m_valid = false;
			}
		}

		~AutoUndoGroup()
		{
			if (m_valid)
			{
				m_undoManager.CloseGroup(m_closeAction, *m_reopenGroupId, m_applyEventName);
				switch (m_closeAction)
				{
				case AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY:
				case AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY_FIRST_EVENT_NAME:
				case AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY_LAST_EVENT_NAME:
				case AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_CANCEL:
					*m_reopenGroupId = 0;
					break;
				case AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_CLOSE:
				default:
					;
				}
			}
			delete[] m_applyEventName;
		}

		// Cancel the group once the class is destroyed.
		void Cancel()
		{
			m_closeAction = AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_CANCEL;
		}

		// Do not apply the group to the parent once it is closed.
		void DontApply()
		{
			m_closeAction = AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_CLOSE;
		}
		
		bool IsValid()
		{
			return m_valid;
		}

		UndoManager& m_undoManager;

		char* m_applyEventName;

		ak_wwise_plugin_undo_group_id m_groupId;
		ak_wwise_plugin_undo_group_id* m_reopenGroupId;

		ak_wwise_plugin_undo_group_close_action m_closeAction;
		bool m_valid;
	};
} // of namespace AK::Wwise::Plugin

#endif
