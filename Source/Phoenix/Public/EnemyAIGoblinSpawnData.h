#pragma once
#include "CoreMinimal.h"
#include "EEnemyGoblinAISpawnType.h"
#include "EnemyAISpawnData.h"
#include "EnemyAIGoblinSpawnData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnemyAIGoblinSpawnData : public UEnemyAISpawnData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyGoblinAISpawnType Type;
    
    UEnemyAIGoblinSpawnData();
};

