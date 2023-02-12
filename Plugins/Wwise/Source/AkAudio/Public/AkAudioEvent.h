#pragma once
#include "CoreMinimal.h"
#include "AkAssetBase.h"
#include "AkAudioEvent.generated.h"

class UAkAssetPlatformData;
class UAkAudioBank;

UCLASS(Blueprintable)
class AKAUDIO_API UAkAudioEvent : public UAkAssetBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FString, UAkAssetPlatformData*> LocalizedPlatformAssetDataMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioBank* RequiredBank;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAkAssetPlatformData* CurrentLocalizedPlatformData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAttenuationRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsInfinite;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumDuration;
    
public:
    UAkAudioEvent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMinimumDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaximumDuration() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMaxAttenuationRadius() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsInfinite() const;
    
};

