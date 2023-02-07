#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Enemy_AttackSpecificData.h"
#include "Enemy_FlourishData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_FlourishData : public FEnemy_AttackSpecificData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer TagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistToTarget;
    
    PHOENIX_API FEnemy_FlourishData();
};

