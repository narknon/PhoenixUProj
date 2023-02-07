#include "AblBranchConditionTargetTracker_AnyValidTargets.h"

UAblBranchConditionTargetTracker_AnyValidTargets::UAblBranchConditionTargetTracker_AnyValidTargets() {
    this->UseTracker = EUseTargetTracker::Facing;
    this->bReturnTrueIfTargetListEmptyThisFrame = false;
    this->MatchTargetID = ETargetID::None;
    this->MatchTargetType = ETargetType::None;
}

