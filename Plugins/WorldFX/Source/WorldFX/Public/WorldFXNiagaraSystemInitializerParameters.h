#pragma once
#include "CoreMinimal.h"
#include "NiagaraHelpersInitializers.h"
#include "WorldFXNiagaraSystemInitializer.h"
#include "WorldFXNiagaraSystemInitializerParameters.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UWorldFXNiagaraSystemInitializerParameters : public UWorldFXNiagaraSystemInitializer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersInitializers Parameters;
    
    UWorldFXNiagaraSystemInitializerParameters();
};

