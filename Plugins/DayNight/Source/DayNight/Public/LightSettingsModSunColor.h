#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingSunColorParams.h"
#include "LightSettingsModColorBase.h"
#include "LightSettingsModSunColor.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModSunColor : public ULightSettingsModColorBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightingSunColorParams Params;
    
    ULightSettingsModSunColor();
};

