#include "InterpolationFunctions.h"

float UInterpolationFunctions::SmoothStep(float Value) {
    return 0.0f;
}

FVector UInterpolationFunctions::SmoothBlendVectors(FVector A, FVector B, float Blend) {
    return FVector{};
}

FTransform UInterpolationFunctions::SmoothBlendTransforms(FTransform A, FTransform B, float Blend) {
    return FTransform{};
}

float UInterpolationFunctions::SmoothBlendScalars(float A, float B, float Blend) {
    return 0.0f;
}

FRotator UInterpolationFunctions::SmoothBlendRotators(FRotator A, FRotator B, float Blend) {
    return FRotator{};
}

FQuat UInterpolationFunctions::SmoothBlendQuaternions(FQuat A, FQuat B, float Blend) {
    return FQuat{};
}

float UInterpolationFunctions::LinearStep(float Value) {
    return 0.0f;
}

FVector UInterpolationFunctions::LinearBlendVectors(FVector A, FVector B, float Blend) {
    return FVector{};
}

FTransform UInterpolationFunctions::LinearBlendTransforms(FTransform A, FTransform B, float Blend) {
    return FTransform{};
}

float UInterpolationFunctions::LinearBlendScalars(float A, float B, float Blend) {
    return 0.0f;
}

FRotator UInterpolationFunctions::LinearBlendRotators(FRotator A, FRotator B, float Blend) {
    return FRotator{};
}

FQuat UInterpolationFunctions::LinearBlendQuaternions(FQuat A, FQuat B, float Blend) {
    return FQuat{};
}

float UInterpolationFunctions::EaseOutStep(float Value) {
    return 0.0f;
}

float UInterpolationFunctions::EaseInStep(float Value) {
    return 0.0f;
}

float UInterpolationFunctions::BoundedSmoothStep(float step_min, float step_max, float Value) {
    return 0.0f;
}

float UInterpolationFunctions::BoundedLinearStep(float step_min, float step_max, float Value) {
    return 0.0f;
}

float UInterpolationFunctions::BoundedEaseOutStep(float step_min, float step_max, float Value) {
    return 0.0f;
}

float UInterpolationFunctions::BoundedEaseInStep(float step_min, float step_max, float Value) {
    return 0.0f;
}

FVector UInterpolationFunctions::AssymetricallyApproachVectorWithClampedVelocity(FVector current_value, FVector desired_value, float max_positive_delta, float max_negative_delta) {
    return FVector{};
}

FVector UInterpolationFunctions::AssymetricallyApproachVector(FVector current_value, FVector desired_value, float positive_approach_rate, float negative_approach_rate) {
    return FVector{};
}

float UInterpolationFunctions::AssymetricallyApproachScalarWithClampedVelocity(float current_value, float desired_value, float max_positive_delta, float max_negative_delta) {
    return 0.0f;
}

float UInterpolationFunctions::AssymetricallyApproachScalar(float current_value, float desired_value, float negative_approach_rate, float positive_approach_rate) {
    return 0.0f;
}

FVector UInterpolationFunctions::ApproachVectorWithClampedVelocity(FVector current_value, FVector desired_value, float max_delta) {
    return FVector{};
}

FVector UInterpolationFunctions::ApproachVector(FVector current_value, FVector desired_value, float approach_rate) {
    return FVector{};
}

FTransform UInterpolationFunctions::ApproachTransformWithClampedVelocity(FTransform current_value, FTransform desired_value, float max_rotation_delta, float max_translation_delta, float max_scale_delta) {
    return FTransform{};
}

FTransform UInterpolationFunctions::ApproachTransform(FTransform current_value, FTransform desired_value, float rotation_approach_rate, float translation_approach_rate, float scale_approach_rate) {
    return FTransform{};
}

float UInterpolationFunctions::ApproachScalarWithClampedVelocity(float current_value, float desired_value, float max_delta) {
    return 0.0f;
}

float UInterpolationFunctions::ApproachScalar(float current_value, float desired_value, float approach_rate) {
    return 0.0f;
}

FRotator UInterpolationFunctions::ApproachRotatorWithClampedVelocity(FRotator current_value, FRotator desired_value, float max_delta) {
    return FRotator{};
}

FRotator UInterpolationFunctions::ApproachRotator(FRotator current_value, FRotator desired_value, float approach_rate) {
    return FRotator{};
}

FQuat UInterpolationFunctions::ApproachQuaternionWithClampedVelocity(FQuat current_value, FQuat desired_value, float max_delta) {
    return FQuat{};
}

FQuat UInterpolationFunctions::ApproachQuaternion(FQuat current_value, FQuat desired_value, float approach_rate) {
    return FQuat{};
}

UInterpolationFunctions::UInterpolationFunctions() {
}

