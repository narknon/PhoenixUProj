#include "AblNpcReactPopupTask.h"

UAblNpcReactPopupTask::UAblNpcReactPopupTask() {
    this->bUseReactionPopupType = false;
    this->ReactPopupType = EAblNpcReactPopupTaskType::ReactionInitialVelocity;
    this->bInvertReactPopupTypeDirection = false;
    this->bConvertReactPopupTypeDirectionTo2D = false;
    this->bUseReactionVelocityIfSendTargetExists = false;
    this->bUseReactionDataMagnitude = false;
    this->bModifyGravityAtReactionEnd = false;
    this->GravityScaleAtReactionEnd = 1.00f;
}

