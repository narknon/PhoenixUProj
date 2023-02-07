#pragma once
#include "CoreMinimal.h"
#include "LightSettingsModFloatBase.h"
#include "LightSettingsModFloatThreshold.generated.h"

class ULightSettingsModThreshold;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModFloatThreshold : public ULightSettingsModFloatBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULightSettingsModThreshold* Threshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ValueAbove;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ValueBelow;
    
    ULightSettingsModFloatThreshold();
};

