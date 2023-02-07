#pragma once
#include "CoreMinimal.h"
#include "LumosDefaultValueInterpolant.h"
#include "LumosVolumetricScatteringIntensityInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosVolumetricScatteringIntensityInterpolant : public ULumosDefaultValueInterpolant {
    GENERATED_BODY()
public:
    ULumosVolumetricScatteringIntensityInterpolant();
};

