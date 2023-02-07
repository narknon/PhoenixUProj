#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "StencilManagerEffectInfoAccessibilityOverride.h"
#include "StencilManagerAccessibilityOverrides.generated.h"

UCLASS(Blueprintable)
class STENCILMANAGER_API UStencilManagerAccessibilityOverrides : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStencilManagerEffectInfoAccessibilityOverride> AccessibilityOverrides;
    
    UStencilManagerAccessibilityOverrides();
};

