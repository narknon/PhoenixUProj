#pragma once
#include "CoreMinimal.h"
#include "EHighContrastGameplayBucket.h"
#include "FXAutoTriggerRequiredActorsBase.h"
#include "FXAutoTriggerRequiredActorsExternalBucketHighContrast.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerRequiredActorsExternalBucketHighContrast : public UFXAutoTriggerRequiredActorsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHighContrastGameplayBucket Bucket;
    
    UFXAutoTriggerRequiredActorsExternalBucketHighContrast();
};

