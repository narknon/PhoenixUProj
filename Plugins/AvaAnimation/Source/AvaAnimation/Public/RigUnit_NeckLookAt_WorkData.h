#pragma once
#include "CoreMinimal.h"

#include "UObject/NoExportTypes.h"
#include "RigUnit_NeckLookAt_ConeConstraint.h"
#include "Rigs/RigBoneHierarchy.h"
#include "RigUnit_NeckLookAt_WorkData.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_NeckLookAt_WorkData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> BoneIndices;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FQuat> BoneLocalRotations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRigUnit_NeckLookAt_ConeConstraint> PerBoneConstraints;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> BoneLengths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChainLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> BoneYawWeights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> BonePitchWeights;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigBoneHierarchy ChainHierarchy;
    
    AVAANIMATION_API FRigUnit_NeckLookAt_WorkData();
};

