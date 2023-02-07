#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "NiagaraHelpersVarNameLinearColor.h"
#include "NiagaraHelpersInitializerLinearColor.generated.h"

USTRUCT(BlueprintType)
struct NIAGARAHELPERS_API FNiagaraHelpersInitializerLinearColor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNiagaraHelpersVarNameLinearColor Variable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Value;
    
    FNiagaraHelpersInitializerLinearColor();
};

