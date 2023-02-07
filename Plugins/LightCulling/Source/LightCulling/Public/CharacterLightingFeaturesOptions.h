#pragma once
#include "CoreMinimal.h"
#include "CharacterLightingFeaturesOptions.generated.h"

USTRUCT(BlueprintType)
struct LIGHTCULLING_API FCharacterLightingFeaturesOptions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoAddDeleteCharacters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoDetectCharacterChanges;
    
    FCharacterLightingFeaturesOptions();
};

