#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerUpdateLocalVar.h"
#include "FXAutoTriggerUpdateNiagaraBatchVar.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerUpdateNiagaraBatchVar : public UFXAutoTriggerUpdateLocalVar {
    GENERATED_BODY()
public:
    UFXAutoTriggerUpdateNiagaraBatchVar();
};

