#pragma once
#include "CoreMinimal.h"
#include "BlendableGlobalLightingVolumeFogBase.h"
#include "ExpHeightFogBasicParametersOverride.h"
#include "ExpHeightFogDirectionalInscatteringParametersOverride.h"
#include "ExpHeightFogSecondParametersOverride.h"
#include "ExpHeightFogVolumetricAdvancedParametersOverride.h"
#include "ExpHeightFogVolumetricLightingParametersOverride.h"
#include "ExpHeightFogVolumetricNoiseParametersOverride.h"
#include "ExpHeightFogVolumetricParametersOverride.h"
#include "BlendableGlobalLightingVolumeFog.generated.h"

class UBlendableGlobalLightingVolumeFogDefaults;

UCLASS(Blueprintable)
class GLOBALLIGHTRIG_API ABlendableGlobalLightingVolumeFog : public ABlendableGlobalLightingVolumeFogBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogBasicParametersOverride Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogSecondParametersOverride Second;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogDirectionalInscatteringParametersOverride DirectionalInscattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricParametersOverride Volumetric;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricLightingParametersOverride VolumetricLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricNoiseParametersOverride VolumetricNoise;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricAdvancedParametersOverride VolumetricAdvanced;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBlendableGlobalLightingVolumeFogDefaults* Defaults;
    
public:
    ABlendableGlobalLightingVolumeFog(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ReloadDefaults();
    
};

