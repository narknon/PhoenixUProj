#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EMountErrorMessages.h"
#include "ENoMountZoneError.h"
#include "PlayerMountOverlapManager.generated.h"

class UPlayerMountOverlapManager;

UCLASS(Blueprintable, NotPlaceable)
class UPlayerMountOverlapManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ENoMountZoneError, FName> NoMountZoneErrors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EMountErrorMessages, FName> MountErrors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedUpUnavailableMessageTimeout;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LandingUnavailableMessageTimeout;
    
public:
    UPlayerMountOverlapManager();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInsideFacingEntry(bool bDraw) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTimeInNoMountZone(float& Time);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetInNoMountZone() const;
    
    UFUNCTION(BlueprintCallable)
    static UPlayerMountOverlapManager* Get();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanSpeedUp() const;
    
};

