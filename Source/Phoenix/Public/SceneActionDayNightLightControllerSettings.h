#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SceneActionDayNightLightControllerSettings.generated.h"

UCLASS(Abstract, Blueprintable)
class USceneActionDayNightLightControllerSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpdateThresholdDegrees;
    
    USceneActionDayNightLightControllerSettings();
};

