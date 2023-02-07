#pragma once
#include "CoreMinimal.h"
#include "CharacterLightingFeaturesOptions.h"
#include "CharacterLightingFeaturesState.h"
#include "CharacterLightingFeatures.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct LIGHTCULLING_API FCharacterLightingFeatures {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCharacterLightingFeaturesOptions OPTIONS;
    
private:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<TWeakObjectPtr<AActor>> IgnoreCharacters;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AActor>> PendingCharacters;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<AActor>, FCharacterLightingFeaturesState> Characters;
    
public:
    FCharacterLightingFeatures();
};

