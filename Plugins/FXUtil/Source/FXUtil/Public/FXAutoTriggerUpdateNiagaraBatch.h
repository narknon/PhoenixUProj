#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerUpdateBase.h"
#include "FXAutoTriggerUpdateNiagaraBatch.generated.h"

class UFXAutoTriggerUpdateNiagaraBatchVar;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerUpdateNiagaraBatch : public UFXAutoTriggerUpdateBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UFXAutoTriggerUpdateNiagaraBatchVar*> Vars;
    
    UFXAutoTriggerUpdateNiagaraBatch();
};

