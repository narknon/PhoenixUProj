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
 * \brief Wwise Authoring Plug-ins - API to convert used object medias to a
 *        format usable by the plug-in's Sound Engine part.
 * \file AK/Wwise/Plugin/MediaConverter.h
 */

#pragma once

#include "PluginInfoGenerator.h"

/**
 * \brief API to convert used object medias to a format usable by the plug-in's Sound Engine part.
 */
struct ak_wwise_plugin_media_converter_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for providing custom media conversion.
	using Instance = ak_wwise_plugin_media_converter_instance_v1;

	ak_wwise_plugin_media_converter_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_MEDIA_CONVERTER, 1)
	{}
#endif

	/**
	 * \brief Converts a file.
	 * 
	 * \aknote If the conversion failed the function is responsible for deleting any files that may have been
	 *         created, even the destination file in case of error. If the function returns false we will use the
	 *         string put in io_pError to display an error message.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the custom platform being converted for.
	 * \param[in] in_basePlatform The unique ID of the base platform being converted for.
	 * \param[in] in_szSourceFile Source File to convert data from.
	 * \param[in] in_szDestFile Destination File, must be created by the plug-in.
	 * \param[in] in_uSampleRate The target sample rate for the converted file, passing 0 will default to
	 *            the platform default.
	 * \param[in] in_uBlockLength The block length, passing 0 will default to the platform default.
	 * \param[in] in_pProgress Optional Progress Bar controller.
	 * \param io_pError Optional error string that can be displayed if ConversionResult is not successful.
	 * \result Whether the conversion was successful or not.
	 */
	AK::Wwise::Plugin::ConversionResult(*ConvertFile)(
		const struct ak_wwise_plugin_media_converter_instance_v1* in_this,
		const GUID* in_guidPlatform,
		const BasePlatformID* in_basePlatform,
		const AkOSChar * in_szSourceFile,
		const AkOSChar * in_szDestFile,
		AkUInt32 in_uSampleRate,
		AkUInt32 in_uBlockLength,
		AK::Wwise::Plugin::IProgress* in_pProgress,
		AK::Wwise::Plugin::IWriteString* io_pError
	);

	/**
	 * \brief Calculates the conversion setting's hash.
	 * 
	 * The goal of this function is to return a value that can be used to indicate whether the plug-in information changed
	 * between two conversion requests. Each time a SoundBank generation is done, that value is stored, and if it's
	 * different from the previous one, or if the file changed, a new ConvertFile will be called.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_guidPlatform The unique ID of the custom platform for which the conversion is being done.
	 * \param[in] in_uSampleRate The target sample rate for the converted file, passing 0 will default to
	 *            the platform default.
	 * \param[in] in_uBlockLength The block length, passing 0 will default to the platform default.
	 * \return A hash value for all the plug-in parameters.
	 */
	uint32_t(*GetCurrentConversionSettingsHash)(
		const struct ak_wwise_plugin_media_converter_instance_v1* in_this,
		const GUID* in_guidPlatform,
		AkUInt32 in_uSampleRate,
		AkUInt32 in_uBlockLength
	);
};
#define AK_WWISE_PLUGIN_MEDIA_CONVERTER_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_MEDIA_CONVERTER, 1)
#define AK_WWISE_PLUGIN_MEDIA_CONVERTER_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_MEDIA_CONVERTER_V1_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CMediaConverter = ak_wwise_plugin_media_converter_v1;
		class MediaConverter : public CMediaConverter::Instance
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
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_MEDIA_CONVERTER
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
			struct Interface : public CMediaConverter
			{
				using Instance = MediaConverter;
				Interface()
				{
					CMediaConverter::ConvertFile = [](const struct ak_wwise_plugin_media_converter_instance_v1* in_this, const GUID* in_guidPlatform, const BasePlatformID* in_basePlatform, const AkOSChar * in_szSourceFile, const AkOSChar * in_szDestFile, AkUInt32 in_uSampleRate, AkUInt32 in_uBlockLength, IProgress* in_pProgress, IWriteString* io_pError)
					{ return (ConversionResult)static_cast<const Instance*>(in_this)->ConvertFile(*in_guidPlatform, *in_basePlatform, in_szSourceFile, in_szDestFile, in_uSampleRate, in_uBlockLength, in_pProgress, io_pError); };
					CMediaConverter::GetCurrentConversionSettingsHash = [](const struct ak_wwise_plugin_media_converter_instance_v1* in_this, const GUID* in_guidPlatform, AkUInt32 in_uSampleRate, AkUInt32 in_uBlockLength)
					{ return (uint32_t)static_cast<const Instance*>(in_this)->GetCurrentConversionSettingsHash(*in_guidPlatform, in_uSampleRate, in_uBlockLength); };
				}
			};

			InterfacePtr GetInterfacePointer() {
				static Interface g_interface;
				return &g_interface;
			}
			CMediaConverter::Instance* GetInstancePointer() {
				return this;
			}
			const CMediaConverter::Instance* GetInstancePointer() const {
				return this;
			}

			MediaConverter() :
				CMediaConverter::Instance()
			{
			}

			virtual ~MediaConverter() {}

			/**
			 * \brief Converts a file.
			 * 
			 * \aknote If the conversion failed the function is responsible for deleting any files that may have been
			 *         created, even the destination file in case of error. If the function returns false we will use the
			 *         string put in io_pError to display an error message.
			 * 
			 * \param[in] in_guidPlatform The unique ID of the custom platform being converted for.
			 * \param[in] in_basePlatform The unique ID of the base platform being converted for.
			 * \param[in] in_szSourceFile Source file to convert data from.
			 * \param[in] in_szDestFile Destination file, must be created by the plug-in.
			 * \param[in] in_uSampleRate The target sample rate for the converted file, passing 0 will default to
			 *            the platform default.
			 * \param[in] in_uBlockLength The block length, passing 0 will default to the platform default.
			 * \param[in] in_pProgress Optional Progress Bar controller.
			 * \param io_pError Optional error string that can be displayed if ConversionResult is not successful.
			 * \result Whether the conversion was successful or not.
			 */
			virtual ConversionResult ConvertFile(
				const GUID& in_guidPlatform,
				const BasePlatformID& in_basePlatform,
				const AkOSChar * in_szSourceFile,
				const AkOSChar * in_szDestFile,
				AkUInt32 in_uSampleRate,
				AkUInt32 in_uBlockLength,
				IProgress* in_pProgress,
				IWriteString* io_pError
			) const = 0;

			/**
			 * \brief Calculates the conversion setting's hash.
			 * 
			 * The goal of this function is to return a value that can be used to indicate whether the plug-in information changed
			 * between two conversion requests. Each time a SoundBank generation is done, that value is stored, and if it's
			 * different from the previous one, or if the file changed, a new ConvertFile will be called.
			 * 
			 * \param[in] in_guidPlatform The unique ID of the custom platform for which the conversion is being done.
			 * \param[in] in_uSampleRate The target sample rate for the converted file, passing 0 will default to
			 *            the platform default.
			 * \param[in] in_uBlockLength The block length, passing 0 will default to the platform default.
			 * \return A hash value for all the plug-in parameters.
			 */
			virtual uint32_t GetCurrentConversionSettingsHash(
				const GUID& in_guidPlatform,
				AkUInt32 in_uSampleRate = 0,
				AkUInt32 in_uBlockLength = 0
			) const = 0;
		};
	} // of namespace V1

	/// Latest version of the C MediaConverter interface.
	using CMediaConverter = V1::CMediaConverter;
	/// Latest version of the C++ MediaConverter interface.
	using MediaConverter = V1::MediaConverter;

	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(MediaConverter);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(MediaConverter);
} // of namespace AK::Wwise::Plugin

#endif
