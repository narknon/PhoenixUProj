#pragma once
#include "CoreMinimal.h"
#include "BoneIndexProperty.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FBoneIndexProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BoneIndex;
    
    FBoneIndexProperty();
};

