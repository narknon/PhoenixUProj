#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackChoice.h"
#include "Wolf_AttackChoice_BiteLeft.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWolf_AttackChoice_BiteLeft : public UEnemy_AttackChoice {
    GENERATED_BODY()
public:
    UWolf_AttackChoice_BiteLeft();
};

