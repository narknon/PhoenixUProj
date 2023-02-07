#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DynamicLightAdaptationModSettingsAsset.generated.h"

class UDynamicLightAdaptationModSettingsInterface;

UCLASS(Blueprintable)
class RENDERSETTINGS_API UDynamicLightAdaptationModSettingsAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDynamicLightAdaptationModSettingsInterface*> Mods;
    
    UDynamicLightAdaptationModSettingsAsset();
};

