#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackChoice.h"
#include "DW_Summon_Reinforcements_AttackChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UDW_Summon_Reinforcements_AttackChoice : public UEnemy_AttackChoice {
    GENERATED_BODY()
public:
    UDW_Summon_Reinforcements_AttackChoice();
};

