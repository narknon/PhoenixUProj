#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Curves/CurveFloat.h"
#include "ExposureExpressions.h"
#include "ExposureExpressionsExtrasDefaults.h"
#include "Interface_ExposureExpressionsGlobals.h"
#include "RenderSettingsEmissiveAdaptation.h"
#include "RenderSettingsEmissiveAdaptationSettings.generated.h"

class UExposureExpressionsExposureValue;
class UMaterialParameterCollection;
class UNiagaraParameterCollection;

UCLASS(Blueprintable)
class RENDERSETTINGS_API URenderSettingsEmissiveAdaptationSettings : public UDataAsset, public IInterface_ExposureExpressionsGlobals {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve NightDayLerp;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve OutdoorsIndoorsLerp;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraParameterCollection* NiagaraParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressions GlobalExpressions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExposureExpressionsExtrasDefaults Extras;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Interp, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* AutoExposureBaseExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Interp, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* AverageLuminanceBaseExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Interp, meta=(AllowPrivateAccess=true))
    UExposureExpressionsExposureValue* FilteredAverageLuminanceBaseExpression;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderSettingsEmissiveAdaptation> Settings;
    
    URenderSettingsEmissiveAdaptationSettings();
    
    // Fix for true pure virtual functions not being implemented
};

