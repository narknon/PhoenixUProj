#pragma once
#include "CoreMinimal.h"
#include "Rigs/RigBoneHierarchy.h"
#include "UObject/NoExportTypes.h"
#include "RigUnit_FourBoneIK_WorkData.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_FourBoneIK_WorkData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> BoneIndices;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> BoneLengths;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransform> HelperATransforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransform> HelperBTransforms;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRigBoneHierarchy ChainHierarchy;
    
    AVAANIMATION_API FRigUnit_FourBoneIK_WorkData();
};

