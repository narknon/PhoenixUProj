#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AnimatedLightPluginSettings.generated.h"

UCLASS(Blueprintable)
class ANIMATEDLIGHTS_API UAnimatedLightPluginSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> InOrderBuckets;
    
    UAnimatedLightPluginSettings();
};

