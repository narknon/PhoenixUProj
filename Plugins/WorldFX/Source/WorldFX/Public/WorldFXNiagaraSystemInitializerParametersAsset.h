#pragma once
#include "CoreMinimal.h"
#include "WorldFXNiagaraSystemInitializer.h"
#include "WorldFXNiagaraSystemInitializerParametersAsset.generated.h"

class UWorldFXNiagaraSystemParameters;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class WORLDFX_API UWorldFXNiagaraSystemInitializerParametersAsset : public UWorldFXNiagaraSystemInitializer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorldFXNiagaraSystemParameters* Parameters;
    
    UWorldFXNiagaraSystemInitializerParametersAsset();
};

