#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingSunColorParams.h"
#include "LightSettingsModFloatBase.h"
#include "LightSettingsModSunLuminance.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModSunLuminance : public ULightSettingsModFloatBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightingSunColorParams Params;
    
    ULightSettingsModSunLuminance();
};

