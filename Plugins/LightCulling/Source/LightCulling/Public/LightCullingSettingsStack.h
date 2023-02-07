#pragma once
#include "CoreMinimal.h"
#include "LightCullingSettingsStackEntry.h"
#include "LightCullingSettingsStack.generated.h"

USTRUCT(BlueprintType)
struct LIGHTCULLING_API FLightCullingSettingsStack {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLightCullingSettingsStackEntry> Stack;
    
    FLightCullingSettingsStack();
};

