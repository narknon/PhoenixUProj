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
 * \brief Wwise Authoring Plug-ins - Windows frontend plug-in API for Audio plug-ins.
 * \file AK/Wwise/Plugin/GUIWindows.h
 */

#pragma once

#include "AudioPlugin.h"

#if defined(AK_WIN) || defined(DOXYGEN_INCLUDE)

// Acquire the module instance from the Microsoft linker
extern "C" IMAGE_DOS_HEADER __ImageBase;

/**
 * \brief Starts a new property-control bindings table.
 * 
 * Starts the declaration of a new property-control bindings table, used in controls such as checkboxes and
 * radio buttons. These can be bound to properties of your plug-in by using AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM().
 * 
 * \param theName The name of the populate table. It must be unique within the current scope.
 * 
 * \sa
 * - \ref wwiseplugin_dialog_guide_poptable
 * - AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM()
 * - AK_WWISE_PLUGIN_GUI_WINDOWS_END_POPULATE_TABLE()
 */
#define AK_WWISE_PLUGIN_GUI_WINDOWS_BEGIN_POPULATE_TABLE(theName) AK::Wwise::Plugin::PopulateTableItem theName[] = {

/**
 * \brief Declares an association between a control and a property within a property-control bindings table.
 * 
 * \param theID The resource ID of the control (checkbox or radio button)
 * \param theProp The name of the property, as defined in your plug-in's
 *        XML definition file (refer to \ref wwiseplugin_xml_properties_tag)
 * \sa
 * - \ref wwiseplugin_dialog_guide_poptable
 * - \ref wwiseplugin_xml_properties_tag
 * - AK_WWISE_PLUGIN_GUI_WINDOWS_BEGIN_POPULATE_TABLE()
 * - AK_WWISE_PLUGIN_GUI_WINDOWS_END_POPULATE_TABLE()
 */
#define AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM(theID, theProp) {theID, theProp },

/**
 * \brief Ends the declaration of a property-control bindings table.
 * 
 * \sa
 * - \ref wwiseplugin_dialog_guide_poptable
 * - AK_WWISE_PLUGIN_GUI_WINDOWS_BEGIN_POPULATE_TABLE()
 * - AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM()
 */
#define AK_WWISE_PLUGIN_GUI_WINDOWS_END_POPULATE_TABLE() AK_WWISE_PLUGIN_GUI_WINDOWS_POP_ITEM(0, NULL) };

/**
 * \brief Windows frontend plug-in API for Audio plug-ins.
 * 
 * You must create this interface in order to support the GUI part of the user interface.
 * 
 * \sa
 * - \ref plugin_frontend_windows
 */
struct ak_wwise_plugin_gui_windows_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for providing a Windows frontend for an audio plug-in.
	using Instance = ak_wwise_plugin_gui_windows_instance_v1;

	ak_wwise_plugin_gui_windows_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_GUI_WINDOWS, 1)
	{}
