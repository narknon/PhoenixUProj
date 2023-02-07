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
 * \brief Wwise Authoring Plug-ins - API for retrieving and handling data files, as used in the plug-in.
 * \file AK/Wwise/Plugin/HostObjectMedia.h
 */

#pragma once

#include "PluginInfoGenerator.h"

#include <AK/SoundEngine/Common/AkTypes.h>

/**
 * Plug-in object media interface. Can be used to normalize media file handling inside the project.
 */
struct ak_wwise_plugin_host_object_media_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base host-provided instance type for ak_wwise_plugin_host_object_media_v1.
	using Instance = ak_wwise_plugin_host_object_media_instance_v1;

	ak_wwise_plugin_host_object_media_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_OBJECT_MEDIA, 1)
	{}
#endif

	/**
	 * \brief Requests to set the specified file as a data input file.
	 * 
	 * This will copy the file in the project under the file name specified in in_pszFilePathToImport, and
	 * create or replace a Media Source at the given index.
	 * 
	 * \aknote
	 * 		You must add up indexes sequentially. If you have 0-14 indexes, adding a new one at 40 will create it at 15.
	 * 		If you want to have empty spaces for indexes, add empty media sources with a nullptr in_pszFilePathToImport
	 * 		sequentially. Pass <code>(unsigned int)-1</code> as the in_Index to insert at the end of the list.
	 * \endaknote
	 * 
	 * \akwarning
	 * 		You should not put the same file in two different indexes.
	 * \endakwarning
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_pszFilePathToImport (Optional) File path. Can be nullptr if the plug-in generates this file, or
	 *            if the file is not yet available.
	 * \param[in] in_Index Media source index. If higher than or equal to the current media source count, will
	 * 			  add a new index.
	 * \param[in] in_bReplace True to replace a file under the same name. False will succeed if the file already exists.
	 * \return true if succeeded.
	 */
	bool(*SetMediaSource)(
		struct ak_wwise_plugin_host_object_media_instance_v1* in_this,
		const AkOSChar * in_pszFilePathToImport,
		unsigned int in_Index,
		bool in_bReplace
	);

	/**
	 * \brief Requests to remove the specified index file as data input file.
	 * 
	 * This will not renumber the supplemental index, it will merely remove the file from that index, if existing.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_Index Media source index to remove.
	 */
	void(*RemoveMediaSource)(
		struct ak_wwise_plugin_host_object_media_instance_v1* in_this,
		unsigned int in_Index
	);

	/**
	 * \brief Retrieve the number of media source indexes.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \return Count of media sources.
	 */
	unsigned int(*GetMediaSourceCount)(
		const struct ak_wwise_plugin_host_object_media_instance_v1* in_this
	);

	/**
	 * \brief Retrieve the file name of the source plug-in data at the specified index, as provided in SetMediaSource.
	 * 
	 * Used to allow the plug-in to display this information. This is the file name, and doesn't include any path.
	 * 
	 * \akwarning
	 * 		If you do not provide a buffer big enough to write the full string, the function will fail and return
	 * 		0. Make sure to use a buffer big enough to write the entire string, such as your platform's
	 * 		max path size.
	 * \endakwarning
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[out] out_pszFileName Buffer that will contain the file name.
	 * \param[in] in_uiBufferSize Size of the provided string buffer.
	 * \param[in] in_Index Media source index to query.
	 * \return Number of characters written to the buffer. 0 means no file, or failure.
	 */
	unsigned int(*GetMediaSourceFileName)(
		const struct ak_wwise_plugin_host_object_media_instance_v1* in_this,
		AkOSChar * out_pszFileName,
		unsigned int in_uiBufferSize,
		unsigned int in_Index
	);

	/**
	 * \brief Retrieve the full file path of the source plug-in data at the specified index.
	 * 
	 * This is the path name of the data file, as kept in the project directory.
	 * 
	 * \akwarning
	 * 		If you do not provide a buffer big enough to write the full string, the function will fail and return
	 * 		0. Make sure to use a buffer big enough to write the entire string, such as your platform's
	 * 		max path size.
	 * \endakwarning
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[out] out_pszFilePath Buffer that will contain the original file path.
	 * \param[in] in_uiBufferSize Size of the provided string buffer.
	 * \param[in] in_Index Media source index to query.
	 * \return Number of characters written to the buffer. 0 means no file, or failure.
	 */
	unsigned int(*GetMediaSourceOriginalFilePath)(
		const struct ak_wwise_plugin_host_object_media_instance_v1* in_this,
		AkOSChar * out_pszFilePath,
		unsigned int in_uiBufferSize,
		unsigned int in_Index
	);

	/**
	 * \brief Retrieve the full file path of the converted plug-in data at the specified index.
	 * 
	 * \akwarning
	 * 		If you do not provide a buffer big enough to write the full string, the function will fail and return
	 * 		0. Make sure to use a buffer big enough to write the entire string, such as your platform's
	 * 		max path size.
	 * \endakwarning
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[out] out_pszFilePath Buffer that will contain the converted file path.
	 * \param[in] in_uiBufferSize Size of the provided string buffer.
	 * \param[in] in_guidPlatform GUID of the platform to query.
	 * \param[in] in_Index Media source index to query.
	 * \return Number of characters written to the buffer. 0 means no file, or failure.
	 */
	unsigned int(*GetMediaSourceConvertedFilePath)(
		const struct ak_wwise_plugin_host_object_media_instance_v1* in_this,
		AkOSChar * out_pszFilePath,
		unsigned int in_uiBufferSize,
		const GUID* in_guidPlatform,
		unsigned int in_Index
	);

	/**
	 * \brief Request Wwise to perform any required conversion on the data.
	 *
	 * \sa
	 * - \ref AK::Wwise::Plugin::MediaConverter.
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[in] in_Index Media source index to invalidate.
	 */
	void(*InvalidateMediaSource)(
		struct ak_wwise_plugin_host_object_media_instance_v1* in_this,
		unsigned int in_Index
	);

	/**
	 * \brief Obtain the Original directory for the plug-in.
	 * 
	 * \akwarning
	 * 		If you do not provide a buffer big enough to write the full string, the function will fail and return
	 * 		0. Make sure to use a buffer big enough to write the entire string, such as your platform's
	 * 		max path size.
	 * \endakwarning
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[out] out_pszDirectory Buffer that will contain the path.
	 * \param[in] in_uiBufferSize Size of the provided string buffer.
	 * \return Number of characters written to the buffer. 0 means a failure.
	 */
	unsigned int(*GetOriginalDirectory)(
		const struct ak_wwise_plugin_host_object_media_instance_v1* in_this,
		AkOSChar * out_pszDirectory,
		unsigned int in_uiBufferSize
	);

	/**
	 * \brief Obtain the Converted directory for the plug-in and platform.
	 * 
	 * \akwarning
	 * 		If you do not provide a buffer big enough to write the full string, the function will fail and return
	 * 		0. Make sure to use a buffer big enough to write the entire string, such as your platform's
	 * 		max path size.
	 * \endakwarning
	 * 
	 * \param[in] in_this Current instance of this interface.
	 * \param[out] out_pszDirectory Buffer that will contain the path.
	 * \param[in] in_uiBufferSize Size of the provided string buffer.
	 * \param[in] in_guidPlatform GUID of the platform to query.
	 * \return Number of characters written to the buffer. 0 means a failure.
	 */
	unsigned int(*GetConvertedDirectory)(
		const struct ak_wwise_plugin_host_object_media_instance_v1* in_this,
		AkOSChar * out_pszDirectory,
		unsigned int in_uiBufferSize,
		const GUID* in_guidPlatform
	);
};


