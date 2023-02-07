#include "BTT_Camera_ReplaceBehavior.h"

UBTT_Camera_ReplaceBehavior::UBTT_Camera_ReplaceBehavior() {
    this->BehaviorClass = NULL;
    this->BlendInDuration = 0.00f;
    this->BlendOutDuration = 0.00f;
    this->BlendOutPredecessorDuration = 0.00f;
    this->BlendInPredecessorDuration = 0.00f;
    this->PredecessorSorting = ECameraStackBehaviorSorting::Oldest;
    this->FilterFlags = 0;
    this->bRemovePredecessor = false;
}

