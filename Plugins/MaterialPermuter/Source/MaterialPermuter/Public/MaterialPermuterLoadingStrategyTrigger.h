#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingPriority.h"
#include "MaterialPermuterLoadingStrategyTrigger.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterLoadingStrategyTrigger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Trigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingPriority TriggerPriority;
    
    MATERIALPERMUTER_API FMaterialPermuterLoadingStrategyTrigger();
};

