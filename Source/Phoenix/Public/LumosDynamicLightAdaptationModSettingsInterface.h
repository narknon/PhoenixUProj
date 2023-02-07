#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesScalarName.h"
#include "DynamicLightAdaptationModSettingsInterface.h"
#include "LumosDynamicLightAdaptationModSettingsInterface.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class ULumosDynamicLightAdaptationModSettingsInterface : public UDynamicLightAdaptationModSettingsInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesScalarName AdjustBaseEV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesScalarName OutdoorsDayTimeEVBoost;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesScalarName MaxEV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesScalarName MinEV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesScalarName StartCutoffMaxEV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLerpVolumesScalarName StartCutoffMinEV;
    
    ULumosDynamicLightAdaptationModSettingsInterface();
};

