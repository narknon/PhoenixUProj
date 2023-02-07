#include "FastTravelForDoorsComponent.h"

UFastTravelForDoorsComponent::UFastTravelForDoorsComponent() {
    this->FastTravelDoorType = EDoorFastTravelType::TravelToOtherSideOfDoor;
    this->FastTravelType = EFT_TravelType::NormalFastTravelOnly;
    this->FastTravelSceneRig = NULL;
    this->ChargeTime = 1.50f;
    this->SceneRigPlayer = NULL;
    this->Door = NULL;
    this->CalloutLocator = NULL;
    this->CognitionStimuliSource = NULL;
}

