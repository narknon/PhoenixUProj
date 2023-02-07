#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "MultiFX2Handle.h"
#include "EOverlapEffectsAttachment.h"
#include "OverlapEffectsHandlerEffect.h"
#include "OverlapEffectsHandlerEffectMultiFX.generated.h"

class UMultiFX2Asset;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class FXUTIL_API UOverlapEffectsHandlerEffectMultiFX : public UOverlapEffectsHandlerEffect {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMultiFX2Asset* FXAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOverlapEffectsAttachment Attachment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachPointName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AttachLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator AttachRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyOneEffectAtATime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FMultiFX2Handle FXHandle;
    
    UOverlapEffectsHandlerEffectMultiFX();
};

