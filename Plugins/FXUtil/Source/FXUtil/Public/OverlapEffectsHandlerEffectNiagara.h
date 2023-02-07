#pragma once
#include "CoreMinimal.h"
#include "OverlapEffectsHandlerEffect.h"
#include "OverlapEffectsHandlerEffectNiagara.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerEffectNiagara : public UOverlapEffectsHandlerEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UNiagaraSystem> System;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* Component;
    
    UOverlapEffectsHandlerEffectNiagara();
};

