#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "AncientMagicHotSpot_OnCancelledDelegate.h"
#include "AncientMagicHotSpot_OnCompletedDelegate.h"
#include "AncientMagicHotSpot_OnEndedDelegate.h"
#include "Biped_Interact_Interface.h"
#include "AncientMagicHotSpot.generated.h"

class ABiped_Player;
class UBTService_AvaAITree;
class UCognitionStimuliSourceComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UObject;

UCLASS(Blueprintable)
class AAncientMagicHotSpot : public AActor, public IBiped_Interact_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugDraw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HotSpotHeightAllowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterRadiusMaxAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterRadiusActiveMaxAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOuterAngleUseCameraFacing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterAngleRatioInterpToSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterAngleRatioInterpOutSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinOuterAngleRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinOuterRadiusRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInsideOuterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInsideCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerRadiusMaxAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInnerAngleUseCameraFacing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerAngleRatioInterpToSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerAngleRatioInterpOutSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InnerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExitInnerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinInnerAngleRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinInnerRadiusRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInsideInnerRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HotSpotRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HotSpotRumbleDeadZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInsideHotSpotRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDiscoverAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHotSpotActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTriggerAOEMunition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumberOfUses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Cooldown;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAncientMagicHotSpot_OnCompleted OnCompletedDelagate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAncientMagicHotSpot_OnCancelled OnCancelledDelagate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAncientMagicHotSpot_OnEnded OnEndedDelagate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CognitionStimuliSourceComponent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ABiped_Player> PlayerActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* VFXPulseComponent;
    
    AAncientMagicHotSpot();
    UFUNCTION(BlueprintCallable)
    void UpdateVFX(float AngleRatio, float DistanceRatio);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateOuterRadius(float AngleRatio, float DistanceRatio);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateInnerRadius(float AngleRatio, float Ratio);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateHotSpotRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateHotSpot();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UnHide();
    
    UFUNCTION(BlueprintCallable)
    void TrackFootPlants();
    
    UFUNCTION(BlueprintCallable)
    void StopTrackingFootPlants();
    
    UFUNCTION(BlueprintCallable)
    void StartVFX(UNiagaraSystem* InAsset);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Reactivate();
    
    UFUNCTION(BlueprintCallable)
    void PlayerIsInHotSpot(AActor* InPlayerActor, bool bInHotSpot);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NovaComplete();
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void LogList(const TArray<AActor*>& LogActorList, const FString& HeaderInfo, const FString& PerActorInfo, const FString& PerActorExtraInfo) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void Log(const FString& Info, const UObject* LogObjectName, const FString& ExtraInfo) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsHotspotBeingForcedActive();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Interact(UBTService_AvaAITree* AvaService);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HotSpotWasForcedInactive();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HotSpotWasForcedActive();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HideRevealOBJ();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void HideHideOBJ();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void GetLoggingIsEnabled(bool& bLoggingIsEnabled);
    
    UFUNCTION(BlueprintCallable)
    void ForceDeactivateHotSpot();
    
    UFUNCTION(BlueprintCallable)
    void ForceActivateHotSpot(AActor* InPlayerActor, float InRadiiMultiplier, float InHeightMultiplier);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FootPlantOccurred(FVector FootLocation, FRotator FootRotator);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void FireWand();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitedOuterRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitedInnerRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitedHotSpotRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnteredOuterRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnteredInnerRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnteredHotSpotRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void EnableInteract();
    
    UFUNCTION(BlueprintCallable)
    void Done(bool NewDeactivateHotSpot);
    
    UFUNCTION(BlueprintCallable)
    void DestroyVFX();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DeactivateHotSpot();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ActivateHotSpot();
    
    
    // Fix for true pure virtual functions not being implemented
};

