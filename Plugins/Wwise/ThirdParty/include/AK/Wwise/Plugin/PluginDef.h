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
 * \brief Wwise Authoring Plug-ins - Base plug-in definitions
 * \file AK/Wwise/Plugin/PluginDef.h
 */

#pragma once

#include "PluginHelpers.h"

// Everthing in this section needs:
// - to be converted back to plain vanilla C
// - create optional interfaces for classes
// - create compulsory convertion functions for enums
#ifdef __cplusplus
#include "../../SoundEngine/Common/IAkPlugin.h"

namespace AK
{
	namespace WwiseAuthoringAPI
	{
		class AkVariantBase;
	}
}

namespace AK
{
	namespace Wwise
	{
		namespace Plugin
		{
			/// License type.
			enum LicenseType
			{
				LicenseType_Trial = 1,		///< Used for both Trial and Evaluation License handling
				LicenseType_Purchased,		///< The license was purchased
				LicenseType_Academic		///< The license is for academic
			};

			/// License status.
			enum LicenseStatus
			{
				LicenseStatus_Unlicensed,	///< No license found
				LicenseStatus_Expired,		///< A license is found, but is expired
				LicenseStatus_Valid,		///< A license is found and is valid

				LicenseStatus_Incompatible	///< The plugin was made for an older version of Wwise
			};

			/// Type of operation for the NotifyInnerObjectAddedRemoved function.
			enum NotifyInnerObjectOperation
			{
				InnerObjectAdded,
				InnerObjectRemoved
			};

			struct MonitorData
			{
				uint64_t uGameObjectID;
				void* pData;
				unsigned int uDataSize;
			};

			/// Import channel configuration options.
			enum AudioFileChannel
			{
				Channel_mono = 0,
				Channel_stereo = 1,
				Channel_mono_drop = 2,
				Channel_stereo_drop = 3,
				Channel_as_input = 4,
				Channel_mono_drop_right = 5,
				Channel_stereo_balance = 6,
			};

			/// Log message severity.
			enum Severity
			{
				Severity_Success = -1,	///< operation was executed without errors or will not produce errors
				Severity_Message,		///< not impacting the integrity of the current operation
				Severity_Warning,		///< potentially impacting the integrity of the current operation
				Severity_Error,			///< impacting the integrity of the current operation
				Severity_FatalError,	///< impacting the completion of the current operation
			};

			/// Represents the association between a dialog control (such as
			/// a checkbox or radio button) and a plug-in property.
			/// \aknote
			/// You should not need to use this structure directly. Instead, use the 
			/// AK_BEGIN_POPULATE_TABLE(), AK_POP_ITEM(), and AK_END_POPULATE_TABLE() macros.
			/// \endaknote
			/// \sa
			/// - \ref wwiseplugin_dialog_guide_poptable
			struct PopulateTableItem
			{
				uint32_t uiID;				///< The dialog control resource ID
				const char * pszProp;		///< The property name
			};

			/// Dialog type. Source plug-ins can be edited in the Property Editor or
			/// the Contents Editor, while effect plug-ins can only be edited in the
			/// Effect Editor.
			/// \sa
			/// - \ref wwiseplugin_dialogcode
			enum eDialog
			{
				SettingsDialog,			///< Main plug-in dialog. This is the dialog used in the Property
										///< Editor for source plug-ins, and in the Effect Editor for
										///< effect plug-ins.
				ContentsEditorDialog	///< Contents Editor dialog. This is the small dialog used in the
										///< Contents Editor for source plug-ins.
			};

			/// Conversion error code.
			enum ConversionResult
			{
				ConversionSuccess = 0,
				ConversionWarning = 1,
				ConversionFailed = 2,
			};

			class IProgress
			{
			public:
				/// Call this to set the name of the operation currently done.
				/// If not called the operation will have an empty name in the UI.
				/// The name should be on a single line.
				virtual void SetCurrentOperationName(const char * in_szOperationName) = 0;

				/// Should be called at the beginning of the operation to set the min and max value 
				virtual void SetRange(uint32_t in_dwMinValue, uint32_t in_dwMaxValue) = 0;

				/// Notify of the advancement of the task.
				virtual void NotifyProgress(uint32_t in_dwProgress) = 0;

				/// Check if the user has cancelled the task
				virtual bool IsCancelled() = 0;

