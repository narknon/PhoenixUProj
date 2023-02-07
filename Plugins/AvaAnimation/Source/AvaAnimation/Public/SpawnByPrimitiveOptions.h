#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SpawnByPrimitiveOptions.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, Const, EditInlineNew)
class USpawnByPrimitiveOptions : public UObject {
    GENERATED_BODY()
public:
    USpawnByPrimitiveOptions();
};

