#include "FlyingStairComponent.h"

bool UFlyingStairComponent::NeedsToBeBuilt() const {
    return false;
}

bool UFlyingStairComponent::IsBuilt() const {
    return false;
}

void UFlyingStairComponent::Demolish() {
}

void UFlyingStairComponent::Build() {
}

UFlyingStairComponent::UFlyingStairComponent() {
    this->TimeBeforeDemolitionWhenUnused = 5.00f;
    this->IndexForAutomaticChainBuilding = 0;
    this->BuildingStairMesh = NULL;
    this->BuildingStairAnim = NULL;
    this->BuildingStairAnimCounter = NULL;
    this->DemolishingStairMesh = NULL;
    this->DemolishingStairAnim = NULL;
    this->DemolishingStairAnimCounter = NULL;
    this->bPlayPartOfAnim = false;
}

