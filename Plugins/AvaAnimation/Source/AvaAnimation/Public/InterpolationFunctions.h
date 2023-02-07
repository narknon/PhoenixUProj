#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "InterpolationFunctions.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UInterpolationFunctions : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UInterpolationFunctions();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float SmoothStep(float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector SmoothBlendVectors(FVector A, FVector B, float Blend);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTransform SmoothBlendTransforms(FTransform A, FTransform B, float Blend);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float SmoothBlendScalars(float A, float B, float Blend);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRotator SmoothBlendRotators(FRotator A, FRotator B, float Blend);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FQuat SmoothBlendQuaternions(FQuat A, FQuat B, float Blend);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float LinearStep(float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector LinearBlendVectors(FVector A, FVector B, float Blend);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTransform LinearBlendTransforms(FTransform A, FTransform B, float Blend);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float LinearBlendScalars(float A, float B, float Blend);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRotator LinearBlendRotators(FRotator A, FRotator B, float Blend);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FQuat LinearBlendQuaternions(FQuat A, FQuat B, float Blend);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float EaseOutStep(float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float EaseInStep(float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float BoundedSmoothStep(float step_min, float step_max, float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float BoundedLinearStep(float step_min, float step_max, float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float BoundedEaseOutStep(float step_min, float step_max, float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float BoundedEaseInStep(float step_min, float step_max, float Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector AssymetricallyApproachVectorWithClampedVelocity(FVector current_value, FVector desired_value, float max_positive_delta, float max_negative_delta);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector AssymetricallyApproachVector(FVector current_value, FVector desired_value, float positive_approach_rate, float negative_approach_rate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float AssymetricallyApproachScalarWithClampedVelocity(float current_value, float desired_value, float max_positive_delta, float max_negative_delta);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float AssymetricallyApproachScalar(float current_value, float desired_value, float negative_approach_rate, float positive_approach_rate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector ApproachVectorWithClampedVelocity(FVector current_value, FVector desired_value, float max_delta);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector ApproachVector(FVector current_value, FVector desired_value, float approach_rate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTransform ApproachTransformWithClampedVelocity(FTransform current_value, FTransform desired_value, float max_rotation_delta, float max_translation_delta, float max_scale_delta);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FTransform ApproachTransform(FTransform current_value, FTransform desired_value, float rotation_approach_rate, float translation_approach_rate, float scale_approach_rate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ApproachScalarWithClampedVelocity(float current_value, float desired_value, float max_delta);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ApproachScalar(float current_value, float desired_value, float approach_rate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRotator ApproachRotatorWithClampedVelocity(FRotator current_value, FRotator desired_value, float max_delta);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRotator ApproachRotator(FRotator current_value, FRotator desired_value, float approach_rate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FQuat ApproachQuaternionWithClampedVelocity(FQuat current_value, FQuat desired_value, float max_delta);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FQuat ApproachQuaternion(FQuat current_value, FQuat desired_value, float approach_rate);
    
};

