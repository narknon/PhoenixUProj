#pragma once
#include "CoreMinimal.h"
#include "EStencilManagerPreferredEffect.h"
#include "LocalStencilEffect.h"
#include "StencilManagerEffectName.h"
#include "StencilManagerGroupName.h"
#include "StencilManagerSkinFX.h"
#include "StencilManagerEffectInfoOverride.generated.h"

USTRUCT(BlueprintType)
struct FStencilManagerEffectInfoOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerEffectName Effect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerGroupName GroupOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilManagerPreferredEffect PreferredEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocalStencilEffect LocalDepthFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerSkinFX SkinFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseGroupOverride;
    
    STENCILMANAGER_API FStencilManagerEffectInfoOverride();
};

