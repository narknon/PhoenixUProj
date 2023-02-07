#include "ExtendedOdcRepulsorComponent.h"

UExtendedOdcRepulsorComponent::UExtendedOdcRepulsorComponent() {
    this->bEnabled = true;
    this->RepulsorTickFrameInterval = 5;
    this->RepulsorDistanceThreshold = 15.00f;
    this->RepulsorRadius = 20.00f;
    this->RepulsorOuterCushion = 5.00f;
    this->RepulsorInnerCushion = 5.00f;
}

