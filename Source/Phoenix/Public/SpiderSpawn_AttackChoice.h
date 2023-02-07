#pragma once
#include "CoreMinimal.h"
#include "Enemy_AttackChoice.h"
#include "SpiderSpawn_AttackChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpiderSpawn_AttackChoice : public UEnemy_AttackChoice {
    GENERATED_BODY()
public:
    USpiderSpawn_AttackChoice();
};

