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
 * \brief Wwise Authoring Plug-ins - API to write data that can be converted for the target platform.
 * \file AK/Wwise/Plugin/HostDataWriter.h
 */

#pragma once

#include "PluginInfoGenerator.h"

/**
 * \brief Interface used to write data during sound bank generation.
 * 
 * \aknote
 * All functions perform the appropriate platform-specific byte reordering, except where noted.
 * \endaknote
 * 
 * \sa
 * - \ref wwiseplugin_bank
 * - AK::Wwise::Plugin::Plugin::GetBankParameters()
 */
struct ak_wwise_plugin_host_data_writer_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base host-provided instance type for ak_wwise_plugin_host_data_writer_v1.
	using Instance = ak_wwise_plugin_host_data_writer_instance_v1;

	ak_wwise_plugin_host_data_writer_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_DATA_WRITER, 1)
	{}
#endif

	/**
	 * \brief Writes a block of data.
	 * 
	 * \akcaution 
	 * This data will always be written as-is, with no platform-specific conversion.
	 * \endakcaution
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pData A pointer to the buffer containing the data to be written.
	 * \param[in] in_cBytes The number of bytes to write.
	 * \param[out] out_cWritten The number of bytes actually written.
	 * \return true if successful.
	 */
	bool(*WriteData)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		const void* in_pData,
		uint32_t in_cBytes,
		uint32_t* out_cWritten
	);

	/**
	 * \brief Writes a string.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_szString The string to be written (null-terminated).
	 * \return true if successful.
	 */
	bool(*WriteString)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		const char * in_szString
	);

	/**
	 * \brief Writes a 64-bit signed integer value.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_value The value to be written.
	 * \return true if successful.
	 */
	bool(*WriteInt64)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		int64_t in_value
	);

	/**
	 * \brief Writes a 32-bit signed integer value.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_value The value to be written.
	 * \return true if successful.
	 */
	bool(*WriteInt32)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		int32_t in_value
	);

	/**
	 * \brief Writes a 16-bit signed integer value.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_value The value to be written.
	 * \return true if successful.
	 */
	bool(*WriteInt16)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		int16_t in_value
	);

	/**
	 * \brief Writes an 8-bit signed integer value.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_value The value to be written.
	 * \return true if successful.
	 */
	bool(*WriteInt8)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		int8_t in_value
	);

	/**
	 * \brief Writes a 64-bit unsigned integer value.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_value The value to be written.
	 * \return true if successful.
	 */
	bool(*WriteUInt64)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		uint64_t in_value
	);

	/**
	 * \brief Writes a 32-bit unsigned integer value.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_value The value to be written.
	 * \return true if successful.
	 */
	bool(*WriteUInt32)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		uint32_t in_value
	);

	/**
	 * \brief Writes a 16-bit unsigned integer value.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_value The value to be written.
	 * \return true if successful.
	 */
	bool(*WriteUInt16)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		uint16_t in_value
	);

	/**
	 * \brief Writes an 8-bit unsigned integer value.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_value The value to be written.
	 * \return true if successful.
	 */
	bool(*WriteUInt8)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		uint8_t in_value
	);

	/**
	 * \brief Writes a 64-bit, double-precision floating point value.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_value The value to be written.
	 * \return true if successful.
	 */
	bool(*WriteReal64)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		double in_value
	);

	/**
	 * \brief Writes a 32-bit, single-precision floating point value.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_value The value to be written.
	 * \return true if successful.
	 */
	bool(*WriteReal32)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		float in_value
	);

	/**
	 * \brief Writes a boolean value.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_value The boolean to be written.
	 * \return true if successful.
	 */
	bool(*WriteBool)(
		struct ak_wwise_plugin_host_data_writer_instance_v1* in_this,
		bool in_value
	);
};
#define AK_WWISE_PLUGIN_HOST_WRITE_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_DATA_WRITER, 1)
#define AK_WWISE_PLUGIN_HOST_WRITE_V1_CTOR() \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_HOST_WRITE_V1_ID() \
}

