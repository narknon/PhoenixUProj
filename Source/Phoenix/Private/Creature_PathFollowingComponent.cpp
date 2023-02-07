#include "Creature_PathFollowingComponent.h"

void UCreature_PathFollowingComponent::SetUseRepulsorCollisionAvoidance(bool bEnabled) {
}

UCreature_PathFollowingComponent::UCreature_PathFollowingComponent() {
    this->bMoveToStopPrediction = true;
    this->RepulsorMinimumRadius = 26.00f;
    this->RepulsorDetectionRadiusMultiplier = 15.00f;
    this->RepulsorDetectionRadiusMultiplierVariance = 2.00f;
    this->RepulsorNavProbeMinLength = 200.00f;
    this->bTangentialAcceptance = true;
    this->bTangentialAcceptanceDefaultRadius = 200.00f;
    this->LookaheadDistanceMultiplierTune = 1.10f;
    this->TurnAnticipationLookaheadTune = 1.00f;
    this->TurnAnticipationCornerLookaheadTune = 1.00f;
    this->TurnAnticipationCornerOffsetTune = 1.00f;
    this->AdditionalTurningFactor = 0.25f;
    this->MinNavDistSq2D = 225.00f;
    this->CreatureController = NULL;
    this->CreatureCharacter = NULL;
    this->MovementComponent = NULL;
}

