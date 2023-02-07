#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "StencilManagerEffectName.h"
#include "FXAutoTriggerScalarStencilEffectPriority.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarStencilEffectPriority : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerEffectName Effect;
    
    UFXAutoTriggerScalarStencilEffectPriority();
};

