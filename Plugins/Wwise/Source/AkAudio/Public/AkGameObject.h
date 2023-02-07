#pragma once
#include "CoreMinimal.h"
#include "Engine/LatentActionManager.h"
#include "Components/SceneComponent.h"
#include "AkExternalSourceInfo.h"
#include "ERTPCValueType.h"
#include "OnAkPostEventCallbackDelegate.h"
#include "AkGameObject.generated.h"

class UAkAudioEvent;
class UAkRtpc;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class AKAUDIO_API UAkGameObject : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* AkAudioEvent;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EventName;
    
    UAkGameObject();
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    void Stop();
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintPure=false)
    void SetRTPCValue(UAkRtpc* RTPCValue, float Value, int32 InterpolationTimeMs, const FString& RTPC) const;
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(Latent, LatentInfo="LatentInfo", WorldContext="WorldContextObject"))
    void PostAssociatedAkEventAsync(const UObject* WorldContextObject, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo, int32& PlayingID);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    int32 PostAssociatedAkEvent(int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    int32 PostAkEventWithStartTime(UAkAudioEvent* AkEvent, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources, const FString& in_EventName, float StartTime);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, meta=(Latent, LatentInfo="LatentInfo", WorldContext="WorldContextObject"))
    void PostAkEventAsync(const UObject* WorldContextObject, UAkAudioEvent* AkEvent, int32& PlayingID, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic)
    int32 PostAkEvent(UAkAudioEvent* AkEvent, int32 CallbackMask, const FOnAkPostEventCallback& PostEventCallback, const TArray<FAkExternalSourceInfo>& ExternalSources, const FString& in_EventName);
    
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, BlueprintPure)
    void GetRTPCValue(UAkRtpc* RTPCValue, ERTPCValueType InputValueType, float& Value, ERTPCValueType& OutputValueType, const FString& RTPC, int32 PlayingID) const;
    
};

