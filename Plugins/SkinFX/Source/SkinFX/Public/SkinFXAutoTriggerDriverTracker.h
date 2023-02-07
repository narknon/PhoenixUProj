#pragma once
#include "CoreMinimal.h"
#include "SkinFXAutoTriggerEffectInfo.h"
#include "SkinFXAutoTriggerDriverTracker.generated.h"

class UNiagaraComponent;
class USkinFXAutoTriggerDriver;

USTRUCT(BlueprintType)
struct FSkinFXAutoTriggerDriverTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkinFXAutoTriggerDriver* Driver;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXAutoTriggerEffectInfo EffectInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* NiagaraComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSignalledActive: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSignalledInactive: 1;
    
    SKINFX_API FSkinFXAutoTriggerDriverTracker();
};

