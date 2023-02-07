#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Enemy_SpawmParams.h"
#include "Enemy_SpawnAsleep.generated.h"

class APerceptionPointArea;

USTRUCT(BlueprintType)
struct FEnemy_SpawnAsleep : public FEnemy_SpawmParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APerceptionPointArea*> WakeupVolumeList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AATagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimOffset;
    
    PHOENIX_API FEnemy_SpawnAsleep();
};