				/// Display an error message to the user.
				/// The message should be on a single line.
				virtual void ErrorMessage(const char * in_rErrorText, Severity in_eSeverity = Severity_Warning) = 0;
			};

			/// Interface to let the plug in give us a string of any size.
			/// The pointer to the interface should not be kept.
			class IWriteString
			{
			public:
				virtual void WriteString(const char * in_szString,
					int in_iStringLength) = 0;
			};

			/// Interfaces used to set and get the properties from a plug in.
			class IReadOnlyProperties
			{
			public:
				virtual bool GetValue(const char * in_szPropertyName,
					AK::WwiseAuthoringAPI::AkVariantBase& out_rValue) const = 0;

				virtual int GetType(
					const char* in_pszPropertyName		///< The name of the property
				) const = 0;

				virtual bool GetValueString(
					const char * in_pszPropertyName,		///< The name of the property
					const char*& out_varProperty		///< The returned value of the property
				) const = 0;

				virtual bool GetValueInt64(
					const char * in_pszPropertyName,		///< The name of the property
					int64_t& out_varProperty		///< The returned value of the property
				) const = 0;

				virtual bool GetValueInt32(
					const char * in_pszPropertyName,		///< The name of the property
					int32_t& out_varProperty		///< The returned value of the property
				) const = 0;

				virtual bool GetValueInt16(
					const char * in_pszPropertyName,		///< The name of the property
					int16_t& out_varProperty		///< The returned value of the property
				) const = 0;

				virtual bool GetValueInt8(
					const char * in_pszPropertyName,		///< The name of the property
					int8_t& out_varProperty		///< The returned value of the property
				) const = 0;

				virtual bool GetValueUInt64(
					const char * in_pszPropertyName,		///< The name of the property
					uint64_t& out_varProperty		///< The returned value of the property
				) const = 0;

				virtual bool GetValueUInt32(
					const char * in_pszPropertyName,		///< The name of the property
					uint32_t& out_varProperty		///< The returned value of the property
				) const = 0;

				virtual bool GetValueUInt16(
					const char * in_pszPropertyName,		///< The name of the property
					uint16_t& out_varProperty		///< The returned value of the property
				) const = 0;

				virtual bool GetValueUInt8(
					const char * in_pszPropertyName,		///< The name of the property
					uint8_t& out_varProperty		///< The returned value of the property
				) const = 0;

				virtual bool GetValueReal64(
					const char * in_pszPropertyName,		///< The name of the property
					double& out_varProperty		///< The returned value of the property
				) const = 0;

				virtual bool GetValueReal32(
					const char * in_pszPropertyName,		///< The name of the property
					float& out_varProperty		///< The returned value of the property
				) const = 0;

				virtual bool GetValueBool(
					const char * in_pszPropertyName,		///< The name of the property
					bool& out_varProperty		///< The returned value of the property
				) const = 0;

				inline const char* GetString(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					const char* result;
					AKVERIFY(GetValueString(in_pszPropertyName, result));
					return result;
				}

				inline int64_t GetInt64(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					int64_t result;
					AKVERIFY(GetValueInt64(in_pszPropertyName, result));
					return result;
				}

				inline int32_t GetInt32(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					int32_t result;
					AKVERIFY(GetValueInt32(in_pszPropertyName, result));
					return result;
				}

				inline int16_t GetInt16(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					int16_t result;
					AKVERIFY(GetValueInt16(in_pszPropertyName, result));
					return result;
				}

				inline int8_t GetInt8(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					int8_t result;
					AKVERIFY(GetValueInt8(in_pszPropertyName, result));
					return result;
				}

				inline uint64_t GetUInt64(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					uint64_t result;
					AKVERIFY(GetValueUInt64(in_pszPropertyName, result));
					return result;
				}

				inline uint32_t GetUInt32(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					uint32_t result;
					AKVERIFY(GetValueUInt32(in_pszPropertyName, result));
					return result;
				}

				inline uint16_t GetUInt16(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					uint16_t result;
					AKVERIFY(GetValueUInt16(in_pszPropertyName, result));
					return result;
				}

				inline uint8_t GetUInt8(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					uint8_t result;
					AKVERIFY(GetValueUInt8(in_pszPropertyName, result));
					return result;
				}

				inline double GetReal64(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					double result;
					AKVERIFY(GetValueReal64(in_pszPropertyName, result));
					return result;
				}

