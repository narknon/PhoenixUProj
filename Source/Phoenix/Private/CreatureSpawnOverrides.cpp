#include "CreatureSpawnOverrides.h"

FCreatureSpawnOverrides::FCreatureSpawnOverrides() {
    this->StartState = ECreatureAIInitialState::Auto;
    this->StartPathNode = NULL;
    this->Cage = NULL;
    this->CageAnimation = ECreatureCageAnimation::Idle;
    this->bOverride_Team = false;
    this->bOverride_Gender = false;
    this->bGenderIsMaleOverride = false;
    this->bIsProtectedFromSpells = false;
    this->bIsUncapturable = false;
    this->bOverride_ShouldTAKWhenWild = false;
    this->bShouldTAKWhenWildOverride = false;
    this->bSpawnFlying = false;
    this->bSpawnPerched = false;
    this->bPlaySpawnFX = false;
    this->bFadeOnSpawn = false;
    this->bOverride_FadeWhenFleeing = false;
    this->bFadeWhenFleeingOverride = false;
    this->TetherVolume = NULL;
    this->bOverride_IsFleeConstrainedByTether = false;
    this->bIsFleeConstrainedByTether = false;
    this->bOverride_IsPerchingConstrainedByTether = false;
    this->bIsPerchingConstrainedByTether = false;
    this->bOverride_MaximumFleeMovementSpeed = false;
    this->MaximumFleeMovementSpeed = ECreatureMovementSpeed::Stop;
    this->bOverride_CombatMaxDistanceFromTether = false;
    this->CombatMaxDistanceFromTether = 0.00f;
}

