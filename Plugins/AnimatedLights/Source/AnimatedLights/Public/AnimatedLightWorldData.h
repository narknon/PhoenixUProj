#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AnimatedLightWorldData.generated.h"

class UAnimatedLightPluginSettings;

UCLASS(Blueprintable, Transient)
class ANIMATEDLIGHTS_API UAnimatedLightWorldData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimatedLightPluginSettings* Settings;
    
    UAnimatedLightWorldData();
};

