#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WorldFXRule.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class WORLDFX_API UWorldFXRule : public UObject {
    GENERATED_BODY()
public:
    UWorldFXRule();
};

