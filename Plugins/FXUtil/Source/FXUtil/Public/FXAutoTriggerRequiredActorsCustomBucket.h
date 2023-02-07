#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerRequiredActorsBase.h"
#include "FXAutoTriggerRequiredActorsCustomBucket.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerRequiredActorsCustomBucket : public UFXAutoTriggerRequiredActorsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CustomBucket;
    
    UFXAutoTriggerRequiredActorsCustomBucket();
};

