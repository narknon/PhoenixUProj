#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "EStandardManagedPriority.h"
#include "AmendSocapDetails.h"
#include "ChatDelegateDelegate.h"
#include "CombatDelegateDelegate.h"
#include "CompanionshipDelegateDelegate.h"
#include "ESpawnedStationTypes.h"
#include "GhostStoryEndedDelegateDelegate.h"
#include "GreetingQueryData.h"
#include "InteractionCallbackDelegateDelegate.h"
#include "PerformTask_MoveToLocationDelegate.h"
#include "PerformTask_MoveToStationDelegate.h"
#include "PerformTask_WaitForPlayerDelegate.h"
#include "PlayerHasGreetedMeDelegateDelegate.h"
#include "PlayerSightedDelegateDelegate.h"
#include "RunEQS_FinishedDelegateDelegate.h"
#include "SocialActionTypes.h"
#include "SocialSemanticIDs.h"
#include "StationQueryData.h"
#include "StoryDirector_Interface.h"
#include "ThinkDelegateDelegate.h"
#include "SocialReasoning.generated.h"

class AFocusTrigger;
class APawn;
class UBTCustomComponent;
class UBlackboardComponent;
class UObject;
class UStoryTeller;

UCLASS(Blueprintable)
class ASocialReasoning : public AActor, public IStoryDirector_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAmendSocapDetails SocialCapitalDetails;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerHasGreetedMeDelegate PlayerHasGreetedMeDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBTCustomComponent* Mind;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBlackboardComponent* Memory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FThinkDelegate ThinkDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChatDelegate ChatDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCombatDelegate CombatDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCompanionshipDelegate CompanionshipDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformTask_WaitForPlayer PerformTask_WaitForPlayerDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformTask_MoveToLocation PerformTask_MoveToLocationDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPerformTask_MoveToStation PerformTask_MoveToStationDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerSightedDelegate PlayerSightedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRunEQS_FinishedDelegate RunEQS_FindStationsDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRunEQS_FinishedDelegate RunEQS_FindSocialReasoningsDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractionCallbackDelegate InteractionCallbackDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGhostStoryEndedDelegate GhostStoryEndedDelegate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStoryTeller* StoryTeller;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PatrolWaitTime;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AFocusTrigger> LookAtMe;
    
    ASocialReasoning(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    FGreetingQueryData WhomShallIGreet(const TArray<AActor*>& PotentialGreetees, float& Score);
    
    UFUNCTION(BlueprintCallable)
    FGreetingQueryData WhomShallIAccompany(const TArray<AActor*>& PotentialAccompaniers, float& Score);
    
    UFUNCTION(BlueprintCallable)
    static bool TriggerSoloActionOnActor(AActor* InTargetActor, TEnumAsByte<SocialActionTypes> Story, TEnumAsByte<SocialSemanticIDs> Emotion, AActor* FocusActor);
    
    UFUNCTION(BlueprintCallable)
    bool TriggerSoloAction(TEnumAsByte<SocialActionTypes> Story, TEnumAsByte<SocialSemanticIDs> Emotion, AActor* FocusActor);
    
    UFUNCTION(BlueprintCallable)
    static void SuppressGreetingGhostStoriesOnActor(AActor* InTargetActor, bool InShouldSuppress, UObject* InCaller);
    
    UFUNCTION(BlueprintCallable)
    void SuppressGreetingGhostStories(bool InShouldSuppress);
    
    UFUNCTION(BlueprintCallable)
    void StartSettingGhostStoryInterestFactor(float InInterestLevel, EStandardManagedPriority InPriority, UObject* InCaller);
    
    UFUNCTION(BlueprintCallable)
    void StartActivateLookAtTrigger(bool inActivate, EStandardManagedPriority InPriority, FName InReason);
    
    UFUNCTION(BlueprintCallable)
    void SetGhostStoryInterestFactor(float inInterestFactor);
    
    UFUNCTION(BlueprintCallable)
    bool SelectGhostStoryPartners(const TArray<AActor*>& PotentialPartners, TArray<AActor*>& AvailablePartners);
    
    UFUNCTION(BlueprintCallable)
    void NoStationsFound();
    
    UFUNCTION(BlueprintCallable)
    bool MonitorTheAccompaniment(float LeashLength);
    
    UFUNCTION(BlueprintCallable)
    bool JoinStation(const FStationQueryData& StationData, float Duration, bool OverwritePreviousGoal);
    
    UFUNCTION(BlueprintCallable)
    void Greet(const FGreetingQueryData& TheGreeting);
    
    UFUNCTION(BlueprintCallable)
    bool GetUseOptimizedEQS();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APawn* GetReasonerPawn() const;
    
    UFUNCTION(BlueprintCallable)
    FName GetReasonerName();
    
    UFUNCTION(BlueprintCallable)
    FName GetReasonerDisplayName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetReasoner() const;
    
    UFUNCTION(BlueprintCallable)
    void GetFreeTimeMinMaxStationChangeTime(float& outMinTime, float& outMaxTime);
    
    UFUNCTION(BlueprintCallable)
    FGameplayTag GetDesiredBehavior();
    
    UFUNCTION(BlueprintCallable)
    FGameplayTag GetCurrentBehavior();
    
    UFUNCTION(BlueprintCallable)
    void FinishSettingGhostStoryInterestFactor(EStandardManagedPriority InPriority, UObject* InCaller);
    
    UFUNCTION(BlueprintCallable)
    void FinishActivateLookAtTrigger(EStandardManagedPriority InPriority, FName InReason);
    
    UFUNCTION(BlueprintCallable)
    void EndTheGhostStory();
    
    UFUNCTION(BlueprintCallable)
    bool CreateSocialInteractionForChat(const FStationQueryData& ProvidedStationData, TEnumAsByte<ESpawnedStationTypes> SpawnedStationType, float TimeAvailable, bool IsDynamic);
    
    UFUNCTION(BlueprintCallable)
    bool CreateSocialInteraction(int32 MinimumInteractors, const FStationQueryData& ProvidedStationData, TEnumAsByte<ESpawnedStationTypes> SpawnedStationType, float TimeAvailable, bool IsDynamic);
    
    UFUNCTION(BlueprintCallable)
    bool AvailableToTellAGhostStory();
    
    UFUNCTION(BlueprintCallable)
    void AbandonTheGhostStory();
    
    
    // Fix for true pure virtual functions not being implemented
};

