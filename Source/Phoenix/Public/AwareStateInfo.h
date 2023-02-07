#pragma once
#include "CoreMinimal.h"
#include "ENPC_TargetAwareState.h"
#include "AwareStateInfo.generated.h"

USTRUCT(BlueprintType)
struct FAwareStateInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_TargetAwareState AwareState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AlertPercent;
    
    PHOENIX_API FAwareStateInfo();
};

