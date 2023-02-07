#pragma once
#include "CoreMinimal.h"
#include "EEnemyAIDodgeState.h"
#include "Templates/SubclassOf.h"
#include "EnemyEvadeData.generated.h"

class UAblAbility;
class UInteractionArchitectAsset;

USTRUCT(BlueprintType)
struct FEnemyEvadeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemyAIDodgeState EvadeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> EvadeAbilityPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* InteractionArchitectAssetPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EvadeChance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EvadeSuccessCooldown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EvadeFailedCooldown;
    
    PHOENIX_API FEnemyEvadeData();
};

