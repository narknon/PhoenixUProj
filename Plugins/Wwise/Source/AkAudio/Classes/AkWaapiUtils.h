/*******************************************************************************
The content of the files in this repository include portions of the
AUDIOKINETIC Wwise Technology released in source code form as part of the SDK
package.

Commercial License Usage

Licensees holding valid commercial licenses to the AUDIOKINETIC Wwise Technology
may use these files in accordance with the end user license agreement provided
with the software or, alternatively, in accordance with the terms contained in a
written agreement between you and Audiokinetic Inc.

Copyright (c) 2021 Audiokinetic Inc.
*******************************************************************************/


/*------------------------------------------------------------------------------------
	WwiseUtils.h
------------------------------------------------------------------------------------*/
#pragma once

#include "Dom/JsonObject.h"
#include "AkWaapiClient.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAkWaapiUtils, Log, All);

class AKAUDIO_API WwiseWaapiHelper
{
public:
	static const FString ACTION;
	static const FString ANCESTORS;
	static const FString AT;
	static const FString AUX_BUSSES;
	static const FString BACK_SLASH;
	static const FString BANK_DATA;
	static const FString BANK_INFO;
	static const FString CHILD;
	static const FString CHILDREN;
	static const FString CHILDREN_COUNT;
	static const FString CLASSID;
	static const FString COMMAND;
	static const FString DATA;
	static const FString DELETE_ITEMS;
	static const FString DESCENDANTS;
	static const FString DISPLAY_NAME;
	static const FString DRAG_DROP_ITEMS;
	static const FString EVENT;
	static const FString EVENTS;
	static const FString FILEPATH;
	static const FString FIND_IN_PROJECT_EXPLORER;
	static const FString FOLDER;
	static const FString FROM;
	static const FString ID;
	static const FString INCLUSIONS;
	static const FString INFO_FILE;
	static const FString IS_CONNECTED;
	static const FString LANGUAGE;
	static const FString LANGUAGES;
	static const FString MAX;
	static const FString MAX_RADIUS_ATTENUATION;
	static const FString MESSSAGE;
	static const FString MIN;
	static const FString NAME;
	static const FString NAMECONTAINS;
	static const FString NEW;
	static const FString NEW_NAME;
	static const FString NOTES;
	static const FString OBJECT;
	static const FString OBJECTS;
	static const FString OF_TYPE;
	static const FString OLD_NAME;
	static const FString PARENT;
	static const FString PATH;
	static const FString PHYSICAL_FOLDER;
	static const FString PLATFORM;
	static const FString PLATFORMS;
	static const FString PLAY;
	static const FString PLAYING;
	static const FString PLAYSTOP;
	static const FString PLUGININFO_OPTIONS;
	static const FString PLUGININFO_RESPONSE;
	static const FString PROJECT;
	static const FString PROPERTY;
	static const FString RADIUS;
	static const FString RANGE;
	static const FString REBUILD;
	static const FString REBUILD_INIT_BANK;
	static const FString REDO;
	static const FString RESTRICTION;
	static const FString RETURN;
	static const FString SEARCH;
	static const FString SELECT;
	static const FString SIZE;
	static const FString SKIP_LANGUAGES;
	static const FString SOUNDBANK;
	static const FString SOUNDBANKS;
	static const FString STATE;
	static const FString STOP;
	static const FString STOPPED;
	static const FString STRUCTURE;
	static const FString TRANSFORM;
	static const FString TRANSPORT;
	static const FString TYPE;
	static const FString UI;
	static const FString UNDO;
	static const FString VALUE;
	static const FString VOLUME;
	static const FString WHERE;
	static const FString WORKUNIT_TYPE;
};

bool CallWappiGetPropertySate(const FString& ItemID, const FString& ItemProperty, TSharedPtr<FJsonObject>& ItemInfoResult); 
bool SubscribeToPropertyStateChange(const FString& ItemID, const FString& ItemProperty, WampEventCallback CallBack, uint64& SubscriptionId, TSharedPtr<FJsonObject>& outJsonResult);