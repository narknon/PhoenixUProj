#pragma once
#include "CoreMinimal.h"
#include "LightSettingsLerpBinary.h"
#include "LightSettingsLerpIfNotZero.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsLerpIfNotZero : public ULightSettingsLerpBinary {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Tolerance;
    
    ULightSettingsLerpIfNotZero();
};

