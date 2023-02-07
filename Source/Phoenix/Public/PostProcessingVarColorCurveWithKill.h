#pragma once
#include "CoreMinimal.h"
#include "PostProcessingVarColorCurve.h"
#include "PostProcessingVarColorCurveWithKill.generated.h"

USTRUCT(BlueprintType)
struct FPostProcessingVarColorCurveWithKill : public FPostProcessingVarColorCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKillWhenDone;
    
    PHOENIX_API FPostProcessingVarColorCurveWithKill();
};

