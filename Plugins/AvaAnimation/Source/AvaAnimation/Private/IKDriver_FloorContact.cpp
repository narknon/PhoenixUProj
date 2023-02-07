#include "IKDriver_FloorContact.h"

UIKDriver_FloorContact::UIKDriver_FloorContact() {
    this->HipAlphaVariableName = TEXT("HipAlpha");
    this->HipTransformVariableName = TEXT("HipTransform");
    this->CollisionChannel = ECC_WorldStatic;
    this->HipMultiplier = 1.00f;
    this->GlobalRayTraceStartScale = 0.30f;
    this->GlobalRayTraceFinishScale = 0.50f;
    this->bAddHipsAverageToHands = true;
    this->bTraceComplex = true;
    this->LimitLegExtenstion = false;
    this->MaxLegExtension = 0.00f;
    this->bUseFK = false;
    this->bReverseFootSetup = true;
    this->ReverseFootFactor = 1.00f;
    this->ReverseFootInterpSpeed = 0.10f;
    this->RollLimit = 55.00f;
    this->PitchLimit = 60.00f;
    this->PTransitionSpeed = 25.00f;
    this->RTransitionSpeed = 80.00f;
    this->PTransitionMaxDistance = 100.00f;
    this->bFloorContact = false;
    this->DrawDebug = false;
    this->bFootStabilization = false;
    this->StabilizationThreshold = 1.00f;
    this->InterpTimeHipsUp = 0.30f;
    this->InterpTimeHipsDown = 0.10f;
    this->UseMinToMaxHipAdjust = -0.50f;
    this->InterpTimeHipsUpFromCapsule = 0.30f;
    this->InterpTimeHipsDownFromCapsule = 0.10f;
    this->PlantRestoreSpeed = 6.00f;
    this->GlobalDebugScale = 0.00f;
}

