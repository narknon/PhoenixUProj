#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationModSettingsInterface.h"
#include "DynamicLightAdaptationModSettingsInterfaceAsset.generated.h"

class UDynamicLightAdaptationModSettingsAsset;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class RENDERSETTINGS_API UDynamicLightAdaptationModSettingsInterfaceAsset : public UDynamicLightAdaptationModSettingsInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicLightAdaptationModSettingsAsset* ModAsset;
    
    UDynamicLightAdaptationModSettingsInterfaceAsset();
};

