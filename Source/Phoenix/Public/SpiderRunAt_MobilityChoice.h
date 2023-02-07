#pragma once
#include "CoreMinimal.h"
#include "NPC_MobilityChoice.h"
#include "SpiderRunAt_MobilityChoice.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USpiderRunAt_MobilityChoice : public UNPC_MobilityChoice {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChangeDist;
    
    USpiderRunAt_MobilityChoice();
};

