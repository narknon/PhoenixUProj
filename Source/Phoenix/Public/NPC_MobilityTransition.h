#pragma once
#include "CoreMinimal.h"
#include "ENPC_Mobility.h"
#include "Templates/SubclassOf.h"
#include "NPC_MobilityTransition.generated.h"

class UAblAbility;

USTRUCT(BlueprintType)
struct FNPC_MobilityTransition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_Mobility FromMobility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_Mobility ToMobility;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> AbilityPtr;
    
    PHOENIX_API FNPC_MobilityTransition();
};

