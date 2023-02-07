#include "AblNPC_PhysicalReactionCOMVelocityTask.h"

UAblNPC_PhysicalReactionCOMVelocityTask::UAblNPC_PhysicalReactionCOMVelocityTask() {
    this->VelocitySource = EAblNpcReactCapsuleImpulseVelocitySource::InstigatorRight;
    this->Magnitude = 360.00f;
    this->Angle = 0.00f;
}

