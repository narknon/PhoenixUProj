#pragma once
#include "CoreMinimal.h"
#include "StencilManagerEffectInfoOverride.h"
#include "StencilManagerEffectInfoAccessibilityOverride.generated.h"

USTRUCT(BlueprintType)
struct FStencilManagerEffectInfoAccessibilityOverride : public FStencilManagerEffectInfoOverride {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HighContrastMode;
    
    STENCILMANAGER_API FStencilManagerEffectInfoAccessibilityOverride();
};

