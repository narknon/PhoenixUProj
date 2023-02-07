#pragma once
#include "CoreMinimal.h"
#include "ENPC_AbilityChannel.h"
#include "NPC_AbilityChannelMap.generated.h"

USTRUCT(BlueprintType)
struct FNPC_AbilityChannelMap {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_AbilityChannel Channel;
    
    PHOENIX_API FNPC_AbilityChannelMap();
};

