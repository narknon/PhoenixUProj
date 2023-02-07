#pragma once
#include "CoreMinimal.h"
#include "LightSettingsLerpControl.h"
#include "LightSettingsLerpBinary.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsLerpBinary : public ULightSettingsLerpControl {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInvert;
    
    ULightSettingsLerpBinary();
};

