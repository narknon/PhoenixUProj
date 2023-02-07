#pragma once
#include "CoreMinimal.h"
#include "ENPC_Mobility.h"
#include "NPC_MobilityChoice.h"
#include "Forced_MobilityChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UForced_MobilityChoice : public UNPC_MobilityChoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENPC_Mobility Mobility;
    
    UForced_MobilityChoice();
};

