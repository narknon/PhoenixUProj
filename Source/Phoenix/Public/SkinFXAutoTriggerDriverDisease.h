#pragma once
#include "CoreMinimal.h"
#include "SkinFXAutoTriggerDriver.h"
#include "SkinFXAutoTriggerEffectInfo.h"
#include "SkinFXAutoTriggerDriverDisease.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXAutoTriggerDriverDisease : public USkinFXAutoTriggerDriver {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXAutoTriggerEffectInfo EffectInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Priority;
    
public:
    USkinFXAutoTriggerDriverDisease();
};

