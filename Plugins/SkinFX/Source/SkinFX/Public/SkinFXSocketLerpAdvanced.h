#pragma once
#include "CoreMinimal.h"
#include "SkinFXSocketLerpAdvanced.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXSocketLerpAdvanced {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UseSpecificComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEvaluateOnlyAtStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreviewOnly;
    
    SKINFX_API FSkinFXSocketLerpAdvanced();
};

