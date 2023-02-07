#pragma once
#include "CoreMinimal.h"
#include "LumosDefaultValueInterpolant.h"
#include "LumosLevelIntensityFactorInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosLevelIntensityFactorInterpolant : public ULumosDefaultValueInterpolant {
    GENERATED_BODY()
public:
    ULumosLevelIntensityFactorInterpolant();
};

