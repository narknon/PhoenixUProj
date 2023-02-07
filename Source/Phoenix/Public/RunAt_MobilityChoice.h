#pragma once
#include "CoreMinimal.h"
#include "NPC_MobilityChoice.h"
#include "RunAt_MobilityChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URunAt_MobilityChoice : public UNPC_MobilityChoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChangeDist;
    
    URunAt_MobilityChoice();
};

