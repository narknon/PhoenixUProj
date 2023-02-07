#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PhoenixHighContrastGameplaySettings.generated.h"

class UFXAutoTriggerHighContrastGameplayConditions;

UCLASS(Blueprintable)
class UPhoenixHighContrastGameplaySettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXAutoTriggerHighContrastGameplayConditions* Conditions;
    
    UPhoenixHighContrastGameplaySettings();
};

