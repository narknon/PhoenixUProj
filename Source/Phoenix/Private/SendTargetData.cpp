#include "SendTargetData.h"

USendTargetData::USendTargetData() {
    this->bShowDebug = false;
    this->bDebugShowPossibleTargets = false;
    this->SendTargetIgnoreNearDistance = 350.00f;
    this->SendAngleScale = 0.50f;
    this->SendDistanceScale = 1.00f;
    this->SendPriorityScale = 2.00f;
    this->CharacterOffsetZ = 0.00f;
    this->CollisionTargetMinVel = 500.00f;
    this->CollisionTargetHalfAngle = 90;
    this->CollisionTargetChance = 50;
}