				inline float GetReal32(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					float result;
					AKVERIFY(GetValueReal32(in_pszPropertyName, result));
					return result;
				}

				inline bool GetBool(
					const char * in_pszPropertyName		///< The name of the property
				) const
				{
					bool result;
					AKVERIFY(GetValueBool(in_pszPropertyName, result));
					return result;
				}
			};

			class IReadWriteProperties : public IReadOnlyProperties
			{
			public:
				virtual bool SetValue(const char * in_szPropertyName,
					const AK::WwiseAuthoringAPI::AkVariantBase& in_rValue) = 0;

				virtual bool ClearValue(
					const char* in_pszPropertyName		///< The name of the property
				) = 0;

				virtual bool SetValueString(
					const char * in_pszPropertyName,		///< The name of the property
					const char * in_varProperty	///< The value to set
				) = 0;

				virtual bool SetValueInt64(
					const char * in_pszPropertyName,		///< The name of the property
					int64_t in_varProperty	///< The value to set
				) = 0;

				virtual bool SetValueInt32(
					const char * in_pszPropertyName,		///< The name of the property
					int32_t in_varProperty	///< The value to set
				) = 0;

				virtual bool SetValueInt16(
					const char * in_pszPropertyName,		///< The name of the property
					int16_t in_varProperty	///< The value to set
				) = 0;

				virtual bool SetValueInt8(
					const char * in_pszPropertyName,		///< The name of the property
					int8_t in_varProperty	///< The value to set
				) = 0;

				virtual bool SetValueUInt64(
					const char * in_pszPropertyName,		///< The name of the property
					uint64_t in_varProperty	///< The value to set
				) = 0;

				virtual bool SetValueUInt32(
					const char * in_pszPropertyName,		///< The name of the property
					uint32_t in_varProperty	///< The value to set
				) = 0;

				virtual bool SetValueUInt16(
					const char * in_pszPropertyName,		///< The name of the property
					uint16_t in_varProperty	///< The value to set
				) = 0;

				virtual bool SetValueUInt8(
					const char * in_pszPropertyName,		///< The name of the property
					uint8_t in_varProperty	///< The value to set
				) = 0;

				virtual bool SetValueReal64(
					const char * in_pszPropertyName,		///< The name of the property
					double in_varProperty	///< The value to set
				) = 0;

				virtual bool SetValueReal32(
					const char * in_pszPropertyName,		///< The name of the property
					float in_varProperty	///< The value to set
				) = 0;

				virtual bool SetValueBool(
					const char * in_pszPropertyName,		///< The name of the property
					bool in_varProperty	///< The value to set
				) = 0;
			};

			// Note: This should be kept in line with RIFFHEADER
			struct RiffHeader
			{
				uint32_t fccChunkId;
				uint32_t dwDataSize;
			};
			
			struct ConversionContext
			{
				//
				// Inputs
				//
				const GUID* platformID;
				const GUID* basePlatformID;
				const char* sourceFileName;
				const char* destinationFileName;
				AK::Wwise::Plugin::IProgress* progress;
				AK::Wwise::Plugin::IWriteString* error;

				bool noDecode;

				const IReadOnlyProperties* sourceProperties;
				IReadWriteProperties* pluginProperties;

				// Analysis data types available for this source.
				uint32_t analysisDataTypes;

				// False if source context contains at least one value that is not the default.
				bool isDefault;

				// Required downmix normalization gain (linear), 1 if not available / desired.
				float downmixNormalizationGain;

				//
				// Outputs
				//
				uint32_t sampleRate;			///< Number of samples per second
				AkChannelConfig channelConfig;	///< Channel configuration
				uint32_t decodedFileSize;		///< File size of file when decoded to PCM format, *If* offline decoding is supported by the codec.  Otherwise has value NO_OFFLINE_DECODING (-1)
			};

			struct OpenedConvertedFile
			{
				const void* data;
				uint32_t dataSize;
				uint32_t duration;				///< Actual duration of data, or -1 for entire file.
			};
		}
	}
}
#endif

/** \addtogroup global
 * @{
 */

struct ak_wwise_plugin_base_interface;
typedef struct ak_wwise_plugin_base_interface* ak_wwise_plugin_interface_ptr;											///< Pointer to a generic base from a plug-in interface.

/**
 * \brief Generic base for all plug-in instances. In C++, this is derived. In C, they are equivalent.
 * 
 * \sa
 * - \ref ak_wwise_plugin_cpp_base_instance for disrepancies between the C and C++ model.
 */
