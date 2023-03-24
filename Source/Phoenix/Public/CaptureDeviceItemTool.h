#pragma once
#include "CoreMinimal.h"
#include "ETargetSpeedMode.h"
#include "GameplayTagContainer.h"
#include "ECaptureState.h"
#include "InventoryItemTool.h"
#include "Templates/SubclassOf.h"
#include "CaptureDeviceItemTool.generated.h"

class AActor;
class ABiped_Player;
class UAkAudioEvent;
class UCapturingWidget;
class USkinnedMeshComponent;

UCLASS(Blueprintable)
class ACaptureDeviceItemTool : public AInventoryItemTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCapturingWidget> WidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionNoiseEventLoudness;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerceptionNoiseEventMaxRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TriggersSight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TriggersHearing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ETargetSpeedMode::Type> UsingToolSpeedMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GracePeriodTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* BeastCapture_MusicStartEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* BeastCapture_MusicStopEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* BeastCapture_SuccessStingerEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ReactionTagContainer;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECaptureState CurrentCaptureState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ABiped_Player* BipedPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurrentDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCapturingWidget* CaptureWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableIntermediateGates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FName> LargeTargetTypeNames;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OutOfRangeTutorialStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OutOfRangeTutorial;
    
public:
    ACaptureDeviceItemTool(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void PlayCaptureStinger() const;
    
    UFUNCTION(BlueprintCallable)
    void OnConfirmCapture();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCompletedGate(bool bIsFinalGate);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnCaptureStateChanged(ECaptureState PreviousState, ECaptureState NewState);
    
public:
    UFUNCTION(BlueprintCallable)
    void OnCancelCapture();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTargetConsideredLarge() const;
    
    UFUNCTION(BlueprintCallable)
    void InvalidateCachedMeshBounds(USkinnedMeshComponent* InMeshComponent);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTotalNumGates() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetTargetActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    float GetProgressTowardNextGate() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumGatesPassed() const;
    
    UFUNCTION(BlueprintCallable)
    float GetMaxCapturingDistance();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsGateActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    float GetCapturingProgress() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void FinishSucceeding();
    
    UFUNCTION(BlueprintCallable)
    void FinishCancelling();
    
public:
    UFUNCTION(BlueprintCallable)
    void BeginCapturing();
    
};

