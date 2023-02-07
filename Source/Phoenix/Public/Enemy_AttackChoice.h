#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Enemy_AttackChoice.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UEnemy_AttackChoice : public UObject {
    GENERATED_BODY()
public:
    UEnemy_AttackChoice();
};

