#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackChoice.h"
#include "Goblin_AttackChoice_DaggerThrow.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UGoblin_AttackChoice_DaggerThrow : public UEnemy_AttackChoice {
    GENERATED_BODY()
public:
    UGoblin_AttackChoice_DaggerThrow();
};

