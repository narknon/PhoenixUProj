#include "ForceCapsuleShadowsSettings.h"

FForceCapsuleShadowsSettings::FForceCapsuleShadowsSettings() {
    this->DynamicShadowEndDistanceMeters = 0.00f;
    this->CapsuleShadowStartDistanceMeters = 0.00f;
    this->CapsuleShadowEndDistanceMeters = 0.00f;
    this->CapsuleIndirectShadowStartDistanceMeters = 0.00f;
    this->CapsuleIndirectShadowEndDistanceMeters = 0.00f;
    this->CapsuleIndirectShadowMinVisibilityAtStart = 0.00f;
    this->CapsuleIndirectShadowMinVisibilityAtEnd = 0.00f;
    this->bControlDynamicShadow = false;
    this->bControlCapsuleShadow = false;
    this->bControlCapsuleIndirectShadow = false;
}