struct ak_wwise_plugin_base_instance {};
typedef struct ak_wwise_plugin_base_instance* ak_wwise_plugin_instance_ptr;												///< Pointer to a generic base for a plug-in instances.

struct ak_wwise_plugin_interface_array_item;
struct ak_wwise_plugin_info;
struct ak_wwise_plugin_container;

#ifdef __cplusplus
/**
 * \brief Generic base for all plug-in instances in C++
 * 
 * \warning This differs from the ak_wwise_plugin_base_instance, as C++ classes have a virtual table as their first member.
 * It's important to make the distinction between the two by specifically doing a static_cast between the C version and the C++ version,
 * and not a mere reinterpret_cast or a C-style cast. As such, it is expected to instantiate a plug-in in C++, and return
 * C pointers back to the instance structures with a different base address.
 */
struct ak_wwise_plugin_cpp_base_instance : public ak_wwise_plugin_base_instance
{
	virtual ~ak_wwise_plugin_cpp_base_instance() {}
};

/**
 * \brief Define a generic instance base, either in C or in C++.
 * 
 * \warning These are NOT equivalent! In C, it is expected you can directly cast from your instance to an
 * ak_wwise_plugin_base_instance. In C++, since the base classes have a virtual table, the pointer to the C members is
 * shifted in memory.
 */
#define AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE : public ak_wwise_plugin_cpp_base_instance
#else
#define AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE
#endif

/**
 * \brief Plug-in backend instance.
 * 
 * A backend contains all the logic for the Authoring part of the plug-in. It is uniquely instantiated for each plug-in instance
 * in a project.
 */
struct ak_wwise_plugin_backend_instance AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

/**
 * \brief Plug-in frontend instance.
 * 
 * A frontend contains the visual part of the Authoring plug-in. It is optional, for example, it is never instantiated when
 * connecting through WwiseConsole. As such, there should never be any processing or "intelligence" done in a frontend part.
 * 
 * For example, the frontend should not affect licensing, soundbank generation, audio processing, property handling (such as
 * validating ranges for property sets), media handling, media conversion, custom data loading, ...
 * 
 * \aknote Porting note: In legacy plug-ins, there is only one instance of the Authoring plug-in that contains both
 * the backend and the frontend. This has changed for multiple reasons: to be able to instantiate a plug-in backend without any
 * frontend, or alternatively, to instantiate multiple copies of a frontend for a unique backend. \endaknote
 */
struct ak_wwise_plugin_frontend_instance AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

#ifdef __cplusplus
/**
 * \brief Define an instance type as a backend.
 * 
 * In C++, this derives the backend instance from the ak_wwise_plugin_backend_instance in a separate action so that RTTI can help
 * pinpoint the types and the compiler ensures the type correctness.
 * 
 * In C, this is a typedef, as we cannot derive. The compiler also doesn't need to lookup addresses for complex structures, so this
 * is merely an equivalency.
 * 
 * \sa
 * - \ref ak_wwise_plugin_backend_instance for a backend discussion.
 * - \ref ak_wwise_plugin_frontend_instance for a frontend discussion.
 * - \ref ak_wwise_plugin_cpp_base_instance for disrepancies between the C and C++ model.
 */
#define AK_WWISE_PLUGIN_DERIVE_FROM_BACKEND_INSTANCE(x) \
	struct x : public ak_wwise_plugin_backend_instance {}

/**
 * \brief Define an instance type as a frontend.
 * 
 * In C++, this derives the frontend instance from the ak_wwise_plugin_frontend_instance in a separate action so that RTTI can help
 * pinpoint the types and the compiler ensures the type correctness.
 * 
 * In C, this is a typedef, as we cannot derive. The compiler also doesn't need to lookup addresses for complex structures, so this
 * is merely an equivalency.
 * 
 * \sa
 * - \ref ak_wwise_plugin_backend_instance for a backend discussion.
 * - \ref ak_wwise_plugin_frontend_instance for a frontend discussion.
 * - \ref ak_wwise_plugin_cpp_base_instance for disrepancies between the C and C++ model.
 */
#define AK_WWISE_PLUGIN_DERIVE_FROM_FRONTEND_INSTANCE(x) \
	struct x : public ak_wwise_plugin_frontend_instance {}
