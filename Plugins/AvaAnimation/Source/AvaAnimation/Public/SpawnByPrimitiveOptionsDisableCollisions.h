#pragma once
#include "CoreMinimal.h"
#include "SpawnByPrimitiveOptions.h"
#include "SpawnByPrimitiveOptionsDisableCollisions.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USpawnByPrimitiveOptionsDisableCollisions : public USpawnByPrimitiveOptions {
    GENERATED_BODY()
public:
    USpawnByPrimitiveOptionsDisableCollisions();
};

