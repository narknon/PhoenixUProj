#include "TimeRig.h"

UTimeRig::UTimeRig() {
    this->InitializingBehavior = ETimeRigInitializingBehavior::UseSRSettings;
    this->RandomSeed = 0;
    this->StoryGraph = NULL;
}

