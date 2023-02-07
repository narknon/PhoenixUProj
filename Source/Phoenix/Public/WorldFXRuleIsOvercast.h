#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleOvercast.h"
#include "WorldFXRuleIsOvercast.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleIsOvercast : public UWorldFXRuleOvercast {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Threshold;
    
    UWorldFXRuleIsOvercast();
};

