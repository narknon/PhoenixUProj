#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "ECreatureMovementSpeed.h"
#include "EMountFlyingGait.h"
#include "EMountFlyingSpeedLimit.h"
#include "EMountGroundSpeedLimit.h"
#include "MountZoneVolumeBase.h"
#include "MountSpeedLimitVolume.generated.h"

class AActor;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class AMountSpeedLimitVolume : public AMountZoneVolumeBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnforceGroundGait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMountGroundSpeedLimit GroundGaitLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECreatureMovementSpeed EnforcedGroundGait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnforceFlyingGait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMountFlyingSpeedLimit FlyingGaitLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMountFlyingGait EnforcedFlyingGait;
    
public:
    AMountSpeedLimitVolume(const FObjectInitializer& ObjectInitializer);
protected:
    UFUNCTION(BlueprintCallable)
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
};

