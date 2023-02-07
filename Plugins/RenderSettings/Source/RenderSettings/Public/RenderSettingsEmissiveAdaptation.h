#pragma once
#include "CoreMinimal.h"
#include "ExposureExpressionsExtras.h"
#include "RenderSettingsEmissiveAdaptation.generated.h"

class UExposureExpressionsExposureValue;

USTRUCT(BlueprintType)
struct RENDERSETTINGS_API FRenderSettingsEmissiveAdaptation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_BloomTarget: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_BloomBaseEV: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_BloomIntensityCorrection: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_BloomOutdoorsDaytimeBoostEV: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_AutoExposureAdaptationBoostEV: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_LuminanceAdaptationBoostEV: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_LuminanceAdaptationMinEV: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bOverride_LuminanceAdaptationMaxEV: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Interp, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* BloomTargetExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Interp, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* BloomBaseExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float BloomIntensityCorrection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Interp, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* BloomOutdoorsDaytimeBoostExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Interp, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* AutoExposureAdaptationBoostExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Interp, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* LuminanceAdaptationBoostExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Interp, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* LuminanceAdaptationMinExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Interp, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* LuminanceAdaptationMaxExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtras Extras;
    
    FRenderSettingsEmissiveAdaptation();
};

