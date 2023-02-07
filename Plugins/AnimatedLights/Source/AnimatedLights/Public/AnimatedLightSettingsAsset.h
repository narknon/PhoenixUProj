#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AnimatedLightSettings.h"
#include "AnimatedLightSettingsAsset.generated.h"

UCLASS(Blueprintable)
class ANIMATEDLIGHTS_API UAnimatedLightSettingsAsset : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimatedLightSettings Settings;
    
    UAnimatedLightSettingsAsset();
};

