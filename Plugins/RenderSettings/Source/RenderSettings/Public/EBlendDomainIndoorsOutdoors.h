#pragma once
#include "CoreMinimal.h"
#include "EBlendDomainIndoorsOutdoors.generated.h"

UENUM(BlueprintType)
enum class EBlendDomainIndoorsOutdoors : uint8 {
    IndoorsAndOutdoors,
    OutdoorsOnly,
    IndoorsOnly,
};

