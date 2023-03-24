#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Biped_Interact_Interface.h"
#include "FieldGuideHotSpot_OnCancelledDelegate.h"
#include "FieldGuideHotSpot_OnCompletedDelegate.h"
#include "FieldGuideHotSpot_OnEndedDelegate.h"
#include "RevealInterface.h"
#include "FieldGuideHotSpot.generated.h"

class ABiped_Player;
class UBTService_AvaAITree;
class UCognitionStimuliSourceComponent;
class UNiagaraComponent;
class UNiagaraSystem;

UCLASS(Blueprintable)
class AFieldGuideHotSpot : public AActor, public IBiped_Interact_Interface, public IRevealInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebugDraw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HotSpotHeightAllowed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OuterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinOuterRadiusRatio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInsideOuterRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInsideCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HotSpotRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HotSpotRumbleDeadZone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInsideHotSpotRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHotSpotActive;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFieldGuideHotSpot_OnCompleted OnCompletedDelagate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFieldGuideHotSpot_OnCancelled OnCancelledDelagate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFieldGuideHotSpot_OnEnded OnEndedDelagate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCognitionStimuliSourceComponent* CognitionStimuliSourceComponent;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ABiped_Player> PlayerActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* VFXPulseComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPageCollected;
    
    AFieldGuideHotSpot(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UpdateVFX(float AngleRatio, float DistanceRatio);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateOuterRadius(float AngleRatio, float DistanceRatio);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateHotSpotRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateHotSpot();
    
    UFUNCTION(BlueprintCallable)
    void StartVFX(UNiagaraSystem* InAsset);
    
    UFUNCTION(BlueprintCallable)
    void SetRevealed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RevealedByRevelio();
    
    UFUNCTION(BlueprintCallable)
    void PlayerIsInHotSpot(AActor* InPlayerActor, bool bInHotSpot);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PageCollected();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void NovaComplete();
    
    UFUNCTION(BlueprintCallable)
    void Log(const FString& InLogString);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRevealed() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Interact(UBTService_AvaAITree* AvaService);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HintedByRevelio(const bool bWasHintedAt);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitedOuterRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ExitedHotSpotRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnteredOuterRadius();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void EnteredHotSpotRadius();
    
    UFUNCTION(BlueprintCallable)
    void DestroyVFX();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DeactivateHotSpot();
    
    UFUNCTION(BlueprintCallable)
    void ClearRevealed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ActivateHotSpot();
    
    
    // Fix for true pure virtual functions not being implemented
};

