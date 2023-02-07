#pragma once
#include "CoreMinimal.h"
#include "ESkinFXColorConvert.h"
#include "SkinFXApplyFunctionModColor.h"
#include "SkinFXColorAdvanced.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXColorAdvanced {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXApplyFunctionModColor FunctionMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXColorConvert Convert;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreviewOnly;
    
    SKINFX_API FSkinFXColorAdvanced();
};

