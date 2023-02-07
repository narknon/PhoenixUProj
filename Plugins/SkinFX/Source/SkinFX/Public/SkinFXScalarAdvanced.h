#pragma once
#include "CoreMinimal.h"
#include "SkinFXApplyFunctionMod.h"
#include "SkinFXScalarAdvanced.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXScalarAdvanced {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXApplyFunctionMod FunctionMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreviewOnly;
    
    SKINFX_API FSkinFXScalarAdvanced();
};

