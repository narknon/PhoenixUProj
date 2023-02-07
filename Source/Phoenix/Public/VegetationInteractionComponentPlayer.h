#pragma once
#include "CoreMinimal.h"
#include "VegetationInteractionComponentBiped.h"
#include "VegetationInteractionComponentPlayer.generated.h"

class URenderSettingsCustomBlendDomain;
class UVegetationInteractionCameraFadeSetup;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UVegetationInteractionComponentPlayer : public UVegetationInteractionComponentBiped {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVegetationInteractionCameraFadeSetup* CameraFadeSetup;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* CameraFadeStrengthBlendDomain;
    
    UVegetationInteractionComponentPlayer();
};

