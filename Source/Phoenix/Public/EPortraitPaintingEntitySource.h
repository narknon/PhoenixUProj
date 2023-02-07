#pragma once
#include "CoreMinimal.h"
#include "EPortraitPaintingEntitySource.generated.h"

UENUM(BlueprintType)
enum class EPortraitPaintingEntitySource : uint8 {
    Unresolved,
    FleshCacheCallback,
    CustomizableCharacterCallBack,
    CustomizableCharacterScan,
    PopulationManager,
};

