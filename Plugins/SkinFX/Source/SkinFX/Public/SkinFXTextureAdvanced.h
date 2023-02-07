#pragma once
#include "CoreMinimal.h"
#include "SkinFXTextureAdvanced.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXTextureAdvanced {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPreviewOnly;
    
    SKINFX_API FSkinFXTextureAdvanced();
};

