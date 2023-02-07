#pragma once
#include "CoreMinimal.h"
#include "LightCullingLevelName.h"
#include "LightCullingPerLevelSettings.generated.h"

class ULightCullingSettings;

USTRUCT(BlueprintType)
struct LIGHTCULLING_API FLightCullingPerLevelSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLightCullingLevelName Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LevelPartialMatch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULightCullingSettings* Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseSubString;
    
    FLightCullingPerLevelSettings();
};