#endif

	/**
	 * \brief Retrieves the plug-in's HINSTANCE used for loading resources.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return A handle to the instance of the plug-in DLL
	 * \sa
	 * - \ref wwiseplugin_dialogcode
	 */
	HINSTANCE(*GetResourceHandle)(const struct ak_wwise_plugin_gui_windows_instance_v1* in_this);

	/**
	 * \brief Retrieves the plug-in dialog parameters.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_eDialog The dialog type.
	 * \param[out] out_uiDialogID The returned resource ID of the dialog
	 * \param[out] out_pTable The returned table of property-control bindings (can be nullptr if no properties are to be bound).
	 * \return true if a dialog was returned, false otherwise.
	 * 
	 * \sa
	 * - \ref wwiseplugin_dialogcode
	 * - \ref wwiseplugin_dialog_guide
	 */
	bool(*GetDialog)(
		const struct ak_wwise_plugin_gui_windows_instance_v1* in_this,
		AK::Wwise::Plugin::eDialog in_eDialog,
		uint32_t* out_uiDialogID,
		AK::Wwise::Plugin::PopulateTableItem ** out_pTable
	);

	/**
	 * \brief Window message handler for dialogs.
	 * 
	 * This is very similar to a standard WIN32 window procedure.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_eDialog The dialog type.
	 * \param[in] in_hWnd The window handle of the dialog.
	 * \param[in] in_message The incoming message. This is a standard Windows message ID (ex. WM_PAINT).
	 * \param[in] in_wParam The WPARAM of the message (see MSDN).
	 * \param[in] in_lParam The LPARAM of the message (see MSDN).
	 * \param[out] out_lResult The returned value if the message has been processed
	 *             (it is only considered if the method also returns true).
	 * \return True if the message has been processed by the plug-in, False otherwise
	 * 
	 * \sa
	 * - \ref wwiseplugin_dialogcode
	 */
	bool(*WindowProc)(
		struct ak_wwise_plugin_gui_windows_instance_v1* in_this,
		AK::Wwise::Plugin::eDialog in_eDialog,
		HWND in_hWnd,
		uint32_t in_message,
		WPARAM in_wParam,
		LPARAM in_lParam,
		LRESULT* out_lResult
	);

	/**
	 * \brief Called when the user clicks on the '?' icon.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_hWnd The window handle of the dialog.
	 * \param[in] in_eDialog The dialog type.
	 * \param[in] in_szLanguageCode The language code in ISO639-1.
	 * \return true if the plug-in handled the help request, false otherwise
	 * 
	 * \sa
	 * - \ref wwiseplugin_help
	 */
	bool(*Help)(
		const struct ak_wwise_plugin_gui_windows_instance_v1* in_this,
		HWND in_hWnd,
		AK::Wwise::Plugin::eDialog in_eDialog,
		const char * in_szLanguageCode
	);
};
#define AK_WWISE_PLUGIN_GUI_WINDOWS_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_GUI_WINDOWS, 1)
#define AK_WWISE_PLUGIN_GUI_WINDOWS_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_GUI_WINDOWS_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CGUIWindows = ak_wwise_plugin_gui_windows_v1;
		
		/// \copydoc ak_wwise_plugin_gui_windows_v1
		class GUIWindows : public CGUIWindows::Instance
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
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_GUI_WINDOWS
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
			struct Interface : public CGUIWindows
			{
				using Instance = GUIWindows;
				Interface()
				{
					CGUIWindows::GetResourceHandle = [](const struct ak_wwise_plugin_gui_windows_instance_v1* in_this) { return (HINSTANCE)static_cast<const Instance*>(in_this)->GetResourceHandle(); };
					CGUIWindows::GetDialog = [](const struct ak_wwise_plugin_gui_windows_instance_v1* in_this, eDialog in_eDialog, uint32_t* out_uiDialogID, PopulateTableItem ** out_pTable) { return (bool)static_cast<const Instance*>(in_this)->GetDialog(in_eDialog, *out_uiDialogID, *out_pTable); };
					CGUIWindows::WindowProc = [](struct ak_wwise_plugin_gui_windows_instance_v1* in_this, eDialog in_eDialog, HWND in_hWnd, uint32_t in_message, WPARAM in_wParam, LPARAM in_lParam, LRESULT* out_lResult) { return (bool)static_cast<Instance*>(in_this)->WindowProc(in_eDialog, in_hWnd, in_message, in_wParam, in_lParam, *out_lResult); };
					CGUIWindows::Help = [](const struct ak_wwise_plugin_gui_windows_instance_v1* in_this, HWND in_hWnd, eDialog in_eDialog, const char * in_szLanguageCode) { return (bool)static_cast<const Instance*>(in_this)->Help(in_hWnd, in_eDialog, in_szLanguageCode); };
				}
			};

			InterfacePtr GetInterfacePointer() {
				static Interface g_interface;
				return &g_interface;
			}
			CGUIWindows::Instance* GetInstancePointer() {
				return this;
			}
			const CGUIWindows::Instance* GetInstancePointer() const {
				return this;
			}

			GUIWindows() :
				CGUIWindows::Instance()
			{
			}

			virtual ~GUIWindows() {}

			/**
			 * \brief Retrieves the plug-in's HINSTANCE used for loading resources.
			 * 
			 * \return A handle to the instance of the plug-in DLL
			 * \sa
			 * - \ref wwiseplugin_dialogcode
			 */
			virtual HINSTANCE GetResourceHandle() const {
				return ((HINSTANCE)&__ImageBase);
			}

			/**
			 * \brief Retrieves the plug-in dialog parameters.
			 * 
			 * \param[in] in_eDialog The dialog type.
			 * \param[out] out_uiDialogID The returned resource ID of the dialog
			 * \param[out] out_pTable The returned table of property-control bindings (can be nullptr if no properties are to be bound).
			 * \return True if out_uiDialogID was set. If nothing was set and true is returned, an empty dialog will be created
			 *         (non-MFC code will then have a window handle to hook to). False otherwise (no frontend).
			 * 
			 * \sa
			 * - \ref wwiseplugin_dialogcode
			 * - \ref wwiseplugin_dialog_guide
			 */
			virtual bool GetDialog(
				eDialog in_eDialog,
				uint32_t & out_uiDialogID,
				PopulateTableItem *& out_pTable
			) const { return false; }

			/**
			 * \brief Window message handler for dialogs.
			 * 
			 * This is very similar to a standard WIN32 window procedure.
			 * 
			 * \param[in] in_eDialog The dialog type.
			 * \param[in] in_hWnd The window handle of the dialog.
			 * \param[in] in_message The incoming message. This is a standard Windows message ID (ex. WM_PAINT).
			 * \param[in] in_wParam The WPARAM of the message (see MSDN).
			 * \param[in] in_lParam The LPARAM of the message (see MSDN).
			 * \param[out] out_lResult The returned value if the message has been processed
			 *             (it is only considered if the method also returns true).
			 * \return True if the message has been processed by the plug-in, False otherwise
			 * 
			 * \sa
			 * - \ref wwiseplugin_dialogcode
			 */
			virtual bool WindowProc(
				eDialog in_eDialog,
				HWND in_hWnd,
				uint32_t in_message,
				WPARAM in_wParam,
				LPARAM in_lParam,
				LRESULT& out_lResult
			) { return false; }

			/**
			 * \brief Called when the user clicks on the '?' icon.
			 * 
			 * \param[in] in_hWnd The window handle of the dialog.
			 * \param[in] in_eDialog The dialog type.
			 * \param[in] in_szLanguageCode The language code in ISO639-1.
			 * \return true if the plug-in handled the help request, false otherwise
			 * 
			 * \sa
			 * - \ref wwiseplugin_help
			 */
			virtual bool Help(
				HWND in_hWnd,
				eDialog in_eDialog,
				const char * in_szLanguageCode
			) const { return false; }
		};
	} // of namespace V1

	/// Latest version of the C GUIWindows interface.
	using CGUIWindows = V1::CGUIWindows;
	/// Latest version of the C++ GUIWindows interface.
	using GUIWindows = V1::GUIWindows;

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(GUIWindows);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(GUIWindows);
} // of namespace AK::Wwise::Plugin
#endif // of __cplusplus

#ifndef WM_AK_PRIVATE_SHOW_HELP_TOPIC
#define WM_AK_PRIVATE_SHOW_HELP_TOPIC 0x4981
#endif

#endif // of AK_WIN