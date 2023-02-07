#include "CreatureFeedingStationState.h"

bool UCreatureFeedingStationState::HasFeedAvailable() const {
    return false;
}

bool UCreatureFeedingStationState::HasEmptySlot() const {
    return false;
}

int32 UCreatureFeedingStationState::GetNumFeedSlots() const {
    return 0;
}

EItemConversionState UCreatureFeedingStationState::GetConversionState(int32 SlotIndex) const {
    return EItemConversionState::Available;
}

void UCreatureFeedingStationState::FinalizeCurrentConversion() {
}

UCreatureFeedingStationState::UCreatureFeedingStationState() {
}

