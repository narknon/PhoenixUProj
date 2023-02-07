#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRequiredActorsIterate.generated.h"

USTRUCT(BlueprintType)
struct FFXAutoTriggerRequiredActorsIterate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ExternalBuckets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMainActorList;
    
    FXUTIL_API FFXAutoTriggerRequiredActorsIterate();
};

