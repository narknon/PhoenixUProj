#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerUpdateNiagaraBatchVar.h"
#include "FXAutoTriggerUpdateNiagaraBatchLinearColor.generated.h"

class UFXAutoTriggerLinearColor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerUpdateNiagaraBatchLinearColor : public UFXAutoTriggerUpdateNiagaraBatchVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Var;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerLinearColor* Color;
    
    UFXAutoTriggerUpdateNiagaraBatchLinearColor();
};

