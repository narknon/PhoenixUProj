#pragma once
#include "CoreMinimal.h"
#include "FXAutoTriggerUpdateBase.h"
#include "FXAutoTriggerUpdateNiagaraScalar.generated.h"

class UFXAutoTriggerScalar;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerUpdateNiagaraScalar : public UFXAutoTriggerUpdateBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NiagaraVar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerScalar* Scalar;
    
    UFXAutoTriggerUpdateNiagaraScalar();
};

