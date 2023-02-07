#pragma once
#include "CoreMinimal.h"
#include "Enemy_InstanceQBUpdateData.h"
#include "Enemy_TooClose_InstanceQBUpdateData.generated.h"

UCLASS(Blueprintable)
class UEnemy_TooClose_InstanceQBUpdateData : public UEnemy_InstanceQBUpdateData {
    GENERATED_BODY()
public:
    UEnemy_TooClose_InstanceQBUpdateData();
};

