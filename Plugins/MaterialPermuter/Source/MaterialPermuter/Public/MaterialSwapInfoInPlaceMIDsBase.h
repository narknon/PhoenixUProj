#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapInfoBase.h"
#include "MaterialSwapInfoInPlaceMIDsBase.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialSwapInfoInPlaceMIDsBase : public FMaterialSwapInfoBase {
    GENERATED_BODY()
public:
    FMaterialSwapInfoInPlaceMIDsBase();
};

