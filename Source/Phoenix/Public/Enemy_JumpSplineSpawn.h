#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Enemy_SpawmParams.h"
#include "NPC_JumpSplineData.h"
#include "Enemy_JumpSplineSpawn.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_JumpSplineSpawn : public FEnemy_SpawmParams {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFreezeUntilReleased;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer FreezeAATagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FreezeAnimOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNPC_JumpSplineData JumpSplineParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer JumpSplineAATagContainer;
    
    PHOENIX_API FEnemy_JumpSplineSpawn();
};

