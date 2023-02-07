#pragma once
#include "CoreMinimal.h"
#include "EStencilManagerEffectPriority.h"
#include "EStencilManagerPreferredEffect.h"
#include "LocalStencilEffect.h"
#include "StencilManagerGroupName.h"
#include "StencilManagerSkinFX.h"
#include "StencilManagerEffectInfo.generated.h"

USTRUCT(BlueprintType)
struct FStencilManagerEffectInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerGroupName Group;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 LegacyStencilValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilManagerEffectPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStencilManagerPreferredEffect PreferredEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocalStencilEffect LocalDepthFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerSkinFX SkinFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bDisableOverrides;
    
    STENCILMANAGER_API FStencilManagerEffectInfo();
};

