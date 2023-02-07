#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackChoice.h"
#include "DW_ReplicateSelf_AttackChoice_GameChanger.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UDW_ReplicateSelf_AttackChoice_GameChanger : public UEnemy_AttackChoice {
    GENERATED_BODY()
public:
    UDW_ReplicateSelf_AttackChoice_GameChanger();
};

