#pragma once
#include "CoreMinimal.h"
#include "ESpellCategory.h"
#include "Templates/SubclassOf.h"
#include "CooldownPickupData.generated.h"

class ACooldownPickup;

USTRUCT(BlueprintType)
struct FCooldownPickupData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ACooldownPickup> CooldownPickupActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float weight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESpellCategory, float> CooldownRecoveryMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FocusGain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthGainPercent;
    
    PHOENIX_API FCooldownPickupData();
};

