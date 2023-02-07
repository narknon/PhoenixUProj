#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerBool.h"
#include "StencilManagerGroupName.h"
#include "FXAutoTriggerBoolStencilEffectGroupActive.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerBoolStencilEffectGroupActive : public UFXAutoTriggerBool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerGroupName Group;
    
    UFXAutoTriggerBoolStencilEffectGroupActive();
};

