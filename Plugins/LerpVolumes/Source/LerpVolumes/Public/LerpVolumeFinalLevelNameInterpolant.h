#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeFinalTagInterpolant.h"
#include "LerpVolumeFinalLevelNameInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeFinalLevelNameInterpolant : public ULerpVolumeFinalTagInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeFinalLevelNameInterpolant();
};

