#pragma once
#include "CoreMinimal.h"
#include "DOTData.h"
#include "CrucioData.generated.h"

USTRUCT(BlueprintType)
struct FCrucioData : public FDOTData {
    GENERATED_BODY()
public:
    PHOENIX_API FCrucioData();
};

