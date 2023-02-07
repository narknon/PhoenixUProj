#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerLinearColor.h"
#include "FXAutoTriggerLinearSelectColor.generated.h"

class UFXAutoTriggerBool;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerLinearSelectColor : public UFXAutoTriggerLinearColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerBool* Condition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerLinearColor* ColorTrue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerLinearColor* ColorFalse;
    
    UFXAutoTriggerLinearSelectColor();
};

