#pragma once
#include "CoreMinimal.h"
#include "EMobilityModeState.h"
#include "Enemy_MobilityAbilityData.h"
#include "Enemy_MobilityMovementData.h"
#include "Enemy_MobilityData.generated.h"

USTRUCT(BlueprintType)
struct FEnemy_MobilityData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MoveDistThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_MobilityMovementData Movement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EMobilityModeState::Type> MobilityModeState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnemy_MobilityAbilityData AbilityData;
    
    PHOENIX_API FEnemy_MobilityData();
};

