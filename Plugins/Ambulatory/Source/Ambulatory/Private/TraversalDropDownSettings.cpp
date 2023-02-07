#include "TraversalDropDownSettings.h"

FTraversalDropDownSettings::FTraversalDropDownSettings() {
    this->bEnableJumpDown = false;
    this->bEnableTeeterOnEdge = false;
    this->MinJumpDownHeight = 0.00f;
    this->MinTeeterOnEdgeHeight = 0.00f;
    this->TeeterEdgeDistance = 0.00f;
    this->DeepWaterCollisionChannel = ECC_WorldStatic;
}

