#include "AnimationInspectionFunctions.h"

class UAnimSequence;
class UAnimSequenceBase;
class UBlendSpaceBase;
class USkeletalMesh;

bool UAnimationInspectionFunctions::SetBlendSpaceFraction(const UBlendSpaceBase* BlendSpace, const float Fraction, TArray<FBlendSampleData>& OutSampleData) {
    return false;
}

bool UAnimationInspectionFunctions::GetSocketsInAnimationSpaceFromClip(const USkeletalMesh* SkeletalMesh, const UAnimSequence* AnimationAsset, const float EvaluationTime, const TArray<FName>& SocketNameArray, TArray<FTransform>& TransformArray, const int32 LoopCount) {
    return false;
}

bool UAnimationInspectionFunctions::GetSocketInAnimationSpaceFromClip(const USkeletalMesh* SkeletalMesh, const UAnimSequence* AnimationAsset, const float EvaluationTime, const FName SocketName, FTransform& Transform, const int32 LoopCount) {
    return false;
}

bool UAnimationInspectionFunctions::GetRootInAnimationSpaceFromClip(const UAnimSequenceBase* AnimationAsset, const float EvaluationTime, FTransform& Transform, const int32 LoopCount) {
    return false;
}

bool UAnimationInspectionFunctions::GetRootInAnimationSpaceFromBlendSpace(const UBlendSpaceBase* BlendSpace, const TArray<FBlendSampleData>& SampleData, FTransform& Transform, const int32 LoopCount) {
    return false;
}

bool UAnimationInspectionFunctions::GetComponentInWorldSpaceFromAlignedRoot(const UAnimSequence* AnimationAsset, FTransform AnimationInWorldSpace, FTransform RootInAnimationSpace, FTransform& Transform, const int32 LoopCount, EBoneEvaluationRootMode RootModeSetting) {
    return false;
}

bool UAnimationInspectionFunctions::GetBonesInParentSpaceFromClip(const UAnimSequenceBase* AnimationAsset, const float EvaluationTime, const TArray<FName>& BoneNameArray, TArray<FTransform>& TransformArray) {
    return false;
}

bool UAnimationInspectionFunctions::GetBonesInParentSpaceFromBlendSpace(const UBlendSpaceBase* BlendSpaceAsset, const float EvaluationTime, const float ParameterX, const float ParameterY, const TArray<FName>& BoneNameArray, TArray<FTransform>& TransformArray) {
    return false;
}

bool UAnimationInspectionFunctions::GetBonesInAnimationSpaceFromClip(const UAnimSequence* AnimationAsset, const float EvaluationTime, const TArray<FName>& BoneNameArray, TArray<FTransform>& TransformArray, const int32 LoopCount) {
    return false;
}

bool UAnimationInspectionFunctions::GetBoneInParentSpaceFromClip(const UAnimSequenceBase* AnimationAsset, const float EvaluationTime, const FName BoneName, FTransform& Transform) {
    return false;
}

bool UAnimationInspectionFunctions::GetBoneInParentSpaceFromBlendSpace(const UBlendSpaceBase* BlendSpaceAsset, const float EvaluationTime, const float ParameterX, const float ParameterY, const FName BoneName, FTransform& Transform) {
    return false;
}

bool UAnimationInspectionFunctions::GetBoneInAnimationSpaceFromClip(const UAnimSequence* AnimationAsset, const float EvaluationTime, const FName BoneName, FTransform& Transform, const int32 LoopCount, EBoneEvaluationRootMode RootModeSetting) {
    return false;
}

float UAnimationInspectionFunctions::GetBlendSpaceDuration(const UBlendSpaceBase* BlendSpace, const TArray<FBlendSampleData>& SampleData) {
    return 0.0f;
}

UAnimationInspectionFunctions::UAnimationInspectionFunctions() {
}

