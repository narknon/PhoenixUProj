#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapParameters.h"
#include "NiagaraMaterialDriver.h"
#include "NiagaraMaterialSwapDriver.generated.h"

UCLASS(Blueprintable)
class SKINFX_API UNiagaraMaterialSwapDriver : public UNiagaraMaterialDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters ParameterSet;
    
    UNiagaraMaterialSwapDriver();
};

