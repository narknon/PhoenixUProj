#pragma once
#include "CoreMinimal.h"
#include "AnimatedLightComponentBase.h"
#include "AnimatedLightComponentLean.generated.h"

class UAnimatedLightSettingsAsset;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ANIMATEDLIGHTS_API UAnimatedLightComponentLean : public UAnimatedLightComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimatedLightSettingsAsset* Settings;
    
    UAnimatedLightComponentLean();
};

