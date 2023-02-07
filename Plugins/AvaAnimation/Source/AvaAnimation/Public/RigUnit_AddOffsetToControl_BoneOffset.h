#pragma once
#include "CoreMinimal.h"
#include "RigUnit_AddOffsetToControl_BoneOffset.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_AddOffsetToControl_BoneOffset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Bone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Control;
    
    AVAANIMATION_API FRigUnit_AddOffsetToControl_BoneOffset();
};

