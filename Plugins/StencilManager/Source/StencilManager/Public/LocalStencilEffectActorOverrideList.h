#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectActorOverride.h"
#include "StencilManagerEffectName.h"
#include "LocalStencilEffectActorOverrideList.generated.h"

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FLocalStencilEffectActorOverrideList {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerEffectName Effect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocalStencilEffectActorOverride> ActorOverrides;
    
    FLocalStencilEffectActorOverrideList();
};

