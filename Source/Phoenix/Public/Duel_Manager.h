#pragma once
#include "CoreMinimal.h"
#include "Enemy_Manager.h"
#include "Duel_Manager.generated.h"

UCLASS(Blueprintable)
class UDuel_Manager : public UEnemy_Manager {
    GENERATED_BODY()
public:
    UDuel_Manager();
};