#else
#define AK_WWISE_PLUGIN_DERIVE_FROM_BACKEND_INSTANCE(x) \
	typedef x ak_wwise_plugin_backend_instance
#define AK_WWISE_PLUGIN_DERIVE_FROM_FRONTEND_INSTANCE(x) \
	typedef x ak_wwise_plugin_frontend_instance
#endif

/**
 * \brief Base host-provided instance type for ak_wwise_plugin_host_v1.
 * 
 * \sa
 * - ak_wwise_plugin_host_v1 C interface.
 * - AK::Wwise::Plugin::V1::Host C++ class.
 */
struct ak_wwise_plugin_host_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

/**
 * \brief Base host-provided instance type for ak_wwise_plugin_host_conversion_helpers_v1.
 * 
 * \sa
 * - ak_wwise_plugin_host_conversion_helpers_v1 C interface.
 * - AK::Wwise::Plugin::V1::ConversionHelpers C++ class.
 */
struct ak_wwise_plugin_host_conversion_helpers_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

/**
 * \brief Base host-provided instance type for ak_wwise_plugin_host_data_writer_v1.
 * 
 * \sa
 * - ak_wwise_plugin_host_data_writer_v1 C interface.
 * - AK::Wwise::Plugin::V1::DataWriter C++ class.
 */
struct ak_wwise_plugin_host_data_writer_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

/**
 * \brief Base host-provided instance type for ak_wwise_plugin_host_object_media_v1.
 * 
 * \sa
 * - ak_wwise_plugin_host_object_media_v1 C interface.
 * - AK::Wwise::Plugin::V1::ObjectMedia C++ class.
 */
struct ak_wwise_plugin_host_object_media_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

/**
 * \brief Base host-provided instance type for ak_wwise_plugin_host_object_store_v1.
 * 
 * \sa
 * - ak_wwise_plugin_host_object_store_v1 C interface.
 * - AK::Wwise::Plugin::V1::ObjectStore C++ class.
 */
struct ak_wwise_plugin_host_object_store_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

/**
 * \brief Base host-provided instance type for ak_wwise_plugin_host_property_set_v1.
 * 
 * \sa
 * - ak_wwise_plugin_host_property_set_v1 C interface.
 * - AK::Wwise::Plugin::V1::PropertySet C++ class.
 */
struct ak_wwise_plugin_host_property_set_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

/**
 * \brief Base host-provided instance type for ak_wwise_plugin_host_undo_manager_v1.
 * 
 * \sa
 * - ak_wwise_plugin_host_undo_manager_v1 C interface.
 * - AK::Wwise::Plugin::V1::UndoManager C++ class.
 */
struct ak_wwise_plugin_host_undo_manager_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

/**
 * \brief Base host-provided instance type for reading XML files through ak_wwise_plugin_host_xml_v1.
 * 
 * \sa
 * - ak_wwise_plugin_host_xml_v1 C interface.
 * - AK::Wwise::Plugin::V1::XmlReader C++ class.
 */
struct ak_wwise_plugin_host_xml_reader_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

/**
 * \brief Base host-provided instance type for writing XML files through ak_wwise_plugin_host_xml_v1.
 * 
 * \sa
 * - ak_wwise_plugin_host_xml_v1 C interface.
 * - AK::Wwise::Plugin::V1::XmlWriter C++ class.
 */
struct ak_wwise_plugin_host_xml_writer_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};


struct ak_wwise_plugin_analysis_task_v1;
/**
 * \brief Base instance type for providing analysis task services through ak_wwise_plugin_analysis_task_v1.
 * 
 * \sa
 * - ak_wwise_plugin_analysis_task_v1 C interface.
 * - AK::Wwise::Plugin::V1::AnalysisTask C++ class.
 */
struct ak_wwise_plugin_analysis_task_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_audio_plugin_v1;
/**
 * \brief Base instance type for providing audio plug-in backend services through ak_wwise_plugin_audio_plugin_v1.
 * 
 * \sa
 * - ak_wwise_plugin_audio_plugin_v1 C interface.
 * - AK::Wwise::Plugin::V1::AudioPlugin C++ class.
 */
AK_WWISE_PLUGIN_DERIVE_FROM_BACKEND_INSTANCE(ak_wwise_plugin_audio_plugin_instance_v1);

