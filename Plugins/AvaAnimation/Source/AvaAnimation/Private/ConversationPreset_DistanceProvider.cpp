#include "ConversationPreset_DistanceProvider.h"

UConversationPreset_DistanceProvider::UConversationPreset_DistanceProvider() {
    this->Enabled = true;
    this->Proximity = EConversationPreset_ProximityType::Ideal;
    this->Force = false;
}

