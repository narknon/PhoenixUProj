#pragma once
#include "CoreMinimal.h"
#include "LocalStencilEffectActorOverrideParameters.h"
#include "LocalStencilEffectActorOverride.generated.h"

class UStencilManagerMatchActor;

USTRUCT(BlueprintType)
struct STENCILMANAGER_API FLocalStencilEffectActorOverride : public FLocalStencilEffectActorOverrideParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStencilManagerMatchActor* Expression;
    
    FLocalStencilEffectActorOverride();
};

