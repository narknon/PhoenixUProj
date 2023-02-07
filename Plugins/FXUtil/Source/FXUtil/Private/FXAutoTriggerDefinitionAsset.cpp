#include "FXAutoTriggerDefinitionAsset.h"

UFXAutoTriggerDefinitionAsset::UFXAutoTriggerDefinitionAsset() {
    this->Prerequisite = NULL;
    this->RequiredActors = NULL;
    this->TriggerCondition = NULL;
    this->SleepWhenFinishingImmediately = 150;
    this->SleepWhenStartFails = 300;
}

