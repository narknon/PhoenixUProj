#pragma once
#include "CoreMinimal.h"
#include "EOverlapEffectsHitPoint.h"
#include "OverlapEffectsHandlerEffectSound.h"
#include "OverlapEffectsHandlerEffectSoundWorld.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerEffectSoundWorld : public UOverlapEffectsHandlerEffectSound {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOverlapEffectsHitPoint HitPoint;
    
    UOverlapEffectsHandlerEffectSoundWorld();
};

