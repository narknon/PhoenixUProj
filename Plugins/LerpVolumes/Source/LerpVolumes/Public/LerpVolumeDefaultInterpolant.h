#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeTagInterpolantBase.h"
#include "LerpVolumeDefaultInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeDefaultInterpolant : public ULerpVolumeTagInterpolantBase {
    GENERATED_BODY()
public:
    ULerpVolumeDefaultInterpolant();
};

