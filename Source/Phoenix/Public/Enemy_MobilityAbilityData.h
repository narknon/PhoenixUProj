#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Enemy_MobilityAbilityData.generated.h"

class UAblAbility;
class UCurveFloat;

USTRUCT(BlueprintType)
struct FEnemy_MobilityAbilityData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> MoveAbilityPtr;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimSpeedMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimSpeedMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* TurnAssistCurve;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* TurnAssistTimeMultiplier;
    
    PHOENIX_API FEnemy_MobilityAbilityData();
};

