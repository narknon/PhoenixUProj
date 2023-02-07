#pragma once
#include "CoreMinimal.h"
#include "EEnemy_ProtegoLevel.generated.h"

UENUM(BlueprintType)
enum class EEnemy_ProtegoLevel : uint8 {
    None,
    TypeA,
    TypeB,
    TypeC,
    TypeD,
    TypePhysical_Deprecated,
    TypeProfessor_Deprecated,
    TypeDuelOpponent,
    TypeStudent_Deprecated,
    TypeTownie_Deprecated,
    TypeBoss_Deprecated,
    TypeBoss_Harlow,
    TypeBoss_Oppugno,
    TypeBoss_AncientMagic,
    TypeBoss_Solomon,
    EEnemy_MAX UMETA(Hidden),
};

