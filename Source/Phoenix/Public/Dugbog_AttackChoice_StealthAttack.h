#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackChoice.h"
#include "Dugbog_AttackChoice_StealthAttack.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UDugbog_AttackChoice_StealthAttack : public UEnemy_AttackChoice {
    GENERATED_BODY()
public:
    UDugbog_AttackChoice_StealthAttack();
};

