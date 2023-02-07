#pragma once
#include "CoreMinimal.h"
#include "StencilManagerEffectName.generated.h"

USTRUCT(BlueprintType)
struct FStencilManagerEffectName {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    STENCILMANAGER_API FStencilManagerEffectName();
};

