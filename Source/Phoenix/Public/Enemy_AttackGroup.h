#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Enemy_AttackGroup.generated.h"

class APerceptionPointArea;

USTRUCT(BlueprintType)
struct FEnemy_AttackGroup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxAttacking;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APerceptionPointArea*> StandbyVolumeList;
    
    PHOENIX_API FEnemy_AttackGroup();
};

