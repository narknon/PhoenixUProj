#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingCustomBlendableNameScalar.h"
#include "LightSettingsModThreshold.h"
#include "LightSettingsModThresholdBlendable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class DAYNIGHT_API ULightSettingsModThresholdBlendable : public ULightSettingsModThreshold {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightingCustomBlendableNameScalar Blendable;
    
    ULightSettingsModThresholdBlendable();
};

