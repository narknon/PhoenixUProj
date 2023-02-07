#pragma once
#include "CoreMinimal.h"
#include "LightSettingsModFloatBase.h"
#include "LightSettingsModFloatConstant.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModFloatConstant : public ULightSettingsModFloatBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    ULightSettingsModFloatConstant();
};

