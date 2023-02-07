#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoBase.h"
#include "MaterialSwapKeyBase.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapKeyBase : public FMaterialSwapInfoBase {
    GENERATED_BODY()
public:
    FMaterialSwapKeyBase();
};

