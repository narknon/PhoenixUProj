#include "AblPhysicalReactionCOMVelocityTask.h"

UAblPhysicalReactionCOMVelocityTask::UAblPhysicalReactionCOMVelocityTask() {
    this->VelocitySource = EAblNpcReactCapsuleImpulseVelocitySource::InstigatorRight;
    this->Magnitude = 360.00f;
    this->Angle = 0.00f;
}