struct ak_wwise_plugin_notifications_object_media_v1
#ifdef __cplusplus
	: public ak_wwise_plugin_base_interface
#endif
{
#ifndef __cplusplus
	ak_wwise_plugin_base_interface m_baseInterface;
#endif

#ifdef __cplusplus
	/// Base instance type for receiving notifications on related object media's changes.
	using Instance = ak_wwise_plugin_notifications_object_media_instance_v1;

	ak_wwise_plugin_notifications_object_media_v1() :
		ak_wwise_plugin_base_interface(AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_OBJECT_MEDIA, 1)
	{}
#endif

	/**
	 * \brief This function is called by Wwise when any of the plug-in media changes.
	 * 
	 * It is called when plugin media is added, removed or changes. This function is also called during undo or redo operations.
	 * 
	 * \sa
	 * - \ref effectplugin_media_managing
	 * 
	 * \param[in] in_this Current instance of this interface.
	 */
	void(*NotifyPluginMediaChanged)(struct ak_wwise_plugin_notifications_object_media_instance_v1* in_this);
};


#define AK_WWISE_PLUGIN_HOST_OBJECT_MEDIA_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_OBJECT_MEDIA, 1)
#define AK_WWISE_PLUGIN_HOST_OBJECT_MEDIA_V1_CTOR() \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_HOST_OBJECT_MEDIA_V1_ID() \
}

