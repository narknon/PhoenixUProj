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
 * \brief Wwise Authoring Plug-ins - Provides MFC initialization on plug-in instantiation.
 * \file AK/Wwise/Plugin/PluginMFCWindows.h
 * 
 * By default, an MFC-based DLL initializes itself when the DLL is loaded. However, not all plug-ins in a DLL container
 * require MFC, so this makes sure to initialize MFC only on instantiation of a particular plug-in.
 *
 * \sa C++ interfaces
 * - \ref AK::Wwise::Plugin::PluginMFCWindows
 */

#pragma once

#if 	defined( DOXYGEN_INCLUDE ) || ( \
		(defined( _WIN32 ) || defined ( _WIN64 ) || defined( WINAPI_FAMILY )) \
	 && ((defined(_AFXDLL) && _AFXDLL) || defined(_MFC_BLD) || defined(__AFX_H__)) )

#include <afxwin.h>

#ifdef __cplusplus

#include <memory>

namespace AK::Wwise::Plugin
{
	/**
	 * \brief Initializes MFC for this plug-in.
	 * 
	 * By default, an MFC-based DLL initializes itself when the DLL is loaded. However, not all plug-ins in a DLL
	 * container require MFC, so this makes sure to initialize MFC only on instantiation of a particular plug-in.
	 * 
	 * If you need to modify the CWinApp class on your own, you can update the template.
	 * 
	 * \code
	 *     : public AK::Wwise::Plugin::PluginMFCWindows<MyWinApp>
	 * \endcode
	 * 
	 * \aknote This should be the first interface of the plug-in, as it needs to be initialized before anything. \endaknote
	 */
	template<typename CWinApp = ::CWinApp>
	class PluginMFCWindows
	{
		/**
		 * \brief DLL singleton for MFC's CWinApp.
		 * 
		 * This singleton is unique in the DLL. It should be initialized in the main app thread.
		 * Please note it is desired behavior to have multiple instances of this singleton in an application. However,
		 * MFC expects to have a single copy per DLL.
		 */
		static std::unique_ptr<CWinApp> g_theApp;

	public:
		/**
		 * \brief Initializes g_theApp singleton
		 */
		PluginMFCWindows()
		{
			if (!g_theApp)
			{
				AFX_MANAGE_STATE(AfxGetStaticModuleState());
				g_theApp.reset(new CWinApp);

				g_theApp->InitInstance();
			}
		}

		/**
		 * \brief Retrieves the CWinApp singleton.
		 * 
		 * \return CWinApp* 
		 */
		static CWinApp* GetMFCApp()
		{
			return g_theApp;
		}
	};

	template<typename CWinApp>
	std::unique_ptr<CWinApp> PluginMFCWindows<CWinApp>::g_theApp;
} // of namespace AK::Wwise::Plugin

#endif // of __cplusplus
#endif // of Windows detection