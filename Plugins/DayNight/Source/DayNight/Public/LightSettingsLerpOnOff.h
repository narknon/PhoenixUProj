#pragma once
#include "CoreMinimal.h"
#include "LightSettingsLerpBinary.h"
#include "LightSettingsLerpOnOff.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsLerpOnOff : public ULightSettingsLerpBinary {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Cutoff;
    
    ULightSettingsLerpOnOff();
};

