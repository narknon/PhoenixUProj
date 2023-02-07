#include "MountZoneVolumeBase.h"

class AFlyingBroom;
class APawn;
class UCreature_MountComponent;

bool AMountZoneVolumeBase::IsIgnored(EMountTypes InType) const {
    return false;
}

bool AMountZoneVolumeBase::GetMountType(const APawn* InPawn, EMountTypes& OutType) {
    return false;
}

UCreature_MountComponent* AMountZoneVolumeBase::GetMount(const APawn* InPawn) {
    return NULL;
}

bool AMountZoneVolumeBase::GetEquivalentGroundType(EMountTypes InType, EMountTypes& OutType) {
    return false;
}

bool AMountZoneVolumeBase::GetEquivalentFlyingType(EMountTypes InType, EMountTypes& OutType) {
    return false;
}

AFlyingBroom* AMountZoneVolumeBase::GetBroom(const APawn* InPawn) {
    return NULL;
}

void AMountZoneVolumeBase::EnableZone(bool Enable) {
}

AMountZoneVolumeBase::AMountZoneVolumeBase() {
    this->bDisableOnHighEndPlatforms = false;
    this->IgnoredMounts = 64;
    this->PrerequisiteType = EPrerequisiteType::None;
    this->MissionStates = 0;
}

