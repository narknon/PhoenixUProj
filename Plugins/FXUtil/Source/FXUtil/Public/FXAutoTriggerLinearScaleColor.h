#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerLinearColor.h"
#include "FXAutoTriggerLinearScaleColor.generated.h"

class UFXAutoTriggerScalar;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerLinearScaleColor : public UFXAutoTriggerLinearColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerLinearColor* Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* Scale;
    
    UFXAutoTriggerLinearScaleColor();
};

