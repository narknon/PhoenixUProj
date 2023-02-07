#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EnemyAISpawnData.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew, Config=Game)
class UEnemyAISpawnData : public UObject {
    GENERATED_BODY()
public:
    UEnemyAISpawnData();
};