#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CHostDataWriter = ak_wwise_plugin_host_data_writer_v1;
		
		/// \copydoc ak_wwise_plugin_host_data_writer_v1
		class DataWriter : public CBaseInstanceGlue<CHostDataWriter>
		{
		public:
			using Interface = CHostDataWriter;

			/**
			 * \brief The interface type, as requested by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as requested by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_DATA_WRITER
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
			 * \brief Writes a block of data.
			 * 
			 * \akcaution 
			 * This data will always be written as-is, with no platform-specific conversion.
			 * \endakcaution
			 * 
			 * \param[in] in_pData A pointer to the buffer containing the data to be written.
			 * \param[in] in_cBytes The number of bytes to write.
			 * \param[out] out_cWritten The number of bytes actually written.
			 * \return true if successful.
			 */
			inline bool WriteData(
				const void* in_pData,
				uint32_t in_cBytes,
				uint32_t& out_cWritten
			)
			{
				return MKBOOL(g_cinterface->WriteData(this, in_pData, in_cBytes, &out_cWritten));
			}

			/**
			 * \brief Writes a string.
			 * 
			 * \param[in] in_szString The string to be written (null-terminated).
			 * \return true if successful.
			 */
			inline bool WriteString(
				const char * in_szString
			)
			{
				return MKBOOL(g_cinterface->WriteString(this, in_szString));
			}

			/**
			 * \brief Writes a 64-bit signed integer value.
			 * 
			 * \param[in] in_value The value to be written.
			 * \return true if successful.
			 */
			inline bool WriteInt64(
				int64_t in_value
			)
			{
				return MKBOOL(g_cinterface->WriteInt64(this, in_value));
			}

			/**
			 * \brief Writes a 32-bit signed integer value.
			 * 
			 * \param[in] in_value The value to be written.
			 * \return true if successful.
			 */
			inline bool WriteInt32(
				int32_t in_value
			)
			{
				return MKBOOL(g_cinterface->WriteInt32(this, in_value));
			}

			/**
			 * \brief Writes a 16-bit signed integer value.
			 * 
			 * \param[in] in_value The value to be written.
			 * \return true if successful.
			 */
			inline bool WriteInt16(
				int16_t in_value
			)
			{
				return MKBOOL(g_cinterface->WriteInt16(this, in_value));
			}

			/**
			 * \brief Writes an 8-bit signed integer value.
			 * 
			 * \param[in] in_value The value to be written.
			 * \return true if successful.
			 */
			inline bool WriteInt8(
				int8_t in_value
			)
			{
				return MKBOOL(g_cinterface->WriteInt8(this, in_value));
			}

			/**
			 * \brief Writes a 64-bit unsigned integer value.
			 * 
			 * \param[in] in_value The value to be written.
			 * \return true if successful.
			 */
			inline bool WriteUInt64(
				uint64_t in_value
			)
			{
				return MKBOOL(g_cinterface->WriteUInt64(this, in_value));
			}

			/**
			 * \brief Writes a 32-bit unsigned integer value.
			 * 
			 * \param[in] in_value The value to be written.
			 * \return true if successful.
			 */
			inline bool WriteUInt32(
				uint32_t in_value
			)
			{
				return MKBOOL(g_cinterface->WriteUInt32(this, in_value));
			}

			/**
			 * \brief Writes a 16-bit unsigned integer value.
			 * 
			 * \param[in] in_value The value to be written.
			 * \return true if successful.
			 */
			inline bool WriteUInt16(
				uint16_t in_value
			)
			{
				return MKBOOL(g_cinterface->WriteUInt16(this, in_value));
			}

			/**
			 * \brief Writes an 8-bit unsigned integer value.
			 * 
			 * \param[in] in_value The value to be written.
			 * \return true if successful.
			 */
			inline bool WriteUInt8(
				uint8_t in_value
			)
			{
				return MKBOOL(g_cinterface->WriteUInt8(this, in_value));
			}

			/**
			 * \brief Writes a 64-bit, double-precision floating point value.
			 * 
			 * \param[in] in_value The value to be written.
			 * \return true if successful.
			 */
			inline bool WriteReal64(
				double in_value
			)
			{
				return MKBOOL(g_cinterface->WriteReal64(this, in_value));
			}

			/**
			 * \brief Writes a 32-bit, single-precision floating point value.
			 * 
			 * \param[in] in_value The value to be written.
			 * \return true if successful.
			 */
			inline bool WriteReal32(
				float in_value
			)
			{
				return MKBOOL(g_cinterface->WriteReal32(this, in_value));
			}

			/**
			 * \brief Writes a boolean value.
			 * 
			 * \param[in] in_value The boolean to be written.
			 * \return true if successful.
			 */
			inline bool WriteBool(
				bool in_value
			)
			{
				return MKBOOL(g_cinterface->WriteBool(this, in_value));
			}
		};

		/**
		 * \brief Requests a DataWriter interface.
		 * 
		 * Deriving your plug-in class from RequestConversionHelpers will automatically request
		 * DataWriter interface. This is useful for SoundBank generation and parameter
		 * passing to the Sound Engine. You must derive from this interface in order to use the
		 * provided functions.
		 * 
		 * \aknote The AK::Wwise::Plugin::RequestPropertySet and AK::Wwise::Plugin::RequestWrite classes are
		 * automatically derived when providing AK::Wwise::Plugin::AudioPlugin in C++. \endaknote
		 */
		using RequestWrite = RequestedHostInterface<DataWriter>;

	} // of namespace V1

	/// Latest version of the C DataWriter interface.
	using CHostDataWriter = V1::CHostDataWriter;
	/// Latest version of the C++ DataWriter interface.
	using DataWriter = V1::DataWriter;
	/// Latest version of the requested C++ DataWriter interface.
	using RequestWrite = V1::RequestWrite;

	AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE_NO_BASE_INSTANCE(DataWriter, dataWriter);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(DataWriter);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(DataWriter);
} // of namespace AK::Wwise::Plugin

#endif
