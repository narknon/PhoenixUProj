#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingMaster.h"
#include "GlobalLightingMasterWithClouds.generated.h"

class URenderSettingsBlendDomainAsset;
class UVolumetricCloudsComponent;

UCLASS(Blueprintable)
class GLOBALLIGHTRIG_API AGlobalLightingMasterWithClouds : public AGlobalLightingMaster {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RelativeHeightMeters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URenderSettingsBlendDomainAsset* VisibilityBlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VisibilityBlendDomainThreshold;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVolumetricCloudsComponent* VolumetricCloudsComponent;
    
public:
    AGlobalLightingMasterWithClouds(const FObjectInitializer& ObjectInitializer);
};

