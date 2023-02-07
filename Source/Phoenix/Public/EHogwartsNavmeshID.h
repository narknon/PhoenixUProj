#pragma once
#include "CoreMinimal.h"
#include "EHogwartsNavmeshID.generated.h"

UENUM(BlueprintType)
enum class EHogwartsNavmeshID : uint8 {
    Hogwarts_Navmesh_A,
    Hogwarts_Navmesh_B,
    Hogwarts_Navmesh_Count,
    Hogwarts_Navmesh_MAX UMETA(Hidden),
};

