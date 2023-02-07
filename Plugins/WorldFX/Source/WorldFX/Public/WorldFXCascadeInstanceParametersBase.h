#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldFXCascadeInstanceParametersBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class WORLDFX_API UWorldFXCascadeInstanceParametersBase : public UObject {
    GENERATED_BODY()
public:
    UWorldFXCascadeInstanceParametersBase();
};

