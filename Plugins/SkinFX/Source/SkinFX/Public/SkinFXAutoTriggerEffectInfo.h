#pragma once
#include "CoreMinimal.h"
#include "SkinFXAutoTriggeNiagaraInfo.h"
#include "SkinFXAutoTriggeSkinFXInfo.h"
#include "SkinFXAutoTriggerEffectInfo.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXAutoTriggerEffectInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXAutoTriggeSkinFXInfo SkinFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXAutoTriggeNiagaraInfo NiagaraFX;
    
    SKINFX_API FSkinFXAutoTriggerEffectInfo();
};

