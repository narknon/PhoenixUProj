#include "CameraStackVolumeOperationSettings.h"

FCameraStackVolumeOperationSettings::FCameraStackVolumeOperationSettings() {
    this->BehaviorToAdd = NULL;
    this->Operation = ECameraStackVolumeOperation::AddOnTop;
    this->ExistingBehaviorClass = NULL;
}

