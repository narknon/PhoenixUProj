#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerScalar.h"
#include "EStencilManagerEffectPriority.h"
#include "FXAutoTriggerScalarStencilEffectConstPriority.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerScalarStencilEffectConstPriority : public UFXAutoTriggerScalar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilManagerEffectPriority Priority;
    
    UFXAutoTriggerScalarStencilEffectConstPriority();
};

