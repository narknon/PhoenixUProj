#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "FXAutoTriggerBoolStencilEffectSubStringActive.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolStencilEffectSubStringActive : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EffectSubString;
    
    UFXAutoTriggerBoolStencilEffectSubStringActive();
};

