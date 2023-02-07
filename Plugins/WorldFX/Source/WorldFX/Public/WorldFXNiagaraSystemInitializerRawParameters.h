#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersInitializerRaw.h"
#include "WorldFXNiagaraSystemInitializer.h"
#include "WorldFXNiagaraSystemInitializerRawParameters.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXNiagaraSystemInitializerRawParameters : public UWorldFXNiagaraSystemInitializer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersInitializerRaw Parameters;
    
    UWorldFXNiagaraSystemInitializerRawParameters();
};

