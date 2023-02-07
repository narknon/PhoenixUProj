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


/*=============================================================================
	AkWaapiClient.h: Audiokinetic WAAPI interface object.
=============================================================================*/

#pragma once

/*------------------------------------------------------------------------------------
	AkWaapiClient system headers.
------------------------------------------------------------------------------------*/

#include "AkInclude.h"
#include "Engine/EngineBaseTypes.h"
#include "Engine/EngineTypes.h"
#include "HAL/Runnable.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"
#include "HAL/ThreadSafeBool.h"
#include "AK/WwiseAuthoringAPI/waapi.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAkWaapiClient, Log, All);

/*------------------------------------------------------------------------------------
Dependencies, helpers & forward declarations.
------------------------------------------------------------------------------------*/

/** Defines WampEventCallback delegate interface */
DECLARE_DELEGATE_TwoParams(WampEventCallback, uint64_t, TSharedPtr<FJsonObject>);

/** Events fired when WAAPI connection is started or lost */
DECLARE_EVENT(FAkWaapiClient, WwiseProjectLoaded);
DECLARE_EVENT(FAkWaapiClient, WAAPIConnectionLost);
DECLARE_EVENT(FAkWaapiClient, BeginDestroyClient);

#define WAAPI_LOCAL_HOST_IP_STRING "127.0.0.1"
#define WAAPI_PORT 8080

/*------------------------------------------------------------------------------------
- FAkWaapiClientConnectionHandler
------------------------------------------------------------------------------------*/

class FAkWaapiClient;

class FAkWaapiClientConnectionHandler : public FRunnable
{
public:
    FAkWaapiClientConnectionHandler(FAkWaapiClient& in_Client);
    ~FAkWaapiClientConnectionHandler();
    // FRunnable interface.
    virtual bool   Init() override;
    virtual uint32 Run()  override;
    virtual void   Stop() override;
    virtual void   Exit() override;

    void ResetReconnectionDelay();
    void RegisterAutoConnectChangedCallback();
    void Wake();
private:
	FThreadSafeBool ThreadShouldExit = false;
    FThreadSafeCounter ReconnectDelay = 2;
    FThreadSafeCounter ConnectionMonitorDelay = 7;
	FThreadSafeCounter LogOutputCount = 0;
    int m_iMaxReconnectDelay = 32;
    FEvent* WaitEvent;
    FCriticalSection AkSettingsSection;
    FAkWaapiClient& m_Client;
    bool hadConnection = false;
    bool AttemptReconnect();
    FDelegateHandle AutoConnectChangedHandle;
};

/*------------------------------------------------------------------------------------
AkWaapiClient audio device.
------------------------------------------------------------------------------------*/

class AKAUDIO_API FAkWaapiClient
{
public:

    virtual ~FAkWaapiClient();

    /**
    * Initialize the singleton instance of FAkWaapiClient.
    * The singleton instance owns a connection thread which will monitor the WAAPI connection.
    * This function should therefore be called once, in the module startup function, such that WAAPI is ready to be used, if available.
    */
    static void Initialize();

    /**
    * Obtain a pointer to the singleton instance of FAkWaapiClient.
    * Be sure to call FAkWaapiClient::Initialize() first (i.e. during Module startup).
    *
    * @return Pointer to the singleton instance of FAkWaapiClient.
    */
    static FAkWaapiClient* Get();

    /**
    * Delete the singleton instance of FAkWaapiClient.
    */
    static void DeleteInstance();

    /**
    * Obtain a pointer to the delegate associated to the in_subscriptionId
    *
    * @return Pointer to the delegate associated to the in_subscriptionId
    */
    WampEventCallback* GetWampEventCallback(const uint64_t& in_subscriptionId);


    /**
    * Allows clients to subscribe to notifications according to the event.
    *
    * @param in_jsonObject		  An FJsonObject that we want to convert to string.
    * @param ou_jsonObjectString  The result of conversation in string format.
    * @return					  A boolean to ensure that the conversion was successfully done.
    */
    static bool JsonObjectToString(const TSharedRef<FJsonObject>& in_jsonObject, FString& ou_jsonObjectString);

