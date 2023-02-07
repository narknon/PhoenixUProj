#include "ConversationPreset_AvatarPlacement_Preexisting.h"

UConversationPreset_AvatarPlacement_Preexisting::UConversationPreset_AvatarPlacement_Preexisting() {
    this->Proximity = EConversationPreset_ProximityType::Ideal;
    this->RotateInteractionActorToAvatar = false;
    this->InteractionActorRotationOffset = 0.00f;
    this->RotateActorToInteractionActor = false;
    this->AvatarRotationOffset = 0.00f;
}

