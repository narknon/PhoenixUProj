#pragma once
#include "CoreMinimal.h"
#include "BlendableGlobalLightingVolumeFogBase.h"
#include "ExpHeightFogBasicParametersRelative.h"
#include "ExpHeightFogDirectionalInscatteringParametersRelative.h"
#include "ExpHeightFogSecondParametersRelative.h"
#include "ExpHeightFogVolumetricNoiseParametersRelative.h"
#include "ExpHeightFogVolumetricParametersRelative.h"
#include "BlendableGlobalLightingVolumeFogRelative.generated.h"

class UBlendableGlobalLightingVolumeFogRelativeDefaults;

UCLASS(Blueprintable)
class GLOBALLIGHTRIG_API ABlendableGlobalLightingVolumeFogRelative : public ABlendableGlobalLightingVolumeFogBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogBasicParametersRelative Basic;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogSecondParametersRelative Second;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogDirectionalInscatteringParametersRelative DirectionalInscattering;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricParametersRelative Volumetric;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExpHeightFogVolumetricNoiseParametersRelative VolumetricNoise;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UBlendableGlobalLightingVolumeFogRelativeDefaults* Defaults;
    
public:
    ABlendableGlobalLightingVolumeFogRelative(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ReloadDefaults();
    
};

