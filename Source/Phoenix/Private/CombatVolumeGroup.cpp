#include "CombatVolumeGroup.h"

class ACombatVolume;

bool UCombatVolumeGroup::TryStartEncounter() {
    return false;
}

bool UCombatVolumeGroup::IsActiveForCurrentEncounter() const {
    return false;
}

TSet<ACombatVolume*> UCombatVolumeGroup::GetVolumes() const {
    return TSet<ACombatVolume*>();
}

UCombatVolumeGroup::UCombatVolumeGroup() {
    this->bEnableDuelTechniques = true;
}