struct ak_wwise_plugin_conversion_v1;
/**
 * \brief Base instance type for providing a conversion plug-in through ak_wwise_plugin_conversion_v1.
 * 
 * \sa
 * - ak_wwise_plugin_conversion_v1 C interface.
 * - AK::Wwise::Plugin::V1::Conversion C++ class.
 */
AK_WWISE_PLUGIN_DERIVE_FROM_BACKEND_INSTANCE(ak_wwise_plugin_conversion_instance_v1);

struct ak_wwise_plugin_custom_data_v1;
/**
 * \brief Base instance type for providing custom data loading and saving through ak_wwise_plugin_custom_data_v1.
 * 
 * \sa
 * - ak_wwise_plugin_custom_data_v1 C interface.
 * - AK::Wwise::Plugin::V1::CustomData C++ class.
 */
struct ak_wwise_plugin_custom_data_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_property_display_name_v1;
/**
 * \brief Base instance type for providing display names to properties through ak_wwise_plugin_property_display_name_v1.
 * 
 * \sa
 * - ak_wwise_plugin_property_display_name_v1 C interface.
 * - AK::Wwise::Plugin::V1::PropertyDisplayName C++ class.
 */
struct ak_wwise_plugin_property_display_name_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_feedback_aware_v1;
/**
 * \brief Base instance type for providing property-based feedback through ak_wwise_plugin_feedback_aware_v1.
 * 
 * \sa
 * - ak_wwise_plugin_feedback_aware_v1 C interface.
 * - AK::Wwise::Plugin::V1::FeedbackAware C++ class.
 */
struct ak_wwise_plugin_feedback_aware_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_gui_conversion_windows_v1;
/**
 * \brief Base instance type for providing a Windows frontend for a conversion plug-in through ak_wwise_plugin_gui_conversion_windows_v1.
 * 
 * \sa
 * - ak_wwise_plugin_gui_conversion_windows_v1 C interface.
 * - AK::Wwise::Plugin::V1::GUIConversionWindows C++ class.
 * - ak_wwise_plugin_conversion_v1 Conversion backend's C interface.
 * - AK::Wwise::Plugin::V1::Conversion Conversion frontend's C++ class.
 */
AK_WWISE_PLUGIN_DERIVE_FROM_FRONTEND_INSTANCE(ak_wwise_plugin_gui_conversion_windows_instance_v1);

struct ak_wwise_plugin_gui_windows_v1;
/**
 * \brief Base instance type for providing a Windows frontend for an audio plug-in through ak_wwise_plugin_gui_windows_v1.
 * 
 * \sa
 * - ak_wwise_plugin_gui_windows_v1 C interface.
 * - AK::Wwise::Plugin::V1::GUIWindows C++ class.
 * - ak_wwise_plugin_audio_plugin_v1 Audio plug-in backend's C interface.
 * - AK::Wwise::Plugin::V1::AudioPlugin Audio plug-in frontend's C++ class.
 */
AK_WWISE_PLUGIN_DERIVE_FROM_FRONTEND_INSTANCE(ak_wwise_plugin_gui_windows_instance_v1);

struct ak_wwise_plugin_link_backend_v1;
/**
 * \brief Base host-provided instance to retrieve the related backend instance, as shown in the frontend.
 * 
 * \sa
 * - ak_wwise_plugin_link_backend_v1 C interface.
 * - AK::Wwise::Plugin::V1::LinkBackend C++ class.
 */
struct ak_wwise_plugin_link_backend_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_link_frontend_v1;
/**
 * \brief Base host-provided instance to retrieve the related frontend instances related to the current backend.
 * 
 * \sa
 * - ak_wwise_plugin_link_frontend_v1 C interface.
 * - AK::Wwise::Plugin::V1::LinkFrontend C++ class.
 */
struct ak_wwise_plugin_link_frontend_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_media_converter_v1;
/**
 * \brief Base instance type for providing custom media conversion through ak_wwise_plugin_media_converter_v1.
 * 
 * \sa
 * - ak_wwise_plugin_media_converter_v1 C interface.
 * - AK::Wwise::Plugin::V1::MediaConverter C++ class.
 */
struct ak_wwise_plugin_media_converter_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_notifications_host_v1;
/**
 * \brief Base instance type for receiving notifications on host changes events.
 * 
 * \sa
 * - ak_wwise_plugin_notifications_host_v1 C interface.
 * - AK::Wwise::Plugin::V1::Notifications::Host_ C++ class.
 * - ak_wwise_plugin_host_v1 Related C host interface.
 * - AK::Wwise::Plugin::V1::Host Related C++ host class.
 */
