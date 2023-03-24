#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ELockOnReticleType.h"
#include "Templates/SubclassOf.h"
#include "Actor_LockOnReticle.generated.h"

class ABiped_PlayerController;
class UAkAudioEvent;
class ULockTargetScreenInfo;
class UUserWidget;

UCLASS(Abstract, Blueprintable)
class AActor_LockOnReticle : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimModeCircleGrowRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimModeCircleShrinkRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetingHorizontalStickAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetingVerticalStickAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FootprintRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickInnerDeadZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickOuterDeadZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxStickFlickMag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFindNewTargetWhenLockonTargetLost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReleaseTargetWhenLockonGoesInvalid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFindNewTargetFromCenterOfScreen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bScaleFootprint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinCameraDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxCameraDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinFootprintScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFootprintScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* LockOnToTargetSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* FlickToTargetSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* TargetReleasedSfx;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* TargetSwitchedWhenCurrentTargetLostSfx;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<uint32, ULockTargetScreenInfo*> LockTargetScreenInfoMap;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UUserWidget> LockOnReticleOffScreenWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickResetTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ABiped_PlayerController* BipedPlayerController;
    
public:
    AActor_LockOnReticle(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StickY(float AxisVal);
    
    UFUNCTION(BlueprintCallable)
    void StickX(float AxisVal);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLockedOn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ELockOnReticleType GetLockedOnType() const;
    
};

