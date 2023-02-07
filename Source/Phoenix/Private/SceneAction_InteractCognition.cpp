#include "SceneAction_InteractCognition.h"

USceneAction_InteractCognition::USceneAction_InteractCognition() {
    this->CalloutType = ECalloutType::Interact;
    this->CalloutBlipType = ECalloutBlipType::Diamond;
    this->CalloutAction = ECalloutActions::Action_Interact;
    this->CalloutChargeTime = 0.50f;
    this->FootprintRadius = 0.00f;
    this->TopOffset = 0.00f;
    this->BottomOffset = 0.00f;
}

