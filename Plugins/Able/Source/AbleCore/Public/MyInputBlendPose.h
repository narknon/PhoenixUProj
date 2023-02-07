#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimData/BoneMaskFilter.h"
#include "MyInputBlendPose.generated.h"

USTRUCT(BlueprintType)
struct FMyInputBlendPose {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBranchFilter> BranchFilters;
    
    ABLECORE_API FMyInputBlendPose();
};

