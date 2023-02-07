#pragma once
#include "CoreMinimal.h"
#include "EOverlapEffectsHitPoint.h"
#include "OverlapEffectsHandlerEffectNiagara.h"
#include "OverlapEffectsHandlerEffectNiagaraWorld.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerEffectNiagaraWorld : public UOverlapEffectsHandlerEffectNiagara {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOverlapEffectsHitPoint HitPoint;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyOneEffectActiveAtAnyTime;
    
    UOverlapEffectsHandlerEffectNiagaraWorld();
};

