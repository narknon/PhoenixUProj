#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeScalarInterpolant.h"
#include "LerpVolumeRelativeScalarInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeRelativeScalarInterpolant : public ULerpVolumeScalarInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeRelativeScalarInterpolant();
};

