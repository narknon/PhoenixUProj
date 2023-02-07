#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableBase.h"
#include "GlobalLightingCustomBlendableFocusValue.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UGlobalLightingCustomBlendableFocusValue : public UGlobalLightingBlendableBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Focus;
    
    UGlobalLightingCustomBlendableFocusValue();
};

