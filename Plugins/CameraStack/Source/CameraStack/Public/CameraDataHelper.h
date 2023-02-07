#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "CameraData.h"
#include "CameraDataHelper.generated.h"

class AActor;
class APlayerController;

UCLASS(Abstract, Blueprintable)
class CAMERASTACK_API UCameraDataHelper : public UObject {
    GENERATED_BODY()
public:
    UCameraDataHelper();
    UFUNCTION(BlueprintCallable)
    static FRotator VecToRot(FVector Vec);
    
    UFUNCTION(BlueprintCallable)
    static FRotator ToOrientationRotator(FVector Vec);
    
    UFUNCTION(BlueprintCallable)
    static void SetTargetOffset(UPARAM(Ref) FCameraData& CameraData, FVector Value, FVector Velocity);
    
    UFUNCTION(BlueprintCallable)
    static void SetRotation(UPARAM(Ref) FCameraData& CameraData, FRotator Value, FRotator Velocity);
    
    UFUNCTION(BlueprintCallable)
    static void SetFocusDistance(UPARAM(Ref) FCameraData& CameraData, float Value, float Velocity);
    
    UFUNCTION(BlueprintCallable)
    static void SetFieldOfView(UPARAM(Ref) FCameraData& CameraData, float Value, float Velocity);
    
    UFUNCTION(BlueprintCallable)
    static void SetCameraSpaceTranslation(UPARAM(Ref) FCameraData& CameraData, FVector Value, FVector Velocity);
    
    UFUNCTION(BlueprintCallable)
    static void SetCameraSpaceRotation(UPARAM(Ref) FCameraData& CameraData, FRotator Value, FRotator Velocity);
    
    UFUNCTION(BlueprintCallable)
    static void SetArmOrigin(UPARAM(Ref) FCameraData& CameraData, FVector Value, FVector Velocity);
    
    UFUNCTION(BlueprintCallable)
    static void SetArmLength(UPARAM(Ref) FCameraData& CameraData, float Value, float Velocity);
    
    UFUNCTION(BlueprintCallable)
    static void SetAperture(UPARAM(Ref) FCameraData& CameraData, float Value, float Velocity);
    
    UFUNCTION(BlueprintCallable)
    static void SetAccumulatedRotationDelta(UPARAM(Ref) FCameraData& CameraData, FRotator Value, FRotator Velocity);
    
    UFUNCTION(BlueprintCallable)
    static float SafeUnwindDegrees(float Deg);
    
    UFUNCTION(BlueprintCallable)
    static FVector RotToVec(FRotator Rot);
    
    UFUNCTION(BlueprintCallable)
    static void RotateAroundLocation(const FVector& TargetLocation, FVector& InOutViewLocation, FRotator& InOutViewRotation, float AngleInRadians);
    
    UFUNCTION(BlueprintCallable)
    static FVector RayPlaneIntersection(const FVector& RayOrigin, const FVector& RayDirection, const FPlane& Plane);
    
    UFUNCTION(BlueprintCallable)
    static FVector GetWorldDirectionAtScreenLocation(const FVector2D& InScreenLocation, const FMatrix& InInvViewProjectionMatrix);
    
    UFUNCTION(BlueprintCallable)
    static void GetTargetOffset(const FCameraData& CameraData, FVector& OutValue, FVector& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static bool GetScreenLocationAtWorldLocation(const FVector& InWorldLocation, const FMatrix& InViewProjectionMatrix, FVector2D& OutScreenLocation);
    
    UFUNCTION(BlueprintCallable)
    static void GetRotation(const FCameraData& CameraData, FRotator& OutValue, FRotator& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static float GetFOVFromFocalLength(float InFocalLength, float InSensorWidth, bool bIncOffset);
    
    UFUNCTION(BlueprintCallable)
    static void GetFocusDistance(const FCameraData& CameraData, float& OutValue, float& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static float GetFocalLengthFromFOV(float InFieldOfView, float InSensorWidth, bool bIncOffset);
    
    UFUNCTION(BlueprintCallable)
    static void GetFieldOfView(const FCameraData& CameraData, float& OutValue, float& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static void GetCameraSpaceTranslation(const FCameraData& CameraData, FVector& OutValue, FVector& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static void GetCameraSpaceRotation(const FCameraData& CameraData, FRotator& OutValue, FRotator& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static void GetArmOrigin(const FCameraData& CameraData, FVector& OutValue, FVector& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static void GetArmLength(const FCameraData& CameraData, float& OutValue, float& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static void GetAperture(const FCameraData& CameraData, float& OutValue, float& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static void GetAccumulatedRotationDelta(const FCameraData& CameraData, FRotator& OutValue, FRotator& OutVelocity);
    
    UFUNCTION(BlueprintCallable)
    static float FindSwingTwistDecomposition(const FQuat& Quat, const FVector& Axis);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void DeprojectScreenToWorldStable(APlayerController* PlayerController, const FVector2D& InScreenPosition, FVector& OutLocation, FVector& OutDirection);
    
    UFUNCTION(BlueprintCallable)
    static FMatrix ComputeViewProjectionMatrix(const AActor* InTargetActor, const FTransform& InCameraTransform, float InFieldOfView);
    
    UFUNCTION(BlueprintCallable)
    static FVector ComputeClosestDirectionInFrustum(const FVector& InTargetDirection, const FBox2D& InScreenArea, const FVector& InEyeLocation, const FMatrix& InViewProjMatrix, const FMatrix& InInvViewProjMatrix);
    
    UFUNCTION(BlueprintCallable)
    static void AddTargetOffset(UPARAM(Ref) FCameraData& CameraData, FVector Value, FVector Velocity, float Scale);
    
    UFUNCTION(BlueprintCallable)
    static void AddRotation(UPARAM(Ref) FCameraData& CameraData, FRotator Value, FRotator Velocity, float Scale, bool bAccumulate);
    
    UFUNCTION(BlueprintCallable)
    static void AddFocusDistance(UPARAM(Ref) FCameraData& CameraData, float Value, float Velocity, float Scale);
    
    UFUNCTION(BlueprintCallable)
    static void AddFieldOfView(UPARAM(Ref) FCameraData& CameraData, float Value, float Velocity, float Scale);
    
    UFUNCTION(BlueprintCallable)
    static void AddCameraSpaceTranslation(UPARAM(Ref) FCameraData& CameraData, FVector Value, FVector Velocity, float Scale);
    
    UFUNCTION(BlueprintCallable)
    static void AddCameraSpaceRotation(UPARAM(Ref) FCameraData& CameraData, FRotator Value, FRotator Velocity, float Scale);
    
    UFUNCTION(BlueprintCallable)
    static void AddArmOrigin(UPARAM(Ref) FCameraData& CameraData, FVector Value, FVector Velocity, float Scale);
    
    UFUNCTION(BlueprintCallable)
    static void AddArmLength(UPARAM(Ref) FCameraData& CameraData, float Value, float Velocity, float Scale);
    
    UFUNCTION(BlueprintCallable)
    static void AddAperture(UPARAM(Ref) FCameraData& CameraData, float Value, float Velocity, float Scale);
    
};

