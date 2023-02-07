#pragma once
#include "CoreMinimal.h"
#include "ESkinFXEffectEndStyle.h"
#include "SkinFXParameterDriverEndEffect.h"
#include "SkinFXParameterDriverAutoTriggerBoolEndEffect.generated.h"

class UFXAutoTriggerBool;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXParameterDriverAutoTriggerBoolEndEffect : public USkinFXParameterDriverEndEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerBool* AutoTriggerBool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESkinFXEffectEndStyle EndStyle;
    
    USkinFXParameterDriverAutoTriggerBoolEndEffect();
};

