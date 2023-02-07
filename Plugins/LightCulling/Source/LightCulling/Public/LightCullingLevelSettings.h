#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "LightCullingLevelName.h"
#include "LightCullingPerLevelSettings.h"
#include "SimpleBlobShadowDecalComponentMapper.h"
#include "LightCullingLevelSettings.generated.h"

class ULightCullingSettings;

UCLASS(Blueprintable)
class LIGHTCULLING_API ULightCullingLevelSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ULightCullingSettings* LevelDefaultSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLightCullingPerLevelSettings> LevelSettings;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLightCullingLevelName> DisableLevels;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> DisableProceduralLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSimpleBlobShadowDecalComponentMapper SimpleBlobShadowDecalComponentMapper;
    
    ULightCullingLevelSettings();
};