#define AK_WWISE_PLUGIN_NOTIFICATIONS_OBJECT_MEDIA_V1_ID() \
	AK_WWISE_PLUGIN_BASE_INTERFACE_FROM_ID(AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_OBJECT_MEDIA, 1)
#define AK_WWISE_PLUGIN_NOTIFICATIONS_OBJECT_MEDIA_V1_CTOR(/* ak_wwise_plugin_info* */ in_pluginInfo, /* void* */ in_data) \
{ \
	.m_baseInterface = AK_WWISE_PLUGIN_BASE_INTERFACE_CTOR(AK_WWISE_PLUGIN_NOTIFICATIONS_OBJECT_MEDIA_V1_ID(), in_pluginInfo, in_data) \
}


#ifdef __cplusplus
namespace AK::Wwise::Plugin
{
	namespace V1
	{
		using CHostObjectMedia = ak_wwise_plugin_host_object_media_v1;

		/// \copydoc ak_wwise_plugin_host_object_media_v1
		class ObjectMedia : public CBaseInstanceGlue<CHostObjectMedia>
		{
		public:
			using Interface = CHostObjectMedia;

			/**
			 * \brief The interface type, as requested by this plug-in.
			 */
			enum : InterfaceTypeValue
			{
				/**
				 * \brief The interface type, as requested by this plug-in.
				 */
				k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_HOST_OBJECT_MEDIA
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
			 * \brief Requests to set the specified file as a data input file.
			 * 
			 * This will copy the file in the project under the file name specified in in_pszFilePathToImport, and
			 * create or replace a Media Source at the given index.
			 * 
			 * \aknote
			 * 		You must add up indexes sequentially. If you have 0-14 indexes, adding a new one at 40 will create it at 15.
			 * 		If you want to have empty spaces for indexes, add empty media sources with a nullptr in_pszFilePathToImport
			 * 		sequentially. Pass <code>(unsigned int)-1</code> as the in_Index to insert at the end of the list.
			 * \endaknote
			 * 
			 * \akwarning
			 * 		You should not put the same file in two different indexes.
			 * \endakwarning
			 * 
			 * \param[in] in_pszFilePathToImport (Optional) File path. Can be nullptr if the plug-in generates this file, or
			 *            if the file is not yet available.
			 * \param[in] in_Index Media source index. If higher than or equal to the current media source count, will
			 * 			  add a new index.
			 * \param[in] in_bReplace True to replace a file under the same name. False will succeed if the file already exists.
			 * \return true if succeeded.
			 */
			inline bool SetMediaSource(
				const AkOSChar * in_pszFilePathToImport,
				unsigned int in_Index,
				bool in_bReplace
			)
			{
				return MKBOOL(g_cinterface->SetMediaSource(this, in_pszFilePathToImport, in_Index, in_bReplace));
			}

			/**
			 * \brief Requests to remove the specified index file as data input file.
			 * 
			 * This will not renumber the supplemental index, it will merely remove the file from that index, if existing.
			 * 
			 * \param[in] in_Index Media source index to remove.
			 */
			inline void RemoveMediaSource(
				unsigned int in_Index
			)
			{
				g_cinterface->RemoveMediaSource(this, in_Index);
			}

			/**
			 * \brief Retrieve the number of media source indexes.
			 * 
			 * \return Count of media sources.
			 */
			inline unsigned int GetMediaSourceCount() const
			{
				return g_cinterface->GetMediaSourceCount(this);
			}

