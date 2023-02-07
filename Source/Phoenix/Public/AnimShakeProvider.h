#pragma once
#include "CoreMinimal.h"
#include "FloatProvider.h"
#include "AnimShakeProvider.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimShakeProvider : public UFloatProvider {
    GENERATED_BODY()
public:
    UAnimShakeProvider();
};

