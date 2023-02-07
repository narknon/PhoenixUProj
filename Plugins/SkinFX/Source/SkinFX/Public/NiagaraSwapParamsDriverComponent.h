#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapParameters.h"
#include "NiagaraMaterialDriverComponent.h"
#include "NiagaraSwapParamsDriverComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class SKINFX_API UNiagaraSwapParamsDriverComponent : public UNiagaraMaterialDriverComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters ParameterSet;
    
    UNiagaraSwapParamsDriverComponent();
};

