#include "CameraDataHelper.h"

class AActor;
class APlayerController;

FRotator UCameraDataHelper::VecToRot(FVector Vec) {
    return FRotator{};
}

FRotator UCameraDataHelper::ToOrientationRotator(FVector Vec) {
    return FRotator{};
}

void UCameraDataHelper::SetTargetOffset(FCameraData& CameraData, FVector Value, FVector Velocity) {
}

void UCameraDataHelper::SetRotation(FCameraData& CameraData, FRotator Value, FRotator Velocity) {
}

void UCameraDataHelper::SetFocusDistance(FCameraData& CameraData, float Value, float Velocity) {
}

void UCameraDataHelper::SetFieldOfView(FCameraData& CameraData, float Value, float Velocity) {
}

void UCameraDataHelper::SetCameraSpaceTranslation(FCameraData& CameraData, FVector Value, FVector Velocity) {
}

void UCameraDataHelper::SetCameraSpaceRotation(FCameraData& CameraData, FRotator Value, FRotator Velocity) {
}

void UCameraDataHelper::SetArmOrigin(FCameraData& CameraData, FVector Value, FVector Velocity) {
}

void UCameraDataHelper::SetArmLength(FCameraData& CameraData, float Value, float Velocity) {
}

void UCameraDataHelper::SetAperture(FCameraData& CameraData, float Value, float Velocity) {
}

void UCameraDataHelper::SetAccumulatedRotationDelta(FCameraData& CameraData, FRotator Value, FRotator Velocity) {
}

float UCameraDataHelper::SafeUnwindDegrees(float Deg) {
    return 0.0f;
}

FVector UCameraDataHelper::RotToVec(FRotator Rot) {
    return FVector{};
}

void UCameraDataHelper::RotateAroundLocation(const FVector& TargetLocation, FVector& InOutViewLocation, FRotator& InOutViewRotation, float AngleInRadians) {
}

FVector UCameraDataHelper::RayPlaneIntersection(const FVector& RayOrigin, const FVector& RayDirection, const FPlane& Plane) {
    return FVector{};
}

FVector UCameraDataHelper::GetWorldDirectionAtScreenLocation(const FVector2D& InScreenLocation, const FMatrix& InInvViewProjectionMatrix) {
    return FVector{};
}

void UCameraDataHelper::GetTargetOffset(const FCameraData& CameraData, FVector& OutValue, FVector& OutVelocity) {
}

bool UCameraDataHelper::GetScreenLocationAtWorldLocation(const FVector& InWorldLocation, const FMatrix& InViewProjectionMatrix, FVector2D& OutScreenLocation) {
    return false;
}

void UCameraDataHelper::GetRotation(const FCameraData& CameraData, FRotator& OutValue, FRotator& OutVelocity) {
}

float UCameraDataHelper::GetFOVFromFocalLength(float InFocalLength, float InSensorWidth, bool bIncOffset) {
    return 0.0f;
}

void UCameraDataHelper::GetFocusDistance(const FCameraData& CameraData, float& OutValue, float& OutVelocity) {
}

float UCameraDataHelper::GetFocalLengthFromFOV(float InFieldOfView, float InSensorWidth, bool bIncOffset) {
    return 0.0f;
}

void UCameraDataHelper::GetFieldOfView(const FCameraData& CameraData, float& OutValue, float& OutVelocity) {
}

void UCameraDataHelper::GetCameraSpaceTranslation(const FCameraData& CameraData, FVector& OutValue, FVector& OutVelocity) {
}

void UCameraDataHelper::GetCameraSpaceRotation(const FCameraData& CameraData, FRotator& OutValue, FRotator& OutVelocity) {
}

void UCameraDataHelper::GetArmOrigin(const FCameraData& CameraData, FVector& OutValue, FVector& OutVelocity) {
}

void UCameraDataHelper::GetArmLength(const FCameraData& CameraData, float& OutValue, float& OutVelocity) {
}

void UCameraDataHelper::GetAperture(const FCameraData& CameraData, float& OutValue, float& OutVelocity) {
}

void UCameraDataHelper::GetAccumulatedRotationDelta(const FCameraData& CameraData, FRotator& OutValue, FRotator& OutVelocity) {
}

float UCameraDataHelper::FindSwingTwistDecomposition(const FQuat& Quat, const FVector& Axis) {
    return 0.0f;
}

void UCameraDataHelper::DeprojectScreenToWorldStable(APlayerController* PlayerController, const FVector2D& InScreenPosition, FVector& OutLocation, FVector& OutDirection) {
}

FMatrix UCameraDataHelper::ComputeViewProjectionMatrix(const AActor* InTargetActor, const FTransform& InCameraTransform, float InFieldOfView) {
    return FMatrix{};
}

FVector UCameraDataHelper::ComputeClosestDirectionInFrustum(const FVector& InTargetDirection, const FBox2D& InScreenArea, const FVector& InEyeLocation, const FMatrix& InViewProjMatrix, const FMatrix& InInvViewProjMatrix) {
    return FVector{};
}

void UCameraDataHelper::AddTargetOffset(FCameraData& CameraData, FVector Value, FVector Velocity, float Scale) {
}

void UCameraDataHelper::AddRotation(FCameraData& CameraData, FRotator Value, FRotator Velocity, float Scale, bool bAccumulate) {
}

void UCameraDataHelper::AddFocusDistance(FCameraData& CameraData, float Value, float Velocity, float Scale) {
}

void UCameraDataHelper::AddFieldOfView(FCameraData& CameraData, float Value, float Velocity, float Scale) {
}

void UCameraDataHelper::AddCameraSpaceTranslation(FCameraData& CameraData, FVector Value, FVector Velocity, float Scale) {
}

void UCameraDataHelper::AddCameraSpaceRotation(FCameraData& CameraData, FRotator Value, FRotator Velocity, float Scale) {
}

void UCameraDataHelper::AddArmOrigin(FCameraData& CameraData, FVector Value, FVector Velocity, float Scale) {
}

void UCameraDataHelper::AddArmLength(FCameraData& CameraData, float Value, float Velocity, float Scale) {
}

void UCameraDataHelper::AddAperture(FCameraData& CameraData, float Value, float Velocity, float Scale) {
}

UCameraDataHelper::UCameraDataHelper() {
}

