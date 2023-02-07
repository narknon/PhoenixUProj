#pragma once
#include "CoreMinimal.h"
#include "RenderSettingsPPChromaticAberration.h"
#include "RenderSettingsPPGrain.h"
#include "RenderSettingsPPLensFX.generated.h"

USTRUCT(BlueprintType)
struct RENDERSETTINGS_API FRenderSettingsPPLensFX {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_VignetteIntensity: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float VignetteIntensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FRenderSettingsPPGrain Grain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FRenderSettingsPPChromaticAberration ChromaticAberration;
    
    FRenderSettingsPPLensFX();
};

