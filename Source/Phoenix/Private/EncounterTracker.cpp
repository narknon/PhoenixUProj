#include "EncounterTracker.h"

class AActor;
class ACombatVolume;

void UEncounterTracker::TryEndEncounter() {
}

bool UEncounterTracker::StartEncounterForPlayersCombatVolume() {
    return false;
}

void UEncounterTracker::ResetTryEndEncounterTimer() {
}

void UEncounterTracker::OnCurtainRaised() {
}

void UEncounterTracker::OnCombatVolumeDeath(ACombatVolume* CombatVolume, AActor* DeadActor) {
}

void UEncounterTracker::OnCombatVolumeActorSpawned(ACombatVolume* CombatVolume, AActor* SpawnedActor) {
}

bool UEncounterTracker::IsPlayerInAnEncounter() {
    return false;
}

UEncounterTracker::UEncounterTracker() {
    this->m_currentCombatVolumeGroup = NULL;
    this->DuelTechniquesController = NULL;
}