    bool IsConnected();
    bool AttemptConnection();

    /** Checks whether the current project is dirty */
    static bool IsProjectDirty();

    /**
    * Allows clients to subscribe to notifications according to the event.
    *
    * @param in_uri			 The reference to the event that we would be aware of when it happens.
    * @param in_options		 Optional flag to get more information about the event happened.
    * @param in_callback		 A delegate to be executed during the subscription event.
    * @param out_subscriptionId Gets the id of this subscription.
    * @param out_result		 A JSON object that contains useful informations about the subscription process to a specific event, gets an error infos in case the subscription failed.
    * @return					 A boolean to ensure that the subscription was successfully done.
    */
    bool Subscribe(const char* in_uri, const FString& in_options, WampEventCallback in_callback,
        uint64& out_subscriptionId, FString& out_result, int in_iTimeoutMs = 500);
    bool Subscribe(const char* in_uri, const TSharedRef<FJsonObject>& in_options, WampEventCallback in_callback,
        uint64& out_subscriptionId, TSharedPtr<FJsonObject>& out_result, int in_iTimeoutMs = 500);

    /**
    * Unsubscribe to notifications
    *
    * @param in_subscriptionId	Gets the id of the current subscription to the event from which we want to be unsubscribed.
    * @param out_result		A JSON object that contains useful informations about the unsubscription process from a specific event, gets an error infos in case the unsubscription failed.
    * @return					A boolean to ensure that the unsubscription was successfully done.
    */
    bool Unsubscribe(const uint64_t& in_subscriptionId, FString& out_result, int in_iTimeoutMs = 500, bool in_bSilenceLog = false);
    bool Unsubscribe(const uint64_t& in_subscriptionId, TSharedPtr<FJsonObject>& out_result, int in_iTimeoutMs = 500, bool in_bSilenceLog = false);

	/**
	 * Remove manually the WampEventCallback, used by the WAAPI picker when the connection is lost
	 *
	  * @param in_subscriptionId The subscription id to the event from which we want to be unsubscribed.
	 */
	bool RemoveWampEventCallback(const uint64_t in_subscriptionId);

    /**
    *
    *
    * @param in_uri		The	Function that will be called when an event that we would be aware of happens.
    * @param in_args		The arguments referenced to the in_uri function.
    * @param in_options	Optional flag to get more information about the event happened.
    * @param out_result	A JSON object that contains useful informations about the Call process to a specific event, gets an error infos in case the Call fails.
    * @return				A boolean to ensure that the call was successfully passed.
    */
    bool Call(const char* in_uri, const FString& in_args, const FString& in_options, FString& out_result, int in_iTimeoutMs = 500, bool silenceLog = false);
    bool Call(const char* in_uri, const TSharedRef<FJsonObject>& in_args, const TSharedRef<FJsonObject>& in_options,
        TSharedPtr<FJsonObject>& out_result, int in_iTimeoutMs = 500, bool silenceLog = false);

    /** Sets in_outParentGUID to the object ID of a parent of object in_objectGUID of type in_strType. */
    static void GetParentOfType(FGuid in_objectGUID, FGuid& in_outParentGUID, FString in_strType);
    /** Gets the path of the currently loaded project in Wwise Authoring. */
    static bool GetProjectPath(TSharedPtr<FJsonObject>& inOutJsonReslut, FString& ProjectPath);

    WwiseProjectLoaded OnProjectLoaded;
    WAAPIConnectionLost OnConnectionLost;
	BeginDestroyClient OnClientBeginDestroy;

    /** This is called when the reconnection handler successfully connects to WAAPI.
    *  We check if the correct project is loaded on a background thread. If it is, we broadcast OnProjectLoaded.
    *  We also subscribe to ak::wwise::core::project::loaded in order to check the project whenever one is loaded.
    *  If an incorrect project is loaded we broadcast OnConnectionLost.
    */
    void ConnectionEstablished();
    void BroadcastConnectionLost();
    static bool IsProjectLoaded();