struct ak_wwise_plugin_notifications_host_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_notifications_monitor_v1;
/**
 * \brief Base instance type for receiving Sound Engine's monitoring data.
 * 
 * \sa
 * - ak_wwise_plugin_notifications_monitor_v1 C interface.
 * - AK::Wwise::Plugin::V1::Notifications::Monitor C++ class.
 * - AK::Wwise::Plugin::MonitorData
 */
struct ak_wwise_plugin_notifications_monitor_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_notifications_object_media_v1;
/**
 * \brief Base instance type for receiving notifications on related object media's changes.
 * 
 * \sa
 * - ak_wwise_plugin_notifications_object_media_v1 C interface.
 * - AK::Wwise::Plugin::V1::Notifications::ObjectMedia_ C++ class.
 * - ak_wwise_plugin_host_object_media_v1 Related C host interface.
 * - AK::Wwise::Plugin::V1::ObjectMedia Related C++ host class.
 */
struct ak_wwise_plugin_notifications_object_media_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_notifications_object_store_v1;
/**
 * \brief Base instance type for receiving notifications on related Object Store's changes.
 * 
 * \sa
 * - ak_wwise_plugin_notifications_object_store_v1 C interface.
 * - AK::Wwise::Plugin::V1::Notifications::ObjectStore_ C++ class.
 * - ak_wwise_plugin_host_object_store_v1 Related C host interface.
 * - AK::Wwise::Plugin::V1::ObjectStore Related C++ host class.
 */
struct ak_wwise_plugin_notifications_object_store_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_notifications_property_set_v1;
/**
 * \brief Base instance type for receiving notifications on property set's changes.
 * 
 * \sa
 * - ak_wwise_plugin_notifications_property_set_v1 C interface.
 * - AK::Wwise::Plugin::V1::Notifications::PropertySet_ C++ class.
 * - ak_wwise_plugin_host_property_set_v1 Related C host interface.
 * - AK::Wwise::Plugin::V1::PropertySet Related C++ host class.
 */
struct ak_wwise_plugin_notifications_property_set_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_source_v1;
/**
 * \brief Base instance type for providing source-specific information, through ak_wwise_plugin_source_v1.
 * 
 * \sa
 * - ak_wwise_plugin_source_v1 C interface.
 * - AK::Wwise::Plugin::V1::Source C++ class.
 */
struct ak_wwise_plugin_source_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_undo_event_v1;
/**
 * \brief Base instance type for providing custom undo operations through ak_wwise_plugin_undo_event_v1.
 * 
 * \sa
 * - ak_wwise_plugin_undo_event_v1 C interface.
 * - AK::Wwise::Plugin::V1::UndoEvent C++ class.
 * - ak_wwise_plugin_host_undo_manager_v1 Host's C manager interface.
 * - AK::Wwise::Plugin::V1::UndoManager Host's C++ manager class.
 */
struct ak_wwise_plugin_undo_event_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_license_v1;
/**
 * \brief Base instance type for providing licensing information, through ak_wwise_plugin_license_v1.
 * 
 * \sa
 * - ak_wwise_plugin_license_v1 C interface.
 * - AK::Wwise::Plugin::V1::License C++ class.
 */
struct ak_wwise_plugin_license_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};


/**
 * \brief Base instance type for providing a message shown the first time an instance is created through ak_wwise_plugin_first_time_creation_message_v1.
 * 
 * \sa
 * - ak_wwise_plugin_first_time_creation_message_v1 C interface.
 * - AK::Wwise::Plugin::V1::FirstTimeCreationMessage C++ class.
 */
struct ak_wwise_plugin_first_time_creation_message_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

/**
 * \brief Base instance type for providing a device list for your custom sink through ak_wwise_plugin_sink_devices_v1.
 * 
 * \sa
 * - ak_wwise_plugin_sink_devices_v1 C interface.
 * - AK::Wwise::Plugin::V1::SinkDevices C++ class.
 */
struct ak_wwise_plugin_sink_devices_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

struct ak_wwise_plugin_test_service_instance_v1 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};
struct ak_wwise_plugin_test_service_instance_v2 AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE {};

#undef AK_WWISE_PLUGIN_DERIVE_FROM_INSTANCE_BASE

