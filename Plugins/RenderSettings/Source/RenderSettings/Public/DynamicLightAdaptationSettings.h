#pragma once
#include "CoreMinimal.h"
#include "DynamicLightAdaptationSettingsBase.h"
#include "DynamicLightAdaptationSettings.generated.h"

class UDynamicLightAdaptationModSettingsInterface;

USTRUCT(BlueprintType)
struct RENDERSETTINGS_API FDynamicLightAdaptationSettings : public FDynamicLightAdaptationSettingsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDynamicLightAdaptationModSettingsInterface* ModInterface;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDynamicLightAdaptationModSettingsInterface*> ModInterfaces;
    
    FDynamicLightAdaptationSettings();
};

