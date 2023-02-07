#pragma once
#include "CoreMinimal.h"
#include "Enemy_QBUpdate.h"
#include "Enemy_Follow_QBUpdate.generated.h"

UCLASS(Blueprintable)
class UEnemy_Follow_QBUpdate : public UEnemy_QBUpdate {
    GENERATED_BODY()
public:
    UEnemy_Follow_QBUpdate();
};

