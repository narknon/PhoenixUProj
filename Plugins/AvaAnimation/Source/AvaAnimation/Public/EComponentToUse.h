#pragma once
#include "CoreMinimal.h"
#include "EComponentToUse.generated.h"

UENUM(BlueprintType)
enum class EComponentToUse : uint8 {
    RootComponent,
    FirstFoundMesh,
};

