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
 * \brief Wwise Authoring Plug-ins - Main include file.
 * \file AK/Wwise/Plugin.h
 * 
 * This is the default file you should include in order to build the authoring part of your plug-in.
 */

#pragma once

#include "Plugin/PluginMFCWindows.h"			// Must be set first, as it can include MFC or not

#include "Plugin/PluginInfoGenerator.h"
#include "Plugin/PluginLinks.h"

#include "Plugin/Host.h"
#include "Plugin/HostDataWriter.h"
#include "Plugin/HostObjectMedia.h"
#include "Plugin/HostObjectStore.h"
#include "Plugin/HostPropertySet.h"
#include "Plugin/HostUndoManager.h"
#include "Plugin/HostXml.h"

#include "Plugin/AudioPlugin.h"
#include "Plugin/CustomData.h"
#include "Plugin/FirstTimeCreationMessage.h"
#include "Plugin/License.h"
#include "Plugin/MediaConverter.h"
#include "Plugin/Notifications.h"
#include "Plugin/PropertyDisplayName.h"
#include "Plugin/SinkDevices.h"
#include "Plugin/Source.h"

#ifdef AK_WIN
#include "Plugin/GUIWindows.h"
#endif