			/**
			 * \brief Retrieve the file name of the source plug-in data at the specified index, as provided in SetMediaSource.
			 * 
			 * Used to allow the plug-in to display this information. This is the file name, and doesn't include any path.
			 * 
			 * \akwarning
			 * 		If you do not provide a buffer big enough to write the full string, the function will fail and return
			 * 		0. Make sure to use a buffer big enough to write the entire string, such as your platform's
			 * 		max path size.
			 * \endakwarning
			 * 
			 * \param[out] out_pszFileName Buffer that will contain the file name.
			 * \param[in] in_uiBufferSize Size of the provided string buffer.
			 * \param[in] in_Index Media source index to query.
			 * \return Number of characters written to the buffer. 0 means no file, or failure.
			 */
			inline unsigned int GetMediaSourceFileName(
				AkOSChar * out_pszFileName,
				unsigned int in_uiBufferSize,
				unsigned int in_Index
			) const
			{
				return g_cinterface->GetMediaSourceFileName(this, out_pszFileName, in_uiBufferSize, in_Index);
			}

			/**
			 * \brief Retrieve the full file path of the source plug-in data at the specified index.
			 * 
			 * This is the path name of the data file, as kept in the project directory.
			 * 
			 * \akwarning
			 * 		If you do not provide a buffer big enough to write the full string, the function will fail and return
			 * 		0. Make sure to use a buffer big enough to write the entire string, such as your platform's
			 * 		max path size.
			 * \endakwarning
			 * 
			 * \param[out] out_pszFilePath Buffer that will contain the original file path.
			 * \param[in] in_uiBufferSize Size of the provided string buffer.
			 * \param[in] in_Index Media source index to query.
			 * \return Number of characters written to the buffer. 0 means no file, or failure.
			 */
			inline unsigned int GetMediaSourceOriginalFilePath(
				AkOSChar * out_pszFilePath,
				unsigned int in_uiBufferSize,
				unsigned int in_Index
			) const
			{
				return g_cinterface->GetMediaSourceOriginalFilePath(this, out_pszFilePath, in_uiBufferSize, in_Index);
			}

			/**
			 * \brief Retrieve the full file path of the converted plug-in data at the specified index.
			 * 
			 * \akwarning
			 * 		If you do not provide a buffer big enough to write the full string, the function will fail and return
			 * 		0. Make sure to use a buffer big enough to write the entire string, such as your platform's
			 * 		max path size.
			 * \endakwarning
			 * 
			 * \param[out] out_pszFilePath Buffer that will contain the converted file path.
			 * \param[in] in_uiBufferSize Size of the provided string buffer.
			 * \param[in] in_guidPlatform GUID of the platform to query.
			 * \param[in] in_Index Media source index to query.
			 * \return Number of characters written to the buffer. 0 means no file, or failure.
			 */
			inline unsigned int GetMediaSourceConvertedFilePath(
				AkOSChar * out_pszFilePath,
				unsigned int in_uiBufferSize,
				const GUID& in_guidPlatform,
				unsigned int in_Index
			) const
			{
				return g_cinterface->GetMediaSourceConvertedFilePath(this, out_pszFilePath, in_uiBufferSize, &in_guidPlatform, in_Index);
			}

			/**
			 * \brief Request Wwise to perform any required conversion on the data.
			 * 
			 * \sa
			 * - \ref AK::Wwise::Plugin::MediaConverter.
			 * 
			 * \param[in] in_Index Media source index to invalidate.
			 */
			inline void InvalidateMediaSource(
				unsigned int in_Index
			)
			{
				return g_cinterface->InvalidateMediaSource(this, in_Index);
			}

			/**
			 * \brief Obtain the Original directory for the plug-in.
			 * 
			 * \akwarning
			 * 		If you do not provide a buffer big enough to write the full string, the function will fail and return
			 * 		0. Make sure to use a buffer big enough to write the entire string, such as your platform's
			 * 		max path size.
			 * \endakwarning
			 * 
			 * \param[out] out_pszDirectory Buffer that will contain the path.
			 * \param[in] in_uiBufferSize Size of the provided string buffer.
			 * \return Number of characters written to the buffer. 0 means a failure.
			 */
			inline unsigned int GetOriginalDirectory(
				AkOSChar * out_pszDirectory,
				unsigned int in_uiBufferSize
			) const
			{
				return g_cinterface->GetOriginalDirectory(this, out_pszDirectory, in_uiBufferSize);
			}

