#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerUpdateNiagaraBatchVar.h"
#include "FXAutoTriggerUpdateNiagaraBatchFloat.generated.h"

class UFXAutoTriggerScalar;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UFXAutoTriggerUpdateNiagaraBatchFloat : public UFXAutoTriggerUpdateNiagaraBatchVar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Var;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* Scalar;
    
    UFXAutoTriggerUpdateNiagaraBatchFloat();
};

