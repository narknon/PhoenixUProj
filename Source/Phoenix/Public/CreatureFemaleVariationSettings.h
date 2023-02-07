#pragma once
#include "CoreMinimal.h"
#include "CreatureVariation.h"
#include "CreatureFemaleVariationSettings.generated.h"

class UObjectArchitectAsset;
class USkeletalMesh;

USTRUCT(BlueprintType)
struct FCreatureFemaleVariationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSwapMeshForFemale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> FemaleSkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObjectArchitectAsset> AudioAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCreatureVariation MaterialSwap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCreatureVariation> ColorVariations;
    
    PHOENIX_API FCreatureFemaleVariationSettings();
};

