#include "DistanceTransition_MobilityChoice.h"

UDistanceTransition_MobilityChoice::UDistanceTransition_MobilityChoice() {
    this->WalkMinRange = 0.00f;
    this->WalkMaxRange = 600.00f;
    this->JogMinRange = 500.00f;
    this->JogMaxRange = 1100.00f;
    this->RunMinRange = 1000.00f;
    this->RunMaxRange = -1.00f;
}

