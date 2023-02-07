#include "CreatureFeed.h"

class ACreature_Character;

void ACreatureFeed::OnStartedVanishing_Implementation() {
}

void ACreatureFeed::InitializeRelease(ACreature_Character* NewSelectedCreature) {
}

void ACreatureFeed::FloatToCreature(FVector ReleaseVelocity) {
}

ACreatureFeed::ACreatureFeed() {
    this->StartFeedAnimDistance = 40.00f;
    this->bUsePelletStartingScaleInAnim = false;
    this->MaxWaitTime = 3.00f;
    this->FeedFloatingComponent = NULL;
    this->SelectedCreature = NULL;
}

