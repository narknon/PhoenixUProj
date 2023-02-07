#pragma once
#include "CoreMinimal.h"
#include "ELightRigCurveColorConversionType.h"
#include "LightSettingsModCurve.h"
#include "LightSettingsModFloatBase.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModFloatBase : public ULightSettingsModCurve {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELightRigCurveColorConversionType ColorConversion;
    
    ULightSettingsModFloatBase();
};

