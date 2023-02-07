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
	UAkWaapiCalls.h
=============================================================================*/
#pragma once

#include "AkInclude.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AkWaapiUri.h"
#include "AkWaapiUtils.h"
#include "AkWaapiJsonManager.h"
#include "AkWaapiCalls.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAkWaapiCalls, Log, All);

/**
* Structure for Field Names
*/
USTRUCT(BlueprintType)
struct AKAUDIO_API FAkWaapiSubscriptionId
{
	GENERATED_USTRUCT_BODY()
	
	FAkWaapiSubscriptionId() {}
	FAkWaapiSubscriptionId(const uint64_t& SubscribId) : SubscriptionId(SubscribId){}

	mutable uint64 SubscriptionId = 0;
};

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnEventCallback, FAkWaapiSubscriptionId, SubscriptionId, FAKWaapiJsonObject, WaapiJsonObject);
DECLARE_DYNAMIC_DELEGATE(FOnWaapiProjectLoaded);
DECLARE_DYNAMIC_DELEGATE(FOnWaapiConnectionLost);

UCLASS(Within = World, config = Engine, defaultconfig)
class AKAUDIO_API UAkWaapiCalls : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()
	
    UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiCalls")
    static void SetSubscriptionID(const FAkWaapiSubscriptionId& Subscription, int id);

    UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiCalls")
    static int GetSubscriptionID(const FAkWaapiSubscriptionId& Subscription);

    /**
    * Subscribe to WAAPI project loaded event. This event will be broadcast whenever the correct Wwise project is loaded (defined by Wwise Project Path in the Wwise Plugin Settings). This should be used to initialize any resources that use WAAPI.
    *
    * @param Callback the event to call when a connection is established
    */
    UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiCalls")
    static bool RegisterWaapiProjectLoadedCallback(const FOnWaapiProjectLoaded& Callback);
    /**
    * Subscribe to WAAPI connection lost event. This event will be broadcast when the WAAPI connection is lost. This should be used to clean up any resources that use WAAPI.
    *
    * @param Callback the event to call when the connection is lost
    */
    UFUNCTION(BlueprintCallable, Category = "Audiokinetic|WaapiCalls")
    static bool RegisterWaapiConnectionLostCallback(const FOnWaapiConnectionLost& Callback);

	/**
	* Call Waapi and get/set information/parameters according to the uri chosen.
	*
	* @param WaapiUri		The	function that will be called when an event that we would be aware of happens.
	* @param WaapiArgs		The arguments referenced to the in_uri function.
	* @param WaapiOptions	Optional flag to get more information about the event happened.
	* @return out_result	A JSON object that contains useful informations about the Call process to a specific event, gets an error infos in case the Call fails.
	*/
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|WaapiCalls")
	static FAKWaapiJsonObject CallWaapi(const FAkWaapiUri& WaapiUri, const FAKWaapiJsonObject& WaapiArgs, const FAKWaapiJsonObject& WaapiOptions);

	/**
	* Allows clients to subscribe to notifications according to the event.
	*
	* @param WaapiUri			 The reference to the event that we would be aware of when it happens.
	* @param WaapiOptions		 Optional flag to get more information about the event happened.
	* @param in_callback		 A delegate to be executed during the subscription event.
	* @param out_subscriptionId	 Gets the id of this subscription.
	* @param out_result			 A boolean to ensure that the subscription was successfully done.
	* @return					 A JSON object that contains useful informations about the subscription process to a specific event, gets an error infos in case the subscription failed. 
	*/
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|WaapiCalls")
	static FAKWaapiJsonObject SubscribeToWaapi(const FAkWaapiUri& WaapiUri, const FAKWaapiJsonObject& WaapiOptions, const FOnEventCallback& CallBack, FAkWaapiSubscriptionId& SubscriptionId, bool& SubscriptionDone);

	/**
	* Unsubscribe from an event.
	*
	* @param SubscriptionId	     Gets the id of the current subscription to the event from which we want to be unsubscribed.
	* @param UnsubscriptionDone  A boolean to ensure that the unsubscription was successfully done.
	* @return					 A JSON object that contains useful informations about the unsubscription process from a specific event, gets an error infos in case the unsubscription failed. 
	*/
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "Audiokinetic|WaapiCalls")
	static FAKWaapiJsonObject Unsubscribe(const FAkWaapiSubscriptionId& SubscriptionId, bool& UnsubscriptionDone);

	/** Converts an AkWaapiSubscriptionId value to a string */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToString (FAkWaapiSubscriptionId)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|String")
	static FString Conv_FAkWaapiSubscriptionIdToString(const FAkWaapiSubscriptionId& INAkWaapiSubscriptionId);

	/** Converts an AkWaapiSubscriptionId value to a localizable text */
	UFUNCTION(BlueprintPure, meta = (DisplayName = "ToText (FAkWaapiSubscriptionId)", CompactNodeTitle = "->", BlueprintAutocast), Category = "Utilities|Text")
	static FText Conv_FAkWaapiSubscriptionIdToText(const FAkWaapiSubscriptionId& INAkWaapiSubscriptionId);
};