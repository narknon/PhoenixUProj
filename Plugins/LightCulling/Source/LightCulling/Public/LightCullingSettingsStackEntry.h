#pragma once
#include "CoreMinimal.h"
#include "LightCullingSettingsStackEntry.generated.h"

class ULightCullingSettings;
class UObject;

USTRUCT(BlueprintType)
struct FLightCullingSettingsStackEntry {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> Owner;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ULightCullingSettings> Settings;
    
    LIGHTCULLING_API FLightCullingSettingsStackEntry();
};

