#pragma once
#include "CoreMinimal.h"
#include "CreatureVariation.h"
#include "CreatureMaleVariationSettings.generated.h"

class UObjectArchitectAsset;
class USkeletalMesh;

USTRUCT(BlueprintType)
struct FCreatureMaleVariationSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> MaleSkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObjectArchitectAsset> AudioAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCreatureVariation> ColorVariations;
    
    PHOENIX_API FCreatureMaleVariationSettings();
};

