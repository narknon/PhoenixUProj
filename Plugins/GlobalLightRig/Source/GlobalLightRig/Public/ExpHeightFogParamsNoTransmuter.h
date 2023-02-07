#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogParams.h"
#include "ExpHeightFogParamsNoTransmuter.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogParamsNoTransmuter : public UExpHeightFogParams {
    GENERATED_BODY()
public:
    UExpHeightFogParamsNoTransmuter();
};

