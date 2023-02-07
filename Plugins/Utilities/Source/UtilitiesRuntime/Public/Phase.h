#pragma once
#include "CoreMinimal.h"
#include "Phase.generated.h"

USTRUCT(BlueprintType)
struct UTILITIESRUNTIME_API FPhase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PhaseValue;
    
    FPhase();
};

