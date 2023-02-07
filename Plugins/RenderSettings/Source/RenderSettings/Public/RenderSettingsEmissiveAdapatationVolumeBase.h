#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "Interface_ExposureExpressionsGlobalsProvider.h"
#include "BlendDomain.h"
#include "Interface_RenderSettingsEmissiveAdaptation.h"
#include "RenderSettingsEmissiveAdapatationVolumeBase.generated.h"

UCLASS(Abstract, Blueprintable)
class RENDERSETTINGS_API ARenderSettingsEmissiveAdapatationVolumeBase : public AVolume, public IInterface_RenderSettingsEmissiveAdaptation, public IInterface_ExposureExpressionsGlobalsProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlendDomain BlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BlendWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    uint8 bUnbounded: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    uint8 bEnabled: 1;
    
    ARenderSettingsEmissiveAdapatationVolumeBase();
    UFUNCTION(BlueprintCallable)
    void SetPriority(float NewPriority);
    
    
    // Fix for true pure virtual functions not being implemented
};

