#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeFinalTagInterpolant.h"
#include "LerpVolumeFinalLastValidTagInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeFinalLastValidTagInterpolant : public ULerpVolumeFinalTagInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeFinalLastValidTagInterpolant();
};

