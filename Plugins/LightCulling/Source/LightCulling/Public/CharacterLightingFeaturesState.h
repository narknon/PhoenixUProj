#pragma once
#include "CoreMinimal.h"
#include "LightingFeaturesSkeletalMeshState.h"
#include "CharacterLightingFeaturesState.generated.h"

class USkeletalMeshComponent;

USTRUCT(BlueprintType)
struct LIGHTCULLING_API FCharacterLightingFeaturesState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<USkeletalMeshComponent>, FLightingFeaturesSkeletalMeshState> Meshes;
    
public:
    FCharacterLightingFeaturesState();
};

