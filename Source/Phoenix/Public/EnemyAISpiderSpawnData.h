#pragma once
#include "CoreMinimal.h"
#include "EEnemySpiderAISpawnType.h"
#include "EnemyAISpawnData.h"
#include "EnemyAISpiderSpawnData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnemyAISpiderSpawnData : public UEnemyAISpawnData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemySpiderAISpawnType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DescendSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FallGravityScale;
    
    UEnemyAISpiderSpawnData();
};

