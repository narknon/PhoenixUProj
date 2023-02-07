#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimationAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EBoneEvaluationRootMode.h"
#include "AnimationInspectionFunctions.generated.h"

class UAnimSequence;
class UAnimSequenceBase;
class UBlendSpaceBase;
class USkeletalMesh;

UCLASS(Blueprintable)
class AVAANIMATION_API UAnimationInspectionFunctions : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UAnimationInspectionFunctions();
    UFUNCTION(BlueprintCallable)
    static bool SetBlendSpaceFraction(const UBlendSpaceBase* BlendSpace, const float Fraction, TArray<FBlendSampleData>& OutSampleData);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetSocketsInAnimationSpaceFromClip(const USkeletalMesh* SkeletalMesh, const UAnimSequence* AnimationAsset, const float EvaluationTime, const TArray<FName>& SocketNameArray, TArray<FTransform>& TransformArray, const int32 LoopCount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetSocketInAnimationSpaceFromClip(const USkeletalMesh* SkeletalMesh, const UAnimSequence* AnimationAsset, const float EvaluationTime, const FName SocketName, FTransform& Transform, const int32 LoopCount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetRootInAnimationSpaceFromClip(const UAnimSequenceBase* AnimationAsset, const float EvaluationTime, FTransform& Transform, const int32 LoopCount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetRootInAnimationSpaceFromBlendSpace(const UBlendSpaceBase* BlendSpace, const TArray<FBlendSampleData>& SampleData, FTransform& Transform, const int32 LoopCount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetComponentInWorldSpaceFromAlignedRoot(const UAnimSequence* AnimationAsset, FTransform AnimationInWorldSpace, FTransform RootInAnimationSpace, FTransform& Transform, const int32 LoopCount, EBoneEvaluationRootMode RootModeSetting);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetBonesInParentSpaceFromClip(const UAnimSequenceBase* AnimationAsset, const float EvaluationTime, const TArray<FName>& BoneNameArray, TArray<FTransform>& TransformArray);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetBonesInParentSpaceFromBlendSpace(const UBlendSpaceBase* BlendSpaceAsset, const float EvaluationTime, const float ParameterX, const float ParameterY, const TArray<FName>& BoneNameArray, TArray<FTransform>& TransformArray);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetBonesInAnimationSpaceFromClip(const UAnimSequence* AnimationAsset, const float EvaluationTime, const TArray<FName>& BoneNameArray, TArray<FTransform>& TransformArray, const int32 LoopCount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetBoneInParentSpaceFromClip(const UAnimSequenceBase* AnimationAsset, const float EvaluationTime, const FName BoneName, FTransform& Transform);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetBoneInParentSpaceFromBlendSpace(const UBlendSpaceBase* BlendSpaceAsset, const float EvaluationTime, const float ParameterX, const float ParameterY, const FName BoneName, FTransform& Transform);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetBoneInAnimationSpaceFromClip(const UAnimSequence* AnimationAsset, const float EvaluationTime, const FName BoneName, FTransform& Transform, const int32 LoopCount, EBoneEvaluationRootMode RootModeSetting);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float GetBlendSpaceDuration(const UBlendSpaceBase* BlendSpace, const TArray<FBlendSampleData>& SampleData);
    
};

