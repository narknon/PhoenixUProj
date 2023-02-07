#pragma once
#include "CoreMinimal.h"
#include "ELerpEasingType.h"
#include "LightSettingsLerpControl.h"
#include "LightSettingsEase.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsEase : public ULightSettingsLerpControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELerpEasingType Easing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendExp;
    
    ULightSettingsEase();
};

