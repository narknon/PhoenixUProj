#pragma once
#include "CoreMinimal.h"
#include "OverlapEffectsHandlerEffect.h"
#include "OverlapEffectsHandlerEffectSound.generated.h"

class UAkAudioEvent;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerEffectSound : public UOverlapEffectsHandlerEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* Event;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LastSoundHandle;
    
    UOverlapEffectsHandlerEffectSound();
};

