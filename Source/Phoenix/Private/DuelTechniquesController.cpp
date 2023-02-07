#include "DuelTechniquesController.h"

class UCombatVolumeGroup;

void UDuelTechniquesController::OnCombatVolumeGroupDestroyed(const UCombatVolumeGroup* Group) {
}

UDuelTechniquesController::UDuelTechniquesController() {
    this->Owner = NULL;
}

