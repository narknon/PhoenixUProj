#pragma once
#include "CoreMinimal.h"
#include "LerpVolumeFinalTagInterpolant.h"
#include "LerpVolumeFinalDefaultTagInterpolant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeFinalDefaultTagInterpolant : public ULerpVolumeFinalTagInterpolant {
    GENERATED_BODY()
public:
    ULerpVolumeFinalDefaultTagInterpolant();
};

