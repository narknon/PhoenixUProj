#pragma once
#include "CoreMinimal.h"
#include "RigUnit_ConstrainRotation_WorkData.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_ConstrainRotation_WorkData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<int32> BoneIndices;
    
    AVAANIMATION_API FRigUnit_ConstrainRotation_WorkData();
};

