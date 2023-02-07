#include "TransformationSpellToolComponent.h"

void UTransformationSpellToolComponent::InitialCameraBlendIsComplete() {
}

float UTransformationSpellToolComponent::GetTargetPointScreenPosition() const {
    return 0.0f;
}

float UTransformationSpellToolComponent::GetNormalizedObjectSizeRatio() const {
    return 0.0f;
}

FName UTransformationSpellToolComponent::GetCurrentColor() const {
    return NAME_None;
}

void UTransformationSpellToolComponent::AdjustDistance(float InAdjust) {
}

UTransformationSpellToolComponent::UTransformationSpellToolComponent() {
    this->PreviewActorClass = NULL;
    this->LeftBehindPreviewActorClass = NULL;
    this->SnappingLineVisualizationClass = NULL;
    this->SnappingTargetObjectVisualizationClass = NULL;
    this->DefaultDistance = 1000.00f;
    this->MinDistance = 600.00f;
    this->MaxDistance = 2500.00f;
    this->DistanceSpeed = 500.00f;
    this->ObjectLevitationHeight = 75.00f;
    this->MinFootprintDistance = 125.00f;
    this->TransformRotationAngle = 45.00f;
    this->PowerpointFindRange = 800.00f;
    this->PowerpointSnapRange = 50.00f;
    this->PowerpointWallSnapRange = 25.00f;
    this->IncreasedSnapRangeThreshold = 400.00f;
    this->PowerpointMaxSpeed = 12.00f;
    this->PowerpointMaxNearbySnappingPoints = 8;
    this->PowerpointValidLocationStickingRange = 150.00f;
    this->NoSnappingValidLocationStickingRange = 50.00f;
    this->WallSnappingValidLocationStickingRange = 50.00f;
    this->WallNoSnappingValidLocationStickingRange = 30.00f;
    this->WallAlignmentFindRange = 400.00f;
    this->WallAlignmentSnapRange = 50.00f;
    this->LeftBehindPreviewFadeInStartDistance = 100.00f;
    this->LeftBehindPreviewFadeInEndDistance = 400.00f;
    this->TargetPointScreenPositionOverPitchSmall = NULL;
    this->TargetPointScreenPositionOverPitchLarge = NULL;
    this->ObjectRadiusSmall = 200.00f;
    this->ObjectRadiusLarge = 1000.00f;
    this->TwirlDirection = 1.00f;
    this->DefaultSmallScale = 0.50f;
    this->DefaultLargeScale = 2.00f;
    this->CurrentPreviewActor = NULL;
}

