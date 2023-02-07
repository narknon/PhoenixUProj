#pragma once
#include "CoreMinimal.h"
#include "EOverlapEffectsAttachment.h"
#include "OverlapEffectsHandlerEffect.h"
#include "Templates/SubclassOf.h"
#include "OverlapEffectsHandlerEffectSkinFX.generated.h"

class ASkinFXDefinition;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerEffectSkinFX : public UOverlapEffectsHandlerEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> SkinFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOverlapEffectsAttachment Attachment;
    
    UOverlapEffectsHandlerEffectSkinFX();
};

