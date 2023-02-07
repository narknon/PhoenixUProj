#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerUpdateNiagaraBatchVar.h"
#include "FXAutoTriggerUpdateNiagaraBatchBool.generated.h"

class UFXAutoTriggerBool;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerUpdateNiagaraBatchBool : public UFXAutoTriggerUpdateNiagaraBatchVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Var;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerBool* Bool;
    
    UFXAutoTriggerUpdateNiagaraBatchBool();
};

