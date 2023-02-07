#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadType.h"
#include "EMaterialPermuterLoadingPriority.h"
#include "MaterialPermuterLoadingStrategyTrigger.h"
#include "MaterialPermuterLoadingStrategy.generated.h"

USTRUCT(BlueprintType)
struct FMaterialPermuterLoadingStrategy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadingStrategyTrigger Trigger;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PurgeTime;
    
    MATERIALPERMUTER_API FMaterialPermuterLoadingStrategy();
};

