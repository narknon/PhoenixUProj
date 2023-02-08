#pragma once
#include "CoreMinimal.h"
#include "DbSingleColumnInfo.h"
#include "GameFramework/Actor.h"
#include "Engine/EngineTypes.h"
#include "AIPerformTaskContainer.h"
#include "AvaAudioDialogueEvent.h"
#include "DialogueConversationReference.h"
#include "EPerformTaskContainerType.h"
#include "PerformTriggerTaskCompleteBPDelegate.h"
#include "Templates/SubclassOf.h"
#include "WholePerformTaskTriggerCompleteDelegate.h"
#include "WholePerformTaskTriggerStartDelegate.h"
#include "PerformTasksForAI.generated.h"

class APerformTasksForAI;
class UAblAbility;

class UBoxComponent;
class UObject;
class UPrimitiveComponent;
class USceneComponent;
class UScheduledEntity;
class USpellToolRecord;
class USphereComponent;
class UTextRenderComponent;

UCLASS(Blueprintable)
class PHOENIX_API APerformTasksForAI : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo NPCKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPerformTaskContainerType PerformTaskContainerType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LevelOwnerName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAIPerformTaskContainer> TasksToBePerformedContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartOff;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoActivate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAlwaysActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCanActivateAgainWhenUnfinished;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLumosOn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ApparateInAblAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> ApparateOutAblAbility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> JumpDownAbilityPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo m_missionID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MissionUID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bReleaseOnCompletion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDialogueConversationReference ClearedDialogueReference;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAvaAudioDialogueEvent* ClearedDialogueEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float clearedAudioDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APerformTasksForAI* NextTask;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> OffTargets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Scene;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* Trigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* SphereTrigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextRenderComponent* TextRenderer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FirstDelay;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformTriggerTaskCompleteBP OnPerformTriggerTaskCompleteBP;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWholePerformTaskTriggerStart OnWholePerformTaskTriggerStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWholePerformTaskTriggerComplete OnWholePerformTaskTriggerComplete;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowAxisInGame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USpellToolRecord*> SpellToolRecords;
    
    APerformTasksForAI();
    UFUNCTION(BlueprintCallable)
    void SwitchOnBPImplementation();
    
    UFUNCTION(BlueprintCallable)
    void SetScheduledEntity(UScheduledEntity* InAI_ScheduledEntity);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    
    UFUNCTION(BlueprintCallable)
    void OnFleshLoadComplete(AActor* FleshActor);
    
public:
    UFUNCTION(BlueprintCallable)
    void HardExecuteStartPerformTasksForAI();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FAIPerformTaskContainer GetTaskAtIndex(const int32 TaskIndex) const;
    
    UFUNCTION(BlueprintCallable)
    UScheduledEntity* GetScheduledEntity();
    
    UFUNCTION(BlueprintCallable)
    void ForceFinishCurrentTask();
    
    UFUNCTION(BlueprintCallable)
    void FinishPerformTaskTriggerBP();
    
    UFUNCTION(BlueprintCallable)
    static TArray<APerformTasksForAI*> FindMissionActors(const FName InMissionID, const int32 InMissionUID);
    
    UFUNCTION(BlueprintCallable)
    void ExecuteStartPerformTasksForAI();
    
    UFUNCTION(BlueprintCallable)
    void ClearScheduledEntity();
    
private:
    UFUNCTION(BlueprintCallable)
    void CleanUpAndStartNextPerformTask(UScheduledEntity* ScheduledEntity, int32 ActivityTypeBits);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CallSwitchOnBP(UObject* InTarget);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void CallSwitchOffBP(UObject* InTarget);
    
};

