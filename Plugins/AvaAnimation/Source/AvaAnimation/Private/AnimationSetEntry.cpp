#include "AnimationSetEntry.h"

FAnimationSetEntry::FAnimationSetEntry() {
    this->AnimationAsset = NULL;
    this->InWorldStatus = INWORLD_UNTESTED;
    this->bSelectedForNextUse = false;
}

