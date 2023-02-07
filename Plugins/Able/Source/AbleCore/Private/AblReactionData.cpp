#include "AblReactionData.h"

class AActor;

bool UAblReactionData::IsPassive() const {
    return false;
}

AActor* UAblReactionData::GetTarget() {
    return NULL;
}

AActor* UAblReactionData::GetInstigator() {
    return NULL;
}

FName UAblReactionData::GetChannelName() const {
    return NAME_None;
}

UAblReactionData::UAblReactionData() {
    this->bDestroyEffectComponentOnReactionEnd = true;
}

