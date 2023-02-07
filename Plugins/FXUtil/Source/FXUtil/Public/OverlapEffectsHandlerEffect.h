#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OverlapEffectsHandlerEffect.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerEffect : public UObject {
    GENERATED_BODY()
public:
    UOverlapEffectsHandlerEffect();
};