    /**
     *  Indicates that the connection to WAAPI should be stopped and shouldn't be reconnected.
     */
    bool IsDisconnecting();
    bool AppIsExiting();

    void SetConnectionClosing(bool isClosing);

    /**
    * Since it's a singleton WaapiClient, we  want to make sure these methods (copying constructor and assignment operator).
    * are unacceptable otherwise we may accidentally get copies of our WaapiClient singleton appearing.
    */
    FAkWaapiClient(FAkWaapiClient const&) = delete;
    void operator=(FAkWaapiClient const&) = delete;

    //===================================================================================================
    // WAAPI enums
    //===================================================================================================
    enum class WAAPIGetFromOption : AkUInt16
    {
        ID = 0,
        SEARCH,
        PATH,
        OF_TYPE,
        QUERY
    };

    static FString GetFromOptionString(WAAPIGetFromOption from);

    enum class WAAPIGetTransformOption : AkUInt16
    {
        SELECT = 0,
        RANGE,
        WHERE,
        NONE
    };

    static FString GetTransformOptionString(WAAPIGetTransformOption transform);

    enum class WAAPIGetReturnOptionFlag : AkInt64
    {
        ID = 0x1,
        NAME = 0x2,
        NOTES = 0x4,
        TYPE = 0x8,
        PATH = 0x10,
        PARENT = 0x20,
        OWNER = 0x40,
        IS_PLAYABLE = 0x80,
        SHORT_ID = 0x100,
        CATEGORY = 0x200,
        FILEPATH = 0x400,
        WORKUNIT = 0x800,
        CHILDREN_COUNT = 0x1000,
        MUSIC_TRANSITION_ROOT = 0x2000,
        MUSIC_PLAYLIST_ROOT = 0x4000,
        SOUND_ORIGINAL_WAV_FILE_PATH = 0x8000,
        SOUND_CONVERTED_WEM_FILE_PATH = 0x10000,
        SOUNDBANK_BANK_FILE_PATH = 0x20000,
        AUDIO_SOURCE_PLAYBACK_DURATION = 0x40000,
        AUDIO_SOURCE_MAX_DURATION_SOURCE = 0x80000,
        AUDIO_SOURCE_TRIM_VALUES = 0x100000,
        WORKUNIT_IS_DEFAULT = 0x200000,
        WORKUNIT_TYPE = 0x400000,
        WORKUNIT_IS_DIRTY = 0x800000,
        NUM_FLAGS = 0x19
    };

    //===================================================================================================
    // WAAPI JSon Helpers
    //===================================================================================================
    /** Returns a shared reference to a FJsonObject with the requested WAAPI FROM and TRANSFORM items. */
    static TSharedRef<FJsonObject> CreateWAAPIGetArgumentJson(WAAPIGetFromOption in_FromOption, TArray<TSharedPtr<FJsonValue>> in_FromItems,
        WAAPIGetTransformOption in_TransformOption = WAAPIGetTransformOption::NONE,
        TArray<TSharedPtr<FJsonValue>> in_TransformItems = TArray<TSharedPtr<FJsonValue>>());
    /** Returns a shared reference to a FJsonObject with the requested WAAPI RETURN options. */
    static TSharedRef<FJsonObject> CreateWAAPIGetReturnOptionsJson(AkInt64 ReturnOptions);

