#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoBase.h"
#include "MaterialSwapInfoOverrideMaterialBase.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapInfoOverrideMaterialBase : public FMaterialSwapInfoBase {
    GENERATED_BODY()
public:
    FMaterialSwapInfoOverrideMaterialBase();
};

