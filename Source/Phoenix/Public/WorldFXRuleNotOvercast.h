#pragma once
#include "CoreMinimal.h"
#include "WorldFXRuleOvercast.h"
#include "WorldFXRuleNotOvercast.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXRuleNotOvercast : public UWorldFXRuleOvercast {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Threshold;
    
    UWorldFXRuleNotOvercast();
};

