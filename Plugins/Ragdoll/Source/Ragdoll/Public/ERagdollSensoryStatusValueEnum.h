#pragma once
#include "CoreMinimal.h"
#include "ERagdollSensoryStatusValueEnum.generated.h"

UENUM(BlueprintType)
enum class ERagdollSensoryStatusValueEnum : uint8 {
    RSSVE_OnGround,
    RSSVE_InAir,
    RSSVE_Hovering,
    RSSVE_Dead,
    RSSVE_GetupObstructed,
    RSSVE_NearDeathKneeling,
    RSSVE_Frozen,
    RSSVE_OnFire,
    RSSVE_Charred,
    RSSVE_Petrified,
    RSSVE_Resurrecting,
    RSSVE_MAX UMETA(Hidden),
};

