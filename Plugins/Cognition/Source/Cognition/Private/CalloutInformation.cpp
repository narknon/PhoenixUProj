#include "CalloutInformation.h"

FCalloutInformation::FCalloutInformation() {
    this->CalloutType = ECalloutType::Interact;
    this->CalloutBlipType = ECalloutBlipType::Diamond;
    this->CalloutAction = ECalloutActions::NOT_SET;
    this->CalloutInteractDistance = 0.00f;
    this->bGrayOutButton = false;
    this->bIsTargetNameTranslatable = false;
    this->Owned = false;
    this->CalloutChargeTime = 0.00f;
}

