#pragma once
#include "CoreMinimal.h"
#include "LightSettingsLerpBinary.h"
#include "LightSettingsLerpIfOne.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsLerpIfOne : public ULightSettingsLerpBinary {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Tolerance;
    
    ULightSettingsLerpIfOne();
};

