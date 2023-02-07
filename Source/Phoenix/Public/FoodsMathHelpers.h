#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FoodsMathHelpers.generated.h"

UCLASS(Blueprintable)
class UFoodsMathHelpers : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UFoodsMathHelpers();
    UFUNCTION(BlueprintCallable)
    static void UniformPointsOnSphere(int32 NumPoints, TArray<FVector>& PointsOnSphere);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void UniformPointOnSphere(int32 NumPoints, int32 Point, FVector& PointOnSphere);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void TriangleWaveSine(float Time, float Period, float& Output, float Amplitude);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void TriangleWaveCosine(float Time, float Period, float& Output, float Amplitude, float Phase);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void TriangleWave(float Time, float Period, float& Output, float Amplitude);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationSafeUp(FVector Unit, FVector& SafeUp);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationSafePerp(const FVector& UnitA, const FVector& UnitB, FVector& SafePerp);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitZYSafe(FVector UnitZ, FVector UnitY, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitZY(FVector UnitZ, FVector UnitY, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitZXSafe(FVector UnitZ, FVector UnitX, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitZX(FVector UnitZ, FVector UnitX, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitZ(FVector UnitZ, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitYZSafe(FVector UnitY, FVector UnitZ, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitYZ(FVector UnitY, FVector UnitZ, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitYXSafe(FVector UnitY, FVector UnitX, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitYX(FVector UnitY, FVector UnitX, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitY(FVector UnitY, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitXZSafe(FVector UnitX, FVector UnitZ, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitXZ(FVector UnitX, FVector UnitZ, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitXYSafe(FVector UnitX, FVector UnitY, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitXY(FVector UnitX, FVector UnitY, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RotationFromUnitX(FVector UnitX, FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable)
    static void RandomUniformPointsOnSphere(int32 NumPoints, float RandomHalfAngleDegrees, TArray<FVector>& PointsOnSphere);
    
    UFUNCTION(BlueprintCallable)
    static void RandomUniformPointOnSphere(int32 NumPoints, int32 Point, FVector& PointOnSphere, float RandomHalfAngleInnerDegrees, float RandomHalfAngleOuterDegrees);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void RandomInCone(FVector Direction, FVector& RandomDir, float HalfAngleInnerDegrees, float HalfAngleOuterDegrees);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static void MakeOrthogonalUnitVector(FVector In, FVector& Orthoganal);
    
};

