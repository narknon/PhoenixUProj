#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackChoice.h"
#include "ActivateDOV_AttackChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UActivateDOV_AttackChoice : public UEnemy_AttackChoice {
    GENERATED_BODY()
public:
    UActivateDOV_AttackChoice();
};

