#include "CreatureFeedingStation.h"

class ACreatureFeed;
class ACreature_Character;
class UCreatureFeedingStationState;
class USceneComponent;

void ACreatureFeedingStation::UnregisterFeedingStationFromBiome() {
}


void ACreatureFeedingStation::Unassign(ACreature_Character* Creature) {
}

void ACreatureFeedingStation::SetSlotVisualState(int32 SlotIdx, ECreatureFeedingStationSlotVisualState VisualState) {
}

void ACreatureFeedingStation::RemoveOneFeed(int32 SlotIdx) {
}


void ACreatureFeedingStation::RegisterFeedingStationToBiome() {
}

void ACreatureFeedingStation::RefillEmptyFeederSlots() {
}


void ACreatureFeedingStation::OnFeedDispensed_Implementation(ACreatureFeed* CreatureFeed, ACreature_Character* Creature) {
}



ECreatureFeedingStationSlotVisualState ACreatureFeedingStation::GetSlotVisualState(int32 SlotIdx) {
    return ECreatureFeedingStationSlotVisualState::Empty;
}

UCreatureFeedingStationState* ACreatureFeedingStation::GetFeedingStationState() {
    return NULL;
}

FTransform ACreatureFeedingStation::GetBestSlotTransform(ACreature_Character* Creature) {
    return FTransform{};
}

void ACreatureFeedingStation::FindSlotComponents_Implementation(TArray<USceneComponent*>& OutSlotComponents) {
}

bool ACreatureFeedingStation::DispenseFeed(ACreature_Character* Creature) {
    return false;
}

void ACreatureFeedingStation::ConvertAvailableFeederSlot() {
}


void ACreatureFeedingStation::AssignToSlot(ACreature_Character* Creature) {
}

ACreatureFeedingStation::ACreatureFeedingStation(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->FeedActorClass = NULL;
}

