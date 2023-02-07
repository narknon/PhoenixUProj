#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleOvercast.h"
#include "WorldFXRuleRangedOvercast.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleRangedOvercast : public UWorldFXRuleOvercast {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float minThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float maxThreshold;
    
    UWorldFXRuleRangedOvercast();
};

