#include "Conversation_AvatarSettings.h"

FConversation_AvatarSettings::FConversation_AvatarSettings() {
    this->EnableFinalPositionOverride = false;
    this->FinalPositionOverrideCheckGroundCollision = false;
    this->FinalPositionOverrideCheckNavMesh = false;
    this->PreInitInvokePlacement = NULL;
}

