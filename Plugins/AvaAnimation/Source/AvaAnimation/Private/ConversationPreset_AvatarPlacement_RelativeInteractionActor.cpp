#include "ConversationPreset_AvatarPlacement_RelativeInteractionActor.h"

UConversationPreset_AvatarPlacement_RelativeInteractionActor::UConversationPreset_AvatarPlacement_RelativeInteractionActor() {
    this->AvatarPositionDirectionFromInteractionActor = 0.00f;
    this->AvatarRotationFromInteractionActor = 180.00f;
    this->CheckGroundCollision = true;
    this->CheckNavMesh = true;
    this->UseMaxHeightAngleThreshold = true;
    this->MaxHeightAngleThreshold = 22.50f;
    this->FailProximity = EConversationPreset_ProximityType::TooClose;
}

