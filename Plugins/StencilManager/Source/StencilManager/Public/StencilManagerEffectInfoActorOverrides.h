#pragma once
#include "CoreMinimal.h"
#include "StencilManagerEffectInfoOverride.h"
#include "StencilManagerEffectInfoActorOverrides.generated.h"

class UStencilManagerMatchActor;

USTRUCT(BlueprintType)
struct FStencilManagerEffectInfoActorOverrides {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStencilManagerMatchActor* Expression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStencilManagerEffectInfoOverride> EffectOverrides;
    
    STENCILMANAGER_API FStencilManagerEffectInfoActorOverrides();
};

