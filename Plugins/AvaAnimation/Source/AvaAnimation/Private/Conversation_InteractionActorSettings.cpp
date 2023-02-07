#include "Conversation_InteractionActorSettings.h"

FConversation_InteractionActorSettings::FConversation_InteractionActorSettings() {
    this->EnableInitialPositionOverride = false;
    this->InitialPositionOverrideCheckGroundCollision = false;
    this->InitialPositionOverrideCheckNavMesh = false;
    this->EnableInitialPositionFromStationSockets = false;
    this->InitialPositionFromStationSocketsCheckGroundCollision = false;
    this->InitialPositionFromStationSocketsCheckNavMesh = false;
}

