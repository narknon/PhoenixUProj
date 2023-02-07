#pragma once
#include "CoreMinimal.h"
#include "ESkinFXEffectEndStyle.h"
#include "SkinFXEffectEnd.generated.h"

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXEffectEnd {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXEffectEndStyle EndStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnd;
    
    FSkinFXEffectEnd();
};

