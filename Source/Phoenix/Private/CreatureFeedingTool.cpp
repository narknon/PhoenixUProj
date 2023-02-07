#include "CreatureFeedingTool.h"

class ACreature_Character;

void ACreatureFeedingTool::SetupDistanceBasedPelletReleaseAnim(ACreature_Character* InCreatureCharacter) {
}

FVector ACreatureFeedingTool::CalculateDynamicPelletReleaseVeloctiy(ACreature_Character* InCreatureCharacter) const {
    return FVector{};
}

ACreatureFeedingTool::ACreatureFeedingTool() {
    this->PelletsMediumReleaseRange = 100.00f;
    this->PelletsThrowReleaseRange = 250.00f;
}

