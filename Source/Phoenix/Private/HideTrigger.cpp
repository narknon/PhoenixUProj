#include "HideTrigger.h"
#include "OdcObstacleComponent.h"

class AActor;

void AHideTrigger::OnEndAggroActorOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void AHideTrigger::OnEndActorOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void AHideTrigger::OnBeginAggroActorOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void AHideTrigger::OnBeginActorOverlap(AActor* SelfActor, AActor* OtherActor) {
}

void AHideTrigger::Deactivate(bool bInFromEndPlay) {
}

void AHideTrigger::Activate() {
}

AHideTrigger::AHideTrigger() {
    this->HideFlags = 0;
    this->PauseScheduleFlags = 0;
    this->bStartActive = true;
    this->bExcludeCompanions = true;
    this->bShutdownExternalNpcs = false;
    this->DynamicObstacleShape = EDynamicObstacleShape::SHAPE_NONE;
    this->DynamicObstacle = NULL;
    this->NumHideFlags = 0;
    this->NavObstacle = CreateDefaultSubobject<UOdcObstacleComponent>(TEXT("NavObstacle"));
    this->NavigationDisruptor = NULL;
}

