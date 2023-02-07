#include "MovementPredictionComponent.h"

void UMovementPredictionComponent::TriggerMovementEvent(EMovementSensorType InType) {
}

void UMovementPredictionComponent::SetMovementState(FName InState) {
}

bool UMovementPredictionComponent::IsLastEventFollowThroughComplete() const {
    return false;
}

bool UMovementPredictionComponent::GetTimeToEventTransition(FName InEventName, float& OutTimeUntilTransition) const {
    return false;
}

float UMovementPredictionComponent::GetSteeringCorrectionAngle() const {
    return 0.0f;
}

FTransform UMovementPredictionComponent::GetPredictedUncorrectedTransform(const float InTimeFromNow) const {
    return FTransform{};
}

FTransform UMovementPredictionComponent::GetPredictedTransform(const float InTimeFromNow) const {
    return FTransform{};
}

bool UMovementPredictionComponent::GetNextSensorInfoOfTypes(const TArray<EMovementSensorType>& SensorTypes, float InTimeFromNow, FMovementSensorInfo& OutSensorInfo) const {
    return false;
}

bool UMovementPredictionComponent::GetNextSensorInfo(EMovementSensorType SensorType, float InTimeFromNow, FMovementSensorInfo& OutSensorInfo) const {
    return false;
}

bool UMovementPredictionComponent::GetNextBlockingCollision(float InGlancingAngleThresholdDegrees, FMovementSensorInfo& OutSensorInfo) const {
    return false;
}

FName UMovementPredictionComponent::GetMovementState() const {
    return NAME_None;
}

bool UMovementPredictionComponent::GetMovementEventTarget(EMovementSensorType& OutType, float& OutTimeToEvent) const {
    return false;
}

float UMovementPredictionComponent::GetMovementAnimTime() const {
    return 0.0f;
}

FRotator UMovementPredictionComponent::GetFlightSteeringCorrectionAngles(const FRotator& InInputRotation) const {
    return FRotator{};
}

bool UMovementPredictionComponent::GetEventFollowThroughAnimTime(FName InEventName, FName InCurrentState, float& OutAnimTime) const {
    return false;
}

bool UMovementPredictionComponent::GetEventAnimTime(FName InEventName, FName InCurrentState, float& OutAnimTime) const {
    return false;
}

UMovementPredictionComponent::UMovementPredictionComponent() {
    this->MotionTable = NULL;
    this->bEnableEventMatching = true;
    this->MovementWarpingStrength = 1.00f;
    this->SteeringCorrectionStrength = 1.00f;
    this->bDebugDrawMotionEvents = false;
}

