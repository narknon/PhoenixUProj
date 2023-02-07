#include "SpellMiniGameSpark.h"

void USpellMiniGameSpark::Stop() {
}

void USpellMiniGameSpark::Start() {
}

void USpellMiniGameSpark::Reset() {
}








void USpellMiniGameSpark::LogSpellMinigameData(const FString& LogData) {
}

FVector2D USpellMiniGameSpark::GetVelocity() const {
    return FVector2D{};
}

float USpellMiniGameSpark::GetTotalDistanceAsPercent() const {
    return 0.0f;
}

FVector2D USpellMiniGameSpark::GetPosition() const {
    return FVector2D{};
}

float USpellMiniGameSpark::GetOrientation() const {
    return 0.0f;
}

float USpellMiniGameSpark::GetNextAngleTowardsDirection(float CurrentAngle, const FVector2D& TargetDirection, const float& SmoothSpeed, const float& MaxSmoothAngle) const {
    return 0.0f;
}

bool USpellMiniGameSpark::GetIsBoosting() const {
    return false;
}

float USpellMiniGameSpark::GetDistanceAlongPathSegment(const FSpellUnlockMiniGamePathSegment PathSegment) const {
    return 0.0f;
}

FVector2D USpellMiniGameSpark::GetDirection() const {
    return FVector2D{};
}

FVector2D USpellMiniGameSpark::GetCurrentPositionOnPath() const {
    return FVector2D{};
}

int32 USpellMiniGameSpark::GetCurrentPathSegmentIndex() const {
    return 0;
}

FSpellUnlockMiniGamePathSegment USpellMiniGameSpark::GetCurrentPathSegment() const {
    return FSpellUnlockMiniGamePathSegment{};
}

float USpellMiniGameSpark::GetCurrentDistanceAlongPath() const {
    return 0.0f;
}

float USpellMiniGameSpark::GetActiveSpeedScale() const {
    return 0.0f;
}

void USpellMiniGameSpark::ApplyBoost() {
}

USpellMiniGameSpark::USpellMiniGameSpark() {
    this->IsRunning = false;
    this->MaxSpeed = 0.00f;
    this->MaxAcceleration = 0.00f;
    this->BoostMultiplier = 1.00f;
    this->BoostTime = 0.50f;
    this->BoostRampUpSpeed = 0.50f;
    this->BoostRampDownSpeed = 0.50f;
    this->OrientationSmoothSpeed = 20.00f;
    this->MaxOrientationSmoothAngle = 190.00f;
    this->NormalizedPerformanceSpeed = 1.00f;
}