    static WAAPIGetReturnOptionFlag GetReturnOptionFlagValue(int in_iFlagIndex);
    /** Returns the correct string for a given WAAPI RETURN option. */
    static FString GetReturnOptionString(WAAPIGetReturnOptionFlag returnOption);
    /** Calls wwise.core.object.get with the given WAAPI FROM, RETURN, and TRANSFORM items.*/
    static bool WAAPIGet(WAAPIGetFromOption inFromField,
        TArray<TSharedPtr<FJsonValue>> inFromItems,
        AkInt64 inReturnOptionsFlags,
        TSharedPtr<FJsonObject>& outJsonResult,
        WAAPIGetTransformOption inTransformField = WAAPIGetTransformOption::NONE,
        TArray<TSharedPtr<FJsonValue>> inTransformItems = TArray<TSharedPtr<FJsonValue>>(),
        bool in_bSilenceLog = false);
    /** Searches for an object of type in_sTypeName with name in_sName via WAAPI. */
    static bool GetGUIDForObjectOfTypeWithName(FGuid& io_GUID, const FString& in_sTypeName, const FString& in_sName);
    /** Saves the Wwise project via WAAPI.*/
    static void SaveProject();

    //===================================================================================================
    // WAAPI Strings
    //===================================================================================================

    struct WAAPIStrings
    {
        static const FString BACK_SLASH;
        static const FString ID;
        static const FString RETURN;
        static const FString PATH;
        static const FString FILEPATH;
        static const FString FROM;
        static const FString NAME;
        static const FString TYPE;
        static const FString CHILDREN;
        static const FString CHILDREN_COUNT;
        static const FString ANCESTORS;
        static const FString DESCENDANTS;
        static const FString WOKUNIT_TYPE;
        static const FString FOLDER;
        static const FString PHYSICAL_FOLDER;
        static const FString SEARCH;
        static const FString PARENT;
        static const FString SELECT;
        static const FString TRANSFORM;
        static const FString OBJECT;
        static const FString OBJECTS;
        static const FString VALUE;
        static const FString COMMAND;
        static const FString TRANSPORT;
        static const FString ACTION;
        static const FString PLAY;
        static const FString STOP;
        static const FString STOPPED;
        static const FString DISPLAY_NAME;
        static const FString DELETE_ITEMS;
        static const FString DRAG_DROP_ITEMS;
        static const FString UNDO;
        static const FString REDO;
        static const FString STATE;
        static const FString OF_TYPE;
        static const FString PROJECT;
        static const FString PROPERTY;
        static const FString VOLUME;
        static const FString FIND_IN_PROJECT_EXPLORER;
        static const FString TRIMMED_DURATION;
    };

    struct WwiseTypeStrings
    {
        static const FString SOUND;
        static const FString WORKUNIT;
    };

    struct AudioPeaksStrings
    {
        struct Args
        {
            static const FString OBJECT;
            static const FString NUM_PEAKS;
            static const FString TIME_FROM;
            static const FString TIME_TO;
            static const FString CROSS_CHANNEL_PEAKS;
        };

        struct Results
        {
            static const FString PEAKS_BINARY;
            static const FString MAX_ABS_VALUE;
            static const FString PEAKS_ARRAY_LENGTH;
            static const FString PEAKS_DATA_SIZE;
        };
    };

    struct PropertyChangedStrings
    {
        struct RequiredOptions
        {
            static const FString OBJECT;
            static const FString PROPERTY;
        };
        struct OptionalOptions
        {
            static const FString RETURN;
            static const FString PLATFORM;
        };
    };

    struct AudioSourceProperties
    {
        static const FString TRIM_END;
        static const FString TRIM_BEGIN;
    };

    struct PlaybackDurationStrings
    {
        static const FString MIN;
        static const FString MAX;
        static const FString TYPE;
    };

    struct TrimValuesStrings
    {
        static const FString TRIM_BEGIN;
        static const FString TRIM_END;
    };

private:
    /**
    * Since it's a singleton WaapiClient, we  want to make sure this method (default constructor).
    * is inaccessible otherwise we may accidentally get instances of our WaapiClient singleton appearing.
    */
    FAkWaapiClient();

    /** Checks if the currently loaded Wwise project matches the project path set in AkSettings (Wwise plugin settings).
    *  NTOE: This function will block while Wwise has a modal window open. It should not be called on the Game thread.
    */
    static bool CheckProjectLoaded();

    struct FAkWaapiClientImpl* m_Impl;
};
