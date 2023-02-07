#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "DialogueConversationReference.h"
#include "ERaceType.h"
#include "RacerTime.h"
#include "Race.generated.h"

class AFlyingBroom;
class ARaceGate;
class ARaceGhostOrb;
class UInventoryItemToolRecord;
class UObject;
class UPopupScreen;
class USceneComponent;
class USplineComponent;
class UWorld;

UCLASS(Abstract, Blueprintable)
class ARace : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USplineComponent* SplineComponent;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* TrackGatesParent;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* EndGateParent;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ARaceGate*> SpawnedGates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ARaceGate> RaceRingClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ARaceGate> EndGateClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ARaceGhostOrb> GhostOrbClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<ARaceGhostOrb> SpawnedGhostOrb;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AFlyingBroom> PlayerBroom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CountdownTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TimePenaltySeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepPlayerCloseToSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxDistanceFromSpline;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxDistancePastRing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StoryModeRaceAttempts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERaceType RaceType;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo RaceId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo FastTravelLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> LevelToLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogueConversationReference> GateSuccessDialogueEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GateSuccessDialoguePercentageChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GateSuccessDialogueCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogueConversationReference> GateMissDialogueEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GateMissDialoguePercentageChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GateMissDialogueCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogueConversationReference> TurboBubbleDialogueEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurboBubbleDialoguePercentageChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurboBubbleDialogueCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogueConversationReference> WinRaceDialogueEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDialogueConversationReference> LoseRaceDialogueEvents;
    
public:
    ARace();
    UFUNCTION(BlueprintCallable)
    void RaceHudDismissed();
    
    UFUNCTION(BlueprintCallable)
    void OnStoryModeSkipScreenDismissed(UPopupScreen* Popup, int32 ConfirmationResult);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRaceStart();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRaceFinish();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRaceAbandoned();
    
public:
    UFUNCTION(BlueprintCallable)
    void OnEndOfRaceFTComplete();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnCollectTurboBubble(const UObject* i_caller);
    
public:
    UFUNCTION(BlueprintCallable)
    void ItemToolLoadedCallback(UInventoryItemToolRecord* ToolRecord);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsRaceMissionActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNewBestTime();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetTotalRaceTime(const TArray<float>& Times);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTotalPenaltyTime() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeElapsed() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetRacerBestTime(const FName InRacerName, const bool bMissionRelevant, float& OutBestTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetRaceID();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AFlyingBroom* GetPlayerBroom();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumberOfGates() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetGatePrevBestTime(const int32 GateNumber);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetBestRacer_Blueprint(const bool bMissionRelevant, float& OutBestTime);
    
    UFUNCTION(BlueprintCallable)
    TArray<FRacerTime> GetAllRacerTimes(bool bMissionRelevant);
    
};

