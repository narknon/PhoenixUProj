#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Enemy_SpawmParams.h"
#include "Enemy_SpawnFreeze.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_SpawnFreeze : public FEnemy_SpawmParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer AATagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBranchOnRelease;
    
    PHOENIX_API FEnemy_SpawnFreeze();
};

