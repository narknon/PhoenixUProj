#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterLoadingTriggerSemaphone.h"
#include "MaterialPermuterLoadingTriggers.generated.h"

USTRUCT(BlueprintType)
struct MATERIALPERMUTER_API FMaterialPermuterLoadingTriggers {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FMaterialPermuterLoadingTriggerSemaphone> Triggers;
    
    FMaterialPermuterLoadingTriggers();
};