/**
 * \brief A definition of an undo event, with a specific interface and instance.
 * 
 * Allows to bind an event from any source: Authoring or any plug-in. Allows to have multiple separate interfaces.
 * 
 * - ak_wwise_plugin_undo_event_v1 C interface for an undo event.
 * - ak_wwise_plugin_undo_event_instance_v1 C instance for an undo event.
 * - AK::Wwise::Plugin::V1::UndoEvent C++ class for an undo event.
 * - ak_wwise_plugin_host_undo_manager_v1 C interface for the undo manager.
 * - AK::Wwise::Plugin::V1::UndoManager C++ class for the undo manager.
 */
struct ak_wwise_plugin_undo_event_pair_v1
{
	struct ak_wwise_plugin_undo_event_v1* m_interface;																	///< The interface to execute that undo event's commands.
	struct ak_wwise_plugin_undo_event_instance_v1* m_instance;															///< The specific instance usued for that particular undo event.
};

typedef int ak_wwise_plugin_undo_group_id;																				///< Unique identifier for a particular undo group. Useful to reopen an unapplied closed group session.

/**
 * \brief Action to apply once this undo group is closed.
 * 
 * The goal of an undo group is to keep a list of actions being executed that can be undone (for example, a
 * property set modification). Once the operations are all done, this indicates what should be done with the internal
 * operations.
 * 
 * - \ref AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY : The usual operation is to open an undo group, and then close
 *   and apply the group to the undo stack. This provides a valid Undo/Redo label, as well as a description of all
 *   the operations that need to be done.
 * - \ref AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY_FIRST_EVENT_NAME
 *   and AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY_LAST_EVENT_NAME are convenience operations, where the Undo
 *   operation title is retrieved from either the first or the last event's name, instead of hard-coding it ourselves.
 * - \ref AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_CANCEL cancels the undo operations. It happens when an abnormal
 *   termination occurs, such as an error, or the user cancelling a lengthy operation. Since the operation states
 *   aren't known, you are responsible to handle the stored undo yourself, and manually revert all operations first
 *   before closing the action. An example of this operation is doing a slider drag event, where the user presses
 *   the Escape key instead of doing a Mouse Up. Effectively, all the inner operations will simply be cancelled by storing
 *   the initial value before doing the cancel operation on close.
 * - \ref AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_CLOSE temporarily closes the undo state, leaving it possible to reopen
 *   it later. This is useful during lengthy processes, such as a user dragging a slider. You are expected to
 *   temporarily close the undo group when going out of scope, and reopening it when receiving a new system mouse drag
 *   event in this particular example.
 */
typedef enum {
	AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_CLOSE,																		///< Close this group session (going out of scope), but do not apply it yet.
	AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY,																		///< Close this group session permanently, and apply its operations to the englobing group.
	AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY_FIRST_EVENT_NAME,														///< Same than AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY, but copies the name of the first inner undo event as the name.
	AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY_LAST_EVENT_NAME,														///< Same than AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_APPLY, but copies the name of the last inner undo event as the name.
	AK_WWISE_PLUGIN_UNDO_GROUP_CLOSE_ACTION_CANCEL																		///< Close this group session permanently, and cancel all its internal operations. Undo operations are not applied.
} ak_wwise_plugin_undo_group_close_action;

/**
 * @}
 */

#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	using CBaseInterface = ak_wwise_plugin_base_interface;																///< \copydoc ak_wwise_plugin_base_interface
	using CInterfacePtr = ak_wwise_plugin_interface_ptr;
	using CInterfaceArrayItem = ak_wwise_plugin_interface_array_item;													///< \copydoc ak_wwise_plugin_interface_array_item
	using CPluginInfo = ak_wwise_plugin_info;																			///< \copydoc ak_wwise_plugin_info
	using CPluginContainer = ak_wwise_plugin_container;																	///< \copydoc ak_wwise_plugin_container

	using BaseInterface = CBaseInterface;																				///< \copydoc ak_wwise_plugin_base_interface
	using InterfacePtr = CInterfacePtr;
	using InterfaceArrayItem = CInterfaceArrayItem;																		///< \copydoc ak_wwise_plugin_interface_array_item
	using PluginInfo = CPluginInfo;																						///< \copydoc ak_wwise_plugin_info
	using PluginContainer = CPluginContainer;																			///< \copydoc ak_wwise_plugin_container
}
#endif