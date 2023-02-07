#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RigUnit_NeckLookAt_BoneRotation.generated.h"

USTRUCT(BlueprintType)
struct FRigUnit_NeckLookAt_BoneRotation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Bone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator BoneRotation;
    
    AVAANIMATION_API FRigUnit_NeckLookAt_BoneRotation();
};

