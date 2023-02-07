#pragma once
#include "CoreMinimal.h"
#include "OverlapEffectsHandlerMinimumSpeedBase.h"
#include "OverlapEffectsHandlerInstancedFoliageOverlap.generated.h"

class UOverlapEffectsHandlerEffect;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerInstancedFoliageOverlap : public UOverlapEffectsHandlerMinimumSpeedBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UOverlapEffectsHandlerEffect*> BeginEffects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UOverlapEffectsHandlerEffect*> EndEffects;
    
    UOverlapEffectsHandlerInstancedFoliageOverlap();
};

