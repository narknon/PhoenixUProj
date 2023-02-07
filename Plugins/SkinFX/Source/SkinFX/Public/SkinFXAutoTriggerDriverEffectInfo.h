#pragma once
#include "CoreMinimal.h"
#include "MaterialSwapParameters.h"
#include "SkinFXAutoTriggerEffectInfo.h"
#include "SkinFXAutoTriggerDriverEffectInfo.generated.h"

USTRUCT(BlueprintType)
struct FSkinFXAutoTriggerDriverEffectInfo : public FSkinFXAutoTriggerEffectInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialSwapParameters Parameters;
    
    SKINFX_API FSkinFXAutoTriggerDriverEffectInfo();
};

