#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LerpVolumeInterpolant.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class LERPVOLUMES_API ULerpVolumeInterpolant : public UObject {
    GENERATED_BODY()
public:
    ULerpVolumeInterpolant();
};

