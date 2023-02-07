#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VegetationInteractionCameraFade.h"
#include "VegetationInteractionCameraFadeSetup.generated.h"

class URenderSettingsCustomBlendDomain;

UCLASS(Blueprintable)
class UVegetationInteractionCameraFadeSetup : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVegetationInteractionCameraFade Normal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVegetationInteractionCameraFade Aiming;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URenderSettingsCustomBlendDomain* StrengthBlendDomain;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAimBlend;
    
    UVegetationInteractionCameraFadeSetup();
};

