#pragma once
#include "CoreMinimal.h"
#include "Enemy_QBUpdate.h"
#include "Enemy_TooClose_QBUpdate.generated.h"

UCLASS(Blueprintable)
class UEnemy_TooClose_QBUpdate : public UEnemy_QBUpdate {
    GENERATED_BODY()
public:
    UEnemy_TooClose_QBUpdate();
};

