#pragma once
#include "CoreMinimal.h"
#include "MyBranchFilter.generated.h"

USTRUCT(BlueprintType)
struct FMyBranchFilter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 BlendDepth;
    
    ABLECORE_API FMyBranchFilter();
};

