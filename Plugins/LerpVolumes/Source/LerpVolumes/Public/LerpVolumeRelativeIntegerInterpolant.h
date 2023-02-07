#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeIntegerInterpolant.h"
#include "LerpVolumeRelativeIntegerInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeRelativeIntegerInterpolant : public ULerpVolumeIntegerInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeRelativeIntegerInterpolant();
};

