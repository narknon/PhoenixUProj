#pragma once
#include "CoreMinimal.h"
#include "PostProcessingVarScalarCurve.h"
#include "PostProcessingVarScalarCurveWithKill.generated.h"

USTRUCT(BlueprintType)
struct FPostProcessingVarScalarCurveWithKill : public FPostProcessingVarScalarCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKillWhenDone;
    
    PHOENIX_API FPostProcessingVarScalarCurveWithKill();
};

