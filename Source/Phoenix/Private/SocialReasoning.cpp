#include "SocialReasoning.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTCustomComponent.h"

class AActor;
class APawn;
class UObject;

FGreetingQueryData ASocialReasoning::WhomShallIGreet(const TArray<AActor*>& PotentialGreetees, float& Score) {
    return FGreetingQueryData{};
}

FGreetingQueryData ASocialReasoning::WhomShallIAccompany(const TArray<AActor*>& PotentialAccompaniers, float& Score) {
    return FGreetingQueryData{};
}

bool ASocialReasoning::TriggerSoloActionOnActor(AActor* InTargetActor, TEnumAsByte<SocialActionTypes> Story, TEnumAsByte<SocialSemanticIDs> Emotion, AActor* FocusActor) {
    return false;
}

bool ASocialReasoning::TriggerSoloAction(TEnumAsByte<SocialActionTypes> Story, TEnumAsByte<SocialSemanticIDs> Emotion, AActor* FocusActor) {
    return false;
}

void ASocialReasoning::SuppressGreetingGhostStoriesOnActor(AActor* InTargetActor, bool InShouldSuppress, UObject* InCaller) {
}

void ASocialReasoning::SuppressGreetingGhostStories(bool InShouldSuppress) {
}

void ASocialReasoning::StartSettingGhostStoryInterestFactor(float InInterestLevel, EStandardManagedPriority InPriority, UObject* InCaller) {
}

void ASocialReasoning::StartActivateLookAtTrigger(bool inActivate, EStandardManagedPriority InPriority, FName InReason) {
}

void ASocialReasoning::SetGhostStoryInterestFactor(float inInterestFactor) {
}

bool ASocialReasoning::SelectGhostStoryPartners(const TArray<AActor*>& PotentialPartners, TArray<AActor*>& AvailablePartners) {
    return false;
}

void ASocialReasoning::NoStationsFound() {
}

bool ASocialReasoning::MonitorTheAccompaniment(float LeashLength) {
    return false;
}

bool ASocialReasoning::JoinStation(const FStationQueryData& StationData, float Duration, bool OverwritePreviousGoal) {
    return false;
}

void ASocialReasoning::Greet(const FGreetingQueryData& TheGreeting) {
}

bool ASocialReasoning::GetUseOptimizedEQS() {
    return false;
}

APawn* ASocialReasoning::GetReasonerPawn() const {
    return NULL;
}

FName ASocialReasoning::GetReasonerName() {
    return NAME_None;
}

FName ASocialReasoning::GetReasonerDisplayName() {
    return NAME_None;
}

UObject* ASocialReasoning::GetReasoner() const {
    return NULL;
}

void ASocialReasoning::GetFreeTimeMinMaxStationChangeTime(float& outMinTime, float& outMaxTime) {
}

FGameplayTag ASocialReasoning::GetDesiredBehavior() {
    return FGameplayTag{};
}

FGameplayTag ASocialReasoning::GetCurrentBehavior() {
    return FGameplayTag{};
}

void ASocialReasoning::FinishSettingGhostStoryInterestFactor(EStandardManagedPriority InPriority, UObject* InCaller) {
}

void ASocialReasoning::FinishActivateLookAtTrigger(EStandardManagedPriority InPriority, FName InReason) {
}

void ASocialReasoning::EndTheGhostStory() {
}

bool ASocialReasoning::CreateSocialInteractionForChat(const FStationQueryData& ProvidedStationData, TEnumAsByte<ESpawnedStationTypes> SpawnedStationType, float TimeAvailable, bool IsDynamic) {
    return false;
}

bool ASocialReasoning::CreateSocialInteraction(int32 MinimumInteractors, const FStationQueryData& ProvidedStationData, TEnumAsByte<ESpawnedStationTypes> SpawnedStationType, float TimeAvailable, bool IsDynamic) {
    return false;
}

bool ASocialReasoning::AvailableToTellAGhostStory() {
    return false;
}

void ASocialReasoning::AbandonTheGhostStory() {
}

ASocialReasoning::ASocialReasoning(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Mind = CreateDefaultSubobject<UBTCustomComponent>(TEXT("Mind"));
    this->Memory = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Memory"));
    this->StoryTeller = NULL;
    this->PatrolWaitTime = 0.00f;
}

