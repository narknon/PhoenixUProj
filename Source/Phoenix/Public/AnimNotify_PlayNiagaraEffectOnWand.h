#pragma once
#include "CoreMinimal.h"
#include "AnimNotify_PlayNiagaraEffect.h"
#include "AnimNotify_PlayNiagaraEffectOnWand.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UAnimNotify_PlayNiagaraEffectOnWand : public UAnimNotify_PlayNiagaraEffect {
    GENERATED_BODY()
public:
    UAnimNotify_PlayNiagaraEffectOnWand();
};

