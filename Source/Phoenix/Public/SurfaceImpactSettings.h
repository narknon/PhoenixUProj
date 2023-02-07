#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SurfaceImpactSettings.generated.h"

UCLASS(Blueprintable, Config=Engine, DefaultConfig, Config=Game)
class USurfaceImpactSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VfxLandscapeLayerInfoWetnessOverrideThreshold;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SfxLandscapeLayerInfoWetnessOverrideThreshold;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpactLandscapeLayerInfoWetnessOverrideThreshold;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> LandscapeWetnessLayerInfo;
    
    USurfaceImpactSettings();
};

