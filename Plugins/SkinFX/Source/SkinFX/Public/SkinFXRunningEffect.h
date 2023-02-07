#pragma once
#include "CoreMinimal.h"
#include "SkinFXEffectDefinition.h"
#include "SkinFXRunningEffect.generated.h"

class ASkinFXDefinitionGraph;

USTRUCT(BlueprintType)
struct FSkinFXRunningEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXEffectDefinition EffectDefinition;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASkinFXDefinitionGraph* BlueprintGraph;
    
    SKINFX_API FSkinFXRunningEffect();
};

