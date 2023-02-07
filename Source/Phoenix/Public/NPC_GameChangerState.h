#pragma once
#include "CoreMinimal.h"
#include "NPC_GameChangerState.generated.h"

UENUM(BlueprintType)
enum class NPC_GameChangerState : uint8 {
    GameChanger_None,
    GameChanger_ReplicaMaster,
    GameChanger_Replicant,
    GameChanger_Animagus_Character,
    GameChanger_Animagus_Loading,
    GameChanger_Animagus_Creature,
    GameChanger_Animagus_Unloading,
    GameChanger_Animagus_Form_Loading,
    GameChanger_Animagus_Form,
    GameChanger_Animagus_Form_Unloading,
    GameChanger_Summoned_Form,
    GameChanger_SummoningDead,
    GameChanger_MAX UMETA(Hidden),
};

