#include "ablCentaurSpawnMunitionTask.h"

UablCentaurSpawnMunitionTask::UablCentaurSpawnMunitionTask() {
    this->EquipArrowClass = NULL;
    this->MunitionClass = NULL;
    this->MunitionSocketOffsetX = 80.00f;
    this->BlackboardTargetActorKeyName = TEXT("TargetActor");
    this->bTrackTargetLocation = false;
}

