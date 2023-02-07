#pragma once
#include "CoreMinimal.h"
#include "OverlapEffectsHandlerEffect.h"
#include "OverlapEffectsHandlerEffectHermes.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerEffectHermes : public UOverlapEffectsHandlerEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HermesMessage;
    
    UOverlapEffectsHandlerEffectHermes();
};

