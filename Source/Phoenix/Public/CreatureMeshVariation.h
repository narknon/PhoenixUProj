#pragma once
#include "CoreMinimal.h"
#include "CreatureMeshVariation.generated.h"

class UObjectArchitectAsset;
class USkeletalMesh;

USTRUCT(BlueprintType)
struct FCreatureMeshVariation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VariationName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UObjectArchitectAsset> AudioAsset;
    
    PHOENIX_API FCreatureMeshVariation();
};

