#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "StencilManagerEffectName.h"
#include "FXAutoTriggerBoolStencilEffectActive.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolStencilEffectActive : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerEffectName Effect;
    
    UFXAutoTriggerBoolStencilEffectActive();
};

