#pragma once
#include "CoreMinimal.h"
#include "LightCullingSettingsStack.h"
#include "LightCullingSettingsWorldStacks.generated.h"

class UWorld;

USTRUCT(BlueprintType)
struct LIGHTCULLING_API FLightCullingSettingsWorldStacks {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UWorld>, FLightCullingSettingsStack> WorldMap;
    
    FLightCullingSettingsWorldStacks();
};

