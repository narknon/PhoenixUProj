#pragma once
#include "CoreMinimal.h"
#include "EOverlapEffectsAttachment.h"
#include "OverlapEffectsHandlerEffectSound.h"
#include "OverlapEffectsHandlerEffectSoundAttached.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerEffectSoundAttached : public UOverlapEffectsHandlerEffectSound {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOverlapEffectsAttachment Attachment;
    
    UOverlapEffectsHandlerEffectSoundAttached();
};

