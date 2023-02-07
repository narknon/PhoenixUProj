#pragma once
#include "CoreMinimal.h"
#include "EHoboType.generated.h"

UENUM(BlueprintType)
enum class EHoboType : uint8 {
    AnyType,
    DarkWizards,
    Ghosts,
    Students,
    TownsPeople,
    HouseElf,
    Authority,
    Worker,
    Child,
    YoungStudent,
    AzkabanPrisoner,
    Custom,
};