			/**
			 * \brief Obtain the Converted directory for the plug-in and platform.
			 * 
			 * \akwarning
			 * 		If you do not provide a buffer big enough to write the full string, the function will fail and return
			 * 		0. Make sure to use a buffer big enough to write the entire string, such as your platform's
			 * 		max path size.
			 * \endakwarning
			 * 
			 * \param[out] out_pszDirectory Buffer that will contain the path.
			 * \param[in] in_uiBufferSize Size of the provided string buffer.
			 * \param[in] in_guidPlatform GUID of the platform to query.
			 * \return Number of characters written to the buffer. 0 means a failure.
			 */
			inline unsigned int GetConvertedDirectory(
				AkOSChar * out_pszDirectory,
				unsigned int in_uiBufferSize,
				const GUID& in_guidPlatform
			) const
			{
				return g_cinterface->GetConvertedDirectory(this, out_pszDirectory, in_uiBufferSize, &in_guidPlatform);
			}
		};

		namespace Notifications
		{
			using CObjectMedia_ = ak_wwise_plugin_notifications_object_media_v1;

			/// \copydoc ak_wwise_plugin_notifications_object_media_v1
			class ObjectMedia_ : public CObjectMedia_::Instance
			{
			public:
				/**
				 * \copydoc CObjectMedia_::Instance
				 */
				using Instance = CObjectMedia_::Instance;

				/**
				 * \brief The interface type, as provided by this plug-in.
				 */
				enum : InterfaceTypeValue
				{
					/**
					 * \brief The interface type, as provided by this plug-in.
					 */
					k_interfaceType = AK_WWISE_PLUGIN_INTERFACE_TYPE_NOTIFICATIONS_OBJECT_MEDIA
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
				struct Interface : public CObjectMedia_
				{
					using Instance = ObjectMedia_;
					Interface()
					{
						CObjectMedia_::NotifyPluginMediaChanged = [](
							struct ak_wwise_plugin_notifications_object_media_instance_v1* in_this)
						{
							static_cast<Instance*>(in_this)->NotifyPluginMediaChanged();
						};
					}
				};

				InterfacePtr GetInterfacePointer() {
					static Interface g_interface;
					return &g_interface;
				}
				CObjectMedia_::Instance* GetInstancePointer() {
					return this;
				}
				const CObjectMedia_::Instance* GetInstancePointer() const {
					return this;
				}

				ObjectMedia_() :
					CObjectMedia_::Instance()
				{
				}

				virtual ~ObjectMedia_() {}

				/**
				 * \brief This function is called by Wwise when any of the plug-in media changes.
				 *
				 * It is called when plugin media is added, removed or changes. This function is also called during undo or redo operations.
				 *
				 * \sa
				 * - \ref effectplugin_media_managing
				 */
				virtual void NotifyPluginMediaChanged() {}
			};
		} // of namespace Notifications

		/**
		 * \brief Requests a ObjectMedia interface, provided as m_objectMedia variable.
		 * 
		 * Deriving your plug-in class from RequestObjectMedia will automatically request both ObjectMedia and
		 * Notifications::ObjectMedia_ interfaces. From this point, you will be able to derive from the virtual
		 * functions as defined in Notifications::ObjectMedia_, and access the host-provided functions in the
		 * \c m_objectMedia variable.
		 */
		using RequestObjectMedia = RequestedHostInterface<ObjectMedia>;

	} // of namespace V1

	/// Latest version of the C ObjectMedia interface.
	using CHostObjectMedia = V1::CHostObjectMedia;
	/// Latest version of the C++ ObjectMedia interface.
	using ObjectMedia = V1::ObjectMedia;
	/// Latest version of the requested C++ ObjectMedia interface.
	using RequestObjectMedia = V1::RequestObjectMedia;

	namespace Notifications
	{
		/// Latest version of the C ObjectMedia notification interface.
		using CObjectMedia = V1::Notifications::CObjectMedia_;
		/// Latest version of the C++ ObjectMedia notification interface.
		using ObjectMedia = V1::Notifications::ObjectMedia_;
	}

	AK_WWISE_PLUGIN_SPECIALIZE_HOST_INTERFACE(ObjectMedia, objectMedia,, public Notifications::ObjectMedia);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(ObjectMedia);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(ObjectMedia);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_CLASS(Notifications::ObjectMedia);
	AK_WWISE_PLUGIN_SPECIALIZE_INTERFACE_VERSION(Notifications::ObjectMedia);
} // of namespace AK::Wwise::Plugin

#endif
