#include "PerformTasksForAI.h"
#include "Components/BoxComponent.h"

class AActor;
class APerformTasksForAI;
class UPrimitiveComponent;
class UScheduledEntity;

void APerformTasksForAI::SwitchOnBPImplementation() {
}

void APerformTasksForAI::SetScheduledEntity(UScheduledEntity* InAI_ScheduledEntity) {
}

void APerformTasksForAI::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void APerformTasksForAI::OnFleshLoadComplete(AActor* FleshActor) {
}

void APerformTasksForAI::HardExecuteStartPerformTasksForAI() {
}

FAIPerformTaskContainer APerformTasksForAI::GetTaskAtIndex(const int32 TaskIndex) const {
    return FAIPerformTaskContainer{};
}

UScheduledEntity* APerformTasksForAI::GetScheduledEntity() {
    return NULL;
}

void APerformTasksForAI::ForceFinishCurrentTask() {
}

void APerformTasksForAI::FinishPerformTaskTriggerBP() {
}

TArray<APerformTasksForAI*> APerformTasksForAI::FindMissionActors(const FName InMissionID, const int32 InMissionUID) {
    return TArray<APerformTasksForAI*>();
}

void APerformTasksForAI::ExecuteStartPerformTasksForAI() {
}

void APerformTasksForAI::ClearScheduledEntity() {
}

void APerformTasksForAI::CleanUpAndStartNextPerformTask(UScheduledEntity* ScheduledEntity, int32 ActivityTypeBits) {
}



APerformTasksForAI::APerformTasksForAI() {
    this->PerformTaskContainerType = EPerformTaskContainerType::LeadingPlayer;
    this->bStartOff = false;
    this->bAutoActivate = false;
    this->bAlwaysActive = false;
    this->bCanActivateAgainWhenUnfinished = false;
    this->bLumosOn = false;
    this->ApparateInAblAbility = NULL;
    this->ApparateOutAblAbility = NULL;
    this->JumpDownAbilityPtr = NULL;
    this->MissionUID = 0;
    this->bReleaseOnCompletion = true;
    this->ClearedDialogueEvent = NULL;
    this->clearedAudioDelay = 0.00f;
    this->NextTask = NULL;
    this->Scene = NULL;
    this->Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxTrigger"));
    this->SphereTrigger = NULL;
    this->TextRenderer = NULL;
    this->FirstDelay = 0.00f;
    this->bShowAxisInGame = false;
}

