#pragma once
#include "CoreMinimal.h"
#include "Rigs/RigBoneHierarchy.h"

#include "RigUnit_TwoBoneIK_WorkData.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_TwoBoneIK_WorkData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> BoneIndices;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> BoneLengths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigBoneHierarchy ChainHierarchy;
    
    AVAANIMATION_API FRigUnit_TwoBoneIK_WorkData();
};

