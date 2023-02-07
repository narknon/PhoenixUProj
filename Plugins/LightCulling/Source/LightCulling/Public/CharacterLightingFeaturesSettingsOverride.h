#pragma once
#include "CoreMinimal.h"
#include "CharacterLightingFeaturesSettings.h"
#include "CharacterLightingFeaturesSettingsOverride.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct LIGHTCULLING_API FCharacterLightingFeaturesSettingsOverride {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCharacterLightingFeaturesSettings Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Lerp;
    
    FCharacterLightingFeaturesSettingsOverride();
};

